***
Hoy 12/09/26, empezamos con este proyectito...
Vamos a empezar por leer una rom para levantar la moral! :D
Queremos leer la ROM, e imprimir el titulo del juego

Vamos a basaron en https://mgba-emu.github.io/gbatek/#header-overview

Y conseguimos nuestro primer objetivo
```
gba-emulator feature/read_cartridge  ❯ ./run.sh roms/Tetris\ Worlds\ \(USA\).gba
[ 50%] Built target gbacore
[100%] Built target gbaemu
Hola mundo
Hola cartucho
Rom Opened
Game Title: TETRISWORLDS
```

Por el mometo leimos toda la rom en un array de bytes

Copiamos una estructura de proyecto que teniamos, donde tenemos el core, donde va a estar la logica, y platform, donde estarian los detalles de cada plataforma (desktop, android)

Agregamos una clase para el cartucho, donde vamos a empezar a guardar algunos datos relevantes y crear algunas funciones de clase sencillas.