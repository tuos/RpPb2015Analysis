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
TH1D *nVzHistSD = new TH1D("nvzhistsd","generalTracks pT Distribution", 10, 0,10);
TH1D *nVzHistDD = new TH1D("nvzhistdd","generalTracks pT Distribution", 10, 0,10);
TH1D *nVzHistND = new TH1D("nvzhistnd","generalTracks pT Distribution", 10, 0,10);
TH1D *nVzHistNoES = new TH1D("nvzhistnoes","generalTracks pT Distribution", 10, 0,10);
TH1D *nVz1PtHist = new TH1D("nvz1pthist","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *vzHistNoES = new TH1D("vzhistnoes","generalTracks pT Distribution", 100, -25,25);
TH1D *vzHistnVz1 = new TH1D("vzhistnvz1","generalTracks pT Distribution", 100, -25,25);

TH1D *ptHistCalo = new TH1D("pthistcalo","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *nVz1PtHistCalo = new TH1D("nvz1pthistcalo","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *gPtVtxptHistCalo = new TH1D("gptvtxpthistcalo","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *allVtxptHistCalo = new TH1D("allvtxpthistcalo","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *allVtxptHistCaloSD = new TH1D("allvtxpthistcalosd","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *allVtxptHistCaloDD = new TH1D("allvtxpthistcalodd","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *allVtxptHistCaloND = new TH1D("allvtxpthistcalond","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *allVtxptHistCaloEta1 = new TH1D("allvtxpthistcaloeta1","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *allVtxptHistCaloSDEta1 = new TH1D("allvtxpthistcalosdeta1","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *allVtxptHistCaloDDEta1 = new TH1D("allvtxpthistcaloddeta1","generalTracks pT Distribution", nPtBin, ptBins);
TH1D *allVtxptHistCaloNDEta1 = new TH1D("allvtxpthistcalondeta1","generalTracks pT Distribution", nPtBin, ptBins);

TH1D *proIDnVtx0Hist = new TH1D("proidnvtx0hist","process ID Distribution", 10, 100,110);
TH1D *proIDnVtxnHist = new TH1D("proidnvtxnhist","process ID Distribution", 10, 100,110);
TH1D *proIDAllHist = new TH1D("proidallhist","process ID Distribution", 10, 100,110);
TH1D *proIDESHist = new TH1D("proideshist","process ID Distribution", 10, 100,110);

TH1D *nVzHistNoESWithHLT = new TH1D("nvzhistnoeswithhlt","generalTracks pT Distribution", 10, 0,10);
TH1D *proIDnVtx0HLTHist = new TH1D("proidnvtx0hlthist","process ID Distribution", 10, 100,110);
TH1D *proIDnVtxnHLTHist = new TH1D("proidnvtxnhlthist","process ID Distribution", 10, 100,110);
TH1D *proIDHLTHist = new TH1D("proidhlthist","process ID Distribution", 10, 100,110);
TH1D *proIDHLTESHist = new TH1D("proidhlteshist","process ID Distribution", 10, 100,110);

TH1D *nMultHist = new TH1D("nmulthist","Multiplicity Distribution", 200, 0,200);
TH1D *nMultHistSD = new TH1D("nmulthistsd","Multiplicity Distribution", 200, 0,200);
TH1D *nMultHistDD = new TH1D("nmulthistdd","Multiplicity Distribution", 200, 0,200);
TH1D *nMultHistND = new TH1D("nmulthistnd","Multiplicity Distribution", 200, 0,200);
TH1D *nMultHistEta24 = new TH1D("nmulthisteta24","Multiplicity Distribution", 200, 0,200);
TH1D *nMultHistEta10 = new TH1D("nmulthisteta10","Multiplicity Distribution", 200, 0,200);
TH1D *nMultHistEta24SD = new TH1D("nmulthisteta24sd","Multiplicity Distribution", 200, 0,200);
TH1D *nMultHistEta10SD = new TH1D("nmulthisteta10sd","Multiplicity Distribution", 200, 0,200);
TH1D *nMultHistEta24DD = new TH1D("nmulthisteta24dd","Multiplicity Distribution", 200, 0,200);
TH1D *nMultHistEta10DD = new TH1D("nmulthisteta10dd","Multiplicity Distribution", 200, 0,200);
TH1D *nMultHistEta24ND = new TH1D("nmulthisteta24nd","Multiplicity Distribution", 200, 0,200);
TH1D *nMultHistEta10ND = new TH1D("nmulthisteta10nd","Multiplicity Distribution", 200, 0,200);
int nmult24, nmult10;
int nmult24sd, nmult10sd;
int nmult24dd, nmult10dd;
int nmult24nd, nmult10nd;

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

       nmult24=0; nmult10=0;
       nmult24sd=0; nmult10sd=0;
       nmult24dd=0; nmult10dd=0;
       nmult24nd=0; nmult10nd=0;

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
         if(processid==103 || processid==104)
           nVzHistSD->Fill(nVtx);
         if(processid==105)
           nVzHistDD->Fill(nVtx);
         if(processid==101)
           nVzHistND->Fill(nVtx);      

         if(nVtx==1)
           vzHistnVz1->Fill(vz);

         nMultHist->Fill(nTrk);
         if(processid==103 || processid==104)
           nMultHistSD->Fill(nTrk);
         if(processid==105)
           nMultHistDD->Fill(nTrk);
         if(processid==101)
           nMultHistND->Fill(nTrk);

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
           if(fabs(trkEta[ni])<1.0) 
             allVtxptHistCaloEta1->Fill(trkPt[ni]);
           nmult24++;
           if(fabs(trkEta[ni])<1.0)
             nmult10++;

           if(processid==103 || processid==104){
             allVtxptHistCaloSD->Fill(trkPt[ni]);
             if(fabs(trkEta[ni])<1.0)
               allVtxptHistCaloSDEta1->Fill(trkPt[ni]);
             nmult24sd++;
             if(fabs(trkEta[ni])<1.0)
               nmult10sd++;
           }
           if(processid==105){
             allVtxptHistCaloDD->Fill(trkPt[ni]);
             if(fabs(trkEta[ni])<1.0)
               allVtxptHistCaloDDEta1->Fill(trkPt[ni]);
             nmult24dd++;
             if(fabs(trkEta[ni])<1.0)
               nmult10dd++;
           }
           if(processid==101){
             allVtxptHistCaloND->Fill(trkPt[ni]);
             if(fabs(trkEta[ni])<1.0)
               allVtxptHistCaloNDEta1->Fill(trkPt[ni]);
             nmult24nd++;
             if(fabs(trkEta[ni])<1.0)
               nmult10nd++;
           }

         }//end of ntrk
         nMultHistEta24->Fill(nmult24);
         nMultHistEta10->Fill(nmult10);
         nMultHistEta24SD->Fill(nmult24sd);
         nMultHistEta10SD->Fill(nmult10sd);
         nMultHistEta24DD->Fill(nmult24dd);
         nMultHistEta10DD->Fill(nmult10dd);
         nMultHistEta24ND->Fill(nmult24nd);
         nMultHistEta10ND->Fill(nmult10nd);
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
  nVzHistSD->Write();
  nVzHistDD->Write();
  nVzHistND->Write();
  nVz1PtHist->Write();
  vzHistNoES->Write();
  vzHistnVz1->Write();
  ptHistCalo->Write();
  nVz1PtHistCalo->Write();
  gPtVtxptHistCalo->Write();
  allVtxptHistCalo->Write();
  allVtxptHistCaloSD->Write();
  allVtxptHistCaloDD->Write();
  allVtxptHistCaloND->Write();
  allVtxptHistCaloEta1->Write();
  allVtxptHistCaloSDEta1->Write();
  allVtxptHistCaloDDEta1->Write();
  allVtxptHistCaloNDEta1->Write();
  proIDnVtx0Hist->Write();
  proIDnVtxnHist->Write();
  proIDAllHist->Write();
  proIDESHist->Write();
  nVzHistNoESWithHLT->Write();
  proIDnVtx0HLTHist->Write();
  proIDnVtxnHLTHist->Write();
  proIDHLTHist->Write();
  proIDHLTESHist->Write();
  nMultHist->Write();
  nMultHistSD->Write();
  nMultHistDD->Write();
  nMultHistND->Write();
  nMultHistEta24->Write();
  nMultHistEta10->Write();
  nMultHistEta24SD->Write();
  nMultHistEta10SD->Write();
  nMultHistEta24DD->Write();
  nMultHistEta10DD->Write();
  nMultHistEta24ND->Write();
  nMultHistEta10ND->Write();
  outFiles->Close();

  delete vzHist;
  delete ptHist;
  delete nVzHistNoES;
  delete nVzHist;
  delete nVzHistSD;
  delete nVzHistDD;
  delete nVzHistND;
  delete nVz1PtHist;
  delete vzHistNoES;
  delete vzHistnVz1;
  delete ptHistCalo;
  delete nVz1PtHistCalo;
  delete gPtVtxptHistCalo;
  delete allVtxptHistCalo;
  delete allVtxptHistCaloSD;
  delete allVtxptHistCaloDD;
  delete allVtxptHistCaloND;
  delete allVtxptHistCaloEta1;
  delete allVtxptHistCaloSDEta1;
  delete allVtxptHistCaloDDEta1;
  delete allVtxptHistCaloNDEta1;
  delete proIDnVtx0Hist;
  delete proIDnVtxnHist;
  delete proIDAllHist;
  delete proIDESHist;
  delete nVzHistNoESWithHLT;
  delete proIDnVtx0HLTHist;
  delete proIDnVtxnHLTHist;
  delete proIDHLTHist;
  delete proIDHLTESHist;
  delete nMultHist;
  delete nMultHistSD;
  delete nMultHistDD;
  delete nMultHistND;
  delete nMultHistEta24;
  delete nMultHistEta10;
  delete nMultHistEta24SD;
  delete nMultHistEta10SD;
  delete nMultHistEta24DD;
  delete nMultHistEta10DD;
  delete nMultHistEta24ND;
  delete nMultHistEta10ND;

}

//void TrackSlurm::endJob(TString outFileName)
//{
//
//}

