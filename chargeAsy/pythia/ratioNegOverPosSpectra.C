#include "highestPtHat.C"

void ratioNegOverPosSpectra(){

TH1D::SetDefaultSumw2();
  TFile* fquark = new TFile("outGenJet_HAD_R23457_5020GeV_Apr282016_FLAVOURposChAll_Z2Combined.root");
  TH1D* hquark  = fquark->Get("ak5GenJetSpectrum_n10_p10/Neg_Spectra");
  TH1D* hgluon  = fquark->Get("ak5GenJetSpectrum_n10_p10/Pos_Spectra");

  TH1D *puEffx;
  puEffx = (TH1D*) hquark->Clone(Form("puEffx"));
  TH1D *puEff1, *puEff2, *puEff3, *puEff4;
  puEff2 = (TH1D*) hgluon->Clone(Form("puEff2"));

 Double_t bins[] = {0,1,3,5,8,18,22,37,50,65,85,102,125,145};
 Int_t  binnum = sizeof(bins)/sizeof(Double_t) - 1; 
 //TH1F* rebined = new TH1F("rebined","", binnum, bins);
 TH1D *puEffxn = puEffx->Rebin(binnum,"puEffxn",bins);
 TH1D *puEff2n = puEff2->Rebin(binnum,"puEff2n",bins);
 puEffxn->Divide(puEff2n);
 puEffx = (TH1D*) puEffxn->Clone(Form("puEffx"));

/*
  int nrebin=10;
  puEffx->Rebin(nrebin);
  puEff2->Rebin(nrebin);
  puEffx->Scale(1.0/nrebin);  
  puEff2->Scale(1.0/nrebin);  
  puEffx->Divide(puEff2);
*/

  TCanvas* cd = new TCanvas("cd","",500,500);
  cd->SetLeftMargin(0.12);
  cd->SetRightMargin(0.02);
  cd->SetTopMargin(0.02);
  cd->SetBottomMargin(0.12);
  cd->SetTicks(1);
  cd->SetLogx();
  //cd->SetLogy();
  gStyle->SetOptStat(0);
  puEffx->SetTitle("");
  puEffx->SetXTitle("Particle p_{T} (GeV/c)");
  puEffx->SetYTitle("1/N_{evt}*dN_{pos or neg}/(dp_{T}d_{#eta})");
  puEffx->GetYaxis()->SetTitleOffset(1.2);
  puEffx->GetXaxis()->SetTitleOffset(1.2);
  puEffx->GetXaxis()->CenterTitle(1);
  puEffx->GetYaxis()->CenterTitle(1);
  puEffx->GetXaxis()->SetTitleSize(0.046);
  puEffx->GetYaxis()->SetTitleSize(0.046);
  puEffx->GetXaxis()->SetTitleFont(62);
  puEffx->GetYaxis()->SetTitleFont(62);
  //puEffx->SetAxisRange(1e-4,puEffx->GetMaximum()*1.4,"Y");
 // puEffx->SetAxisRange(0.7,1.3,"Y");
  //puEffx->SetAxisRange(1e-12,1e1,"Y");
  puEffx->SetAxisRange(0.5,1.5,"Y");
  puEffx->SetAxisRange(1,150,"X");
  puEffx->SetStats(0);
  puEffx->SetLineColor(1);
  puEffx->SetLineWidth(2);
  puEffx->SetMarkerColor(1);
  puEffx->SetMarkerStyle(20);
  puEffx->SetMarkerSize(1.);
  puEffx->Draw("pez");

  puEff2->SetLineColor(2);
  puEff2->SetLineWidth(2);
  puEff2->SetMarkerColor(2);
  puEff2->SetMarkerStyle(24);
  puEff2->SetMarkerSize(1.);
  //puEff2->Draw("pezsame");

    TLegend *leg0 = new TLegend(0.5,0.76,0.8,0.905);
    leg0->SetFillColor(10);
    leg0->SetBorderSize(0.035);
    leg0->SetTextFont(42);
    leg0->SetTextSize(0.05);
    leg0->AddEntry(puEffx,"Neg","pl");
    //leg0->AddEntry(puEff2,"Pos","pl");
    leg0->Draw();

    TLatex *tex1= new TLatex(300.45,1e-4,"PYTHIA6 Z2 5.02 TeV");
    tex1->SetTextColor(1);
    tex1->SetTextSize(0.05);
    tex1->SetTextFont(42);
    tex1->Draw();
    //TLatex *tex1= new TLatex(300.45,3e-6,"ak3GenJet |#eta|<1.0");
    TLatex *tex1= new TLatex(300.45,3e-6,"ak5GenJet |#eta|<1.0");
    tex1->SetTextColor(1);
    tex1->SetTextSize(0.05);
    tex1->SetTextFont(42);
    tex1->Draw();

highestPtHat();
neg_11_2->Draw("histsame");

  cd->SaveAs("plot_ratioNegOverPosSpectra.png");

}

