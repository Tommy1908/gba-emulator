#pragma once

#include <common.h>


class cartridge
{
  char title[13];
  byte *rom;
  
  public:
    void hello_cartridge(char *rom_path);
};


void hello_cartridge(char *rom_path);