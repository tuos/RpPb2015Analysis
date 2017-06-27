import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )
#process.MessageLogger.cerr.FwkReport.reportEvery = 10

process.source = cms.Source("PoolSource",
                            duplicateCheckMode = cms.untracked.string("noDuplicateCheck"),
                fileNames = cms.untracked.vstring(
'/store/hidata/PARun2016B/PAMinimumBias1/AOD/PromptReco-v1/000/285/383/00000/109ADEA7-4CAE-E611-9E2B-02163E0121C2.root',
'/store/hidata/PARun2016B/PAMinimumBias1/AOD/PromptReco-v1/000/285/383/00000/1211D62B-53AE-E611-9DD1-FA163E314C09.root',
'/store/hidata/PARun2016B/PAMinimumBias1/AOD/PromptReco-v1/000/285/383/00000/1459ABC3-55AE-E611-B2C9-02163E011924.root',
'/store/hidata/PARun2016B/PAMinimumBias1/AOD/PromptReco-v1/000/285/383/00000/14EFE8B3-50AE-E611-9B6D-02163E0142EB.root',
'/store/hidata/PARun2016B/PAMinimumBias1/AOD/PromptReco-v1/000/285/383/00000/16673E04-40AE-E611-91EA-FA163E718A7F.root',
'/store/hidata/PARun2016B/PAMinimumBias1/AOD/PromptReco-v1/000/285/383/00000/167A98E1-4FAE-E611-8396-FA163EBF8C40.root'

),
)

process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
from Configuration.AlCa.GlobalTag import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag, '80X_dataRun2_Prompt_v15', '')
process.GlobalTag = GlobalTag(process.GlobalTag, '80X_dataRun2_v19', '')

#Triggers:
process.load("HLTrigger.HLTfilters.hltHighLevel_cfi")
process.hltTriggerSinglePixelTrackPPb = process.hltHighLevel.clone()
process.hltTriggerSinglePixelTrackPPb.HLTPaths = ["HLT_PAL1MinimumBiasHF_OR_SinglePixelTrack_part1_v*"]

process.TFileService = cms.Service("TFileService",
                                  fileName=cms.string("strange_data2016_pPb.root"))

#Event Selections:
process.load('HeavyIonsAnalysis.Configuration.collisionEventSelection_cff')
#PAprimaryVertexFilter
process.PAprimaryVertexFilter = cms.EDFilter("VertexSelector",
    src = cms.InputTag("offlinePrimaryVertices"),
    cut = cms.string("!isFake && abs(z) <= 25 && position.Rho <= 2 && tracksSize >= 2"),
    filter = cms.bool(True), # otherwise it won't filter the events
)
#BeamScrapingFilter
process.NoScraping = cms.EDFilter("FilterOutScraping",
 applyfilter = cms.untracked.bool(True),
 debugOn = cms.untracked.bool(False),
 numtrack = cms.untracked.uint32(10),
 thresh = cms.untracked.double(0.25)
) 
#phfCoincFilter1
process.load("HeavyIonsAnalysis.Configuration.hfCoincFilter_cff")
# 5 TeV pileup cuts with 5_3_20? or 8 TeV cuts with 8_0_X
process.load("HeavyIonsAnalysis.VertexAnalysis.pileUpFilter_cff")
process.load("HeavyIonsAnalysis.VertexAnalysis.PAPileUpVertexFilter_cff")
#all the selections
process.eventSelections = cms.Sequence(
        process.PAprimaryVertexFilter
        + process.NoScraping
        + process.hfCoincFilter #phfCoincFilter1
#        + process.process.pileUpFilter_pPb8TeV_Gplus
        + process.pileupVertexFilterCutGplus
)

process.demo = cms.EDAnalyzer('Test2016pPbAnalysis',
   srcTracks = cms.InputTag("generalTracks"),
   srcVertex= cms.InputTag("offlinePrimaryVertices"),
   srcTower= cms.InputTag("towerMaker"),
   UseQuality = cms.bool(True),
   TrackQuality = cms.string('highPurity')
)

process.p = cms.Path(process.hltTriggerSinglePixelTrackPPb * process.eventSelections * process.demo)

