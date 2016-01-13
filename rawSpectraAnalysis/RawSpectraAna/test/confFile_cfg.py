import FWCore.ParameterSet.Config as cms

process = cms.Process("Demo")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )
#process.MessageLogger.cerr.FwkReport.reportEvery = 10

#process.load('HeavyIonsAnalysis.Configuration.collisionEventSelection_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
#process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:run1_data', '')
process.GlobalTag = GlobalTag(process.GlobalTag, '75X_dataRun2_Prompt_ppAt5TeV_v0', '')

process.load("HLTrigger.HLTfilters.hltHighLevel_cfi")
process.hltL1MinimumBiasHF1AND = process.hltHighLevel.clone()
process.hltL1MinimumBiasHF1AND.HLTPaths = ["HLT_L1MinimumBiasHF1AND_v1"]


process.source = cms.Source("PoolSource",
#                            duplicateCheckMode = cms.untracked.string("noDuplicateCheck"),
                            fileNames = cms.untracked.vstring(
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/004E78B2-1396-E511-9F94-02163E01439C.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/0050E7AB-1296-E511-B2B8-02163E0134DB.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/005D56AC-1396-E511-9F41-02163E0144A3.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/08C017CB-1396-E511-97F6-02163E011E84.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/0E5F7FA1-1296-E511-89D2-02163E011F70.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/0EA78EAD-1396-E511-A160-02163E012306.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/125864A0-1396-E511-9EA9-02163E012580.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/1A4797A8-1396-E511-9CBE-02163E0134E0.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/1E9E76A0-1396-E511-8156-02163E0145C5.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/1EC534ED-1396-E511-AC40-02163E014434.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/223CBDAD-1396-E511-9DAF-02163E01439C.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/2265A399-1396-E511-BCA9-02163E013546.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/28DE93A7-1396-E511-94B3-02163E014558.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/2A4FFDC0-1396-E511-9E09-02163E013522.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/2A702BB8-1396-E511-A8C0-02163E0144EE.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/2A86209E-1396-E511-BF89-02163E011DDA.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/386FFBA3-1396-E511-AD54-02163E012261.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/3A54CEC1-1396-E511-8DA2-02163E01430A.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/3CD91AAD-1396-E511-999A-02163E011D9F.root',
'/store/data/Run2015E/MinimumBias1/AOD/PromptReco-v1/000/262/271/00000/408F8EA2-1396-E511-ABE6-02163E013505.root'

))

process.TFileService = cms.Service("TFileService",
                                  fileName=cms.string("histogram_test_MB_pp.root")
)

process.demo = cms.EDAnalyzer('RawSpectraAna',
   srcTracks = cms.InputTag("generalTracks"),
   #srcVertex= cms.InputTag("hiSelectedVertex"),
   srcVertex= cms.InputTag("offlinePrimaryVertices"),
   UseQuality = cms.bool(True),
   TrackQuality = cms.string('highPurity'),
   trackPtMinCut = cms.double(0.0),
   trackPtMaxCut = cms.double(150.0),
   trackEtaMinCut = cms.double(-1.0),
   trackEtaMaxCut = cms.double(1.0)
)


#process.p = cms.Path(process.hltL1MinimumBiasHF1AND * process.demo)
process.p = cms.Path(process.demo)


