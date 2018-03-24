#include <stdio.h>
#include <string.h>
#include <windows.h>
#define SIZE 8192

char *charToBf(char cell);

int main(int argc, char** argv)
{   
    if(argc < 2){
        fprintf(stderr, "no input");
        return 1;
    }
    int i, j;
    char  cell;

    FILE * file = fopen("temporarybf.c","w");

    fprintf(file,\
        "#include <stdio.h>\n\n"
        "#define SIZE %d"  
        "////////////////////\n"
        "int main(){\n"
        "char tape[SIZE];\n"
        "char *p = &(tape[SIZE/2]);\n"
        "for(int i = 0; i < SIZE; i++ ){tape[i] = 0;}\n", SIZE);

    for(j = 1; j < argc; j++)
    {
        do{
            cell = argv[j][i];
            fprintf(file,"%s",charToBf(cell));
            i++;
        }while(cell!='\0');
    }

    fprintf(file,"return 0;}");
    fclose(file);

    //compile
    system("gcc -o tmpbf temporarybf.c");
    system("tmpbf");
    remove("temporarybf.c");
    return 0;
}

char *charToBf(char cell)
{
    char *bf;

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
        bf = "*p=getchar();";
    else
        bf = "";

    return bf;
}

