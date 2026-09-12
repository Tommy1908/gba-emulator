#include <cartridge.h>
#include <stdint.h>
#include <iostream>


void hello_cartridge(char *rom_path){

  printf("Hola cartucho\n");

  uint8_t *rom;
  int rom_size;
  
  FILE *rom_file = fopen(rom_path,"r");
  if(rom_file == NULL){
    perror("Error opening rom");
    return;
  }
  printf("Rom Opened\n");
  
  // Get rom size
  fseek(rom_file,0,SEEK_END);
  rom_size = ftell(rom_file); // final position
  rewind(rom_file);

  rom = (uint8_t*)malloc(rom_size);
  fread(rom,rom_size,1,rom_file);
  
  // Print title
  char title[13];
  int title_offset = 0x0A0;
  for(int i = 0; i<12; i++){
    title[i] = rom[title_offset+i];
  }
  title[12] = 0;

  printf("Game Title: %s\n", title);
}
