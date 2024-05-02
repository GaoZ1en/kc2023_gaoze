// $Id: $
using namespace RooFit;

void drawRes( TTree* tMC,
              TCut totCuts, 
              const char* variable,
              TString fileName,
              TString xLabel,
              TString unit, 
              Double_t ValMin,
              Double_t ValMax,
              Bool_t useLogy = false,
              Int_t nBins=100,
              TString filePrefix=""
              )
{
  
  TCanvas *MyCan = new TCanvas("MyCan", "",600, 480 );
  
  if( useLogy ) gPad->SetLogy();
  else gPad->SetLogy(0);

  const Double_t ParaLayXMin = 0.60 ;
  const Double_t ParaLayXMax = 0.95 ;
  const Double_t ParaLayYMax = 0.95 ;

  const Double_t LatexXMin = 0.18 ;
  const Double_t LatexY1 = 0.85 ;
  const Double_t LatexY2 = 0.78 ;

  TH1F *hsig = new TH1F("hsig", "", nBins, ValMin, ValMax );
  
  tMC->Project("hsig", variable, totCuts );
  
  const Double_t YMax = hsig->GetMaximum(); 
  
  //Parameters
  Double_t muInt = (ValMin + ValMax)*0.5;
  Double_t sigmaInt1 = ValMax*0.2;
  Double_t sigmaInt2 = ValMax*0.6;

  RooRealVar x("x",xLabel, ValMin,ValMax, unit) ;
  RooRealVar mean("#mu","mean of gaussians",muInt, ValMin, ValMax, unit ) ;
  RooRealVar sigma1("#sigma_{1}","width of gaussian 1", sigmaInt1,  0,ValMax, unit ) ;
  RooRealVar sigma2("#sigma_{2}","width of gaussian 2", sigmaInt2,  0,ValMax, unit ) ;
  
  //PDF
  RooGaussian gauss1("gauss1","gaussian PDF",x, mean,sigma1) ;
  RooGaussian gauss2("gauss2","gaussian PDF",x, mean,sigma2) ;
  
  // Add the components
  RooRealVar fracg1("f_{1}","fraction of gauss1",0.5, 0, 1.0) ;
  
  RooAddPdf sum("sum","g1+g2",RooArgList(gauss1,gauss2 ),
                RooArgList(fracg1)) ;
  //TH1* histo = h;
  RooDataHist bdata("bdata","bdata",RooArgList(x), hsig);
  RooFitResult* fitres = sum.fitTo(bdata, Save(true) );
  RooArgSet *paramList = sum.getParameters(bdata);
  paramList->Print("v");
  //Could work only "r" in fitTo
  // To calculate one gaussian SIGMA
  Double_t frac1Val = fracg1.getVal();
  
  Double_t sigma1Val = sigma1.getVal();
  Double_t sigma2Val = sigma2.getVal();
  
  Double_t SigmaGau =  TMath::Sqrt( frac1Val*sigma1Val*sigma1Val
                                    + (1.-frac1Val)*sigma2Val*sigma2Val );
  char text[1024];

  sprintf(text,"#sigma = %4.2f", SigmaGau );    
  
  RooPlot* xframe = x.frame();
  xframe->SetTitle("");
  xframe->GetYaxis()->SetNdivisions(505);
  bdata.plotOn(xframe, Name("MyHist") ) ;
  sum.plotOn(xframe, Name("MyCurv") ) ;
  sum.paramOn( xframe, Layout( ParaLayXMin, ParaLayXMax, ParaLayYMax ) );
  //sum.paramOn( xframe, Layout( 0.60, 0.90, 0.90 ) );
  
  TLatex *L1 = new TLatex( LatexXMin, LatexY1, text);
  L1->SetNDC();
  L1->SetTextSize(0.05);
  xframe->addObject( L1 );
  
  Double_t chiSn = xframe->chiSquare("MyCurv", "MyHist");
  char text2[1024];
  sprintf(text2,"#chi^{2}/ndf: %4.2f", chiSn );
  TLatex *L2 = new TLatex( LatexXMin ,LatexY2, text2);
  L2->SetTextSize(0.05);
  L2->SetNDC();
  xframe->addObject( L2 );
  
  xframe->Draw();

  fileName = filePrefix+ fileName +"_Res";

  TString epsName = fileName + ".eps";
  TString pdfName = fileName + ".pdf";
  TString gifName = fileName + ".gif";
    
  MyCan->Print(epsName);
  MyCan->Print(pdfName); 
  MyCan->Print(gifName);

  delete xframe;
  delete MyCan;
  delete hsig;

  cout << fileName + " fit done." << endl;
}

