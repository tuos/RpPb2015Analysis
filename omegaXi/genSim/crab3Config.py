from CRABClient.UserUtilities import config, getUsernameFromSiteDB
config = config()

config.General.requestName = 'multiStrangePYTHIA_step1_v8'
config.General.workArea = 'crab_projects_500kEvts_v8'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'PrivateMC'
config.JobType.psetName = 'Pythia8_OmegaXi_pp_TuneCUETP8M1_5020GeV_cff_GEN_SIM.py'

config.Data.outputPrimaryDataset = 'MinBias'
config.Data.splitting = 'EventBased'
config.Data.unitsPerJob = 500000
NJOBS = 20  # This is not a configuration parameter, but an auxiliary variable that we use in the next line.
config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
config.Data.outLFNDirBase = '/store/user/tuos/RpPb2016/multiStrange/genSim/v8'
config.Data.publication = True
config.Data.outputDatasetTag = 'multiStrangeFilteredPYTHIA_GENSIM_757p1_v8'

config.Site.storageSite = 'T2_US_Vanderbilt'


#crab submit -c crab3Config.py
#crab status -d crab_projects/xxxx
