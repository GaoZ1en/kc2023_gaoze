void drawHist(TTree* tree1,
              TTree* tree2,
              const char* variable, 
              const char* xtitle, 
              Double_t xlow,              // Lower bound 
              Double_t xup,               // Upper bound 
              const char* fileName=NULL,
              Double_t cutValue1=1.0e+10,
              Double_t cutValue2=1.0e+10,
              Bool_t useLogy = false, 
              Int_t nBins=100){
  
  gROOT->ProcessLine(".x /afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/lhcbStyle.C");
 
  TCanvas *MyCan = new TCanvas("MyCan", "",600, 480 );
  gStyle->SetNdivisions(505,"xy");

  if( useLogy ) gPad->SetLogy();
  else gPad->SetLogy(0);

  TCut LcCut("Lc_TMVA_BDT>0-0.27 && LcBar_TMVA_BDT>-0.27");
  TCut LcMCut_RR("Lc_M>2300 && Lc_M<2360 && LcBar_M>2300 && LcBar_M<2360");
  TCut LcMCut_RL("Lc_M>2300 && Lc_M<2360 && LcBar_M>2220 && LcBar_M<2270");
  TCut LcMCut_LR("Lc_M>2200 && Lc_M<2270 && LcBar_M>2300 && LcBar_M<2360");
  TCut LcMCut_LL("Lc_M>2200 && Lc_M<2270 && LcBar_M>2220 && LcBar_M<2270");
  TCut LcMCut_C("Lc_M>2270 && Lc_M<2300 && LcBar_M>2270 && LcBar_M<2300");
  TCut sigCut = LcCut && LcMCut_C;
  TCut LcMCut_sb = LcMCut_RR || LcMCut_RL || LcMCut_LR || LcMCut_LL;
  TCut sbCut = LcCut && LcMCut_sb;

  TTree *tree_sig = tree1->CopyTree(sigCut);
  TTree *tree_sb = tree1->CopyTree(sbCut);

  TH1F *h_sb = new TH1F("h_sb", "", nBins, xlow, xup);
  TH1F *h_sig = new TH1F("h_sig", "", nBins, xlow, xup);
  
  tree_sb->Project("h_sb", variable, "nsig_sw");
  tree_sig->Project("h_sig", variable, "nbs_sw");

  h_sb->SetLineColor(kRed);
  h_sb->SetMarkerStyle(24);
  h_sb->SetMarkerColor(kRed);
  h_sb->SetLineStyle(kDashed);
  
  // normalize
  h_sb->Scale(h_sig->Integral()/h_sb->Integral());

  Double_t ymax;
  Double_t LegX1;
  Double_t LegX2;

  if( h_sb->GetMaximum() > h_sig->GetMaximum() ){
    h_sb->GetXaxis()->SetTitle(xtitle);
    h_sb->GetYaxis()->SetTitle();
    h_sb->Draw();  
    h_sig->Draw("same");

    ymax = h_sb->GetMaximum();
    // legend x position
    if( h_sb->Integral(0,((nBins*0.5)-1)) > h_sb->Integral(((nBins*0.5)+1), nBins) ){ 
      LegX1 = 0.6  ;
      LegX2 = 0.89 ;
    } else{ 
      LegX1 = 0.2  ;
      LegX2 = 0.4  ;    
    }
  } else {
    h_sig->GetXaxis()->SetTitle(xtitle);
    h_sig->GetYaxis()->SetTitle();
    h_sig->Draw();  
    h_sb->Draw("Esame");  
  
    ymax = h_sig->GetMaximum();
    // legend x position
    if( h_sig->Integral(0,(nBins/2)-1) > h_sig->Integral((nBins/2), nBins) ){
      LegX1 = 0.6  ;
      LegX2 = 0.89 ;
    } else{
      LegX1 = 0.2  ;
      LegX2 = 0.4 ;    
    }

  }
 
  TLine line1( cutValue1, 0, cutValue1, ymax );
  line1.SetLineStyle(9);
  line1.SetLineColor(kBlue);
  //line
  line1.Draw("same");

  TLine line2( cutValue2, 0, cutValue2, ymax );
  line2.SetLineStyle(9);
  line2.SetLineColor(kBlue);
  line2.Draw("same"); 

  
  // legend
  //Define some common variables
  Double_t LegY1 = 0.78 ;
  Double_t LegY2 = 0.89 ;
  TLegend *leg = new TLegend(LegX1,LegY1,LegX2,LegY2);
  leg->SetBorderSize(0);
  leg->SetFillColor(0);
  leg->SetTextSize(0.04);
  leg->AddEntry(h_sig,"signal region","LP");
  leg->AddEntry(h_sb,"sideband region","LP");
  leg->Draw();

  TString epsName, pdfName, gifName;
  if(!fileName){ 
    epsName = variable ;
    pdfName = variable ;
    gifName = variable ;
  } else{
    epsName = fileName ;
    pdfName = fileName ;
    gifName = fileName ;
  }
  
  epsName += ".eps";
  MyCan->Print( epsName );

  pdfName += ".pdf";
  MyCan->Print( pdfName ); 
  
  gifName += ".gif";
  MyCan->Print( gifName );

  //delete h_sb;
  //delete h_sig;
  //delete MyCan;
}



void compDist(){

  TFile *fSig = new TFile("/afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/XiccTuple_sw.root");
  TTree *tSig = (TTree*)fSig->Get("DecayTree");
  drawHist( tSig, tSig, "C_M-Lc_M-LcBar_M+2286.99*2",
            "m(#Lambda_{c}#Lambda_{c})[MeV]", 4550, 6000, "sp_bkg&sig" );
}