void drawRes_sg( TTree* tMC,
              TCut totCuts,
              const char* variable,
              TString fileName,
              TString xLabel,
              TString unit,
              Double_t ValMin,
              Double_t ValMax,
              Bool_t useLogy = false,
              Int_t nBins=100,
              TString filePrefix=""
              )
{

  TCanvas *MyCan = new TCanvas("MyCan", "",600, 480 );

  if( useLogy ) gPad->SetLogy();
  else gPad->SetLogy(0);

  const Double_t ParaLayXMin = 0.60 ;
  const Double_t ParaLayXMax = 0.95 ;
  const Double_t ParaLayYMax = 0.95 ;

  const Double_t LatexXMin = 0.18 ;
  const Double_t LatexY1 = 0.85 ;
  const Double_t LatexY2 = 0.78 ;

  TH1F *hsig = new TH1F("hsig", "", nBins, ValMin, ValMax );

  tMC->Project("hsig", variable, totCuts );

  const Double_t YMax = hsig->GetMaximum();

  //Parameters
  Double_t muInt = (ValMin + ValMax)*0.5;
  Double_t sigmaInt = ValMax*0.5;

  RooRealVar x("x",xLabel, ValMin,ValMax, unit) ;
  RooRealVar mean("#mu","mean of gaussians",muInt, ValMin, ValMax, unit ) ;
  RooRealVar sigma("#sigma","width of gaussian", sigmaInt,  0,ValMax, unit ) ;

  //PDF
  RooGaussian gauss("gauss","gaussian PDF",x, mean,sigma) ;

  //TH1* histo = h;
  RooDataHist bdata("bdata","bdata",RooArgList(x), hsig);
  RooFitResult* fitres = gauss.fitTo(bdata, Save(true) );
  RooArgSet *paramList = gauss.getParameters(bdata);
  paramList->Print("v");
  //Could work only "r" in fitTo
  // To calculate one gaussian SIGMA

  Double_t sigmaVal = sigma.getVal();

  Double_t SigmaGau =  TMath::Sqrt( sigmaVal*sigmaVal );
  char text[1024];

  sprintf(text,"#sigma = %4.2f", SigmaGau );

  RooPlot* xframe = x.frame();
  xframe->SetTitle("");
  xframe->GetYaxis()->SetNdivisions(505);
  bdata.plotOn(xframe, Name("MyHist") ) ;
  gauss.plotOn(xframe, Name("MyCurv") ) ;
  gauss.paramOn( xframe, Layout( ParaLayXMin, ParaLayXMax, ParaLayYMax ) );
  gauss.paramOn( xframe, Layout( 0.60, 0.90, 0.90 ) );
  
  TLatex *L1 = new TLatex( LatexXMin, LatexY1, text);
  L1->SetNDC();
  L1->SetTextSize(0.05);
  xframe->addObject( L1 );

  Double_t chiSn = xframe->chiSquare("MyCurv", "MyHist");
  char text2[1024];
  sprintf(text2,"#chi^{2}/ndf: %4.2f", chiSn );
  TLatex *L2 = new TLatex( LatexXMin ,LatexY2, text2);
  L2->SetTextSize(0.05);
  L2->SetNDC();
  xframe->addObject( L2 );

  xframe->Draw();

  fileName = filePrefix+ fileName +"_Res";

  TString epsName = fileName + ".eps";
  TString pdfName = fileName + ".pdf";
  TString gifName = fileName + ".gif";

  MyCan->Print(epsName);
  MyCan->Print(pdfName);
  MyCan->Print(gifName);

  delete xframe;
  delete MyCan;
  delete hsig;

  cout << fileName + " fit done." << endl;
}

