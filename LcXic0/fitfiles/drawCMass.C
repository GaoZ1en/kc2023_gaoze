void drawCMass()
{

  using namespace RooFit;

  TCanvas *MyCan = new TCanvas("MyCan", "",600, 480 );

  TChain *chain = new TChain("DecayTree");
  chain->Add("/home/Koishi/LcXic0/datafiles/XiccTuple_sw.root");
  
  //...mass range
  const Double_t MassMin = 4760;
  const Double_t MassMax = 6755;
  const Int_t BinNum = 100;

  //...mass resolution
  const Double_t MsigmaAve = 3. ;
  const Double_t MsigmaMin = -10. ;
  const Double_t MsigmaMax = 300. ;

  TH1F *h10 = new TH1F("h10", "", BinNum, MassMin, MassMax);

  chain->Project("h10", "C_M - Lc_M - Xic_M + 2286.46 + 2470.44","nsig_sw");

  h10->Draw("E");
  
  TString fileName = "LcXic0";
  TString epsName = fileName + ".eps";
  TString pngName = fileName + ".png";
  TString pdfName = fileName + ".pdf";
 
  MyCan->Print( epsName );
  MyCan->Print( pngName );
  MyCan->Print( pdfName );
 
  
}
