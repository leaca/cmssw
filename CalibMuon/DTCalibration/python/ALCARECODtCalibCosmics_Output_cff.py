import FWCore.ParameterSet.Config as cms

# output block for alcastream
OutALCARECODtCalibCosmics_noDrop = cms.PSet(
    # put this if you have a filter
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('pathALCARECODtCalibCosmics')
    ),
    outputCommands = cms.untracked.vstring( 
        'keep *_dt4DSegments_*_*', 
        'keep *_dt4DSegmentsNoWire_*_*',
        'keep *_muonDTDigis_*_*', 
        'keep *_dttfDigis_*_*',
        'keep *_gtDigis_*_*',
        'keep *_TriggerResults_*_*',
        'keep recoTracks_cosmicMuons_*_*',
        'keep recoMuons_muons_*_*',
        #'keep booledmValueMap_muid*_*_*')
        'keep booledmValueMap_muidAllArbitrated_*_*',
        'keep booledmValueMap_muidGMStaChiCompatibility_*_*',
        'keep booledmValueMap_muidGMTkChiCompatibility_*_*',
        'keep booledmValueMap_muidGMTkKinkTight_*_*',
        'keep booledmValueMap_muidGlobalMuonPromptTight_*_*',
        'keep booledmValueMap_muidRPCMuLoose_*_*',
        'keep booledmValueMap_muidTM2DCompatibilityLoose_*_*',
        'keep booledmValueMap_muidTM2DCompatibilityTight_*_*',
        'keep booledmValueMap_muidTMLastStationAngLoose_*_*',
        'keep booledmValueMap_muidTMLastStationAngTight_*_*',
        'keep booledmValueMap_muidTMLastStationLoose_*_*',
        'keep booledmValueMap_muidTMLastStationOptimizedLowPtLoose_*_*',
        'keep booledmValueMap_muidTMLastStationOptimizedLowPtTight_*_*',
        'keep booledmValueMap_muidTMLastStationTight_*_*',
        'keep booledmValueMap_muidTMOneStationAngLoose_*_*',
        'keep booledmValueMap_muidTMOneStationAngTight_*_*',
        'keep booledmValueMap_muidTMOneStationLoose_*_*',
        'keep booledmValueMap_muidTMOneStationTight_*_*',
        'keep booledmValueMap_muidTrackerMuonArbitrated_*_*')
)


import copy
OutALCARECODtCalibCosmics = copy.deepcopy(OutALCARECODtCalibCosmics_noDrop)
OutALCARECODtCalibCosmics.outputCommands.insert(0, "drop *")
