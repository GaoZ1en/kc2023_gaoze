// $Id: $
void loadFilesToChain (TChain *chain, const std::string &filename){
  string line;
  ifstream source(filename.c_str(), ios::in);
  while ( getline (source, line) )
  {
    // you may want to clean line here...
    chain->AddFile( line.c_str() );
  }
}

void drawBdMassRes()
{

  using namespace RooFit;


  TProof::Open("");

  TChain *chain = new TChain("XiccTuple/DecayTree");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC16_Sim09l_MagDown_2024_01_29.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC16_Sim09l_MagUp_2024_01_29.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC17_Sim09l_MagDown_2024_01_29.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC17_Sim09l_MagUp_2024_01_29.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC18_Sim09l_MagDown_2024_01_29.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC18_Sim09l_MagUp_2024_01_29.txt");

  chain->SetProof();


  
  TCanvas *MyCan = new TCanvas("MyCan", "",600, 480 );

  //TCut LcCut("Lc_TMVA_BDT>-0.27 && Lc_M>2260 && Lc_M<2310 && LcBar_TMVA_BDT>-0.27 && (LcBar_M>2260 && LcBar_M<2310)"); 
  TCut LcCut("Lc_TMVA_BDT>-0.27 && Lc_M>2270 && Lc_M<2305 && LcBar_TMVA_BDT>-0.27 && (LcBar_M>2270 && LcBar_M<2305)"); 

  TCut CCut("C_DTF_CHI2NDOF<9 && abs(C_TRUEID)==511");

  TCut totCuts = LcCut
    && CCut
    ;
  
  //chain->Draw("Lc_M:LcBar_M", totCuts,"COLZ");
  

  //...mass range
  const Double_t MassMin = -20;
  const Double_t MassMax =  20;
  const Int_t BinNum = 40;

  //...mass resolution
  const Double_t MsigmaAve = 3. ;
  const Double_t MsigmaMin = -10. ;
  const Double_t MsigmaMax = 300. ;

  TH1F *h10 = new TH1F("h10", "", BinNum, MassMin, MassMax);

  //chain->Project("h10", "(C_M-Lc_M-LcBar_M+2286.46*2) - sqrt(C_TRUEP_E*C_TRUEP_E - C_TRUEP_X*C_TRUEP_X - C_TRUEP_Y*C_TRUEP_Y - C_TRUEP_Z*C_TRUEP_Z)", totCuts);
  chain->Project("h10", "sqrt(C_TRUEP_E*C_TRUEP_E - C_TRUEP_X*C_TRUEP_X - C_TRUEP_Y*C_TRUEP_Y - C_TRUEP_Z*C_TRUEP_Z)", totCuts);
  //chain->Project("h10", "C_DTF_M", totCuts);
  

  h10->Draw("E");
  
  TString fileName = "Bd_MassRes";
  TString epsName = fileName + ".eps";
  TString pngName = fileName + ".png";
  TString pdfName = fileName + ".pdf";
 
  MyCan->Print( epsName );
  MyCan->Print( pngName );
  MyCan->Print( pdfName );
 
  
}
