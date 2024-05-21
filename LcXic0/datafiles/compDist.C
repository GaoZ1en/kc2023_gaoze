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
  
  gROOT->ProcessLine(".x /home/Koishi/kc2023/DiLc/datafiles/lhcbStyle.C");
 
  TCanvas *MyCan = new TCanvas("MyCan", "",600, 480 );
  gStyle->SetNdivisions(505,"xy");

  if( useLogy ) gPad->SetLogy();
  else gPad->SetLogy(0);

  TCut LcMCut_RU("Lc_M>2310 && Lc_M<2350 && Xic_M>2490 && Xic_M<2540");
  TCut LcMCut_RD("Lc_M>2310 && Lc_M<2350 && Xic_M>2400 && Xic_M<2450");
  TCut LcMCut_LU("Lc_M>2220 && Lc_M<2260 && Xic_M>2490 && Xic_M<2540");
  TCut LcMCut_LD("Lc_M>2220 && Lc_M<2260 && Xic_M>2400 && Xic_M<2450");
  TCut totCuts = LcMCut_RU || LcMCut_RD || LcMCut_LU || LcMCut_LD;

  TH1F *h_sb = new TH1F("h_sb", "", nBins, xlow, xup);
  TH1F *h_sp = new TH1F("h_sp", "", nBins, xlow, xup);
  
  tree1->Project("h_sb", variable, totCuts);
  tree2->Project("h_sp", variable, "nbs_sw");

  h_sp->SetLineColor(kRed);
  h_sp->SetMarkerStyle(24);
  h_sp->SetMarkerColor(kRed);
  h_sp->SetLineStyle(kDashed);
  
  // normalize
  h_sb->Scale(h_sp->Integral()/h_sb->Integral());

  Double_t ymax;
  Double_t LegX1;
  Double_t LegX2;

  if( h_sp->GetMaximum() > h_sb->GetMaximum() ){
    h_sp->GetXaxis()->SetTitle(xtitle);
    h_sp->GetYaxis()->SetTitle();
    h_sp->Draw();  
    h_sb->Draw("same");

    ymax = h_sp->GetMaximum();
    // legend x position
    if( h_sp->Integral(0,((nBins*0.5)-1)) > h_sp->Integral(((nBins*0.5)+1), nBins) ){ 
      LegX1 = 0.6  ;
      LegX2 = 0.89 ;
    } else{ 
      LegX1 = 0.2  ;
      LegX2 = 0.4  ;    
    }
  } else {
    h_sb->GetXaxis()->SetTitle(xtitle);
    h_sb->GetYaxis()->SetTitle();
    h_sb->Draw();  
    h_sp->Draw("Esame");  
  
    ymax = h_sb->GetMaximum();
    // legend x position
    if( h_sb->Integral(0,(nBins/2)-1) > h_sb->Integral((nBins/2), nBins) ){
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
  leg->AddEntry(h_sp,"sPlot","LP");
  leg->AddEntry(h_sb,"sideband","LP");
  leg->Draw();

  TString epsName, pdfName, pngName;
  if(!fileName){ 
    epsName = variable ;
    pdfName = variable ;
    pngName = variable ;
  } else{
    epsName = fileName ;
    pdfName = fileName ;
    pngName = fileName ;
  }
  
  epsName += ".eps";
  MyCan->Print( epsName );

  pdfName += ".pdf";
  MyCan->Print( pdfName ); 
  
  pngName += ".png";
  MyCan->Print( pngName );

  //delete h_sp;
  //delete h_sb;
  //delete MyCan;
}



void compDist(){

  TFile *fSig = new TFile("/home/Koishi/kc2023/LcXic0/datafiles/XiccTuple_sw.root");
  TTree *tSig = (TTree*)fSig->Get("DecayTree");
  drawHist( tSig, tSig, "C_M-Lc_M-Xic_M+2286.46+2470.44",
            "m(#Lambda_{c}^{+}#bar{#Xi_{c}^{#minus}})[MeV]", 4757, 6757, "sp&sb" );
}
