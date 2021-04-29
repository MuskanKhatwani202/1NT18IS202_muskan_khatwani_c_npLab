//design a c program to implement bit stuffing encoding decoding concept in data link layer

#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

int main()
{
  char *p,*q;
  char temp;
  char in[MAXSIZE], stuff[MAXSIZE], unstuff[MAXSIZE];
  int count=0;
  printf("enter the frame (0‘s & 1‘s only):\n");
  scanf("%s",in);
  
  p=in;
  q=stuff;
  
  while(*p!='\0')
  {
    if(*p=='0')
    {
      *q=*p;
      q++;
      p++;
    }
    else
    {
      while(*p=='1' && count!=5)
      {
        count++;
        *q=*p;
        q++;
        p++;
      }
      
      if(count==5)
      {
        *q='0';
        q++;
      }
      count=0;
    }
  }
  *q='\0';
  printf("\nthe encoded message is");
  printf("\n%s",stuff);
  
  p=stuff;
  q=unstuff;
  while(*p!='\0')
  {
    if(*p=='0')
    {
      *q=*p;
      q++;
      p++;
    }
    else
    {
      while(*p=='1' && count!=5)
      {
        count++;
        *q=*p;
        q++;
        p++;
      }
      if(count==5)
        p++;
      count=0;
    }
  }
  *q='\0';
  printf("\nthe decoded message is");
  printf("\n%s\n",unstuff);
  return 0;
}
