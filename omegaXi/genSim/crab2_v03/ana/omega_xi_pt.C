#include "vandyStyle.h"

  void SetHistStyle(){
    gPad->SetTicks();
    gPad->SetLeftMargin(0.14);
    gPad->SetBottomMargin(0.16);
    gPad->SetTopMargin(0.02);
    gPad->SetRightMargin(0.02);
    //gPad->SetLogx(1);
    gPad->SetLogy(1);
  }

void omega_xi_pt()
{


 TFile * infile = TFile::Open("./MiniForestAODMC_mergedAllfiles.root");
 TTree * tgen = (TTree *) infile->Get("HiGenParticleAna/hi");
 //float pt;               tgen->SetBranchAddress("pt", &pt);
 //float pdg;              tgen->SetBranchAddress("pdg", &pdg);
 //tgen->Draw("pt","pdg==3312");

  vandyStyle();
  TCanvas* c1 = makeMultiCanvas("c1","c1", true, true);
  TH1D *htemp = makeHist("htemp", "", "p_{T} (GeV/c)", "Yield", 200, 0.0, 50, kBlack);
  htemp->SetAxisRange(1e-1,1e6,"Y");
  fixedFontHist1D(htemp, 1.1, 1.1);
  SetHistStyle();
  htemp->Draw();
  //TH1D *hptx;
  tgen->Draw("pt>>hptx","pdg==3312||pdg==-3312","goff");
  //hptx->SetAxisRange(0,50,"X");
  hptx->SetLineWidth(2);
  hptx->SetLineColor(1);
  hptx->Draw("hsame");
  tgen->Draw("pt>>hpto","pdg==3334||pdg==-3334","goff");
  //hpto->SetAxisRange(0,50,"X");
  hpto->SetLineWidth(2);
  hpto->SetLineColor(2);
  hpto->Draw("hsame");

    TLegend *leg0 = new TLegend(0.55,0.73,0.8,0.905);
    leg0->SetFillColor(10);
    leg0->SetBorderSize(0.035);
    leg0->SetTextFont(42);
    leg0->SetTextSize(0.048);
    leg0->AddEntry(hptx,"Xi+/-","pl");
    leg0->AddEntry(hpto,"Omega+/-","pl");
    leg0->Draw();
    TLatex *tex1= new TLatex(25.,8e2,"pp 5 TeV, |#eta|<2.4");
    tex1->SetTextColor(1);
    tex1->SetTextSize(0.05);
    tex1->SetTextFont(42);
    tex1->Draw();
  c1->SaveAs("plot_xi_omega_genfilter.png");

}
