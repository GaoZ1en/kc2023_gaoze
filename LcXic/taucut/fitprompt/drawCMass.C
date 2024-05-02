void drawCMass()
{
  gROOT->ProcessLine(".x /home/Koishi/LcXic/datafiles/lhcbStyle.C");

  using namespace RooFit;

  TCanvas *MyCan = new TCanvas("MyCan", "",600, 480 );

  TCut taucut("C_TAU*1000<0.12");

  TChain *tree = new TChain("DecayTree");
  tree->Add("/home/Koishi/LcXic/taucut/XiccTuple_sw.root");
  TTree *chain = tree->CopyTree(taucut);
  

  //...mass range
  const Double_t MassMin = 4755;
  const Double_t MassMax = 6755;
  const Int_t BinNum = 100;

  //...mass resolution
  const Double_t MsigmaAve = 3. ;
  const Double_t MsigmaMin = -10. ;
  const Double_t MsigmaMax = 300. ;

  TH1F *h10 = new TH1F("h10", "", BinNum, MassMin, MassMax);

  chain->Project("h10", "C_M - Lc_M - Xic_M + 2286.46 + 2467.71");

  h10->Draw("E");
  
  TString fileName = "LcXic";
  TString epsName = fileName + ".eps";
  TString pngName = fileName + ".png";
  TString pdfName = fileName + ".pdf";
 
  MyCan->Print( epsName );
  MyCan->Print( pngName );
  MyCan->Print( pdfName );
 
  
}
