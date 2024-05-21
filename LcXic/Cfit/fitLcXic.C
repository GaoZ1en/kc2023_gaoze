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
   gROOT->ProcessLine(".x /home/Koishi/kc2023/LcXic/datafiles/lhcbStyle.C");

   TCut MCut = "Lc_M>2210 && Lc_M<2360 && Xic_M>2420 && Xic_M<2540";
   TChain *tree = new TChain("DecayTree");
   tree->AddFile("/home/Koishi/kc2023/LcXic/datafiles/XiccTuple_sw_corrected.root");
   TTree *chain = tree->CopyTree(MCut);

   RooRealVar *m = new RooRealVar("C_M_corrected","M(#Lambda_{c}^{+}#bar{#Xi_{c}^{#minus}})",4755,6755,"MeV/c^{2}");
   RooRealVar *nsig_sw = new RooRealVar("nsig_sw","signal weight",-2.0,2.0);

   RooDataSet *data_pre = new RooDataSet("data_pre","dataset with m",chain->CopyTree(MCut),RooArgSet(*m,*nsig_sw),nullptr,"nsig_sw");
   RooDataSet *data = new RooDataSet("data","dataset with m",chain->CopyTree(MCut),RooArgSet(*m));

   // **** signal,crystal ball ****
   // #### sig ####
   RooRealVar *mean1_pre = new RooRealVar("#mu1_pre","mean1_pre",4788.66,4785,4795);
   RooRealVar *sigma1_pre = new RooRealVar("#sigma1_pre","sigma1_pre",20.17,15,25);
   RooAbsPdf *sig1_pre = new RooGaussian("sig1_pre","sig1_pre",*m,*mean1_pre,*sigma1_pre);

   RooRealVar *mean2_pre = new RooRealVar("#mu2_pre","mean2_pre",4911.53,4905,4915);
   RooRealVar *sigma2_pre = new RooRealVar("#sigma2_pre","sigma2_pre",15,10,16.92);
   RooAbsPdf *sig2_pre = new RooGaussian("sig2_pre","sig2_pre",*m,*mean2_pre,*sigma2_pre);

   RooRealVar *mean3_pre = new RooRealVar("#mu3_pre","mean3_pre",4947.32,4945,4955);
   RooRealVar *sigma3_pre = new RooRealVar("#sigma3_pre","sigma3_pre",2.30,0,5);
   RooAbsPdf *sig3_pre = new RooGaussian("sig3_pre","sig3_pre",*m,*mean3_pre,*sigma3_pre);

   RooRealVar *mean4_pre = new RooRealVar("#mu4_pre","mean4_pre",4985.75,4980,4990);
   RooRealVar *sigma4_pre = new RooRealVar("#sigma4_pre","sigma4_pre",20.07,15,25);
   RooAbsPdf *sig4_pre = new RooGaussian("sig4_pre","sig4_pre",*m,*mean4_pre,*sigma4_pre);
   
   RooRealVar *mean5_pre = new RooRealVar("#mu5_pre","mean5",5101.61,5095,5105);
   RooRealVar *sigma5_pre = new RooRealVar("#sigma5_pre","sigma5_pre",70,60,73.71);
   RooAbsPdf *sig5_pre = new RooGaussian("sig5_pre","sig5_pre",*m,*mean5_pre,*sigma5_pre);

   RooRealVar *mean6_pre = new RooRealVar("#mu6_pre","mean6_pre",5126.20,5120,5130);
   RooRealVar *sigma6_pre = new RooRealVar("#sigma6_pre","sigma6_pre",7.63,5,10);
   RooAbsPdf *sig6_pre = new RooGaussian("sig6_pre","sig6_pre",*m,*mean6_pre,*sigma6_pre);

   RooRealVar *mean7_pre = new RooRealVar("#mu7_pre","mean7_pre",5279.36,5275,5285);
   RooRealVar *sigma7_pre = new RooRealVar("#sigma7_pre","sigma7_pre",5.06,0,10);
   RooAbsPdf *sig7_pre = new RooGaussian("sig7_pre","sig7_pre",*m,*mean7_pre,*sigma7_pre);

   RooRealVar *mean8_pre = new RooRealVar("#mu8_pre","mean8_pre",5369.55,5365,5375);
   RooRealVar *sigma8_pre = new RooRealVar("#sigma8_pre","sigma8_pre",3.71,3.50,5);
   RooAbsPdf *sig8_pre = new RooGaussian("sig8_pre","sig8_pre",*m,*mean8_pre,*sigma8_pre);

   /*RooRealVar *mean9_pre = new RooRealVar("#mu9_pre","mean9_pre",5500.00,5450,5550);
   RooRealVar *sigma9_pre = new RooRealVar("#sigma9_pre","sigma9_pre",5.22,0,20);
   RooAbsPdf *sig9_pre = new RooGaussian("sig9_pre","sig9_pre",*m,*mean9_pre,*sigma9_pre);*/
  
   RooRealVar *mean10_pre = new RooRealVar("#mu10_pre","mean10_pre",4842.57,4835,4845);
   RooRealVar *sigma10_pre = new RooRealVar("#sigma10_pre","sigma10_pre",5.06,0,25.064);
   RooAbsPdf *sig10_pre = new RooGaussian("sig10_pre","sig10_pre",*m,*mean10_pre,*sigma10_pre);


   // **** background ****
   RooRealVar *BkgMSlope_pre = new RooRealVar("c_{exp}pre","Slope of mass bkg (pre)",-0.0005,-1.0,1.0);
   RooAbsPdf  *bkg_pre = new RooExponential("bkg_pre","bkg_pre", *m, *BkgMSlope_pre);

   RooRealVar *Nsig1_pre = new RooRealVar("nsig1_pre","pre Number of signal events",310.84,300,400);
   RooRealVar *Nsig2_pre = new RooRealVar("nsig2_pre","pre Number of signal events",150.19,140,200);
   RooRealVar *Nsig3_pre = new RooRealVar("nsig3_pre","pre Number of signal events",33.30,20,40);
   RooRealVar *Nsig4_pre = new RooRealVar("nsig4_pre","pre Number of signal events",185.08,180,250);
   RooRealVar *Nsig5_pre = new RooRealVar("nsig5_pre","pre Number of signal events",193.55,190,250);
   RooRealVar *Nsig6_pre = new RooRealVar("nsig6_pre","pre Number of signal events",24.78,20,30);
   RooRealVar *Nsig7_pre = new RooRealVar("nsig7_pre","pre Number of signal events",72.18,70,75);
   RooRealVar *Nsig8_pre = new RooRealVar("nsig8_pre","pre Number of signal events",8.0,0,20);
   //RooRealVar *Nsig9_pre = new RooRealVar("nsig9_pre","pre Number of signal events",1000,0,3000);
   RooRealVar *Nsig10_pre = new RooRealVar("nsig10_pre","pre Number of signal events",163,160,200);
   RooRealVar *Nbkg_pre = new RooRealVar("nbkg_pre","pre Number of bkg",1000,0,3000);

   // **** total pdf and fit ****
   RooAbsPdf *total_pre= new RooAddPdf("total","sum of signal and background PDF's",RooArgList(*sig1_pre,*sig2_pre,*sig3_pre,*sig4_pre,*sig5_pre,*sig6_pre,*sig7_pre,*sig8_pre,/*sig9_pre,*/*sig10_pre,*bkg_pre),RooArgList(*Nsig1_pre,*Nsig2_pre,*Nsig3_pre,*Nsig4_pre,*Nsig5_pre,*Nsig6_pre,*Nsig7_pre,*Nsig8_pre,/*Nsig9_pre,*/*Nsig10_pre,*Nbkg_pre));
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

   RooRealVar *mean5 = new RooRealVar("#mu5","mean5",mean5_pre->getVal(),mean5_pre->getMin(),mean5_pre->getMax());
   RooRealVar *sigma5 = new RooRealVar("#sigma5","sigma5",sigma5_pre->getVal(),sigma5_pre->getMin(),sigma5_pre->getMax());
   //mean5->setConstant(true);sigma5->setConstant(true);
   RooAbsPdf *sig5 = new RooGaussian("sig5","sig5",*m,*mean5,*sigma5);

   RooRealVar *mean6 = new RooRealVar("#mu6","mean6",mean6_pre->getVal(),mean6_pre->getMin(),mean6_pre->getMax());
   RooRealVar *sigma6 = new RooRealVar("#sigma6","sigma6",sigma6_pre->getVal(),sigma6_pre->getMin(),sigma6_pre->getMax());
   //mean6->setConstant(true);sigma6->setConstant(true);
   RooAbsPdf *sig6 = new RooGaussian("sig6","sig6",*m,*mean6,*sigma6);

   RooRealVar *mean7 = new RooRealVar("#mu7","mean7",mean7_pre->getVal(),mean7_pre->getMin(),mean7_pre->getMax());
   RooRealVar *sigma7 = new RooRealVar("#sigma7","sigma7",sigma7_pre->getVal(),sigma7_pre->getMin(),sigma7_pre->getMax());
   //mean7->setConstant(true);sigma7->setConstant(true);
   RooAbsPdf *sig7 = new RooGaussian("sig7","sig7",*m,*mean7,*sigma7);

   RooRealVar *mean8 = new RooRealVar("#mu8","mean8",mean8_pre->getVal(),mean8_pre->getMin(),mean8_pre->getMax());
   RooRealVar *sigma8 = new RooRealVar("#sigma8","sigma8",sigma8_pre->getVal(),sigma8_pre->getMin(),sigma8_pre->getMax());
   //mean8->setConstant(true);sigma8->setConstant(true);
   RooAbsPdf *sig8 = new RooGaussian("sig8","sig8",*m,*mean8,*sigma8);

   /*RooRealVar *mean9 = new RooRealVar("#mu9","mean9",mean9_pre->getVal(),mean9_pre->getMin(),mean9_pre->getMax());
   RooRealVar *sigma9 = new RooRealVar("#sigma9","sigma9",sigma9_pre->getVal(),sigma9_pre->getMin(),sigma9_pre->getMax());
   //mean9->setConstant(true);sigma9->setConstant(true);
   RooAbsPdf *sig9 = new RooGaussian("sig9","sig9",*m,*mean9,*sigma9);*/

   RooRealVar *mean10 = new RooRealVar("#mu10","mean10",mean10_pre->getVal(),mean10_pre->getMin(),mean10_pre->getMax());
   RooRealVar *sigma10 = new RooRealVar("#sigma10","sigma10",sigma10_pre->getVal(),sigma10_pre->getMin(),sigma10_pre->getMax());
   //mean10->setConstant(true);sigma10->setConstant(true);
   RooAbsPdf *sig10 = new RooGaussian("sig10","sig10",*m,*mean10,*sigma10);

   // **** background ****
   RooRealVar *BkgMSlope = new RooRealVar("c_{exp}","Slope of mass bkg",BkgMSlope_pre->getVal(),BkgMSlope_pre->getMin(),BkgMSlope_pre->getMax());
   BkgMSlope->setConstant(true);
   RooAbsPdf *bkg = new RooExponential("bkg","bkg", *m, *BkgMSlope);

   TH1F *h_bb = new TH1F("h_bb","h_bb",200,4755,6755);
   TH1F *h_bs = new TH1F("h_bs","h_bs",200,4755,6755);
   TH1F *h_comb = new TH1F("h_comb","h_comb",200,4755,6755);
   chain->Project("h_bb","C_M_corrected","nbb_sw");
   chain->Project("h_bs","C_M_corrected","nbs_sw");
   h_comb->Add(h_bb);h_comb->Add(h_bs);
   RooDataHist *data_comb = new RooDataHist("data_comb","dataset with m", *m, h_comb);
   RooHistPdf *bkg_comb = new RooHistPdf("bkg_comb","bkg_comb",*m,*data_comb);

   RooRealVar *Nsig1 = new RooRealVar("nsig1","Number of signal events",Nsig1_pre->getVal(),Nsig1_pre->getMin(),Nsig1_pre->getMax());
   RooRealVar *Nsig2 = new RooRealVar("nsig2","Number of signal events",Nsig2_pre->getVal(),Nsig2_pre->getMin(),Nsig2_pre->getMax());
   RooRealVar *Nsig3 = new RooRealVar("nsig3","Number of signal events",Nsig3_pre->getVal(),Nsig3_pre->getMin(),Nsig3_pre->getMax());
   RooRealVar *Nsig4 = new RooRealVar("nsig4","Number of signal events",Nsig4_pre->getVal(),Nsig4_pre->getMin(),Nsig4_pre->getMax());
   RooRealVar *Nsig5 = new RooRealVar("nsig5","Number of signal events",Nsig5_pre->getVal(),Nsig5_pre->getMin(),Nsig5_pre->getMax());
   RooRealVar *Nsig6 = new RooRealVar("nsig6","Number of signal events",Nsig6_pre->getVal(),Nsig6_pre->getMin(),Nsig6_pre->getMax());
   RooRealVar *Nsig7 = new RooRealVar("nsig7","Number of signal events",Nsig7_pre->getVal(),Nsig7_pre->getMin(),Nsig7_pre->getMax());
   RooRealVar *Nsig8 = new RooRealVar("nsig8","Number of signal events",Nsig8_pre->getVal(),Nsig8_pre->getMin(),Nsig8_pre->getMax());
   //RooRealVar *Nsig9 = new RooRealVar("nsig9","Number of signal events",Nsig9_pre->getVal(),Nsig9_pre->getMin(),Nsig9_pre->getMax());
   RooRealVar *Nsig10 = new RooRealVar("nsig10","Number of signal events",Nsig10_pre->getVal(),Nsig10_pre->getMin(),Nsig10_pre->getMax());
   RooRealVar *Nbkg = new RooRealVar("nbkg","Number of bkg",Nbkg_pre->getVal(),Nbkg_pre->getMin(),Nbkg_pre->getMax());
   //Nsig1->setConstant(true);Nsig2->setConstant(true);Nsig3->setConstant(true);Nsig4->setConstant(true);Nsig5->setConstant(true);
   //Nsig6->setConstant(true);Nsig7->setConstant(true);Nsig8->setConstant(true);Nsig10->setConstant(true);
   RooRealVar *Nbkg_comb = new RooRealVar("nbkg_comb","Number of bkg_comb",3983.09795,0,10000);
   Nbkg->setConstant(true);//Nbkg_comb->setConstant(true);

   // **** total pdf and fit ****
   RooAbsPdf *total= new RooAddPdf("total","sum of signal and background PDF's",RooArgList(*sig1,*sig2,*sig3,*sig4,*sig5,*sig6,*sig7,*sig8,/*sig9,*/*sig10,*bkg,*bkg_comb),RooArgList(*Nsig1,*Nsig2,*Nsig3,*Nsig4,*Nsig5,*Nsig6,*Nsig7,*Nsig8,/*Nsig9,*/*Nsig10,*Nbkg,*Nbkg_comb));
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
   total->plotOn(mframe,Components(*sig4),LineColor(4),LineStyle(kDashed),Name("state 4"));
   total->plotOn(mframe,Components(*sig5),LineColor(7),LineStyle(kDashed),Name("state 5"));
   total->plotOn(mframe,Components(*sig6),LineColor(9),LineStyle(kDashed),Name("state 6"));
   total->plotOn(mframe,Components(*sig7),LineColor(13),LineStyle(kDashed),Name("B^{0}"));
   total->plotOn(mframe,Components(*sig8),LineColor(11),LineStyle(kDashed),Name("B_{s}^{0}"));
   //total->plotOn(mframe,Components(*sig9),LineColor(12),LineStyle(kDashed),Name("state 8"));
   total->plotOn(mframe,Components(*sig10),LineColor(14),LineStyle(kDashed),Name("state 9"));
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

   TLegend *legend = new TLegend(0.3,0.4,0.8,0.9);
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
   legend->AddEntry("state 9",Form("state 7:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean10->getVal(),mean10->getError(),sigma10->getVal(),sigma10->getError(),Nsig10->getVal(),Nsig10->getError()),"l");
   legend->AddEntry("B_{s}^{0}",Form("B_{s}^{0}:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean8->getVal(),mean8->getError(),sigma8->getVal(),sigma8->getError(),Nsig8->getVal(),Nsig8->getError()),"l");
   legend->AddEntry("B^{0}",Form("B^{0}:mean=%.2f#pm%.2f, sigma=%.2f#pm%.2f, N=%.2f#pm%.2f",mean7->getVal(),mean7->getError(),sigma7->getVal(),sigma7->getError(),Nsig7->getVal(),Nsig7->getError()),"l");
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

   c1->SaveAs("fitLcXic.png");
   c1->SaveAs("fitLcXic.eps");
   c1->SaveAs("fitLcXic.pdf");
} 
