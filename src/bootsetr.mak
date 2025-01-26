# Created by IBM WorkFrame/2 MakeMake at 0:11:08 on 18 Mar 1996
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Link::Linker

.SUFFIXES: .CPP .obj

.all: \
    .\bootset.exe

.CPP.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /Gm /Fo"%|dpfF.obj" /C %s

.\BootSet.Exe: \
    .\BOOTSET.obj \
    {$(LIB)}STVIOR.LIB \
    {$(LIB)}STSTCR.LIB \
    {$(LIB)}BOOTSET.DEF
    @echo " Link::Linker "
    icc.exe @<<

     /B" /nodeb /optfunc /packd /exepack:1"
     /Fe.\bootset.exe
     STVIOR.LIB
     STSTCR.LIB
     BOOTSET.DEF
     .\BOOTSET.obj
<<
    MC BOOTSET.VER

.\BOOTSET.obj: \
    .\BOOTSET.CPP
