// -*- C++ -*-
//
// Package:    ppAna/RawSpectraAna
// Class:      RawSpectraAna
// 
/**\class RawSpectraAna RawSpectraAna.cc ppAna/RawSpectraAna/plugins/RawSpectraAna.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Shengquan Tuo
//         Created:  Wed, 02 Dec 2015 20:24:07 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <TH1D.h>
#include <TH2D.h>
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/HeavyIonEvent/interface/Centrality.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"

using namespace std;
using namespace edm;
using namespace reco;

const int nPtBin=36;
double ptBins[nPtBin+1]={0,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.4,1.6,1.8,2.0,2.2,2.4,3.2,4.0,4.8,5.6,6.4,7.2,9.6,12.0,14.4,19.2,24.0,28.8,35.2,41.6,48.0,60.8,73.6,86.4,103.6,120.8,150};

//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class RawSpectraAna : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit RawSpectraAna(const edm::ParameterSet&);
      ~RawSpectraAna();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      // ----------member data ---------------------------
edm::Service<TFileService> fs;
edm::EDGetTokenT<TrackCollection> srcTracks_;
edm::EDGetTokenT<VertexCollection> srcVertex_;
bool useQuality_;
reco::TrackBase::TrackQuality trackQuality_;
  double trackPtMinCut_;
  double trackPtMaxCut_;
  double trackEtaMinCut_;
  double trackEtaMaxCut_;

   TH1D* vxHist;
   TH1D* vyHist;
   TH1D* vzHist;
   TH1D* hiGeneralTracksHist;
   TH1D* ptHist;
   TH1D* etaHist;
   TH1D* phiHist;


};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
RawSpectraAna::RawSpectraAna(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
   usesResource("TFileService");
edm::Service<TFileService> fs;
srcTracks_ = consumes<TrackCollection>(iConfig.getParameter<edm::InputTag>("srcTracks"));
srcVertex_ = consumes<VertexCollection>(iConfig.getParameter<edm::InputTag>("srcVertex"));
useQuality_ = iConfig.getParameter<bool>("UseQuality");
trackQuality_ = TrackBase::qualityByName(iConfig.getParameter<std::string>("TrackQuality"));
trackPtMinCut_ = iConfig.getParameter<double>("trackPtMinCut");
trackPtMaxCut_ = iConfig.getParameter<double>("trackPtMaxCut");
trackEtaMinCut_ = iConfig.getParameter<double>("trackEtaMinCut");
trackEtaMaxCut_ = iConfig.getParameter<double>("trackEtaMaxCut");

TH1::SetDefaultSumw2();
vxHist = fs->make<TH1D>("vxhist","offlinePrimaryVertices Vx Distribution", 100, -0.5, 0.5);
vyHist = fs->make<TH1D>("vyhist","offlinePrimaryVertices Vy Distribution", 100, -0.5, 0.5);
vzHist = fs->make<TH1D>("vzhist","offlinePrimaryVertices Vz Distribution", 120, -30., 30.);
hiGeneralTracksHist = fs->make<TH1D>("higeneraltrackshist","generalTracks Distribution", 100, 0., 300.);
//ptHist = fs->make<TH1D>("pthist","generalTracks pT Distribution", 320, 0., 32.);
ptHist = fs->make<TH1D>("pthist","generalTracks pT Distribution", nPtBin, ptBins);
etaHist = fs->make<TH1D>("etahist","generalTracks eta Distribution", 120, -3.0, 3.0);
phiHist = fs->make<TH1D>("phihist","generalTracks phi Distribution", 80, -4.0, 4.0);


}


RawSpectraAna::~RawSpectraAna()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
RawSpectraAna::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;
   using namespace std;
   using namespace reco;

     double vx=-999.;
     double vy=-999.;
     double vz=-999.;
     double vxError=-999.;
     double vyError=-999.;
     double vzError=-999.;
     math::XYZVector vtxPos(0,0,0);

     edm::Handle<VertexCollection> recoVertices;
     iEvent.getByToken(srcVertex_,recoVertices);
     unsigned int daughter = 0;
     int greatestvtx = 0;

     for (unsigned int i = 0 ; i< recoVertices->size(); ++i){
      daughter = (*recoVertices)[i].tracksSize();
      if( daughter > (*recoVertices)[greatestvtx].tracksSize()) greatestvtx = i;
     }

     if(recoVertices->size()>0){
      vx = (*recoVertices)[greatestvtx].position().x();
      vy = (*recoVertices)[greatestvtx].position().y();
      vz = (*recoVertices)[greatestvtx].position().z();
      vxError = (*recoVertices)[greatestvtx].xError();
      vyError = (*recoVertices)[greatestvtx].yError();
      vzError = (*recoVertices)[greatestvtx].zError();
     }

     vtxPos = math::XYZVector(vx,vy,vz);
     vxHist->Fill(vx);
     vyHist->Fill(vy);
     vzHist->Fill(vz);

     edm::Handle<TrackCollection> tracks;
     iEvent.getByToken(srcTracks_,tracks);
     int nTracks = 0;

     for(unsigned int i = 0 ; i < tracks->size(); ++i){
       const Track& track = (*tracks)[i];
       if(useQuality_ && !track.quality(trackQuality_)) continue;

       math::XYZPoint v1(vx,vy, vz);
       double dz= track.dz(v1);
       double dzsigma2 = track.dzError()*track.dzError()+vzError*vzError;
       double dxy= track.dxy(v1);
       double dxysigma2 = track.dxyError()*track.dxyError()+vxError*vyError;

       const double pterrcut = 0.1;
       const double dzrelcut = 3.0;
       const double dxyrelcut = 3.0;

       if( track.quality(trackQuality_) &&
       track.pt()>trackPtMinCut_ && track.pt()<trackPtMaxCut_ && 
       track.eta()>trackEtaMinCut_ && track.eta()<trackEtaMaxCut_ &&
       track.ptError()/track.pt() < pterrcut &&
       dz*dz < dzrelcut*dzrelcut * dzsigma2 &&
       dxy*dxy < dxyrelcut*dxyrelcut * dxysigma2 ){
         ptHist->Fill(track.pt());
         etaHist->Fill(track.eta());
         phiHist->Fill(track.phi());
         nTracks++;
       }
     }

     hiGeneralTracksHist->Fill(nTracks);



#ifdef THIS_IS_AN_EVENT_EXAMPLE
   Handle<ExampleData> pIn;
   iEvent.getByLabel("example",pIn);
#endif
   
#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
   ESHandle<SetupData> pSetup;
   iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
RawSpectraAna::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
RawSpectraAna::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
RawSpectraAna::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(RawSpectraAna);
