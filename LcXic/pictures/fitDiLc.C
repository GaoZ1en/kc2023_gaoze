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
#include "MyCB.h"
#include "MyCB.cxx"
#include "TIterator.h"
//#include "../MC_run2/parJ_MC.h"
#define DiLc_Class_cxx
#include "DiLc_Class.h"

using namespace RooFit;
using namespace RooStats;

void fitDiLc()
{
   gROOT->ProcessLine(".x /afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/lhcbStyle.C");

   TChain* newtree = new TChain();
   newtree->Add("/afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/XiccTuple.root/DecayTree");

   RooArgSet vars("Variables");
   RooRealVar m1("Lc_M","M(p_{1}K_{1}#pi_{1}",2220,2360,"MeV/c^{2}");
   RooRealVar m2("LcBar_M","M(p_{2}K_{2}#pi_{2})",2220,2360,"MeV/c^{2}");
   vars.add(m1);
   vars.add(m2);

   RooDataSet data("data","dataset with m",newtree->CopyTree(""),vars);

   // **** signal,crystal ball ****
   // #### sig ####
   RooRealVar mean("#mu","mean",2286.99,2220,2360);
   RooRealVar sigma1("#sigma","sigma1",5,0.,20);
   //RooRealVar sigma2Oversigma1("sigma2Oversigma1","sigma2Oversigma1",1,0,2);
   //RooFormulaVar sigma2("sigma2","@1 * @0", RooArgList(sigma1,sigma2Oversigma1));
   RooRealVar alphal("al","alphal",2,0,5);
   RooRealVar alphar("ar","alphar",2,0,5);
   RooRealVar nl("nl","nl",8,0,20);
   RooRealVar nr("nr","nr",8,0,20);
   //RooRealVar fCB("fCB","fCB",1,0,2);
   MyCB sig1("sig1","sig1",m1,mean,sigma1,alphal,nl,alphar,nr);
   //RooGaussian sig11("sig11","sig11",m1,mean,sigma1);
   //RooGaussian sig12("sig12","sig12",m1,mean,sigma1);
   //RooAddPdf sig1("sig1","sig1",RooArgList(sig11,sig12),fCB);
   MyCB sig2("sig2","sig2",m2,mean,sigma1,alphal,nl,alphar,nr);
   //RooGaussian sig21("sig21","sig21",m2,mean,sigma2);
   //RooGaussian sig22("sig22","sig22",m2,mean,sigma2);
   //RooAddPdf sig2("sig2","sig2",RooArgList(sig21,sig22),fCB);

   // **** background ****
   // #### bkg (* sig) ####
   RooRealVar taua("#tau_{a}","taua",-0.,-0.5,0.5);
   RooExponential combbkga1("exponentiala1","exponential backgrounda1",m1,taua);   
   RooExponential combbkga2("exponentiala2","exponential backgrounda2",m2,taua);   

   // #### bkg (* bkg) ####
   RooRealVar taub("#tau_{b}","taub",-0.,-0.5,0.5);
   RooExponential combbkgb1("exponentialb1","exponential backgroundb1",m1,taub);   
   RooExponential combbkgb2("exponentialb2","exponential backgroundb2",m2,taub);   

   // **** product ****
   RooProdPdf sig("sig","sig",RooArgSet(sig1,sig2));
   RooProdPdf bkg1("bkg1","bkg1",RooArgSet(combbkga1,sig2));
   RooProdPdf bkg2("bkg2","bkg2",RooArgSet(sig1,combbkga2));
   RooRealVar f("f","f",0.5);
   RooAddPdf combbkg("bkg","bkg",RooArgSet(bkg1,bkg2),RooArgList(f));
   RooProdPdf bkg("combbkg","combbkg",RooArgSet(combbkgb1,combbkgb2));

   RooRealVar Nsig("nsig","Number of signal events",10000,0,25000);
   RooRealVar Nbkg("nbs","",10000,0,25000);
   RooRealVar Ncombbkg("nbb","",10000,0,25000);

   // **** total pdf and fit ****
   RooAddPdf total("total","sum of signal and background PDF's",RooArgList(sig,bkg,combbkg),RooArgList(Nsig,Nbkg,Ncombbkg));
   //RooAddPdf total("total","sum of signal and background PDF's",RooArgList(sig,bkg1,bkg2,combbkg),RooArgList(Nsig,Nbkg,Nbkg,Ncombbkg));
   total.fitTo(data, Minos(kTRUE), Extended(kTRUE));

   RooArgSet* params = total.getParameters(data);
   //params->writeToFile("params_DiLc.txt");

   // **** plot the distributions ****
   // #### Lc ####
   RooPlot *m1frame=m1.frame(Title("Lc mass fit"));
   data.plotOn(m1frame,Binning(50));

   total.plotOn(m1frame,Components(sig),LineColor(kRed),LineStyle(kDashed));
   total.plotOn(m1frame,Components(bkg1),LineColor(kGreen),LineStyle(kDashed));
   total.plotOn(m1frame,Components(bkg2),LineColor(kGreen+1),LineStyle(kDashed));
   //total.plotOn(m1frame,Components(combbkg),LineColor(kViolet),LineStyle(kDashed));
   total.plotOn(m1frame,Components(bkg),LineColor(kBlue),LineStyle(kDashed));
   total.plotOn(m1frame); 
   total.paramOn(m1frame,Layout(0.70,0.95,0.97));
   m1frame->getAttText()->SetTextSize(0.04);

   double chi2 =  m1frame->chiSquare(7);
   cout << " fitting chi square is : " << chi2 << endl;

   Int_t canvasWidth = 900;
   Int_t canvasHeight = 600;
   TCanvas *c1 = new TCanvas("c1","fitted Lc mass",canvasWidth,canvasHeight);
   c1->SetFillColor(kWhite);
   gPad->SetTopMargin(0);
   gPad->SetLeftMargin(0.12);
   gPad->SetPad(0.02,0.02,0.98,0.77);
   m1frame->GetYaxis()->SetTitleOffset(0.85);
   m1frame->Draw();

   // #### LcBar ####
   RooPlot *m2frame=m2.frame(Title("Lc mass fit"));
   data.plotOn(m2frame,Binning(50));

   total.plotOn(m2frame,Components(sig),LineColor(kRed),LineStyle(kDashed));
   total.plotOn(m2frame,Components(bkg1),LineColor(kGreen),LineStyle(kDashed));
   total.plotOn(m2frame,Components(bkg2),LineColor(kGreen+1),LineStyle(kDashed));
   //total.plotOn(m2frame,Components(combbkg),LineColor(kViolet),LineStyle(kDashed));
   total.plotOn(m2frame,Components(bkg),LineColor(kBlue),LineStyle(kDashed));
   total.plotOn(m2frame); 
   total.paramOn(m2frame,Layout(0.70,0.95,0.97));
   m2frame->getAttText()->SetTextSize(0.04);

   chi2 =  m2frame->chiSquare(7);
   cout << " fitting chi square is : " << chi2 << endl;

   TCanvas *c2 = new TCanvas("c2","fitted Lc mass",canvasWidth,canvasHeight);
   c2->SetFillColor(kWhite);
   gPad->SetTopMargin(0);
   gPad->SetLeftMargin(0.12);
   gPad->SetPad(0.02,0.02,0.98,0.77);
   m2frame->GetYaxis()->SetTitleOffset(0.85);
   m2frame->Draw();

   //***************************** 2D ******************************
   TH2F *h_2D = new TH2F("h_2D","h_2D",50,2220,2360,50,2220,2360);
   newtree->Draw("Lc_M:LcBar_M>>h_2D");
   gStyle->SetPalette(kLightTemperature);
   gStyle->SetNumberContours(50);
   h_2D->GetXaxis()->SetTitle("#it{M}^{(2)}_{#it{pK#pi}} [MeV/c^{2}]");
   h_2D->GetXaxis()->SetTitleSize(0.05);
   h_2D->GetXaxis()->SetTitleOffset(1.4);
   h_2D->GetYaxis()->SetTitle("#it{M}^{(1)}_{#it{pK#pi}} [MeV/c^{2}]");
   h_2D->GetYaxis()->SetNdivisions(505);
   h_2D->GetYaxis()->SetTitleSize(0.05);
   h_2D->GetYaxis()->SetTitleOffset(1.4);
   h_2D->GetZaxis()->SetTitle("Candidates/(5 MeV/c^{2})^{2}");
   h_2D->GetZaxis()->SetTitleSize(0.05);
   h_2D->GetZaxis()->SetTitleOffset(1.);
   h_2D->SetMinimum(0.001);
   h_2D->GetXaxis()->SetLabelSize(0.04);
   h_2D->GetYaxis()->SetLabelSize(0.04);
   h_2D->GetZaxis()->SetLabelSize(0.04);

   gStyle->SetLineScalePS(2.);
   Int_t canvasWidth1 = 500;
   Int_t canvasHeight1 = 500;
   TCanvas *c_2D_1 = new TCanvas("c_2D_1","c_2D_1",canvasWidth1,canvasHeight1);
   gPad->SetPad(0.,0.,1.0,0.6);
   gPad->SetLeftMargin(0.2);
   gPad->SetRightMargin(0.2);
   gPad->SetTopMargin(0.05);
   gPad->SetBottomMargin(0.2);
   h_2D->Draw("COLZ");

   /*TH2F* datah = new TH2F("datah","datah",50,2220,2360,50,2220,2360);
   newtree->Draw("LcBar_M:Lc_M>>datah");
   TH1* modelh = total.createHistogram("modelh",m1,Binning(50,2220,2360),YVar(m2,Binning(50,2220,2360)));
   TCanvas* c3 = new TCanvas("c3","c3",900,600);
   modelh->GetXaxis()->SetTitle("M(p_{1}K_{1}#pi_{1})");
   modelh->GetYaxis()->SetTitle("M(p_{2}K_{2}#pi_{2})");
   modelh->GetXaxis()->SetLabelSize(0.05);
   modelh->GetYaxis()->SetLabelSize(0.05);
   modelh->GetXaxis()->SetTitleSize(0.05);
   modelh->GetYaxis()->SetNdivisions(505);
   modelh->GetYaxis()->SetTitleSize(0.05);
   modelh->GetXaxis()->SetTitleOffset(1.2);
   modelh->GetYaxis()->SetTitleOffset(1.2);
   gPad->SetRightMargin(0.1);
   modelh->Draw("COLZ");
   datah->SetMarkerSize(0.2);
   datah->Draw("SCAT,same");

   TH2F* datah2 = new TH2F("datah2","datah2",25,2220,2360,25,2220,2360);
   newtree->Draw("LcBar_M:Lc_M>>datah2");
   RooDataHist dataHist("dataHist","dataHist",RooArgSet(m1,m2),datah2);
   RooChi2Var chi2D("chi2D","chi2D",total,dataHist);
   double chi2_2D = chi2D.getVal()/(25.*25.-7.);
   cout<<"2Dchi2    "<<chi2_2D<<endl;

   TPaveText* text = new TPaveText(0.7,0.8,0.9,0.9,"NBNDC");
   text->AddText(TString::Format("#chi^{2}/ndf = %f",chi2_2D));
   text->SetFillColor(kWhite);
   text->SetShadowColor(kWhite);
   text->Draw();

   c3->SaveAs("plots/fitplot2D_datarun2.pdf");
   c3->SaveAs("plots/fitplot2D_datarun2.png");
   c3->SaveAs("plots/fitplot2D_datarun2.eps");*/



} 
