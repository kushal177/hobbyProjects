#include <sys/resource.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>    // For opendir, readdir
#include <linux/kernel.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
const char *prefix = "/proc";

struct pf_info_struct
{
int numberofProc;
int majPgFault;
int minPgFault;
};

int pgfltstat (int val, pid_t pid, struct pf_info_struct *info)
{
  struct rusage usage;	
  int process_id=0;
  long totMajPgFlt=0;
  long totMinPgFlt=0;
  struct dirent* dirEntry = NULL;
  struct stat buf;
  int target = 0;
  int count = 0; 
  int dummy = 0;
  DIR* dir=NULL;

  if (val == -1)
   {
	printf("Getting resource usage for all the processes\n");
   }
   else if (val == -2)
   {
	printf("Getting resource usage for single process\n");
   }
   else
   {
	printf("Getting resource usage for group of process\n");
   }

  if (val != -2)
    {
      // find the pid's of all the current running processes
      dir = opendir(prefix);
      dirEntry = readdir(dir);
      printf("Entered proc directory\n");
      while( dirEntry != NULL) 
	{
	      
	      // get info about the node (file or folder)
	      lstat(dirEntry->d_name, &buf);
	      if (val == -1)
		{
		  if (count >= 999)
		    {
		      break;
		    }
		  process_id = atoi(dirEntry->d_name);
		  printf("1) Getting resource usage for the process = %d\n", process_id);
		  count++;
	        }
	      else
		{
		  process_id = atoi(dirEntry->d_name);
		  if (buf.st_uid != val)
		  {
			printf("Process %d doen not belong to group id %d\n", process_id, val);
			 dirEntry = readdir(dir);
              		continue;
		  }		
		  if (count >= 499)
		    {
		      break;
		    }
		  
		  printf("Process %d belongs to group id %d\n", process_id, val);
		  count++;
		}	
	      if (process_id<0)
		{
                  printf("Not a process 2\n");
		    dirEntry = readdir(dir);
		   continue;
		}
	      getrusage(process_id, &usage);
              totMinPgFlt += usage.ru_minflt;// minor page faults: "page reclaims"
	      totMajPgFlt += usage.ru_majflt; 

	    //}
	    printf("Entered direc...\n");
	    dirEntry = readdir(dir);
	}

    }
    
  if (val == -2)
    {
      process_id = (int) pid;
      printf("Getting resource usage for the process = %d\n", process_id);
      // find the resource usage for the specified process
      getrusage(process_id, &usage);
      totMinPgFlt = usage.ru_minflt;// minor page faults: "page reclaims"
      totMajPgFlt = usage.ru_majflt; 
      count = 1;
      
    }

      info->majPgFault = totMinPgFlt;
      info->minPgFault = totMajPgFlt;
      info->numberofProc = count;
	

	return 21;
	//anup - 7760880573
}


int main(int argc, char** argv)
{
  
  int process_id = 1000;//getpid();
  int inWhat = 1000;
  int returnVal = 1;
  struct pf_info_struct info;
  int loop1 = 0;
  int i=0;
  FILE* fp;
  char ch;
  int count  = 100000000;
  char* str =(char*) malloc (count*sizeof(char));
  int loop = 0;
  FILE* fpOut = fopen("config1.out", "w");
  FILE* fpRes = fopen("results.txt", "w");
  printf("program running.");
  printf("PID = %d\n", process_id); 
  long numberOfMajFlts=0;
  long numberOfMinFlts=0;
  long numberOfProcs=0;
  //returnVal = syscall(315, inWhat, processNum, &info);
  returnVal = pgfltstat (inWhat,process_id,&info);
  printf("Number of major page faults = %ld\n", numberOfMajFlts);
  printf("Number of minor page faults = %ld\n", numberOfMinFlts);
 
 fprintf(fpRes, "Getting page faults for group process:\n");
 fprintf(fpRes, "Number of major page faults = %ld\n", numberOfMajFlts);
 fprintf(fpRes, "Number of minor page faults = %ld\n", numberOfMinFlts);
  while (1)
    {
    fp = fopen("config", "r");
    if (fp != NULL)
    {
       printf(".");
      do {
	if (loop == 100)
	  {    
	    //getch();
	    returnVal = pgfltstat (inWhat,process_id,&info);
	    numberOfMajFlts +=  info.majPgFault;
	    numberOfMinFlts += info.minPgFault;
	    numberOfProcs += info.numberofProc;
	    //printf("Number of processes = %ld\n", numberOfProcs);
		printf("Number of major page faults = %ld\n", numberOfMajFlts);
		printf("Number of minor page faults = %ld\n", numberOfMinFlts);

		fprintf(fpRes, "Number of major page faults = %ld\n", numberOfMajFlts);
 		fprintf(fpRes, "Number of minor page faults = %ld\n", numberOfMinFlts);
		
	  }
	else if (0)//(loop % 1000)
	  {
	    int div = loop / 100;
	    if (div == 1)
		  {
		    fclose(fp);
		    fp = fopen("links", "r");
		  }
	    if (div == 2)
	      {
		fclose(fp);
		fp = fopen("CMakeLists", "r");
	      }
	    if (div ==3)
	      {
		fclose(fp);
		fp = fopen("README", "r");
	      }
	    else
	      {
		fclose(fp);
		fp = fopen("config", "r");
	      }
	  }
	ch = getc(fp);
	putc(ch,fpOut);
	if (loop<count-1)
	  {
	    str[loop++] = ch;
	  } 
	else
	  {
	    loop = 0;
	    loop1++;
	    printf("\nRealloc happened\n");
	    //printf("\nFree happened\n");
	    str = (char*)realloc((void*)str,count);
	    //if (NULL != str)
	    // {
	    // free(str);
	    // }
            //str =(char*) malloc (count*sizeof(char));
	  }
      }while (ch !=EOF);
      fflush(stdout);

      if ( loop1 >=15)
	  {
	    printf("loop1 = %d", loop1);
	     fclose(fp);
	     break;
	  }
    }
    
  fclose(fp);
  fp=NULL;
    }
  fclose(fpOut);
  if (NULL != str)
    {
      free(str);
    }
    
  printf("\n");
  returnVal = pgfltstat (inWhat,process_id,&info);
  printf("Number of major page faults = %ld\n", numberOfMajFlts);
  printf("Number of minor page faults = %ld\n", numberOfMinFlts);
  fprintf(fpRes, "Number of major page faults = %ld\n", numberOfMajFlts);
  fprintf(fpRes, "Number of minor page faults = %ld\n", numberOfMinFlts);
 
  fclose(fpRes);


	return 0;
}


