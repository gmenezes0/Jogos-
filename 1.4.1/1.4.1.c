#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Movendo um Retângulo",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         500, 500, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */ 
    int count = 0;
    int n = 1;
    SDL_Rect r = { 40,20, 10,10 };
    SDL_Rect q[10];
    SDL_Event evt;
    while (n) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren,rand()%255,rand()%255,rand()%255,0x00);
        SDL_RenderFillRect(ren, &r);
        int i = 0;
		
	for (i;i<count;i++){
		SDL_RenderFillRect(ren,&q[i]);
	}
	
	SDL_RenderPresent(ren);
        SDL_WaitEvent(&evt);
        if (evt.type == SDL_KEYDOWN) {
            switch (evt.key.keysym.sym) {
                case SDLK_UP:
                    r.y -= 5;
                    break;
                case SDLK_DOWN:
                    r.y += 5;
                    break;
                case SDLK_LEFT:
                    r.x -= 5;
                    break;
                case SDLK_RIGHT:
                    r.x += 5;
                    break;
            }
        }
        if (evt.type == SDL_MOUSEBUTTONDOWN) {
        	switch (evt.button.button){
        		case SDL_BUTTON_LEFT:
        			if (count <= 9) {	    
        				SDL_Rect temp = { evt.button.x, evt.button.y, rand()%50, rand()%50};
					q[count] = temp;
        				count += 1;
        			}break;
        	}
        }
        
        if (evt.type == SDL_WINDOWEVENT) {
        	switch (evt.window.event){	
			case SDL_WINDOWEVENT_CLOSE:
				n = 0;
			 break;}
			
	}
    }
SDL_DestroyRenderer(ren);
SDL_DestroyWindow(win);
SDL_Quit();    

}
