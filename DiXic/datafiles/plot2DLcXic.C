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

void plot2DLcXic()
{
   gROOT->ProcessLine(".x /home/Koishi/LcXic/datafiles/lhcbStyle.C");

   TChain* chain = new TChain("DecayTree");
   chain->Add("/home/Koishi/LcXic/datafiles/XiccTuple.root");
   TTree* newtree = chain->CopyTree("");

   //***************************** 2D ******************************
   TH2F *h_2D = new TH2F("h_2D","h_2D",50,2210,2360,50,2390,2540);
   newtree->Draw("Xic_M:Lc_M>>h_2D");
   gStyle->SetPalette(kLightTemperature);
   gStyle->SetNumberContours(50);
   h_2D->GetXaxis()->SetTitle("#it{M}^{(2)}_{#it{#Lambda_{c}^{+}}} [MeV/c^{2}]");
   h_2D->GetXaxis()->SetTitleSize(0.05);
   h_2D->GetXaxis()->SetTitleOffset(1.4);
   h_2D->GetYaxis()->SetTitle("#it{M}^{(1)}_{#it{#bar{#Xi_{c}^{#minus}}}} [MeV/c^{2}]");
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
   Int_t canvasWidth = 900;
   Int_t canvasHeight = 800;
   TCanvas *c_2D = new TCanvas("c_2D","c_2D",canvasWidth,canvasHeight);
   gPad->SetPad(0.,0.,1.0,0.9);
   gPad->SetLeftMargin(0.2);
   gPad->SetRightMargin(0.2);
   gPad->SetTopMargin(0.05);
   gPad->SetBottomMargin(0.2);
   h_2D->Draw("COLZ");

   c_2D->SaveAs("fitplot2D.pdf");
   c_2D->SaveAs("fitplot2D.png");
   c_2D->SaveAs("fitplot2D.eps");
} 
