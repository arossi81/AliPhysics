/**************************************************************************
 * Copyright(c) 1998-1999, ALICE Experiment at CERN, All rights reserved. *
 *                                                                        *
 * Author: The ALICE Off-line Project.                                    *
 * Contributors are mentioned in the code where appropriate.              *
 *                                                                        *
 * Permission to use, copy, modify and distribute this software and its   *
 * documentation strictly for non-commercial purposes is hereby granted   *
 * without fee, provided that the above copyright notice appears in all   *
 * copies and that both the copyright notice and this permission notice   *
 * appear in the supporting documentation. The authors make no claims     *
 * about the suitability of this software for any purpose. It is          *
 * provided "as is" without express or implied warranty.                  *
 **************************************************************************/
//
// AliCEPBase
// for
// AliAnalysisTaskCEP
//
//
//  Author:
//  Xianguo Lu <lu@physi.uni-heidelberg.de>
//  continued by
//  Felix Reidt <Felix.Reidt@cern.ch>
//  rewritten by
//  Paul Buehler <paul.buehler@oeaw.ac.at>

#ifndef AliCEPBase_H
#define AliCEPBase_H

#include "TH1I.h"

class AliCEPBase : public TObject {

  public:

  // define some constants
  static const Int_t kdumval = -999;

	enum {

		// collission types
		kBinEventUnknown = 0,
		kBinEventI,             // Beam-Beam Interaction
		kBinEventA,             // Beam from A-side
		kBinEventC,             // Beam from C-side
		kBinEventAC,            // Beam from one side (there is no separation in 2011)
		kBinEventE,             // no beam (empty event)

		// track status bits
		kTTBaseLine        = 0,
    kTTTOFBunchCrossing= (1<< 0), // TOFBunchCrossing==0
    kTTTPCScluster     = (1<< 1), // number of TPC shared clusters <= fTPCnclsS(3)
    kTTDCA             = (1<< 2), // DCA to vertex is < 500
    kTTV0              = (1<< 3), // is a daughter of a V0
    kTTITSpure         = (1<< 4), // is an ITS pure track
    kTTZv              = (1<< 5), // |Zv-VtxZ| <= 6
    kTTeta             = (1<< 6), // -0.9<eta<0.9
    kTTAccITSTPC       = (1<< 7), // accepted by ITSTPC criteria
    kTTAccITSSA        = (1<< 8), // accepted by ITSSA  criteria
    kTTFiredChips      = (1<< 9), // passed FiredChips test

    // type of vertex
    kVtxUnknown = 0,
    kVtxSPD,                // from ITS
    kVtxTracks,             // from tracks
    kVtxErrRes,             // z-resolution of SPD vertex is out-of-bounds
    kVtxErrDif,             // difference in z between SPD and track vertex is
                            //  out-of-bounds
    kVtxErrZ,               // z-position of vertex is  out-of-bounds
    kVtxAOD,                // On AOD only primary vertex is stored

		// StatsFlow histogram entries
		// names for the bins are specified in AliCEPUtils.cxx
		kBinTotalInput = 0,
		kBinGoodInput,
		kBinMCEvent,
		kBinPhysEvent,
		kBinEventCut,
		kBinPhysel,
		kBinPileup,
		kBinClusterCut,
		kBinDGTrigger,
		kBinSharedCluster,
    kBinVtx,
		kBinMBOR,
		kBinMBAND,
		kBinnoV0,
		kBinnoFMD,
		kBinnoAD,
		kBinDG,
		kBinNDG,
		kBinSaved,
		kBinLastValue,

		// definition of bits in AliAnalysisTaskCEP::fCurrentEventCondition
		kBitBaseLine       = (1<< 0),
    kBitEventCut       = (1<< 1),
    kBitPhyssel        = (1<< 2),
    kBitPileup         = (1<< 3),
    kBitClusterCut     = (1<< 4),
		kBitDGTrigger      = (1<< 5),
    kBitVtx            = (1<< 6),
		kBitMBOR           = (1<< 7),
    kBitMBAND          = (1<< 8),
		kBitSPDA           = (1<< 9),
		kBitSPDC           = (1<<10),
		kBitTPCA           = (1<<11),
		kBitTPCC           = (1<<12),
    kBitV0A            = (1<<13),
		kBitV0C            = (1<<14),
		kBitFMDA           = (1<<15),
		kBitFMDC           = (1<<16),
		kBitADA            = (1<<17),
		kBitADC            = (1<<18), 
		kBitZDCA           = (1<<19), 
		kBitZDCC           = (1<<20), 
		kBitZDNA           = (1<<21),
		kBitZDNC           = (1<<22),
    kBitSClusterCut    = (1<<23),

    // MC process types
    kProctypeUnknown = 0,
    kProctypeND,
    kProctypeSD,
    kProctypeDD,
    kProctypeCD,

		// analysis task status bits
		// do not change the order in order to be backward compatible!
    
		kBitConfigurationSet      = (1<< 0), // if not set everything is active
    kBitisRun1                = (1<< 1), // is it run1
    kBitSaveAllEvents         = (1<< 2), // save all events
    kBitisMC                  = (1<< 3), // is Monte Carlo
    kBitQArnumStudy           = (1<< 4), // QA as function of rnum
    kBitSPDPileupStudy        = (1<< 5), // SPD pileup study
    kBitnClunTraStudy         = (1<< 6), // cluster vs tracklet study
    kBitVtxStudy              = (1<< 7), // Vtx study
    kBitTrackCutStudy         = (1<< 8), // track cut study
    kBitBBFlagStudy           = (1<< 9), // BBFlag study
    kBitV0Study               = (1<<10), // V0 study
		kBitConfigurationVersion  = (1<<11)  // always set, last bit
	
  };

	ClassDef(AliCEPBase, 1);

};

#endif
