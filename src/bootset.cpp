/***************************************************************************/
/* F r e e C o d e                                                         */
/*                                                                         */
/* THIS CODE IS FREEWARE AND AS SUCH YOU ARE PERMITTED TO DO WHAT YOU WISH */
/* WITH IT. THESE PROGRAMS ARE PROVIDED AS IS WITHOUT ANY WARRANTY,        */
/* EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO FITNESS FOR ANY      */
/* PARTICULAR PURPOSE.                                                     */
/*                                                                         */
/* However, we would appriciate if you shared any enhancements to us       */
/* Please send them to www.jmast.se/free/ and we will include them in      */
/* future distributions.                                                   */
/*                                                                         */
/***************************************************************************/
/***************************************************************************/
/*                                                                         */
/*   Modul:      BOOTSET.CPP, cpp-sorce for custimized boot                */
/*                                                                         */
/*   Version:    0.165                                                     */
/*                                                                         */
/*   Tid:        960203, 981012, 27h                                       */
/*                                                                         */
/*  ---------------------------------------------------------------------  */
/*   960203:     Stole most from QL.CPP. (MA,1h)                           */
/*  ---------------------------------------------------------------------  */
/*   960204:     *A LOT*. (MA,4h)                                          */
/*  ---------------------------------------------------------------------  */
/*   960205:     Added a help screen and fixed so that a timeout of 0      */
/*               would not start the timeout thread. (MA,2h)               */
/*  ---------------------------------------------------------------------  */
/*   960221:     Changed to 16 bits Vio/Kbd and gave timeout thread a      */
/*               larger stack. (MA,2h)                                     */
/*  ---------------------------------------------------------------------  */
/*   960308:     Added all future fields to .INI file (MA, 1h).            */
/*  ---------------------------------------------------------------------  */
/*   960309:     Cursor now hidden during program exec (MA, 1h).           */
/*  ---------------------------------------------------------------------  */
/*   970504:     Added support for shareware version and fixed a few       */
/*               problems with redraws. (MA, 2h).                          */
/*  ---------------------------------------------------------------------  */
/*   970613:     Tiny waitscreen was added and color support. (MA, 2h)     */
/*  ---------------------------------------------------------------------  */
/*   970624:     Fixed some (layout) bugs. (MA, 2h)                        */
/*  ---------------------------------------------------------------------  */
/*   980325:     Moved to STVIO library. (MA, 5h)                          */
/*  ---------------------------------------------------------------------  */
/*   980325:     Hide cursor after help window. (MA, 1h)                   */
/*  ---------------------------------------------------------------------  */
/*   980715:     Just a recompile. (MA, 1h)                                */
/*  ---------------------------------------------------------------------  */
/*   980729:     Moved all texts to english.h. (MA, 2h)                    */
/*  ---------------------------------------------------------------------  */
/*   981012:     Fixed a bug in ShowUnregistered. (MA, 1h)                 */
/*  ---------------------------------------------------------------------  */
/***************************************************************************/
#define VERSION   "Release (0.165) - Oct 12, 1998"

#define INCL_DOS

#include <os2.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <process.h>

#include <stlibvio.h>
#include <stlibstc.h>

#include "bootset.h"
#include "english.h"

// Global variables
//------------------
APPLICATION     app;


/*-----------------------------------------------------------------------------
   main: Entrypoint into this program.
-----------------------------------------------------------------------------*/
int main(int argc, char *argv[])
    {

    // Check if file can be opened
    // --------------------------------------------
    if (argc == 2)
       {
       if ( !(app.stream = fopen(argv[1], "r")) )
          {
          printf ("\n\n%s - %s", IDS_BOOTSETVER, VERSION);
          printf (IDS_SETNOTFOUND, argv[1]);
          printf (IDS_PRESSANYKEY);
          VioInkey(TRUE, NULL);
          return (1);
          }
       }
    else
       {
       if ( !(app.stream = fopen(IDS_INIFILE, "r")) )
          {
          printf("\n\n%s - %s", IDS_BOOTSETVER, VERSION);
          printf(IDS_SETMUSTSPEC);
          printf(IDS_PRESSANYKEY);
          VioInkey(TRUE, NULL);
          return (1);
          }

       }

    // Save CommandLine screen and clear the screen.
    // ---------------------------------------------
    SelectList(argv[1]);
    app.bShowTime = FALSE;
    app.bExitProgram = FALSE;
    DosWaitThread(&app.tid, DCWW_WAIT);
    InitApplication(1);
    return 0;
    }


