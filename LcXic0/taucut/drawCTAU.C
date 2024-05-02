void drawCTAU()
{
  using namespace RooFit;

  gROOT->ProcessLine(".x /home/Koishi/DiLc/datafiles/lhcbStyle.C");

  TChain *chain = new TChain("DecayTree");
  chain->AddFile("/home/Koishi/LcXic0/datafiles/XiccTuple_sw.root");

  TCanvas *MyCan = new TCanvas("MyCan", "",600, 480 );

  //TCut LcCut("Lc_TMVA_BDT>-0.27 && LcBar_TMVA_BDT>-0.27");
  //TCut TAUCut("C_TAU*1000<0.12");

  //chain->Draw("Lc_M:LcBar_M", totCuts,"COLZ");

  //...mass range
  const Double_t MassMin = -2;
  const Double_t MassMax = 8;
  const Int_t BinNum = 100;

  TH1F *h10 = new TH1F("h10", "", BinNum, MassMin, MassMax);
  TTree *tree = chain->CopyTree("");
  
  tree->Project("h10", "C_TAU*1000", "nsig_sw");
  //chain->Project("h10", "C_DTF_M", totCuts);
  h10->GetXaxis()->SetTitle("#tau(#Lambda_{c}^{+}#Xi_{c}^{0})[ps]");
  h10->Draw("E");

  MyCan->Print("tau_-2-8ps.png");
  MyCan->Print("tau_-2-8ps.pdf");
  MyCan->Print("tau_-2-8ps.eps");
}
