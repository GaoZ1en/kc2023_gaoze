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
#define DiLc_Class_cxx
#include "LcXic_Class.h"

using namespace RooFit;
using namespace RooStats;

void fitLcXic()
{
   gROOT->ProcessLine(".x /home/Koishi/LcXic/taucut/fitfromb/lhcbStyle.C");

   TCut MCut = "Lc_M>2210 && Lc_M<2360 && Xic_M>2420 && Xic_M<2540";
   TChain *chain = new TChain("DecayTree");
   chain->AddFile("/home/Koishi/LcXic/datafiles/XiccTuple_sw_corrected.root");

   RooRealVar *m = new RooRealVar("C_M_corrected","M(#Lambda_{c}^{+}#bar{#Xi_{c}^{#minus}})",4755,6755,"MeV/c^{2}");
   RooRealVar *nsig_sw = new RooRealVar("nsig_sw","signal weight",-2.0,2.0);

   RooDataSet *data = new RooDataSet("data","dataset with m",chain->CopyTree(MCut),RooArgSet(*m,*nsig_sw),nullptr,"nsig_sw");


   // **** signal,crystal ball ****
   // #### sig ####
   RooRealVar *mean1 = new RooRealVar("#mu1","mean1",4800,4775,4825);
   RooRealVar *sigma1 = new RooRealVar("#sigma1","sigma1",10,0,100);
   RooAbsPdf *sig1 = new RooGaussian("sig1","sig1",*m,*mean1,*sigma1);

   RooRealVar *mean2 = new RooRealVar("#mu2","mean2",4906.5,4875,4925);
   RooRealVar *sigma2 = new RooRealVar("#sigma2","sigma2",20,0,50);
   RooAbsPdf *sig2 = new RooGaussian("sig2","sig2",*m,*mean2,*sigma2);

   RooRealVar *mean3 = new RooRealVar("#mu3","mean3",4950,4925,4975);
   RooRealVar *sigma3 = new RooRealVar("#sigma3","sigma3",10,0,50);
   RooAbsPdf *sig3 = new RooGaussian("sig3","sig3",*m,*mean3,*sigma3);

   RooRealVar *mean4 = new RooRealVar("#mu4","mean4",4975,4900,5025);
   RooRealVar *sigma4 = new RooRealVar("#sigma4","sigma4",10,0,50);
   RooAbsPdf *sig4 = new RooGaussian("sig4","sig4",*m,*mean4,*sigma4);
   
   RooRealVar *mean5 = new RooRealVar("#mu5","mean5",5000,4800,5200);
   RooRealVar *sigma5 = new RooRealVar("#sigma5","sigma5",20,0,100);
   RooAbsPdf *sig5 = new RooGaussian("sig5","sig5",*m,*mean5,*sigma5);

   RooRealVar *mean6 = new RooRealVar("#mu6","mean6",5125,5100,5150);
   RooRealVar *sigma6 = new RooRealVar("#sigma6","sigma6",10,0,20);
   RooAbsPdf *sig6 = new RooGaussian("sig6","sig6",*m,*mean6,*sigma6);

   RooRealVar *mean7 = new RooRealVar("#mu7","mean7",5279.66,5250,5300);
   RooRealVar *sigma7 = new RooRealVar("#sigma7","sigma7",10,0,20);
   RooAbsPdf *sig7 = new RooGaussian("sig7","sig7",*m,*mean7,*sigma7);

   RooRealVar *mean8 = new RooRealVar("#mu8","mean8",5375,5350,5400);
   RooRealVar *sigma8 = new RooRealVar("#sigma8","sigma8",10,0,20);
   RooAbsPdf *sig8 = new RooGaussian("sig8","sig8",*m,*mean8,*sigma8);

   /*RooRealVar *mean9 = new RooRealVar("#mu9","mean9",5500,5450,5550);
   RooRealVar *sigma9 = new RooRealVar("#sigma9","sigma9",10,5,20);
   RooAbsPdf *sig9 = new RooGaussian("sig9","sig9",*m,*mean9,*sigma9);*/
  
   RooRealVar *mean10 = new RooRealVar("#mu10","mean10",4840,4820,4860);
   RooRealVar *sigma10 = new RooRealVar("#sigma10","sigma10",10,0,25.064);
   RooAbsPdf *sig10 = new RooGaussian("sig10","sig10",*m,*mean10,*sigma10);


   // **** background ****
   RooRealVar *BkgMSlope = new RooRealVar("c_{exp}","Slope of mass bkg",-0.0005,-1.0,1.0);
   RooAbsPdf  *bkg = new RooExponential("bkg","bkg", *m, *BkgMSlope);

   RooRealVar *Nsig1 = new RooRealVar("nsig1","Number of signal events",1000,0,3000);
   RooRealVar *Nsig2 = new RooRealVar("nsig2","Number of signal events",1000,0,3000);
   RooRealVar *Nsig3 = new RooRealVar("nsig3","Number of signal events",1000,0,3000);
   RooRealVar *Nsig4 = new RooRealVar("nsig4","Number of signal events",1000,0,3000);
   RooRealVar *Nsig5 = new RooRealVar("nsig5","Number of signal events",1000,0,3000);
   RooRealVar *Nsig6 = new RooRealVar("nsig6","Number of signal events",1000,0,3000);
   RooRealVar *Nsig7 = new RooRealVar("nsig7","Number of signal events",1000,0,3000);
   RooRealVar *Nsig8 = new RooRealVar("nsig8","Number of signal events",1000,0,3000);
   //RooRealVar *Nsig9 = new RooRealVar("nsig9","Number of signal events",1000,0,3000);
   RooRealVar *Nsig10 = new RooRealVar("nsig10","Number of signal events",1000,0,3000);
   RooRealVar *Nbkg = new RooRealVar("nbkg","Number of bkg",1000,0,3000);

   // **** total pdf and fit ****
   RooAbsPdf *total= new RooAddPdf("total","sum of signal and background PDF's",RooArgList(*sig1,*sig2,*sig3,*sig4,*sig5,*sig6,*sig7,*sig8,/*sig9,*/*sig10,*bkg),RooArgList(*Nsig1,*Nsig2,*Nsig3,*Nsig4,*Nsig5,*Nsig6,*Nsig7,*Nsig8,/*Nsig9,*/*Nsig10,*Nbkg));
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
   total->plotOn(mframe,Components(*sig4),LineColor(4),LineStyle(kDashed),Name("state 4"));
   total->plotOn(mframe,Components(*sig5),LineColor(7),LineStyle(kDashed),Name("state 5"));
   total->plotOn(mframe,Components(*sig6),LineColor(9),LineStyle(kDashed),Name("state 6"));
   total->plotOn(mframe,Components(*sig7),LineColor(13),LineStyle(kDashed),Name("B^{0}"));
   total->plotOn(mframe,Components(*sig8),LineColor(11),LineStyle(kDashed),Name("B_{s}"));
   //total->plotOn(mframe,Components(*sig9),LineColor(12),LineStyle(kDashed),Name("state 8"));
   total->plotOn(mframe,Components(*sig10),LineColor(14),LineStyle(kDashed),Name("state 9"));
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
   mframe->SetMaximum(300);
   mframe->Draw();

   TLegend *legend = new TLegend(0.3,0.55,0.8,0.9);
   legend->SetFillColor(kWhite);
   legend->SetLineColor(kWhite);
   legend->SetTextSize(0.04);
   legend->AddEntry("Data","Data");
   legend->AddEntry("total fit","Total fit","l");
   legend->AddEntry("state 1",Form("state 1:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean1->getVal(),mean1->getError(),sigma1->getVal(),sigma1->getError(),Nsig1->getVal(),Nsig1->getError()),"l");
   legend->AddEntry("state 2",Form("state 2:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean2->getVal(),mean2->getError(),sigma2->getVal(),sigma2->getError(),Nsig2->getVal(),Nsig2->getError()),"l");
   legend->AddEntry("state 3",Form("state 3:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean3->getVal(),mean3->getError(),sigma3->getVal(),sigma3->getError(),Nsig3->getVal(),Nsig3->getError()),"l");
   legend->AddEntry("state 4",Form("state 4:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean4->getVal(),mean4->getError(),sigma4->getVal(),sigma4->getError(),Nsig4->getVal(),Nsig4->getError()),"l");
   legend->AddEntry("state 5",Form("state 5:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean5->getVal(),mean5->getError(),sigma5->getVal(),sigma5->getError(),Nsig5->getVal(),Nsig5->getError()),"l");
   legend->AddEntry("state 6",Form("state 6:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean6->getVal(),mean6->getError(),sigma6->getVal(),sigma6->getError(),Nsig6->getVal(),Nsig6->getError()),"l");
   //legend->AddEntry("state 7",Form("state 7:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean9->getVal(),mean9->getError(),sigma9->getVal(),sigma9->getError(),Nsig9->getVal(),Nsig9->getError()),"l");
   legend->AddEntry("B_{s}",Form("B_{s}:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean8->getVal(),mean8->getError(),sigma8->getVal(),sigma8->getError(),Nsig8->getVal(),Nsig8->getError()),"l");
   legend->AddEntry("state 9",Form("state 7:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean10->getVal(),mean10->getError(),sigma10->getVal(),sigma10->getError(),Nsig10->getVal(),Nsig10->getError()),"l");
   legend->AddEntry("B_{0}",Form("B_{0}:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean7->getVal(),mean7->getError(),sigma7->getVal(),sigma7->getError(),Nsig7->getVal(),Nsig7->getError()),"l");
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

   c1->SaveAs("fitLcXic.png");
   c1->SaveAs("fitLcXic.eps");
   c1->SaveAs("fitLcXic.pdf");
} 
