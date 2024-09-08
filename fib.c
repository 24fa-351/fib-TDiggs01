#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fibRecursion(int nNum) {
      if(nNum == 0) { return 0; }
      else if(nNum == 1) { return 1; }
      return fibRecursion(nNum - 1) + fibRecursion(nNum - 2);
   }

int fibIterative(int nNum) {
   int a, cur = 0, b = 1;

   if(nNum == 0) { return 0; }
   else if(nNum == 1) { return 1; }
   for(int i = 1; i < nNum; i++) {
      a = b;
      b = cur;
      cur = a + b;
   }
   return cur;
}

int main(int argc, char *argv[]) {

   FILE *infile;
   int N, i;

   /*Check for correct number of arguments*/

   if(argc != 4) {
      printf("Usage: %s <num> <char> <file>\n", argv[0]);
      return 1;
   }

   /*Open file*/
   infile = fopen(argv[3], "r");
   if(infile == NULL) {
      fprintf(stderr, "Cannot open file: %s\n", argv[3]);
      return 3;
   }

   /*Reading file*/
   fscanf(infile, "%d", &i);

   /*Adding first argument with integer in file*/
   N = atoi(argv[1]) + i;

   /*Computing Nth Fibonacci*/
   if(strcmp(argv[2], "r") == 0) {
      printf("%d", fibRecursion(N - 1));
   }
   else if(strcmp(argv[2], "i") == 0) {
      printf("%d", fibIterative(N));
   }
   
   /*Close file*/
   fclose(infile);

   return 0;
}
