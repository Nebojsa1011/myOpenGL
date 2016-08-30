#include "MD5.h"
#include <stdio.h>
using namespace MD5;

int main(int argc,char *argv[] ) {

  if (argc >= 2) {
      MD5MeshParser mesh_parser;
      printf("Parsing file: %s\n", argv[1]);
      mesh_parser.parseMD5File(argv[1]);
    }

  return 0;
}
