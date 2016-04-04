#ifndef VMM_H_INCLUDED
#define VMM_H_INCLUDED
#include <iostream>
#include "program.h"
#include "FileFunc.h"




class memory
{
  private:
      int page_size;

  public:
    void allocate_mem();
    void set_page_size(int sz);




};

#endif // VMM_H_INCLUDED
