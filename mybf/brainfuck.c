#include <stdio.h>
#include <windows.h>
#include <string.h>
#define SIZE 100000

// nailed it 

char *charToBf(char cell);

void openingCheck(FILE * pfile, char * fname)
{
    if(pfile == NULL)
    {
        fprintf(stderr, "Can't open <%s>\n", fname );
        exit(1);
    }
}


FILE * input(char * fname)
{
    FILE * inputf = fopen(fname, "r");
    openingCheck(inputf, fname);
    return inputf;
}

FILE * output(char * fname)
{
    FILE * outputf = fopen(fname, "w");
    openingCheck(outputf, fname);
    return outputf;
}


int main(int argc, char** argv)
{   
    if (argc < 2 || argc > 2){
        fprintf(stderr,"wrong number of input arguments" );
        return 1;
    }
    ///variables
    int i;
    char cell = 0;
    char *bf;
    char * input_name = *(argv+1);
    char output_name[40];
    char output_name_raw[40];
    char compile[50];

    for(i = 0; input_name[i] != '.' && i < 38; i++){
        output_name_raw[i] = input_name[i];
        output_name[i] = input_name[i];
    }
    if(i > 35){
        fprintf(stderr,"wrong input" );
        return 1;
    }
    output_name_raw[i] = 'b';
    output_name_raw[i+1] = 'f';

    output_name[i] = '.';
    output_name[i+1] = 'c';

    sprintf(compile, "gcc -o %s %s", output_name_raw, output_name);


    //else

    FILE * infp  = input(input_name);
    FILE * outfp = output(output_name);

    

    fprintf(outfp,\
        "#include <stdio.h>\n\n"
        "char tape[%d];\n"
        "char *p = &(tape[%d]);\n"    
        "////////////////////\n"
        "int main(){\n", SIZE, SIZE/2 );

    while(cell != EOF)
    {
        cell = getc(infp);
        bf   = charToBf(cell);

        fprintf(outfp, "%s\n", bf);
    }

    fprintf(outfp,"return 0;\n}");

    fclose(infp);
    fclose(outfp);


    //compile c file
    system(compile);
    system(output_name_raw );
    return 0;
}



char *charToBf(char cell){
    char *bf = "";

    if     (cell == '>')
        bf = "p++;";

    else if(cell == '<')
        bf = "p--;";

    else if(cell == '+')
        bf = "(*p)++;";

    else if(cell == '-')
        bf = "(*p)--;";

    else if(cell == '[')
        bf = "while(*p){";

    else if(cell == ']')
        bf = "}";

    else if(cell == '.')
        bf = "putchar(*p);";

    else if(cell == ',')
        bf = "*p = getchar();";

    return bf;
}

