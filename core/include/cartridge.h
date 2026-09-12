#pragma once

#include <common.h>

class cartridge
{
  char title[13];
  int rom_size;
  byte *rom;

  public:
    cartridge(char *rom_path);
    void hello_cartridge();
};

