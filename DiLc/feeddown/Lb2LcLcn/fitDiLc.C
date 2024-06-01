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
//#include "RooStats/ModelConfig.h"
//#include "RooStats/ProfileLikelihoodCalculator.h"
//#include "RooStats/HypoTestResult.h"
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
   gROOT->ProcessLine(".x /home/Koishi/Projects/kc2023/DiLc/datafiles/lhcbStyle.C");

   TCut LcCut("Lc_TMVA_BDT>-0.27 && LcBar_TMVA_BDT>-0.27 && Lc_M>2220 && LcBar_M>2220 && Lc_M<2360 && Lc_M<2360");

   TChain* chain = new TChain();
   chain->Add("/home/Koishi/Projects/kc2023/DiLc/feeddown/Lb2LcLcn/Lb2LcLcn_Sim.root/DecayTree");
   TTree* newtree = chain->CopyTree(LcCut);

   RooArgSet vars("Variables");
   RooRealVar m1("Lc_M","M(#Lambda_{c}^{+})",2220,2360,"MeV/c^{2}");
   RooRealVar m2("LcBar_M","M(#Lambda_{c}^{-})",2220,2360,"MeV/c^{2}");
   vars.add(m1);
   vars.add(m2);

   RooDataSet data("data","dataset with m",newtree->CopyTree(""),vars);

   // **** signal,crystal ball ****
   // #### sig ####
   RooRealVar mean("#mu","mean",2287,2220,2360);
   RooRealVar sigma1("#sigma","sigma1",6,0.,20);
   //RooRealVar sigma2Oversigma1("sigma2Oversigma1","sigma2Oversigma1",1,0,2);
   //RooFormulaVar sigma2("sigma2","@1 * @0", RooArgList(sigma1,sigma2Oversigma1));
   RooRealVar alphal("al","alphal",1.4,0,5);
   RooRealVar alphar("ar","alphar",1.4,0,5);
   RooRealVar nl("nl","nl",10,0,20);
   RooRealVar nr("nr","nr",10,0,20);
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
   params->writeToFile("params_Lb2LcLcn.txt");

   // **** plot the distributions ****
   // #### Lc ####
   RooPlot *m1frame=m1.frame(Title("#Lambda_{c}^{+} mass fit"));
   data.plotOn(m1frame,Binning(100),Name("Data"));

   total.plotOn(m1frame,Components(sig),LineColor(kRed),LineStyle(kDashed),Name("sig+sig"));
   total.plotOn(m1frame,Components(sig),FillColor(kRed),FillStyle(3013),DrawOption("F"),Name("sig+sig fill"));
   total.plotOn(m1frame,Components(bkg1),LineColor(kGreen),LineStyle(kDashed),Name("bkg+sig"));
   total.plotOn(m1frame,Components(bkg2),LineColor(kGreen+1),LineStyle(kDashed),Name("sig+bkg"));
   total.plotOn(m1frame,Components(bkg),LineColor(kBlue),LineStyle(kDashed),FillColor(kBlue),Name("bkg+bkg"));
   total.plotOn(m1frame,Components(bkg),FillColor(kBlue),FillStyle(3013),DrawOption("F"),Name("bkg+bkg fill"));
   total.plotOn(m1frame,Name("Total fit")); 
   //total.paramOn(m1frame,Layout(0.70,0.95,0.97));
   //m1frame->getAttText()->SetTextSize(0.04);

   double chi2 =  m1frame->chiSquare(7);
   cout << " fitting chi square is : " << chi2 << endl;

   //TLatex* texchitwo = new TLatex(0.2,0.8,TString::Format("#chi^{2}/ndf = %f",chi2));
   //texchitwo->SetNDC();
   //m1frame->addObject(texchitwo);

   Int_t canvasWidth = 900;
   Int_t canvasHeight = 600;
   TCanvas *c1 = new TCanvas("c1","fitted Lc mass",canvasWidth,canvasHeight);
   c1->SetFillColor(kWhite);
   c1->Divide(1,2,0,0,0);

   c1->cd(2);
   gPad->SetTopMargin(0);
   gPad->SetLeftMargin(0.12);
   gPad->SetPad(0.02,0.02,0.98,0.77);
   m1frame->GetYaxis()->SetTitleOffset(0.85);
   m1frame->Draw();

   TLegend *legend = new TLegend(0.7,0.4,0.9,0.9);
   legend->SetFillColor(kWhite);
   legend->SetLineColor(kWhite);
   legend->SetTextSize(0.06);
   legend->AddEntry("Data","Data");
   legend->AddEntry("Total fit","Total fit","l");
   legend->AddEntry("sig+sig","#Lambda_{c}^{+}+#Lambda_{c}^{-}","l");
   legend->AddEntry("bkg+sig","bkg_{1}+#Lambda_{c}^{-}","l");
   legend->AddEntry("sig+bkg","#Lambda_{c}^{+}+bkg_{2}","l");
   legend->AddEntry("bkg+bkg","bkg_{1}+bkg_{2}","l");
   legend->Draw();

   c1->cd(1);
   gPad->SetBottomMargin(0);
   gPad->SetLeftMargin(0.12);
   gPad->SetPad(0.02,0.76,0.98,0.97);
   RooHist* hpull1 = m1frame->pullHist();
   RooPlot* m1frame2 = m1.frame(Title("Pull distribution"));
   hpull1->SetFillColor(15);
   hpull1->SetFillStyle(3002);
   m1frame2->addPlotable(hpull1,"L3");
   m1frame2->GetYaxis()->SetNdivisions(505);
   m1frame2->GetYaxis()->SetLabelSize(0.20);
   m1frame2->SetMinimum(-5.0);
   m1frame2->SetMaximum(5.0);
   m1frame2->Draw();

   c1->SaveAs("fitLc.png");
   c1->SaveAs("fitLc.eps");
   c1->SaveAs("fitLc.pdf");

   // #### LcBar ####
   RooPlot *m2frame=m2.frame(Title("#Lambda_{c}^{-} mass fit"));
   data.plotOn(m2frame,Binning(100));

   total.plotOn(m2frame,Components(sig),LineColor(kRed),LineStyle(kDashed));
   total.plotOn(m2frame,Components(sig),FillColor(kRed),FillStyle(3013),DrawOption("F"));
   total.plotOn(m2frame,Components(bkg1),LineColor(kGreen),LineStyle(kDashed));
   total.plotOn(m2frame,Components(bkg2),LineColor(kGreen+1),LineStyle(kDashed));
   total.plotOn(m2frame,Components(bkg),LineColor(kBlue),LineStyle(kDashed));
   total.plotOn(m2frame,Components(bkg),FillColor(kBlue),FillStyle(3013),DrawOption("F"));
   total.plotOn(m2frame); 
   //total.paramOn(m2frame,Layout(0.70,0.95,0.97));
   //m2frame->getAttText()->SetTextSize(0.04);

   chi2 =  m2frame->chiSquare(7);
   cout << " fitting chi square is : " << chi2 << endl;

   //texchitwo = new TLatex(0.2,0.8,TString::Format("#chi^{2}/ndf = %f",chi2));
   //texchitwo->SetNDC();
   //m2frame->addObject(texchitwo);

   TCanvas *c2 = new TCanvas("c2","fitted #Lambda_{c}^{-} mass",canvasWidth,canvasHeight);
   c2->SetFillColor(kWhite);
   c2->Divide(1,2,0,0,0);

   c2->cd(2);
   gPad->SetTopMargin(0);
   gPad->SetLeftMargin(0.12);
   gPad->SetPad(0.02,0.02,0.98,0.77);
   m2frame->GetYaxis()->SetTitleOffset(0.85);
   m2frame->Draw();

   c2->cd(1);
   gPad->SetBottomMargin(0);
   gPad->SetLeftMargin(0.12);
   gPad->SetPad(0.02,0.76,0.98,0.97);
   RooHist* hpull2 = m2frame->pullHist();
   RooPlot* m2frame2 = m2.frame(Title("Pull distribution"));
   hpull2->SetFillColor(15);
   hpull2->SetFillStyle(3002);
   m2frame2->addPlotable(hpull2,"L3");
   m2frame2->GetYaxis()->SetNdivisions(505);
   m2frame2->GetYaxis()->SetLabelSize(0.20);
   m2frame2->SetMinimum(-5.0);
   m2frame2->SetMaximum(5.0);
   m2frame2->Draw();

   c2->SaveAs("fitLcBar.png");
   c2->SaveAs("fitLcBar.eps");
   c2->SaveAs("fitLcBar.pdf");

   //************************* sweight ***************************
   TFile* file = new TFile("Lb2LcLcn_sw.root","recreate"); 
   TTree* tree = newtree->CloneTree(0);
   double nsig_sw,nbs_sw,nbb_sw;
   tree->Branch("nsig_sw",&nsig_sw,"nsig_sw/D");
   tree->Branch("nbs_sw",&nbs_sw,"nbs_sw/D");
   tree->Branch("nbb_sw",&nbb_sw,"nbb_sw/D");

#if 1 
   RooStats::SPlot* splot = new RooStats::SPlot("splot","splot",data,&total,RooArgList(Nsig,Nbkg,Ncombbkg));
   DiLc_Class t(newtree);

   cout<<"************ check number **************"<<endl;
   cout<<newtree->GetEntries("Lc_M>2220&&Lc_M<2360&&LcBar_M>2220&&LcBar_M<2360")<<endl;
   cout<<data.numEntries()<<endl;

   int j = -1;
   for(int i=0;i<newtree->GetEntries();i++){
      newtree->GetEntry(i);
	if(!(t.Lc_M>2220&&t.Lc_M<2360&&t.LcBar_M>2220&&t.LcBar_M<2360)) continue;
	j += 1;
	nsig_sw = splot->GetSWeight(j,"nsig");
	nbs_sw = splot->GetSWeight(j,"nbs");
	nbb_sw = splot->GetSWeight(j,"nbb");

	tree->Fill();
   }
   tree->Write();
   file->Close();
#endif
} 
