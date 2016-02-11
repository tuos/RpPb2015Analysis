#include "TRandom3.h"
dz_pp_Plot(){

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

  //TH1D *hdzRandom = (TH1D*) vzDZW2->Clone("hdzRandom");
  for(int i=0; i<1000; i++){
    //hdzRandom->SetBinContent(i+1,0);
    //hdzRandom->SetBinError(i+1,0);
  }
  TH1D *hdzRandom = new TH1D("hdzrandom","hdzRandom", 1000, -10,10);  
  rnd = new TRandom3(0);
  const int nTry=5000000;
  for(int i=0; i<nTry; i++){
    double v1=vz0Dist->GetRandom();
    double v2=vz1Dist->GetRandom();

    if(fabs(v1-v2)>0.2) hdzRandom->Fill(v1-v2);
    if(fabs(v1-v2)<0.2 && fabs(v1-v2)>0.1) if(rnd->Uniform(0.0,1)>0.1)hdzRandom->Fill(v1-v2);
    if(fabs(v1-v2)<0.1 && fabs(v1-v2)>0.05) if(rnd->Uniform(0.0,1)>0.2)hdzRandom->Fill(v1-v2);
    if(fabs(v1-v2)<0.05 && fabs(v1-v2)>0.01) if(rnd->Uniform(0.0,1)>0.3)hdzRandom->Fill(v1-v2);
    if(fabs(v1-v2)<0.01 && fabs(v1-v2)>0.0) if(rnd->Uniform(0.0,1)>0.6)hdzRandom->Fill(v1-v2);

    //hdzRandom->Fill(v1-v2);

  }

  TH1D *vz0pDist = (TH1D*) hdzRandom->Clone("vz0pDist");
  TCanvas* cd = new TCanvas("cd","",500,500);
  cd->SetLeftMargin(0.15);
  cd->SetRightMargin(0.02);
  cd->SetTopMargin(0.02);
  cd->SetBottomMargin(0.11);
  cd->SetTicks(1);
  //cd->SetLogy();
  gStyle->SetOptStat(0);
  vz0pDist->SetTitle("");
  vz0pDist->SetXTitle("v1 - v2 (cm)");
  vz0pDist->SetYTitle("Number of Events");
  vz0pDist->GetYaxis()->SetTitleOffset(1.6);
  vz0pDist->GetXaxis()->SetTitleOffset(1.);
  vz0pDist->GetXaxis()->CenterTitle(1);
  vz0pDist->GetYaxis()->CenterTitle(1);
  vz0pDist->GetXaxis()->SetTitleSize(0.046);
  vz0pDist->GetYaxis()->SetTitleSize(0.046);
  vz0pDist->GetXaxis()->SetTitleFont(62);
  vz0pDist->GetYaxis()->SetTitleFont(62);
  //vz0pDist->SetAxisRange(100,vz0pDist->GetMaximum()*10.4,"Y");
  vz0pDist->SetAxisRange(0,vz0pDist->GetMaximum()*1.4,"Y");
  vz0pDist->SetAxisRange(-1.0,1.0,"X");
  //vz0pDist->SetAxisRange(0,122,"X");
/*
  vz0pDist->SetMarkerStyle(20);
  vz0pDist->Sumw2();
  vz0pDist->SetMarkerSize(1);
  vz0pDist->SetMarkerColor(1);
  vz0pDist->SetLineColor(1);
*/
  vz0pDist->SetStats(0);
  //vz0pDist->Draw("Pez");
  vz0pDist->SetLineColor(2);
  vz1Dist->SetLineColor(2);
  vz2Dist->SetLineColor(4);
  vz0pDist->SetLineWidth(2);
  vz1Dist->SetLineWidth(2);
  vz2Dist->SetLineWidth(2);
  vz0pDist->Draw("h");
  //vz1Dist->Draw("same");
  //vz2Dist->Draw("same");

    TLegend *leg0 = new TLegend(0.43,0.15,0.68,0.355);
    leg0->SetFillColor(10);
    leg0->SetBorderSize(0.035);
    leg0->SetTextFont(42);
    leg0->SetTextSize(0.048);
    leg0->AddEntry(vz0pDist,"vertex[0] - vertex[1]","pl");
    //leg0->AddEntry(vz1Dist,"vertexz[1]","pl");
    //leg0->AddEntry(vz2Dist,"vertexz[2]","pl");
    leg0->Draw();

    TLatex *tex1= new TLatex(-6.,vz0pDist->GetMaximum()*0.85,"Fill = 4643, run = 262274");
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

  //cd->SaveAs("vz0pDist.png");
  cd->SaveAs("vz_dz_m1p1_v1.png");

}
