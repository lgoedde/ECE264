#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa05.h"
#define MAXIMUM_LENGTH 80

/* ----------------------------------------------- */
/*
 * release the memory occupied by the array of integers
 */
void freeInteger(int * arrInteger, int numInteger)
{
  free(arrInteger);
}

/* ----------------------------------------------- */
/*
 * release the memory occupied by the array of strings
 *
 * Hint: an array of strings is a two-dimensional array of characters
 */
void freeString(char * * arrString, int numString)
{
  int i;
  for(i=0; i < numString; i++)
    {
      free(arrString[i]);
    }
  free(arrString);
}

/*
 * Read a file of integers.
 *
 * Arguments:
 *
 * filename: the name of a file that contains a list of integers (one
 * per line)
 * 
 * numInteger: pointer to store the number of integers in the
 * file. You need to update the value stored at the address which is
 * the pointer's value.  If the function fails to update the value, it
 * is considered reading the file has failed.
 *
 * Returns:
 *
 * a array of integers from the file, or NULL if *any* error is
 * encountered.
 *
 * Hint: use fscanf
 *
 * You do NOT know how many integers are in the file until you have
 * read it. Once you know how many integers there are, you can modify
 * the "numberOfIntegers" variable. (Note that this is a pointer, not
 * an integer) You must allocate memory to store the integers.
 * 
 * Once memory is allocated to store the integers, you will need to
 * re-read the values from the file. To do this, you must reset the
 * file pointer to the beginning of the file using the function
 * "fseek". 
 *
 * You should not use rewind (if you have learned it somewhere).  The
 * difference of rewind and fseek is that rewind does not tell you
 * whether it fails.  
 *
 * One way to read integeres is to use the "fscanf" function.  It is
 * easier than reading one character at a time by using fgetc.
 *
 * You must use malloc in this function.
 * 
 * Some old books encourage readers to type cast in front of malloc,
 * something like
 *
 * int * ptr = (int *) malloc(sizeof(int) * size);
 *
 * Type cast is no longer needed and in fact is discouraged now.  You
 * should *NOT* type cast malloc.  It is discouraged even though it is
 * not wrong.
 *
 * You will receive zero if you allocate a large array whose size is
 * independent of the number of integers in the file.  For example, if
 * you write this
 *
 * int array[10000];
 * 
 *
 */

int * readInteger(char * filename, int * numInteger)
{
  FILE *fptr; // pointer for the start of the file to be read in
  int *arr; //pointer to store the array that will be used for rest of program
  int i=0; //counter variable
  int temp=0; //temp variable used to find how many ints are in the text file
  fptr = fopen(filename, "r"); 
  if(fptr==NULL)   
    {
      return NULL;
    }
     
  while(fscanf(fptr, "%d", &temp)==1)
    {
      (*numInteger)++;
    }
  fseek(fptr, 0, SEEK_SET);//brings the start pointer back to the beginning so it can be used again
  arr = malloc(sizeof(int)*(*numInteger)); //allocating memory for array
  for(i=0; i<(*numInteger); i++)
    {
      fscanf(fptr, "%d",&arr[i]);
    } 
  
  fclose(fptr);
  return(arr);
}

/* ----------------------------------------------- */

/*
 * Read a file of strings. This is similar to readInteger. However,
 * each string is an array of characters. The function needs to
 * allocate memory for an array of strings, i.e., array of arrays of
 * characters. In other words, this is a two-dimensional array (thus,
 * char **).
 *
 * Arguments:
 *
 * filename: the name of a file that contains a list of strings (one
 * per line)
 * 
 * numString: pointer to store the number of strings in the
 * file. You need to update the value stored at the address which is
 * the pointer's value.  If the function fails to update the value, it
 * is considered reading the file has failed.
 *
 * Returns:
 *
 * a array of strings from the file, or NULL if *any* error is
 * encountered.
 *
 * Hint: use fgets. 
 * 
 * Remember that an array of strings is a two-dimensional array of
 * characters
 *
 * You do NOT know how many strings are in the file until you have
 * read it. Once you know how many strings there are, you can modify
 * the "numberOfStrings" variable. (Note that this is a pointer, not
 * an string) You must allocate memory to store the strings.
 * 
 * Once memory is allocated to store the strings, you will need to
 * re-read the values from the file. To do this, you must reset the
 * file pointer to the beginning of the file using the function
 * "fseek". 
 *
 * You should not use rewind (if you have learned it somewhere).  The
 * difference of rewind and fseek is that rewind does not tell you
 * whether it fails.  
 *
 * One way to read stringes is to use the "fscanf" function.  It is
 * easier than reading one character at a time by using fgetc.
 *
 * You must use malloc in this function.
 * 
 * Some old books encourage readers to type cast in front of malloc,
 * something like
 *
 * int * ptr = (int *) malloc(sizeof(int) * size);
 *
 * Type cast is no longer needed and in fact is discouraged now.  You
 * should *NOT* type cast malloc.  It is discouraged even though it is
 * not wrong.
 *
 * You will receive zero if you allocate a large array whose size is
 * independent of the number of strings in the file.  For example, if
 * you write this
 *
 * char array[10000];
 * 
 *
 */

