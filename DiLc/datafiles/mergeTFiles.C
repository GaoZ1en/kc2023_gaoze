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
  TChain *chain = new TChain("XiccWSTuple/DecayTree");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/DiLc_MvaLc_BDTG_2016_2023_10_25.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/DiLc_MvaLc_BDTG_2017_2023_10_25.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/DiLc_MvaLc_BDTG_2018_2023_10_25.txt");

  TFile *outputFile = new TFile("XiccWSTuple.root", "RECREATE");
  TTree *outputTree = chain->CloneTree();
  outputTree->Write();
  outputFile->Close();
}
