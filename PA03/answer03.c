#include "pa03.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Read a file of integers.
 *
 * Arguments:
 *
 * filename: the name of a file that contains a list of integers (one
 * per line)
 * 
 * numberOfIntegers: pointer to store the number of integers in the
 * file. You need to update the value stored at the address which is
 * the pointer's value
 *
 * Returns:
 *
 * a array of integers from the file, or NULL if *any* error is
 * encountered.
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
 * The allocated memory will be released in pa03.c. You do not need to
 * worry about releasing memory.
 *
 * You will receive zero if you allocate a large array whose size is
 * independent of the number of integers in the file.  For example, if
 * you write this
 *
 * int array[10000];
 * 
 *
 */

int * readIntegers(const char * filename, int * numberOfIntegers)
{
  FILE *start; // pointer for the start of the file to be read in
  int *array; //pointer to store the array that will be used for rest of program
  int i=0; //counter variable
  int temp=0; //temp variable used to find how many ints are in the text file
  start = fopen(filename, "r"); 
  if(start==NULL)   
    {
      return NULL;
    }
  else
    {
      while(fscanf(start, "%d", &temp)==1)
	{
	 (*numberOfIntegers)++;
	}
      fseek(start, 0, SEEK_SET);//brings the start pointer back to the beginning so it can be used again
      array = malloc(sizeof(int)*(*numberOfIntegers)); //allocating memory for array
      for(i=0; i<(*numberOfIntegers); i++)
	{
	  fscanf(start, "%d",&array[i]);
        }
      fclose(start);
      return(array);
    }
}

/**
 * Sort an (ascending) array of integers
 *
 * Arguments:
 * arr    The array to search
 * length Number of elements in the array
 *
 * Uses "quicksort" to sort "arr".  Use the first element of the array
 * as the pivot.  
 *
 * Your solution MUST use recursive function (or functions)
 * 
 * quicksort works in the following way: 
 * 
 * find an element in the array (this element is called the
 * pivot). 
 *
 * rearrange the array's elements into two parts: the part smaller
 * than this pivot and the part greater than this pivot; make the pivot
 * the element between these two parts
 * 
 * sort the first and the second parts separately by repeating the 
 * procedure described above
 * 
 * You will receive no point if you use any other sorting algorithm.
 * You cannot use selection sort, merge sort, or bubble sort.
 * 
 * Some students are fascinated by the name of bubble sort.  In
 * reality, bubble sort is rarely used because it is slow.  It is a
 * mystery why some students (or even professors) like bubble sort.
 * Other than the funny name, bubble sort has nothing special and is
 * inefficient, in both asymptotic complexity and the amount of data
 * movement.  There are many algorithms much better than bubble sort.
 * You would not lose anything if you do not know (or forget) bubble
 * sort.
 *
 */

void sort_help(int *arr, int left, int right)
{
  int piv = *(arr+left); //declaring the pivot for the quick sort
  int left1 = left; //copy of the left # in this case starts at 0
  int right1 = right; //copy of rightmost number, in this case the end of the array

  while(left<right) 
    {
      while((*(arr+right)>=piv) && (left<right))
	{
	  right--; //decrements the rightmost number until it gets to the pivot
	}
      if(left != right)
	{
	  *(arr+left) = *(arr+right);  //swaps the value at array[left] and array[right]
	  left++; 
	}
      while((*(arr+left)<=piv) && (left<right))
	{
	  left++; //increments left number until it gets to the pivot
	}
      if(left!=right)
	{
	  *(arr+right) = *(arr+left); //swaps the variables within the array that correspond to left and right
	  right--;
	}
    }

  *(arr+left) = piv;  //moves the unsorted part of the array to where pivot used to be 
  piv = left; //pivot now becomes the part of the array that isnt sorted 
  left = left1; //restores value of left
  right = right1; //restores value of right
  
  if(left<piv)
    {
      sort_help(arr, left, piv-1); //recalls the function to keep sorting the array until it is completely sorted
    }
  if(right>piv)
    {
      sort_help(arr, piv+1, right);
      }
}

void sort(int * arr, int length)
{
  sort_help(arr, 0, length-1);  //initially calles the sort help, to begin the sorting process
}


/**
 * Use binary search to find 'key' in a sorted array of integers
 *
 * Arguments:
 * 
 * arr The array to search. Must be sorted ascending.  You do not need
 *        to check. This array is from the result of your sort
 *        function. Make sure your sort function is correct before you
 *        start writing this function.
 *
 * length Number of elements in the array
 * key    Value to search for in arr
 *
 * Returns:
 * The index of 'key', or -1 if key is not found.
 *
 * Since the array is sorted, you can quickly discard many elements by
 * comparing the key and the element at the center of the array. If
 * the key is the same as this element, you have found the index.  If
 * the key is greater than this element, you can discard the first
 * half of the array.  If the key is smaller, you can discard the
 * second half of the array.  Now you have only half of the array to
 * search.  Continue this procedure until either you find the index or
 * it is impossible to find a match.
 * 
 * Your solution MUST use recursive function (or functions)
 *
 * Don't forget that arrays are 'zero-indexed'. Also, you must
 * use a binary search to pass this question.
 * 
 * You will receive no point if you do the following because it is not
 * binary search.  This is called linear search because it checks
 * every element.
 *
 * int ind;
 * for (ind = 0; ind < length; ind ++)
 * {
 *    if (arr[ind] == key)
 *    {
 *       return ind;
 *    }
 * }
 * return -1;
 */

int search_help(int *arr, int first, int last, int key)
{
  int mid; //initilizes a new variable mid

  if(last<first) //if there is nothing in the array return a null variable
    {
      return(-1);
    }
  else
    {
      mid = (first+last)/2; //creates the mid variable by dividing the length by 2
      if(key > arr[mid])
	{
	  return search_help(arr, mid+1, last, key); // if the # we are looking for is greater than the # at the middle index then recall the search but this time the beginning of this array is the number at middle index +1
	}
      else if(key < arr[mid])
	{
	  return search_help(arr, first, mid-1, key); //if the # we are searching for is less than the value at mid, then get rid of the last half and reuse the search function
	}
      else
	{
	  return(mid); // if the number we are looking for is at mid, then return the index of mid
	}   
    }
}

int search(int * arr, int length, int key)
{
  int first = 0; //initializes start of the array
  int last = length-1;  // end of the array is at length -1
  int index=-1; //initialize the index to the null variable

  index = search_help(arr, first, last, key);   //the index is equal to the first call of search help, search help will return the value of index

  return(index); 
}
