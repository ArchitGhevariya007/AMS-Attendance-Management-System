#include<stdbool.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

int checkNumberInput(int *input,int Bnd)
{

 if(!cin)
 {
     cin.clear();
     cin.ignore(80,'\n');
 }
 if(*(input)<1||*(input)>Bnd)
 {        
    //scrClr();
    //setCursorPos(2,24);
    cout<<"INVALID CHOICE ENTERTED !"<<endl;
   // setCursorPos(2,20);
    cout<<"PLEASE RE-ENTER YOUR CHOICE CORRECTLY !"<<endl;
    //scrClr(1);
    return 1;
 }
 return 0;
}

void input()
{   
    int validate;
    int number;
    
    reinput:

    fflush(stdin);
    cout<<"Enter Number : ";
    cin>>number;
    
    validate = checkNumberInput(&number,5);

    if(validate)goto reinput;

    cout<<endl<<"Number : "<<number;
}

int main()
{

    input();

    return 0;
}