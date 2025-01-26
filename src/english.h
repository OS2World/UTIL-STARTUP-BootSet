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
/*   Modul:      ENGLISH.H, language headerfile for custimized boot        */
/***************************************************************************/

#ifndef IDS_BOOTSETVER
#define IDS_BOOTSETVER          "BootSet 2.01"
#endif

#define IDS_COPYRIGHT           "FreeCode"

#define IDS_BOOTSET             "BootSet"

#define IDS_SETNOTFOUND         "\nSettings file not found: %s\n"
#define IDS_SETMUSTSPEC         "\nSettings file must be specified\n"
#define IDS_PRESSANYKEY         "\nPress any key to continue\n"

#define IDS_PRESSBFOR           "Press [B] for %s, "
#define IDI_PRESSBFORCOL        28

#define IDS_PRESSBFORUNREG      "Press [B] for %s  - unregistered, "
#define IDI_PRESSBFORUNREGCOL   44

#define IDS_STATUSKEYS          "Enter=Select  Esc=Cancel  F1=Help"
#define IDS_UNREG               "unregistered"
#define IDS_WINDOWKEYS          " Enter=Start  Esc=Cancel  F1=Help "

#define IDS_TIMEOUTWINDOW       "Timeout will occur in %d seconds.   "
#define IDS_TIMEOUTONELINE      ", timeout in %d seconds.  "

#define IDS_WNDHELP             "Condensed help"
#define IDS_HELP01              "    Condensed help. Please refer to README.TXT for more help.      "
#define IDS_HELP02              "  ���������������������������������������������������������������  "
#define IDS_HELP03              "   Use the arrow keys and <Home>/<End> to select the item you      "
#define IDS_HELP04              "   wish to run and then press <Enter> to run it.                   "
#define IDS_HELP05              "                                                                   "
#define IDS_HELP06              "   Press <Esc> if you do not want to run any item.                 "
#define IDS_HELP07              "                                                                   "
#define IDS_HELP08              "   <F1> will give you this help screen.                            "
#define IDS_HELP09              "                                                                   "
#define IDS_HELP10              "                                                                   "
#define IDS_HELP11              "   Please note that any keypress (including <F1>) will stop        "
#define IDS_HELP12              "   the timeout countdown (when using full menu).                   "
#define IDS_HELP13              "  ���������������������������������������������������������������  "
#define IDS_HELP14              "          %s, %s"
#define IDS_HELP15              "        FreeCode                                                   "
#define IDS_HELP16              "                                                                   "
#define IDS_HELP17              "  email -  free@jmast.se       www   -  http://www.jmast.se/free/  "

#define IDS_WNDUNREG             "BootSet is unregistered!"
#define IDS_UNREG01              "         %s, unregistered version."
#define IDS_UNREG02              "                                          "
#define IDS_UNREG03              "      Please register, key is free !      "



#define IDS_BSEDITVER           "BootSet Editor 2.0"
#define IDS_BSEDIT              "BootSet Editor"
#define IDS_BSESETNOTFOUND      "Settings file not found:"
#define IDS_BSESETNOTCREATE     "Settings file could not be created."
#define IDS_BSESETMUSTSPEC      "Settings file must be specified"

#define IDS_BSESTATUSKEYS       "F1=Help"
#define IDS_BSEWINDOWKEYS       "Enter=Edit  Esc=Quit  Ins=Add  Del=Remove  F4=Settings"

#define IDS_BSEWARNING          "Warning"
#define IDS_BSENOSETSPEC        "No settings file specified."
#define IDS_BSEBSCREATE         "File BOOTSET.SET will be created"
#define IDS_BSEAREYOUSURE       "Are you sure ?"

#define IDS_BSEERROR            "Error"

#define IDS_BSSETTINGSSTAR      "**SETTINGS:**"
#define IDS_BSFILENAME          "File name: %s"
#define IDS_BSSTARTFS           " Start full screen  "
#define IDS_BSSTARTOL           "Start with one line "
#define IDS_BSREGCODE           "Regcode:"
#define IDS_BSCOLORSET          "Color settings:"
#define IDS_BSCOLORCUR          " Current colors "
#define IDS_BSENTEREDIT         "Enter=Edit"
#define IDS_BSESCEXIT           "Esc=Exit"
#define IDS_BSINSADD            "Ins=Add"
#define IDS_BSDELREM            "Del=Remove"
#define IDS_BSTABEDITSET        "Tab=Edit settings"

#define IDS_BSTOMANYLINES       "To many lines, if you save"
#define IDS_BSDATALOST          "data will be lost."
#define IDS_BSNEWITEM           "New item"
#define IDS_BSREM1              "REM This is an example !"
#define IDS_BSREM2              "REM It must be modified to do anything."

#define IDS_BSTOMANYITEMS       "To many items"
#define IDS_BSCANNOTADD         "Cannot add item"
#define IDS_BSDELETEITEM        "Delete item:"
#define IDS_BSCANNOTREMOVE      "Cannot remove last item !"

#define IDS_BSEXITPROGRAM       "Exit program"
#define IDS_BSCHANGESET         "Do you wish to save changes ?"
#define IDS_BSCANNOTWRITE       "Cannot open file for writing"

#define IDS_BSENTERKEYHERE      "Enter key here"
#define IDS_BSEXAMPLE           "Example"

