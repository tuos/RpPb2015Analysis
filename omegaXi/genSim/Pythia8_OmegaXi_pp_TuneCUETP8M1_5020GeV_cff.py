import FWCore.ParameterSet.Config as cms

from Configuration.Generator.Pythia8CommonSettings_cfi import *
from Configuration.Generator.Pythia8CUEP8M1Settings_cfi import *



generator = cms.EDFilter("Pythia8GeneratorFilter",
    maxEventsToPrint = cms.untracked.int32(0),
    filterEfficiency = cms.untracked.double(1.0),
    pythiaHepMCVerbosity = cms.untracked.bool(False),
    pythiaPylistVerbosity = cms.untracked.int32(0),
    comEnergy = cms.double(5020.0),
                         PythiaParameters = cms.PSet(
        pythia8CommonSettingsBlock,
        pythia8CUEP8M1SettingsBlock,
        processParameters = cms.vstring(
            'SoftQCD:nonDiffractive = on',
            'SoftQCD:singleDiffractive = on',
            'SoftQCD:doubleDiffractive = on'),
        parameterSets = cms.vstring('pythia8CommonSettings',
                                    'pythia8CUEP8M1Settings',
                                    'processParameters',
                                    )
    )
)

omegaxifilter = cms.EDFilter("MCSingleParticleFilter",
                       Status     = cms.untracked.vint32(2, 2, 2, 2),
                       MaxEta     = cms.untracked.vdouble(2.5, 2.5, 2.5, 2.5),
                       MinEta     = cms.untracked.vdouble(-2.5, -2.5, -2.5, -2.5),
                       MinPt      = cms.untracked.vdouble(2.4, 2.4, 2.4, 2.4),
                       ParticleID = cms.untracked.vint32(3334, -3334, 3312, -3312)
                       )

ProductionFilterSequence = cms.Sequence(generator*omegaxifilter)
