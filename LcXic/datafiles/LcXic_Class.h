//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Feb 19 18:36:08 2024 by ROOT version 6.24/08
// from TTree DecayTree/DecayTree
// found on file: XiccTuple.root
//////////////////////////////////////////////////////////

#ifndef LcXic_Class_h
#define LcXic_Class_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class LcXic_Class {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
   static constexpr Int_t kMaxC_ENDVERTEX_COV = 1;
   static constexpr Int_t kMaxC_OWNPV_COV = 1;
   static constexpr Int_t kMaxLc_ENDVERTEX_COV = 1;
   static constexpr Int_t kMaxLc_OWNPV_COV = 1;
   static constexpr Int_t kMaxLc_ORIVX_COV = 1;
   static constexpr Int_t kMaxXic_ENDVERTEX_COV = 1;
   static constexpr Int_t kMaxXic_OWNPV_COV = 1;
   static constexpr Int_t kMaxXic_ORIVX_COV = 1;

   // Declaration of leaf types
   Double_t        C_ETA;
   Double_t        C_LOKI_IPCHI2;
   Double_t        C_Y;
   Double_t        C_ENDVERTEX_X;
   Double_t        C_ENDVERTEX_Y;
   Double_t        C_ENDVERTEX_Z;
   Double_t        C_ENDVERTEX_XERR;
   Double_t        C_ENDVERTEX_YERR;
   Double_t        C_ENDVERTEX_ZERR;
   Double_t        C_ENDVERTEX_CHI2;
   Int_t           C_ENDVERTEX_NDOF;
   Float_t         C_ENDVERTEX_COV_[3][3];
   Double_t        C_OWNPV_X;
   Double_t        C_OWNPV_Y;
   Double_t        C_OWNPV_Z;
   Double_t        C_OWNPV_XERR;
   Double_t        C_OWNPV_YERR;
   Double_t        C_OWNPV_ZERR;
   Double_t        C_OWNPV_CHI2;
   Int_t           C_OWNPV_NDOF;
   Float_t         C_OWNPV_COV_[3][3];
   Double_t        C_IP_OWNPV;
   Double_t        C_IPCHI2_OWNPV;
   Double_t        C_FD_OWNPV;
   Double_t        C_FDCHI2_OWNPV;
   Double_t        C_DIRA_OWNPV;
   Double_t        C_P;
   Double_t        C_PT;
   Double_t        C_PE;
   Double_t        C_PX;
   Double_t        C_PY;
   Double_t        C_PZ;
   Double_t        C_MM;
   Double_t        C_MMERR;
   Double_t        C_M;
   Int_t           C_ID;
   Double_t        C_TAU;
   Double_t        C_TAUERR;
   Double_t        C_TAUCHI2;
   Double_t        C_DTF_CHI2NDOF;
   Double_t        C_DTF_CTAU;
   Double_t        C_DTF_CTAUERR;
   Double_t        C_DTF_CTAUS;
   Double_t        C_DTF_DM;
   Double_t        C_DTF_M;
   Double_t        C_DTF_PV_CTAU;
   Double_t        C_DTF_PV_CTAUERR;
   Double_t        C_LOKI_DIRA;
   Double_t        C_LOKI_FDCHI2;
   Double_t        C_LOKI_FDS;
   Double_t        C_LV01;
   Double_t        C_LV02;
   Double_t        C_Lc_DTF_CTAU;
   Double_t        C_Lc_DTF_CTAUERR;
   Double_t        C_Lc_DTF_CTAUS;
   Double_t        C_Xic_DTF_CTAU;
   Double_t        C_Xic_DTF_CTAUERR;
   Double_t        C_Xic_DTF_CTAUS;
   Int_t           C_FullFit_nPV;
   Float_t         C_FullFit_Lambda_cplus_M[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_Lambda_cplus_MERR[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_Lambda_cplus_P[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_Lambda_cplus_PERR[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_Lambda_cplus_ctau[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_Lambda_cplus_ctauErr[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_Lambda_cplus_decayLength[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_Lambda_cplus_decayLengthErr[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_M[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_MERR[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_P[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_PERR[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_PV_X[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_PV_Y[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_PV_Z[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_PV_key[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_Xi_cplus_M[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_Xi_cplus_MERR[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_Xi_cplus_P[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_Xi_cplus_PERR[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_Xi_cplus_ctau[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_Xi_cplus_ctauErr[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_Xi_cplus_decayLength[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_Xi_cplus_decayLengthErr[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_chi2[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_ctau[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_ctauErr[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_decayLength[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_decayLengthErr[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_nDOF[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_nIter[100];   //[C_FullFit_nPV]
   Float_t         C_FullFit_status[100];   //[C_FullFit_nPV]
   Int_t           C_MassFit_nPV;
   Float_t         C_MassFit_M[100];   //[C_MassFit_nPV]
   Float_t         C_MassFit_MERR[100];   //[C_MassFit_nPV]
   Float_t         C_MassFit_P[100];   //[C_MassFit_nPV]
   Float_t         C_MassFit_PERR[100];   //[C_MassFit_nPV]
   Float_t         C_MassFit_chi2[100];   //[C_MassFit_nPV]
   Float_t         C_MassFit_nDOF[100];   //[C_MassFit_nPV]
   Float_t         C_MassFit_nIter[100];   //[C_MassFit_nPV]
   Float_t         C_MassFit_status[100];   //[C_MassFit_nPV]
   Int_t           C_PVFit_nPV;
   Float_t         C_PVFit_Lambda_cplus_M[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_Lambda_cplus_MERR[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_Lambda_cplus_P[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_Lambda_cplus_PERR[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_Lambda_cplus_ctau[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_Lambda_cplus_ctauErr[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_Lambda_cplus_decayLength[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_Lambda_cplus_decayLengthErr[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_M[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_MERR[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_P[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_PERR[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_PV_X[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_PV_Y[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_PV_Z[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_PV_key[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_Xi_cplus_M[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_Xi_cplus_MERR[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_Xi_cplus_P[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_Xi_cplus_PERR[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_Xi_cplus_ctau[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_Xi_cplus_ctauErr[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_Xi_cplus_decayLength[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_Xi_cplus_decayLengthErr[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_chi2[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_ctau[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_ctauErr[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_decayLength[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_decayLengthErr[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_nDOF[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_nIter[100];   //[C_PVFit_nPV]
   Float_t         C_PVFit_status[100];   //[C_PVFit_nPV]
   Bool_t          C_L0Global_Dec;
   Bool_t          C_L0Global_TIS;
   Bool_t          C_L0Global_TOS;
   Bool_t          C_Hlt1Global_Dec;
   Bool_t          C_Hlt1Global_TIS;
   Bool_t          C_Hlt1Global_TOS;
   Bool_t          C_Hlt1Phys_Dec;
   Bool_t          C_Hlt1Phys_TIS;
   Bool_t          C_Hlt1Phys_TOS;
   Bool_t          C_L0ElectronDecision_Dec;
   Bool_t          C_L0ElectronDecision_TIS;
   Bool_t          C_L0ElectronDecision_TOS;
   Bool_t          C_L0PhotonDecision_Dec;
   Bool_t          C_L0PhotonDecision_TIS;
   Bool_t          C_L0PhotonDecision_TOS;
   Bool_t          C_L0HadronDecision_Dec;
   Bool_t          C_L0HadronDecision_TIS;
   Bool_t          C_L0HadronDecision_TOS;
   Bool_t          C_L0MuonDecision_Dec;
   Bool_t          C_L0MuonDecision_TIS;
   Bool_t          C_L0MuonDecision_TOS;
   Bool_t          C_L0MuonHighDecision_Dec;
   Bool_t          C_L0MuonHighDecision_TIS;
   Bool_t          C_L0MuonHighDecision_TOS;
   Bool_t          C_L0DiMuonDecision_Dec;
   Bool_t          C_L0DiMuonDecision_TIS;
   Bool_t          C_L0DiMuonDecision_TOS;
   Bool_t          C_Hlt1TrackAllL0Decision_Dec;
   Bool_t          C_Hlt1TrackAllL0Decision_TIS;
   Bool_t          C_Hlt1TrackAllL0Decision_TOS;
   Bool_t          C_Hlt1TrackMuonDecision_Dec;
   Bool_t          C_Hlt1TrackMuonDecision_TIS;
   Bool_t          C_Hlt1TrackMuonDecision_TOS;
   Bool_t          C_Hlt1TrackPhotonDecision_Dec;
   Bool_t          C_Hlt1TrackPhotonDecision_TIS;
   Bool_t          C_Hlt1TrackPhotonDecision_TOS;
   Bool_t          C_Hlt1TrackMVADecision_Dec;
   Bool_t          C_Hlt1TrackMVADecision_TIS;
   Bool_t          C_Hlt1TrackMVADecision_TOS;
   Bool_t          C_Hlt1TwoTrackMVADecision_Dec;
   Bool_t          C_Hlt1TwoTrackMVADecision_TIS;
   Bool_t          C_Hlt1TwoTrackMVADecision_TOS;
   Double_t        Lc_ETA;
   Double_t        Lc_LOKI_IPCHI2;
   Double_t        Lc_Y;
   Double_t        Lc_CosTheta;
   Double_t        Lc_ENDVERTEX_X;
   Double_t        Lc_ENDVERTEX_Y;
   Double_t        Lc_ENDVERTEX_Z;
   Double_t        Lc_ENDVERTEX_XERR;
   Double_t        Lc_ENDVERTEX_YERR;
   Double_t        Lc_ENDVERTEX_ZERR;
   Double_t        Lc_ENDVERTEX_CHI2;
   Int_t           Lc_ENDVERTEX_NDOF;
   Float_t         Lc_ENDVERTEX_COV_[3][3];
   Double_t        Lc_OWNPV_X;
   Double_t        Lc_OWNPV_Y;
   Double_t        Lc_OWNPV_Z;
   Double_t        Lc_OWNPV_XERR;
   Double_t        Lc_OWNPV_YERR;
   Double_t        Lc_OWNPV_ZERR;
   Double_t        Lc_OWNPV_CHI2;
   Int_t           Lc_OWNPV_NDOF;
   Float_t         Lc_OWNPV_COV_[3][3];
   Double_t        Lc_IP_OWNPV;
   Double_t        Lc_IPCHI2_OWNPV;
   Double_t        Lc_FD_OWNPV;
   Double_t        Lc_FDCHI2_OWNPV;
   Double_t        Lc_DIRA_OWNPV;
   Double_t        Lc_ORIVX_X;
   Double_t        Lc_ORIVX_Y;
   Double_t        Lc_ORIVX_Z;
   Double_t        Lc_ORIVX_XERR;
   Double_t        Lc_ORIVX_YERR;
   Double_t        Lc_ORIVX_ZERR;
   Double_t        Lc_ORIVX_CHI2;
   Int_t           Lc_ORIVX_NDOF;
   Float_t         Lc_ORIVX_COV_[3][3];
   Double_t        Lc_FD_ORIVX;
   Double_t        Lc_FDCHI2_ORIVX;
   Double_t        Lc_DIRA_ORIVX;
   Double_t        Lc_P;
   Double_t        Lc_PT;
   Double_t        Lc_PE;
   Double_t        Lc_PX;
   Double_t        Lc_PY;
   Double_t        Lc_PZ;
   Double_t        Lc_MM;
   Double_t        Lc_MMERR;
   Double_t        Lc_M;
   Int_t           Lc_ID;
   Double_t        Lc_TAU;
   Double_t        Lc_TAUERR;
   Double_t        Lc_TAUCHI2;
   Double_t        Lc_TMVA_BDT;
   Bool_t          Lc_L0Global_Dec;
   Bool_t          Lc_L0Global_TIS;
   Bool_t          Lc_L0Global_TOS;
   Bool_t          Lc_Hlt1Global_Dec;
   Bool_t          Lc_Hlt1Global_TIS;
   Bool_t          Lc_Hlt1Global_TOS;
   Bool_t          Lc_Hlt1Phys_Dec;
   Bool_t          Lc_Hlt1Phys_TIS;
   Bool_t          Lc_Hlt1Phys_TOS;
   Bool_t          Lc_L0ElectronDecision_Dec;
   Bool_t          Lc_L0ElectronDecision_TIS;
   Bool_t          Lc_L0ElectronDecision_TOS;
   Bool_t          Lc_L0PhotonDecision_Dec;
   Bool_t          Lc_L0PhotonDecision_TIS;
   Bool_t          Lc_L0PhotonDecision_TOS;
   Bool_t          Lc_L0HadronDecision_Dec;
   Bool_t          Lc_L0HadronDecision_TIS;
   Bool_t          Lc_L0HadronDecision_TOS;
   Bool_t          Lc_L0MuonDecision_Dec;
   Bool_t          Lc_L0MuonDecision_TIS;
   Bool_t          Lc_L0MuonDecision_TOS;
   Bool_t          Lc_L0MuonHighDecision_Dec;
   Bool_t          Lc_L0MuonHighDecision_TIS;
   Bool_t          Lc_L0MuonHighDecision_TOS;
   Bool_t          Lc_L0DiMuonDecision_Dec;
   Bool_t          Lc_L0DiMuonDecision_TIS;
   Bool_t          Lc_L0DiMuonDecision_TOS;
   Bool_t          Lc_Hlt1TrackAllL0Decision_Dec;
   Bool_t          Lc_Hlt1TrackAllL0Decision_TIS;
   Bool_t          Lc_Hlt1TrackAllL0Decision_TOS;
   Bool_t          Lc_Hlt1TrackMuonDecision_Dec;
   Bool_t          Lc_Hlt1TrackMuonDecision_TIS;
   Bool_t          Lc_Hlt1TrackMuonDecision_TOS;
   Bool_t          Lc_Hlt1TrackPhotonDecision_Dec;
   Bool_t          Lc_Hlt1TrackPhotonDecision_TIS;
   Bool_t          Lc_Hlt1TrackPhotonDecision_TOS;
   Bool_t          Lc_Hlt1TrackMVADecision_Dec;
   Bool_t          Lc_Hlt1TrackMVADecision_TIS;
   Bool_t          Lc_Hlt1TrackMVADecision_TOS;
   Bool_t          Lc_Hlt1TwoTrackMVADecision_Dec;
   Bool_t          Lc_Hlt1TwoTrackMVADecision_TIS;
   Bool_t          Lc_Hlt1TwoTrackMVADecision_TOS;
   Double_t        Xic_ETA;
   Double_t        Xic_LOKI_IPCHI2;
   Double_t        Xic_Y;
   Double_t        Xic_CosTheta;
   Double_t        Xic_ENDVERTEX_X;
   Double_t        Xic_ENDVERTEX_Y;
   Double_t        Xic_ENDVERTEX_Z;
   Double_t        Xic_ENDVERTEX_XERR;
   Double_t        Xic_ENDVERTEX_YERR;
   Double_t        Xic_ENDVERTEX_ZERR;
   Double_t        Xic_ENDVERTEX_CHI2;
   Int_t           Xic_ENDVERTEX_NDOF;
   Float_t         Xic_ENDVERTEX_COV_[3][3];
   Double_t        Xic_OWNPV_X;
   Double_t        Xic_OWNPV_Y;
   Double_t        Xic_OWNPV_Z;
   Double_t        Xic_OWNPV_XERR;
   Double_t        Xic_OWNPV_YERR;
   Double_t        Xic_OWNPV_ZERR;
   Double_t        Xic_OWNPV_CHI2;
   Int_t           Xic_OWNPV_NDOF;
   Float_t         Xic_OWNPV_COV_[3][3];
   Double_t        Xic_IP_OWNPV;
   Double_t        Xic_IPCHI2_OWNPV;
   Double_t        Xic_FD_OWNPV;
   Double_t        Xic_FDCHI2_OWNPV;
   Double_t        Xic_DIRA_OWNPV;
   Double_t        Xic_ORIVX_X;
   Double_t        Xic_ORIVX_Y;
   Double_t        Xic_ORIVX_Z;
   Double_t        Xic_ORIVX_XERR;
   Double_t        Xic_ORIVX_YERR;
   Double_t        Xic_ORIVX_ZERR;
   Double_t        Xic_ORIVX_CHI2;
   Int_t           Xic_ORIVX_NDOF;
   Float_t         Xic_ORIVX_COV_[3][3];
   Double_t        Xic_FD_ORIVX;
   Double_t        Xic_FDCHI2_ORIVX;
   Double_t        Xic_DIRA_ORIVX;
   Double_t        Xic_P;
   Double_t        Xic_PT;
   Double_t        Xic_PE;
   Double_t        Xic_PX;
   Double_t        Xic_PY;
   Double_t        Xic_PZ;
   Double_t        Xic_MM;
   Double_t        Xic_MMERR;
   Double_t        Xic_M;
   Int_t           Xic_ID;
   Double_t        Xic_TAU;
   Double_t        Xic_TAUERR;
   Double_t        Xic_TAUCHI2;
   Double_t        Xic_TMVA_BDT;
   UInt_t          nCandidate;
   ULong64_t       totCandidates;
   ULong64_t       EventInSequence;
   UInt_t          runNumber;
   ULong64_t       eventNumber;
   UInt_t          BCID;
   Int_t           BCType;
   UInt_t          OdinTCK;
   UInt_t          L0DUTCK;
   UInt_t          HLT1TCK;
   UInt_t          HLT2TCK;
   ULong64_t       GpsTime;
   Short_t         Polarity;
   Int_t           L0Data_DiMuon_Pt;
   Int_t           L0Data_DiMuonProd_Pt1Pt2;
   Int_t           L0Data_Electron_Et;
   Int_t           L0Data_GlobalPi0_Et;
   Int_t           L0Data_Hadron_Et;
   Int_t           L0Data_LocalPi0_Et;
   Int_t           L0Data_Muon1_Pt;
   Int_t           L0Data_Muon1_Sgn;
   Int_t           L0Data_Muon2_Pt;
   Int_t           L0Data_Muon2_Sgn;
   Int_t           L0Data_Muon3_Pt;
   Int_t           L0Data_Muon3_Sgn;
   Int_t           L0Data_PUHits_Mult;
   Int_t           L0Data_PUPeak1_Cont;
   Int_t           L0Data_PUPeak1_Pos;
   Int_t           L0Data_PUPeak2_Cont;
   Int_t           L0Data_PUPeak2_Pos;
   Int_t           L0Data_Photon_Et;
   Int_t           L0Data_Spd_Mult;
   Int_t           L0Data_Sum_Et;
   Int_t           L0Data_Sum_Et_Next1;
   Int_t           L0Data_Sum_Et_Next2;
   Int_t           L0Data_Sum_Et_Prev1;
   Int_t           L0Data_Sum_Et_Prev2;
   Int_t           nPV;
   Float_t         PVX[100];   //[nPV]
   Float_t         PVY[100];   //[nPV]
   Float_t         PVZ[100];   //[nPV]
   Float_t         PVXERR[100];   //[nPV]
   Float_t         PVYERR[100];   //[nPV]
   Float_t         PVZERR[100];   //[nPV]
   Float_t         PVCHI2[100];   //[nPV]
   Float_t         PVNDOF[100];   //[nPV]
   Float_t         PVNTRACKS[100];   //[nPV]
   Int_t           nPVs;
   Int_t           nTracks;
   Int_t           nLongTracks;
   Int_t           nDownstreamTracks;
   Int_t           nUpstreamTracks;
   Int_t           nVeloTracks;
   Int_t           nTTracks;
   Int_t           nBackTracks;
   Int_t           nRich1Hits;
   Int_t           nRich2Hits;
   Int_t           nVeloClusters;
   Int_t           nITClusters;
   Int_t           nTTClusters;
   Int_t           nOTClusters;
   Int_t           nSPDHits;
   Int_t           nMuonCoordsS0;
   Int_t           nMuonCoordsS1;
   Int_t           nMuonCoordsS2;
   Int_t           nMuonCoordsS3;
   Int_t           nMuonCoordsS4;
   Int_t           nMuonTracks;

   // List of branches
   TBranch        *b_C_ETA;   //!
   TBranch        *b_C_LOKI_IPCHI2;   //!
   TBranch        *b_C_Y;   //!
   TBranch        *b_C_ENDVERTEX_X;   //!
   TBranch        *b_C_ENDVERTEX_Y;   //!
   TBranch        *b_C_ENDVERTEX_Z;   //!
   TBranch        *b_C_ENDVERTEX_XERR;   //!
   TBranch        *b_C_ENDVERTEX_YERR;   //!
   TBranch        *b_C_ENDVERTEX_ZERR;   //!
   TBranch        *b_C_ENDVERTEX_CHI2;   //!
   TBranch        *b_C_ENDVERTEX_NDOF;   //!
   TBranch        *b_C_ENDVERTEX_COV_;   //!
   TBranch        *b_C_OWNPV_X;   //!
   TBranch        *b_C_OWNPV_Y;   //!
   TBranch        *b_C_OWNPV_Z;   //!
   TBranch        *b_C_OWNPV_XERR;   //!
   TBranch        *b_C_OWNPV_YERR;   //!
   TBranch        *b_C_OWNPV_ZERR;   //!
   TBranch        *b_C_OWNPV_CHI2;   //!
   TBranch        *b_C_OWNPV_NDOF;   //!
   TBranch        *b_C_OWNPV_COV_;   //!
   TBranch        *b_C_IP_OWNPV;   //!
   TBranch        *b_C_IPCHI2_OWNPV;   //!
   TBranch        *b_C_FD_OWNPV;   //!
   TBranch        *b_C_FDCHI2_OWNPV;   //!
   TBranch        *b_C_DIRA_OWNPV;   //!
   TBranch        *b_C_P;   //!
   TBranch        *b_C_PT;   //!
   TBranch        *b_C_PE;   //!
   TBranch        *b_C_PX;   //!
   TBranch        *b_C_PY;   //!
   TBranch        *b_C_PZ;   //!
   TBranch        *b_C_MM;   //!
   TBranch        *b_C_MMERR;   //!
   TBranch        *b_C_M;   //!
   TBranch        *b_C_ID;   //!
   TBranch        *b_C_TAU;   //!
   TBranch        *b_C_TAUERR;   //!
   TBranch        *b_C_TAUCHI2;   //!
   TBranch        *b_C_DTF_CHI2NDOF;   //!
   TBranch        *b_C_DTF_CTAU;   //!
   TBranch        *b_C_DTF_CTAUERR;   //!
   TBranch        *b_C_DTF_CTAUS;   //!
   TBranch        *b_C_DTF_DM;   //!
   TBranch        *b_C_DTF_M;   //!
   TBranch        *b_C_DTF_PV_CTAU;   //!
   TBranch        *b_C_DTF_PV_CTAUERR;   //!
   TBranch        *b_C_LOKI_DIRA;   //!
   TBranch        *b_C_LOKI_FDCHI2;   //!
   TBranch        *b_C_LOKI_FDS;   //!
   TBranch        *b_C_LV01;   //!
   TBranch        *b_C_LV02;   //!
   TBranch        *b_C_Lc_DTF_CTAU;   //!
   TBranch        *b_C_Lc_DTF_CTAUERR;   //!
   TBranch        *b_C_Lc_DTF_CTAUS;   //!
   TBranch        *b_C_Xic_DTF_CTAU;   //!
   TBranch        *b_C_Xic_DTF_CTAUERR;   //!
   TBranch        *b_C_Xic_DTF_CTAUS;   //!
   TBranch        *b_C_FullFit_nPV;   //!
   TBranch        *b_C_FullFit_Lambda_cplus_M;   //!
   TBranch        *b_C_FullFit_Lambda_cplus_MERR;   //!
   TBranch        *b_C_FullFit_Lambda_cplus_P;   //!
   TBranch        *b_C_FullFit_Lambda_cplus_PERR;   //!
   TBranch        *b_C_FullFit_Lambda_cplus_ctau;   //!
   TBranch        *b_C_FullFit_Lambda_cplus_ctauErr;   //!
   TBranch        *b_C_FullFit_Lambda_cplus_decayLength;   //!
   TBranch        *b_C_FullFit_Lambda_cplus_decayLengthErr;   //!
   TBranch        *b_C_FullFit_M;   //!
   TBranch        *b_C_FullFit_MERR;   //!
   TBranch        *b_C_FullFit_P;   //!
   TBranch        *b_C_FullFit_PERR;   //!
   TBranch        *b_C_FullFit_PV_X;   //!
   TBranch        *b_C_FullFit_PV_Y;   //!
   TBranch        *b_C_FullFit_PV_Z;   //!
   TBranch        *b_C_FullFit_PV_key;   //!
   TBranch        *b_C_FullFit_Xi_cplus_M;   //!
   TBranch        *b_C_FullFit_Xi_cplus_MERR;   //!
   TBranch        *b_C_FullFit_Xi_cplus_P;   //!
   TBranch        *b_C_FullFit_Xi_cplus_PERR;   //!
   TBranch        *b_C_FullFit_Xi_cplus_ctau;   //!
   TBranch        *b_C_FullFit_Xi_cplus_ctauErr;   //!
   TBranch        *b_C_FullFit_Xi_cplus_decayLength;   //!
   TBranch        *b_C_FullFit_Xi_cplus_decayLengthErr;   //!
   TBranch        *b_C_FullFit_chi2;   //!
   TBranch        *b_C_FullFit_ctau;   //!
   TBranch        *b_C_FullFit_ctauErr;   //!
   TBranch        *b_C_FullFit_decayLength;   //!
   TBranch        *b_C_FullFit_decayLengthErr;   //!
   TBranch        *b_C_FullFit_nDOF;   //!
   TBranch        *b_C_FullFit_nIter;   //!
   TBranch        *b_C_FullFit_status;   //!
   TBranch        *b_C_MassFit_nPV;   //!
   TBranch        *b_C_MassFit_M;   //!
   TBranch        *b_C_MassFit_MERR;   //!
   TBranch        *b_C_MassFit_P;   //!
   TBranch        *b_C_MassFit_PERR;   //!
   TBranch        *b_C_MassFit_chi2;   //!
   TBranch        *b_C_MassFit_nDOF;   //!
   TBranch        *b_C_MassFit_nIter;   //!
   TBranch        *b_C_MassFit_status;   //!
   TBranch        *b_C_PVFit_nPV;   //!
   TBranch        *b_C_PVFit_Lambda_cplus_M;   //!
   TBranch        *b_C_PVFit_Lambda_cplus_MERR;   //!
   TBranch        *b_C_PVFit_Lambda_cplus_P;   //!
   TBranch        *b_C_PVFit_Lambda_cplus_PERR;   //!
   TBranch        *b_C_PVFit_Lambda_cplus_ctau;   //!
   TBranch        *b_C_PVFit_Lambda_cplus_ctauErr;   //!
   TBranch        *b_C_PVFit_Lambda_cplus_decayLength;   //!
   TBranch        *b_C_PVFit_Lambda_cplus_decayLengthErr;   //!
   TBranch        *b_C_PVFit_M;   //!
   TBranch        *b_C_PVFit_MERR;   //!
   TBranch        *b_C_PVFit_P;   //!
   TBranch        *b_C_PVFit_PERR;   //!
   TBranch        *b_C_PVFit_PV_X;   //!
   TBranch        *b_C_PVFit_PV_Y;   //!
   TBranch        *b_C_PVFit_PV_Z;   //!
   TBranch        *b_C_PVFit_PV_key;   //!
   TBranch        *b_C_PVFit_Xi_cplus_M;   //!
   TBranch        *b_C_PVFit_Xi_cplus_MERR;   //!
   TBranch        *b_C_PVFit_Xi_cplus_P;   //!
   TBranch        *b_C_PVFit_Xi_cplus_PERR;   //!
   TBranch        *b_C_PVFit_Xi_cplus_ctau;   //!
   TBranch        *b_C_PVFit_Xi_cplus_ctauErr;   //!
   TBranch        *b_C_PVFit_Xi_cplus_decayLength;   //!
   TBranch        *b_C_PVFit_Xi_cplus_decayLengthErr;   //!
   TBranch        *b_C_PVFit_chi2;   //!
   TBranch        *b_C_PVFit_ctau;   //!
   TBranch        *b_C_PVFit_ctauErr;   //!
   TBranch        *b_C_PVFit_decayLength;   //!
   TBranch        *b_C_PVFit_decayLengthErr;   //!
   TBranch        *b_C_PVFit_nDOF;   //!
   TBranch        *b_C_PVFit_nIter;   //!
   TBranch        *b_C_PVFit_status;   //!
   TBranch        *b_C_L0Global_Dec;   //!
   TBranch        *b_C_L0Global_TIS;   //!
   TBranch        *b_C_L0Global_TOS;   //!
   TBranch        *b_C_Hlt1Global_Dec;   //!
   TBranch        *b_C_Hlt1Global_TIS;   //!
   TBranch        *b_C_Hlt1Global_TOS;   //!
   TBranch        *b_C_Hlt1Phys_Dec;   //!
   TBranch        *b_C_Hlt1Phys_TIS;   //!
   TBranch        *b_C_Hlt1Phys_TOS;   //!
   TBranch        *b_C_L0ElectronDecision_Dec;   //!
   TBranch        *b_C_L0ElectronDecision_TIS;   //!
   TBranch        *b_C_L0ElectronDecision_TOS;   //!
   TBranch        *b_C_L0PhotonDecision_Dec;   //!
   TBranch        *b_C_L0PhotonDecision_TIS;   //!
   TBranch        *b_C_L0PhotonDecision_TOS;   //!
   TBranch        *b_C_L0HadronDecision_Dec;   //!
   TBranch        *b_C_L0HadronDecision_TIS;   //!
   TBranch        *b_C_L0HadronDecision_TOS;   //!
   TBranch        *b_C_L0MuonDecision_Dec;   //!
   TBranch        *b_C_L0MuonDecision_TIS;   //!
   TBranch        *b_C_L0MuonDecision_TOS;   //!
   TBranch        *b_C_L0MuonHighDecision_Dec;   //!
   TBranch        *b_C_L0MuonHighDecision_TIS;   //!
   TBranch        *b_C_L0MuonHighDecision_TOS;   //!
   TBranch        *b_C_L0DiMuonDecision_Dec;   //!
   TBranch        *b_C_L0DiMuonDecision_TIS;   //!
   TBranch        *b_C_L0DiMuonDecision_TOS;   //!
   TBranch        *b_C_Hlt1TrackAllL0Decision_Dec;   //!
   TBranch        *b_C_Hlt1TrackAllL0Decision_TIS;   //!
   TBranch        *b_C_Hlt1TrackAllL0Decision_TOS;   //!
   TBranch        *b_C_Hlt1TrackMuonDecision_Dec;   //!
   TBranch        *b_C_Hlt1TrackMuonDecision_TIS;   //!
   TBranch        *b_C_Hlt1TrackMuonDecision_TOS;   //!
   TBranch        *b_C_Hlt1TrackPhotonDecision_Dec;   //!
   TBranch        *b_C_Hlt1TrackPhotonDecision_TIS;   //!
   TBranch        *b_C_Hlt1TrackPhotonDecision_TOS;   //!
   TBranch        *b_C_Hlt1TrackMVADecision_Dec;   //!
   TBranch        *b_C_Hlt1TrackMVADecision_TIS;   //!
   TBranch        *b_C_Hlt1TrackMVADecision_TOS;   //!
   TBranch        *b_C_Hlt1TwoTrackMVADecision_Dec;   //!
   TBranch        *b_C_Hlt1TwoTrackMVADecision_TIS;   //!
   TBranch        *b_C_Hlt1TwoTrackMVADecision_TOS;   //!
   TBranch        *b_Lc_ETA;   //!
   TBranch        *b_Lc_LOKI_IPCHI2;   //!
   TBranch        *b_Lc_Y;   //!
   TBranch        *b_Lc_CosTheta;   //!
   TBranch        *b_Lc_ENDVERTEX_X;   //!
   TBranch        *b_Lc_ENDVERTEX_Y;   //!
   TBranch        *b_Lc_ENDVERTEX_Z;   //!
   TBranch        *b_Lc_ENDVERTEX_XERR;   //!
   TBranch        *b_Lc_ENDVERTEX_YERR;   //!
   TBranch        *b_Lc_ENDVERTEX_ZERR;   //!
   TBranch        *b_Lc_ENDVERTEX_CHI2;   //!
   TBranch        *b_Lc_ENDVERTEX_NDOF;   //!
   TBranch        *b_Lc_ENDVERTEX_COV_;   //!
   TBranch        *b_Lc_OWNPV_X;   //!
   TBranch        *b_Lc_OWNPV_Y;   //!
   TBranch        *b_Lc_OWNPV_Z;   //!
   TBranch        *b_Lc_OWNPV_XERR;   //!
   TBranch        *b_Lc_OWNPV_YERR;   //!
   TBranch        *b_Lc_OWNPV_ZERR;   //!
   TBranch        *b_Lc_OWNPV_CHI2;   //!
   TBranch        *b_Lc_OWNPV_NDOF;   //!
   TBranch        *b_Lc_OWNPV_COV_;   //!
   TBranch        *b_Lc_IP_OWNPV;   //!
   TBranch        *b_Lc_IPCHI2_OWNPV;   //!
   TBranch        *b_Lc_FD_OWNPV;   //!
   TBranch        *b_Lc_FDCHI2_OWNPV;   //!
   TBranch        *b_Lc_DIRA_OWNPV;   //!
   TBranch        *b_Lc_ORIVX_X;   //!
   TBranch        *b_Lc_ORIVX_Y;   //!
   TBranch        *b_Lc_ORIVX_Z;   //!
   TBranch        *b_Lc_ORIVX_XERR;   //!
   TBranch        *b_Lc_ORIVX_YERR;   //!
   TBranch        *b_Lc_ORIVX_ZERR;   //!
   TBranch        *b_Lc_ORIVX_CHI2;   //!
   TBranch        *b_Lc_ORIVX_NDOF;   //!
   TBranch        *b_Lc_ORIVX_COV_;   //!
   TBranch        *b_Lc_FD_ORIVX;   //!
   TBranch        *b_Lc_FDCHI2_ORIVX;   //!
   TBranch        *b_Lc_DIRA_ORIVX;   //!
   TBranch        *b_Lc_P;   //!
   TBranch        *b_Lc_PT;   //!
   TBranch        *b_Lc_PE;   //!
   TBranch        *b_Lc_PX;   //!
   TBranch        *b_Lc_PY;   //!
   TBranch        *b_Lc_PZ;   //!
   TBranch        *b_Lc_MM;   //!
   TBranch        *b_Lc_MMERR;   //!
   TBranch        *b_Lc_M;   //!
   TBranch        *b_Lc_ID;   //!
   TBranch        *b_Lc_TAU;   //!
   TBranch        *b_Lc_TAUERR;   //!
   TBranch        *b_Lc_TAUCHI2;   //!
   TBranch        *b_Lc_TMVA_BDT;   //!
   TBranch        *b_Lc_L0Global_Dec;   //!
   TBranch        *b_Lc_L0Global_TIS;   //!
   TBranch        *b_Lc_L0Global_TOS;   //!
   TBranch        *b_Lc_Hlt1Global_Dec;   //!
   TBranch        *b_Lc_Hlt1Global_TIS;   //!
   TBranch        *b_Lc_Hlt1Global_TOS;   //!
   TBranch        *b_Lc_Hlt1Phys_Dec;   //!
   TBranch        *b_Lc_Hlt1Phys_TIS;   //!
   TBranch        *b_Lc_Hlt1Phys_TOS;   //!
   TBranch        *b_Lc_L0ElectronDecision_Dec;   //!
   TBranch        *b_Lc_L0ElectronDecision_TIS;   //!
   TBranch        *b_Lc_L0ElectronDecision_TOS;   //!
   TBranch        *b_Lc_L0PhotonDecision_Dec;   //!
   TBranch        *b_Lc_L0PhotonDecision_TIS;   //!
   TBranch        *b_Lc_L0PhotonDecision_TOS;   //!
   TBranch        *b_Lc_L0HadronDecision_Dec;   //!
   TBranch        *b_Lc_L0HadronDecision_TIS;   //!
   TBranch        *b_Lc_L0HadronDecision_TOS;   //!
   TBranch        *b_Lc_L0MuonDecision_Dec;   //!
   TBranch        *b_Lc_L0MuonDecision_TIS;   //!
   TBranch        *b_Lc_L0MuonDecision_TOS;   //!
   TBranch        *b_Lc_L0MuonHighDecision_Dec;   //!
   TBranch        *b_Lc_L0MuonHighDecision_TIS;   //!
   TBranch        *b_Lc_L0MuonHighDecision_TOS;   //!
   TBranch        *b_Lc_L0DiMuonDecision_Dec;   //!
   TBranch        *b_Lc_L0DiMuonDecision_TIS;   //!
   TBranch        *b_Lc_L0DiMuonDecision_TOS;   //!
   TBranch        *b_Lc_Hlt1TrackAllL0Decision_Dec;   //!
   TBranch        *b_Lc_Hlt1TrackAllL0Decision_TIS;   //!
   TBranch        *b_Lc_Hlt1TrackAllL0Decision_TOS;   //!
   TBranch        *b_Lc_Hlt1TrackMuonDecision_Dec;   //!
   TBranch        *b_Lc_Hlt1TrackMuonDecision_TIS;   //!
   TBranch        *b_Lc_Hlt1TrackMuonDecision_TOS;   //!
   TBranch        *b_Lc_Hlt1TrackPhotonDecision_Dec;   //!
   TBranch        *b_Lc_Hlt1TrackPhotonDecision_TIS;   //!
   TBranch        *b_Lc_Hlt1TrackPhotonDecision_TOS;   //!
   TBranch        *b_Lc_Hlt1TrackMVADecision_Dec;   //!
   TBranch        *b_Lc_Hlt1TrackMVADecision_TIS;   //!
   TBranch        *b_Lc_Hlt1TrackMVADecision_TOS;   //!
   TBranch        *b_Lc_Hlt1TwoTrackMVADecision_Dec;   //!
   TBranch        *b_Lc_Hlt1TwoTrackMVADecision_TIS;   //!
   TBranch        *b_Lc_Hlt1TwoTrackMVADecision_TOS;   //!
   TBranch        *b_Xic_ETA;   //!
   TBranch        *b_Xic_LOKI_IPCHI2;   //!
   TBranch        *b_Xic_Y;   //!
   TBranch        *b_Xic_CosTheta;   //!
   TBranch        *b_Xic_ENDVERTEX_X;   //!
   TBranch        *b_Xic_ENDVERTEX_Y;   //!
   TBranch        *b_Xic_ENDVERTEX_Z;   //!
   TBranch        *b_Xic_ENDVERTEX_XERR;   //!
   TBranch        *b_Xic_ENDVERTEX_YERR;   //!
   TBranch        *b_Xic_ENDVERTEX_ZERR;   //!
   TBranch        *b_Xic_ENDVERTEX_CHI2;   //!
   TBranch        *b_Xic_ENDVERTEX_NDOF;   //!
   TBranch        *b_Xic_ENDVERTEX_COV_;   //!
   TBranch        *b_Xic_OWNPV_X;   //!
   TBranch        *b_Xic_OWNPV_Y;   //!
   TBranch        *b_Xic_OWNPV_Z;   //!
   TBranch        *b_Xic_OWNPV_XERR;   //!
   TBranch        *b_Xic_OWNPV_YERR;   //!
   TBranch        *b_Xic_OWNPV_ZERR;   //!
   TBranch        *b_Xic_OWNPV_CHI2;   //!
   TBranch        *b_Xic_OWNPV_NDOF;   //!
   TBranch        *b_Xic_OWNPV_COV_;   //!
   TBranch        *b_Xic_IP_OWNPV;   //!
   TBranch        *b_Xic_IPCHI2_OWNPV;   //!
   TBranch        *b_Xic_FD_OWNPV;   //!
   TBranch        *b_Xic_FDCHI2_OWNPV;   //!
   TBranch        *b_Xic_DIRA_OWNPV;   //!
   TBranch        *b_Xic_ORIVX_X;   //!
   TBranch        *b_Xic_ORIVX_Y;   //!
   TBranch        *b_Xic_ORIVX_Z;   //!
   TBranch        *b_Xic_ORIVX_XERR;   //!
   TBranch        *b_Xic_ORIVX_YERR;   //!
   TBranch        *b_Xic_ORIVX_ZERR;   //!
   TBranch        *b_Xic_ORIVX_CHI2;   //!
   TBranch        *b_Xic_ORIVX_NDOF;   //!
   TBranch        *b_Xic_ORIVX_COV_;   //!
   TBranch        *b_Xic_FD_ORIVX;   //!
   TBranch        *b_Xic_FDCHI2_ORIVX;   //!
   TBranch        *b_Xic_DIRA_ORIVX;   //!
   TBranch        *b_Xic_P;   //!
   TBranch        *b_Xic_PT;   //!
   TBranch        *b_Xic_PE;   //!
   TBranch        *b_Xic_PX;   //!
   TBranch        *b_Xic_PY;   //!
   TBranch        *b_Xic_PZ;   //!
   TBranch        *b_Xic_MM;   //!
   TBranch        *b_Xic_MMERR;   //!
   TBranch        *b_Xic_M;   //!
   TBranch        *b_Xic_ID;   //!
   TBranch        *b_Xic_TAU;   //!
   TBranch        *b_Xic_TAUERR;   //!
   TBranch        *b_Xic_TAUCHI2;   //!
   TBranch        *b_Xic_TMVA_BDT;   //!
   TBranch        *b_nCandidate;   //!
   TBranch        *b_totCandidates;   //!
   TBranch        *b_EventInSequence;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_BCID;   //!
   TBranch        *b_BCType;   //!
   TBranch        *b_OdinTCK;   //!
   TBranch        *b_L0DUTCK;   //!
   TBranch        *b_HLT1TCK;   //!
   TBranch        *b_HLT2TCK;   //!
   TBranch        *b_GpsTime;   //!
   TBranch        *b_Polarity;   //!
   TBranch        *b_L0Data_DiMuon_Pt;   //!
   TBranch        *b_L0Data_DiMuonProd_Pt1Pt2;   //!
   TBranch        *b_L0Data_Electron_Et;   //!
   TBranch        *b_L0Data_GlobalPi0_Et;   //!
   TBranch        *b_L0Data_Hadron_Et;   //!
   TBranch        *b_L0Data_LocalPi0_Et;   //!
   TBranch        *b_L0Data_Muon1_Pt;   //!
   TBranch        *b_L0Data_Muon1_Sgn;   //!
   TBranch        *b_L0Data_Muon2_Pt;   //!
   TBranch        *b_L0Data_Muon2_Sgn;   //!
   TBranch        *b_L0Data_Muon3_Pt;   //!
   TBranch        *b_L0Data_Muon3_Sgn;   //!
   TBranch        *b_L0Data_PUHits_Mult;   //!
   TBranch        *b_L0Data_PUPeak1_Cont;   //!
   TBranch        *b_L0Data_PUPeak1_Pos;   //!
   TBranch        *b_L0Data_PUPeak2_Cont;   //!
   TBranch        *b_L0Data_PUPeak2_Pos;   //!
   TBranch        *b_L0Data_Photon_Et;   //!
   TBranch        *b_L0Data_Spd_Mult;   //!
   TBranch        *b_L0Data_Sum_Et;   //!
   TBranch        *b_L0Data_Sum_Et_Next1;   //!
   TBranch        *b_L0Data_Sum_Et_Next2;   //!
   TBranch        *b_L0Data_Sum_Et_Prev1;   //!
   TBranch        *b_L0Data_Sum_Et_Prev2;   //!
   TBranch        *b_nPV;   //!
   TBranch        *b_PVX;   //!
   TBranch        *b_PVY;   //!
   TBranch        *b_PVZ;   //!
   TBranch        *b_PVXERR;   //!
   TBranch        *b_PVYERR;   //!
   TBranch        *b_PVZERR;   //!
   TBranch        *b_PVCHI2;   //!
   TBranch        *b_PVNDOF;   //!
   TBranch        *b_PVNTRACKS;   //!
   TBranch        *b_nPVs;   //!
   TBranch        *b_nTracks;   //!
   TBranch        *b_nLongTracks;   //!
   TBranch        *b_nDownstreamTracks;   //!
   TBranch        *b_nUpstreamTracks;   //!
   TBranch        *b_nVeloTracks;   //!
   TBranch        *b_nTTracks;   //!
   TBranch        *b_nBackTracks;   //!
   TBranch        *b_nRich1Hits;   //!
   TBranch        *b_nRich2Hits;   //!
   TBranch        *b_nVeloClusters;   //!
   TBranch        *b_nITClusters;   //!
   TBranch        *b_nTTClusters;   //!
   TBranch        *b_nOTClusters;   //!
   TBranch        *b_nSPDHits;   //!
   TBranch        *b_nMuonCoordsS0;   //!
   TBranch        *b_nMuonCoordsS1;   //!
   TBranch        *b_nMuonCoordsS2;   //!
   TBranch        *b_nMuonCoordsS3;   //!
   TBranch        *b_nMuonCoordsS4;   //!
   TBranch        *b_nMuonTracks;   //!

   LcXic_Class(TTree *tree=0);
   virtual ~LcXic_Class();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef LcXic_Class_cxx
LcXic_Class::LcXic_Class(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("XiccTuple.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("XiccTuple.root");
      }
      f->GetObject("DecayTree",tree);

   }
   Init(tree);
}

LcXic_Class::~LcXic_Class()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t LcXic_Class::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t LcXic_Class::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void LcXic_Class::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("C_ETA", &C_ETA, &b_C_ETA);
   fChain->SetBranchAddress("C_LOKI_IPCHI2", &C_LOKI_IPCHI2, &b_C_LOKI_IPCHI2);
   fChain->SetBranchAddress("C_Y", &C_Y, &b_C_Y);
   fChain->SetBranchAddress("C_ENDVERTEX_X", &C_ENDVERTEX_X, &b_C_ENDVERTEX_X);
   fChain->SetBranchAddress("C_ENDVERTEX_Y", &C_ENDVERTEX_Y, &b_C_ENDVERTEX_Y);
   fChain->SetBranchAddress("C_ENDVERTEX_Z", &C_ENDVERTEX_Z, &b_C_ENDVERTEX_Z);
   fChain->SetBranchAddress("C_ENDVERTEX_XERR", &C_ENDVERTEX_XERR, &b_C_ENDVERTEX_XERR);
   fChain->SetBranchAddress("C_ENDVERTEX_YERR", &C_ENDVERTEX_YERR, &b_C_ENDVERTEX_YERR);
   fChain->SetBranchAddress("C_ENDVERTEX_ZERR", &C_ENDVERTEX_ZERR, &b_C_ENDVERTEX_ZERR);
   fChain->SetBranchAddress("C_ENDVERTEX_CHI2", &C_ENDVERTEX_CHI2, &b_C_ENDVERTEX_CHI2);
   fChain->SetBranchAddress("C_ENDVERTEX_NDOF", &C_ENDVERTEX_NDOF, &b_C_ENDVERTEX_NDOF);
   fChain->SetBranchAddress("C_ENDVERTEX_COV_", C_ENDVERTEX_COV_, &b_C_ENDVERTEX_COV_);
   fChain->SetBranchAddress("C_OWNPV_X", &C_OWNPV_X, &b_C_OWNPV_X);
   fChain->SetBranchAddress("C_OWNPV_Y", &C_OWNPV_Y, &b_C_OWNPV_Y);
   fChain->SetBranchAddress("C_OWNPV_Z", &C_OWNPV_Z, &b_C_OWNPV_Z);
   fChain->SetBranchAddress("C_OWNPV_XERR", &C_OWNPV_XERR, &b_C_OWNPV_XERR);
   fChain->SetBranchAddress("C_OWNPV_YERR", &C_OWNPV_YERR, &b_C_OWNPV_YERR);
   fChain->SetBranchAddress("C_OWNPV_ZERR", &C_OWNPV_ZERR, &b_C_OWNPV_ZERR);
   fChain->SetBranchAddress("C_OWNPV_CHI2", &C_OWNPV_CHI2, &b_C_OWNPV_CHI2);
   fChain->SetBranchAddress("C_OWNPV_NDOF", &C_OWNPV_NDOF, &b_C_OWNPV_NDOF);
   fChain->SetBranchAddress("C_OWNPV_COV_", C_OWNPV_COV_, &b_C_OWNPV_COV_);
   fChain->SetBranchAddress("C_IP_OWNPV", &C_IP_OWNPV, &b_C_IP_OWNPV);
   fChain->SetBranchAddress("C_IPCHI2_OWNPV", &C_IPCHI2_OWNPV, &b_C_IPCHI2_OWNPV);
   fChain->SetBranchAddress("C_FD_OWNPV", &C_FD_OWNPV, &b_C_FD_OWNPV);
   fChain->SetBranchAddress("C_FDCHI2_OWNPV", &C_FDCHI2_OWNPV, &b_C_FDCHI2_OWNPV);
   fChain->SetBranchAddress("C_DIRA_OWNPV", &C_DIRA_OWNPV, &b_C_DIRA_OWNPV);
   fChain->SetBranchAddress("C_P", &C_P, &b_C_P);
   fChain->SetBranchAddress("C_PT", &C_PT, &b_C_PT);
   fChain->SetBranchAddress("C_PE", &C_PE, &b_C_PE);
   fChain->SetBranchAddress("C_PX", &C_PX, &b_C_PX);
   fChain->SetBranchAddress("C_PY", &C_PY, &b_C_PY);
   fChain->SetBranchAddress("C_PZ", &C_PZ, &b_C_PZ);
   fChain->SetBranchAddress("C_MM", &C_MM, &b_C_MM);
   fChain->SetBranchAddress("C_MMERR", &C_MMERR, &b_C_MMERR);
   fChain->SetBranchAddress("C_M", &C_M, &b_C_M);
   fChain->SetBranchAddress("C_ID", &C_ID, &b_C_ID);
   fChain->SetBranchAddress("C_TAU", &C_TAU, &b_C_TAU);
   fChain->SetBranchAddress("C_TAUERR", &C_TAUERR, &b_C_TAUERR);
   fChain->SetBranchAddress("C_TAUCHI2", &C_TAUCHI2, &b_C_TAUCHI2);
   fChain->SetBranchAddress("C_DTF_CHI2NDOF", &C_DTF_CHI2NDOF, &b_C_DTF_CHI2NDOF);
   fChain->SetBranchAddress("C_DTF_CTAU", &C_DTF_CTAU, &b_C_DTF_CTAU);
   fChain->SetBranchAddress("C_DTF_CTAUERR", &C_DTF_CTAUERR, &b_C_DTF_CTAUERR);
   fChain->SetBranchAddress("C_DTF_CTAUS", &C_DTF_CTAUS, &b_C_DTF_CTAUS);
   fChain->SetBranchAddress("C_DTF_DM", &C_DTF_DM, &b_C_DTF_DM);
   fChain->SetBranchAddress("C_DTF_M", &C_DTF_M, &b_C_DTF_M);
   fChain->SetBranchAddress("C_DTF_PV_CTAU", &C_DTF_PV_CTAU, &b_C_DTF_PV_CTAU);
   fChain->SetBranchAddress("C_DTF_PV_CTAUERR", &C_DTF_PV_CTAUERR, &b_C_DTF_PV_CTAUERR);
   fChain->SetBranchAddress("C_LOKI_DIRA", &C_LOKI_DIRA, &b_C_LOKI_DIRA);
   fChain->SetBranchAddress("C_LOKI_FDCHI2", &C_LOKI_FDCHI2, &b_C_LOKI_FDCHI2);
   fChain->SetBranchAddress("C_LOKI_FDS", &C_LOKI_FDS, &b_C_LOKI_FDS);
   fChain->SetBranchAddress("C_LV01", &C_LV01, &b_C_LV01);
   fChain->SetBranchAddress("C_LV02", &C_LV02, &b_C_LV02);
   fChain->SetBranchAddress("C_Lc_DTF_CTAU", &C_Lc_DTF_CTAU, &b_C_Lc_DTF_CTAU);
   fChain->SetBranchAddress("C_Lc_DTF_CTAUERR", &C_Lc_DTF_CTAUERR, &b_C_Lc_DTF_CTAUERR);
   fChain->SetBranchAddress("C_Lc_DTF_CTAUS", &C_Lc_DTF_CTAUS, &b_C_Lc_DTF_CTAUS);
   fChain->SetBranchAddress("C_Xic_DTF_CTAU", &C_Xic_DTF_CTAU, &b_C_Xic_DTF_CTAU);
   fChain->SetBranchAddress("C_Xic_DTF_CTAUERR", &C_Xic_DTF_CTAUERR, &b_C_Xic_DTF_CTAUERR);
   fChain->SetBranchAddress("C_Xic_DTF_CTAUS", &C_Xic_DTF_CTAUS, &b_C_Xic_DTF_CTAUS);
   fChain->SetBranchAddress("C_FullFit_nPV", &C_FullFit_nPV, &b_C_FullFit_nPV);
   fChain->SetBranchAddress("C_FullFit_Lambda_cplus_M", C_FullFit_Lambda_cplus_M, &b_C_FullFit_Lambda_cplus_M);
   fChain->SetBranchAddress("C_FullFit_Lambda_cplus_MERR", C_FullFit_Lambda_cplus_MERR, &b_C_FullFit_Lambda_cplus_MERR);
   fChain->SetBranchAddress("C_FullFit_Lambda_cplus_P", C_FullFit_Lambda_cplus_P, &b_C_FullFit_Lambda_cplus_P);
   fChain->SetBranchAddress("C_FullFit_Lambda_cplus_PERR", C_FullFit_Lambda_cplus_PERR, &b_C_FullFit_Lambda_cplus_PERR);
   fChain->SetBranchAddress("C_FullFit_Lambda_cplus_ctau", C_FullFit_Lambda_cplus_ctau, &b_C_FullFit_Lambda_cplus_ctau);
   fChain->SetBranchAddress("C_FullFit_Lambda_cplus_ctauErr", C_FullFit_Lambda_cplus_ctauErr, &b_C_FullFit_Lambda_cplus_ctauErr);
   fChain->SetBranchAddress("C_FullFit_Lambda_cplus_decayLength", C_FullFit_Lambda_cplus_decayLength, &b_C_FullFit_Lambda_cplus_decayLength);
   fChain->SetBranchAddress("C_FullFit_Lambda_cplus_decayLengthErr", C_FullFit_Lambda_cplus_decayLengthErr, &b_C_FullFit_Lambda_cplus_decayLengthErr);
   fChain->SetBranchAddress("C_FullFit_M", C_FullFit_M, &b_C_FullFit_M);
   fChain->SetBranchAddress("C_FullFit_MERR", C_FullFit_MERR, &b_C_FullFit_MERR);
   fChain->SetBranchAddress("C_FullFit_P", C_FullFit_P, &b_C_FullFit_P);
   fChain->SetBranchAddress("C_FullFit_PERR", C_FullFit_PERR, &b_C_FullFit_PERR);
   fChain->SetBranchAddress("C_FullFit_PV_X", C_FullFit_PV_X, &b_C_FullFit_PV_X);
   fChain->SetBranchAddress("C_FullFit_PV_Y", C_FullFit_PV_Y, &b_C_FullFit_PV_Y);
   fChain->SetBranchAddress("C_FullFit_PV_Z", C_FullFit_PV_Z, &b_C_FullFit_PV_Z);
   fChain->SetBranchAddress("C_FullFit_PV_key", C_FullFit_PV_key, &b_C_FullFit_PV_key);
   fChain->SetBranchAddress("C_FullFit_Xi_cplus_M", C_FullFit_Xi_cplus_M, &b_C_FullFit_Xi_cplus_M);
   fChain->SetBranchAddress("C_FullFit_Xi_cplus_MERR", C_FullFit_Xi_cplus_MERR, &b_C_FullFit_Xi_cplus_MERR);
   fChain->SetBranchAddress("C_FullFit_Xi_cplus_P", C_FullFit_Xi_cplus_P, &b_C_FullFit_Xi_cplus_P);
   fChain->SetBranchAddress("C_FullFit_Xi_cplus_PERR", C_FullFit_Xi_cplus_PERR, &b_C_FullFit_Xi_cplus_PERR);
   fChain->SetBranchAddress("C_FullFit_Xi_cplus_ctau", C_FullFit_Xi_cplus_ctau, &b_C_FullFit_Xi_cplus_ctau);
   fChain->SetBranchAddress("C_FullFit_Xi_cplus_ctauErr", C_FullFit_Xi_cplus_ctauErr, &b_C_FullFit_Xi_cplus_ctauErr);
   fChain->SetBranchAddress("C_FullFit_Xi_cplus_decayLength", C_FullFit_Xi_cplus_decayLength, &b_C_FullFit_Xi_cplus_decayLength);
   fChain->SetBranchAddress("C_FullFit_Xi_cplus_decayLengthErr", C_FullFit_Xi_cplus_decayLengthErr, &b_C_FullFit_Xi_cplus_decayLengthErr);
   fChain->SetBranchAddress("C_FullFit_chi2", C_FullFit_chi2, &b_C_FullFit_chi2);
   fChain->SetBranchAddress("C_FullFit_ctau", C_FullFit_ctau, &b_C_FullFit_ctau);
   fChain->SetBranchAddress("C_FullFit_ctauErr", C_FullFit_ctauErr, &b_C_FullFit_ctauErr);
   fChain->SetBranchAddress("C_FullFit_decayLength", C_FullFit_decayLength, &b_C_FullFit_decayLength);
   fChain->SetBranchAddress("C_FullFit_decayLengthErr", C_FullFit_decayLengthErr, &b_C_FullFit_decayLengthErr);
   fChain->SetBranchAddress("C_FullFit_nDOF", C_FullFit_nDOF, &b_C_FullFit_nDOF);
   fChain->SetBranchAddress("C_FullFit_nIter", C_FullFit_nIter, &b_C_FullFit_nIter);
   fChain->SetBranchAddress("C_FullFit_status", C_FullFit_status, &b_C_FullFit_status);
   fChain->SetBranchAddress("C_MassFit_nPV", &C_MassFit_nPV, &b_C_MassFit_nPV);
   fChain->SetBranchAddress("C_MassFit_M", C_MassFit_M, &b_C_MassFit_M);
   fChain->SetBranchAddress("C_MassFit_MERR", C_MassFit_MERR, &b_C_MassFit_MERR);
   fChain->SetBranchAddress("C_MassFit_P", C_MassFit_P, &b_C_MassFit_P);
   fChain->SetBranchAddress("C_MassFit_PERR", C_MassFit_PERR, &b_C_MassFit_PERR);
   fChain->SetBranchAddress("C_MassFit_chi2", C_MassFit_chi2, &b_C_MassFit_chi2);
   fChain->SetBranchAddress("C_MassFit_nDOF", C_MassFit_nDOF, &b_C_MassFit_nDOF);
   fChain->SetBranchAddress("C_MassFit_nIter", C_MassFit_nIter, &b_C_MassFit_nIter);
   fChain->SetBranchAddress("C_MassFit_status", C_MassFit_status, &b_C_MassFit_status);
   fChain->SetBranchAddress("C_PVFit_nPV", &C_PVFit_nPV, &b_C_PVFit_nPV);
   fChain->SetBranchAddress("C_PVFit_Lambda_cplus_M", C_PVFit_Lambda_cplus_M, &b_C_PVFit_Lambda_cplus_M);
   fChain->SetBranchAddress("C_PVFit_Lambda_cplus_MERR", C_PVFit_Lambda_cplus_MERR, &b_C_PVFit_Lambda_cplus_MERR);
   fChain->SetBranchAddress("C_PVFit_Lambda_cplus_P", C_PVFit_Lambda_cplus_P, &b_C_PVFit_Lambda_cplus_P);
   fChain->SetBranchAddress("C_PVFit_Lambda_cplus_PERR", C_PVFit_Lambda_cplus_PERR, &b_C_PVFit_Lambda_cplus_PERR);
   fChain->SetBranchAddress("C_PVFit_Lambda_cplus_ctau", C_PVFit_Lambda_cplus_ctau, &b_C_PVFit_Lambda_cplus_ctau);
   fChain->SetBranchAddress("C_PVFit_Lambda_cplus_ctauErr", C_PVFit_Lambda_cplus_ctauErr, &b_C_PVFit_Lambda_cplus_ctauErr);
   fChain->SetBranchAddress("C_PVFit_Lambda_cplus_decayLength", C_PVFit_Lambda_cplus_decayLength, &b_C_PVFit_Lambda_cplus_decayLength);
   fChain->SetBranchAddress("C_PVFit_Lambda_cplus_decayLengthErr", C_PVFit_Lambda_cplus_decayLengthErr, &b_C_PVFit_Lambda_cplus_decayLengthErr);
   fChain->SetBranchAddress("C_PVFit_M", C_PVFit_M, &b_C_PVFit_M);
   fChain->SetBranchAddress("C_PVFit_MERR", C_PVFit_MERR, &b_C_PVFit_MERR);
   fChain->SetBranchAddress("C_PVFit_P", C_PVFit_P, &b_C_PVFit_P);
   fChain->SetBranchAddress("C_PVFit_PERR", C_PVFit_PERR, &b_C_PVFit_PERR);
   fChain->SetBranchAddress("C_PVFit_PV_X", C_PVFit_PV_X, &b_C_PVFit_PV_X);
   fChain->SetBranchAddress("C_PVFit_PV_Y", C_PVFit_PV_Y, &b_C_PVFit_PV_Y);
   fChain->SetBranchAddress("C_PVFit_PV_Z", C_PVFit_PV_Z, &b_C_PVFit_PV_Z);
   fChain->SetBranchAddress("C_PVFit_PV_key", C_PVFit_PV_key, &b_C_PVFit_PV_key);
   fChain->SetBranchAddress("C_PVFit_Xi_cplus_M", C_PVFit_Xi_cplus_M, &b_C_PVFit_Xi_cplus_M);
   fChain->SetBranchAddress("C_PVFit_Xi_cplus_MERR", C_PVFit_Xi_cplus_MERR, &b_C_PVFit_Xi_cplus_MERR);
   fChain->SetBranchAddress("C_PVFit_Xi_cplus_P", C_PVFit_Xi_cplus_P, &b_C_PVFit_Xi_cplus_P);
   fChain->SetBranchAddress("C_PVFit_Xi_cplus_PERR", C_PVFit_Xi_cplus_PERR, &b_C_PVFit_Xi_cplus_PERR);
   fChain->SetBranchAddress("C_PVFit_Xi_cplus_ctau", C_PVFit_Xi_cplus_ctau, &b_C_PVFit_Xi_cplus_ctau);
   fChain->SetBranchAddress("C_PVFit_Xi_cplus_ctauErr", C_PVFit_Xi_cplus_ctauErr, &b_C_PVFit_Xi_cplus_ctauErr);
   fChain->SetBranchAddress("C_PVFit_Xi_cplus_decayLength", C_PVFit_Xi_cplus_decayLength, &b_C_PVFit_Xi_cplus_decayLength);
   fChain->SetBranchAddress("C_PVFit_Xi_cplus_decayLengthErr", C_PVFit_Xi_cplus_decayLengthErr, &b_C_PVFit_Xi_cplus_decayLengthErr);
   fChain->SetBranchAddress("C_PVFit_chi2", C_PVFit_chi2, &b_C_PVFit_chi2);
   fChain->SetBranchAddress("C_PVFit_ctau", C_PVFit_ctau, &b_C_PVFit_ctau);
   fChain->SetBranchAddress("C_PVFit_ctauErr", C_PVFit_ctauErr, &b_C_PVFit_ctauErr);
   fChain->SetBranchAddress("C_PVFit_decayLength", C_PVFit_decayLength, &b_C_PVFit_decayLength);
   fChain->SetBranchAddress("C_PVFit_decayLengthErr", C_PVFit_decayLengthErr, &b_C_PVFit_decayLengthErr);
   fChain->SetBranchAddress("C_PVFit_nDOF", C_PVFit_nDOF, &b_C_PVFit_nDOF);
   fChain->SetBranchAddress("C_PVFit_nIter", C_PVFit_nIter, &b_C_PVFit_nIter);
   fChain->SetBranchAddress("C_PVFit_status", C_PVFit_status, &b_C_PVFit_status);
   fChain->SetBranchAddress("C_L0Global_Dec", &C_L0Global_Dec, &b_C_L0Global_Dec);
   fChain->SetBranchAddress("C_L0Global_TIS", &C_L0Global_TIS, &b_C_L0Global_TIS);
   fChain->SetBranchAddress("C_L0Global_TOS", &C_L0Global_TOS, &b_C_L0Global_TOS);
   fChain->SetBranchAddress("C_Hlt1Global_Dec", &C_Hlt1Global_Dec, &b_C_Hlt1Global_Dec);
   fChain->SetBranchAddress("C_Hlt1Global_TIS", &C_Hlt1Global_TIS, &b_C_Hlt1Global_TIS);
   fChain->SetBranchAddress("C_Hlt1Global_TOS", &C_Hlt1Global_TOS, &b_C_Hlt1Global_TOS);
   fChain->SetBranchAddress("C_Hlt1Phys_Dec", &C_Hlt1Phys_Dec, &b_C_Hlt1Phys_Dec);
   fChain->SetBranchAddress("C_Hlt1Phys_TIS", &C_Hlt1Phys_TIS, &b_C_Hlt1Phys_TIS);
   fChain->SetBranchAddress("C_Hlt1Phys_TOS", &C_Hlt1Phys_TOS, &b_C_Hlt1Phys_TOS);
   fChain->SetBranchAddress("C_L0ElectronDecision_Dec", &C_L0ElectronDecision_Dec, &b_C_L0ElectronDecision_Dec);
   fChain->SetBranchAddress("C_L0ElectronDecision_TIS", &C_L0ElectronDecision_TIS, &b_C_L0ElectronDecision_TIS);
   fChain->SetBranchAddress("C_L0ElectronDecision_TOS", &C_L0ElectronDecision_TOS, &b_C_L0ElectronDecision_TOS);
   fChain->SetBranchAddress("C_L0PhotonDecision_Dec", &C_L0PhotonDecision_Dec, &b_C_L0PhotonDecision_Dec);
   fChain->SetBranchAddress("C_L0PhotonDecision_TIS", &C_L0PhotonDecision_TIS, &b_C_L0PhotonDecision_TIS);
   fChain->SetBranchAddress("C_L0PhotonDecision_TOS", &C_L0PhotonDecision_TOS, &b_C_L0PhotonDecision_TOS);
   fChain->SetBranchAddress("C_L0HadronDecision_Dec", &C_L0HadronDecision_Dec, &b_C_L0HadronDecision_Dec);
   fChain->SetBranchAddress("C_L0HadronDecision_TIS", &C_L0HadronDecision_TIS, &b_C_L0HadronDecision_TIS);
   fChain->SetBranchAddress("C_L0HadronDecision_TOS", &C_L0HadronDecision_TOS, &b_C_L0HadronDecision_TOS);
   fChain->SetBranchAddress("C_L0MuonDecision_Dec", &C_L0MuonDecision_Dec, &b_C_L0MuonDecision_Dec);
   fChain->SetBranchAddress("C_L0MuonDecision_TIS", &C_L0MuonDecision_TIS, &b_C_L0MuonDecision_TIS);
   fChain->SetBranchAddress("C_L0MuonDecision_TOS", &C_L0MuonDecision_TOS, &b_C_L0MuonDecision_TOS);
   fChain->SetBranchAddress("C_L0MuonHighDecision_Dec", &C_L0MuonHighDecision_Dec, &b_C_L0MuonHighDecision_Dec);
   fChain->SetBranchAddress("C_L0MuonHighDecision_TIS", &C_L0MuonHighDecision_TIS, &b_C_L0MuonHighDecision_TIS);
   fChain->SetBranchAddress("C_L0MuonHighDecision_TOS", &C_L0MuonHighDecision_TOS, &b_C_L0MuonHighDecision_TOS);
   fChain->SetBranchAddress("C_L0DiMuonDecision_Dec", &C_L0DiMuonDecision_Dec, &b_C_L0DiMuonDecision_Dec);
   fChain->SetBranchAddress("C_L0DiMuonDecision_TIS", &C_L0DiMuonDecision_TIS, &b_C_L0DiMuonDecision_TIS);
   fChain->SetBranchAddress("C_L0DiMuonDecision_TOS", &C_L0DiMuonDecision_TOS, &b_C_L0DiMuonDecision_TOS);
   fChain->SetBranchAddress("C_Hlt1TrackAllL0Decision_Dec", &C_Hlt1TrackAllL0Decision_Dec, &b_C_Hlt1TrackAllL0Decision_Dec);
   fChain->SetBranchAddress("C_Hlt1TrackAllL0Decision_TIS", &C_Hlt1TrackAllL0Decision_TIS, &b_C_Hlt1TrackAllL0Decision_TIS);
   fChain->SetBranchAddress("C_Hlt1TrackAllL0Decision_TOS", &C_Hlt1TrackAllL0Decision_TOS, &b_C_Hlt1TrackAllL0Decision_TOS);
   fChain->SetBranchAddress("C_Hlt1TrackMuonDecision_Dec", &C_Hlt1TrackMuonDecision_Dec, &b_C_Hlt1TrackMuonDecision_Dec);
   fChain->SetBranchAddress("C_Hlt1TrackMuonDecision_TIS", &C_Hlt1TrackMuonDecision_TIS, &b_C_Hlt1TrackMuonDecision_TIS);
   fChain->SetBranchAddress("C_Hlt1TrackMuonDecision_TOS", &C_Hlt1TrackMuonDecision_TOS, &b_C_Hlt1TrackMuonDecision_TOS);
   fChain->SetBranchAddress("C_Hlt1TrackPhotonDecision_Dec", &C_Hlt1TrackPhotonDecision_Dec, &b_C_Hlt1TrackPhotonDecision_Dec);
   fChain->SetBranchAddress("C_Hlt1TrackPhotonDecision_TIS", &C_Hlt1TrackPhotonDecision_TIS, &b_C_Hlt1TrackPhotonDecision_TIS);
   fChain->SetBranchAddress("C_Hlt1TrackPhotonDecision_TOS", &C_Hlt1TrackPhotonDecision_TOS, &b_C_Hlt1TrackPhotonDecision_TOS);
   fChain->SetBranchAddress("C_Hlt1TrackMVADecision_Dec", &C_Hlt1TrackMVADecision_Dec, &b_C_Hlt1TrackMVADecision_Dec);
   fChain->SetBranchAddress("C_Hlt1TrackMVADecision_TIS", &C_Hlt1TrackMVADecision_TIS, &b_C_Hlt1TrackMVADecision_TIS);
   fChain->SetBranchAddress("C_Hlt1TrackMVADecision_TOS", &C_Hlt1TrackMVADecision_TOS, &b_C_Hlt1TrackMVADecision_TOS);
   fChain->SetBranchAddress("C_Hlt1TwoTrackMVADecision_Dec", &C_Hlt1TwoTrackMVADecision_Dec, &b_C_Hlt1TwoTrackMVADecision_Dec);
   fChain->SetBranchAddress("C_Hlt1TwoTrackMVADecision_TIS", &C_Hlt1TwoTrackMVADecision_TIS, &b_C_Hlt1TwoTrackMVADecision_TIS);
   fChain->SetBranchAddress("C_Hlt1TwoTrackMVADecision_TOS", &C_Hlt1TwoTrackMVADecision_TOS, &b_C_Hlt1TwoTrackMVADecision_TOS);
   fChain->SetBranchAddress("Lc_ETA", &Lc_ETA, &b_Lc_ETA);
   fChain->SetBranchAddress("Lc_LOKI_IPCHI2", &Lc_LOKI_IPCHI2, &b_Lc_LOKI_IPCHI2);
   fChain->SetBranchAddress("Lc_Y", &Lc_Y, &b_Lc_Y);
   fChain->SetBranchAddress("Lc_CosTheta", &Lc_CosTheta, &b_Lc_CosTheta);
   fChain->SetBranchAddress("Lc_ENDVERTEX_X", &Lc_ENDVERTEX_X, &b_Lc_ENDVERTEX_X);
   fChain->SetBranchAddress("Lc_ENDVERTEX_Y", &Lc_ENDVERTEX_Y, &b_Lc_ENDVERTEX_Y);
   fChain->SetBranchAddress("Lc_ENDVERTEX_Z", &Lc_ENDVERTEX_Z, &b_Lc_ENDVERTEX_Z);
   fChain->SetBranchAddress("Lc_ENDVERTEX_XERR", &Lc_ENDVERTEX_XERR, &b_Lc_ENDVERTEX_XERR);
   fChain->SetBranchAddress("Lc_ENDVERTEX_YERR", &Lc_ENDVERTEX_YERR, &b_Lc_ENDVERTEX_YERR);
   fChain->SetBranchAddress("Lc_ENDVERTEX_ZERR", &Lc_ENDVERTEX_ZERR, &b_Lc_ENDVERTEX_ZERR);
   fChain->SetBranchAddress("Lc_ENDVERTEX_CHI2", &Lc_ENDVERTEX_CHI2, &b_Lc_ENDVERTEX_CHI2);
   fChain->SetBranchAddress("Lc_ENDVERTEX_NDOF", &Lc_ENDVERTEX_NDOF, &b_Lc_ENDVERTEX_NDOF);
   fChain->SetBranchAddress("Lc_ENDVERTEX_COV_", Lc_ENDVERTEX_COV_, &b_Lc_ENDVERTEX_COV_);
   fChain->SetBranchAddress("Lc_OWNPV_X", &Lc_OWNPV_X, &b_Lc_OWNPV_X);
   fChain->SetBranchAddress("Lc_OWNPV_Y", &Lc_OWNPV_Y, &b_Lc_OWNPV_Y);
   fChain->SetBranchAddress("Lc_OWNPV_Z", &Lc_OWNPV_Z, &b_Lc_OWNPV_Z);
   fChain->SetBranchAddress("Lc_OWNPV_XERR", &Lc_OWNPV_XERR, &b_Lc_OWNPV_XERR);
   fChain->SetBranchAddress("Lc_OWNPV_YERR", &Lc_OWNPV_YERR, &b_Lc_OWNPV_YERR);
   fChain->SetBranchAddress("Lc_OWNPV_ZERR", &Lc_OWNPV_ZERR, &b_Lc_OWNPV_ZERR);
   fChain->SetBranchAddress("Lc_OWNPV_CHI2", &Lc_OWNPV_CHI2, &b_Lc_OWNPV_CHI2);
   fChain->SetBranchAddress("Lc_OWNPV_NDOF", &Lc_OWNPV_NDOF, &b_Lc_OWNPV_NDOF);
   fChain->SetBranchAddress("Lc_OWNPV_COV_", Lc_OWNPV_COV_, &b_Lc_OWNPV_COV_);
   fChain->SetBranchAddress("Lc_IP_OWNPV", &Lc_IP_OWNPV, &b_Lc_IP_OWNPV);
   fChain->SetBranchAddress("Lc_IPCHI2_OWNPV", &Lc_IPCHI2_OWNPV, &b_Lc_IPCHI2_OWNPV);
   fChain->SetBranchAddress("Lc_FD_OWNPV", &Lc_FD_OWNPV, &b_Lc_FD_OWNPV);
   fChain->SetBranchAddress("Lc_FDCHI2_OWNPV", &Lc_FDCHI2_OWNPV, &b_Lc_FDCHI2_OWNPV);
   fChain->SetBranchAddress("Lc_DIRA_OWNPV", &Lc_DIRA_OWNPV, &b_Lc_DIRA_OWNPV);
   fChain->SetBranchAddress("Lc_ORIVX_X", &Lc_ORIVX_X, &b_Lc_ORIVX_X);
   fChain->SetBranchAddress("Lc_ORIVX_Y", &Lc_ORIVX_Y, &b_Lc_ORIVX_Y);
   fChain->SetBranchAddress("Lc_ORIVX_Z", &Lc_ORIVX_Z, &b_Lc_ORIVX_Z);
   fChain->SetBranchAddress("Lc_ORIVX_XERR", &Lc_ORIVX_XERR, &b_Lc_ORIVX_XERR);
   fChain->SetBranchAddress("Lc_ORIVX_YERR", &Lc_ORIVX_YERR, &b_Lc_ORIVX_YERR);
   fChain->SetBranchAddress("Lc_ORIVX_ZERR", &Lc_ORIVX_ZERR, &b_Lc_ORIVX_ZERR);
   fChain->SetBranchAddress("Lc_ORIVX_CHI2", &Lc_ORIVX_CHI2, &b_Lc_ORIVX_CHI2);
   fChain->SetBranchAddress("Lc_ORIVX_NDOF", &Lc_ORIVX_NDOF, &b_Lc_ORIVX_NDOF);
   fChain->SetBranchAddress("Lc_ORIVX_COV_", Lc_ORIVX_COV_, &b_Lc_ORIVX_COV_);
   fChain->SetBranchAddress("Lc_FD_ORIVX", &Lc_FD_ORIVX, &b_Lc_FD_ORIVX);
   fChain->SetBranchAddress("Lc_FDCHI2_ORIVX", &Lc_FDCHI2_ORIVX, &b_Lc_FDCHI2_ORIVX);
   fChain->SetBranchAddress("Lc_DIRA_ORIVX", &Lc_DIRA_ORIVX, &b_Lc_DIRA_ORIVX);
   fChain->SetBranchAddress("Lc_P", &Lc_P, &b_Lc_P);
   fChain->SetBranchAddress("Lc_PT", &Lc_PT, &b_Lc_PT);
   fChain->SetBranchAddress("Lc_PE", &Lc_PE, &b_Lc_PE);
   fChain->SetBranchAddress("Lc_PX", &Lc_PX, &b_Lc_PX);
   fChain->SetBranchAddress("Lc_PY", &Lc_PY, &b_Lc_PY);
   fChain->SetBranchAddress("Lc_PZ", &Lc_PZ, &b_Lc_PZ);
   fChain->SetBranchAddress("Lc_MM", &Lc_MM, &b_Lc_MM);
   fChain->SetBranchAddress("Lc_MMERR", &Lc_MMERR, &b_Lc_MMERR);
   fChain->SetBranchAddress("Lc_M", &Lc_M, &b_Lc_M);
   fChain->SetBranchAddress("Lc_ID", &Lc_ID, &b_Lc_ID);
   fChain->SetBranchAddress("Lc_TAU", &Lc_TAU, &b_Lc_TAU);
   fChain->SetBranchAddress("Lc_TAUERR", &Lc_TAUERR, &b_Lc_TAUERR);
   fChain->SetBranchAddress("Lc_TAUCHI2", &Lc_TAUCHI2, &b_Lc_TAUCHI2);
   fChain->SetBranchAddress("Lc_TMVA_BDT", &Lc_TMVA_BDT, &b_Lc_TMVA_BDT);
   fChain->SetBranchAddress("Lc_L0Global_Dec", &Lc_L0Global_Dec, &b_Lc_L0Global_Dec);
   fChain->SetBranchAddress("Lc_L0Global_TIS", &Lc_L0Global_TIS, &b_Lc_L0Global_TIS);
   fChain->SetBranchAddress("Lc_L0Global_TOS", &Lc_L0Global_TOS, &b_Lc_L0Global_TOS);
   fChain->SetBranchAddress("Lc_Hlt1Global_Dec", &Lc_Hlt1Global_Dec, &b_Lc_Hlt1Global_Dec);
   fChain->SetBranchAddress("Lc_Hlt1Global_TIS", &Lc_Hlt1Global_TIS, &b_Lc_Hlt1Global_TIS);
   fChain->SetBranchAddress("Lc_Hlt1Global_TOS", &Lc_Hlt1Global_TOS, &b_Lc_Hlt1Global_TOS);
   fChain->SetBranchAddress("Lc_Hlt1Phys_Dec", &Lc_Hlt1Phys_Dec, &b_Lc_Hlt1Phys_Dec);
   fChain->SetBranchAddress("Lc_Hlt1Phys_TIS", &Lc_Hlt1Phys_TIS, &b_Lc_Hlt1Phys_TIS);
   fChain->SetBranchAddress("Lc_Hlt1Phys_TOS", &Lc_Hlt1Phys_TOS, &b_Lc_Hlt1Phys_TOS);
   fChain->SetBranchAddress("Lc_L0ElectronDecision_Dec", &Lc_L0ElectronDecision_Dec, &b_Lc_L0ElectronDecision_Dec);
   fChain->SetBranchAddress("Lc_L0ElectronDecision_TIS", &Lc_L0ElectronDecision_TIS, &b_Lc_L0ElectronDecision_TIS);
   fChain->SetBranchAddress("Lc_L0ElectronDecision_TOS", &Lc_L0ElectronDecision_TOS, &b_Lc_L0ElectronDecision_TOS);
   fChain->SetBranchAddress("Lc_L0PhotonDecision_Dec", &Lc_L0PhotonDecision_Dec, &b_Lc_L0PhotonDecision_Dec);
   fChain->SetBranchAddress("Lc_L0PhotonDecision_TIS", &Lc_L0PhotonDecision_TIS, &b_Lc_L0PhotonDecision_TIS);
   fChain->SetBranchAddress("Lc_L0PhotonDecision_TOS", &Lc_L0PhotonDecision_TOS, &b_Lc_L0PhotonDecision_TOS);
   fChain->SetBranchAddress("Lc_L0HadronDecision_Dec", &Lc_L0HadronDecision_Dec, &b_Lc_L0HadronDecision_Dec);
   fChain->SetBranchAddress("Lc_L0HadronDecision_TIS", &Lc_L0HadronDecision_TIS, &b_Lc_L0HadronDecision_TIS);
   fChain->SetBranchAddress("Lc_L0HadronDecision_TOS", &Lc_L0HadronDecision_TOS, &b_Lc_L0HadronDecision_TOS);
   fChain->SetBranchAddress("Lc_L0MuonDecision_Dec", &Lc_L0MuonDecision_Dec, &b_Lc_L0MuonDecision_Dec);
   fChain->SetBranchAddress("Lc_L0MuonDecision_TIS", &Lc_L0MuonDecision_TIS, &b_Lc_L0MuonDecision_TIS);
   fChain->SetBranchAddress("Lc_L0MuonDecision_TOS", &Lc_L0MuonDecision_TOS, &b_Lc_L0MuonDecision_TOS);
   fChain->SetBranchAddress("Lc_L0MuonHighDecision_Dec", &Lc_L0MuonHighDecision_Dec, &b_Lc_L0MuonHighDecision_Dec);
   fChain->SetBranchAddress("Lc_L0MuonHighDecision_TIS", &Lc_L0MuonHighDecision_TIS, &b_Lc_L0MuonHighDecision_TIS);
   fChain->SetBranchAddress("Lc_L0MuonHighDecision_TOS", &Lc_L0MuonHighDecision_TOS, &b_Lc_L0MuonHighDecision_TOS);
   fChain->SetBranchAddress("Lc_L0DiMuonDecision_Dec", &Lc_L0DiMuonDecision_Dec, &b_Lc_L0DiMuonDecision_Dec);
   fChain->SetBranchAddress("Lc_L0DiMuonDecision_TIS", &Lc_L0DiMuonDecision_TIS, &b_Lc_L0DiMuonDecision_TIS);
   fChain->SetBranchAddress("Lc_L0DiMuonDecision_TOS", &Lc_L0DiMuonDecision_TOS, &b_Lc_L0DiMuonDecision_TOS);
   fChain->SetBranchAddress("Lc_Hlt1TrackAllL0Decision_Dec", &Lc_Hlt1TrackAllL0Decision_Dec, &b_Lc_Hlt1TrackAllL0Decision_Dec);
   fChain->SetBranchAddress("Lc_Hlt1TrackAllL0Decision_TIS", &Lc_Hlt1TrackAllL0Decision_TIS, &b_Lc_Hlt1TrackAllL0Decision_TIS);
   fChain->SetBranchAddress("Lc_Hlt1TrackAllL0Decision_TOS", &Lc_Hlt1TrackAllL0Decision_TOS, &b_Lc_Hlt1TrackAllL0Decision_TOS);
   fChain->SetBranchAddress("Lc_Hlt1TrackMuonDecision_Dec", &Lc_Hlt1TrackMuonDecision_Dec, &b_Lc_Hlt1TrackMuonDecision_Dec);
   fChain->SetBranchAddress("Lc_Hlt1TrackMuonDecision_TIS", &Lc_Hlt1TrackMuonDecision_TIS, &b_Lc_Hlt1TrackMuonDecision_TIS);
   fChain->SetBranchAddress("Lc_Hlt1TrackMuonDecision_TOS", &Lc_Hlt1TrackMuonDecision_TOS, &b_Lc_Hlt1TrackMuonDecision_TOS);
   fChain->SetBranchAddress("Lc_Hlt1TrackPhotonDecision_Dec", &Lc_Hlt1TrackPhotonDecision_Dec, &b_Lc_Hlt1TrackPhotonDecision_Dec);
   fChain->SetBranchAddress("Lc_Hlt1TrackPhotonDecision_TIS", &Lc_Hlt1TrackPhotonDecision_TIS, &b_Lc_Hlt1TrackPhotonDecision_TIS);
   fChain->SetBranchAddress("Lc_Hlt1TrackPhotonDecision_TOS", &Lc_Hlt1TrackPhotonDecision_TOS, &b_Lc_Hlt1TrackPhotonDecision_TOS);
   fChain->SetBranchAddress("Lc_Hlt1TrackMVADecision_Dec", &Lc_Hlt1TrackMVADecision_Dec, &b_Lc_Hlt1TrackMVADecision_Dec);
   fChain->SetBranchAddress("Lc_Hlt1TrackMVADecision_TIS", &Lc_Hlt1TrackMVADecision_TIS, &b_Lc_Hlt1TrackMVADecision_TIS);
   fChain->SetBranchAddress("Lc_Hlt1TrackMVADecision_TOS", &Lc_Hlt1TrackMVADecision_TOS, &b_Lc_Hlt1TrackMVADecision_TOS);
   fChain->SetBranchAddress("Lc_Hlt1TwoTrackMVADecision_Dec", &Lc_Hlt1TwoTrackMVADecision_Dec, &b_Lc_Hlt1TwoTrackMVADecision_Dec);
   fChain->SetBranchAddress("Lc_Hlt1TwoTrackMVADecision_TIS", &Lc_Hlt1TwoTrackMVADecision_TIS, &b_Lc_Hlt1TwoTrackMVADecision_TIS);
   fChain->SetBranchAddress("Lc_Hlt1TwoTrackMVADecision_TOS", &Lc_Hlt1TwoTrackMVADecision_TOS, &b_Lc_Hlt1TwoTrackMVADecision_TOS);
   fChain->SetBranchAddress("Xic_ETA", &Xic_ETA, &b_Xic_ETA);
   fChain->SetBranchAddress("Xic_LOKI_IPCHI2", &Xic_LOKI_IPCHI2, &b_Xic_LOKI_IPCHI2);
   fChain->SetBranchAddress("Xic_Y", &Xic_Y, &b_Xic_Y);
   fChain->SetBranchAddress("Xic_CosTheta", &Xic_CosTheta, &b_Xic_CosTheta);
   fChain->SetBranchAddress("Xic_ENDVERTEX_X", &Xic_ENDVERTEX_X, &b_Xic_ENDVERTEX_X);
   fChain->SetBranchAddress("Xic_ENDVERTEX_Y", &Xic_ENDVERTEX_Y, &b_Xic_ENDVERTEX_Y);
   fChain->SetBranchAddress("Xic_ENDVERTEX_Z", &Xic_ENDVERTEX_Z, &b_Xic_ENDVERTEX_Z);
   fChain->SetBranchAddress("Xic_ENDVERTEX_XERR", &Xic_ENDVERTEX_XERR, &b_Xic_ENDVERTEX_XERR);
   fChain->SetBranchAddress("Xic_ENDVERTEX_YERR", &Xic_ENDVERTEX_YERR, &b_Xic_ENDVERTEX_YERR);
   fChain->SetBranchAddress("Xic_ENDVERTEX_ZERR", &Xic_ENDVERTEX_ZERR, &b_Xic_ENDVERTEX_ZERR);
   fChain->SetBranchAddress("Xic_ENDVERTEX_CHI2", &Xic_ENDVERTEX_CHI2, &b_Xic_ENDVERTEX_CHI2);
   fChain->SetBranchAddress("Xic_ENDVERTEX_NDOF", &Xic_ENDVERTEX_NDOF, &b_Xic_ENDVERTEX_NDOF);
   fChain->SetBranchAddress("Xic_ENDVERTEX_COV_", Xic_ENDVERTEX_COV_, &b_Xic_ENDVERTEX_COV_);
   fChain->SetBranchAddress("Xic_OWNPV_X", &Xic_OWNPV_X, &b_Xic_OWNPV_X);
   fChain->SetBranchAddress("Xic_OWNPV_Y", &Xic_OWNPV_Y, &b_Xic_OWNPV_Y);
   fChain->SetBranchAddress("Xic_OWNPV_Z", &Xic_OWNPV_Z, &b_Xic_OWNPV_Z);
   fChain->SetBranchAddress("Xic_OWNPV_XERR", &Xic_OWNPV_XERR, &b_Xic_OWNPV_XERR);
   fChain->SetBranchAddress("Xic_OWNPV_YERR", &Xic_OWNPV_YERR, &b_Xic_OWNPV_YERR);
   fChain->SetBranchAddress("Xic_OWNPV_ZERR", &Xic_OWNPV_ZERR, &b_Xic_OWNPV_ZERR);
   fChain->SetBranchAddress("Xic_OWNPV_CHI2", &Xic_OWNPV_CHI2, &b_Xic_OWNPV_CHI2);
   fChain->SetBranchAddress("Xic_OWNPV_NDOF", &Xic_OWNPV_NDOF, &b_Xic_OWNPV_NDOF);
   fChain->SetBranchAddress("Xic_OWNPV_COV_", Xic_OWNPV_COV_, &b_Xic_OWNPV_COV_);
   fChain->SetBranchAddress("Xic_IP_OWNPV", &Xic_IP_OWNPV, &b_Xic_IP_OWNPV);
   fChain->SetBranchAddress("Xic_IPCHI2_OWNPV", &Xic_IPCHI2_OWNPV, &b_Xic_IPCHI2_OWNPV);
   fChain->SetBranchAddress("Xic_FD_OWNPV", &Xic_FD_OWNPV, &b_Xic_FD_OWNPV);
   fChain->SetBranchAddress("Xic_FDCHI2_OWNPV", &Xic_FDCHI2_OWNPV, &b_Xic_FDCHI2_OWNPV);
   fChain->SetBranchAddress("Xic_DIRA_OWNPV", &Xic_DIRA_OWNPV, &b_Xic_DIRA_OWNPV);
   fChain->SetBranchAddress("Xic_ORIVX_X", &Xic_ORIVX_X, &b_Xic_ORIVX_X);
   fChain->SetBranchAddress("Xic_ORIVX_Y", &Xic_ORIVX_Y, &b_Xic_ORIVX_Y);
   fChain->SetBranchAddress("Xic_ORIVX_Z", &Xic_ORIVX_Z, &b_Xic_ORIVX_Z);
   fChain->SetBranchAddress("Xic_ORIVX_XERR", &Xic_ORIVX_XERR, &b_Xic_ORIVX_XERR);
   fChain->SetBranchAddress("Xic_ORIVX_YERR", &Xic_ORIVX_YERR, &b_Xic_ORIVX_YERR);
   fChain->SetBranchAddress("Xic_ORIVX_ZERR", &Xic_ORIVX_ZERR, &b_Xic_ORIVX_ZERR);
   fChain->SetBranchAddress("Xic_ORIVX_CHI2", &Xic_ORIVX_CHI2, &b_Xic_ORIVX_CHI2);
   fChain->SetBranchAddress("Xic_ORIVX_NDOF", &Xic_ORIVX_NDOF, &b_Xic_ORIVX_NDOF);
   fChain->SetBranchAddress("Xic_ORIVX_COV_", Xic_ORIVX_COV_, &b_Xic_ORIVX_COV_);
   fChain->SetBranchAddress("Xic_FD_ORIVX", &Xic_FD_ORIVX, &b_Xic_FD_ORIVX);
   fChain->SetBranchAddress("Xic_FDCHI2_ORIVX", &Xic_FDCHI2_ORIVX, &b_Xic_FDCHI2_ORIVX);
   fChain->SetBranchAddress("Xic_DIRA_ORIVX", &Xic_DIRA_ORIVX, &b_Xic_DIRA_ORIVX);
   fChain->SetBranchAddress("Xic_P", &Xic_P, &b_Xic_P);
   fChain->SetBranchAddress("Xic_PT", &Xic_PT, &b_Xic_PT);
   fChain->SetBranchAddress("Xic_PE", &Xic_PE, &b_Xic_PE);
   fChain->SetBranchAddress("Xic_PX", &Xic_PX, &b_Xic_PX);
   fChain->SetBranchAddress("Xic_PY", &Xic_PY, &b_Xic_PY);
   fChain->SetBranchAddress("Xic_PZ", &Xic_PZ, &b_Xic_PZ);
   fChain->SetBranchAddress("Xic_MM", &Xic_MM, &b_Xic_MM);
   fChain->SetBranchAddress("Xic_MMERR", &Xic_MMERR, &b_Xic_MMERR);
   fChain->SetBranchAddress("Xic_M", &Xic_M, &b_Xic_M);
   fChain->SetBranchAddress("Xic_ID", &Xic_ID, &b_Xic_ID);
   fChain->SetBranchAddress("Xic_TAU", &Xic_TAU, &b_Xic_TAU);
   fChain->SetBranchAddress("Xic_TAUERR", &Xic_TAUERR, &b_Xic_TAUERR);
   fChain->SetBranchAddress("Xic_TAUCHI2", &Xic_TAUCHI2, &b_Xic_TAUCHI2);
   fChain->SetBranchAddress("Xic_TMVA_BDT", &Xic_TMVA_BDT, &b_Xic_TMVA_BDT);
   fChain->SetBranchAddress("nCandidate", &nCandidate, &b_nCandidate);
   fChain->SetBranchAddress("totCandidates", &totCandidates, &b_totCandidates);
   fChain->SetBranchAddress("EventInSequence", &EventInSequence, &b_EventInSequence);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("BCID", &BCID, &b_BCID);
   fChain->SetBranchAddress("BCType", &BCType, &b_BCType);
   fChain->SetBranchAddress("OdinTCK", &OdinTCK, &b_OdinTCK);
   fChain->SetBranchAddress("L0DUTCK", &L0DUTCK, &b_L0DUTCK);
   fChain->SetBranchAddress("HLT1TCK", &HLT1TCK, &b_HLT1TCK);
   fChain->SetBranchAddress("HLT2TCK", &HLT2TCK, &b_HLT2TCK);
   fChain->SetBranchAddress("GpsTime", &GpsTime, &b_GpsTime);
   fChain->SetBranchAddress("Polarity", &Polarity, &b_Polarity);
   fChain->SetBranchAddress("L0Data_DiMuon_Pt", &L0Data_DiMuon_Pt, &b_L0Data_DiMuon_Pt);
   fChain->SetBranchAddress("L0Data_DiMuonProd_Pt1Pt2", &L0Data_DiMuonProd_Pt1Pt2, &b_L0Data_DiMuonProd_Pt1Pt2);
   fChain->SetBranchAddress("L0Data_Electron_Et", &L0Data_Electron_Et, &b_L0Data_Electron_Et);
   fChain->SetBranchAddress("L0Data_GlobalPi0_Et", &L0Data_GlobalPi0_Et, &b_L0Data_GlobalPi0_Et);
   fChain->SetBranchAddress("L0Data_Hadron_Et", &L0Data_Hadron_Et, &b_L0Data_Hadron_Et);
   fChain->SetBranchAddress("L0Data_LocalPi0_Et", &L0Data_LocalPi0_Et, &b_L0Data_LocalPi0_Et);
   fChain->SetBranchAddress("L0Data_Muon1_Pt", &L0Data_Muon1_Pt, &b_L0Data_Muon1_Pt);
   fChain->SetBranchAddress("L0Data_Muon1_Sgn", &L0Data_Muon1_Sgn, &b_L0Data_Muon1_Sgn);
   fChain->SetBranchAddress("L0Data_Muon2_Pt", &L0Data_Muon2_Pt, &b_L0Data_Muon2_Pt);
   fChain->SetBranchAddress("L0Data_Muon2_Sgn", &L0Data_Muon2_Sgn, &b_L0Data_Muon2_Sgn);
   fChain->SetBranchAddress("L0Data_Muon3_Pt", &L0Data_Muon3_Pt, &b_L0Data_Muon3_Pt);
   fChain->SetBranchAddress("L0Data_Muon3_Sgn", &L0Data_Muon3_Sgn, &b_L0Data_Muon3_Sgn);
   fChain->SetBranchAddress("L0Data_PUHits_Mult", &L0Data_PUHits_Mult, &b_L0Data_PUHits_Mult);
   fChain->SetBranchAddress("L0Data_PUPeak1_Cont", &L0Data_PUPeak1_Cont, &b_L0Data_PUPeak1_Cont);
   fChain->SetBranchAddress("L0Data_PUPeak1_Pos", &L0Data_PUPeak1_Pos, &b_L0Data_PUPeak1_Pos);
   fChain->SetBranchAddress("L0Data_PUPeak2_Cont", &L0Data_PUPeak2_Cont, &b_L0Data_PUPeak2_Cont);
   fChain->SetBranchAddress("L0Data_PUPeak2_Pos", &L0Data_PUPeak2_Pos, &b_L0Data_PUPeak2_Pos);
   fChain->SetBranchAddress("L0Data_Photon_Et", &L0Data_Photon_Et, &b_L0Data_Photon_Et);
   fChain->SetBranchAddress("L0Data_Spd_Mult", &L0Data_Spd_Mult, &b_L0Data_Spd_Mult);
   fChain->SetBranchAddress("L0Data_Sum_Et", &L0Data_Sum_Et, &b_L0Data_Sum_Et);
   fChain->SetBranchAddress("L0Data_Sum_Et,Next1", &L0Data_Sum_Et_Next1, &b_L0Data_Sum_Et_Next1);
   fChain->SetBranchAddress("L0Data_Sum_Et,Next2", &L0Data_Sum_Et_Next2, &b_L0Data_Sum_Et_Next2);
   fChain->SetBranchAddress("L0Data_Sum_Et,Prev1", &L0Data_Sum_Et_Prev1, &b_L0Data_Sum_Et_Prev1);
   fChain->SetBranchAddress("L0Data_Sum_Et,Prev2", &L0Data_Sum_Et_Prev2, &b_L0Data_Sum_Et_Prev2);
   fChain->SetBranchAddress("nPV", &nPV, &b_nPV);
   fChain->SetBranchAddress("PVX", PVX, &b_PVX);
   fChain->SetBranchAddress("PVY", PVY, &b_PVY);
   fChain->SetBranchAddress("PVZ", PVZ, &b_PVZ);
   fChain->SetBranchAddress("PVXERR", PVXERR, &b_PVXERR);
   fChain->SetBranchAddress("PVYERR", PVYERR, &b_PVYERR);
   fChain->SetBranchAddress("PVZERR", PVZERR, &b_PVZERR);
   fChain->SetBranchAddress("PVCHI2", PVCHI2, &b_PVCHI2);
   fChain->SetBranchAddress("PVNDOF", PVNDOF, &b_PVNDOF);
   fChain->SetBranchAddress("PVNTRACKS", PVNTRACKS, &b_PVNTRACKS);
   fChain->SetBranchAddress("nPVs", &nPVs, &b_nPVs);
   fChain->SetBranchAddress("nTracks", &nTracks, &b_nTracks);
   fChain->SetBranchAddress("nLongTracks", &nLongTracks, &b_nLongTracks);
   fChain->SetBranchAddress("nDownstreamTracks", &nDownstreamTracks, &b_nDownstreamTracks);
   fChain->SetBranchAddress("nUpstreamTracks", &nUpstreamTracks, &b_nUpstreamTracks);
   fChain->SetBranchAddress("nVeloTracks", &nVeloTracks, &b_nVeloTracks);
   fChain->SetBranchAddress("nTTracks", &nTTracks, &b_nTTracks);
   fChain->SetBranchAddress("nBackTracks", &nBackTracks, &b_nBackTracks);
   fChain->SetBranchAddress("nRich1Hits", &nRich1Hits, &b_nRich1Hits);
   fChain->SetBranchAddress("nRich2Hits", &nRich2Hits, &b_nRich2Hits);
   fChain->SetBranchAddress("nVeloClusters", &nVeloClusters, &b_nVeloClusters);
   fChain->SetBranchAddress("nITClusters", &nITClusters, &b_nITClusters);
   fChain->SetBranchAddress("nTTClusters", &nTTClusters, &b_nTTClusters);
   fChain->SetBranchAddress("nOTClusters", &nOTClusters, &b_nOTClusters);
   fChain->SetBranchAddress("nSPDHits", &nSPDHits, &b_nSPDHits);
   fChain->SetBranchAddress("nMuonCoordsS0", &nMuonCoordsS0, &b_nMuonCoordsS0);
   fChain->SetBranchAddress("nMuonCoordsS1", &nMuonCoordsS1, &b_nMuonCoordsS1);
   fChain->SetBranchAddress("nMuonCoordsS2", &nMuonCoordsS2, &b_nMuonCoordsS2);
   fChain->SetBranchAddress("nMuonCoordsS3", &nMuonCoordsS3, &b_nMuonCoordsS3);
   fChain->SetBranchAddress("nMuonCoordsS4", &nMuonCoordsS4, &b_nMuonCoordsS4);
   fChain->SetBranchAddress("nMuonTracks", &nMuonTracks, &b_nMuonTracks);
   Notify();
}

Bool_t LcXic_Class::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void LcXic_Class::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t LcXic_Class::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef LcXic_Class_cxx
