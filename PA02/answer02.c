#include "pa02.h"

/**
 * Count the number of characters in a null-terminated string 's' 
 * (not counting the null character).
 *
 * Example: my_strlen("foo") should yield 3.
 */
int my_strlen(const char * s)
{
  int i; /*loop control variable*/
  int count = 0;/*counter for how many characters in string*/
  for(i=0; *(s+i) != '\0'; i++)
    {
      count++;
    }
    return count;
}

/**
 * Count the number of occurrences of a particular character 'c' in a
 * null-terminated string 's'.
 *
 * Example: my_countchar("foo", 'o') should yield 2.
 */
int my_countchar(const char * s, char c) 
{
  int i;
  int count=0;
  for(i=0; *(s+i) != '\0'; i++)
    {
      if(*(s+i) == c)
	{
	  count++;
	}
    }
    return count;
}

/**
 * Convert an entire null-terminated string 's' to uppercase.  Only
 * alphabetical characters should be converted; numbers and symbols
 * should not be affected.  Hint: toupper(c) is a macro that yields
 * the uppercase version of a character c.
 *
 * Example: char foobar[10] = "foobar";
 * my_strupper(foobar) yields "FOOBAR".
 */
void my_strupper(char * s)
{
  int i;
  for(i=0; *(s+i)!='\0'; i++)
    {
      if(*(s+i) < 123 && *(s+i) >96) /*if the character is either a lower or uppercase letter it gets turned to an uppercase*/
	{
	  *(s+i) -= 32;
	}
    }
}

/**
 * Convert an entire null-terminated string 's' to lowercase.  Only
 * alphabetical characters should be converted; numbers and symbols
 * should not be affected.  Hint: tolower(c) is a macro that yields
 * the lowercase version of a character 'c'.
 *
 * Example: char foobar[10] = "FOOBAR";
 * my_strupper(foobar) yields "foobar".
 */
void my_strlower(char * s)
{
  int i;
  for(i=0; *(s+i)!='\0'; i++)
    {
      if(*(s+i) < 91 && *(s+i) > 64) /*same as above but everything gets turned to lowercase*/
	{
	  *(s+i) += 32;
	}
    }
}

/**
 * Copy the contents of a null-terminated string 's2' into the memory
 * pointed to by 's1'.  Any existing data in 's1' will be overwritten by
 * the contents of 's2'.  Note: you can assume that there is sufficient
 * memory available in 's1'.  Hint: Don't forget to terminate the new
 * string with '\0'!
 * 
 * Example: char foo[10];
 * my_strcpy(foo, "foo") yields "foo".
 */
void my_strcpy(char * s1, const char * s2)
{
  int i;
  for(i=0; *(s2+i)!='\0'; i++)
    {
      *(s1+i)= *(s2+i);
    }
  *(s1+i)= '\0';
}

/**
 * Copy the first 'n' characters of a null-terminated string 's2' into the
 * memory pointed to by 's1'. Any existing data in 's1' will be
 * overwritten by the contents of 's2'.  Note: you can assume that there
 * is sufficient memory available in 's1'.  Hint: Don't forget to
 * terminate the new string with '\0'!
 * 
 * Example: char foo[10];
 * my_strncpy(foo, "foo", 1) yields "f".
 */
void my_strncpy(char * s1, const char * s2, int num)
{
  int i;
  for(i=0; i < num; i++)
    {
      *(s1+i)= *(s2+i);
    }
  *(s1+i)= '\0';
}


/** 
 * Concatenate (append) the contents of a null-terminated string 's2'
 * onto the end of the null-terminated string 's1'.  Note: you can
 * assume that there is sufficient memory available in 's1'.  Hint:
 * Don't forget to terminate the new string with '\0'!
 * 
 * Example: char foo[10] = "foo";
 * my_strcat(foo, "bar") yields "foobar".
 */
void my_strcat(char * s1, const char * s2) 
{
  int i;
  int k;
  int j = 0; /* i,j, and k are all loop variables*/
  int count = 0;/*counter for how many characters in string*/
  for(i=0; *(s1+i) != '\0'; i++)
    {
      count++;
    }
  for(k=count; *(s2+j)!='\0'; j++)
    {
      *(s1+k+j) = *(s2+j);
    }
  *(s1+k+j)='\0';
}

/** 
 * Concatenate (append) the first n characters of a null-terminated
 * string 's2' onto the end of the null-terminated string 's1'.  Note: you
 * can assume that there is sufficient memory available in 's1'.  Hint:
 * Don't forget to terminate the new string with '\0'!
 * 
 * Example: char foo[10] = "foo";
 * my_strcat(foo, "bar", 1) yields "foob".
 */