/*-----------------------------------------------------------------------------
   SelectList: .
-----------------------------------------------------------------------------*/
void SelectList(char *szINIfile)
     {
     char               szString[255];

     STVIOLISTBOX       lb;
     BOOL               bQuit = FALSE;

     PCHAR              *pszSelectList;
     PFILESETTYPE       set;

     int                iRet = 0, iCounter, iInner;

     FILE               *batch;

     HFILE              hIOCTL;
     unsigned long      ulAction;

     char               szProduct[12];
     char               cOne, cTwo;

     PSTVIO             pstv;
     PSTVIOWINDOW       pwnd, hwnd;
     int                aiRet[2];


     // Waitscreen
     fgets(szString, 255, app.stream);
     app.iWait = atoi(szString);

     // Foreground color
     fgets(szString, 255, app.stream);
     app.iForeColor = atoi(szString);

     // Background color
     fgets(szString, 255, app.stream);
     app.iBackColor = atoi(szString);

     // Timeout
     fgets(szString, 255, app.stream);
     app.iTimeOut = atoi(szString);

     // Future expansion
     fgets(szString, 255, app.stream);
     fgets(szString, 255, app.stream);
     fgets(szString, 255, app.stream);
     fgets(szString, 255, app.stream);
     fgets(szString, 255, app.stream);

     // Registration key
     fgets(szString, 255, app.stream);
     sprintf(app.szRegKey, szString);
     app.szRegKey[11] = '\0';

     // Assume registered
     app.bRegistered = TRUE;

     InitApplication(0);

     // Check for one-line keypress
     if (app.iWait == 1)
        {
        app.iOneLineRow = VioQueryCursorRow();
        app.pbOneLine = VioGetWindow(app.iOneLineRow, 1, app.iOneLineRow, 80);

        if (app.bRegistered == TRUE)
           {
           app.iOneLineCol = IDI_PRESSBFORCOL;
           VioFill(app.iOneLineRow, 1, 80, app.iForeColor, app.iBackColor);
           sprintf(szString, IDS_PRESSBFOR, IDS_BOOTSETVER);
           VioPrintString (app.iOneLineRow, 2, szString);
           }
        else
           {
           app.iOneLineCol = IDI_PRESSBFORUNREGCOL;
           VioFill(app.iOneLineRow, 1, 80, app.iForeColor, app.iBackColor);
           sprintf(szString, IDS_PRESSBFORUNREG, IDS_BOOTSETVER);
           VioPrintString (app.iOneLineRow, 2, szString);
           }

        VioSetCursorPosition(app.iOneLineRow, 9);

        // Start the thread.
        // --------------------------------------------
        if (app.iTimeOut > 0)
           app.tid = _beginthread(ExitProgram, NULL, 16738, NULL);

        app.bExitProgram = TRUE;
        app.bShowTime = TRUE;

        iRet = VioInkey(TRUE, NULL);
        VioPutWindow(app.pbOneLine, app.iOneLineRow, 1, app.iOneLineRow, 80);

        switch (iRet)
               {
               case 'B':
               case 'b':
                     app.bExitProgram = FALSE;
                     app.bShowTime = FALSE;
                     break;

               default:
                    return;
               }
        }

     // Number of menu items
     fgets(szString, 255, app.stream);
     app.iTotalSet = atoi(szString);

     set = (PFILESETTYPE)calloc(app.iTotalSet, sizeof(FILESETTYPE));
     pszSelectList = (PCHAR*)calloc(app.iTotalSet, sizeof(PCHAR));

     for (iCounter = 0; iCounter < app.iTotalSet; iCounter++)
         {
         fgets(szString, 255, app.stream);
         szString[strlen(szString) - 1] = '\0';
         sprintf(set[iCounter].szTitle, " %s ", szString);

         pszSelectList[iCounter] = set[iCounter].szTitle;

         fgets(szString, 255, app.stream);
         set[iCounter].bReboot = atoi(szString);

         fgets(szString, 255, app.stream);
         set[iCounter].iCommand = atoi(szString);

         for (iInner = 0; iInner < set[iCounter].iCommand; iInner++)
             {
             fgets(szString, 255, app.stream);
             sprintf(set[iCounter].szCommand[iInner], szString);
             }
         }

     // Draw the window for BootSet fullscreen
     pstv = VioInit(-1, -1);

     VioSetGlobal(pstv, TRUE, 255, TRUE, TRUE, 30,
                  app.iForeColor, app.iBackColor,
                  app.iForeColor, app.iBackColor,
                  app.iForeColor, app.iBackColor,
                  app.iBackColor, app.iForeColor);

     sprintf(szString, "%s - %s", IDS_BOOTSETVER, IDS_COPYRIGHT);
     VioDesktop(pstv, szString, 177, TRUE);

     VioStatusPrint(pstv, 2, 1, FALSE, IDS_STATUSKEYS);

     if (app.bRegistered == TRUE)
        sprintf(szString, "%s", IDS_BOOTSETVER);
     else
        sprintf(szString, "%s - %s", IDS_BOOTSETVER, IDS_UNREG);

     app.pmainWnd = VioOpenStandardWindow(pstv, 3, 20, 20, 40, szString);

     VioPrint(app.pmainWnd, 18, 3, IDS_WINDOWKEYS);
     VioFrame(app.pmainWnd, "", 2, 2, 15, 35, 0);

     // If we went strait into the fullscreen
     if (app.iWait == 0)
        {
        // Start the thread.
        // --------------------------------------------
        if (app.iTimeOut > 0)
           app.tid = _beginthread(ExitProgram, NULL, 16738, NULL);

        app.bExitProgram = TRUE;
        app.bShowTime = TRUE;
        }

     VioSetCursor(app.pmainWnd, 0, 0, FALSE);
     // Prepare for the listbox.
     // --------------------------------------------
     memset(&lb, 0, sizeof(STVIOLISTBOX));

     lb.row1 = 3;
     lb.col1 = 3;
     lb.rowTo = 14;
     lb.colTo = 34;
     lb.llen = app.iTotalSet;
     lb.startat = 0;
     lb.mark = FALSE;

     VioListBox(app.pmainWnd, &lb, 0, pszSelectList, aiRet, 0);

     bQuit = FALSE;
     while (bQuit == FALSE)
           {
           iRet = VioListBox(app.pmainWnd, &lb, 1, pszSelectList, aiRet, 0);
           app.bExitProgram = FALSE;
           app.bShowTime = FALSE;
           VioPrint(app.pmainWnd, 1, 3, "                                 ");
           switch (iRet)
                  {
                  case KEY_ENTER:
                       batch = fopen(IDS_BATCHFILE, "w");
                       for (iCounter = 0; iCounter < set[lb.curpos].iCommand; iCounter++)
                           fprintf(batch, set[lb.curpos].szCommand[iCounter]);
                       fclose(batch);

                       // If not registered, display and wait
                       if (app.bRegistered == FALSE)
                          {
                          app.bShowTime = FALSE;
                          ShowUnRegistered(pstv);
                          }

                       VioCls(COLOR_WHITE, COLOR_BLACK);

                       if (system(IDS_BATCHFILE) == 0)
                          {
                          // Remove Batch file
                          remove(IDS_BATCHFILE);

                          // Do we want to reboot
                          if (set[lb.curpos].bReboot == 1)
                             {
                             // Open handle to DOS$
                             DosOpen("\\DEV\\DOS$", &hIOCTL, &ulAction, 0L, 0, 1, 0x0011, 0L);
                             // Shutdown
                             DosShutdown(0);
                             // Reboot machine to use new files
                             DosDevIOCtl(hIOCTL, 0xd5, 0xab, NULL, 0, NULL, NULL, 0, NULL);
                             }
                          }
                       bQuit = TRUE;
                       break;

                  case KEY_ESC:
                       bQuit = TRUE;
                       break;

                  case KEY_F1:
                       ShowFileHelp(pstv);
                       VioSetCursor(app.pmainWnd, 0, 0, FALSE);
                       break;
                 }
           }
     VioListBox(app.pmainWnd, &lb, 2, NULL, NULL, 0);
     free (pszSelectList);

     VioCloseWindow(app.pmainWnd);
     VioExit(pstv);
     return;
     }


