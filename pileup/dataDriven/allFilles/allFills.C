{
   const int nL=6417;
   int time[6][nL];
   double tmpd;
   int tmpi;
   double xtime[nL];
   double mu[nL];
   TDatime *da[nL];

   ifstream infile;
   infile.open("readyAllFills.txt");
   for(int i=0; i<nL; i++)
   {
     infile>>tmpi>>tmpi>>tmpi>>time[0][i]>>time[1][i]>>time[2][i]>>time[3][i]>>time[4][i]>>time[5][i]>>tmpd>>mu[i]>>tmpd;
     da[i] = new TDatime(time[0][i],time[1][i],time[2][i],time[3][i],time[4][i],time[5][i]);
     xtime[i] = da[i]->Convert(); 
  }

   //TDatime da5(2008,02,28,19,56,00);
   //x[4] = da5.Convert();
  TCanvas* c1 = new TCanvas("c1","",1100,400);
  c1->SetLeftMargin(0.06);
  c1->SetRightMargin(0.02);
  c1->SetTopMargin(0.02);
  c1->SetBottomMargin(0.12);
  c1->SetTicks(1);
  c1->SetGridx(1);
  c1->SetGridy(1);
  //c1->SetLogy();
  gStyle->SetOptStat(0);

   TGraph mgr(nL,xtime,mu);
   mgr.SetTitle("");
   mgr.SetMarkerStyle(24);
   mgr.SetMarkerColor(2);

   mgr.GetXaxis()->SetTimeDisplay(1);
   mgr.GetXaxis()->SetNdivisions(-504);
   mgr.GetXaxis()->SetTimeFormat("%Y-%m-%d %H:%M");
   mgr.GetXaxis()->SetTimeOffset(0,"gmt");
   mgr.GetXaxis()->SetLabelOffset(0.05);
   mgr.GetXaxis()->SetLabelSize(0.05);
   mgr.GetXaxis()->SetLabelFont(62);
   mgr.GetYaxis()->SetTitle("Average Pileup (#mu)");
   mgr.GetYaxis()->SetTitleSize(0.05);
   mgr.GetYaxis()->SetTitleFont(62);
   mgr.GetYaxis()->SetTitleOffset(0.56);
   mgr.GetYaxis()->CenterTitle(1);
   mgr.GetYaxis()->SetLabelOffset(0.003);
   mgr.GetYaxis()->SetLabelSize(0.05);
   mgr.GetYaxis()->SetLabelFont(62);
   mgr.Draw("ap");
 

    TLegend *leg0 = new TLegend(0.25,0.73,0.3,0.905);
    leg0->SetFillColor(10);
    leg0->SetBorderSize(0.035);
    leg0->SetTextFont(42);
    leg0->SetTextSize(0.048);
    //leg0->AddEntry(hptx,"Xi+/-","pl");
    //leg0->AddEntry(hpto,"Omega+/-","pl");
    //leg0->Draw();
    TLatex *tex1= new TLatex(xtime[0]-(xtime[660]-xtime[0])/2,1.05,"pp 5.02 TeV");
    tex1->SetTextColor(1);
    tex1->SetTextSize(0.05);
    tex1->SetTextFont(62);
    tex1->Draw();
    TLatex *tex1= new TLatex(xtime[0]-(xtime[660]-xtime[0])/2,0.9,"L1_MinimumBiasHF2_OR");
    tex1->SetTextColor(1);
    tex1->SetTextSize(0.05);
    tex1->SetTextFont(62);
    tex1->Draw();

 c1->SaveAs("plot_pilupData_L1_MinimumBiasHF2_OR_AllFills.png"); 

}