void my_strncat(char * s1, const char * s2, int num)
{
  int i;
  int k;
  int j = 0;
  int count = 0;/*counter for how many characters in string*/
  for(i=0; *(s1+i) != '\0'; i++)
    {
      count++;
    }
  for(k=count; j < num; j++)
    {
      *(s1+k+j) = *(s2+j);
    }
  *(s1+k+j)='\0';
}

/**
 * Return a pointer to the first occurrence of a null-terminated
 * substring 's2' in a null-terminated string 's1'.  If 's2' does not appear
 * in 's1', the empty (NULL) pointer is returned.
 * 
 * Example: my_strstr("hello world!", "test") will yield 0 (NULL).
 * Example(2): my_strstr("foobar", "bar") will yield a pointer to the
 * "bar" portion of the "foobar" argument.
 */

const char *my_strstr(const char * s1, const char * s2)
{
  int count;
  int i;
  int j=0;
  int k=0;
  const char *s1start = s1; /*makes a variable to hold the starting point of s1*/
  for(count=0; *(s1+j)!='\0'; count++)
    {
      if(*(s1+j) == *(s2+k))
	{
	  j++;
	  k++;
	  i=1;
	}
      else
	{
	  j++;
	  k=0;
	  i=0;
	}
    }

  if(i==1)
    {
      return(s1start+j-k);
    }
  else
    {
      return 0;
    }
}



/**
 * Insert a null-terminated string s2 in the null-terminated string s1
 * at position pos.  All characters following position pos in s1 will
 * be moved to follow directly after the inserted characters from s2;
 * no characters will be overwritten.  Note: you can assume that there
 * is sufficient memory available in s1.
 * 
 * Hint: there is no need to create any temporary memory; simply copy
 * the contents of the string after position pos to its new location
 * starting from the back of the string and going forwards.
 * 
 * Insertions should happen BEFORE the character position referenced
 * by pos.  In other words, inserting s2 at position 0 (the first
 * character of a string) in s1 is equivalent to the string s2
 * followed by string s1.
 * 
 * If the character position pos is higher (or equivalent to) the
 * length of string s1, s2 will simply be appended to the end of s1
 * (i.e. it is equivalent to my_strcat(s1, s2);
 * 
 * Example: char foo[10] = "foo";
 * my_strinsert(foo, "bar", 0) yields "barfoo".
 * 
 * Example(2): char foo[10] = "foo";
 * my_strinsert(foo, "bar", 100) yields "foobar".
 */
void my_strinsert(char *s1, const char *s2, int pos)
{
  int length=0; /*length of s1*/
  int length2=0;/*length of s2*/
  int i;
  
  for(i=0; *(s2+i) != '\0'; i++)
    {
      length2++;
    }
  for(i=0; *(s1+i)!='\0'; i++)
    {
      length++;
    }
  int copy1 = length; /*a copy of the length for s1*/
  int tot = length+length2; /*total length when s1 and s2 are combined*/
   for(i=tot; i >= (tot-length); i--)
	{
	  *(s1+i)= *(s1+copy1);
	  copy1--;
	}
   for(i=0; i<length2;i++)
	{
	  *(s1+pos) = *(s2+i);
	  pos++;
	}
}

/**
 * Delete a portion of the null-terminated string s that starts at
 * character position pos and is length characters long.  All
 * characters following position pos + length in s will be moved up to
 * follow directly after the characters before position pos. 
 * 
 * Hint: there is no need to create any temporary memory; simply copy
 * the contents of the string after position pos + length to their new
 * location.
 * 
 * Deletions should happen BEFORE the character position referenced by
 * pos.  In other words, deleting position 0 (the first character of a
 * string) in s means will start deleting from the first character.
 *
 * If the character position pos is higher (or equivalent to) the
 * length of string s, the function will do nothing.
 * 
 * If the length of the deleted portion from its starting position pos
 * extends past the end of the string, the remainder of the string
 * will be deleted.
 * 
 * Example: char foo[10] = "foobar";
 * my_strdelete(foo, 3, 3) yields "foo".
 *
 * Example(2): char foo[10] = "foobar";
 * my_strdelete(foo, 0, 3) yields "bar".
 * 
 * Example(3): char foo[10] = "foobar";
 * my_strdelete(foo, 0, 34) yields "".
 * 
 * Example(4): char foo[10] = "foobar";
 * my_strdelete(foo, 2, 30) yields "fo";
 */
void my_strdelete(char *s, int pos, int length)
{
  int i;
  int len=0; /*length of string s, not to be confused with the length of portion of string to be deleted*/
  for(i=0; *(s+i)!='\0'; i++)
    {
      len++;
    }
  for(i=0; i<(len-length);i++)
    {
      *(s+pos+i) = *(s+pos+length+i);
    }
  *(s+pos+i) = '\0';
}
