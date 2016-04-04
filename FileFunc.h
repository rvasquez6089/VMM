#ifndef FILEFUNC_H_INCLUDED
#define FILEFUNC_H_INCLUDED

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include "program.h"

using namespace std;

void getproginfo(program progs[], char filename[])
{
  char text[100];
  char * temp;
  //char * programnum;
  //char * numofpages;
  bool cont;
  //cout << "Text parser" << endl;
  ifstream programlist;
  programlist.open(filename);
  cont = !(programlist.eof());
  for(int i = 0; i < PROGARRSZ && cont; i++)
  {
    cont = !(programlist.eof());

    programlist.getline(text,10);
    temp = strtok(text," ");
    if(temp)
    {
      if(isdigit(temp[0]))
      {
        progs[i].programnum = atoi(temp);
      }
      temp = strtok(NULL," ");
      //cout<<temp<<endl;
      {
    }

    if(temp)
    {
      if(isdigit(temp[0]))
        progs[i].programsize = atoi(temp);
      }
    }
    //cout<<"Program Number: "<<programnum<<" Number of Pages: "<<numofpages<<endl;


  }
  programlist.close();
}

#endif // FILEFUNC_H_INCLUDED
