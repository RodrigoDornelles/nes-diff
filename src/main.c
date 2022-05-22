#include <stdio.h>
/** #include <ctype.h> remove std **/
#include "nostd.h"

FILE* rom[2];

int main(int argc,char **argv)
{
    /* check arguments */
    if (argc <= 2) {
        printf("usage: %s [rom1] [rom2]\n", argv[0]);
        return 1;
    }

    /* check existence of files */
    for (char i = 0; i < 2; i++) {
        char header[3];
        rom[i] = fopen(argv[i + 1], "rb");
        if (rom[i] == NULL) {
            printf("error: no such file '%s'", argv[i]);
            return 1;
        }

        fgets(header, 3, rom[i]);
        if(strcmp(header, "NES") != 0) {
            printf("error: Invalid 'NES' header for file '%s'", argv[i]);
            return 1;
        }
    }

    /** compare **/
    {
        unsigned int address_count = 0xc000; /** program start in rom **/
        register int opcode1 = 0;
        register int opcode2 = 0;
        register int opcoded = 0;

        while(opcode1 != -1 && opcode2 != -1)
        {
            address_count++;
            opcode1 = fgetc(rom[0]);
            opcode2 = fgetc(rom[1]);
            opcoded = opcode1 - opcode2;
        
            if (opcoded != 0) {
                printf("%06x: %02x %02x  %c%c\n", address_count, opcode1, opcode2,
                    '.', '.'
                    /*isalpha(opcode1)?opcode1:'.', isalpha(opcode2)?opcode2:'.' */
                );
            }
        }
    }

    fclose(rom[0]);
    fclose(rom[1]);

    return 0;
}