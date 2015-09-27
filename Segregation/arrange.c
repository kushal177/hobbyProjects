#include "arrange.h"

const int MOVE_ITEM = 0;

void swap (int* var1, int* var2)
{
  int temp = *var1;
  *var1 = *var2;
  *var2 = temp;
}

int arrange(int* inp_arr, const int sz)
{
  int ii=0,jj=0;
  int start = 0;
  int end = start;

  for (;ii<sz;++ii)
    {
      if (inp_arr[ii] == MOVE_ITEM)
	{
	  start = ii;
	  for(jj=start;jj>end;--jj)
	    {
	       swap(inp_arr+jj, inp_arr+jj-1);
	    }
	  end++;
	}
    }

  if (ii==sz)
    //success
    return 0;
  else
    //loop terminated, failure
    return 1;
}
