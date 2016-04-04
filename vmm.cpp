
#include "vmm.h"
using namespace std;

void memory::set_page_size(int sz)
{
  page_size = sz;
  //cout<<"Page_Size: "<<page_size<<endl;
}
