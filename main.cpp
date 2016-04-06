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
    mem.RAM = new page[(512/atoi(argv[3]))];
    mem.prog = prog;
    getproginfo(mem.prog, argv[1]);
    for(int i = 0; i < argc; i++)
    {
      cout<<"argv["<<i<<"] "<<argv[i]<<endl;
    }
    mem.set_page_size(atoi(argv[3]));
    mem.allocate_mem();
    for(int i = 0; i < PROGARRSZ; i++)
    {
      cout<<"Prog: "<<mem.prog[i].programnum<<" Progam Size: "<<mem.prog[i].programsize
            <<" Pages: "<<mem.prog[i].pages<<" Pageoffset: "<<mem.prog[i].pageoffset<<endl;
    }

    return 0;
}
