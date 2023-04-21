#include <stdio.h>
#include <stdlib.h>
#include "caesar.h"

int caesar_cipher(FILE* input_file, FILE* output_file, int shift) {
    int c;

    while ((c = fgetc(input_file)) != EOF) {
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + shift) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + shift) % 26 + 'A';
        }

        fputc(c, output_file);
    }

    return 0;
}

