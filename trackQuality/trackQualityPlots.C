
void trackQualityPlots(){
// /Users/tuos/Desktop/soft/run2015/analysisNote/pp/austinRawResults/compRaw
TH1D::SetDefaultSumw2();

  TFile* fpu = new TFile("histogram_test_MB_ppmc.root");
  TH1D* lumiPU1  = fpu->Get("demo/dxyOverdxyErrHist");
  //TH1D* lumiPU1  = fpu->Get("demo/dzOverdzErrHist");
  //TH1D* lumiPU1  = fpu->Get("demo/chi2OverndofHist");
  //TH1D* lumiPU1  = fpu->Get("demo/chi2OverndofHist10_15");
  //TH1D* lumiPU1  = fpu->Get("demo/chi2OverndofHist20_");
  //TH1D* lumiPU1  = fpu->Get("demo/ptErrOverptHist");
  //TH1D* lumiPU1  = fpu->Get("demo/dxyOverdxyErrHist10_15");
  TH1D* lumiPU1n  = fpu->Get("demo/higeneraltrackshist");
  TFile* fpu2 = new TFile("histogram_test_MB_pp.root");
  TH1D* lumiPU2  = fpu2->Get("demo/dxyOverdxyErrHist");
  //TH1D* lumiPU2  = fpu2->Get("demo/dzOverdzErrHist");
  //TH1D* lumiPU2  = fpu2->Get("demo/chi2OverndofHist");
  //TH1D* lumiPU2  = fpu2->Get("demo/chi2OverndofHist10_15");
  //TH1D* lumiPU2  = fpu2->Get("demo/chi2OverndofHist20_");
  //TH1D* lumiPU2  = fpu2->Get("demo/ptErrOverptHist");
  //TH1D* lumiPU2  = fpu2->Get("demo/dxyOverdxyErrHist10_15");
  TH1D* lumiPU2n  = fpu2->Get("demo/higeneraltrackshist");


  TH1D *puEff1, *puEff2, *puEff3, *puEff4;
  TH1D *puEff1p, *puEff2p, *puEff3p, *puEff4p;
  TH1D *puEff1n, *puEff2n, *puEff3n, *puEff4n;
  //puEff1 = (TH1D*) lumiPU1->ProjectionY(Form("puEff1"), 1, 12);
  //puEff1n = (TH1D*) lumiPU1n->ProjectionY(Form("puEff1n"), 1, 12);
  TH1D *puEffx, *puEffxp, *puEffxn;
  puEffx = (TH1D*) lumiPU1->Clone(Form("puEffx"));  
  puEffxn = (TH1D*) lumiPU1n->Clone(Form("puEffxn"));  
  puEff2 = (TH1D*) lumiPU2->Clone(Form("puEff2"));  
  puEff2n = (TH1D*) lumiPU2n->Clone(Form("puEff2n"));  


  puEffx->Scale(1.0/puEffx->GetEntries());
  puEff2->Scale(1.0/puEff2->GetEntries());


  TCanvas* cd = new TCanvas("cd","",500,500);
  cd->SetLeftMargin(0.12);
  cd->SetRightMargin(0.02);
  cd->SetTopMargin(0.02);
  cd->SetBottomMargin(0.12);
  cd->SetTicks(1);
  //cd->SetLogx();
  cd->SetLogy();
  gStyle->SetOptStat(0);
  puEffx->SetTitle("");
  puEffx->SetYTitle("Normalized by # of tracks");
  puEffx->SetXTitle("d_{xy}/#sigma_{xy}");
  //puEffx->SetXTitle("d_{z}/#sigma_{z}");
  //puEffx->SetXTitle("#chi^{2}/Ndof");
  //puEffx->SetXTitle("p_{T}Error/p_{T}");
  puEffx->GetYaxis()->SetTitleOffset(1.2);
  puEffx->GetXaxis()->SetTitleOffset(1.2);
  puEffx->GetXaxis()->CenterTitle(1);
  puEffx->GetYaxis()->CenterTitle(1);
  puEffx->GetXaxis()->SetTitleSize(0.046);
  puEffx->GetYaxis()->SetTitleSize(0.046);
  puEffx->GetXaxis()->SetTitleFont(62);
  puEffx->GetYaxis()->SetTitleFont(62);
  //puEffx->SetAxisRange(1e-4,puEffx->GetMaximum()*1.4,"Y");
  //puEffx->Scale(-1);
  //puEffx->SetAxisRange(1e-13,3e2,"Y");
  puEffx->SetAxisRange(1e-5,puEffx->GetMaximum()*10.4,"Y");
  //puEffx->SetAxisRange(1e-8,puEffx->GetMaximum()*10.4,"Y");
  //puEffx->SetAxisRange(0.,20,"X");

  int nrebin=2;
  puEffx->Rebin(nrebin);
  puEffx->Scale(1.0/nrebin);
  puEff2->Rebin(nrebin);
  puEff2->Scale(1.0/nrebin);
  puEffx->SetAxisRange(0.,20,"X");

  puEffx->SetStats(0);
  puEffx->SetLineColor(1);
  puEffx->SetLineWidth(2);
  puEffx->SetMarkerColor(1);
  puEffx->SetMarkerStyle(20);
  puEffx->SetMarkerSize(1.5);
  puEffx->Draw("pez");
  puEff2->SetStats(0);
  puEff2->SetLineColor(2);
  puEff2->SetLineWidth(2);
  puEff2->SetMarkerColor(2);
  puEff2->SetMarkerStyle(25);
  puEff2->SetMarkerSize(1.5);
  puEff2->Draw("pezsame");

    TLegend *leg0 = new TLegend(0.61,0.65,0.85,0.795);
    leg0->SetFillColor(10);
    leg0->SetBorderSize(0.035);
    leg0->SetTextFont(42);
    leg0->SetTextSize(0.048);
    //leg0->AddEntry(spectraCombined,"All charged particles","pl");
    //leg0->AddEntry(spectraCombinedp,"Postive charged","pl");
    //leg0->AddEntry(spectraCombinedn,"Negative charged","pl");
    leg0->AddEntry(puEffx,"MC","pl");
    leg0->AddEntry(puEff2,"DATA","pl");
    //leg0->AddEntry(puEff2,"Jet40","pl");
    //leg0->AddEntry(puEff3,"Jet60","pl");
    //leg0->AddEntry(puEff4,"Jet80","pl");
    leg0->Draw();

    //TLatex *tex1= new TLatex(200.,puEffx->GetMaximum()*0.85,"ak4Calo Jets, |#eta|<2");
    //TLatex *tex1= new TLatex(2.11,puEffx->GetMaximum()*0.95,"pp 5.02 TeV,|#eta|<1,10<p_{T}<15 GeV/c");
    //TLatex *tex1= new TLatex(2.11,puEffx->GetMaximum()*1.55,"pp 5.02 TeV,|#eta|<1,p_{T}>20 GeV/c");
    //TLatex *tex1= new TLatex(4.11,puEffx->GetMaximum()*0.25,"pp 5.02 TeV, |#eta|<1");
    TLatex *tex1= new TLatex(0.81,puEffx->GetMaximum()*0.15,"pp 5.02 TeV, |#eta|<1");
    //TLatex *tex1= new TLatex(45.42,3.5,"pPb \ #sqrt{s_{NN}} = 5.02 TeV");
    tex1->SetTextColor(1);
    tex1->SetTextSize(0.05);
    tex1->SetTextFont(42);
    tex1->Draw();
    TLatex *tex1= new TLatex(1.11,0.4,"5.02 TeV");
    tex1->SetTextColor(1);
    tex1->SetTextSize(0.05);
    tex1->SetTextFont(42);
    //tex1->Draw();
TLine *line = new TLine(0.4,1,200,1);
line->SetLineStyle(2);
line->SetLineWidth(2);
//line->Draw();

    TLatex *tex2= new TLatex(40.5,3*10e-5,"1687M MB events, |#eta|<1.0");
    tex2->SetTextColor(1);
    tex2->SetTextSize(0.05);
    tex2->SetTextFont(42);
    //tex2->Draw();
  cd->SaveAs("plot_trackquality_ppdatamc_dxy.png");
  //cd->SaveAs("plot_trackquality_ppdatamc_dz.png");
  //cd->SaveAs("plot_trackquality_ppdatamc_chindof.png");
  //cd->SaveAs("plot_trackquality_ppdatamc_chindof10_15.png");
  //cd->SaveAs("plot_trackquality_ppdatamc_chindof20_.png");
  //cd->SaveAs("plot_trackquality_ppdatamc_pterrpt.png");

}
