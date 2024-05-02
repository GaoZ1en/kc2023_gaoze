void loadFilesToChain (TChain *chain, const std::string &filename){
  string line;
  ifstream source(filename.c_str(), ios::in);
  while ( getline (source, line) )
  {
    chain->AddFile( line.c_str() );
  }
}

void mergeTFiles()
{
  TChain *chain = new TChain("XiccTuple/DecayTree");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/X4634ToLcLc_Turbo_MC17_Sim09i_MagDown_2024_01_29.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/X4634ToLcLc_Turbo_MC17_Sim09i_MagUp_2024_01_29.txt");


  TFile *outputFile = new TFile("X4634ToDiLc_MC.root", "RECREATE");
  TTree *outputTree = chain->CloneTree();
  outputTree->Write();
  outputFile->Close();
}
