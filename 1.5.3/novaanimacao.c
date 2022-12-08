#include <SDL2/SDL.h>

int AUX_WaitEventTimeoutCount(SDL_Event* evt, Uint32* ms){
	Uint32 before = SDL_GetTicks();    
	if (SDL_WaitEventTimeout(evt, *ms)){
    	int temporario = *ms - (SDL_GetTicks() - before);
		if (temporario < 0) {
			*ms = 0;
		} 
		else {
			*ms = temporario;
		}
		return 1;
    } 
	return 0;
}


int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Animacao Simples",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         1000, 500, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */

	int fim = 1;
	int timer = 10;	
    SDL_Rect r = { 0, 0, 20, 20};
	int vx, vy; vx = 1; vy = 1;
	printf("%d",timer);
  
    while (fim) {

		SDL_SetRenderDrawColor(ren, 0x00,0x00,0x00,0x00);
	    SDL_RenderClear(ren);
	    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
	    SDL_RenderFillRect(ren, &r);
	    SDL_RenderPresent(ren);
		
		SDL_Event evt;
		if (AUX_WaitEventTimeoutCount(&evt, &timer)){
			if (evt.type == SDL_WINDOWEVENT){
            	if (SDL_WINDOWEVENT_CLOSE == evt.window.event){
            		fim = 0;
				}
            }		    
		} else {
			 if (r.x >= 600) vx = -1;
			 if (r.x <= 0) vx = 2;
			 if (r.y >= 500) vy = -1;
			 if (r.y <= 0) vy = 2;
			 r.x += 1*vx;
			 r.y += 1*vy;
			 timer = 10;	
		}

	}
	
    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

}
