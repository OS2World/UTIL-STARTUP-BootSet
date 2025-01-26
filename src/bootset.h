/***************************************************************************/
/* F r e e C o d e                                                         */
/*                                                                         */
/* This code is free and you can do what you want with it. There is no     */
/* support or warranties on this code. Its distributed as-is.              */
/*                                                                         */
/* However, we would appriciate if you shared any enhancements to us       */
/* Please send them to www.jmast.se/free/ and we will include them in      */
/* future distributions.                                                   */
/*                                                                         */
/***************************************************************************/
/***************************************************************************/
/*   Modul:      BOOTSET.H, headerfile for custimized boot                 */
/***************************************************************************/

// struct declarations
//-----------------------
typedef struct _FILESETTYPE
       {
       char     szTitle[80];
       BOOL     bReboot;
       int      iCommand;
       char     szCommand[100][256];
       } FILESETTYPE;
typedef FILESETTYPE *PFILESETTYPE;



typedef struct _APPLICATION
       {
       FILE             *stream;
       BOOL             bExitProgram;
       BOOL             bShowTime;

       char             szIniFile[_MAX_PATH];

       char             szRegKey[40];
       BOOL             bRegistered;

       int              iWait;
       int              iForeColor;
       int              iBackColor;
       int              iTotalSet;
       int              iTimeOut;

       PFILESETTYPE     set;
       PCHAR            *pszSelectList;

       TID              tid;

       USHORT           usCellNorm;
       USHORT           usCellRev;
       USHORT           usCellBlink;

       PSTVIOWINDOW     pmainWnd;
       int              iOneLineRow;
       int              iOneLineCol;
       char             *pbOneLine;

       } APPLICATION;



// #define declarations
//-----------------------
#define UNREG_TIMEOUT   6000
#define MAX_ITEMS       200

#define IDS_INIFILE     "BOOTSET.SET"
#define IDS_BATCHFILE   "BS.CMD"
#define IDS_BOOTSETVER  "BootSet 2.01"



// Function declarations
//-----------------------
void SelectList(char *szINIfile);
void _Optlink ExitProgram(void *arg);
void InitApplication(USHORT usFlag);
void ShowFileHelp(PSTVIO pstv);
void ShowUnRegistered(PSTVIO pstv);
