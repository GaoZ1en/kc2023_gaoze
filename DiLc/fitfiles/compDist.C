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

  TH1F *h_sig = new TH1F("h_sig", "", nBins, xlow, xup);
  TH1F *h_WS = new TH1F("h_WS", "", nBins, xlow, xup);
  
  tree1->Project("h_sig", variable, "nsig_sw",LcCut);
  tree2->Project("h_WS", variable, "nbs_sw", LcCut);

  h_WS->SetLineColor(kRed);
  h_WS->SetMarkerStyle(24);
  h_WS->SetMarkerColor(kRed);
  h_WS->SetLineStyle(kDashed);
  
  // normalize
  h_sig->Scale(h_WS->Integral()/h_sig->Integral());

  Double_t ymax;
  Double_t LegX1;
  Double_t LegX2;

  if( h_WS->GetMaximum() > h_sig->GetMaximum() ){
    h_WS->GetXaxis()->SetTitle(xtitle);
    h_WS->GetYaxis()->SetTitle();
    h_WS->Draw();  
    h_sig->Draw("same");

    ymax = h_WS->GetMaximum();
    // legend x position
    if( h_WS->Integral(0,((nBins*0.5)-1)) > h_WS->Integral(((nBins*0.5)+1), nBins) ){ 
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
    h_WS->Draw("Esame");  
  
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
  leg->AddEntry(h_WS,"background","LP");
  leg->AddEntry(h_sig,"signal","LP");
  leg->Draw();

  /*TString epsName, pdfName, gifName;
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
  MyCan->Print( gifName );*/

  //delete h_WS;
  //delete h_sig;
  //delete MyCan;
}



void compDist(){

  TFile *fSig = new TFile("/afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/XiccTuple_sw.root");
  TTree *tSig = (TTree*)fSig->Get("DecayTree");
  TFile *fWS = new TFile("/afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/XiccWSTuple_sw.root");
  TTree *tWS = (TTree*)fWS->Get("DecayTree");
  drawHist( tSig, tWS, "C_M-Lc_M-LcBar_M+2286.99*2",
            "m(#Lambda_{c}#Lambda_{c})[MeV]", 4550, 6000, "sig&WS" );
}
