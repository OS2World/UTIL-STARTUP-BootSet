# bootset.mak
# Created by IBM WorkFrame/2 MakeMake at 0:45:50 on 26 Mar 1998
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Link::Linker

.SUFFIXES: .cpp .obj

.all: \
    .\bootset.exe

.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Tx /Ti /Gm /Tm /C %s

{D:\source\c\bootset}.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Tx /Ti /Gm /Tm /C %s

.\bootset.exe: \
    .\bootset.obj \
    {$(LIB)}STVIOD.LIB \
    {$(LIB)}STSTCD.LIB \
    {$(LIB)}BOOTSET.DEF
    @echo " Link::Linker "
    icc.exe @<<
     /B" /de"
     /Febootset.exe
     STVIOD.LIB
     STSTCD.LIB
     BOOTSET.DEF
     .\bootset.obj
<<
     MC bootset.ver

.\bootset.obj: \
    .\bootset.cpp \
    {.\bootset;$(INCLUDE);}bootset.h \
    {.\bootset;$(INCLUDE);}english.h