void drawRes_ts( TTree* tMC,
              TCut totCuts,
              const char* variable,
              TString fileName,
              TString xLabel,
              TString unit,
              Double_t ValMin,
              Double_t ValMax,
              Bool_t useLogy = false,
              Int_t nBins=100,
              TString filePrefix=""
              )
{

  TCanvas *MyCan = new TCanvas("MyCan", "",600, 480 );

  if( useLogy ) gPad->SetLogy();
  else gPad->SetLogy(0);

  const Double_t ParaLayXMin = 0.60 ;
  const Double_t ParaLayXMax = 0.95 ;
  const Double_t ParaLayYMax = 0.95 ;

  const Double_t LatexXMin = 0.18 ;
  const Double_t LatexY1 = 0.85 ;
  const Double_t LatexY2 = 0.78 ;

  TH1F *hsig = new TH1F("hsig", "", nBins, ValMin, ValMax );

  tMC->Project("hsig", variable, totCuts );

  const Double_t YMax = hsig->GetMaximum();

  //Parameters
  Double_t muInt = (ValMin + ValMax)*0.5;
  Double_t sigmaInt1 = ValMax*0.2;
  Double_t sigmaInt2 = ValMax*0.4;
  Double_t sigmaInt3 = ValMax*0.6;

  RooRealVar x("x",xLabel, ValMin,ValMax, unit) ;
  RooRealVar mean("#mu","mean of gaussians",muInt, ValMin, ValMax, unit ) ;
  RooRealVar sigma1("#sigma_{1}","width of gaussian 1", sigmaInt1,  0,ValMax, unit ) ;
  RooRealVar sigma2("#sigma_{2}","width of gaussian 2", sigmaInt2,  0,ValMax, unit ) ;
  RooRealVar sigma3("#sigma_{3}","width of gaussian 3", sigmaInt3,  0,ValMax, unit ) ;

  //PDF
  RooGaussian gauss1("gauss1","gaussian PDF",x, mean,sigma1) ;
  RooGaussian gauss2("gauss2","gaussian PDF",x, mean,sigma2) ;
  RooGaussian gauss3("gauss3","gaussian PDF",x, mean,sigma3) ;

  // Add the components
  RooRealVar fracg1("f_{1}","fraction of gauss1",0.5, 0, 1.0) ;
  RooRealVar fracg2("f_{2}","fraction of gauss2",0.5, 0, 1.0) ;

  RooAddPdf sum("sum","g1+g2",RooArgList(gauss1,gauss2,gauss3 ),
  RooArgList(fracg1,fracg2)) ;
  //TH1* histo = h;
  RooDataHist bdata("bdata","bdata",RooArgList(x), hsig);
  RooFitResult* fitres = sum.fitTo(bdata, Save(true) );
  RooArgSet *paramList = sum.getParameters(bdata);
  paramList->Print("v");
  //Could work only "r" in fitTo
  // To calculate one gaussian SIGMA
  Double_t frac1Val = fracg1.getVal();
  Double_t frac2Val = fracg2.getVal();

  Double_t sigma1Val = sigma1.getVal();
  Double_t sigma2Val = sigma2.getVal();
  Double_t sigma3Val = sigma3.getVal();

  Double_t SigmaGau =  TMath::Sqrt( frac1Val*sigma1Val*sigma1Val + frac2Val*sigma2Val*sigma2Val
                                    + (1.-frac1Val-frac2Val)*sigma3Val*sigma3Val );
  char text[1024];

  sprintf(text,"#sigma = %4.2f", SigmaGau );

  RooPlot* xframe = x.frame();
  xframe->SetTitle("");
  xframe->GetYaxis()->SetNdivisions(505);
  bdata.plotOn(xframe, Name("MyHist") ) ;
  sum.plotOn(xframe, Name("MyCurv") ) ;
  sum.paramOn( xframe, Layout( ParaLayXMin, ParaLayXMax, ParaLayYMax ) );
  sum.paramOn( xframe, Layout( 0.60, 0.90, 0.90 ) );
  
  TLatex *L1 = new TLatex( LatexXMin, LatexY1, text);
  L1->SetNDC();
  L1->SetTextSize(0.05);
  xframe->addObject( L1 );

  Double_t chiSn = xframe->chiSquare("MyCurv", "MyHist");
  char text2[1024];
  sprintf(text2,"#chi^{2}/ndf: %4.2f", chiSn );
  TLatex *L2 = new TLatex( LatexXMin ,LatexY2, text2);
  L2->SetTextSize(0.05);
  L2->SetNDC();
  xframe->addObject( L2 );

  xframe->Draw();

  fileName = filePrefix+ fileName +"_Res";

  TString epsName = fileName + ".eps";
  TString pdfName = fileName + ".pdf";
  TString gifName = fileName + ".gif";

  MyCan->Print(epsName);
  MyCan->Print(pdfName);
  MyCan->Print(gifName);

  delete xframe;
  delete MyCan;
  delete hsig;

  cout << fileName + " fit done." << endl;
}

