#include "editor-debug.h"
#include "editor-imageLoad.h"
#include "editor-camera.h"
#include "map-edit-main.h"
class editor_engine
{
    public:
           editor_engine();
           editor_engine(const char * name_of_level);
           ~editor_engine();

           void init(int screen_width, int screen_height);
           void pulse();
           void clean_up();

    private:
           SDL_Surface *screen;
           SDL_Surface *levelSurface;

           int level_width;
           int level_height;

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
    editor_debug.write_to_file("editor destructor started");
    TTF_Quit();
    SDL_Quit();
}

void editor_engine::init(int screen_width, int screen_height)
{
     screen = SDL_SetVideoMode(screen_width, screen_height, 32, SDL_HWSURFACE);
     map_editor.init(level_width,level_height, screen_width, screen_height, levelSurface);
}

void editor_engine::pulse()
{




     if( SDL_Flip( screen ) < 0 ) {
         editor_debug.write_to_file("!--SDL_Flip() error");
         }

}
