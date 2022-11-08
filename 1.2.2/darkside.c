#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

int main (int argc, char* args[])
{
    //INICIALIZACAO 
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("us & them",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         700, 500, SDL_WINDOW_SHOWN);
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);    
    

    //EXECUÇÃO 
    SDL_SetRenderDrawColor(ren, 0,0,10,0x00); //janela
    SDL_RenderClear(ren);
    
    
    //preenchimento
    int luz = thickLineRGBA(ren, 1, 300, 300, 250, 7, 255,255,255,255);
    Sint16 vx[] = {350,250,450}; Sint16 vy[] = {150,350,350};
    int prisma = polygonRGBA(ren, vx,vy, 3, 255,255,255,255);
    Sint16 vx2[] = {285,400,400}; Sint16 vy2[] = {250,230,270};
    int pass = filledPolygonRGBA(ren, vx2,vy2, 3, 255,255,255,25);
    //int prisma = trigonRGBA(ren,350,250,450,150,200,200,255,255,1,255);
    SDL_RenderDrawPoint(ren,295,247);//entrada da luz
    SDL_RenderDrawPoint(ren,395,250);//saida da luz
    int red = thickLineRGBA(ren, 390, 235, 700, 300, 10, 255,1,1,255);
    int orange = thickLineRGBA(ren, 393, 242, 700, 310, 10, 255,130,1,255);
    int yellow = thickLineRGBA(ren, 396, 249, 700, 320, 10, 255,255,1,255);
    int green = thickLineRGBA(ren, 399, 256, 700, 330, 10, 1,255,1,255);
    int blue = thickLineRGBA(ren, 403, 263, 700, 340, 10, 1,1,255,255);
    int purple = thickLineRGBA(ren, 407, 270, 700, 350, 10, 106,90,205,255);
    
    SDL_RenderPresent(ren);
    SDL_Delay(5000);


    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
