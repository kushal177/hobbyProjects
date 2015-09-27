#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arrange.h"

int const DEF_SZ = 32;

void help()
{
  fprintf (stdout,"%s", " Usage: \n");
  fprintf (stdout,"%s", " -h = To find the list of input arguments,\n -a -d = Use default arrangement,\n -a  my_array_of_numbers = Use my input arrangement\n");

  return;
}

void generate_default_arrangement(int* arr)
{
  //default arrangement is of type 10101010101010101010101010101010.
  int ii=0;
  for (ii=0;ii<DEF_SZ;++ii)
    {
      if(ii%2)
	arr[ii] = 0;
      else
	arr[ii] = 1;
    }
}

void echo_arr(int* arr, int sz)
{
  int ii=0;
  for (ii=0;ii<sz;++ii)
    {
      fprintf(stdout, "%d", arr[ii]);
    }
  fprintf(stdout, "\n");
}

// convert characacter array to integer array
int convert_charArr_to_intArr( const char* charArr, int* intArr)
{
  int ii=0;
  while('\0' != charArr[ii])
    {
      intArr[ii] = charArr[ii] - '0';
      ++ii;
    }
  return 0;
}

//main program
int main (int argc, char** argv)
{
  //wrong inputs
  if (argc == 1)
    {
      help();
    }

  if ((argc == 2) && (!strcmp(argv[1],"-h")))
    {
      help();
    }

  if ((argc == 3) && (!strcmp(argv[1],"-a")))
    {
      int* inp_arr = NULL;
      int sz = 0;
      // use default arrangement
      if (!strcmp(argv[2], "-d"))
	{	
	  inp_arr = (int* )malloc(DEF_SZ*sizeof(int));
	  sz = DEF_SZ;
	  generate_default_arrangement(inp_arr);
	}
	else
	  {
	    // convert the given arrangement into integer array and proceed
	    sz = strlen(argv[2]);
	    inp_arr = (int* )malloc(sz*sizeof(int));	    
	    convert_charArr_to_intArr(argv[2],inp_arr);
	  }
	 fprintf(stdout, "%s", "Input Arrangement of disks: ");	   
	 // display
	 echo_arr(inp_arr, sz);
	 //re-arrange
	 arrange(inp_arr, sz);
	 //re-arrange
	 fprintf(stdout, "%s", "Final Arrangement of disks: ");
	 //dump it on scree
	 echo_arr(inp_arr, sz);
	  
      //de-allocate memory
      if (inp_arr != NULL)
	{
	  free(inp_arr);
	}
   }
      return 0;
}
