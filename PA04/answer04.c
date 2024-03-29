/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 * You can test your functions with your own input file.
 * See details in README or typing command ./pa04 in terminal after make.
 * See output format examples in any of the files in directory expected.
 * 
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa04.h.
 */

#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>



/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * For example, if the value is 3:
 *
 * partitionAll 3
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 */
void print_arr(int *arr, int length)
{
  int i; //The following is my function to print the array of partitions throughout the program
  printf("= ");
  if(length>0)
    {
      printf("%d", arr[0]);
    }
  for(i=1; i<length; i++)
    {
      printf(" + %d", arr[i]);
    }
  printf("\n");
}
void partition_helper(int * arr, int pos, int n)
{
  if(n<= 0)
    {
      print_arr(arr, pos);
      return;
    }

  int i; //counter variable 
  for(i=1; i<=n; i++)
    {
      arr[pos] = i;
      partition_helper(arr, pos+1, n-i);//recalls the helper to break the problem into smaller and smaller parts
    }
}

void partitionAll(int value)
{
  printf("partitionAll %d\n", value);
  int * arr = malloc(sizeof(int)*value); //allocate mem for arr
  partition_helper(arr, 0, value); //first call of partitionAll
  free(arr); //free the mem used by arr
}
/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */

void partition_helper_inc(int * arr, int pos, int n)
{
  if(n<= 0)
    {
      print_arr(arr, pos);
      return;
    }

  int i;
  for(i=1; i<=n; i++)
    {
      if((i > arr[pos-1]) || (pos==0)) //if the numbers are increasing then it is a valid partition 
	{
	  arr[pos] = i;
	  partition_helper_inc(arr, pos+1, n-i);
	}
    }
}
void partitionIncreasing(int value)
{
  printf("partitionIncreasing %d\n", value);
  int * arr = malloc(sizeof(int)*value);
  partition_helper_inc(arr, 0, value);
  free(arr);
}

/*
 * =================================================================
 * This function prints the partitions that use Decreasing values.
 *
 * For example, if value is 5
 * 3 + 2 and
 * 4 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */
void partition_helper_dec(int * arr, int pos, int n)
{
  if(n<= 0)
    {
      print_arr(arr, pos);
      return;
    }

  int i;
  for(i=1; i<=n; i++)
    {
      if((i < arr[pos-1]) || (pos==0)) //only assembles decreasing partitions of n
	{
	  arr[pos] = i;
	  partition_helper_dec(arr, pos+1, n-i);
	}
    }
}

void partitionDecreasing(int value)
{
  printf("partitionDecreasing %d\n", value);
  int * arr = malloc(sizeof(int)*value);
  partition_helper_dec(arr, 0, value);
  free(arr);

}

/*
 * =================================================================
 * This function prints odd number only partitions of a positive integer value
 * For example, if value is 5
 * 1 + 1 + 1 + 1 + 1 and
 * 1 + 3 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 1 + 2 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partition_helper_odd(int * arr, int pos, int n)
{
  if(n<= 0)
    {
      print_arr(arr, pos);
      return;
    }

  int i;
  for(i=1; i<=n; i++)
    {
      if((i%2)==1) //if the partition has only odd numbers, assemble it
	{
	  arr[pos] = i;
	  partition_helper_odd(arr, pos+1, n-i);
	}
    }
}

void partitionOdd(int value)
{
  printf("partitionOdd %d\n", value);
  int * arr = malloc(sizeof(int)*value);
  partition_helper_odd(arr, 0, value);
  free(arr);
}

/*
 * =================================================================
 * This function prints even number only partitions of a positive integer value
 * For example, if value is 8
 * 2 + 2 + 2 + 2and
 * 2 + 4 + 2 are valid partitions
 *
 * 8 is a valid partition
 *
 * 2 + 1 + 1 + 2 + 2and
 * 2 + 1 + 2 + 3and
 * 5 + 3 are invalid partitions.
 *
 * if the value is 5, there will be no result generated
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partition_helper_even(int * arr, int pos, int n)
{
  if(n<= 0)
    {
      print_arr(arr, pos);
      return;
    }

  int i;
  for(i=1; i<=n; i++)
    {
      if((i%2)!=1) //if the partition has only even numbers, assemble it 
	{
	  arr[pos] = i;
	  partition_helper_even(arr, pos+1, n-i);
	}
    }
}

void partitionEven(int value)
{
  printf("partitionEven %d\n", value);
  int * arr = malloc(sizeof(int)*value);
  partition_helper_even(arr, 0, value);
  free(arr);
}

/*
 * =================================================================
 * This function prints alternate ood and even number partitions of a positive integer value. Each partition starts from and odd number, even number, ood number again, even number again...etc.
 *
 * For example, if value is 6
 * 1 + 2 + 1 + 2 and
 * 3 + 2 + 1 are valid partitions
 *
 * 6 is not a valid partition
 *
 * 2 + 1 + 1 + 2 and
 * 2 + 1 + 3and
 * 5 + 1 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */
void partition_helper_oddeven(int * arr, int pos, int n)
{
  if(n == 0)
    {
      print_arr(arr, pos);
    }

  int i; //This is the function that I cannot get to work, I have had help from Yung Lu and he said that the conditions are correct but it still doesnt produce correct output. 
  for(i=1; i<=n; i++)
    {
      if(((pos == 0) && (i%2 == 1)) || ((i%2 == 1) && (arr[pos - 1]%2 == 0)) || ((i%2 == 0) && (arr[pos - 1]%2 == 1)))
	{
	  arr[pos] = i;
	  partition_helper_oddeven(arr, pos+1, n-i);
	}
    }
}
void partitionOddAndEven(int value)
{
  printf("partitionOddAndEven %d\n", value);
  int * arr = malloc(sizeof(int)*value);
  partition_helper_oddeven(arr, 0, value);
  free(arr);
}

/*
 * =================================================================
 * This function prints prime number only partitions of a positive integer value
 * For example, if value is 6
 * 2 + 2 + 2 and
 * 3 + 3 are valid partitions
 *
 * 6 is not a valid partition
 * 
 * 2 + 4 and
 * 1 + 5 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

int check_prime(int n) //a mini function to determine if a number is prime or not
{
  int i;
  for(i=(n-1);i>1;i--)
    {
      if((n%i)==0)
	{
	  return (0);
	}
    }
  return (1);
}
void partition_helper_prime(int * arr, int pos, int n)
{
  if(n<= 0)
    {
      print_arr(arr, pos);
      return;
    }

  int i;
  for(i=2; i<=n; i++)
    {
      if(check_prime(i)) //if checkprime(i) comes back true then assemble the partition
	{
	  arr[pos] = i;
	  partition_helper_prime(arr, pos+1, n-i);
	}
    }
}


void partitionPrime(int value)
{
  printf("partitionPrime %d\n", value);
  int * arr = malloc(sizeof(int)*value);
  partition_helper_prime(arr, 0, value);
  free(arr);
}

