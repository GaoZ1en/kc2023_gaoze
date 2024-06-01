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
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/DiLc_Bu2LcLcPi_MvaLc_MC18_Sim09k_MagUp_2024_05_25.txt");
  loadFilesToChain( chain, "/afs/ihep.ac.cn/users/j/jibo/public/GangaScripts/DiLc_Bu2LcLcPi_MvaLc_MC18_Sim09k_MagDown_2024_05_25.txt");

  TFile *outputFile = new TFile("Bu2LcLcPi_Sim.root", "RECREATE");
  TTree *outputTree = chain->CloneTree();
  outputTree->Write();
  outputFile->Close();
}
