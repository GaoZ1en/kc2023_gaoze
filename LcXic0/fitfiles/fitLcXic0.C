#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLatex.h>
//#include <RooFFTConvPdf.h>
#include <RooDataSet.h>
#include <RooRealVar.h>
#include <RooFormulaVar.h>
#include <RooPlot.h>
#include <RooArgusBG.h>
#include <RooConstVar.h>
#include <RooAddPdf.h>
#include <RooWorkspace.h>
#include <RooAbsData.h>
//#include "RooStats/ModelConfig.h"
//#include "RooStats/ProfileLikelihoodCalculator.h"
//#include "RooStats/HypoTestResult.h"
//#include "RooStats/SPlot.h"
#include "TIterator.h"
//#include "../MC_run2/parJ_MC.h"
#define LcXic0_Class_cxx
#include "LcXic0_Class.h"

using namespace RooFit;
using namespace RooStats;

void fitLcXic0()
{
   gROOT->ProcessLine(".x /home/Koishi/LcXic/datafiles/lhcbStyle.C");

   TCut MCut = "Lc_M>2210 && Lc_M<2360 && Xic_M>2420 && Xic_M<2540";
   TChain *chain = new TChain("DecayTree");
   chain->AddFile("/home/Koishi/LcXic0/datafiles/XiccTuple_sw_corrected.root");

   RooRealVar *m = new RooRealVar("C_M_corrected","M(#Lambda_{c}^{+}#Xi_{c}^{0})",4757,6757,"MeV/c^{2}");
   RooRealVar *nsig_sw = new RooRealVar("nsig_sw","signal weight",-2.0,2.0);

   RooDataSet *data = new RooDataSet("data","dataset with m",chain->CopyTree(MCut),RooArgSet(*m,*nsig_sw),nullptr,"nsig_sw");


   // **** signal,crystal ball ****
   // #### sig ####
   RooRealVar *mean1 = new RooRealVar("#mu1","mean1",4800,4775,4825);
   RooRealVar *sigma1 = new RooRealVar("#sigma1","sigma1",10,0,100);
   RooAbsPdf *sig1 = new RooGaussian("sig1","sig1",*m,*mean1,*sigma1);

   RooRealVar *mean2 = new RooRealVar("#mu2","mean2",5000,4950,5050);
   RooRealVar *sigma2 = new RooRealVar("#sigma2","sigma2",10,0,50);
   RooAbsPdf *sig2 = new RooGaussian("sig2","sig2",*m,*mean2,*sigma2);

   RooRealVar *mean3 = new RooRealVar("#mu3","mean3",5150,5100,5200);
   RooRealVar *sigma3 = new RooRealVar("#sigma3","sigma3",10,0,50);
   RooAbsPdf *sig3 = new RooGaussian("sig3","sig3",*m,*mean3,*sigma3);

   RooRealVar *mean4 = new RooRealVar("#mu4","mean4",5279.34,5250,5300);
   RooRealVar *sigma4 = new RooRealVar("#sigma4","sigma4",10,0,20);
   RooAbsPdf *sig4 = new RooGaussian("sig4","sig4",*m,*mean4,*sigma4);

   // **** background ****
   RooRealVar *BkgMSlope = new RooRealVar("c_{exp}","Slope of mass bkg",-0.0005,-1.0,1.0);
   RooAbsPdf  *bkg = new RooExponential("bkg","bkg", *m, *BkgMSlope);

   RooRealVar *Nsig1 = new RooRealVar("nsig1","Number of signal events",1000,0,3000);
   RooRealVar *Nsig2 = new RooRealVar("nsig2","Number of signal events",1000,0,3000);
   RooRealVar *Nsig3 = new RooRealVar("nsig3","Number of signal events",1000,0,3000);
   RooRealVar *Nsig4 = new RooRealVar("nsig4","Number of signal events",1000,0,3000);
   RooRealVar *Nbkg = new RooRealVar("nbkg","Number of bkg",1000,0,3000);

   // **** total pdf and fit ****
   RooAbsPdf *total= new RooAddPdf("total","sum of signal and background PDF's",RooArgList(*sig1,*sig2,*sig3,*sig4,*bkg),RooArgList(*Nsig1,*Nsig2,*Nsig3,*Nsig4,*Nbkg));
   RooFitResult *fitres = total->fitTo(*data, Minos(kTRUE), Extended(kTRUE));

   RooArgSet *params = total->getParameters(data);
   params->writeToFile("params_fitLcXic.txt");

   // **** plot the distributions ****
   // #### Lc ####
   RooPlot *mframe=m->frame(Title("#Lambda_{c}^{+}#bar{#Xi_{c}^{#minus}} mass fit"));
   Int_t canvasWidth = 1200;
   Int_t canvasHeight = 800;
   TCanvas *c1 = new TCanvas("c1","fitted weighted Lc-Xic mass",canvasWidth,canvasHeight);
   c1->SetFillColor(kWhite);
   c1->Divide(1,2,0,0,0);

   data->plotOn(mframe,Binning(100),Name("Data"));

   total->plotOn(mframe,Components(*sig1),LineColor(1),LineStyle(kDashed),Name("state 1"));
   total->plotOn(mframe,Components(*sig2),LineColor(2),LineStyle(kDashed),Name("state 2"));
   total->plotOn(mframe,Components(*sig3),LineColor(3),LineStyle(kDashed),Name("state 3"));
   total->plotOn(mframe,Components(*sig4),LineColor(13),LineStyle(kDashed),Name("B^{+}"));
   total->plotOn(mframe,Components(*bkg),LineColor(kBlue),LineStyle(kDashed),Name("background"));
   total->plotOn(mframe,Name("total fit")); 
   //total->paramOn(mframe,Layout(0.70,0.95,0.97));
   //mframe->getAttText()->SetTextSize(0.04);

   double chi2 =  mframe->chiSquare(7);
   cout << " fitting chi square is : " << chi2 << endl;

   //TLatex* texchitwo = new TLatex(0.2,0.8,TString::Format("#chi^{2}/ndf = %f",chi2));
   //texchitwo->SetNDC();
   //mframe->addObject(texchitwo);

   c1->cd(2);
   gPad->SetTopMargin(0);
   gPad->SetLeftMargin(0.12);
   gPad->SetPad(0.02,0.02,0.98,0.77);
   mframe->GetYaxis()->SetTitleOffset(0.85);
   mframe->SetMaximum(120);
   mframe->Draw();

   TLegend *legend = new TLegend(0.3,0.4,0.8,0.9);
   legend->SetFillColor(kWhite);
   legend->SetLineColor(kWhite);
   legend->SetTextSize(0.04);
   legend->AddEntry("Data","Data");
   legend->AddEntry("total fit","Total fit","l");
   legend->AddEntry("state 1",Form("state 1:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean1->getVal(),mean1->getError(),sigma1->getVal(),sigma1->getError(),Nsig1->getVal(),Nsig1->getError()),"l");
   legend->AddEntry("state 2",Form("state 2:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean2->getVal(),mean2->getError(),sigma2->getVal(),sigma2->getError(),Nsig2->getVal(),Nsig2->getError()),"l");
   legend->AddEntry("state 3",Form("state 3:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean3->getVal(),mean3->getError(),sigma3->getVal(),sigma3->getError(),Nsig3->getVal(),Nsig3->getError()),"l");
   legend->AddEntry("B^{+}",Form("B^{+}:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean4->getVal(),mean4->getError(),sigma4->getVal(),sigma4->getError(),Nsig4->getVal(),Nsig4->getError()),"l");
   legend->AddEntry("background","background","l");
   legend->Draw();

   c1->cd(1);
   gPad->SetBottomMargin(0);
   gPad->SetLeftMargin(0.12);
   gPad->SetPad(0.02,0.76,0.98,0.97);
   RooHist* hpull = mframe->pullHist();
   RooPlot* mframe1 = m->frame(Title("Pull distribution"));
   hpull->SetFillColor(15);
   hpull->SetFillStyle(3002);
   mframe1->addPlotable(hpull,"L3");
   mframe1->GetYaxis()->SetNdivisions(505);
   mframe1->GetYaxis()->SetLabelSize(0.20);
   mframe1->SetMinimum(-5.0);
   mframe1->SetMaximum(5.0);
   mframe1->Draw();

   c1->SaveAs("fitLcXic0.png");
   c1->SaveAs("fitLcXic0.eps");
   c1->SaveAs("fitLcXic0.pdf");
} 
