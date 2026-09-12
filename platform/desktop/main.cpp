#include <iostream>
#include "cartridge.h"

int main(int argc, char **argv){
  printf("Hola mundo\n");
  
  char *rom_path = argv[1];
  hello_cartridge(rom_path);
  return 0;
}

