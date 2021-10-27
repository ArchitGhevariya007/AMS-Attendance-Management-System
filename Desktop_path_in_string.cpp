#include<iostream>
#include<windows.h>

// #include<stdio.h>
// #include<conio.h>

#include <sys/types.h>
#include <sys/stat.h>

#include <direct.h>
#include <shlobj.h>

#ifndef UNICODE  
  typedef std::string String; 
#else
  typedef std::wstring String; 
#endif
 
using namespace std;

int dirExists(const char *path)
{
    struct stat info;

    if(stat( path, &info ) != 0)
        return 0;
    else if(info.st_mode & S_IFDIR)
        return 1;
    else
        return 0;
}

int main()
{   

    
    TCHAR appData[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPath(NULL,CSIDL_DESKTOPDIRECTORY | CSIDL_FLAG_CREATE,NULL,SHGFP_TYPE_CURRENT,appData)));

    //wcout<<appData<<endl;

    string DesktopPath = appData;
    //string DesktopPath2;

    //DesktopPath2 = DesktopPath; //backup directory if needed
   
    DesktopPath = DesktopPath + "\\" + "Endecter";
    //cout<<"Main"<<DesktopPath<<"Back up"<<DesktopPath2<<endl;
    
    int i;
    char DesktopPathArray[MAX_PATH];

    for(i=0;i<DesktopPath.length();i++)
    {
      DesktopPathArray[i]=DesktopPath[i]; //folder create mate char ma convert
    }

    //printf("\n after array : %s",DesktopPathArray);

    //const char *path = "C:Endecter";
    const char *path = DesktopPathArray;  

    string command;
    int check = dirExists(path); 

    //cout<<check<<endl;

    if(!check)
    {  
       command="mkdir "+DesktopPath;
       //cout<<"commad 1 for creating directory "<<command<<endl;
       system(command.c_str()); 
    }
     
     //getch();
    //cout<<ch<<endl;
    command = "echo.successful > " + DesktopPath + "\\harshil_success.txt";
    //cout<<"commad 2 for creating a file "<<command<<endl;
    system(command.c_str()); 

    //?just use DesktopPath + "\\Emessage1.txt"
    //in all file handling

    return(0);
}

