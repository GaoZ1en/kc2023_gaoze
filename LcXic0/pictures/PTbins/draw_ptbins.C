void draw_ptbins(){
  gROOT->ProcessLine(".x /home/Koishi/kc2023/LcXic0/datafiles/lhcbStyle.C");

  TCut MCut = "Lc_M>2210 && Lc_M<2360 && Xic_M>2420 && Xic_M<2540";
  TChain *chain = new TChain("DecayTree");
  chain->AddFile("/home/Koishi/kc2023/LcXic0/datafiles/XiccTuple_sw_corrected.root");

  TCut PTCut125("C_PT<12.5e+3");
  TTree *tree_125 = chain->CopyTree(MCut && PTCut125);
  TCanvas *c_125 = new TCanvas("c_125","c_125",800,600);
  TH1F *h_125 = new TH1F("h_125","h_125",100,4757,6757);
  tree_125->Project("h_125","C_M-Lc_M-Xic_M+2286.46+2470.44","nsig_sw");
  h_125->Draw();
  c_125->SaveAs("PT<125G.png");c_125->SaveAs("PT<125G.eps");c_125->SaveAs("PT<125G.pdf");


  TCut PTCut12517("C_PT>12.5e+3 && C_PT<17e+3");
  TTree *tree_12517 = chain->CopyTree(MCut && PTCut12517);
  TCanvas *c_12517 = new TCanvas("c_12517","c_12517",800,600);
  TH1F *h_12517 = new TH1F("h_12517","h_12517",100,4757,6757);
  tree_12517->Project("h_12517","C_M-Lc_M-Xic_M+2286.46+2470.44","nsig_sw");
  h_12517->Draw();
  c_12517->SaveAs("125G<PT<17G.png");c_12517->SaveAs("125G<PT<17G.eps");c_12517->SaveAs("125G<PT<17G.pdf");

  TCut PTCut17("C_PT>17e+3");
  TTree *tree_17 = chain->CopyTree(MCut && PTCut17);
  TCanvas *c_17 = new TCanvas("c_17","c_17",800,600);
  TH1F *h_17 = new TH1F("h_17","h_17",100,4757,6757);
  tree_17->Project("h_17","C_M-Lc_M-Xic_M+2286.46+2470.44","nsig_sw");
  h_17->Draw();
  c_17->SaveAs("PT>17G.png");c_17->SaveAs("PT>17G.eps");c_17->SaveAs("PT>17G.pdf");
}
