void drawCMass()
{
  using namespace RooFit;

  gROOT->ProcessLine(".x /home/Koishi/Projects/kc2023/DiLc/datafiles/lhcbStyle.C");

  TChain *chain = new TChain("DecayTree");
  chain->AddFile("/home/Koishi/Projects/kc2023/DiLc/feeddown/Lb2LcLcn/Lb2LcLcn_sw.root");

  TCanvas *MyCan = new TCanvas("MyCan", "",600, 480 );

  TCut LcCut("Lc_TMVA_BDT>-0.27 && LcBar_TMVA_BDT>-0.27"); 
  
  //chain->Draw("Lc_M:LcBar_M", totCuts,"COLZ");

  //...mass range
  const Double_t MassMin = 4475;
  const Double_t MassMax = 4775;
  const Int_t BinNum = 100;

  //...mass resolution
  const Double_t MsigmaAve = 3. ;
  const Double_t MsigmaMin = -10. ;
  const Double_t MsigmaMax = 300. ;

  TH1F *h10 = new TH1F("h10", "", BinNum, MassMin, MassMax);
  TTree *tree = chain->CopyTree(LcCut);
  
  tree->Project("h10", "C_M-Lc_M-LcBar_M+2286.99*2");
  //chain->Project("h10", "C_DTF_M", totCuts);
  h10->GetXaxis()->SetTitle("m(#Lambda_{c}^{+}#bar{#Lambda_{c}^{#minus}})[MeV]");
  h10->Draw("E");

  MyCan->Print("Lb2LcLcn.png");
  MyCan->Print("Lb2LcLcn.pdf");
  MyCan->Print("Lb2LcLcn.eps");
}
