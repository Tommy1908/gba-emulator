#include <emu.h>

int emu_run(int argc, char **argv){
  if(argc < 1){
    fprintf(stderr, "Usage: ./gbaemu <path/to/rom>\n");
    return -1;
  }
  Cartridge cart(argv[1]);
  cart.hello_cartridge();
  return 0;
}

