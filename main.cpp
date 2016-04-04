#include <iostream>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include "program.h"
#include "FileFunc.h"
#include "vmm.h"
using namespace std;

program prog[PROGARRSZ];
memory mem;

int main(int argc, char* argv[])
{
    getproginfo(prog, argv[1]);
    for(int i = 0; i < argc; i++)
    {
      cout<<"argv["<<i<<"] "<<argv[i]<<endl;
    }
    for(int i = 0; i < 10; i++)
    {
      cout<<"Prognum: "<<prog[i].programnum<<" Progsize: "<<prog[i].programsize<<endl;
    }

    mem.set_page_size(atoi(argv[3]));
    return 0;
}
