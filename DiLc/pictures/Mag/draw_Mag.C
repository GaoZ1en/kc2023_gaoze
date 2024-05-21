void draw_Mag(){
  gROOT->ProcessLine(".x /home/Koishi/kc2023/DiLc/datafiles/lhcbStyle.C");

  TCut LcCut("Lc_TMVA_BDT>-0.27 && LcBar_TMVA_BDT>-0.27 && Lc_M>2220 && LcBar_M>2220 && Lc_M<2360 && LcBar_M<2360");

  TChain *chain = new TChain("DecayTree");
  chain->AddFile("/home/Koishi/kc2023/DiLc/datafiles/XiccTuple_sw_corrected.root");

  TCut MagUpCut("Polarity>0");
  TTree *tree_MagUp = chain->CopyTree(LcCut && MagUpCut);
  TCanvas *c_MagUp = new TCanvas("c_MagUp","c_MagUp",800,600);
  TH1F *h_MagUp = new TH1F("h_MagUp","h_MagUp",100,4575,6075);
  tree_MagUp->Project("h_MagUp","C_M-Lc_M-LcBar_M+2286.99*2","nsig_sw");
  h_MagUp->Draw();
  c_MagUp->SaveAs("MagUp.png");c_MagUp->SaveAs("MagUp.eps");c_MagUp->SaveAs("MagUp.pdf");


  TCut MagDownCut("Polarity<0");
  TTree *tree_MagDown = chain->CopyTree(LcCut && MagDownCut);
  TCanvas *c_MagDown = new TCanvas("c_MagDown","c_MagDown",800,600);
  TH1F *h_MagDown = new TH1F("h_MagDown","h_MagDown",100,4575,6075);
  tree_MagDown->Project("h_MagDown","C_M-Lc_M-LcBar_M+2286.99*2","nsig_sw");
  h_MagDown->Draw();
  c_MagDown->SaveAs("MagDown.png");c_MagDown->SaveAs("MagDown.eps");c_MagDown->SaveAs("MagDown.pdf");
}
