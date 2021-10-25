#include <iostream>
#include <windows.h>

#include <direct.h>
#include <shlobj.h>

using namespace std;

int main ()
{
      

    TCHAR appData[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPath(NULL,CSIDL_DESKTOPDIRECTORY | CSIDL_FLAG_CREATE,NULL,SHGFP_TYPE_CURRENT,appData)))

    wcout << appData << endl;
    return 0;
}

