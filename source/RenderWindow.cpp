#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>

#include "RenderWindow.h"
#include "Entity.h"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h) :window(NULL), renderer(NULL) {


    //  INIT THE WINDOW
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if(window == NULL) {
        printf("SDL_CreateWindow failed. SDL_Error: %s\n", SDL_GetError());
    } else {
        printf("SDL_CreateWindow\n");
    }


    //  CREATE THE RENDERER USING GPU
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(renderer == NULL) {
        printf("SDL_CreateRenderer failed. SDL_Error: %s\n", SDL_GetError());
    } else {
        printf("SDL_CreateRenderer\n");
    }

}


//  CLEAN UP THE SYSTEMS
SDL_Texture* RenderWindow::loadTexture(const char* p_filePath) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);
    
    if(texture == NULL) {
        printf("RenderWindow::loadTexture failed to load a texture. Error: %s\n", SDL_GetError());
    }
    return texture;
}


//  CLEAN UP THE SYSTEMS
void RenderWindow::cleanUp() {
    SDL_DestroyWindow(window);
}


//  CLEAR THE SCREEN
void RenderWindow::clear(){
    SDL_RenderClear(renderer);
}


//  RENDER TEXTURES AND SHIZ
void RenderWindow::render(Entity &p_entity) {

    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dest;
    dest.x = p_entity.getPos().x * 2;
    dest.y = p_entity.getPos().y * 2;
    dest.w = p_entity.getCurrentFrame().w * 2;
    dest.h = p_entity.getCurrentFrame().h * 2;

    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dest);
}


//  ACTUALLY DISPLAY THAT SHIZ
void RenderWindow::display() {
    SDL_RenderPresent(renderer);
}

