#include "editor-debug.h"
#include "editor-imageLoad.h"
#include "editor-camera.h"
#include "engine-window.h"
#include "gui-button.h"
#include "map-edit-main.h"
class editor_engine
{
    public:
           editor_engine();
           editor_engine(const char * name_of_level);
           ~editor_engine();

           void init(int screen_width, int screen_height);
           void pulse(SDL_Event event);
           void clean_up();

    private:
           SDL_Surface *screen;
           SDL_Surface *levelSurface;
           SDL_Surface *canvas;

           SDL_Rect canvasRect;
           SDL_Rect levelPlaceRect;

           int level_width;
           int level_height;

           imageLoad image_loader;
           debug editor_debug;
           map_editor_main map_editor;

};


editor_engine::editor_engine()
{
    editor_debug.debug_file_init();
    editor_debug.write_to_file("Map Editor constructor started");

    screen = NULL;
    levelSurface = NULL;

    level_width = 3200;
    level_height = 1200;

    canvasRect.x = 0;
    canvasRect.y = 0;
    canvasRect.w = 600;
    canvasRect.h = 520;

    levelPlaceRect.x = 15;
    levelPlaceRect.y = 50;

    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0) {
       editor_debug.write_to_file("!--SDL failed to initialize.");
       }
    else
       editor_debug.write_to_file("SDL sucessfully initialized.");

    editor_debug.write_to_file("engine constructor finished.");
}

editor_engine::editor_engine(const char * name_of_level)
{
    ;
}

editor_engine::~editor_engine()
{
    TTF_Quit();
    SDL_Quit();
    editor_debug.write_to_file("editor destructor finished");
}

void editor_engine::init(int screen_width, int screen_height)
{
     editor_debug.write_to_file("editor_engine.init() started");
     levelSurface = SDL_LoadBMP("levelSurface.bmp");
     canvas = SDL_LoadBMP("canvas.bmp");

     screen = SDL_SetVideoMode(screen_width, screen_height, 32, SDL_HWSURFACE);
     map_editor.init(level_width,level_height, screen_width, screen_height, levelSurface);

     editor_debug.write_to_file("editor_engine.init() finished");
}

void editor_engine::pulse(SDL_Event event)
{
    SDL_BlitSurface(canvas, &canvasRect, levelSurface, &levelPlaceRect);
    image_loader.apply_surface( 0, 0, levelSurface, screen );

    map_editor.pulse(event);


     if( SDL_Flip( screen ) < 0 ) {
         editor_debug.write_to_file("!--SDL_Flip() error");
         }

}
