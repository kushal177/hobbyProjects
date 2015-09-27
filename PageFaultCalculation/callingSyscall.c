#include <sys/resource.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>    
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

//// function to scan the /proc directory
int dirScan (int val, pid_t pid, struct pf_info_struct *info)
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
	  
	  // is a number? (pid)
	  //if (scanf(dirEntry->d_name, "%d", &dummy) == 1) 
	    //{
	      
	      // get info about the node (file or folder)
	      lstat(dirEntry->d_name, &buf);

	      // it must be a folder
	      //if (buf.st_mode != S_IFDIR)
		{
		  //printf("Not a process 1\n");
		  //continue;
		}
	       //printf("is it a folder");
	      // check if it's owned by the uid you need

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
	      returnVal = syscall(315, inWhat, processNum, &info);/// <<<<<<<<<<<<<<<<<<<<<<<<<implemented system call
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
      returnVal = syscall(315, inWhat, processNum, &info);/// <<<<<<<<<<<<<<<<<<<<<<<<<implemented system call
      totMinPgFlt = usage.ru_minflt;// minor page faults: "page reclaims"
      totMajPgFlt = usage.ru_majflt; 
      count = 1;
      
    }

      info->majPgFault = totMinPgFlt;
      info->minPgFault = totMajPgFlt;
      info->numberofProc = count;
	

	return 21;
	
}

int main(int argc, char** argv)
{
  
  int processNum = getpid();
  int inWhat = -2;
  int returnVal = 1;
  struct pf_info_struct info;
  int loop1 = 0;

  FILE* fp;
  char ch;
  int count  = 100000000;
  char* str =(char*) malloc (count*sizeof(char));
  int loop = 0;
  FILE* fpOut = fopen("config.out", "w");
  printf("program running.");
  FILE* fpRes = fopen("results.txt", "w");
  printf("PID = %d\n", processNum); 
  long numberOfMajFlts=0;
  long numberOfMinFlts=0;
  long numberOfProcs=0;
  dirScan(inWhat, processNum, &info);
  numberOfMajFlts +=  info.majPgFault;
  numberOfMinFlts += info.minPgFault;
  numberOfProcs += info.numberofProc;
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
                returnVal = dirScan(inWhat, processNum, &info);
	            numberOfMajFlts +=  info.majPgFault;
	            numberOfMinFlts += info.minPgFault;
	            //printf("Number of processes = %ld\n", numberOfProcs);
		        printf("Number of major page faults = %ld\n", numberOfMajFlts);
		        printf("Number of minor page faults = %ld\n", numberOfMinFlts);

		        fprintf(fpRes, "Number of major page faults = %ld\n", numberOfMajFlts);
 		        fprintf(fpRes, "Number of minor page faults = %ld\n", numberOfMinFlts);
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
	    printf("Realloc happened\n");
	    str = (char*)realloc((void*)str,count);
	  }
      }while (ch !=EOF);
      fflush(stdout);

      if ( loop1 >=15)
	  {
	     fclose(fp);
	     break;
	  }
    }
    
    fclose(fp);
    fp=NULL;
    }
    fclose(fpOut);

    dirScan(inWhat, processNum, &info);
    free(str);
    dirScan(inWhat, processNum, &info); 
	return 0;
}