char * * readString(char * filename, int * numString)
{
  char buff[MAXIMUM_LENGTH]; //array to store temp variables while we are working with the file 
  FILE * fptr = fopen(filename, "r"); //pointer that stores the filename so we can work with it throughout this function
  if(fptr==NULL)
    {
      return NULL;
    }
  
  int numlines=0; //number of lines within the file
  while(fgets(buff, MAXIMUM_LENGTH, fptr)!=NULL)
    {
      numlines++;
    }
  *numString = numlines; //sets numstring equal to numlines to keep the program happy 
  char * * stArr;
  stArr = malloc(sizeof(char*)*numlines); //allocates mem for stArr
  fseek(fptr, 0, SEEK_SET); //starts the file pointer over 
  int i = 0; //counter variable
  while(fgets(buff, MAXIMUM_LENGTH, fptr)!=NULL)
    {
      stArr[i] = malloc(sizeof(char)*(strlen(buff)+1)); //allocates even more memory for 2D array
      strcpy(stArr[i], buff);
      i++;
    }
  fclose(fptr);
  return(stArr);
}

/* ----------------------------------------------- */
/*
 * print an array of integers, one integer per line
 */
void printInteger(int * arrInteger, int numInteger)
{
  int i; //counter variable 
  for(i=0;i<numInteger;i++)
    {
      printf("%d\n", arrInteger[i]);
    }
}

/* ----------------------------------------------- */
/*
 * print an array of strings, one string per line
 *
 * Hint: printf("%s" ... can print a string
 */
void printString(char * * arrString, int numString)
{
  int i; //counter variable 
  for(i=0;i<numString;i++)
    {
      printf("%s", arrString[i]);
      int len = strlen(arrString[i]);
      if(len==0 || arrString[i][len] != '\n')
	{
	  printf("\n");
	}      
    }
}



/* ----------------------------------------------- */
/*
 * Write integers to a file, one integer per line
 *
 * Arguments:
 *
 * filename: the name of a file.
 * arrInteger: an array of integers
 * numInteger: the number of integers 
 *
 * Returns:
 * 1 if saving to the file successfully
 * 0 if *any* error is encountered
 *
 * Hint: use fprintf(... %d
 *
 */

int saveInteger(char * filename, int * arrInteger, int numInteger)
{
  FILE *fptr = fopen(filename, "w"); //file pointer to work with throughout this function
  int i; //counter variable 
  if(fptr==NULL)
    {
      return(0);
    }
  for(i=0;i<numInteger;i++)
    {
      fprintf(fptr, "%d\n", arrInteger[i]);
    }

  fclose(fptr);
  return(1);
}

/* ----------------------------------------------- */
/*
 * Write strings to a file, one string per line
 *
 * Arguments:
 *
 * filename: the name of a file.
 * arrString: an array of strings
 * numString: the number of strings 
 *
 * Returns:
 * 1 if saving to the file successfully
 * 0 if *any* error is encountered
 *
 * Hint: use fprintf(... %s
 *
 */

int saveString(char * filename, char * * arrString, int numString)
{
  FILE *fptr = fopen(filename, "w"); //file pointer to work with in this function 
  int i; //counter variable
  if(fptr==NULL)
    {
      return(0);
    }
  for(i=0;i<numString;i++)
    {
      fprintf(fptr, "%s", arrString[i]);
      int len = strlen(arrString[i]);
      if(len==0 || arrString[i][len] != '\n')
	{
	  fprintf(fptr, "\n");
	}
    }
  fclose(fptr);
  return(1);
}

/* ----------------------------------------------- */
/*
 * sort an arry of integers by calling the built-in qsort function in
 * the C library.  You need to provide the comparison function. Please
 * read the Linux manual about qsort
 *
 */
int compInt(const void *p1, const void *p2)
{
  int * intp1 = (int*)p1; //pointer that points to p1 
  int * intp2 = (int*)p2; //pointer that points to p2
  int intv1 = *intp1; //variable that holds value at p1
  int intv2 = *intp2; //variable that holds value at p2
  if(intv1<intv2) 
    {
      return(-1);
    }
  if(intv1 == intv2)
    {
      return(0);
    }
  return(1);
   
}
void sortInteger(int * arrInteger, int numInteger)
{
  qsort(&arrInteger[0], numInteger, sizeof(int), compInt);
}


/* ----------------------------------------------- */
/*
 * sort an arry of strings by calling the built-in qsort function in
 * the C library.  You need to provide the comparison function. Please
 * read the Linux manual about qsort
 *
 * Hint: use strcmp in the comparison function
 *
 */

int compStr(const void * p1, const void * p2)
{
  char * * strp1 = (char**)p1; //variable to hold string of p1
  char * * strp2 = (char**)p2; //variable to hold string of p2
  char * str1 = *strp1; //value at pointer strp1
  char * str2 = *strp2; //value at pointer strp2

  return(strcmp(str1, str2));
}
void sortString(char * * arrString, int numString)
{
  qsort(arrString, numString, sizeof(char*), compStr);
}


