#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
void sort(long* array) {
   int i=0;
   bool sorted;

   do {
      sorted = true;
      for (i=0; i< 32; i++) {
        if(array[i] > array[i + 1]) {
            long swap_store = array[i];
            array[i] = array[i + 1];
            array[i + 1] = swap_store;
            sorted = false;
        }
      }
   } while ( !sorted );
}

int main() {
   long array[32];
   int i=0;

   srand(time(NULL));
   for (i=0; i<rand() % 32; i++) {       
      array[i] = rand();
   }
   sort(array);

   //print array
   for (i = 0; i < 32; i++)
   {
    printf("%ld \n", array[i]);
   }
   
   return 0;
}
