//
// Created by Dan Lynch on 4/19/20.
//

/* This is a program that can take either a file from the command line or input from STDIN and 
 * prints a new word from that input on a new line. The program is able to do this using 
 * switch cases.
 */


#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
int i=1;
int memorySize = 100;

char c;

int main(int argc, char *argv[]) {
//if no file name given take input from stdin

    FILE *fp_i, *fp_o;
    fp_i = fopen("data", "r");
    fp_o = fopen("data_out", "w");

    switch (argc - 1) {
//use scanf to take from stdin to print words, each on a new line 
        case 0:
        while (scanf("%c", &c)==1){
            if (c==' '){
                printf("\n");
            }
            else{
                printf("%c", c);
            }
        }
        break;
//if a file argument is given, open a file, make an output file, and write words, each on 
//a new line, to that new file. Make sure to close both when finished. 
        case 1:
            fgetc(fp_i);
            while (c != EOF) {
                if (isspace(c)){
                    fputc("\n", fp_o);
                }
                if (isalpha(c)) {
                    fputc(c, fp_o);
                }
            }
            fclose(fp_i);
            fclose(fp_o);
            break;
    }

}
