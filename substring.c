/* File: substring.c
 * Date: 18-11-2023
 * 
 * Copyright (C) 2023 Iurie Jurja
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUBSTRING_MAJOR 1
#define SUBSTRING_MINOR 0
#define SUBSTRING_PATCH 0

#define LICENSE         "GNU General Public License version 3"

void print_help() {
  fprintf(stdout, "usage: substring [--help|-h|--version|-v] <string> <start> <length>\n");
}

void print_version() {
  fprintf(stdout, "substring %d.%d.%d\n", SUBSTRING_MAJOR, SUBSTRING_MINOR, SUBSTRING_PATCH);
  fprintf(stdout, "Copyright (C) 2023 Iurie Jurja\n");
  fprintf(stdout, "Licensed under the terms and conditions of the %s\n\n", LICENSE);
  fprintf(stdout, "This program comes with absolutely NO WARRANTY.\n");
  fprintf(stdout, "This is free software, and you are welcome to redistribute it\n");
  fprintf(stdout, "under certain conditions.\n");
}

int main(int argc, char* argv[]) {  
  if (argc == 1) {
    fprintf(stderr, "error: substring requires at least two arguments\n");
    return EXIT_FAILURE;
  } else if (argc == 2) {
    if (strcmp(argv[1], "--help") == 0
     || strcmp(argv[1], "-h") == 0
     || strcmp(argv[1], "-?") == 0) {
      print_help();
      return EXIT_SUCCESS;
    } else if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0) {
      print_version();
      return EXIT_SUCCESS;
    } else {
      fprintf(stderr, "error: unrecognized argument: %s\n", argv[1]);
      return EXIT_FAILURE;
    }
  } else if (argc > 4) {          /* only three arguments are enough */
    fprintf(stderr, "error: too many arguments\n");
    return EXIT_FAILURE;
  }

  char* str = argv[1]; /* the string in the substring command is considered as the first argument */
  int start = atoi(argv[2]); /* the start argument is mandatory */

  /* if argv[3] is null, then the variable length is set to its default value */
  int length = strlen(str) - start;
  if (argv[3] != NULL) length = atoi(argv[3]);

  char* result = (char*)malloc(512 * sizeof(char*));
  int i;

  for (i = 0; i < length; i++) {
    result[i] = str[i + start];
  }

  fprintf(stdout, "%s\n", result);
  
  return EXIT_SUCCESS;
}
