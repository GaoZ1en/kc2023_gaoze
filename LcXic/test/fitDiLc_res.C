#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLatex.h>
//#include <RooFFTConvPdf.h>
#include <RooDataSet.h>
#include <RooRealVar.h>
#include <RooFormulaVar.h>
#include <RooPlot.h>
#include <RooVoigtian.h>
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

void fitDiLc_res()
{
   gROOT->ProcessLine(".x /afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/lhcbStyle.C");

   TCut LcCut("Lc_TMVA_BDT>-0.27 && LcBar_TMVA_BDT>-0.27");

   TChain *chain = new TChain("DecayTree");
   TChain *chain_WS = new TChain("DecayTree");
   chain->AddFile("/afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/XiccTuple_sw.root");
   chain_WS->AddFile("/afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/XiccWSTuple_sw.root");
   TH1F *hRS = new TH1F("hRS","",500,4575,6075);
   TTree *tree = chain->CopyTree(LcCut);
   tree->Project("hRS","C_M-Lc_M-LcBar_M+2286.99*2","nsig_sw",LcCut);
   RooRealVar *m = new RooRealVar("C_M","M(#Lambda_{c}^{+}#bar{#Lambda_{c}^{#minus}})",4575,6075,"MeV/c^{2}");
   RooDataHist *data = new RooDataHist("data","dataset with m", *m, hRS);

   // **** signal,crystal ball ****
   // #### sig ####
   RooRealVar *a0 = new RooRealVar("a0","a0",-26.55,-30,30);
   RooRealVar *a1 = new RooRealVar("a1","a1",6.25e-3,-1,1);
   a0->setConstant(true);
   a1->setConstant(true);

   RooRealVar *mean2 = new RooRealVar("#mu2","mean2",4600,4575,4625);
   RooRealVar *width2 = new RooRealVar("#width2","width2",30,0,50);
   RooFormulaVar *res2 = new RooFormulaVar("res2","resolution 2","@0+@1*@2",RooArgSet(*a0,*a1,*mean2));
   RooAbsPdf *sig2 = new RooVoigtian("sig2","sig2",*m,*mean2,*width2,*res2);

   RooRealVar *mean3 = new RooRealVar("#mu3","mean3",4650,4625,4675);
   RooRealVar *width3 = new RooRealVar("#width3","width3",100,50,150);
   RooFormulaVar *res3 = new RooFormulaVar("res3","resolution 3","@0+@1*@2",RooArgSet(*a0,*a1,*mean3));
   RooAbsPdf *sig3 = new RooVoigtian("sig3","sig3",*m,*mean3,*width3,*res3);

   RooRealVar *mean4 = new RooRealVar("#mu4","mean4",4790,4740,4840);
   RooRealVar *width4 = new RooRealVar("#width4","width4",60,0,100);
   RooFormulaVar *res4 = new RooFormulaVar("res4","resolution 4","@0+@1*@2",RooArgSet(*a0,*a1,*mean4));
   RooAbsPdf *sig4 = new RooVoigtian("sig4","sig4",*m,*mean4,*width4,*res4);

   RooRealVar *mean5 = new RooRealVar("#mu5","mean5",4900,4850,4950);
   RooRealVar *width5 = new RooRealVar("#width5","width5",40,0,100);
   RooFormulaVar *res5 = new RooFormulaVar("res5","resolution 5","@0+@1*@2",RooArgSet(*a0,*a1,*mean5));
   RooAbsPdf *sig5 = new RooVoigtian("sig5","sig5",*m,*mean5,*width5,*res5);

   RooRealVar *mean6 = new RooRealVar("#mu6","mean6",5366.92,5350,5400);
   RooRealVar *width6 = new RooRealVar("#width6","width6",6.84,0,50);
   mean6->setConstant(true);
   width6->setConstant(true);
   RooFormulaVar *res6 = new RooFormulaVar("res6","resolution 6","@0+@1*@2",RooArgSet(*a0,*a1,*mean6));
   RooAbsPdf *sig6 = new RooVoigtian("sig6","sig6",*m,*mean6,*width6,*res6);

   RooRealVar *mean7 = new RooRealVar("#mu7","mean7",5000,4950,5050);
   RooRealVar *width7 = new RooRealVar("#width7","width7",100,0,200);
   RooFormulaVar *res7 = new RooFormulaVar("res7","resolution 7","@0+@1*@2",RooArgSet(*a0,*a1,*mean7));
   RooAbsPdf *sig7 = new RooVoigtian("sig7","sig7",*m,*mean7,*width7,*res7);

   RooRealVar *mean8 = new RooRealVar("#mu8","mean8",5000,4950,5050);
   RooRealVar *width8 = new RooRealVar("#width8","width8",100,0,200);
   RooFormulaVar *res8 = new RooFormulaVar("res8","resolution 8","@0+@1*@2",RooArgSet(*a0,*a1,*mean8));
   RooAbsPdf *sig8 = new RooVoigtian("sig8","sig8",*m,*mean8,*width8,*res8);

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

   data->plotOn(mframe,Binning(100),Name("Data"));

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
   legend->AddEntry("1?"        ,"unknown state 1, mean = 4598.77#pm0.91 MeV,   width = 33.91#pm4.22 MeV,   N = 1766#pm232","l");
   legend->AddEntry("#psi(4660)","#psi(4660)            , mean = 4661.88#pm4.08 MeV,   width = 107.4#pm15.0 MeV,   N = 3443#pm459","l");
   legend->AddEntry("#psi(4790)","#psi(4790)            , mean = 4763.74#pm9.31 MeV,   width = 68.78#pm26.60 MeV, N = 325#pm197","l");
   legend->AddEntry("#psi(4900)","#psi(4900)            , mean = 4900.55#pm3.47 MeV,   width = 44.93#pm14.03 MeV, N = 277#pm68","l");
   legend->AddEntry("B^{0}_{s}" ,"B_{s}                      , mean = 5366.92 MeV,            width = 6.84 MeV,                N = 42#pm10","l");
   legend->AddEntry("2?"        ,"unknown state 2, mean = 5025.62#pm10.35 MeV, width = 137.6#pm26.6 MeV, N = 484#pm96","l");
   legend->AddEntry("3?"        ,"unknown state 3, mean = 5025.62#pm10.35 MeV, width = 137.6#pm26.6 MeV, N = 484#pm96","l");
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

   c1->SaveAs("fitDiLc_res.png");
   c1->SaveAs("fitDiLc_res.eps");
   c1->SaveAs("fitDiLc_res.pdf");
} 
