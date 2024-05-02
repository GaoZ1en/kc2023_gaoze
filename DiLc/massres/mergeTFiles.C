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
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC16_Sim09l_MagDown_2024_01_30.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC17_Sim09l_MagDown_2024_01_30.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC18_Sim09l_MagDown_2024_01_30.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC16_Sim09l_MagUp_2024_01_30.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC17_Sim09l_MagUp_2024_01_30.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/Bd2LcLc_Turbo_MC18_Sim09l_MagUp_2024_01_30.txt");

  TFile *outputFile = new TFile("BdToDiLc_30.root", "RECREATE");
  TTree *outputTree = chain->CloneTree();
  outputTree->Write();
  outputFile->Close();
}
