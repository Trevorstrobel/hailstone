// Program:    Hailstone Sequence
// Author:     Trevor Strobel                                                                                                           
// File:       hailstone.cpp                                                                                                            
// Tab stops:  2                                                                                                                        

// This program reads a single positive integer, n, and                                                                                 
// writes information about the hailstone sequence that                                                                                 
// starts with n.  It shows the sequence, the sequence                                                                                  
// length, and the largest number in the sequence.                                                                                      
//                                                                                                                                      
// Example:                                                                                                                             
// Input:                                                                                                                               
//   5                                                                                                                                  
//                                                                                                                                      
// Output:                                                                                                                              
// The hailstone sequence starting with 5 is                                                                                            
// 5 16 8 4 2 1.                                                                                                                        
// The sequence length is 6.                                                                                                            
// The largest number in the sequence is 16.                                                                                            
// The longest hailstone sequence starting with a number up to 5 has length 8.                                                          
// The longest hailstone sequence starting with a number up to 5 begins with 3.                                                         

#include <cstdio>
using namespace std;

//------------------------------------------------                                                                                      
//                  next()                                                                                                              
//------------------------------------------------                                                                                      
//------------------------------------------------                                                                                      
// next(n) returns the number that follows n in                                                                                         
// a hailstone sequence.                                                                                                                
//                                                                                                                                      
//------------------------------------------------                                                                                      

int next(int n)
{
  int x = n;
  if(x > 1)
  {
    if(x % 2 == 0)
    {
      return  x/2;
    }
    else
    {
      return 3 * x + 1;
    }
  }
  return x;
}

//------------------------------------------------                                                                                      
//                  printSequence()                                                                                                     
//------------------------------------------------                                                                                      
//------------------------------------------------                                                                                      
// printSequence(n) prints the entire hailstone                                                                                         
// sequence, starting at n, until the sequence reaches                                                                                  
// 1, to stdout.                                                                                                                        
//                                                                                                                                      
//------------------------------------------------                                                                                      

void printSequence(int n)
{
  int x = next(n);

  if(x > 1)
  {
    printf("%d ", n);
    printf("%d ", x);
    printSequence(next(x));
  }
  else if ( x == 1)
  {
    printf("%d", x);
  }
}

//------------------------------------------------                                                                                      
//                  getLength()                                                                                                         
//------------------------------------------------                                                                                      
//------------------------------------------------                                                                                      
// getLength(n) returns the length of the hailstone                                                                                     
// sequence starting at n.                                                                                                              
//                                                                                                                                      
//------------------------------------------------                                                                                      

int getLength(int n)
{
  int x = n;
  if(x == 1)
  {
    return 1;
  }
  else
  {
    return 1+(getLength(next(x)));
  }
}

//------------------------------------------------                                                                                      
//                  getLargest()                                                                                                        
//------------------------------------------------                                                                                      
//------------------------------------------------                                                                                      
// getLargest(n) returns the largest value in the                                                                                       
// hailstone sequence starting at n.                                                                                                    
//                                                                                                                                      
//------------------------------------------------                                                                                      

int getLargest(int n)
{
  int x = n;

  if(x == 1)
  {
    return 1;
  }
  else
  {
    if(getLargest(next(x)) > x)
    {
      return getLargest(next(x));
    }
    else
    {
      return x;
    }
  }
}

//------------------------------------------------                                                                                      
//              getLongestSequence()                                                                                                    
//------------------------------------------------                                                                                      
//------------------------------------------------                                                                                      
// getLongestSequence(n) returns the length of the                                                                                      
// largest hailstone sequence starting a number from 1                                                                                  
// to n.                                                                                                                                
//                                                                                                                                      
//------------------------------------------------                                                                                      

int getLongestSequence(int n)
{
  int x = n, y = x - 1;

  if(x == 1)
  {
    return 1;
  }
  else
  {
    if(getLongestSequence(y) > getLength(x))
    {
      return getLongestSequence(y);
    }
    else
    {
      return getLength(x);
    }
  }
}

//------------------------------------------------                                                                                      
//             getLongestStart()                                                                                                        
//------------------------------------------------                                                                                      
//------------------------------------------------                                                                                      
// getLongestStart(n) returns the start value of                                                                                        
// the longest hailstone sequence starting on a                                                                                         
// number from 1 to n.                                                                                                                  
//                                                                                                                                      
//------------------------------------------------                                                                                      

int getLongestStart(int n)
{
  int x = n, y = x - 1;

  if(x == 1)
  {
    return 1;
  }
  else
  {
    if(getLongestSequence(y) > getLength(x))
    {
      return getLongestStart(y);
    }
    else
    {
      return x;
    }
  }
}

//------------------------------------------------                                                                                      
//                  main()                                                                                                              
//------------------------------------------------                                                                                      
//------------------------------------------------                                                                                      

int main()
{
  int input, length, largest, longest, starter;

  printf("What number shall I start with? ");
  if(scanf("%d", &input) == 1)
  {
    printf("The hailstone sequence starting at %d is:\n", input);
    printSequence(input);
    length = getLength(input);
    largest = getLargest(input);
    longest = getLongestSequence(input);
    starter = getLongestStart(input);


    printf("\nThe length of the sequence is %d.\n", length);
    printf("The largest number in the sequence is %d.\n", largest);
    printf("The longest hailstone sequence starting with a number up to %d"
           " has length %d.\n", input, longest);
    printf("The longest hailstone sequence starting with a number up to %d"
           " begins with %d.\n", input, starter);
  }
  else
  {
    return 1;
  }
  return 0;
}
