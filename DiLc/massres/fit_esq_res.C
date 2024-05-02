using namespace RooFit;

void fit_esq_res()
{
  gROOT->ProcessLine(".x /afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/lhcbStyle.C");  

  TCanvas *c1 = new TCanvas("c1", "My Canvas", 200, 10, 1000, 600);
  c1->SetGrid();
  const Int_t n =3;
  Double_t esq[n] = {4634-2287.4*2,5279.58-0.736-2287.4*2,5366.77-0.546-2287.4*2};
  Double_t ressq[n]= {2.40*2.40,6.74*6.74,6.84*6.84};
  Double_t esq_err[n] = {0.068,0.21,0.20};
  Double_t ressq_err[n] = {0.21*2*2.40,0.16*2*6.74,0.15*2*6.84};

  TGraphErrors *gr = new TGraphErrors( n, esq, ressq, esq_err, ressq_err);
  gr->SetMarkerColor(kBlue+3);
  gr->SetMarkerStyle(21);
  gr->SetMarkerSize(1);
  gr->GetXaxis()->SetNdivisions(005);
  gr->GetXaxis()->SetTitle("m(#Lambda_{c}^{+}#bar{#Lambda_{c}^{-}})-m(#Lambda_{c}^{+})-m(#bar{#Lambda_{c}^{-}})(MeV)");
  gr->GetXaxis()->CenterTitle();
  gr->GetXaxis()->SetLabelSize(0.04);
  gr->GetXaxis()->SetTitleSize(0.04);
  gr->GetYaxis()->SetNdivisions(005);
  gr->GetYaxis()->SetTitle("#sigma^{2}_{m(#Lambda_{c}^{+}#bar{#Lambda_{c}^{-}})}(MeV^{2})");
  gr->GetYaxis()->CenterTitle();
  gr->GetYaxis()->SetLabelSize(0.04);
  gr->GetYaxis()->SetTitleSize(0.04);
  gr->SetTitle("As Anton suggested");
  gr->Draw();
  gr->Fit("pol1");

  TF1 *fit = gr->GetFunction("pol1");
  fit->SetLineColor(kRed);

  TLegend *legend = new TLegend(0.15,0.7,0.6,0.9);
  legend->AddEntry(gr,"Data with error","p");
  legend->AddEntry(fit,"Fit: a + b*mass, a=-26.55, b=6.25e-03","l");
  legend->SetBorderSize(1);
  legend->SetTextSize(0.04);
  legend->SetFillColor(0);
  legend->Draw();

  //c1->Print("fitmassres.png");
  //c1->Print("fitmassres.pdf");
  //c1->Print("fitmassres.eps");
}
