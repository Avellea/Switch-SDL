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

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);



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

	// // CREATE A BASIC FONT OBJECT
    // TTF_Font *font = TTF_OpenFont("romfs:/res/fonts/small_font.ttf", 24);
	// SDL_Color color = {255,255,255};
    
    // if(!font) {
    //     printf("TTF_Font *font failed. TTF_Error: %s\n", TTF_GetError());
    // } else {
    //     printf("TTF_OpenFont\n");
    // }


    // SDL_Surface *txt_surface = TTF_RenderText_Solid(font, "Hello, world!", color);
	// SDL_Texture* txt_texture = SDL_CreateTextureFromSurface(renderer, txt_surface);
	// SDL_Rect txt_rect;
	// txt_rect.x = 10; 
	// txt_rect.y = 10;
	// txt_rect.w = txt_surface->w;
	// txt_rect.h = txt_surface->h;

    // SDL_RenderCopy(renderer, txt_texture, NULL, &txt_rect);


    SDL_Rect src;
    src.x = p_entity.getCurrentFrame().x;
    src.y = p_entity.getCurrentFrame().y;
    src.w = p_entity.getCurrentFrame().w;
    src.h = p_entity.getCurrentFrame().h;

    SDL_Rect dest;
    dest.x = p_entity.getPos().x * 4;
    dest.y = p_entity.getPos().y * 4;
    dest.w = p_entity.getCurrentFrame().w * 4;
    dest.h = p_entity.getCurrentFrame().h * 4;

    SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dest);
}


//  ACTUALLY DISPLAY THAT SHIZ
void RenderWindow::display() {
    SDL_RenderPresent(renderer);
}

