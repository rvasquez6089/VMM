#ifndef VMM_H_INCLUDED
#define VMM_H_INCLUDED
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include <math.h>

#include "program.h"
#include "arraylist.h"

const int RAMSIZE = 512;


class page;

class memory
{
  private:
      int page_size;

  public:
    void allocate_mem();
    void set_page_size(int sz);
    program *prog;
    ArrayList<page> pagetable;
    page *RAM;
    int RAMpointer;
    void Clocksim(char *progtracf, bool paging);
    int faultnum;
};

class page
{
  private:

  public:
  int timestamp;
  bool usebit;
  int prognum;
  int pagetabnum;
  int progmemnum;
};

#endif // VMM_H_INCLUDED
