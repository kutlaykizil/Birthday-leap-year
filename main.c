/*
* MIT License

* Copyright (c) 2020 Kutlay KIZIL

* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:

* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.

* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //after this I think I've ascended.//
char* leap(int year);
int main(void)
{
  printf("YEAR | NAME   | LEAP YEAR?\n");
	char years[10][16]={"2000 | KUTLAY", "1966 | FATIH ", "2006 | ÜLKÜ  ", "1970 | AYÇİN ", "2002 | SELİN ", "2001 | ELİF  ", "1996 | SARP  ", "1975 | FERHAT", "1982 | HALİL ", "2008 | BEREN "};
  char a[16]; //This is like a temporary storage while sorting the characters in array.//
	int i, j;
  for (i = 0; i < 10; i++)
  {
    for (j = i + 1; j < 10; j++)
    {
      int x = atoi(years[i]), y = atoi(years[j]);/*I couldn't bind the years and names while they're in different arrays, I had to put 
                                                  both of them into a string array but I couldn't find a way to use just the numbers in strings
                                                  after a long search I've found "atoi" in stdlib.h library.*/
      if (x > y)
      {//Also I couldn't assign the arrays to each other after making them string arrays so I had to copy them to each other that's why I've used "strcpy" and had to include string.h library.//
        strcpy(a, years[i]);
        strcpy(years[i], years[j]);
        strcpy(years[j], a);        
      }
    }
  }        
  for (i = 0; i < 10; i++)
  {
    int x = atoi(years[i]);
    printf("%s | %s\n", years[i], leap(x));
  }
  return 0;
}
char* leap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
  return "yes";
	else
	return "no";//Honestly I had no idea that I could use return as literally returning a word, good to know.//
}
