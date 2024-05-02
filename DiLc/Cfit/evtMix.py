from ROOT import *
from array import array

f = TFile('/afs/ihep.ac.cn/users/g/gaoze/private/workfs/DiLc/datafiles/XiccTuple_sw.root')
t = f.Get("DecayTree")
nEntries = t.GetEntries()

"""
Book new file/new Tree to add Branch
"""
newfile = TFile("XiccTuple_MixM.root","RECREATE")
newtree = t.CloneTree(-1)

# B_MixM
C_MixM = array( 'f', [ 0 ] )
newBranch = newtree.Branch( "C_MixM", C_MixM, "C_MixM/F" )

Lc_Vec = TLorentzVector()
LcBar_Vec    = TLorentzVector()

CM_Vec = TLorentzVector()

for i in range( nEntries-10 ):
    t.GetEntry(i)

    Lc_Vec.SetPxPyPzE( t.Lc_PX, t.Lc_PY, t.Lc_PZ, t.Lc_PE )

    t.GetEntry(i+10)
    LcBar_Vec.SetPxPyPzE( t.LcBar_PX, t.LcBar_PY, t.LcBar_PZ, t.LcBar_PE )
    
    CM_Vec = Lc_Vec + LcBar_Vec

    C_MixM[0] = CM_Vec.M()
        
    newBranch.Fill()

newtree.Write()
newfile.Close()


