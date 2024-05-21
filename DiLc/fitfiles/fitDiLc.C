#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLatex.h>
//#include <RooFFTConvPdf.h>
#include <RooDataSet.h>
#include <RooRealVar.h>
#include <RooPlot.h>
#include <RooGaussian.h>
#include <RooArgusBG.h>
#include <RooConstVar.h>
#include <RooAddPdf.h>
#include <RooWorkspace.h>
#include <RooAbsData.h>
#include <RooRealVar.h>
//#include "RooStats/ModelConfig.h"
//#include "RooStats/ProfileLikelihoodCalculator.h"
//#include "RooStats/HypoTestResult.h"
#include "RooStats/SPlot.h"
#include "TIterator.h"
//#include "../MC_run2/parJ_MC.h"
#define DiLc_Class_cxx
#include "DiLc_Class.h"

using namespace RooFit;
using namespace RooStats;

void fitDiLc()
{
   gROOT->ProcessLine(".x /home/Koishi/kc2023/DiLc/datafiles/lhcbStyle.C");

   TCut LcCut("Lc_TMVA_BDT>-0.27 && LcBar_TMVA_BDT>-0.27 && Lc_M>2220 && LcBar_M>2220 && Lc_M<2360 && LcBar_M<2360");

   TChain *chain = new TChain("DecayTree");
   chain->AddFile("/home/Koishi/kc2023/DiLc/datafiles/XiccTuple_sw_corrected.root");

   RooRealVar *m = new RooRealVar("C_M_corrected","M(#Lambda_{c}^{+}#bar{#Lambda}_{c}^{#minux})",4575,6075,"MeV/c^{2}");
   RooRealVar *nsig_sw = new RooRealVar("nsig_sw","signal weight",-2,2);

   RooDataSet *data = new RooDataSet("data","dataset with m", chain->CopyTree(LcCut),RooArgSet(*m,*nsig_sw),nullptr,"nsig_sw");

   // **** signal,crystal ball ****
   // #### sig ####
   RooRealVar *mean2 = new RooRealVar("#mu2","mean2",4600,4575,4650);
   RooRealVar *sigma2 = new RooRealVar("#sigma2","sigma2",20,0,50);
   RooAbsPdf *sig2 = new RooGaussian("sig2","sig2",*m,*mean2,*sigma2);

   RooRealVar *mean3 = new RooRealVar("#mu3","mean3",4650,4610,4710);
   RooRealVar *sigma3 = new RooRealVar("#sigma3","sigma3",40,0,100);
   RooAbsPdf *sig3 = new RooGaussian("sig3","sig3",*m,*mean3,*sigma3);

   RooRealVar *mean4 = new RooRealVar("#mu4","mean4",4790,4700,4840);
   RooRealVar *sigma4 = new RooRealVar("#sigma4","sigma4",50,0,100);
   RooAbsPdf *sig4 = new RooGaussian("sig4","sig4",*m,*mean4,*sigma4);

   RooRealVar *mean5 = new RooRealVar("#mu5","mean5",4900,4850,4950);
   RooRealVar *sigma5 = new RooRealVar("#sigma5","sigma5",50,0,100);
   RooAbsPdf *sig5 = new RooGaussian("sig5","sig5",*m,*mean5,*sigma5);

   RooRealVar *mean6 = new RooRealVar("#mu6","mean6",5366.92,5350,5400);
   RooRealVar *sigma6 = new RooRealVar("#sigma6","sigma6",6.84,0,20);
   mean6->setConstant(true);
   sigma6->setConstant(true);
   RooAbsPdf *sig6 = new RooGaussian("sig6","sig6",*m,*mean6,*sigma6);

   RooRealVar *mean7 = new RooRealVar("#mu7","mean7",5000,4950,5050);
   RooRealVar *sigma7 = new RooRealVar("#sigma7","sigma7",50,0,100);
   RooAbsPdf *sig7 = new RooGaussian("sig7","sig7",*m,*mean7,*sigma7);

   // **** background ****
   RooRealVar *BkgMSlope = new RooRealVar("c_{exp}","Slope of mass bkg",-0.0005,-1.0,1.0);
   RooAbsPdf  *bkg = new RooExponential("bkg","bkg", *m, *BkgMSlope);

   RooRealVar *Nsig2 = new RooRealVar("nsig2","Number of signal events",5000,1,10000);
   RooRealVar *Nsig3 = new RooRealVar("nsig3","Number of signal events",5000,1,10000);
   RooRealVar *Nsig4 = new RooRealVar("nsig4","Number of signal events",5000,1,10000);
   RooRealVar *Nsig5 = new RooRealVar("nsig5","Number of signal events",5000,1,10000);
   RooRealVar *Nsig6 = new RooRealVar("nsig6","Number of signal events",5000,1,10000);
   RooRealVar *Nsig7 = new RooRealVar("nsig7","Number of signal events",5000,1,10000);
   RooRealVar *Nbkg = new RooRealVar("nbkg","Number of bkg",1000,1,10000);

   // **** total pdf and fit ****
   RooAbsPdf *total= new RooAddPdf("total","sum of signal and background PDF's",RooArgList(*sig2,*sig3,*sig4,*sig5,*sig6,*sig7,*bkg),RooArgList(*Nsig2,*Nsig3,*Nsig4,*Nsig5,*Nsig6,*Nsig7,*Nbkg));
   RooFitResult *fitres = total->fitTo(*data, Minos(kTRUE), Extended(kTRUE));

   RooArgSet *params = total->getParameters(data);
   //params->writeToFile("params_DiLc.txt");

   // **** plot the distributions ****
   // #### Lc ####
   RooPlot *mframe=m->frame(Title("#Lambda_{c}^{+}#Lambda_{c}^{-} mass fit"));
   Int_t canvasWidth = 1200;
   Int_t canvasHeight = 800;
   TCanvas *c1 = new TCanvas("c1","fitted weighted Lc-LcBar mass",canvasWidth,canvasHeight);
   c1->SetFillColor(kWhite);
   c1->Divide(1,2,0,0,0);

   data->plotOn(mframe,Binning(100),Name("Data"));

   total->plotOn(mframe,Components(*sig2),LineColor(1),LineStyle(kDashed),Name("1?"));
   total->plotOn(mframe,Components(*sig3),LineColor(2),LineStyle(kDashed),Name("#psi(4660)"));
   total->plotOn(mframe,Components(*sig4),LineColor(3),LineStyle(kDashed),Name("#psi(4790)"));
   total->plotOn(mframe,Components(*sig5),LineColor(4),LineStyle(kDashed),Name("#psi(4900)"));
   total->plotOn(mframe,Components(*sig6),LineColor(7),LineStyle(kDashed),Name("B^{0}_{s}"));
   total->plotOn(mframe,Components(*sig7),LineColor(6),LineStyle(kDashed),Name("2?"));
   total->plotOn(mframe,Components(*bkg),LineColor(kBlue),LineStyle(kDashed),Name("WS background"));
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
   mframe->Draw();

   TLegend *legend = new TLegend(0.23,0.4,0.43,0.9);
   legend->SetFillColor(kWhite);
   legend->SetLineColor(kWhite);
   legend->SetTextSize(0.04);
   legend->AddEntry("Data","Data");
   legend->AddEntry("total fit","Total fit","l");
   legend->AddEntry("1?",Form("unknown state 1:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean2->getVal(),mean2->getError(),sigma2->getVal(),sigma2->getError(),Nsig2->getVal(),Nsig2->getError()),"l");
   legend->AddEntry("#psi(4660)",Form("#psi(4660):mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean3->getVal(),mean3->getError(),sigma3->getVal(),sigma3->getError(),Nsig3->getVal(),Nsig3->getError()),"l");
   legend->AddEntry("#psi(4790)",Form("#psi(4790):mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean4->getVal(),mean4->getError(),sigma4->getVal(),sigma4->getError(),Nsig4->getVal(),Nsig4->getError()),"l");
   legend->AddEntry("#psi(4900)",Form("#psi(4900):mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean5->getVal(),mean5->getError(),sigma5->getVal(),sigma5->getError(),Nsig5->getVal(),Nsig5->getError()),"l");
   legend->AddEntry("B^{0}_{s}",Form("B_{s}^{0}:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean6->getVal(),mean6->getError(),sigma6->getVal(),sigma6->getError(),Nsig6->getVal(),Nsig6->getError()),"l");
   legend->AddEntry("2?",Form("unknown state 2:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean7->getVal(),mean7->getError(),sigma7->getVal(),sigma7->getError(),Nsig7->getVal(),Nsig7->getError()),"l");
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

   c1->SaveAs("fitDiLc.png");
   c1->SaveAs("fitDiLc.eps");
   c1->SaveAs("fitDiLc.pdf");
} 
