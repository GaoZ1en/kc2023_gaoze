void draw_ptbins(){
  gROOT->ProcessLine(".x /home/Koishi/kc2023/LcXic/datafiles/lhcbStyle.C");

  TCut MCut = "Lc_M>2210 && Lc_M<2360 && Xic_M>2420 && Xic_M<2540";
  TChain *chain = new TChain("DecayTree");
  chain->AddFile("/home/Koishi/kc2023/LcXic/datafiles/XiccTuple_sw_corrected.root");

  TCut PTCut8("C_PT<8e+3");
  TTree *tree_8 = chain->CopyTree(MCut && PTCut8);
  TCanvas *c_8 = new TCanvas("c_8","c_8",800,600);
  TH1F *h_8 = new TH1F("h_8","h_8",100,4755,6755);
  tree_8->Project("h_8","C_M-Lc_M-Xic_M+2286.46+2467.71","nsig_sw");
  h_8->Draw();
  c_8->SaveAs("PT<8G.png");c_8->SaveAs("PT<8G.eps");c_8->SaveAs("PT<8G.pdf");


  TCut PTCut8105("C_PT>8e+3 && C_PT<10.5e+3");
  TTree *tree_8105 = chain->CopyTree(MCut && PTCut8105);
  TCanvas *c_8105 = new TCanvas("c_8105","c_8105",800,600);
  TH1F *h_8105 = new TH1F("h_8105","h_8105",100,4755,6755);
  tree_8105->Project("h_8105","C_M-Lc_M-Xic_M+2286.46+2467.71","nsig_sw");
  h_8105->Draw();
  c_8105->SaveAs("8G<PT<10.5G.png");c_8105->SaveAs("8G<PT<10.5G.eps");c_8105->SaveAs("8G<PT<10.5G.pdf");

  TCut PTCut10513("C_PT>10.5e+3 && C_PT<13e+3");
  TTree *tree_10513 = chain->CopyTree(MCut && PTCut10513);
  TCanvas *c_10513 = new TCanvas("c_10513","c_10513",800,600);
  TH1F *h_10513 = new TH1F("h_10513","h_10513",100,4755,6755);
  tree_10513->Project("h_10513","C_M-Lc_M-Xic_M+2286.46+2467.71","nsig_sw");
  h_10513->Draw();
  c_10513->SaveAs("10.5G<PT<13G.png");c_10513->SaveAs("10.5G<PT<13G.eps");c_10513->SaveAs("10.5G<PT<13G.pdf");

  TCut PTCut1316("C_PT>13e+3 && C_PT<16e+3");
  TTree *tree_1316 = chain->CopyTree(MCut && PTCut1316);
  TCanvas *c_1316 = new TCanvas("c_1316","c_1316",800,600);
  TH1F *h_1316 = new TH1F("h_1316","h_1316",100,4755,6755);
  tree_1316->Project("h_1316","C_M-Lc_M-Xic_M+2286.46+2467.71","nsig_sw");
  h_1316->Draw();
  c_1316->SaveAs("13G<PT<16G.png");c_1316->SaveAs("13G<PT<16G.eps");c_1316->SaveAs("13G<PT<16G.pdf");

  TCut PTCut16("C_PT>16e+3");
  TTree *tree_16 = chain->CopyTree(MCut && PTCut16);
  TCanvas *c_16 = new TCanvas("c_16","c_16",800,600);
  TH1F *h_16 = new TH1F("h_16","h_16",100,4755,6755);
  tree_16->Project("h_16","C_M-Lc_M-Xic_M+2286.46+2467.71","nsig_sw");
  h_16->Draw();
  c_16->SaveAs("PT>16G.png");c_16->SaveAs("PT>16G.eps");c_16->SaveAs("PT>16G.pdf");

}
