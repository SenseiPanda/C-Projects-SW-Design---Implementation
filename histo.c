
/* Created by Dan Lynch on 4/18/20.
  A 2nd-year MBA student at Tuck
This programs reads in from stdin a number of integers and groups their frequency into  16 bins
*/
#include <stdio.h>


int main() {
    int maxValue = 16;
    //initial size of the bucket is just 1
    int size = 1;
    int input;

    //declare an array of size 16
    int histogram[16];
    //scan over inputs and start incrementing numbers in bins, adjusting bin sizes as needed
    while (scanf("%d", &input) == 1) {
        //test to see if new max value
        while (input > maxValue - 1) {
            maxValue = maxValue * 2;
            size = size * 2;
            //if a new max
            //do integer
            //one and two should be grouped 
            // 3 and 4 should also be grouped The first two should become the first bucket  their sum
            for (int i = 0; i < 8; i++) {
                histogram[i] = histogram[i * 2] + histogram[i * 2 + 1];
            }
            for (int i = 8; i < 15; i++) {
                histogram[i] = 0;
            }
        }
        histogram[input/size] += 1;

    }
    //write code to display histogram
 for (int j = 0; j<16; j++){
     printf("%d\t%d\t%d\t", j, j*size, histogram[j-1]);
    
 }
}
