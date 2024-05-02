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

void drawCMass()
{

  using namespace RooFit;


  TProof::Open("");

  TChain *chain = new TChain("XiccTuple/DecayTree");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/LcXic0_2016_2024_02_27.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/LcXic0_2017_2024_02_27.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/LcXic0_2018_2024_02_27.txt");

  chain->SetProof();


  
  TCanvas *MyCan = new TCanvas("MyCan", "",600, 480 );

  //TCut totCuts = LcCut
  //  ;
  
  //chain->Draw("Lc_M:LcBar_M", totCuts,"COLZ");
  
  
  //...mass range
  const Double_t MassMin = 4750;
  const Double_t MassMax = 5750;
  const Int_t BinNum = 100;

  //...mass resolution
  const Double_t MsigmaAve = 3. ;
  const Double_t MsigmaMin = -10. ;
  const Double_t MsigmaMax = 300. ;

  TH1F *h10 = new TH1F("h10", "", BinNum, MassMin, MassMax);

  chain->Project("h10", "C_M - Lc_M - Xic_M + 2286.46 + 2470.44");

  h10->Draw("E");
  
  TString fileName = "LcXic_All";
  TString epsName = fileName + ".eps";
  TString pngName = fileName + ".png";
  TString pdfName = fileName + ".pdf";
 
  MyCan->Print( epsName );
  MyCan->Print( pngName );
  MyCan->Print( pdfName );
 
  
}
