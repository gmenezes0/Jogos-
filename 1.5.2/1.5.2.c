#include <assert.h>
#include <SDL2/SDL.h>

int timer = 500;
int AUX_WaitEventTimeoutCount(SDL_Event* evt, Uint32* ms){
    if (SDL_WaitEventTimeout(evt, timer)){
    	timer -= (SDL_GetTicks() - *ms);
	if (timer <= 0) {
		timer = 1;
	}
    	return 1;
    } else {
    	timer = 500;
    	return 0;
    }
}

int main (int argc, char* args[]){
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("1.5.1",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         500, 300, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);

    /* EXECUÇÃO */
    SDL_Rect r = {40,20,10,10};
    while (1) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
        SDL_RenderFillRect(ren, &r);
        SDL_RenderPresent(ren);

        SDL_Event evt;
        Uint32 time = SDL_GetTicks();
        int isevt = AUX_WaitEventTimeoutCount(&evt, &time);
        if (isevt){
            if (SDL_WINDOWEVENT_CLOSE == evt.window.event){
            	SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		SDL_Quit();
            } else if (evt.type == SDL_MOUSEMOTION){
            	r.x = evt.button.x-5;
            	r.y = evt.button.y-5;
            }
        } else {
            r.x += 2;
            r.y += 2;
        }
    }
}


