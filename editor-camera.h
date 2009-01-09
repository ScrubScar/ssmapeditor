class camera
{
      public:
          camera();
          ~camera();

          void init(int level_width, int level_height, int screen_width, int screen_height);
          void update_camera(SDL_Rect &playerRect);
          void update_camera(int move_direction);
          int get_camera_x();
          int get_camera_y();
          void toggle_camera_boundries();
          SDL_Rect &get_camera_rect();

      private:
          int LEVEL_WIDTH;
          int LEVEL_HEIGHT;

          bool attached_to_player;
          bool camera_boundries_are_on;
          enum DIRECTION{ UP, DOWN, LEFT, RIGHT};

          debug camera_debug;

          SDL_Rect cameraRect;
};

camera::camera()
{
    camera_debug.write_to_file("camera constructor started.");
    LEVEL_WIDTH = 0;
    LEVEL_HEIGHT = 0;

    cameraRect.x = 0;
    cameraRect.y = 0;
    cameraRect.w = 100;
    cameraRect.h = 100;

    attached_to_player = true;
    camera_boundries_are_on = true;

    camera_debug.write_to_file("camera constructor finished.");
}

camera::~camera()
{
    LEVEL_WIDTH = 0;
    LEVEL_HEIGHT = 0;

    cameraRect.x = 0;
    cameraRect.y = 0;
    cameraRect.w = 0;
    cameraRect.h = 0;

    attached_to_player = true;
    camera_boundries_are_on = true;
    camera_debug.write_to_file("camera destructor finished.");
}

void camera::init( int level_width, int level_height, int camera_width, int camera_height )
{
     camera_debug.write_to_file("camera.init() started.");

     LEVEL_WIDTH = level_width;
     LEVEL_HEIGHT = level_height;

     cameraRect.w = camera_width;
     cameraRect.h = camera_height;

     attached_to_player = true;
     camera_boundries_are_on = true;

     camera_debug.write_to_file("camera.init() finished.");
}

void camera::update_camera(SDL_Rect &playerRect)
{
    if(attached_to_player) {
       cameraRect.x = playerRect.x - (cameraRect.w/2);
       cameraRect.y = playerRect.y - (cameraRect.h/2);
       }

    if(camera_boundries_are_on) {
                while(cameraRect.x < 0) {
                      cameraRect.x++ ;
                      }

                while(cameraRect.x + cameraRect.w > LEVEL_WIDTH) {
                      cameraRect.x--;
                      }

                while(cameraRect.y + cameraRect.h > LEVEL_HEIGHT){
                     cameraRect.y--;
                    }

                while(cameraRect.y < 0 ){
                   cameraRect.y++;
                   }

            }
}

void camera::update_camera(int move_direction)
{
    switch(move_direction)
    {   // Fall through intentional.
        case  LEFT: cameraRect.x = cameraRect.x - 2;
        case RIGHT: cameraRect.x = cameraRect.x + 2;
        case    UP: cameraRect.y = cameraRect.y - 2;
        case  DOWN: cameraRect.y = cameraRect.y + 2;
                    break;
        default: break;
    }
}

SDL_Rect & camera::get_camera_rect()
{
      return cameraRect;
}

int camera::get_camera_x()
{
    return cameraRect.x;
}

int camera::get_camera_y()
{
    return cameraRect.y;
}

void camera::toggle_camera_boundries()
{
    if( camera_boundries_are_on == false){
        camera_boundries_are_on = true;
    }

    else if( camera_boundries_are_on == true){
        camera_boundries_are_on = false;
    }
    else
        return;
}
