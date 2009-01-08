class map_editor_main
{
    public:
           map_editor_main();
           ~map_editor_main();
           void init(int level_width, int level_height,
                     int screen_width, int screen_height, SDL_Surface * levelSurface );

           void pulse(SDL_Event event);
           void handle_input(SDL_Event event);
           void keyboard_input(SDL_Event event);
           void mouse_input(SDL_Event event);


    private:
           camera editor_camera;
           Uint8 *keystates;
           enum DIRECTION{ UP, DOWN, LEFT, RIGHT};
};

map_editor_main::map_editor_main()
{
    keystates = SDL_GetKeyState(NULL);
}

map_editor_main::~map_editor_main()
{
    ;
}

void map_editor_main::init(int level_width, int level_height,
                           int screen_width, int screen_height, SDL_Surface * levelSurface)
{
   editor_camera.init(level_width,level_height,screen_width,screen_height);
}

void map_editor_main::pulse(SDL_Event event)
{
    handle_input(event);
}

void map_editor_main::handle_input(SDL_Event event)
{
    keyboard_input(event);
    mouse_input(event);
}

void map_editor_main::keyboard_input(SDL_Event event)
{
        keystates = SDL_GetKeyState(NULL);
        if(keystates[SDLK_RIGHT]) {
            editor_camera.update_camera(RIGHT);
        }

        if(keystates[SDLK_LEFT]) {
            editor_camera.update_camera(LEFT);
        }

        if(keystates[SDLK_UP]) {
            editor_camera.update_camera(UP);
        }

        if(keystates[SDLK_DOWN]) {
            editor_camera.update_camera(DOWN);
        }
}

void map_editor_main::mouse_input(SDL_Event event)
{
    ;
}
