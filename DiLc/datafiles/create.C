#include <TTree.h>

void create()
{
   TFile *input_f = new TFile("/afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/XiccTuple_sw.root");
   TFile *output_f = new TFile("XiccTuple_sw_corrected.root","RECREATE");
   TTree *input_t = (TTree*)input_f->Get("DecayTree");
   TTree *output_t = input_t->CopyTree("");

   Double_t C_M, Lc_M, LcBar_M, C_M_corrected;
   input_t->SetBranchAddress("C_M",&C_M);
   input_t->SetBranchAddress("Lc_M",&Lc_M);
   input_t->SetBranchAddress("LcBar_M",&LcBar_M);
   output_t->Branch("C_M_corrected",&C_M_corrected,"C_M_corrected/D");

   for(int i=0;i<input_t->GetEntries();i++)
   {
      input_t->GetEntry(i);
      C_M_corrected = C_M-Lc_M-LcBar_M+2286.99*2;
      output_t->Fill();
   }

   output_t->Write();
   output_f->Close();
}
