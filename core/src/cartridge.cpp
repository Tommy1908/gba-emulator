#include <cartridge.h>

Cartridge::Cartridge(char *rom_path){
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

  // Checksum for integrity of rom
  byte calculated_checksum = 0;
  for (int i = 0xA0; i <= 0xBC; i++) {
    calculated_checksum -= rom[i];
  }
  calculated_checksum = (calculated_checksum - 0x19); // Because docs
  byte header_checksum = rom[0xBD];

  // Title
  int title_offset = 0xA0;
  for(int i = 0; i<12; i++) title[i] = rom[title_offset+i];
  title[12] = '\0';

  // Game_code
  int game_code_offset = 0xAC;
  for(int i = 0; i<4; i++) game_code[i] = rom[game_code_offset+i];
  game_code[4] = '\0';
}

void Cartridge::hello_cartridge(){
  printf("Hola cartucho\n");
  printf("Integrity Check: %s\n", rom_integrity ? "OK" : "FAILED (Running anyway)");
  printf("Game Title: %s\n", title);
  printf("Game Code: %s\n", game_code);
  printf("ROM Size: %d bytes (%d MB)\n", rom_size, rom_size / 1024 / 1024);}


