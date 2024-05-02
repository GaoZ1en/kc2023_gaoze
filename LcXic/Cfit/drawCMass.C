void drawCMass()
{

  using namespace RooFit;

  TCanvas *MyCan = new TCanvas("MyCan", "",600, 480 );
  TCut MCut = "Lc_M>2210 && Lc_M<2360 && Xic_M>2420 && Xic_M<2540";

  TChain *chain = new TChain("DecayTree");
  chain->Add("/home/Koishi/LcXic/datafiles/XiccTuple_sw.root");
  TTree *tree_bkg = chain->CopyTree(MCut);
  
  //...mass range
  const Double_t MassMin = 4755;
  const Double_t MassMax = 6755;
  const Int_t BinNum = 100;

  //...mass resolution
  const Double_t MsigmaAve = 3. ;
  const Double_t MsigmaMin = -10. ;
  const Double_t MsigmaMax = 300. ;

  TH1F *h_bkg = new TH1F("h_bkg", "", BinNum, MassMin, MassMax);

  //TH1F *h_bs = new TH1F("h_bs", "", BinNum, MassMin, MassMax);
  //TH1F *h_bb = new TH1F("h_bb", "", BinNum, MassMin, MassMax);

  //tree_bkg->Project("h_bs", "C_M - Lc_M - Xic_M + 2286.46 + 2467.71","nbs_sw");
  //tree_bkg->Project("h_bb", "C_M - Lc_M - Xic_M + 2286.46 + 2467.71","nbb_sw");

  //h_bkg->Add(h_bb);h_bkg->Add(h_bs);
  tree_bkg->Project("h_bkg","C_M-Lc_M-Xic_M+2286.46+2467.71");
  h_bkg->Draw("E");
  
  //TString fileName = "LcXic_bkg";
  //TString epsName = fileName + ".eps";
  //TString pngName = fileName + ".png";
  //TString pdfName = fileName + ".pdf";
 
  //MyCan->Print( epsName );
  //MyCan->Print( pngName );
  //MyCan->Print( pdfName );
 
  
}
