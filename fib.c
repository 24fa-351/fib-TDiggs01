#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fib_recursion( int nth_term ) {

   if( nth_term == 0 ) {
      return 0;
   }
   else if( nth_term == 1 ) {
      return 1;
   }
   return fib_recursion( nth_term - 1 ) + fib_recursion( nth_term - 2 );
}



int fib_iterative( int nth_term ) {
   
   int previous_a;

   int previous_b = 1;   
   
   int current = 0;

   if( nth_term == 0 ) { 
      return 0;
   }
   else if( nth_term == 1 ) {
      return 1;
   }
   for( int ix = 1; ix < nth_term; ix++ ) {
      previous_a = previous_b;
      previous_b = current;
      current = previous_a + previous_b;
   }
   
   return current;
}
int main( int argc, char *argv[] ) {

   FILE *infile;

   int N;
   
   int int_in_file;

   int _TWO = 2;

   int _THREE = 3;

   int _FOUR = 4;

   /*Check for correct number of arguments*/
   if( argc != _FOUR ) {
      printf( "Usage: %s <num> <char> <file>\n", argv[0] );
      return 1;
   }

   /*Open file*/
   infile = fopen( argv[_THREE], "r" );
   if(infile == NULL) {
      fprintf( stderr, "Cannot open file: %s\n", argv[_THREE] );
      return _THREE;
   }

   /*Reading file*/
   fscanf( infile, "%d", &int_in_file );

   /*Adding first argument with integer in file*/
   N = atoi( argv[1] ) + int_in_file;

   /*Computing Nth Fibonacci*/
   if(strcmp( argv[_TWO], "r" ) == 0) {
      printf( "%d", fib_recursion( N - 1) );
   }
   else if( strcmp( argv[_TWO], "i") == 0 ) {
      printf( "%d", fib_iterative( N ) );
   }
   
   fclose( infile );

   return 0;
}
