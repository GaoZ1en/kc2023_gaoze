using namespace RooFit;
using namespace RooStats;

void drawMagUp()
{
   gROOT->ProcessLine(".x /afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/lhcbStyle.C");

   TCut LcCut("Lc_TMVA_BDT>-0.27 && LcBar_TMVA_BDT>-0.27");
   TCut MagCut("Polarity==1");
   TCut totCuts = LcCut && MagCut;

   TChain *chain = new TChain("DecayTree");
   chain->AddFile("/afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/XiccTuple_sw.root");
   TTree *tree = chain->CopyTree(totCuts);
   TH1F *hRS = new TH1F("hRS","",100,4575,6075);
   tree->Project("hRS","C_M-Lc_M-LcBar_M+2286.99*2","nsig_sw");

   TCanvas *c1 = new TCanvas("c1","m(#Lambda_{c}^{+}#bar{#Lambda_{c}^{#minus}}) with Time cuts",800,600);
   hRS->Draw();
   hRS->GetXaxis()->SetTitle("m(#Lambda_{c}^{+}#bar{#Lambda_{c}^{#minus}})(MeV/c^{2})");
   hRS->GetXaxis()->SetTitleSize(0.05);
   hRS->GetXaxis()->SetLabelSize(0.05);
   hRS->GetYaxis()->SetTitle("Weighted candidates / (15 MeV/c^{2})");
   hRS->GetYaxis()->SetTitleSize(0.05);
   hRS->GetYaxis()->SetLabelSize(0.05);

   auto Number = hRS->Integral();
   cout << Number << endl;

   TPaveText *lhcbName = new TPaveText(0.40-gStyle->GetPadLeftMargin(),
                          0.87-gStyle->GetPadTopMargin(),
                          0.55-gStyle->GetPadLeftMargin(),
                          0.95 - gStyle->GetPadTopMargin(),
                          "BRNDC");
   lhcbName->AddText("MagUp");
   lhcbName->SetFillColor(0);
   lhcbName->SetTextAlign(12);
   lhcbName->SetTextSize(0.05);
   lhcbName->SetBorderSize(0);
   lhcbName->Draw();
 
   c1->SaveAs("MagUp.png");
   c1->SaveAs("MagUp.eps");
   c1->SaveAs("MagUp.pdf");

} 
