#include <cartridge.h>

cartridge::cartridge(char *rom_path){
  FILE *rom_file = fopen(rom_path, "r");
  if(rom_file == NULL){
    perror("Error opening rom");
    exit(EXIT_FAILURE);
  }

  printf("Rom Opened\n");
  
  // Get rom size
  fseek(rom_file,0,SEEK_END);

  // final position
  rom_size = ftell(rom_file);
  rewind(rom_file);

  rom = (byte*)malloc(rom_size);
  fread(rom,rom_size,1,rom_file);
  
  int title_offset = 0x0A0;
  for(int i = 0; i<12; i++){
    title[i] = rom[title_offset+i];
  }
  title[12] = 0;
}

void cartridge::hello_cartridge(){
  printf("Hola cartucho\n");
  printf("Game Title: %s\n", title);
}

