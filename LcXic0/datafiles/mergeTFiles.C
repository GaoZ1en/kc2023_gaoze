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
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/LcXic0_2016_2024_02_27.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/LcXic0_2017_2024_02_27.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/LcXic0_2018_2024_02_27.txt");

  TFile *outputFile = new TFile("XiccTuple.root", "RECREATE");
  TTree *outputTree = chain->CloneTree();
  outputTree->Write();
  outputFile->Close();
}
