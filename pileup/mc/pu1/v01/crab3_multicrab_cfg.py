from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.transferOutputs = True
config.General.transferLogs = True
config.JobType.allowUndistributedCMSSW = True

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'runForestAOD_pp_MC_75X.py'
config.Data.inputDataset = '/MinBias_TuneCUETP8M1_5p02TeV-pythia8/twang-MinBias_TuneCUETP8M1_5p02TeV_pythia8_pp502Fall15_MCRUN2_71_V1_v1_step2_CMSSW_7_4_15_20151105-792724e95bc6b3667ad91f57fcdd4eac/USER'
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 2
config.Data.outLFNDirBase = '/store/user/tuos/RpPb2016/MiniForest/mc/pu1/v01'
config.Data.publication = False
config.Data.outputDatasetTag = 'pp_mcpu_miniforest_v01'

config.Site.storageSite = 'T2_US_Vanderbilt'

if __name__ == '__main__':
   from CRABAPI.RawCommand import crabCommand
   from CRABClient.ClientExceptions import ClientException
   from httplib import HTTPException

   config.General.workArea = 'pp_mcpu_miniforest_v01'

   def submit(config):
      try:
           crabCommand('submit', config = config)
      except HTTPException as hte:
           print "Failed submitting task: %s" % (hte.headers)
      except ClientException as cle:
          print "Failed submitting task: %s" % (cle)
   
   for num in range(0,3):

       print "Submitting pileup %d " % (num+1)

       RequestName = 'pp_mcpu_miniforest_v01_PU'+str(num+1)
       if num == 0:
           DataSetName = '/MinBias_TuneCUETP8M1_5p02TeV-pythia8/twang-MinBias_TuneCUETP8M1_5p02TeV_pythia8_pp502Fall15_MCRUN2_71_V1_v1_step2_CMSSW_7_4_15_20151105-792724e95bc6b3667ad91f57fcdd4eac/USER'
       if num == 1:
           DataSetName = '/Neutrinos5Mfor5TeVpp/gsfs-pp5TeV_Pileup_2_RECO_2016_01_24-24bc0f2c47ba7a24fbd3e8494fe06297/USER'
       if num == 2:
           DataSetName = '/Neutrinos5Mfor5TeVpp/gsfs-pp5TeV_Pileup_3_RECO_2016_01_24-24bc0f2c47ba7a24fbd3e8494fe06297/USER'
       config.General.requestName = RequestName
       config.Data.inputDataset = DataSetName
       submit(config)

# python crab3_multicrab_cfg.py to execute 
# ./multicrab -c status -w crab_projects/ to check status 
