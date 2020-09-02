#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <switch.h>
#include <unistd.h>

class Main {
    public:
        static void switch_init() {
            romfsInit();
            chdir("romfs:/");
        }
};