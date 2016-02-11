ydistPU_pp_Plot(){

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
  TH1D* vz0Dist  = fpu->Get("ana_Lumi0/vertexDZW2");
  TH1D* vz1Dist  = fpu->Get("ana_Lumi0/vertex1Dist");
  TH1D* vz2Dist  = fpu->Get("ana_Lumi0/vertex2Dist");

  for(int i=0; i<1000; i++){
    //vzDZ

  }

  vz0Dist->Rebin(5);

  TCanvas* cd = new TCanvas("cd","",500,500);
  cd->SetLeftMargin(0.15);
  cd->SetRightMargin(0.02);
  cd->SetTopMargin(0.02);
  cd->SetBottomMargin(0.11);
  cd->SetTicks(1);
  //cd->SetLogy();
  gStyle->SetOptStat(0);
  vz0Dist->SetTitle("");
  vz0Dist->SetXTitle("vz[0] - vz[1] (cm)");
  vz0Dist->SetYTitle("Number of Events");
  vz0Dist->GetYaxis()->SetTitleOffset(1.6);
  vz0Dist->GetXaxis()->SetTitleOffset(1.);
  vz0Dist->GetXaxis()->CenterTitle(1);
  vz0Dist->GetYaxis()->CenterTitle(1);
  vz0Dist->GetXaxis()->SetTitleSize(0.046);
  vz0Dist->GetYaxis()->SetTitleSize(0.046);
  vz0Dist->GetXaxis()->SetTitleFont(62);
  vz0Dist->GetYaxis()->SetTitleFont(62);
  //vz0Dist->SetAxisRange(100,vz0Dist->GetMaximum()*10.4,"Y");
  vz0Dist->SetAxisRange(0,vz0Dist->GetMaximum()*1.4,"Y");
  //vz0Dist->SetAxisRange(0,122,"X");
/*
  vz0Dist->SetMarkerStyle(20);
  vz0Dist->Sumw2();
  vz0Dist->SetMarkerSize(1);
  vz0Dist->SetMarkerColor(1);
  vz0Dist->SetLineColor(1);
*/
  vz0Dist->SetStats(0);
  //vz0Dist->Draw("Pez");
  vz0Dist->SetLineColor(2);
  vz1Dist->SetLineColor(2);
  vz2Dist->SetLineColor(4);
  vz0Dist->SetLineWidth(2);
  vz1Dist->SetLineWidth(2);
  vz2Dist->SetLineWidth(2);
  vz0Dist->Draw("h");
  //vz1Dist->Draw("same");
  //vz2Dist->Draw("same");

    TLegend *leg0 = new TLegend(0.33,0.25,0.52,0.305);
    leg0->SetFillColor(10);
    leg0->SetBorderSize(0.035);
    leg0->SetTextFont(42);
    leg0->SetTextSize(0.048);
    leg0->AddEntry(vz0Dist,"vertex[0] - vertex[1]","pl");
    //leg0->AddEntry(vz1Dist,"vertexz[1]","pl");
    //leg0->AddEntry(vz2Dist,"vertexz[2]","pl");
    leg0->Draw();

    TLatex *tex1= new TLatex(-0.6,vz0Dist->GetMaximum()*0.85,"Fill = 4643, run = 262274");
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

  cd->SaveAs("vzDz.png");

}
