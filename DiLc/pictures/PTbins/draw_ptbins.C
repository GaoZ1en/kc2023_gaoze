void draw_ptbins(){
  gROOT->ProcessLine(".x /home/Koishi/kc2023/DiLc/datafiles/lhcbStyle.C");

  TCut LcCut("Lc_TMVA_BDT>-0.27 && LcBar_TMVA_BDT>-0.27 && Lc_M>2220 && LcBar_M>2220 && Lc_M<2360 && LcBar_M<2360");

  TChain *chain = new TChain("DecayTree");
  chain->AddFile("/home/Koishi/kc2023/DiLc/datafiles/XiccTuple_sw_corrected.root");

  TCut PTCut10("C_PT<10e+3");
  TTree *tree_10 = chain->CopyTree(LcCut && PTCut10);
  TCanvas *c_10 = new TCanvas("c_10","c_10",800,600);
  TH1F *h_10 = new TH1F("h_10","h_10",100,4575,6075);
  tree_10->Project("h_10","C_M-Lc_M-LcBar_M+2286.99*2","nsig_sw");
  h_10->Draw();
  c_10->SaveAs("PT<10G.png");c_10->SaveAs("PT<10G.eps");c_10->SaveAs("PT<10G.pdf");

  TCut PTCut1012("C_PT>10e+3 && C_PT<12e+3");
  TTree *tree_1012 = chain->CopyTree(LcCut && PTCut1012);
  TCanvas *c_1012 = new TCanvas("c_1012","c_1012",800,600);
  TH1F *h_1012 = new TH1F("h_1012","h_1012",100,4575,6075);
  tree_1012->Project("h_1012","C_M-Lc_M-LcBar_M+2286.99*2","nsig_sw");
  h_1012->Draw();
  c_1012->SaveAs("10G<PT<12G.png");c_1012->SaveAs("10G<PT<12G.eps");c_1012->SaveAs("10G<PT<12G.pdf");

  TCut PTCut1214("C_PT>12e+3 && C_PT<14e+3");
  TTree *tree_1214 = chain->CopyTree(LcCut && PTCut1214);
  TCanvas *c_1214 = new TCanvas("c_1214","c_1214",800,600);
  TH1F *h_1214 = new TH1F("h_1214","h_1214",100,4575,6075);
  tree_1214->Project("h_1214","C_M-Lc_M-LcBar_M+2286.99*2","nsig_sw");
  h_1214->Draw();
  c_1214->SaveAs("12G<PT<14G.png");c_1214->SaveAs("12G<PT<14G.eps");c_1214->SaveAs("12G<PT<14G.pdf");

  TCut PTCut1417("C_PT>14e+3 && C_PT<17e+3");
  TTree *tree_1417 = chain->CopyTree(LcCut && PTCut1417);
  TCanvas *c_1417 = new TCanvas("c_1417","c_1417",800,600);
  TH1F *h_1417 = new TH1F("h_1417","h_1417",100,4575,6075);
  tree_1417->Project("h_1417","C_M-Lc_M-LcBar_M+2286.99*2","nsig_sw");
  h_1417->Draw();
  c_1417->SaveAs("14G<PT<17G.png");c_1417->SaveAs("14G<PT<17G.eps");c_1417->SaveAs("14G<PT<17G.pdf");

  TCut PTCut17("C_PT>17e+3");
  TTree *tree_17 = chain->CopyTree(LcCut && PTCut17);
  TCanvas *c_17 = new TCanvas("c_17","c_17",800,600);
  TH1F *h_17 = new TH1F("h_17","h_17",100,4575,6075);
  tree_17->Project("h_17","C_M-Lc_M-LcBar_M+2286.99*2","nsig_sw");
  h_17->Draw();
  c_17->SaveAs("PT>17G.png");c_17->SaveAs("PT>17G.eps");c_17->SaveAs("PT>17G.pdf");
 
}
