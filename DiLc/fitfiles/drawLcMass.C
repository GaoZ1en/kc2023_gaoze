void drawLcMass()
{
  using namespace RooFit;

  TChain *chain = new TChain("DecayTree");
  chain->AddFile("/afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/XiccTuple_sw.root");

  TCanvas *MyCan = new TCanvas("MyCan", "",600, 480 );

  TCut LcCut("Lc_TMVA_BDT>-0.27 && LcBar_TMVA_BDT>-0.27"); 
  TCut CCut("C_DTF_CHI2NDOF<9");

  TCut totCuts = LcCut && CCut;
  
  //chain->Draw("Lc_M:LcBar_M", totCuts,"COLZ");

  //...mass range
  const Double_t MassMin = 4550;
  const Double_t MassMax = 5100;
  const Int_t BinNum = 100;

  //...mass resolution
  const Double_t MsigmaAve = 3. ;
  const Double_t MsigmaMin = -10. ;
  const Double_t MsigmaMax = 300. ;

  TH1F *h10 = new TH1F("h10", "", BinNum, MassMin, MassMax);

  chain->Project("h10", "C_M-Lc_M-LcBar_M+2286.46*2", totCuts);
  //chain->Project("h10", "C_DTF_M", totCuts);
  h10->Draw("E");
}