/*-----------------------------------------------------------------------------
   ExitProgram: Counts down and exits program if it times out.
-----------------------------------------------------------------------------*/
void ExitProgram(void *arg)
     {
     char               szString[255];
     int                iAntal;


     iAntal = app.iTimeOut;
     while (iAntal > 0 )
           {
           if (app.bShowTime == TRUE)
              {
              if (app.iWait == 0)
                 {
                 sprintf(szString, IDS_TIMEOUTWINDOW, iAntal);
                 VioPrint(app.pmainWnd, 1, 3, szString);
                 }
              else
                 {
                 sprintf(szString, IDS_TIMEOUTONELINE, iAntal);
                 VioPrintString (app.iOneLineRow, app.iOneLineCol, szString);
                 }
              }

           if (app.bExitProgram == FALSE)
              {
              return;
              }
           DosSleep(1000);
           if (app.bExitProgram == FALSE)
              {
              return;
              }
           iAntal--;
           }

     InitApplication(1);
     exit(0);
     }


/*-----------------------------------------------------------------------------
   InitApplication: Sets colors/clears screen etc.
-----------------------------------------------------------------------------*/
void InitApplication(USHORT usFlag)
    {
    static char         *pbCmdWindow;
    static int          iMaxRows, iMaxCols;
    static USHORT       usCmdRow, usCmdCol;


    if (usFlag == 0)
       {
       usCmdRow = VioQueryCursorRow();
       usCmdCol = VioQueryCursorColumn();
       VioGetInfo(&iMaxRows, &iMaxCols, NULL);
       pbCmdWindow = VioGetWindow(1, 1, iMaxRows, iMaxCols);
       }
    else
       {
       VioSetScreenSize(iMaxRows, iMaxCols);
       VioSetCursorPosition(usCmdRow, usCmdCol);
       VioShowCursor(TRUE);
       VioPutWindow(pbCmdWindow, 1, 1, iMaxRows, iMaxCols);
       }
    }