#define IDS_BSSETTINGS          "Settings"
#define IDS_BSFCOLOR            "Forground color"
#define IDS_BSBCOLOR            "Background color"
#define IDS_BSTIMEOUT           "Timeout"
#define IDS_BSSEC               "sec"
#define IDS_BSREGKEY            "Registration key"
#define IDS_BSLINE01            "����������������������������������������"
#define IDS_BSSTARTONE          "Start with one line"
#define IDS_BSF2SAVE            "F2 = Save"
#define IDS_BSESCCANVEL         "Esc = Cancel"
#define IDS_BSCOLORTEST         " Color test "

#define IDS_BSEDITITEM          "Edit item"
#define IDS_BSITEMTITLE         "Item title:"
#define IDS_BSCOMMAND           "Command:"
#define IDS_BSLINE02            "�����������������������������������������������������������������"
#define IDS_BSREBOOTAFTER       "Reboot after command"
#define IDS_BSCMDNOTEMPTY       "Command cannot be empty !"
#define IDS_BSTITLENOTEMP       "Item title cannot be empty !"

#define IDS_BSWNDHELP           "Condensed help"
#define IDS_BSHELP01            "    Condensed help. Please refer to README.TXT for more help.      "
#define IDS_BSHELP02            "  ���������������������������������������������������������������  "
#define IDS_BSHELP03            "   Use the arrow keys and <Home>/<End> to select the item you      "
#define IDS_BSHELP04            "   wish to edit and then press <Enter> to edit it.                 "
#define IDS_BSHELP05            "                                                                   "
#define IDS_BSHELP06            "   <Ins> Inserts a new item after the current item.                "
#define IDS_BSHELP07            "   <Del> Removes the currently selected item.                      "
#define IDS_BSHELP08            "   <Tab> Shows the settings dialog.                                "
#define IDS_BSHELP09            "   <Esc> Exits the program and asks you if you wish to save        "
#define IDS_BSHELP10            "         any changes you may have made.                            "
#define IDS_BSHELP11            "                                                                   "
#define IDS_BSHELP12            "   <F1>  Gives you this help screen                                "
#define IDS_BSHELP13            "  ���������������������������������������������������������������  "
#define IDS_BSHELP14            "        %s, Release %s"
#define IDS_BSHELP15            "        FreeCode                                                   "
#define IDS_BSHELP16            "                                                                   "
#define IDS_BSHELP17            "  email -  free@jmast.se       www   -  http://www.jmast.se/free/  "

#define IDS_BSWNDHELPSET        "Settings help"
#define IDS_BSHELPS01           "                                                                   "
#define IDS_BSHELPS02           " Use this dialog to change settings for BootSet.                   "
#define IDS_BSHELPS03           "                                                                   "
#define IDS_BSHELPS04           " Start with one line allows you to specify if you wish BootSet to  "
#define IDS_BSHELPS05           "   display the 'Press [B]' one line or go directly to fullscreen.  "
#define IDS_BSHELPS06           "                                                                   "
#define IDS_BSHELPS07           " Foreground/background color are numeric values as follows:        "
#define IDS_BSHELPS08           "   Foreground:                                                     "
#define IDS_BSHELPS09           "   Background:                                                     "
#define IDS_BSHELPS10           "                                                                   "
#define IDS_BSHELPS11           " Timeout tells BootSet how long to wait until it should exit by    "
#define IDS_BSHELPS12           "    itself, a value of zero means stay forever.                    "
#define IDS_BSHELPS13           "                                                                   "
#define IDS_BSHELPS14           " Registration key, here you type the registration key you need     "
#define IDS_BSHELPS15           "   to continue to use BootSet after the trial period.              "
#define IDS_BSHELPS16           "                                                                   "
#define IDS_BSHELPS17           "       <F2> saves the settings, <Esc> discards any changes         "

#define IDS_BSWNDHELPEDIT       "Edit item help"
#define IDS_BSHELPE01           "                                                                   "
#define IDS_BSHELPE02           " Use this dialog to edit one item.                                 "
#define IDS_BSHELPE03           "                                                                   "
#define IDS_BSHELPE04           " The Item title is the text that will be displayed in the list of  "
#define IDS_BSHELPE05           "   runnable commands in BootSet.                                   "
#define IDS_BSHELPE06           "                                                                   "
#define IDS_BSHELPE07           " Reboot after command specifies if BootSet should restart the      "
#define IDS_BSHELPE08           "   machine after the command has been run.                         "
#define IDS_BSHELPE09           "                                                                   "
#define IDS_BSHELPE10           " In command you specify what BootSet should do when you run an     "
#define IDS_BSHELPE11           "   item in the list. This may be OS/2 commands or REXX commands.   "
#define IDS_BSHELPE12           "  The lines you type will put in a batchfile and executed as one   "
#define IDS_BSHELPE13           "   single batchfile. You can also specify the name of an already   "
#define IDS_BSHELPE14           "   existing batchfile tu run.                                      "
#define IDS_BSHELPE15           "  BootSet Editor allows a maximum of 10 lines with 64 characters,  "
#define IDS_BSHELPE16           "   but you can edit the SET file directly for larger files.        "
#define IDS_BSHELPE17           "                                                                   "
#define IDS_BSHELPE18           "        <F2> saves this item, <Esc> discards any changes           "

