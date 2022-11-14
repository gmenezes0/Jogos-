#include <assert.h>
#include <SDL2/SDL.h>

int timer = 500;
int AUX_WaitEventTimeoutCount(SDL_Event* evt, Uint32* ms){
    if (SDL_WaitEventTimeout(evt, espera)){
    	timer -= (SDL_GetTicks() - *ms);
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
    SDL_Rect r(k) = {40,20,10,10};
    SDL_Rect q(t) = {40,20,10,10};
    SDL_Rect t(m) = {40,20,10,10};
    while (1) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0x00,0x00,0xFF,0x00);
        SDL_RenderFillRect(ren, &r);
        SDL_SetRenderDrawColor(ren, 0x00,0xFF,0x00,0x00);
        SDL_RenderFillRect(ren, &q);
        SDL_SetRenderDrawColor(ren, 0xFF,0x00,0x00,0x00);
        SDL_RenderFillRect(ren, &t);
        SDL_RenderPresent(ren);

        SDL_Event evt;
        Uint32 time = SDL_GetTicks();
        int isevt = AUX_WaitEventTimeoutCount(&evt, &time);
        if (isevt){
            if (evt.type == SDL_KEYDOWN){
                switch (evt.key.keysym.sym){
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
            } else if (evt.type == SDL_WINDOWEVENT){
            	if (SDL_WINDOWEVENT_CLOSE == evt.window.event){
            		SDL_DestroyRenderer(ren);
					SDL_DestroyWindow(win);
					SDL_Quit();
            	}
            } else if (evt.type == SDL_MOUSEMOTION){
            	t.x = evt.button.x;
            	t.y = evt.button.y;
            }
        } else {
            q.x += 2;
            q.y += 2;
        }
    }
}


