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
#define LcXic_Class_cxx
#include "LcXic_Class.h"

using namespace RooFit;
using namespace RooStats;

void fitsPlot()
{
   gROOT->ProcessLine(".x /home/Koishi/LcXic/datafiles/lhcbStyle.C");

   TCut tauCut("C_TAU*1000<0.12");
   TChain* chain = new TChain();
   chain->Add("/home/Koishi/LcXic/datafiles/XiccTuple.root/DecayTree");
   TTree* newtree = chain->CopyTree(tauCut);

   RooArgSet vars("Variables");
   RooRealVar m_Lc("Lc_M","M(#Lambda_{c}^{+})",2210,2360,"MeV/c^{2}");
   RooRealVar m_Xic("Xic_M","M(#bar{#Xi_{c}^{-}})",2420,2540,"MeV/c^{2}");
   vars.add(m_Lc);
   vars.add(m_Xic);

   RooDataSet data("data","dataset with m",newtree->CopyTree(""),vars);

   // **** signal,crystal ball ****
   
   RooRealVar aL0("aL0", "aL0",  1.37,  -10, 10);
   RooRealVar aL1("aL1", "aL1",  0.05429,  -10, 10);
   RooRealVar aL2("aL2", "aL2", -0.0009869, -10, 10);
   RooRealVar aR0("aR0", "aR0",  1.873,    -10, 10);
   RooRealVar aR1("aR1", "aR1", 0.07142, -10, 10);
   aL0.setConstant(true);
   aL1.setConstant(true);
   aL2.setConstant(true);
   aR0.setConstant(true);
   aR1.setConstant(true);
   
   // #### sig_Lc ####
   RooRealVar mean_Lc("#mu_Lc","mean_Lc",2287,2220,2360);
   RooRealVar sigma_Lc("#sigma_Lc","sigma_Lc",6,0.,20);
   RooRealVar alphal_Lc("al_Lc","alphal_Lc",1,0,5);
   RooRealVar alphar_Lc("ar_Lc","alphar_Lc",1,0,5);
   RooRealVar nl_Lc("nl_Lc","nl_Lc",10,0,20);
   RooRealVar nr_Lc("nr_Lc","nr_Lc",10,0,20);
   MyCB sig_Lc("sig_Lc","sig_Lc",m_Lc,mean_Lc,sigma_Lc,alphal_Lc,nl_Lc,alphar_Lc,nr_Lc);

   //RooRealVar nl_Lc("nl_Lc","nl_Lc",2.0);
   //RooRealVar nr_Lc("nr_Lc","nr_Lc",4.0);
   //RooFormulaVar alphal_Lc("al_Lc","alphal_Lc","@0+@1*@3+@2*@3*@3",RooArgSet(aL0,aL1,aL2,sigma_Lc));
   //RooFormulaVar alphar_Lc("ar_Lc","alphar_Lc","@0+@1*@2",RooArgSet(aR0,aR1,sigma_Lc));
   //RooCBShape sig_Lc("sig_Lc","sig_Lc",m_Lc,mean_Lc,sigma_Lc,alphal_Lc,alphar_Lc);

   //RooRealVar fsigma_Lc("fsigma_Lc","fsigma_Lc",1,0,2);
   //RooRealVar fsig_Lc("fsig_Lc","fsig_Lc",1,0,2);
   //RooRealVar sigma_Lc1("#sigma_Lc1","sigma_Lc1",6,0,20);
   //RooFormulaVar sigma_Lc2("#sigma_Lc2","@1*@0",RooArgList(sigma_Lc1,fsigma_Lc));
   //RooGaussian sig_Lc1("sig_Lc1","sig_Lc1",m_Xic,mean_Lc,sigma_Lc1);
   //RooGaussian sig_Lc2("sig_Lc2","sig_Lc2",m_Xic,mean_Lc,sigma_Lc2);
   //RooAddPdf sig_Lc("sig_Lc","sig_Lc",RooArgList(sig_Lc1,sig_Lc2),RooArgList(fsig_Lc));

   // #### sig_Xic ####
   RooRealVar mean_Xic("#mu_Xic","mean_Xic",2467,2420,2540);
   RooRealVar sigma_Xic("#sigma_Xic","sigma_Xic",6,0.,20);
   RooRealVar alphal_Xic("al_Xic","alphal_Xic",1,0,5);
   RooRealVar alphar_Xic("ar_Xic","alphar_Xic",1,0,5);
   RooRealVar nl_Xic("nl_Xic","nl_Xic",10,0,20);
   RooRealVar nr_Xic("nr_Xic","nr_Xic",10,0,20);
   MyCB sig_Xic("sig_Xic","sig_Xic",m_Xic,mean_Xic,sigma_Xic,alphal_Xic,nl_Xic,alphar_Xic,nr_Xic);

   //RooRealVar nl_Xic("nl_Xic","nl_Xic",2.0);
   //RooRealVar nr_Xic("nr_Xic","nr_Xic",4.0);
   //RooFormulaVar alphal_Xic("al_Xic","alphal_Xic","@0+@1*@3+@2*@3*@3",RooArgSet(aL0,aL1,aL2,sigma_Xic));
   //RooFormulaVar alphar_Xic("ar_Xic","alphar_Xic","@0+@1*@2",RooArgSet(aR0,aR1,sigma_Xic));
   //RooCBShape sig_Xic("sig_Xic","sig_Xic",m_Xic,mean_Xic,sigma_Xic,alphal_Xic,alphar_Xic);

   //RooRealVar fsigma_Xic("f_sigma","f_sigma",1,0,100);
   //RooRealVar fsig_Xic("f_sig","f_sig",1,0,2);
   //RooRealVar sigma_Xic1("#sigma_Xic1","sigma_Xic1",6,0,20);
   //RooFormulaVar sigma_Xic2("#sigma_Xic2","@1*@0",RooArgList(sigma_Xic1,fsigma_Xic));
   //RooGaussian sig_Xic1("sig_Xic1","sig_Xic1",m_Xic,mean_Xic,sigma_Xic1);
   //RooGaussian sig_Xic2("sig_Xic2","sig_Xic2",m_Xic,mean_Xic,sigma_Xic2);
   //RooAddPdf sig_Xic("sig_Xic","sig_Xic",RooArgList(sig_Xic1,sig_Xic2),RooArgList(fsig_Xic));
   
   //RooRealVar sigma_Xic("#sigma_Xic","sigma_Xic",6,0.,20);
   //RooGaussian sig_Xic("sig_Xic","sig_Xic",m_Xic,mean_Xic,sigma_Xic);

   // **** background ****
   // #### bkg (* sig) ####
   RooRealVar taua_Lc("#tau_{a#Lambda_{c}}","taua_Lc",-0.,-0.5,0.5);
   RooRealVar taua_Xic("#tau_{a#Xi_{c}}","taua_Xic",-0.,-0.5,0.5);
   RooExponential combbkga_Lc("exponentiala_Lc","exponential backgrounda1_Lc",m_Lc,taua_Lc);   
   RooExponential combbkga_Xic("exponentiala_Xic","exponential backgrounda1_Xic",m_Xic,taua_Xic);   

   // #### bkg (* bkg) ####
   RooRealVar taub_Lc("#tau_{b#Lambda_{c}}","taub_Lc",-0.,-0.5,0.5);
   RooRealVar taub_Xic("#tau_{b#Xi_{c}}","taub_Xic",-0.,-0.5,0.5);
   RooExponential combbkgb_Lc("exponentialb_Lc","exponential backgroundb1_Lc",m_Lc,taub_Lc);
   RooExponential combbkgb_Xic("exponentialb_Xic","exponential backgroundb2_Xic",m_Xic,taub_Xic);

   // **** product ****
   RooProdPdf sig("sig","sig",RooArgSet(sig_Lc,sig_Xic));
   RooProdPdf bkg1("bkg1","bkg1",RooArgSet(combbkga_Lc,sig_Xic));
   RooProdPdf bkg2("bkg2","bkg2",RooArgSet(sig_Lc,combbkga_Xic));
   RooRealVar f("f","f",0.5,0,1);
   RooAddPdf combbkg("bkg","bkg",RooArgSet(bkg1,bkg2),RooArgList(f));
   RooProdPdf bkg("combbkg","combbkg",RooArgSet(combbkgb_Lc,combbkgb_Xic));

   RooRealVar Nsig("nsig","Number of signal events",1000,0,5000);
   RooRealVar Nbkg("nbs","",1000,0,5000);
   RooRealVar Ncombbkg("nbb","",1000,0,5000);

   // **** total pdf and fit ****
   RooAddPdf total("total","sum of signal and background PDF's",RooArgList(sig,bkg,combbkg),RooArgList(Nsig,Nbkg,Ncombbkg));
   //RooAddPdf total("total","sum of signal and background PDF's",RooArgList(sig,bkg1,bkg2,combbkg),RooArgList(Nsig,Nbkg,Nbkg,Ncombbkg));
   total.fitTo(data, Minos(kTRUE), Extended(kTRUE));

   RooArgSet* params = total.getParameters(data);
   params->writeToFile("params_sPlot.txt");

   // **** plot the distributions ****
   // #### Lc ####
   RooPlot *m_Lc_frame=m_Lc.frame(Title("#Lambda_{c}^{+} mass fit"));
   data.plotOn(m_Lc_frame,Binning(100),Name("Data"));

   total.plotOn(m_Lc_frame,Components(sig),LineColor(kRed),LineStyle(kDashed),Name("#Lambda_{c}sig+#Xi_{c}sig"));
   total.plotOn(m_Lc_frame,Components(sig),FillColor(kRed),FillStyle(3013),DrawOption("F"),Name("#Lambda_{c}sig+#Xi_{c}sig fill"));
   total.plotOn(m_Lc_frame,Components(bkg1),LineColor(kGreen),LineStyle(kDashed),Name("#Lambda_{c}bkg+#Xi_{c}sig"));
   total.plotOn(m_Lc_frame,Components(bkg2),LineColor(kGreen+1),LineStyle(kDashed),Name("#Lambda_{c}sig+#Xi_{c}bkg"));
   total.plotOn(m_Lc_frame,Components(bkg),LineColor(kBlue),LineStyle(kDashed),FillColor(kBlue),Name("#Lambda_{c}bkg+#Xi_{c}bkg"));
   total.plotOn(m_Lc_frame,Components(bkg),FillColor(kBlue),FillStyle(3013),DrawOption("F"),Name("#Lambda_{c}bkg+#Xi_{c}bkg fill"));
   total.plotOn(m_Lc_frame,Name("Total fit")); 
   //total.paramOn(m_Lc_frame,Layout(0.70,0.95,0.97));
   //m_Lc_frame->getAttText()->SetTextSize(0.04);

   double chi2 =  m_Lc_frame->chiSquare(7);
   cout << " fitting chi square is : " << chi2 << endl;

   //TLatex* texchitwo = new TLatex(0.2,0.8,TString::Format("#chi^{2}/ndf = %f",chi2));
   //texchitwo->SetNDC();
   //m_Lc_frame->addObject(texchitwo);

   Int_t canvasWidth = 900;
   Int_t canvasHeight = 600;
   TCanvas *c_Lc = new TCanvas("c_Lc","fitted Lc mass",canvasWidth,canvasHeight);
   c_Lc->SetFillColor(kWhite);
   c_Lc->Divide(1,2,0,0,0);

   c_Lc->cd(2);
   gPad->SetTopMargin(0);
   gPad->SetLeftMargin(0.12);
   gPad->SetPad(0.02,0.02,0.98,0.77);
   m_Lc_frame->GetYaxis()->SetTitleOffset(0.85);
   m_Lc_frame->Draw();

   TLegend *legend = new TLegend(0.7,0.4,0.9,0.9);
   legend->SetFillColor(kWhite);
   legend->SetLineColor(kWhite);
   legend->SetTextSize(0.06);
   legend->AddEntry("Data","Data");
   legend->AddEntry("Total fit","Total fit","l");
   legend->AddEntry("#Lambda_{c}sig+#Xi_{c}sig","#Lambda_{c}^{+}+#bar{#Xi_{c}^{-}}","l");
   legend->AddEntry("#Lambda_{c}bkg+#Xi_{c}sig","bkg_{1}+#Xi_{c}^{-}","l");
   legend->AddEntry("#Lambda_{c}sig+#Xi_{c}bkg","#Lambda_{c}^{+}+bkg_{2}","l");
   legend->AddEntry("#Lambda_{c}bkg+#Xi_{c}bkg","bkg_{1}+bkg_{2}","l");
   legend->Draw();

   c_Lc->cd(1);
   gPad->SetBottomMargin(0);
   gPad->SetLeftMargin(0.12);
   gPad->SetPad(0.02,0.76,0.98,0.97);
   RooHist* hpull_Lc = m_Lc_frame->pullHist();
   RooPlot* m_Lc_frame2 = m_Lc.frame(Title("Pull distribution"));
   hpull_Lc->SetFillColor(15);
   hpull_Lc->SetFillStyle(3002);
   m_Lc_frame2->addPlotable(hpull_Lc,"L3");
   m_Lc_frame2->GetYaxis()->SetNdivisions(505);
   m_Lc_frame2->GetYaxis()->SetLabelSize(0.20);
   m_Lc_frame2->SetMinimum(-5.0);
   m_Lc_frame2->SetMaximum(5.0);
   m_Lc_frame2->Draw();

   c_Lc->SaveAs("fitLc.png");
   c_Lc->SaveAs("fitLc.eps");
   c_Lc->SaveAs("fitLc.pdf");

   // #### Xic ####
   RooPlot *m_Xic_frame=m_Xic.frame(Title("#bar{#Xi_{c}^{-}} mass fit"));
   data.plotOn(m_Xic_frame,Binning(100));

   total.plotOn(m_Xic_frame,Components(sig),LineColor(kRed),LineStyle(kDashed));
   total.plotOn(m_Xic_frame,Components(sig),FillColor(kRed),FillStyle(3013),DrawOption("F"));
   total.plotOn(m_Xic_frame,Components(bkg1),LineColor(kGreen),LineStyle(kDashed));
   total.plotOn(m_Xic_frame,Components(bkg2),LineColor(kGreen+1),LineStyle(kDashed));
   total.plotOn(m_Xic_frame,Components(bkg),LineColor(kBlue),LineStyle(kDashed));
   total.plotOn(m_Xic_frame,Components(bkg),FillColor(kBlue),FillStyle(3013),DrawOption("F"));
   total.plotOn(m_Xic_frame); 
   //total.paramOn(m_Xic_frame,Layout(0.70,0.95,0.97));
   //m_Xic_frame->getAttText()->SetTextSize(0.04);

   chi2 =  m_Xic_frame->chiSquare(7);
   cout << " fitting chi square is : " << chi2 << endl;

   //texchitwo = new TLatex(0.2,0.8,TString::Format("#chi^{2}/ndf = %f",chi2));
   //texchitwo->SetNDC();
   //m_Xic_frame->addObject(texchitwo);

   TCanvas *c_Xic = new TCanvas("c_Xic","fitted #Lambda_{c}^{-} mass",canvasWidth,canvasHeight);
   c_Xic->SetFillColor(kWhite);
   c_Xic->Divide(1,2,0,0,0);

   c_Xic->cd(2);
   gPad->SetTopMargin(0);
   gPad->SetLeftMargin(0.12);
   gPad->SetPad(0.02,0.02,0.98,0.77);
   m_Xic_frame->GetYaxis()->SetTitleOffset(0.85);
   m_Xic_frame->Draw();

   c_Xic->cd(1);
   gPad->SetBottomMargin(0);
   gPad->SetLeftMargin(0.12);
   gPad->SetPad(0.02,0.76,0.98,0.97);
   RooHist* hpull_Xic = m_Xic_frame->pullHist();
   RooPlot* m_Xic_frame2 = m_Xic.frame(Title("Pull distribution"));
   hpull_Xic->SetFillColor(15);
   hpull_Xic->SetFillStyle(3002);
   m_Xic_frame2->addPlotable(hpull_Xic,"L3");
   m_Xic_frame2->GetYaxis()->SetNdivisions(505);
   m_Xic_frame2->GetYaxis()->SetLabelSize(0.20);
   m_Xic_frame2->SetMinimum(-5.0);
   m_Xic_frame2->SetMaximum(5.0);
   m_Xic_frame2->Draw();

   c_Xic->SaveAs("fitXic.png");
   c_Xic->SaveAs("fitXic.eps");
   c_Xic->SaveAs("fitXic.pdf");

   //************************* sweight ***************************
   TFile* file = new TFile("XiccTuple_sw.root","recreate"); 
   TTree* tree = newtree->CloneTree(0);
   double nsig_sw,nbs_sw,nbb_sw;
   tree->Branch("nsig_sw",&nsig_sw,"nsig_sw/D");
   tree->Branch("nbs_sw",&nbs_sw,"nbs_sw/D");
   tree->Branch("nbb_sw",&nbb_sw,"nbb_sw/D");

#if 1 
   RooStats::SPlot* splot = new RooStats::SPlot("splot","splot",data,&total,RooArgList(Nsig,Nbkg,Ncombbkg));
   LcXic_Class t(newtree);

   cout<<"************ check number **************"<<endl;
   cout<<newtree->GetEntries("Lc_M>2210&&Lc_M<2360&&Xic_M>2420&&Xic_M<2540")<<endl;
   cout<<data.numEntries()<<endl;

   int j = -1;
   for(int i=0;i<newtree->GetEntries();i++){
      newtree->GetEntry(i);
	if(!(t.Lc_M>2210&&t.Lc_M<2360&&t.Xic_M>2420&&t.Xic_M<2540)) continue;
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