void drawPull( TTree* tMC,
               TCut totCuts, 
               const char* variable,
               TString fileName,
               TString xLabel,
               TString unit, 
               Double_t ValMin,
               Double_t ValMax,
               Bool_t useLogy = false,
               Int_t nBins=100,
               TString filePrefix=""
              )
{
  
  TCanvas *MyCan = new TCanvas("MyCan", "",600, 480 );
  
  if( useLogy ) gPad->SetLogy();
  else gPad->SetLogy(0);

  const Double_t ParaLayXMin = 0.60 ;
  const Double_t ParaLayXMax = 0.95 ;
  const Double_t ParaLayYMax = 0.95 ;

  const Double_t LatexXMin = 0.18 ;
  const Double_t LatexY1 = 0.85 ;
  const Double_t LatexY2 = 0.78 ;
  
  TH1F *hsig = new TH1F("hsig", "", nBins, ValMin, ValMax );
  
  tMC->Project("hsig", variable, totCuts );
  
  const Double_t YMax = hsig->GetMaximum(); 
  
  //Parameters
  Double_t muInt = (ValMin + ValMax)*0.5;
  Double_t sigmaInt = ValMax*0.2;

  RooRealVar x("x",xLabel, ValMin,ValMax, unit) ;
  RooRealVar mean("#mu","mean of gaussians",muInt, ValMin, ValMax, unit ) ;
  RooRealVar sigma("#sigma","width of gaussian 1", sigmaInt,  0,ValMax, unit ) ;

  //PDF
  RooGaussian sum("sum","gaussian PDF",x, mean,sigma) ;

  RooDataHist bdata("bdata","bdata",RooArgList(x), hsig);
  RooFitResult* fitres = sum.fitTo(bdata, Save(true));
  RooArgSet *paramList = sum.getParameters(bdata);
  paramList->Print("v");
  
  RooPlot* xframe = x.frame();
  xframe->SetTitle("");
  xframe->GetYaxis()->SetNdivisions(505);
  bdata.plotOn(xframe, Name("MyHist") ) ;
  sum.plotOn(xframe, Name("MyCurv") ) ;
  sum.paramOn( xframe, Layout( ParaLayXMin, ParaLayXMax, ParaLayYMax ) );
  
  Double_t chiSn = xframe->chiSquare("MyCurv", "MyHist");
  char text2[1024];
  sprintf(text2,"#chi^{2}/ndf: %4.2f", chiSn );
  TLatex *L2 = new TLatex( LatexXMin ,LatexY2, text2);
  L2->SetTextSize(0.05);
  L2->SetNDC();
  xframe->addObject( L2 );
  
  xframe->Draw();

  fileName = filePrefix+fileName +"_Pull";

  TString epsName = fileName + ".eps";
  TString pdfName = fileName + ".pdf";
  TString gifName = fileName + ".gif";
    
  MyCan->Print(epsName);
  MyCan->Print(pdfName); 
  MyCan->Print(gifName);

  delete xframe;
  delete MyCan;
  delete hsig;

  cout << fileName + " fit done." << endl; 
}

void loadFilesToChain (TChain *chain, const std::string &filename){
  string line;
  ifstream source(filename.c_str(), ios::in);
  while ( getline (source, line) )
  {
    // you may want to clean line here...
    chain->AddFile( line.c_str() );
  }
}

