# BSEDIT.MAK
# Created by IBM WorkFrame/2 MakeMake at 15:21:10 on 31 Mar 1998
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Link::Linker

.SUFFIXES: .cpp .obj .pdb 

.all: \
    .\BSEDIT.EXE

.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Tx /Ti /Gm /Tm /Fb /C %s

.\BSEDIT.EXE: \
    .\bsedit.obj \
    {$(LIB)}stviod.lib \
    {$(LIB)}ststcd.lib \
    {$(LIB)}bsedit.def
    @echo " Link::Linker "
    icc.exe @<<
     /B" /de /nop"
     /FeBSEDIT.EXE 
     stviod.lib 
     ststcd.lib 
     bsedit.def
     .\bsedit.obj
<<
     mc bsedit.ver

.\bsedit.obj: \
    .\bsedit.cpp \
    {.\BOOTSET;$(INCLUDE);}bootset.h \
    {.\BOOTSET;$(INCLUDE);}english.h
