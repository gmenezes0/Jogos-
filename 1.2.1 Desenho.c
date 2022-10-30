#include <SDL2/SDL.h>

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Hello World!",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         500, 500, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);


    /* EXECUÇÃO */
    SDL_SetRenderDrawColor(ren, 0,0,0,0x00); /*janela*/
    SDL_RenderClear(ren);
    
    SDL_SetRenderDrawColor(ren, 0xFF,0,0, 0x00);
    SDL_Rect r = { 0, 125, 500, 125 }; /*quadrado1*/
    SDL_RenderFillRect(ren, &r);  
    SDL_Rect r1 = { 0, 375, 500, 125 }; /*quadrado2*/
    SDL_RenderFillRect(ren, &r1); 
    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderDrawLine(ren, 200, 0, 200, 125); /*linha vertical*/
    SDL_RenderDrawLine(ren, 0, 125, 200, 125); /*linha horizontal*/
    SDL_Rect r2 = { 60, 10, 5, 105}; /*F traço em pé*/
    SDL_RenderFillRect(ren, &r2);   
    SDL_Rect r3 = { 60, 10, 80, 5}; /*F traço deitado 1*/
    SDL_RenderFillRect(ren, &r3);   
    SDL_Rect r4 = { 60, 60, 60, 5}; /*F traço deitado 2*/
    SDL_RenderFillRect(ren, &r4);
    SDL_RenderDrawPoint(ren, 100, 115);   
    SDL_RenderPresent(ren);
    SDL_Delay(5000);


    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