void ResAndPull()
{
  gROOT->ProcessLine(".x /afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/lhcbStyle.C");

  TChain *tBs = new TChain("XiccTuple/DecayTree");
  loadFilesToChain( tBs, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bs2LcLc_Turbo_MC16_Sim09l_MagDown_2024_01_30.txt");
  loadFilesToChain( tBs, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bs2LcLc_Turbo_MC16_Sim09l_MagUp_2024_01_30.txt");
  loadFilesToChain( tBs, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bs2LcLc_Turbo_MC17_Sim09l_MagDown_2024_01_30.txt");
  loadFilesToChain( tBs, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bs2LcLc_Turbo_MC17_Sim09l_MagUp_2024_01_30.txt");
  loadFilesToChain( tBs, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bs2LcLc_Turbo_MC18_Sim09l_MagDown_2024_01_30.txt");
  loadFilesToChain( tBs, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bs2LcLc_Turbo_MC18_Sim09l_MagUp_2024_01_30.txt");

  TChain *tBd = new TChain("XiccTuple/DecayTree");
  loadFilesToChain( tBd, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC16_Sim09l_MagDown_2024_01_29.txt");
  loadFilesToChain( tBd, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC16_Sim09l_MagUp_2024_01_29.txt");
  loadFilesToChain( tBd, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC17_Sim09l_MagDown_2024_01_29.txt");
  loadFilesToChain( tBd, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC17_Sim09l_MagUp_2024_01_29.txt");
  loadFilesToChain( tBd, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC18_Sim09l_MagDown_2024_01_29.txt");
  loadFilesToChain( tBd, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC18_Sim09l_MagUp_2024_01_29.txt");

  TChain *tX4634 = new TChain("XiccTuple/DecayTree");
  loadFilesToChain( tX4634, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/X4634ToLcLc_Turbo_MC17_Sim09i_MagDown_2024_01_29.txt");
  loadFilesToChain( tX4634, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/X4634ToLcLc_Turbo_MC17_Sim09i_MagUp_2024_01_29.txt");

  TCut LcCut("Lc_TMVA_BDT>-0.27 && Lc_M>2270 && Lc_M<2305 && LcBar_TMVA_BDT>-0.27 && (LcBar_M>2270 && LcBar_M<2305)");
  TCut BdCut("C_DTF_CHI2NDOF<9 && abs(C_TRUEID)==511");
  TCut BsCut("C_DTF_CHI2NDOF<9 && abs(C_TRUEID)==531");
  TCut X4634Cut("C_DTF_CHI2NDOF<9 && abs(C_TRUEID)==20443");

  TCut BdtotCuts = LcCut && BdCut;
  TCut BstotCuts = LcCut && BsCut;
  TCut X4634totCuts = LcCut && X4634Cut;

  drawRes_sg( tBs, BstotCuts,
           "(C_M-Lc_M-LcBar_M+2286.46*2) - sqrt(C_TRUEP_E*C_TRUEP_E - C_TRUEP_X*C_TRUEP_X - C_TRUEP_Y*C_TRUEP_Y - C_TRUEP_Z*C_TRUEP_Z)",
           "Bs_M",
           "Bs mass resolution",
           "MeV",
           -20, 20, false, 40 );

  drawRes_sg( tBd, BdtotCuts,
           "(C_M-Lc_M-LcBar_M+2286.46*2) - sqrt(C_TRUEP_E*C_TRUEP_E - C_TRUEP_X*C_TRUEP_X - C_TRUEP_Y*C_TRUEP_Y - C_TRUEP_Z*C_TRUEP_Z)",
           "Bd_M",
           "Bd mass resolution",
           "MeV",
           -20, 20, false, 40 );

  drawRes( tX4634, X4634totCuts,
           "(C_M-Lc_M-LcBar_M+2286.46*2) - sqrt(C_TRUEP_E*C_TRUEP_E - C_TRUEP_X*C_TRUEP_X - C_TRUEP_Y*C_TRUEP_Y - C_TRUEP_Z*C_TRUEP_Z)",
           "X(4634)_M",
           "X(4634) mass resolution",
           "MeV",
           -10, 10, false, 40 );
}                 
