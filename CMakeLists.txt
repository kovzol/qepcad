# Author: petter.strandmark@gmail.com (Petter Strandmark)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)
PROJECT(QEPCAD C CXX)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Change the default build type from Debug to Release, while still
# supporting overriding the build type.
IF (NOT CMAKE_BUILD_TYPE)
  MESSAGE("-- No build type specified; defaulting to CMAKE_BUILD_TYPE=Release.")
  SET(CMAKE_BUILD_TYPE Release CACHE STRING
    "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel."
    FORCE)
ENDIF (NOT CMAKE_BUILD_TYPE)

IF (MSVC)
  ADD_DEFINITIONS("-D__STDC__=1")
  # unreferenced label
  ADD_DEFINITIONS("/wd4102")
ENDIF (MSVC)

FILE(GLOB SACLIB_HEADERS ${CMAKE_SOURCE_DIR}/saclib/include/*.h)
FILE(GLOB SACLIB_SOURCE ${CMAKE_SOURCE_DIR}/saclib/src/*.c)

SET(QEPCAD_LIB_SOURCE
	${CMAKE_SOURCE_DIR}/qesource/source/db/AFCSBMDB.c
	${CMAKE_SOURCE_DIR}/qesource/source/db/AFPNIPDB.c
	${CMAKE_SOURCE_DIR}/qesource/source/db/AFUPGCDB.c
	${CMAKE_SOURCE_DIR}/qesource/source/db/AFUPSFNDB.c
	${CMAKE_SOURCE_DIR}/qesource/source/db/DBADD.c
	${CMAKE_SOURCE_DIR}/qesource/source/db/DBSRCH.c
	${CMAKE_SOURCE_DIR}/qesource/source/db/DBSTATWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/db/FNDTSDB.c
	${CMAKE_SOURCE_DIR}/qesource/source/db/GETRPDB.c
	${CMAKE_SOURCE_DIR}/qesource/source/db/IPFACDB.c
	${CMAKE_SOURCE_DIR}/qesource/source/db/MODCRDB.c
	${CMAKE_SOURCE_DIR}/qesource/source/db/SUBSTDB.c
	${CMAKE_SOURCE_DIR}/qesource/source/db/SINGULAR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/OW.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/AFLWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/AFPDWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/AFUPRWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/AFWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/ATOMFLWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/ATOMFRDR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/ATOMFWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/BKSP.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/CATTRNRDR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/CATTRNWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/CELLRDR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/CELLWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/CELLSWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/COMMNT.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/COMMNTRD.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/CONWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/CREAD.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/CWRITE.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/DESIREDRDR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/DESIREDWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/DIELOC.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/DISCONWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/DNFWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/DNFLPWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/DNFLWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/DSTATWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/FGWRITE.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/FILINE.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/FREADR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/FWRITE.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/GETWORD.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/GREADR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/IPLDWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/IPLLDWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/IPLLDWRMOD.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/IUPRWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/LABELWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/LGOPRDR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/LGOPWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/PARENTWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/PCADWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/PCADSWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/PIMPTBLWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/PLABELWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/PRODWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/QFFLPWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/QFFLWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/QFFRDR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/QFFWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/QFRDR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/QFWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/RLOPRDR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/RLOPWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/SAMPLEWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/SIGNLWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/SIGNWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/STACKMWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/STATWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/TAB.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/TRMODEWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/TRUTHWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/VLREADR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/VREADR.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/VWRITE.c
	${CMAKE_SOURCE_DIR}/qesource/source/io/XREADR.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/BEGINQEPCAD.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/ENDQEPCAD.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/INITCTRL.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/INITDB.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/INITIO.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/INITSTAT.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/INITSYS.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/INPUTRD.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/MAIN.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/PRINTBANNER.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/QEPCAD.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/SETUPSYS.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/FAIL.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/data.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/QEPCADauto.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/qepcadcls.c
	${CMAKE_SOURCE_DIR}/qesource/source/main/CADautoConst.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/EXPAFEQ.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/EXPAFGT.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/EXPAFGTS.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/EXPAFLT.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/EXPAFLTS.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/ISATOMF.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/NEGRLOP.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/NORMAF.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/NORMAFS.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/NORMQFF.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/PQFF.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/RMCAFS.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/RMCAON.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/RMLREOP.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/RMNOTOP.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/RMNOTOPN.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/TYPEAF.c
	${CMAKE_SOURCE_DIR}/qesource/source/normqff/TYPEQFF.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/APPEND.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/APPENDEC.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/ECLEVEL.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/EXTRACT.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/EXTRACTS.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/GROUPSAMEPJ.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/IPDSCRPRS.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/IPDSCRQE.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/IPLFAC.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/IPRESQE.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/LCM.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/LOAR.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/LUNION.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/MPOLY.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/PROJ.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/PROJCO.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/PROJHO.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/PROJLA.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/PROJMC.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/PROJMCx.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/PROJMCmod.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/PROJMCECmod.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/PROJECT.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/PROJMCEC.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/PROPCONS.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/UDEQNCONST.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/SEPLAB.c
	${CMAKE_SOURCE_DIR}/qesource/source/proj/PROJECTauto.c
	${CMAKE_SOURCE_DIR}/qesource/source/sysolve/ASSUMPTIONSRATVEVAL.c
	${CMAKE_SOURCE_DIR}/qesource/source/sysolve/CHANGEASSUMPTIONSLEVEL.c
	${CMAKE_SOURCE_DIR}/qesource/source/sysolve/COEFFSYS.c
	${CMAKE_SOURCE_DIR}/qesource/source/sysolve/EVALSYS.c
	${CMAKE_SOURCE_DIR}/qesource/source/sysolve/FINDRATCOORD.c
	${CMAKE_SOURCE_DIR}/qesource/source/sysolve/IPRSOL.c
	${CMAKE_SOURCE_DIR}/qesource/source/sysolve/LBMIPL.c
	${CMAKE_SOURCE_DIR}/qesource/source/sysolve/LOSETSBF.c
	${CMAKE_SOURCE_DIR}/qesource/source/sysolve/LPSILB.c
	${CMAKE_SOURCE_DIR}/qesource/source/sysolve/PRINTCOEFFSYSTEM.c
	${CMAKE_SOURCE_DIR}/qesource/source/sysolve/QFRCALLS.c
	${CMAKE_SOURCE_DIR}/qesource/source/sysolve/SIMPLIFYSYS.c
	${CMAKE_SOURCE_DIR}/qesource/source/sysolve/SIMPLIFYSYSLIST.c
	${CMAKE_SOURCE_DIR}/qesource/source/sysolve/SYSSOLVE.c
	${CMAKE_SOURCE_DIR}/qesource/source/sysolve/SYSTOUNNORMFORMULA.c
	${CMAKE_SOURCE_DIR}/qesource/source/sysolve/VERIFYCONSTSIGN.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/ECLI.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/ISFECLI.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/CELLNA.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/ACCCVBC.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/ACCCVBCR.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/AFCSBM.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/AFMSBM.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/AFUPLM.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/AFUPMPR.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/APEQC.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/CELLATTR.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/CELLCOMP.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/CELLSQ.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/CHCELL.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/CHOOSE.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/CHSCN.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/CONSTRUCT.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/CONVERT.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/CSSP.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/CVCOMP.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/DELINPOL.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/DELINPOLR.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/PFPRDQ.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/PPPRDQ.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/IPALLPARTIALS.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/DESCENDANT.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/DMAFUPNR.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/DSCOMP.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/EC.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/EC1.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/ECR.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/EVALUATE.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/FNDTS.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/GETRP.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/INITPCAD.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/IPFSBM.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/IPLSRP.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/ISDESIRED.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/ISPRIMIT.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/IXCOMP.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/LVCOMP.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/LPFTOLRLP.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/LPFZCALL.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/MAFDIF.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/MAFHOM.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/MAFINV.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/MAFPROD.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/MAFUPDIF.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/MAFUPEPROD.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/MAFUPGCD.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/MAFUPMON.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/MAFUPNR.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/MCELL.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/MKMUL.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/MODCR.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/MUPNR.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/NORMAL.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/NZFOPQ.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/NZFOPQR.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/PFCOICQ.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/PLPOS.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/PROPAGATE.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/QFFTEV.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/RCFAFC.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/SETTRUTHVALUE.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/SIGNB.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/SIGNL.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/SIGNP.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/SIGNP1.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/SIGNPR.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/SIMPLEQE.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/SPFRPSFT.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/SSCOMP.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/STACKMULT.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/SUBST.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/SUBSTR.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/TCHILD.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/TICAD.c
	${CMAKE_SOURCE_DIR}/qesource/source/ticad/TICADauto.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/CELLFIDX.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/ESPIWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/ESPORD.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/GETCID.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/GFPCSTAT.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/HELPFRD.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/HELPWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/INTERACT.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRAFUPBRI.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRAPPROX.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRCCS.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRCCSF.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDC.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDCC.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDCS.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDDESIRED.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDESIRED.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDF.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDFPCSTAT.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDIP.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDLFI.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDLPI.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDLV.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDNQFF.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDPC.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDPCS.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDPF.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDPJ.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDQ.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDQFF.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDSEARCH.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDSET.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDSTACK.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDTRACEA.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDTRACED.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDVL.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PREQNCONST.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRFINISH.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRGO.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRHELP.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRIPFZT.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRIGS.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRLDB.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRMCC.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PROMPT.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRPROJOP.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRQUIT.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRRMPF.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRRMPJ.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRRSP.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRSEARCH.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRSIMPLIFIER.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRSTEP.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRTCN.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRTRACEA.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRTRACED.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRUDB.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRUSEDESIRED.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRWHATIS.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/RMMPF.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/RMMPJ.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRCHPIVOT.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRDEQNCONST.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PREQNCONSTL.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRPROPEC.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/PRRESALG.c
	${CMAKE_SOURCE_DIR}/qesource/source/userint/USERINT.c
	${CMAKE_SOURCE_DIR}/qesource/source/util/CELLDEG.c
	${CMAKE_SOURCE_DIR}/qesource/source/util/CELLDIM.c
	${CMAKE_SOURCE_DIR}/qesource/source/util/MATCHWORD.c
	${CMAKE_SOURCE_DIR}/qesource/source/util/MBPROD.c
	${CMAKE_SOURCE_DIR}/qesource/source/util/MMFLR.c
	${CMAKE_SOURCE_DIR}/qesource/source/util/PLDEG.c
	${CMAKE_SOURCE_DIR}/qesource/source/util/PSIMREP.c
	${CMAKE_SOURCE_DIR}/qesource/source/util/RMCONS.c
	${CMAKE_SOURCE_DIR}/qesource/source/util/RNFAF.c
	${CMAKE_SOURCE_DIR}/qesource/source/util/SVPOWR.c
	${CMAKE_SOURCE_DIR}/qesource/source/util/SVPROD.c
	${CMAKE_SOURCE_DIR}/qesource/source/util/VALIDLBL.c
	${CMAKE_SOURCE_DIR}/qesource/source/saclib/GCSI.c
	${CMAKE_SOURCE_DIR}/qesource/source/saclib/gcword.c
	${CMAKE_SOURCE_DIR}/qesource/source/saclib/IPFZT.c
	${CMAKE_SOURCE_DIR}/qesource/source/saclib/IPFZT1.c
	${CMAKE_SOURCE_DIR}/qesource/source/saclib/IPPSCT.c
	${CMAKE_SOURCE_DIR}/qesource/source/saclib/IPRNEVAL.c
	${CMAKE_SOURCE_DIR}/qesource/source/saclib/RVSPTSVSP.c
	${CMAKE_SOURCE_DIR}/qesource/source/saclib/SOSRSUBS.c
	${CMAKE_SOURCE_DIR}/qesource/source/saclib/SOSRSUPS.c
	${CMAKE_SOURCE_DIR}/qesource/source/saclib/SUBSET.c
	)

SET(ADJ2D_LIB_SOURCE
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/testfunc.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/ADJ_2D.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/ADJ_2D_PART.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/AD2DC_CONS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/AD2DS_CONS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/LDCOEFMASK.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/VECTOR_LTEQ.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/VECTOR_SUM.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/VECTOR_DIF_S.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/VECTOR_SEMI_COMP.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/VECTOR_S_PROD.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/VECTOR_NEG.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/SUM_NORM_SP.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/CWD_VECTOR_Q.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/ZERO_VECTOR.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/EQUAL_ON_ONES.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/ADD_2_SOL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/Mystery_f.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/ADJ_2D_CONSTRUCT.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/P1.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/P2.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/P3.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/P4.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/ADJ_2D1_COMPLETE.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/ADJ_2D1.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/ADJ_2D1_SIMPLE.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/ADJ_2D1P1.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/ADJ_2D1P2.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/ADJ_2D1P3.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/VECTOR_ODD_E.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/oldadj/LLBRSPFSS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/oldadj/DNCAC.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/oldadj/LLSISS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/oldadj/RIIFACMA.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/oldadj/ACMADJ2D.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/oldadj/RIIFACMABR.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/oldadj/SPRLC.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/sac_ext/LBRNMAX.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/sac_ext/LBRNMIN.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/sac_ext/PCFE.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/sac_ext/IUPLBREVAL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/sac_ext/IPLBREVAL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/sac_ext/IUPSOPOR.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/sac_ext/IUPSOPORFIL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/sac_ext/RRCOMPSRI.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/sac_ext/ADJNNA.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/sac_ext/IBPIDFV.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/sac_ext/IPMP2.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/sac_ext/RRLBRNCOMP.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/sac_ext/IPRRILBRI.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/sac_ext/IUPTSII.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/truthbytop/TVCLOSURE1D.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/truthbytop/TVCLOSURE1DS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/truthbytop/CCTV.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/truthbytop/CTVPROPUP.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/truthbytop/TVCCOSBSVAI.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/truthbytop/GRAPHMODULE.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/truthbytop/TV2D.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/truthbytop/C1DTOEDGELIST.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/truthbytop/ADJ2DITOEL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/truthbytop/ADJGRAPHCONS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/truthbytop/CLOSURE2D.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d/truthbytop/BOUNDARY2D.c
	)

SET(NEWADJ_LIB_SOURCE
	${CMAKE_SOURCE_DIR}/qesource/extensions/newadj/HAP1.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/newadj/HAP2.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/newadj/HAP3.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/newadj/HA.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/newadj/HALDCOEFMASK.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/newadj/HAS_CONS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/newadj/HAC_CONS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/newadj/HATEST.c 
	)

SET(LIFT2D_LIB_SOURCE
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/PFSRRQ2D.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/PFSRDQ2D.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/CELLLEFTSIB.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/CELLRIGHTSIB.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/CELLSRRQ2D.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/CELLSRDQ2D.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/LIFTSRR2D.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/modHIPRRISD.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/modHIPRRID.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/modIBPRRIOAP.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/LIFTSRD2D.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/IBPRRIOAP.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/IBPRRIOAPSF.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/IBPELBRISIPR.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/IBPESISIPR.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/modIBPRRIOAPSF.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/modSIPRRISD.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/lift2D/modSIPRRID.c
	)

SET(REND_LIB_SOURCE
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/LBRNQORD.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/SSILRCRI.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/CONMIRCAD.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/PLOT_2D_CAD.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/PLOT2DCAD2FILE.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/Rend_Sample.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/Rend_Cell.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/Rend_Win.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/ADD_POINTS.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/FILL_2D.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/WRITE_PLOT.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/WRITE_PS.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/WRITE_PS_COLOR.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/WRITE_EPS.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/WRITE_PS_STANDARD.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/WRITE_PS_INTERACTIVE.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/WRITE_PS_RAJI.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/ZOOM_OUT.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/GET_COORDS.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/CH_VIEW_WIN.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/CH_VIEW_WIN_COOR.cc
	${CMAKE_SOURCE_DIR}/qesource/extensions/rend/DISP2DCAD.cc
	)

SET(SFEXT_LIB_SOURCE
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/addpol/BPOLSETS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/addpol/CFLCELLLIST.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/addpol/CLEAN_BIGLOOP.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/addpol/STRIPPED_BIGLOOP.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/addpol/ICSIGDIFFLNSC.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/addpol/KCONST.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/addpol/MINPFSETNSC.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/addpol/NEWDERIV.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/CADSCL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/CADSTATS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/CELLFINDEX.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/CSN.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/LPFZC.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/LPFZCAL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/CRCELL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/CSORCELL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/CSORCELL_MOD.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/FALSECELLWRITE.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/TRUECELLWRITE.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/LISTOFCWTV.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/NUMSOLPOINTS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/RNCADRTV.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/SPCADCBDD.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/SOLSETDIM.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/crcads/LPFOWCS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/espcad/ESPCADCRNV.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/espcad/ESPCADWRITE.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/espcad/PCAD2ESPCAD.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/espcad/ESPCADLSNC.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/ADDROOTKFUNC.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/CELLDSORT.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/ESCELLWR.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/SCAD2ESCAD.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/ESCCPLIST1.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/ESCMHSCONST1.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/ESCMINHITSET.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/ESCADCL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/LTFOCWTVMARK.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/SCFILTER.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/SCCONFLICTQ.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/ESCSLKMF.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/PARTLIST.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/SPLITBYPART.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/CLOSESTINDEX.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/VECTOR_DIF.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/SETCADTV2MARK.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/SETMARK2FMA.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/CONVEXPROP.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/EXPROP.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/UNIVPROP.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/extlang/TEMPWR.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/fewpol/CSORTSS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/fewpol/ICSIGDIFFL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/fewpol/MINPFSET.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/fewpol/SIGEQUALOL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/fewpol/PWUDSCWCP.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/fewpol/TDTOD.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMAIWRITE.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMAWRITE.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMAWRITEp.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMASMOOTH.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMA2DNF.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMA2QUNF.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMACELLEVAL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMADMQ.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FTYPEINFO.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/SETTV2FMA.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMAREAD.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMAATOMREAD.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/POLINDEX2SIGINDEX.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMALEVEL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMASORT.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMA_REMCONST.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMAOPCOMBINE.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMAWRITELATEX.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/IPDWRITELATEX.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMAWRITENEWLINE.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMAWRITEQEIN.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMAPOLLIST.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/TEST.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMATRYDISTRIBUTE.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/formula/FMASTRENGTHEN.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/CADCL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/CADFPCAD.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/CADFPCADWI.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/CELLSCPCELL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/PCELLHOWTV.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/CATV.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/CCADCON.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/CCADCONEXT.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/CCADCONFPFS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/CCADCONmod.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/CHTVQ.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/CTSEQ.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/LTFOCWTV.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/LTFOCALWTV.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/PCADCFCADC.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/PCADCINDEX.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/PCADCL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/PCADCSV.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/PCADSCANL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/PCADSTATS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/PCADWRITE.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/PLCAD.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/SCADDSCON.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/SIMPLE_CAD_INFO.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/pcadst/REPLACE_WITH_SIMPLE.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/ADD2PROJFACS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/ADD2PROJPOLS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/LIST_OF_FACS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/LPFSETINTERSECT.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/LPFSETMINUS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/PFDISCRIM.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/LLIFIP.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/PFPIPFL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/PFRES.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/PFSREORDER.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/PFSREORDERREV.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/PFSSUNION.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/PFSUFFCOEF.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/PFSUNION.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/PMINHITSETWPTS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/POLFLAB.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/PPF.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/PPFLPROJ.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/PPFMINHITSET.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/PPFMINHITSETEXT.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/PPROJFWRITE.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/PPWITHHIST.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/PROJCLOSUREMCEC.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/QPPPFL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/projpf/SEPPIVNONPIV.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/DOPFSUFF.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/NAIVEDOPFSUFF.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/ESPCADDOPFSUFF.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/NAIVESF.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/IMPCONS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/MINCOVBF.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/LISTOTA.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/LISTOETA.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/NECCONDS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/GEOTEST.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/GEOPARTII.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/CYLFORM.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/CYLIMPFORM.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/SFC1.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/SFC2.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/SFC3.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/SFC3f.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/SFC4.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/SFCFULLD.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/SFCFULLDf.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sfcons/SOLEXTINT.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sort/GIS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sort/GISL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sort/GMS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sort/GMSL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sort/GMSDS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sort/GMSDSL.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sort/BVC.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sort/BVIS.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sort/BVCI1.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/sort/BVISI1.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/minhit/MINHITSET.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/minhit/RSFHSP.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/minhit/ENUMMINHITSET.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/minhit/MINHITSETSR.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/minhit/ENUMMINHITSETSR.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/minhit/MINHITSETSRDR.c
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext/minhit/MINWHITSET.c
	)

INCLUDE_DIRECTORIES(
	${CMAKE_SOURCE_DIR}/saclib/include
	${CMAKE_SOURCE_DIR}/qesource/source
	${CMAKE_SOURCE_DIR}/qesource/extensions/adj2d
	${CMAKE_SOURCE_DIR}/qesource/extensions/sfext
	)
    
ADD_LIBRARY(saclib
	${SACLIB_HEADERS}
	${SACLIB_SOURCE}
	)
set_source_files_properties(${SACLIB_SOURCE} PROPERTIES LANGUAGE C)

ADD_LIBRARY(adj2d
	${ADJ2D_LIB_SOURCE}
	)
set_source_files_properties(${ADJ2D_LIB_SOURCE} PROPERTIES LANGUAGE CXX)
TARGET_LINK_LIBRARIES(adj2d saclib)

ADD_LIBRARY(newadj
	${NEWADJ_LIB_SOURCE}
	)
set_source_files_properties(${NEWADJ_LIB_SOURCE} PROPERTIES LANGUAGE CXX)

ADD_LIBRARY(lift2d
	${LIFT2D_LIB_SOURCE}
	)
set_source_files_properties(${LIFT2D_LIB_SOURCE} PROPERTIES LANGUAGE CXX)

ADD_LIBRARY(rend
	${REND_LIB_SOURCE}
	)
set_source_files_properties(${REND_LIB_SOURCE} PROPERTIES LANGUAGE CXX)

ADD_LIBRARY(sfext
	${SFEXT_LIB_SOURCE}
	)
set_source_files_properties(${SFEXT_LIB_SOURCE} PROPERTIES LANGUAGE CXX)

ADD_EXECUTABLE(qepcad
	${QEPCAD_LIB_SOURCE}
	${SACLIB_HEADERS}
	)
set_source_files_properties(${QEPCAD_LIB_SOURCE} PROPERTIES LANGUAGE CXX)

TARGET_LINK_LIBRARIES(qepcad saclib)
TARGET_LINK_LIBRARIES(qepcad adj2d)
TARGET_LINK_LIBRARIES(qepcad newadj)
TARGET_LINK_LIBRARIES(qepcad lift2d)
TARGET_LINK_LIBRARIES(qepcad rend)
TARGET_LINK_LIBRARIES(qepcad sfext)

IF (NOT MSVC)
	TARGET_LINK_LIBRARIES(qepcad readline rt)
ENDIF ()

configure_file(qesource/bin/qepcad.help ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/qepcad.help COPYONLY)
configure_file(qesource/default.qepcadrc ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/default.qepcadrc COPYONLY)

ENABLE_TESTING()
ADD_SUBDIRECTORY(tests)

ADD_SUBDIRECTORY(python)
