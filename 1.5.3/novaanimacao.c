#include <SDL2/SDL.h>

int AUX_WaitEventTimeoutCount(SDL_Event* evt, Uint32* ms){
	Uint32 before = SDL_GetTicks();    
	if (SDL_WaitEventTimeout(evt, *ms)){
    	*ms -= (SDL_GetTicks() - before);
		if (*ms < 0) {
			*ms = 0;
		} 
		return 1;
    } else {
    	return 0;
    }
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
	SDL_Event evt;
    SDL_Rect r = { 0, 0, 20, 20};

    while (fim) {

		SDL_SetRenderDrawColor(ren, 0x00,0x00,0x00,0x00);
	    SDL_RenderClear(ren);
	    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
	    SDL_RenderFillRect(ren, &r);
	    SDL_RenderPresent(ren);

		if (AUX_WaitEventTimeoutCount(&evt, &timer)){
			if (evt.type == SDL_WINDOWEVENT){
            	if (SDL_WINDOWEVENT_CLOSE == evt.window.event){
            		fim = 0;
				}
            }		    
		} else {
			if (r.x >= 500){
				r.x+=1;
				r.y-=1;
			}
		    if (r.x <500) {
				r.x += 1;
		    	r.y += 1;
		    }
			timer = 10;
		}

	}
	
    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

}
