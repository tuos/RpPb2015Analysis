from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.transferOutputs = True
config.General.transferLogs = True
config.JobType.allowUndistributedCMSSW = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'runForestAOD_pp_DATA_75X.py'
config.Data.inputDataset = '/MinimumBias1/Run2015E-PromptReco-v1/AOD'
config.Data.inputDBS = 'global'
config.Data.lumiMask = 'Cert_262081_262328_5TeV_PromptReco_Collisions15_25ns_JSON.txt'
config.Data.splitting = 'LumiBased'
config.Data.unitsPerJob = 10
config.Data.outLFNDirBase = '/store/user/tuos/RpPb2016/MiniForest/mb/v2'
config.Data.publication = False
config.Data.outputDatasetTag = 'pp_mb_miniforest_v2'

config.Site.storageSite = 'T2_US_Vanderbilt'

if __name__ == '__main__':
   from CRABAPI.RawCommand import crabCommand
   from CRABClient.ClientExceptions import ClientException
   from httplib import HTTPException

   config.General.workArea = 'pp_mb_miniforest_v2'

   def submit(config):
      try:
           crabCommand('submit', config = config)
      except HTTPException as hte:
           print "Failed submitting task: %s" % (hte.headers)
      except ClientException as cle:
          print "Failed submitting task: %s" % (cle)
   
   for num in range(0,22):

       print "Submitting MinimumBias %d " % (num+1)

       RequestName = 'pp_miniforest_v2_MB'+str(num+1)
       if num == 20:
           RequestName = 'pp_miniforest_v2_LowJets'
       if num == 21:
           RequestName = 'pp_miniforest_v2_Jet80'
       DataSetName = '/MinimumBias'+ str(num+1) +'/Run2015E-PromptReco-v1/AOD'
       if num == 20:
           DataSetName = '/HighPtLowerJets/Run2015E-PromptReco-v1/AOD'
       if num == 21:
           DataSetName = '/HighPtJet80/Run2015E-PromptReco-v1/AOD'
       config.General.requestName = RequestName
       config.Data.inputDataset = DataSetName
       submit(config)

# python crab3_multicrab_cfg.py to execute 
# ./multicrab -c status -w crab_projects/ to check status 
