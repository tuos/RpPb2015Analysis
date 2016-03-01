//# Shengquan Tuo on Feb. 20, 2016 in Nashville
#include <stdio.h>
#include <iostream>
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TH1F.h"
#include "TProfile.h"
#include "TTree.h"
#include <TMath.h>
#define Pi 3.14159265359

//
// class declaration
//

class TrackSlurm {
   public:
      //TrackSlurm(TString);
      TrackSlurm();
      ~TrackSlurm(){};

//        void beginJob();
        void getHistograms(TString, TString);
//        void endJob(TString); 

      // ----------member data ---------------------------
   private:
//        TH1D *ptHist;
//        TH1D *vzHist;

        //TString xinFileName;


};

//TrackSlurm::TrackSlurm(TString fileName)
TrackSlurm::TrackSlurm()
{
        //xinFileName = fileName;
}

//void TrackSlurm::beginJob()
//{
//
//}

void TrackSlurm::getHistograms(TString inFile, TString outFile)
{
TString inFileName;
inFileName = inFile;
const int nPtBin=34;
double ptBins[nPtBin+1]={0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.4,1.6,1.8,2.0,2.2,2.4,3.2,4.0,4.8,5.6,6.4,7.2,9.6,12.0,14.4,19.2,24.0,28.8,35.2,41.6,48.0,60.8,73.6,86.4,103.6,120.8};
TH1D *ptHist = new TH1D("pthist","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *vzHist = new TH1D("vzhist","generalTracks pT Distribution", 100, -25,25);
TH1D *nVzHist = new TH1D("nvzhist","generalTracks pT Distribution", 10, 0,10);
TH1D *nVzHistNoES = new TH1D("nvzhistnoes","generalTracks pT Distribution", 10, 0,10);
TH1D *nVz1PtHist = new TH1D("nvz1pthist","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *vzHistNoES = new TH1D("vzhistnoes","generalTracks pT Distribution", 100, -25,25);
TH1D *vzHistnVz1 = new TH1D("vzhistnvz1","generalTracks pT Distribution", 100, -25,25);

TH1D *ptHistHits = new TH1D("pthisthits","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *nVz1PtHistHits = new TH1D("nvz1pthisthits","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *ptHistCalo = new TH1D("pthistcalo","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *nVz1PtHistCalo = new TH1D("nvz1pthistcalo","generalTracks pT Distribution", nPtBin, ptBins);

const Int_t maxn = 90000;
  Float_t b, sumethf, sume3gev;
  Float_t npart, ncoll;
  Int_t nhreco, nhgen, nhf;
  Float_t ptreco[maxn], etareco[maxn], phireco[maxn];
  Float_t ptgen[maxn], etagen[maxn], phigen[maxn];
  Float_t ethf[maxn], ehf[maxn], etahf[maxn], phihf[maxn];
  Float_t gb, gsumethf, gsume3gev;
  Float_t gnpart, gncoll;
  Int_t gnhreco, gnhgen, gnhf;
  Float_t gptreco[maxn], getareco[maxn], gphireco[maxn];
  Float_t gptgen[maxn], getagen[maxn], gphigen[maxn];
  Float_t gethf[maxn], gehf[maxn], getahf[maxn], gphihf[maxn];

Bool_t highPurity[maxn];
Float_t a1[maxn], a2[maxn],a3[maxn],a4[maxn],a5[maxn],a6[maxn];
Int_t nhNtrk;

Int_t HLT_PAZeroBiasPixel_SingleTrack_v1=0;
Int_t phltPixelClusterShapeFilter=0;
Int_t phfPosFilter1=0;
Int_t phfNegFilter1=0;
Int_t pprimaryvertexFilter=0;
Int_t Run=0;
Int_t CentBin=-1;
Float_t vz;

  long Nevt;


  int pVtx;
  int pBeamScrape;
  int pnVtx;
  float trkMVA[maxn];
  unsigned char trkNHit[maxn]; 
  float pfEcal[maxn];
  float pfHcal[maxn];

  TFile * file = TFile::Open(inFileName);
  TTree * tree = (TTree *) file->Get("hiEvtAnalyzer/HiTree");
  tree->AddFriend("pptrack=ppTrack/trackTree");
  tree->AddFriend("skimTree=skimanalysis/HltTree");
  tree->AddFriend("hltTree=hltanalysis/HltTree");
     tree->SetBranchAddress("vz",&vz);
     tree->SetBranchAddress("nTrk",&nhreco);
     tree->SetBranchAddress("trkPt",&ptreco);
     tree->SetBranchAddress("trkEta",&etareco);
     tree->SetBranchAddress("trkPhi",&phireco);
     tree->SetBranchAddress("trkDz1",&a1);
     tree->SetBranchAddress("trkDzError1",&a2);
     tree->SetBranchAddress("trkDxy1",&a3);
     tree->SetBranchAddress("trkDxyError1",&a4);
     tree->SetBranchAddress("trkPtError",&a5);
     tree->SetBranchAddress("highPurity",&highPurity);
     tree->SetBranchAddress("trkMVA",&trkMVA);
     tree->SetBranchAddress("trkNHit",&trkNHit);
     tree->SetBranchAddress("pfHcal",&pfHcal);
     tree->SetBranchAddress("pfEcal",&pfEcal);
     //tree->SetBranchAddress("HLT_PAZeroBiasPixel_SingleTrack_v1",&HLT_PAZeroBiasPixel_SingleTrack_v1);
     //tree->SetBranchAddress("phltPixelClusterShapeFilter",&phltPixelClusterShapeFilter);
     //tree->SetBranchAddress("phfPosFilter1",&phfPosFilter1);
     //tree->SetBranchAddress("phfNegFilter1",&phfNegFilter1);
     //tree->SetBranchAddress("pprimaryvertexFilter",&pprimaryvertexFilter);
     //tree->SetBranchAddress("hiHFplusEta4",&hfpluseta4);
     //tree->SetBranchAddress("hiHFminusEta4",&hfminuseta4);
     //tree->SetBranchAddress("hiNtracks",&ntrks);
     tree->SetBranchAddress("pPAprimaryVertexFilter",&pVtx);
     tree->SetBranchAddress("pBeamScrapingFilter",&pBeamScrape);
     tree->SetBranchAddress("nVtx",&pnVtx);
     Nevt=tree->GetEntries();  cout<<"Entries= "<<Nevt<<endl;

     for(long ne=0; ne<Nevt; ne++){
     //for(long ne=0; ne<30000; ne++){
       if(ne%3000==0)  cout<<"Have run "<<ne<<" events. "<<endl;
       tree->GetEntry(ne);

       nVzHistNoES->Fill(pnVtx*pVtx);
       vzHistNoES->Fill(vz);    
       if(!(pVtx&&pBeamScrape)) continue;
         nVzHist->Fill(pnVtx);
         vzHist->Fill(vz);
         if(pnVtx==1)
           vzHistnVz1->Fill(vz);
         for(int ni=0;ni<nhreco;ni++){

           if(highPurity[ni]&&fabs(a1[ni]/a2[ni])<3&&fabs(a3[ni]/a4[ni])<3&&a5[ni]/ptreco[ni]<0.1&&ptreco[ni]>0.4&&fabs(etareco[ni])<2.4){
             ptHist->Fill(ptreco[ni]);
             if(pnVtx==1) 
               nVz1PtHist->Fill(ptreco[ni]);
           }

           if(highPurity[ni]&&fabs(a1[ni]/a2[ni])<3&&fabs(a3[ni]/a4[ni])<3&&a5[ni]/ptreco[ni]<0.3&&ptreco[ni]>0.4&&ptreco[ni]<120.8&&fabs(etareco[ni])<2.4&&((int)trkNHit[ni]>7)&&(trkMVA[ni]>0.5 || trkMVA[ni]==-99)){
             ptHistHits->Fill(ptreco[ni]);
             if(pnVtx==1)
               nVz1PtHistHits->Fill(ptreco[ni]);
           }

           float Et = (pfHcal[ni]+pfEcal[ni])/TMath::CosH(etareco[ni]);
           //if(!(trkPt[ni]<20 || (Et>0.2*trkPt[ni] && Et>trkPt[ni]-80))) continue; //Calo Matching
           if(highPurity[ni]&&fabs(a1[ni]/a2[ni])<3&&fabs(a3[ni]/a4[ni])<3&&a5[ni]/ptreco[ni]<0.3&&ptreco[ni]>0.4&&ptreco[ni]<120.8&&fabs(etareco[ni])<2.4&&(ptreco[ni]<20 || (Et>0.2*ptreco[ni] && Et>ptreco[ni]-80))){
             ptHistCalo->Fill(ptreco[ni]);
             if(pnVtx==1)
               nVz1PtHistCalo->Fill(ptreco[ni]);
           }

         }
     }

//////
TString outFileName;
outFileName = outFile;
  TFile * outFiles = TFile::Open(outFileName,"recreate");
  outFiles->cd();
  vzHist->Write();
  ptHist->Write();
  nVzHistNoES->Write();
  nVzHist->Write();
  nVz1PtHist->Write();
  vzHistNoES->Write();
  vzHistnVz1->Write();
  ptHistHits->Write();
  nVz1PtHistHits->Write();
  ptHistCalo->Write();
  nVz1PtHistCalo->Write();
  outFiles->Close();

  delete vzHist;
  delete ptHist;
  delete nVzHistNoES;
  delete nVzHist;
  delete nVz1PtHist;
  delete vzHistNoES;
  delete vzHistnVz1;
  delete ptHistHits;
  delete nVz1PtHistHits;
  delete ptHistCalo;
  delete nVz1PtHistCalo;

}

//void TrackSlurm::endJob(TString outFileName)
//{
//
//}

