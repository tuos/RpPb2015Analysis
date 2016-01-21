void plot(){

//const int nEvt = 1001;
const int nEvt = 1006;
double time[nEvt];
double rate[nEvt];
double rate2[nEvt];
double rate3[nEvt];
double mu[nEvt];
double tmp;
ifstream infile;
//infile.open("run262274Fill4643list_HLT_L1MinimumBiasHF1AND_v1.txt");
infile.open("run262274Fill4643list_HLT_L1MinimumBiasHF2OR_v1.txt");
//infile.open("run262274Fill4643list.txt");
//infile.open("old.txt");
for(int i=0; i<nEvt; i++){
infile>>time[i];
infile>>rate[i];
infile>>tmp;
rate2[i]=rate[i]*154349*2/1813/11246;
//rate2[i]=rate[i]*1155.0*20/1813/11246;
//rate2[i]=rate[i]*3329.0/296/11246;
mu[i]=-(log(1-rate2[i]));
rate3[i]=(rate2[i] + log(1-rate2[i])*(1-rate2[i]))/rate2[i];
//cout<<-log(1-rate2[i])<<endl;
}


  TCanvas *c1 = new TCanvas("c1","c1",1,1,550,410);
  c1->SetFillColor(10);
  c1->SetFrameFillColor(0);
  c1->SetFrameBorderSize(0);
  c1->SetFrameBorderMode(0);
  c1->SetLeftMargin(0.15);
  c1->SetBottomMargin(0.15);
  c1->SetTopMargin(0.05);
  c1->SetRightMargin(0.02);
  //c1->Divide(2,1,0,0);
  gStyle->SetOptStat(0);
  c1->SetTicks(-1);

 TH1D* hist = new TH1D("Timing","",1006,0.,1006);
 hist->SetXTitle("Lumi Section");
 //hist->SetYTitle("Event Fraction with more than one collision");
 hist->SetYTitle("Multiple Collision Fraction");
 //hist->SetYTitle("Average pileup (#mu)");
 //hist->SetMinimum(0.031);
 //hist->SetMaximum(0.041);
 hist->GetXaxis()->CenterTitle(1);
 hist->GetYaxis()->CenterTitle(1);
 hist->GetYaxis()->SetTitleOffset(1.);
 hist->GetXaxis()->SetTitleOffset(1.1);
 hist->GetXaxis()->SetTitleSize(0.06);
 hist->GetYaxis()->SetTitleSize(0.07);
 hist->GetXaxis()->SetLabelSize(0.05);
 hist->GetYaxis()->SetLabelSize(0.05);
for(int i=0; i<nEvt; i++){
hist->SetBinContent(i+1,rate3[i]);
//hist->SetBinContent(i+1,mu[i]);
}
 hist->SetMaximum(hist->GetMaximum()*1.4);
//hist->Scale(1.0/hist->GetEntries());
 hist->Draw();

//cout<<hist->GetMean()<<"  "<<hist->GetRMS()<<"  "<<hist->GetMeanError()<<"  "<<hist->GetMeanError()/hist->GetMean()*100<<"%"<<endl;

    TLatex *tex1= new TLatex(200.,hist->GetMaximum()*0.8,"Fill = 4643, run = 262274");
    //TLatex *tex1= new TLatex(45.42,3.5,"pPb \ #sqrt{s_{NN}} = 5.02 TeV");
    tex1->SetTextColor(1);
    tex1->SetTextSize(0.05);
    tex1->SetTextFont(42);
    tex1->Draw();

    TLatex *tex1= new TLatex(60.,hist->GetMaximum()*0.2,"HLT_L1MinimumBiasHF2OR_v1 gating with L1_MinimumBiasHF2_OR");
    //TLatex *tex1= new TLatex(60.,hist->GetMaximum()*0.2,"HLT_L1MinimumBiasHF1AND_v1 gating with L1_MinimumBiasHF1_AND");
    tex1->SetTextColor(1);
    tex1->SetTextSize(0.035);
    tex1->SetTextFont(42);
    tex1->Draw();

//c1->SaveAs("eventFractionFractionHF1AND.png");
c1->SaveAs("eventFractionFractionHF2OR.png");

//c1->SaveAs("eventFractionMuHF1AND.png");
//c1->SaveAs("eventFractionMuHF2OR.png");

}


