#pragma once

#include <common.h>

class Cartridge
{
  int rom_size;
  byte *rom;

  // Header data
  char title[13]; 
  char game_code[5]; // 4 bytes + \0
  bool rom_integrity; // False -> checksum didnt match (probably modified or corrupted) RUNS ANYWAY
  
  public:
    Cartridge(char *rom_path);
    void hello_cartridge();
    
};