/*-----------------------------------------------------------------------------
   ShowFileHelp: Shows help screen for file mode.
-----------------------------------------------------------------------------*/
void ShowFileHelp(PSTVIO pstv)
     {
     char               szTmp[17][70];
     int                iCounter;
     PSTVIOWINDOW       pwnd;


     pwnd = VioOpenStandardWindow(pstv, 3, 5, 21, 69, IDS_WNDHELP);

     sprintf(szTmp[0],  IDS_HELP01);
     sprintf(szTmp[1],  IDS_HELP02);
     sprintf(szTmp[2],  IDS_HELP03);
     sprintf(szTmp[3],  IDS_HELP04);
     sprintf(szTmp[4],  IDS_HELP05);
     sprintf(szTmp[5],  IDS_HELP06);
     sprintf(szTmp[6],  IDS_HELP07);
     sprintf(szTmp[7],  IDS_HELP08);
     sprintf(szTmp[8],  IDS_HELP09);
     sprintf(szTmp[9],  IDS_HELP10);
     sprintf(szTmp[10], IDS_HELP11);
     sprintf(szTmp[11], IDS_HELP12);
     sprintf(szTmp[12], IDS_HELP13);
     sprintf(szTmp[13], IDS_HELP14, IDS_BOOTSETVER, VERSION);
     sprintf(szTmp[14], IDS_HELP15);
     sprintf(szTmp[15], IDS_HELP16);
     sprintf(szTmp[16], IDS_HELP17);

     for (iCounter = 0; iCounter < 17; iCounter++)
         VioPrint(pwnd, iCounter + 2, 1, szTmp[iCounter]);

     VioGetKey(pwnd, TRUE, FALSE);

     VioCloseWindow(pwnd);
     }


/*-----------------------------------------------------------------------------
   ShowUnRegistered: Shows delay screen when unregistered.
-----------------------------------------------------------------------------*/
void ShowUnRegistered(PSTVIO pstv)
     {
     char               szTmp[3][70];
     int                iCounter;
     PSTVIOWINDOW       pwnd;


     pwnd = VioOpenStandardWindow(pstv, 5, 5, 6, 69, IDS_WNDUNREG);
     sprintf(szTmp[0], IDS_UNREG01, IDS_BOOTSETVER);
     sprintf(szTmp[1], IDS_UNREG02);
     sprintf(szTmp[2], IDS_UNREG03);

     for (iCounter = 0; iCounter < 3; iCounter++)
         VioPrint(pwnd, iCounter + 2, 1, szTmp[iCounter]);

     DosSleep(UNREG_TIMEOUT);

     VioCloseWindow(pwnd);
     }




