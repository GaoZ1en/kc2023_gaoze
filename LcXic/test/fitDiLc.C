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
#include "RooStats/ModelConfig.h"
#include "RooStats/ProfileLikelihoodCalculator.h"
#include "RooStats/HypoTestResult.h"
#include "RooStats/SPlot.h"
#include "TIterator.h"
//#include "../MC_run2/parJ_MC.h"
#define DiLc_Class_cxx
#include "DiLc_Class.h"

using namespace RooFit;
using namespace RooStats;

void fitDiLc()
{
   gROOT->ProcessLine(".x /afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/lhcbStyle.C");

   TCut LcCut("Lc_TMVA_BDT>-0.27 && LcBar_TMVA_BDT>-0.27 && Lc_M>2220 && LcBar_M>2220 && Lc_M<2360 && Lc_M<2360");

   TChain *chain = new TChain("DecayTree");
   TChain *chain_WS = new TChain("DecayTree");
   chain->AddFile("/afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/XiccTuple_sw.root");
   chain_WS->AddFile("/afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/XiccWSTuple_sw.root");
   TH1F *hRS = new TH1F("hRS","",500,4575,6075);
   TTree *tree = chain->CopyTree(LcCut);
   tree->Project("hRS","C_M-Lc_M-LcBar_M+2286.99*2","nsig_sw");
   RooRealVar *m = new RooRealVar("C_M","M(#Lambda_{c}^{+}#bar{#Lambda_{c}^{#minus}})",4575,6075,"MeV/c^{2}");
   RooDataHist *data = new RooDataHist("data","dataset with m", *m, hRS);

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

   RooRealVar *mean8 = new RooRealVar("#mu8","mean8",5000,4950,5050);
   RooRealVar *sigma8 = new RooRealVar("#sigma8","sigma8",50,0,100);
   RooAbsPdf *sig8 = new RooGaussian("sig8","sig8",*m,*mean8,*sigma8);


   // **** background ****
   RooRealVar *BkgMSlope = new RooRealVar("c_{exp}","Slope of mass bkg",-0.0005,-1.0,1.0);
   RooAbsPdf  *bkg = new RooExponential("bkg","bkg", *m, *BkgMSlope);

   RooRealVar *Nsig2 = new RooRealVar("nsig2","Number of signal events",5000,0,10000);
   RooRealVar *Nsig3 = new RooRealVar("nsig3","Number of signal events",5000,0,10000);
   RooRealVar *Nsig4 = new RooRealVar("nsig4","Number of signal events",5000,0,10000);
   RooRealVar *Nsig5 = new RooRealVar("nsig5","Number of signal events",5000,0,10000);
   RooRealVar *Nsig6 = new RooRealVar("nsig6","Number of signal events",5000,0,10000);
   RooRealVar *Nsig7 = new RooRealVar("nsig7","Number of signal events",5000,0,10000);
   RooRealVar *Nsig8 = new RooRealVar("nsig8","Number of signal events",5000,0,10000);
   RooRealVar *Nbkg = new RooRealVar("nbkg","Number of bkg",5000,0,10000);

   // **** total pdf and fit ****
   RooAbsPdf *total= new RooAddPdf("total","sum of signal and background PDF's",RooArgList(*sig2,*sig3,*sig4,*sig5,*sig6,*sig7,*sig8,*bkg),RooArgList(*Nsig2,*Nsig3,*Nsig4,*Nsig5,*Nsig6,*Nsig7,*Nsig8,*Nbkg));
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

   data->plotOn(mframe,Binning(500),Name("Data"));

   total->plotOn(mframe,Components(*sig2),LineColor(1),LineStyle(kDashed),Name("1?"));
   total->plotOn(mframe,Components(*sig3),LineColor(2),LineStyle(kDashed),Name("#psi(4660)"));
   total->plotOn(mframe,Components(*sig4),LineColor(3),LineStyle(kDashed),Name("#psi(4790)"));
   total->plotOn(mframe,Components(*sig5),LineColor(4),LineStyle(kDashed),Name("#psi(4900)"));
   total->plotOn(mframe,Components(*sig6),LineColor(7),LineStyle(kDashed),Name("B^{0}_{s}"));
   total->plotOn(mframe,Components(*sig7),LineColor(6),LineStyle(kDashed),Name("2?"));
   total->plotOn(mframe,Components(*sig8),LineColor(8),LineStyle(kDashed),Name("3?"));
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
   legend->AddEntry("1?"        ,"unknown state 1, mean = 4597.35#pm0.78 MeV,   sigma = 14.33#pm1.46 MeV,   N = 1240#pm227","l");
   legend->AddEntry("#psi(4660)","#psi(4660)            , mean = 4651.11#pm5.65 MeV,   sigma = 42.53#pm7.88 MeV,   N = 2776#pm627","l");
   legend->AddEntry("#psi(4790)","#psi(4790)            , mean = 4756.23#pm25.67 MeV, sigma = 48.43#pm16.39 MeV, N = 896#pm500","l");
   legend->AddEntry("#psi(4900)","#psi(4900)            , mean = 4896.09#pm4.81 MeV,   sigma = 28.57#pm5.34 MeV,  N = 301#pm72","l");
   legend->AddEntry("B^{0}_{s}" ,"B_{s}                      , mean = 5366.92 MeV,            sigma = 6.84 MeV,                N = 33#pm8","l");
   legend->AddEntry("2?"        ,"unknown state 2, mean = 5018.96#pm11.91 MeV, sigma = 65.44#pm11.34 MeV, N = 410#pm78","l");
   legend->AddEntry("3?"        ,"unknown state 2, mean = 5018.96#pm11.91 MeV, sigma = 65.44#pm11.34 MeV, N = 410#pm78","l");
   legend->AddEntry("WS background","WS background","l");
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
