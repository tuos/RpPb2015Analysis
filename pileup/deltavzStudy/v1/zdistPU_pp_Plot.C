distPU_pp_Plot(){

const int nLumi=1006;
TH1D::SetDefaultSumw2();
TH1D* lumiHist1 = new TH1D("lumihist1","Lumi Section", nLumi, 0, nLumi);
TH1D* lumiHist2 = new TH1D("lumihist2","Lumi Section", nLumi, 0, nLumi);
TH1D* lumiHist3 = new TH1D("lumihist3","Lumi Section", nLumi, 0, nLumi);
TH1D* lumiHist4 = new TH1D("lumihist4","Lumi Section", nLumi, 0, nLumi);

  TFile* fpu = new TFile("mergedDeltavzStudy.root");
  TH1D* vzDZ  = fpu->Get("ana_Lumi0/vertexDZ");
  TH1D* vzDZW  = fpu->Get("ana_Lumi0/vertexDZW");
  TH1D* vzDZW2  = fpu->Get("ana_Lumi0/vertexDZW2");
  TH1D* vz0Dist  = fpu->Get("ana_Lumi0/vertex0Dist");
  TH1D* vz1Dist  = fpu->Get("ana_Lumi0/vertex1Dist");
  TH1D* vz2Dist  = fpu->Get("ana_Lumi0/vertex2Dist");

  for(int i=0; i<1000; i++){
    //vzDZ

  }


  TCanvas* cd = new TCanvas("cd","",500,500);
  cd->SetLeftMargin(0.15);
  cd->SetRightMargin(0.02);
  cd->SetTopMargin(0.02);
  cd->SetBottomMargin(0.11);
  cd->SetTicks(1);
  //cd->SetLogy();
  gStyle->SetOptStat(0);
  puEffx->SetTitle("");
  puEffx->SetXTitle("Lumi Section");
  puEffx->SetYTitle("Number of Events");
  puEffx->GetYaxis()->SetTitleOffset(1.6);
  puEffx->GetXaxis()->SetTitleOffset(1.);
  puEffx->GetXaxis()->CenterTitle(1);
  puEffx->GetYaxis()->CenterTitle(1);
  puEffx->GetXaxis()->SetTitleSize(0.046);
  puEffx->GetYaxis()->SetTitleSize(0.046);
  puEffx->GetXaxis()->SetTitleFont(62);
  puEffx->GetYaxis()->SetTitleFont(62);
  puEffx->SetAxisRange(0,puEffx->GetMaximum()*1.4,"Y");
  //puEffx->SetAxisRange(0,122,"X");
/*
  puEffx->SetMarkerStyle(20);
  puEffx->Sumw2();
  puEffx->SetMarkerSize(1);
  puEffx->SetMarkerColor(1);
  puEffx->SetLineColor(1);
*/
  puEffx->SetStats(0);
  //puEffx->Draw("Pez");
  puEffx->SetLineColor(1);
  puEff2->SetLineColor(2);
  puEff3->SetLineColor(4);
  puEff4->SetLineColor(8);
  puEffx->SetLineWidth(2);
  puEff2->SetLineWidth(2);
  puEff3->SetLineWidth(2);
  puEff4->SetLineWidth(2);
  puEffx->Draw("h");
  puEff2->Draw("same");
  puEff3->Draw("same");
  puEff4->Draw("same");

    TLegend *leg0 = new TLegend(0.25,0.20,0.5,0.405);
    leg0->SetFillColor(10);
    leg0->SetBorderSize(0.035);
    leg0->SetTextFont(42);
    leg0->SetTextSize(0.048);
    leg0->AddEntry(puEffx,"No Filter","pl");
    leg0->AddEntry(puEff4,"olvFilter_dz1p0","pl");
    leg0->AddEntry(puEff3,"pileUpFilter_Gplus","pl");
    leg0->AddEntry(puEff2,"pileUpFilter_vtx1","pl");
    //leg0->Draw();

    TLatex *tex1= new TLatex(200.,puEffx->GetMaximum()*0.85,"Fill = 4643, run = 262274");
    //TLatex *tex1= new TLatex(45.42,3.5,"pPb \ #sqrt{s_{NN}} = 5.02 TeV");
    tex1->SetTextColor(1);
    tex1->SetTextSize(0.05);
    tex1->SetTextFont(42);
    tex1->Draw();
    TLatex *tex1= new TLatex(40.5,10e-3,"pp 5 TeV raw spectra");
    tex1->SetTextColor(1);
    tex1->SetTextSize(0.05);
    tex1->SetTextFont(42);
    //tex1->Draw();

    TLatex *tex2= new TLatex(40.5,3*10e-5,"1687M MB events, |#eta|<1.0");
    tex2->SetTextColor(1);
    tex2->SetTextSize(0.05);
    tex2->SetTextFont(42);
    //tex2->Draw();

  cd->SaveAs("vzDZ.png");

}
