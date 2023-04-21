#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "caesar.h"

int main(int argc, char** argv) {
    char* input_filename = NULL;
    char* output_filename = NULL;
    int shift = 13;

    int option;
    static struct option long_options[] = {
        {"input", required_argument, 0, 'i'},
        {"output", required_argument, 0, 'o'},
        {"shift", required_argument, 0, 's'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };
    int option_index = 0;

    while ((option = getopt_long(argc, argv, "i:o:s:h", long_options, &option_index)) != -1) {
        switch (option) {
            case 'i':
                input_filename = optarg;
                break;
            case 'o':
                output_filename = optarg;
                break;
            case 's':
                shift = atoi(optarg);
                break;
            case 'h':
                printf("Usage: %s [-i/--input input_file] [-o/--output output_file] [-s/--shift shift] [-h/--help]\n", argv[0]);
                return 0;
            default:
                printf("Usage: %s [-i/--input input_file] [-o/--output output_file] [-s/--shift shift] [-h/--help]\n", argv[0]);
                return 1;
        }
    }

    FILE* input_file = stdin;
    if (input_filename != NULL) {
        input_file = fopen(input_filename, "r");
        if (input_file == NULL) {
            fprintf(stderr, "Error: Cannot open input file %s\n", input_filename);
            return 1;
        }
    }

    FILE* output_file = stdout;
    if (output_filename != NULL) {
        output_file = fopen(output_filename, "w");
        if (output_file == NULL) {
            fprintf(stderr, "Error: Cannot open output file %s\n", output_filename);
            return 1;
        }
    }

    caesar_cipher(input_file, output_file, shift);

    fclose(input_file);
    fclose(output_file);

    return 0;
}
