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
   gROOT->ProcessLine(".x /home/Koishi//kc2023/LcXic0/datafiles/lhcbStyle.C");

   TCut MCut = "Lc_M>2210 && Lc_M<2360 && Xic_M>2420 && Xic_M<2540";
   TChain *chain = new TChain("DecayTree");
   chain->AddFile("/home/Koishi/kc2023/LcXic0/datafiles/XiccTuple_sw_corrected.root");

   RooRealVar *m = new RooRealVar("C_M_corrected","M(#Lambda_{c}^{+}#bar{#Xi_{c}^{#minus}})",4757,6757,"MeV/c^{2}");
   RooRealVar *nsig_sw = new RooRealVar("nsig_sw","signal weight",-2.0,2.0);

   RooDataSet *data_pre = new RooDataSet("data_pre","dataset with m",chain->CopyTree(MCut),RooArgSet(*m,*nsig_sw),nullptr,"nsig_sw");
   RooDataSet *data = new RooDataSet("data","dataset with m",chain->CopyTree(MCut),RooArgSet(*m));

   // **** signal,crystal ball ****
   // #### sig ####
   RooRealVar *mean1_pre = new RooRealVar("#mu1_pre","mean1_pre",4800,4775,4825);
   RooRealVar *sigma1_pre = new RooRealVar("#sigma1_pre","sigma1_pre",10,0,100);
   RooAbsPdf *sig1_pre = new RooGaussian("sig1_pre","sig1_pre",*m,*mean1_pre,*sigma1_pre);

   RooRealVar *mean2_pre = new RooRealVar("#mu2_pre","mean2_pre",5000,4950,5050);
   RooRealVar *sigma2_pre = new RooRealVar("#sigma2_pre","sigma2_pre",10,0,50);
   RooAbsPdf *sig2_pre = new RooGaussian("sig2_pre","sig2_pre",*m,*mean2_pre,*sigma2_pre);

   RooRealVar *mean3_pre = new RooRealVar("#mu3_pre","mean3_pre",5150,5100,5200);
   RooRealVar *sigma3_pre = new RooRealVar("#sigma3_pre","sigma3_pre",10,0,50);
   RooAbsPdf *sig3_pre = new RooGaussian("sig3_pre","sig3_pre",*m,*mean3_pre,*sigma3_pre);

   RooRealVar *mean4_pre = new RooRealVar("#mu4_pre","mean4_pre",5279.34,5250,5300);
   RooRealVar *sigma4_pre = new RooRealVar("#sigma4_pre","sigma4_pre",10,0,20);
   RooAbsPdf *sig4_pre = new RooGaussian("sig4_pre","sig4_pre",*m,*mean4_pre,*sigma4_pre);
   
   // **** background ****
   RooRealVar *BkgMSlope_pre = new RooRealVar("c_{exp}pre","Slope of mass bkg (pre)",-0.0005,-1.0,1.0);
   RooAbsPdf  *bkg_pre = new RooExponential("bkg_pre","bkg_pre", *m, *BkgMSlope_pre);

   RooRealVar *Nsig1_pre = new RooRealVar("nsig1_pre","pre Number of signal events",1000,0,3000);
   RooRealVar *Nsig2_pre = new RooRealVar("nsig2_pre","pre Number of signal events",1000,0,3000);
   RooRealVar *Nsig3_pre = new RooRealVar("nsig3_pre","pre Number of signal events",1000,0,3000);
   RooRealVar *Nsig4_pre = new RooRealVar("nsig4_pre","pre Number of signal events",1000,0,3000);
   RooRealVar *Nbkg_pre = new RooRealVar("nbkg_pre","pre Number of bkg",1000,0,3000);

   // **** total pdf and fit ****
   RooAbsPdf *total_pre= new RooAddPdf("total","sum of signal and background PDF's",RooArgList(*sig1_pre,*sig2_pre,*sig3_pre,*sig4_pre,*bkg_pre),RooArgList(*Nsig1_pre,*Nsig2_pre,*Nsig3_pre,*Nsig4_pre,*Nbkg_pre));
   RooFitResult *fit_pre = total_pre->fitTo(*data_pre, Minos(kTRUE), Extended(kTRUE));

   // **** signal ****

   RooRealVar *mean1 = new RooRealVar("#mu1","mean1",mean1_pre->getVal(),mean1_pre->getMin(),mean1_pre->getMax());
   RooRealVar *sigma1 = new RooRealVar("#sigma1","sigma1",sigma1_pre->getVal(),sigma1_pre->getMin(),sigma1_pre->getMax());
   //mean1->setConstant(true);sigma1->setConstant(true);
   RooAbsPdf *sig1 = new RooGaussian("sig1","sig1",*m,*mean1,*sigma1);

   RooRealVar *mean2 = new RooRealVar("#mu2","mean2",mean2_pre->getVal(),mean2_pre->getMin(),mean2_pre->getMax());
   RooRealVar *sigma2 = new RooRealVar("#sigma2","sigma2",sigma2_pre->getVal(),sigma2_pre->getMin(),sigma2_pre->getMax());
   //mean2->setConstant(true);sigma2->setConstant(true);
   RooAbsPdf *sig2 = new RooGaussian("sig2","sig2",*m,*mean2,*sigma2);

   RooRealVar *mean3 = new RooRealVar("#mu3","mean3",mean3_pre->getVal(),mean3_pre->getMin(),mean3_pre->getMax());
   RooRealVar *sigma3 = new RooRealVar("#sigma3","sigma3",sigma3_pre->getVal(),sigma3_pre->getMin(),sigma3_pre->getMax());
   //mean3->setConstant(true);sigma3->setConstant(true);
   RooAbsPdf *sig3 = new RooGaussian("sig3","sig3",*m,*mean3,*sigma3);

   RooRealVar *mean4 = new RooRealVar("#mu4","mean4",mean4_pre->getVal(),mean4_pre->getMin(),mean4_pre->getMax());
   RooRealVar *sigma4 = new RooRealVar("#sigma4","sigma4",sigma4_pre->getVal(),sigma4_pre->getMin(),sigma4_pre->getMax());
   //mean4->setConstant(true);sigma4->setConstant(true);
   RooAbsPdf *sig4 = new RooGaussian("sig4","sig4",*m,*mean4,*sigma4);

   // **** background ****
   RooRealVar *BkgMSlope = new RooRealVar("c_{exp}","Slope of mass bkg",BkgMSlope_pre->getVal(),BkgMSlope_pre->getMin(),BkgMSlope_pre->getMax());
   BkgMSlope->setConstant(true);
   RooAbsPdf *bkg = new RooExponential("bkg","bkg", *m, *BkgMSlope);

   TH1F *h_bb = new TH1F("h_bb","h_bb",200,4757,6757);
   TH1F *h_bs = new TH1F("h_bs","h_bs",200,4757,6757);
   TH1F *h_comb = new TH1F("h_comb","h_comb",200,4757,6757);
   chain->Project("h_bb","C_M_corrected","nbb_sw");
   chain->Project("h_bs","C_M_corrected","nbs_sw");
   h_comb->Add(h_bb);h_comb->Add(h_bs);
   RooDataHist *data_comb = new RooDataHist("data_comb","dataset with m", *m, h_comb);
   RooHistPdf *bkg_comb = new RooHistPdf("bkg_comb","bkg_comb",*m,*data_comb);

   RooRealVar *Nsig1 = new RooRealVar("nsig1","Number of signal events",Nsig1_pre->getVal(),Nsig1_pre->getMin(),Nsig1_pre->getMax());
   RooRealVar *Nsig2 = new RooRealVar("nsig2","Number of signal events",Nsig2_pre->getVal(),Nsig2_pre->getMin(),Nsig2_pre->getMax());
   RooRealVar *Nsig3 = new RooRealVar("nsig3","Number of signal events",Nsig3_pre->getVal(),Nsig3_pre->getMin(),Nsig3_pre->getMax());
   RooRealVar *Nsig4 = new RooRealVar("nsig4","Number of signal events",Nsig4_pre->getVal(),Nsig4_pre->getMin(),Nsig4_pre->getMax());
   RooRealVar *Nbkg = new RooRealVar("nbkg","Number of bkg",Nbkg_pre->getVal(),Nbkg_pre->getMin(),Nbkg_pre->getMax());
   //Nsig1->setConstant(true);Nsig2->setConstant(true);Nsig3->setConstant(true);Nsig4->setConstant(true);
   RooRealVar *Nbkg_comb = new RooRealVar("nbkg_comb","Number of bkg_comb",3954.336093,0,10000);
   Nbkg->setConstant(true);//Nbkg_comb->setConstant(true);

   // **** total pdf and fit ****
   RooAbsPdf *total= new RooAddPdf("total","sum of signal and background PDF's",RooArgList(*sig1,*sig2,*sig3,*sig4,*bkg,*bkg_comb),RooArgList(*Nsig1,*Nsig2,*Nsig3,*Nsig4,*Nbkg,*Nbkg_comb));
   RooFitResult *fit = total->fitTo(*data, Minos(kTRUE), Extended(kTRUE));

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
   total->plotOn(mframe,Components(*sig4),LineColor(4),LineStyle(kDashed),Name("B^{+}"));
   total->plotOn(mframe,Components(*bkg),LineColor(kBlue),LineStyle(kDashed),Name("background"));
   total->plotOn(mframe,Components(*bkg_comb),LineColor(18),Name("combined background"));
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

   TLegend *legend = new TLegend(0.3,0.5,0.8,0.9);
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
   legend->AddEntry("combined background","combined background","l");
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
