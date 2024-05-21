void draw_timebins(){
  gROOT->ProcessLine(".x /home/Koishi/kc2023/DiLc/datafiles/lhcbStyle.C");

  TCut LcCut("Lc_TMVA_BDT>-0.27 && LcBar_TMVA_BDT>-0.27 && Lc_M>2220 && LcBar_M>2220 && Lc_M<2360 && LcBar_M<2360");

  TChain *chain = new TChain("DecayTree");
  chain->AddFile("/home/Koishi/kc2023/DiLc/datafiles/XiccTuple_sw_corrected.root");

  TCut TimeCut2016("GpsTime<1.49e+15");
  TTree *tree_2016 = chain->CopyTree(LcCut && TimeCut2016);
  TCanvas *c_2016 = new TCanvas("c_2016","c_2016",800,600);
  TH1F *h_2016 = new TH1F("h_2016","h_2016",100,4575,6075);
  tree_2016->Project("h_2016","C_M-Lc_M-LcBar_M+2286.99*2","nsig_sw");
  h_2016->Draw();
  c_2016->SaveAs("2016.png");c_2016->SaveAs("2016.eps");c_2016->SaveAs("2016.pdf");


  TCut TimeCut2017("GpsTime>1.49e+15 && GpsTime<1.52e+15");
  TTree *tree_2017 = chain->CopyTree(LcCut && TimeCut2017);
  TCanvas *c_2017 = new TCanvas("c_2017","c_2017",800,600);
  TH1F *h_2017 = new TH1F("h_2017","h_2017",100,4575,6075);
  tree_2017->Project("h_2017","C_M-Lc_M-LcBar_M+2286.99*2","nsig_sw");
  h_2017->Draw();
  c_2017->SaveAs("2017.png");c_2017->SaveAs("2017.eps");c_2017->SaveAs("2017.pdf");

  TCut TimeCut2018("GpsTime>1.52e+15");
  TTree *tree_2018 = chain->CopyTree(LcCut && TimeCut2018);
  TCanvas *c_2018 = new TCanvas("c_2018","c_2018",800,600);
  TH1F *h_2018 = new TH1F("h_2018","h_2018",100,4575,6075);
  tree_2018->Project("h_2018","C_M-Lc_M-LcBar_M+2286.99*2","nsig_sw");
  h_2018->Draw();
  c_2018->SaveAs("2018.png");c_2018->SaveAs("2018.eps");c_2018->SaveAs("2018.pdf");
}
