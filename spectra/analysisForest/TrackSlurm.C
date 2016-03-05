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

TH1D *ptHistCalo = new TH1D("pthistcalo","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *nVz1PtHistCalo = new TH1D("nvz1pthistcalo","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *gPtVtxptHistCalo = new TH1D("gptvtxpthistcalo","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *allVtxptHistCalo = new TH1D("allvtxpthistcalo","generalTracks pT Distribution", nPtBin, ptBins);

TH1D *proIDnVtx0Hist = new TH1D("proidnvtx0hist","process ID Distribution", 10, 100,110);
TH1D *proIDnVtxnHist = new TH1D("proidnvtxnhist","process ID Distribution", 10, 100,110);
TH1D *proIDAllHist = new TH1D("proidallhist","process ID Distribution", 10, 100,110);
TH1D *proIDESHist = new TH1D("proideshist","process ID Distribution", 10, 100,110);

TH1D *nVzHistNoESWithHLT = new TH1D("nvzhistnoeswithhlt","generalTracks pT Distribution", 10, 0,10);
TH1D *proIDnVtx0HLTHist = new TH1D("proidnvtx0hlthist","process ID Distribution", 10, 100,110);
TH1D *proIDnVtxnHLTHist = new TH1D("proidnvtxnhlthist","process ID Distribution", 10, 100,110);
TH1D *proIDHLTHist = new TH1D("proidhlthist","process ID Distribution", 10, 100,110);
TH1D *proIDHLTESHist = new TH1D("proidhlteshist","process ID Distribution", 10, 100,110);

const Int_t maxn = 90000;
Float_t vz;
Int_t processid;
Int_t HLT_L1MinimumBiasHF1OR_v1;
Int_t nTrk;
Float_t trkPt[maxn], trkEta[maxn], trkPhi[maxn];
Bool_t highPurity[maxn];
Float_t trkDz1[maxn], trkDzError1[maxn],trkDxy1[maxn],trkDxyError1[maxn],trkPtError[maxn];
Int_t nTrkTimesnVtx;
Float_t trkDzOverDzError[maxn], trkDxyOverDxyError[maxn];


  long Nevt;
  int pVtx;
  int pBeamScrape;
  int nVtx;
  float trkMVA[maxn];
  unsigned char trkNHit[maxn]; 
  float pfEcal[maxn];
  float pfHcal[maxn];

  TFile * file = TFile::Open(inFileName);
  TTree * tree = (TTree *) file->Get("hiEvtAnalyzer/HiTree");
  tree->AddFriend("pptrack=ppTrack/trackTree");
  tree->AddFriend("skimTree=skimanalysis/HltTree");
  tree->AddFriend("hltTree=hltanalysis/HltTree");
  tree->AddFriend("genTree=HiGenParticleAna/hi");
     tree->SetBranchAddress("vz",&vz);
     tree->SetBranchAddress("processid",&processid);
     tree->SetBranchAddress("HLT_L1MinimumBiasHF1OR_v1",&HLT_L1MinimumBiasHF1OR_v1);
     tree->SetBranchAddress("nTrk",&nTrk);
     tree->SetBranchAddress("trkPt",&trkPt);
     tree->SetBranchAddress("trkEta",&trkEta);
     tree->SetBranchAddress("trkPhi",&trkPhi);
     tree->SetBranchAddress("trkDz1",&trkDz1);
     tree->SetBranchAddress("trkDzError1",&trkDzError1);
     tree->SetBranchAddress("trkDxy1",&trkDxy1);
     tree->SetBranchAddress("trkDxyError1",&trkDxyError1);
     tree->SetBranchAddress("nTrkTimesnVtx",&nTrkTimesnVtx);
     tree->SetBranchAddress("trkDzOverDzError",&trkDzOverDzError);
     tree->SetBranchAddress("trkDxyOverDxyError",&trkDxyOverDxyError);
     //tree->SetBranchAddress("",&);
     tree->SetBranchAddress("trkPtError",&trkPtError);
     tree->SetBranchAddress("highPurity",&highPurity);
     tree->SetBranchAddress("trkMVA",&trkMVA);
     tree->SetBranchAddress("trkNHit",&trkNHit);
     tree->SetBranchAddress("pfHcal",&pfHcal);
     tree->SetBranchAddress("pfEcal",&pfEcal);
     tree->SetBranchAddress("pPAprimaryVertexFilter",&pVtx);
     tree->SetBranchAddress("pBeamScrapingFilter",&pBeamScrape);
     tree->SetBranchAddress("nVtx",&nVtx);
     Nevt=tree->GetEntries();  cout<<"Entries= "<<Nevt<<endl;

     for(long ne=0; ne<Nevt; ne++){
     //for(long ne=0; ne<10000; ne++){
       if(ne%3000==0)  cout<<"Have run "<<ne<<" events. "<<endl;
       tree->GetEntry(ne);

       nVzHistNoES->Fill(nVtx*pVtx);
       if(HLT_L1MinimumBiasHF1OR_v1==1) 
         nVzHistNoESWithHLT->Fill(nVtx*pVtx);
       vzHistNoES->Fill(vz);    
       proIDAllHist->Fill(processid);
       if(nVtx*pVtx==0)
         proIDnVtx0Hist->Fill(processid);
       if(nVtx*pVtx==0 && HLT_L1MinimumBiasHF1OR_v1==1)
         proIDnVtx0HLTHist->Fill(processid);
       if(nVtx*pVtx>0)
         proIDnVtxnHist->Fill(processid);
       if(nVtx*pVtx>0 && HLT_L1MinimumBiasHF1OR_v1==1)
         proIDnVtxnHLTHist->Fill(processid);
       if(pVtx&&pBeamScrape)
         proIDESHist->Fill(processid); //only ES
       if(HLT_L1MinimumBiasHF1OR_v1==0) continue;
         proIDHLTHist->Fill(processid); //only HLT
       if(!(pVtx&&pBeamScrape)) continue;
         nVzHist->Fill(nVtx);
         vzHist->Fill(vz);
         proIDHLTESHist->Fill(processid);
         if(nVtx==1)
           vzHistnVz1->Fill(vz);
         for(int ni=0;ni<nTrk;ni++){

           if(!(highPurity[ni]&&trkPtError[ni]/trkPt[ni]<0.3&&trkPt[ni]>0.4&&trkPt[ni]<120.8&&fabs(trkEta[ni])<2.4)) continue;

           if(fabs(trkDz1[ni]/trkDzError1[ni])<3&&fabs(trkDxy1[ni]/trkDxyError1[ni])<3){
             ptHist->Fill(trkPt[ni]);
             if(nVtx==1)
               nVz1PtHist->Fill(trkPt[ni]);             
           }


           float Et = (pfHcal[ni]+pfEcal[ni])/TMath::CosH(trkEta[ni]);
           if(!(trkPt[ni]<20 || (Et>0.2*trkPt[ni] && Et>trkPt[ni]-80))) continue; //Calo Matching

           if(fabs(trkDz1[ni]/trkDzError1[ni])<3&&fabs(trkDxy1[ni]/trkDxyError1[ni])<3){
             ptHistCalo->Fill(trkPt[ni]);
             if(nVtx==1)
               nVz1PtHistCalo->Fill(trkPt[ni]);             
             gPtVtxptHistCalo->Fill(trkPt[ni]); 
           }

           bool isCompatibleWithVertex = false;
           for(int v = 0; v<nVtx; v++){
             if(TMath::Abs(trkDxyOverDxyError[ni*nVtx+v])<3 && TMath::Abs(trkDzOverDzError[ni*nVtx+v])<3){
               isCompatibleWithVertex = true;
               break;
             }
           }          
           if(!isCompatibleWithVertex) continue;
           allVtxptHistCalo->Fill(trkPt[ni]);

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
  ptHistCalo->Write();
  nVz1PtHistCalo->Write();
  gPtVtxptHistCalo->Write();
  allVtxptHistCalo->Write();
  proIDnVtx0Hist->Write();
  proIDnVtxnHist->Write();
  proIDAllHist->Write();
  proIDESHist->Write();
  nVzHistNoESWithHLT->Write();
  proIDnVtx0HLTHist->Write();
  proIDnVtxnHLTHist->Write();
  proIDHLTHist->Write();
  proIDHLTESHist->Write();
  outFiles->Close();

  delete vzHist;
  delete ptHist;
  delete nVzHistNoES;
  delete nVzHist;
  delete nVz1PtHist;
  delete vzHistNoES;
  delete vzHistnVz1;
  delete ptHistCalo;
  delete nVz1PtHistCalo;
  delete gPtVtxptHistCalo;
  delete allVtxptHistCalo;
  delete proIDnVtx0Hist;
  delete proIDnVtxnHist;
  delete proIDAllHist;
  delete proIDESHist;
  delete nVzHistNoESWithHLT;
  delete proIDnVtx0HLTHist;
  delete proIDnVtxnHLTHist;
  delete proIDHLTHist;
  delete proIDHLTESHist;

}

//void TrackSlurm::endJob(TString outFileName)
//{
//
//}

