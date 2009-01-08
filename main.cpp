#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "editor-engine.h"
using namespace std;

int main( int argc, char* args[] )
{
    bool quit = false;
    SDL_Event event;
    editor_engine map_editor;
    map_editor.init(800, 600);

    Uint8 *keystates = SDL_GetKeyState(NULL);
    while( quit == false ) {
           while( SDL_PollEvent( &event ) )
           {
                  if( event.type == SDL_QUIT )
                  {
                      quit = true;
                      }

                   if( keystates[SDLK_ESCAPE])
                   {
                       quit = true;
                       }
                   map_editor.pulse();

                   }

           }
    return 0;
}

