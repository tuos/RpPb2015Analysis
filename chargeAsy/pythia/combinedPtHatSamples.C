void combinedPtHatSamples(){

  char flavourSpectra[256] = "posChAll";
  char flavourSpectraFine[256] = "negChAll";
//  char flavourSpectra[256] = "spec_udsjets";
//  char flavourSpectraFine[256] = "spec_udsjets_fine";
//  char flavourSpectra[256] = "spec_cjets";
//  char flavourSpectraFine[256] = "spec_cjets_fine";
//  char flavourSpectra[256] = "spec_bjets";
//  char flavourSpectraFine[256] = "spec_bjets_fine";
//  char flavourSpectra[256] = "spec_gluonjets";
//  char flavourSpectraFine[256] = "spec_gluonjets_fine";
//  char flavourSpectra[256] = "spec_0jets";
//  char flavourSpectraFine[256] = "spec_0jets_fine";

  char energy[256] = "5020";
  char order[256] = "HAD";
  
  //const int MAXDIR = 61;
  const int MAXDIR = 4;

  // cross sections from the Pythia simulations:

  // Z2 cross sections

  if(energy=="2760"){
    // for 2.76 TeV
    //double xsec[10] = {6.198e+01, 5.135e-02, 9.742e-03, 9.250e-04,
    //                   8.812e-05, 9.771e-06, 1.256e-06, 1.795e-07,
    //                   2.708e-08, 4.735e-09};
    //2.76 these below are the exact values for the different pthats mentioned below. have to subtract them to get what we want. 
    //getting it from the log files (for when LO did not force shutoff the HAD and MPI part)
    //double xsec[12] = {6.198e01,1.921e-01,9.771e-03,9.253e-04,8.793e-05,9.766e-06,1.185e-06,2.310e-07,4.721e-08,5.128e-09,6.647e-10,1.483e-10};
    // when the LO is only LO, i.e the HAD and MPI are forced shut off: HAD should be the same as before: 
    if(order=="LO"){
      double xsec[12] = {6.198e01,1.855e-01,9.377e-03,9.009e-04,8.812e-05,1.008e-05,1.242e-06,2.477e-07,5.135e-08,5.65e-09,7.331e-10,1.624e-10};
    }else {
      // for HAD
      double xsec[12] = {6.199e01,1.925e-01,9.724e-03,9.255e-04,8.779e-05,9.791e-06,1.179e-06,2.315e-07,4.703e-08,5.136e-09,6.657e-10,1.478e-10};
    }
  }else {
    // for 5.02 TeV
    //double xsec[10] = {6.782e+01, 1.405e-01, 2.995e-02, 3.334e-03,
    //                  3.800e-04, 5.138e-05, 8.251e-06, 1.525e-06,
    //                   3.141e-07, 9.160e-08};
    // getting the cross section from the log files for LO without MPI and HAD declared.  
    //double xsec[12] = {6.782e01,4.988e-01,2.988e-02,3.329e-03,3.801e-04,5.183e-05,7.695e-06,1.863e-06,5.051e-07,8.381e-08,1.727e-08,7.847e-09};
    //for LO with forced HAD and MPI shut off: 
    if(order=="LO"){
      //double xsec[12] = {6.781e01,4.842e-01,2.873e-02,3.213e-03,3.709e-04,5.099e-05,7.807e-06,1.927e-06,5.319e-07,8.96e-08,1.877e-08,8.563e-09};
      double xsec[12] = {4.573e+01,4.842e-01,2.873e-02,3.213e-03,3.709e-04,5.099e-05,7.807e-06,1.927e-06,5.319e-07,8.96e-08,1.877e-08,8.563e-09}; //nsd for pthat0-15
    }else {
      //double xsec[12] = {6.784e01,4.992e-01,2.992e-02,3.332e-03,3.801e-04,5.132e-05,7.688e-06,1.867e-06,5.058e-07,8.378e-08,1.729e-08,7.831e-09};
      //double xsec[12] = {4.573e+01,4.992e-01,2.992e-02,3.332e-03,3.801e-04,5.132e-05,7.688e-06,1.867e-06,5.058e-07,8.378e-08,1.729e-08,7.831e-09}; //nsd for pthat0-15
      double xsec[12] = {6.782e+01,4.993e-01,2.994e-02,3.335e-03,3.799e-04,5.142e-05,7.693e-06,1.864e-06,5.053e-07,8.374e-08,1.729e-08,7.831e-09}; //nsd for pthat0-15
  }
  
  // for 7 TeV
  //double xsec[10] = {7.131e+01, 2.359e-01, 5.307e-02, 6.354e-03,
  //                   7.837e-04, 1.152e-04, 2.015e-05, 4.094e-06,
  //                   9.351e-07, 3.221e-07};
  }
  //the ones here were the old values. adding the new values 

  // need to fix first entry given as 0-inf. Subtract all 
  // other xsecs to get 0-15
  double xsec15toinf = 0.0;
  double totalxsec = xsec[0];
  for( int i=1;i<12;i++) xsec15toinf += xsec[i];
  xsec[0] = xsec[0] - xsec15toinf;

  // open files and get spectra and event counts 
  TFile * f[12];
  char rpthats[12][256] = {"0to15","15to30","30to50","50to80","80to120","120to170","170to220","220to280","280to370","370to460","460to540","540to5000"};
  //char rpthats[12][256] = {"0to15","15to30","30to50","50to80","80to120","120to170","170to220","220to280","280to370","370to460","460to540","540to5000"};
/*
  char dirname[MAXDIR][256] = {
    "ak3GenJetSpectrum_n10_p10","ak3GenJetSpectrum_n20_p20","ak3GenJetSpectrum_n25_n20","ak3GenJetSpectrum_n20_n15",
    "ak3GenJetSpectrum_n15_n10","ak3GenJetSpectrum_n10_n05","ak3GenJetSpectrum_n05_p05","ak3GenJetSpectrum_p05_p10",
    "ak3GenJetSpectrum_p10_p15","ak3GenJetSpectrum_p15_p20",
    "ak2GenJetSpectrum_n10_p10","ak2GenJetSpectrum_n20_p20","ak2GenJetSpectrum_n25_n20","ak2GenJetSpectrum_n20_n15",
    "ak2GenJetSpectrum_n15_n10","ak2GenJetSpectrum_n10_n05","ak2GenJetSpectrum_n05_p05","ak2GenJetSpectrum_p05_p10",
    "ak2GenJetSpectrum_p10_p15","ak2GenJetSpectrum_p15_p20",
    "ak4GenJetSpectrum_n10_p10","ak4GenJetSpectrum_n20_p20","ak4GenJetSpectrum_n25_n20","ak4GenJetSpectrum_n20_n15",
    "ak4GenJetSpectrum_n15_n10","ak4GenJetSpectrum_n10_n05","ak4GenJetSpectrum_n05_p05","ak4GenJetSpectrum_p05_p10",
    "ak4GenJetSpectrum_p10_p15","ak4GenJetSpectrum_p15_p20",
    "ak5GenJetSpectrum_n10_p10","ak5GenJetSpectrum_n20_p20","ak5GenJetSpectrum_n25_n20","ak5GenJetSpectrum_n20_n15",
    "ak5GenJetSpectrum_n15_n10","ak5GenJetSpectrum_n10_n05","ak5GenJetSpectrum_n05_p05","ak5GenJetSpectrum_p05_p10",
    "ak5GenJetSpectrum_p10_p15","ak5GenJetSpectrum_p15_p20",
    "ak7GenJetSpectrum_n10_p10","ak7GenJetSpectrum_n20_p20","ak7GenJetSpectrum_n25_n20","ak7GenJetSpectrum_n20_n15",
    "ak7GenJetSpectrum_n15_n10","ak7GenJetSpectrum_n10_n05","ak7GenJetSpectrum_n05_p05","ak7GenJetSpectrum_p05_p10",
    "ak7GenJetSpectrum_p10_p15","ak7GenJetSpectrum_p15_p20"
    };
*/
  char dirname[MAXDIR][256] = {
    "ak3GenJetSpectrum_n10_p10","ak3GenJetSpectrum_n20_p20",
    "ak5GenJetSpectrum_n10_p10","ak5GenJetSpectrum_n20_p20"
    };

  double etaWid[MAXDIR] = { 2.0,4.0,
                            2.0,4.0
  };



  // retrieve and normalize spectra
  TH1F * spectrum[12][MAXDIR];
  TH1F * spectrumf[12][MAXDIR];
  TH1F * events[12][MAXDIR];
  double nevt[12][MAXDIR]; 
  for( int i=0; i<12;i++)
  {
    //do it once for HAD and once for LO
    f[i] = new TFile(Form("./GenJet_%s_R23457_%s_Apr282016_Z2pt%s_numEvent500000.root",order,energy,rpthats[i]));
    for( int j=0; j<MAXDIR; j++)
    {

      events[i][j] = (TH1F *) f[i]->Get(Form("%s/events",dirname[j]));
      events[i][j]->SetName(Form("events_%d_%d",i,j));
      nevt[i][j] = events[i][j]->GetBinContent(1);
      spectrum[i][j] = (TH1F *) f[i]->Get(Form("%s/%s",dirname[j],flavourSpectra));
      spectrum[i][j]->SetName(Form("pos_%d_%d",i,j));
      spectrum[i][j]->Sumw2();
      spectrumf[i][j] = (TH1F *) f[i]->Get(Form("%s/%s",dirname[j],flavourSpectraFine));
      spectrumf[i][j]->SetName(Form("neg_%d_%d",i,j));
      spectrumf[i][j]->Sumw2();
      for( int bin = 1; bin <= spectrum[i][j]->GetNbinsX(); bin++)
      {
        double ptWid = spectrum[i][j]->GetBinWidth(bin);

        spectrum[i][j]->SetBinContent(bin,
                       spectrum[i][j]->GetBinContent(bin) 
                       / ptWid / etaWid[j] * xsec[i] / nevt[i][j] ); 
                       // / ptWid / etaWid[j] / nevt[i][j] ); 
        spectrum[i][j]->SetBinError(bin,
                       spectrum[i][j]->GetBinError(bin) 
                       / ptWid / etaWid[j] * xsec[i] / nevt[i][j]  ); 
                       // / ptWid / etaWid[j] / nevt[i][j]  ); 
        //spectrum[i][j]->Scale(1.0/ ptWid / etaWid[j] * xsec[i] / nevt[i][j]);

      }
      for( int bin = 1; bin <= spectrumf[i][j]->GetNbinsX(); bin++)
      {
        double ptWid = spectrumf[i][j]->GetBinWidth(bin);
        spectrumf[i][j]->SetBinContent(bin,
                       spectrumf[i][j]->GetBinContent(bin)
                       / ptWid / etaWid[j] * xsec[i] / nevt[i][j] );
        spectrumf[i][j]->SetBinError(bin,
                       spectrumf[i][j]->GetBinError(bin)
                       / ptWid / etaWid[j] * xsec[i] / nevt[i][j]  );
      }
    }
  }


  // add spectra
  TH1F * spectrum_out[MAXDIR];
  TH1F * spectrumf_out[MAXDIR];

  //TFile * f_out = new TFile(Form("rootfiles_Mar2/GenJet_%s_R23457_%sGeV_Mar2_Z2Combined.root",order,energy),"RECREATE");
  TFile * f_out = new TFile(Form("./outGenJet_%s_R23457_%sGeV_Apr282016_FLAVOUR%s_Z2Combined.root",order,energy,flavourSpectra),"RECREATE");

  for( int j=0;j<MAXDIR;j++)
  {
    TDirectory * tdir = f_out->mkdir(dirname[j]);
    for( int i=1;i<12;i++) spectrum[0][j]->Add(spectrum[i][j],1.0);
    //for( int i=1;i<12;i++) spectrum[0][j]->Add(spectrum[i][j],xsec[i]);
    for( int i=1;i<12;i++) spectrumf[0][j]->Add(spectrumf[i][j],1.0);
    spectrum_out[j] =  (TH1F *) spectrum[0][j]->Clone(Form("Pos_Spectra"));
    spectrum_out[j]->SetDirectory(tdir);
    spectrumf_out[j] = (TH1F *) spectrumf[0][j]->Clone(Form("Neg_Spectra"));
    spectrumf_out[j]->SetDirectory(tdir);
  }

  f_out->Write();

  for( int bin = 1; bin <= spectrum_out[0]->GetNbinsX(); bin++){
    if(spectrum_out[0]->GetBinContent(bin)>0)
    cout<<"bin="<<bin<<", pt="<<spectrum_out[0]->GetBinCenter(bin)<<", BinContent="<<spectrum_out[0]->GetBinContent(bin)<<", err="<<spectrum_out[0]->GetBinError(bin)<<", pErr="<<spectrum_out[0]->GetBinError(bin)/spectrum_out[0]->GetBinContent(bin)<<endl;
  }  


}

