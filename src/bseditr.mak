# bootset.mak
# Created by IBM WorkFrame/2 MakeMake at 0:45:50 on 26 Mar 1998
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Link::Linker

.SUFFIXES: .cpp .obj

.all: \
    .\bsedit.exe

.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Gm /Fo"%|dpfF.obj" /C %s

{D:\source\c\bootset}.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Ss /Tx /Ti /Gm /Tm /C %s

.\bsedit.exe: \
    .\bsedit.obj \
    {$(LIB)}STVIOR.LIB \
    {$(LIB)}STSTCR.LIB \
    {$(LIB)}bsedit.DEF
    @echo " Link::Linker "
    icc.exe @<<
     /B" /nodeb /optfunc /packd /exepack:1"
     /Febsedit.exe
     STVIOR.LIB
     STSTCR.LIB
     bsedit.DEF
     .\bsedit.obj
<<
     MC bsedit.ver

.\bootset.obj: \
    .\bsedit.cpp \
    {.\bootset;$(INCLUDE);}bootset.h \
    {.\bootset;$(INCLUDE);}english.h

