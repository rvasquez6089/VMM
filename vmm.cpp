
#include "vmm.h"
using namespace std;

void memory::set_page_size(int sz)
{
  page_size = sz;
  //cout<<"Page_Size: "<<page_size<<endl;
}

void memory::allocate_mem()
{
  page temp;
  for(int i = 0; i < PROGARRSZ;i++)
  {
    prog[i].pageoffset = pagetable.size();
    prog[i].pages = prog[i].programsize/page_size;
    for(int j = 0; j < prog[i].pages; j++)
    {
      temp.prognum = i;
      temp.timestamp = 0;
      temp.usebit = 0;
      temp.pagetabnum = pagetable.size();
      temp.progmemnum = j;
      pagetable.insert_back(temp);
    }
  }
  for (int i = 0; i < page_size/RAMSIZE; i++)
  {
    RAM[i].pagetabnum = 0;
    RAM[i].progmemnum = 0;
    RAM[i].prognum = 0;
    RAM[i].timestamp = 0;
    RAM[i].usebit = 0;
  }

}

void memory::Clocksim(char *progtracef, bool paging )
{
  char text[100];
  char * temp;
  int prognum;
  int progmemloc;
  int absmemloc;
  ifstream progtrace;
  progtrace.open(progtracef);

  while(!progtrace.eof());
  {


    progtrace.getline(text,10);
    temp = strtok(text," ");
    if(temp)
    {
      if(isdigit(temp[0]))
      {
       prognum = atoi(temp);
      }
    }
    temp = strtok(NULL," ");
    if(temp)
    {
      if(isdigit(temp[0]))
      {
        progmemloc = atoi(temp);
      }
    }

    if(!RAM[RAMpointer].usebit)
    {
      absmemloc = floor(progmemloc/page_size) + prog[prognum].pageoffset;

    }

  }
  progtrace.close();
}
