void drawCMass()
{
  using namespace RooFit;

  gROOT->ProcessLine(".x /afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/lhcbStyle.C");

  TChain *chain = new TChain("DecayTree");
  chain->AddFile("/afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/XiccWSTuple_sw.root");

  TCanvas *MyCan = new TCanvas("MyCan", "",600, 480 );

  TCut LcCut("Lc_TMVA_BDT>-0.27 && LcBar_TMVA_BDT>-0.27"); 
  
  //chain->Draw("Lc_M:LcBar_M", totCuts,"COLZ");

  //...mass range
  const Double_t MassMin = 4575;
  const Double_t MassMax = 6075;
  const Int_t BinNum = 100;

  //...mass resolution
  const Double_t MsigmaAve = 3. ;
  const Double_t MsigmaMin = -10. ;
  const Double_t MsigmaMax = 300. ;

  TH1F *h10 = new TH1F("h10", "", BinNum, MassMin, MassMax);
  TTree *tree = chain->CopyTree(LcCut);
  
  tree->Project("h10", "C_M-Lc_M-LcBar_M+2286.99*2", "nsig_sw");
  //chain->Project("h10", "C_DTF_M", totCuts);
  h10->GetXaxis()->SetTitle("m(#Lambda_{c}^{+}#bar{#Lambda_{c}^{#minus}})[MeV]");
  h10->Draw("E");

  MyCan->Print("WS_spec.png");
  MyCan->Print("WS_spec.pdf");
  MyCan->Print("WS_spec.eps");
}
