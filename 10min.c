#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COL 64
//random 4096 block of data from heap to txt file

int main(int a, char**b){
    FILE * pfile = fopen("block.txt","w");
    int SIZE = atoi(b[1]);
    
    if(SIZE == 0){
        printf("defaults to 4096\n");
        SIZE = 4096;
    }

    char * pint = malloc(SIZE);

    int i,j;
    for(i = 0; i < SIZE/COL; i++)
    {
        for(j = 0; j < COL; j++)
        {
            putc(pint[i*COL+j],pfile);
            putc(pint[i*COL+j],stdout);
        }
        putc('\n',pfile);
        putc('\n',stdout);
    }
    
    free(pint);
    fclose(pfile);
    return 0;
}