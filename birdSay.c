#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ascii[] = {"     \\                    ",                
                 "      \\    __              ",
                 "         <{@ \\             ",
                 "      _____) (_____         ",
                 "     //'--;   ;--'\\\\       ", 
                 "    ///////\\_//\\\\\\\\\\\\      ",
                 "           m m             "};

void print_ascii(void);
void print_message(char*, int);
void print_message_multilines(char*, int);
void clean_stdin(void);

int main(int argc, char* argv[])
{
    int length = 0;
    char message[1000] = {0};
    
    if(argc >= 2)
   {
        if((length = strlen(argv[1])) < 42)
        {
            print_message(argv[1], length);
        }
        else
        {
            print_message_multilines(argv[1], length);
        }
    }
    else
    {
        printf("Enter message: \n");
        scanf("%[^\n]s", message);

	if (strlen(message) > 255){
	  printf("Usage: 255 character limit\n");
	  exit(EXIT_FAILURE);
	}	 
        if((length = strlen(message)) < 42)
        {
            print_message(message, length);
        }
        else
        {
            print_message_multilines(message, length);
        }
    }
   
    print_ascii();
    printf("\n");
    exit(EXIT_SUCCESS);
    return 0;
}

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
    exit(EXIT_SUCCESS);
}

void print_ascii(void)
{
    int i;
    for(i = 0; i < 7; i++)
    {
        printf("%s\n", ascii[i]);
    }
}

void print_message_multilines(char* message, int length)
{
    printf("\n");
    int nb_chunk = (length/42)+1;
    char** strings = calloc(nb_chunk, sizeof(char*));
    
    int i;
    int j;
    for(i = 0; i < nb_chunk; i++)
    {
        strings[i] = calloc(43, sizeof(char));
    }
    
    for(i = 0; i < nb_chunk; i++)
    {
        for(j = 0; j < 42; j++)
        {
            strings[i][j] = message[i*42+j];
        }
    }
    
    for(i =(length%42); i < 42; i++)
    {
        strings[nb_chunk-1][i] = ' ';
    }
    
    
    putc(' ', stdout);
    putc('/', stdout);
    
    for(i = 0; i < strlen(strings[0]); i++)
    {
        putc('-', stdout);
    }
    putc('\\', stdout);
    putc('\n', stdout);
    
    for(i = 0; i < nb_chunk; i++)
    {
        printf("| %s |\n", strings[i]);
    }
    
    putc(' ', stdout);
    putc('\\', stdout);
    
    for(i = 0; i < strlen(strings[0]); i++)
    {
        putc('-', stdout);
    }
    putc('/', stdout);
    putc('\n', stdout);
    
    for(i = 0; i < nb_chunk-1; i++)
    {
        free(strings[i]);
    }
    
    free(strings);
}

void print_message(char* message, int length)
{
    printf("\n");
    printf("%s \n", message);
}
