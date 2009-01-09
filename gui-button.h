class gui_button : public gui_window
{
    public:
           gui_button();
           ~gui_button();

           void init(int x, int y, int w, int h);
           bool button_is_down();
           bool is_mouse_over_button(int x, int y);

    private:
          void show_button_down_image();
          void show_button_up_image();
          void handle_input(SDL_Event event);
          bool button_down;

          int holdEventX;
          int holdEventY;

          int mouse_x;
          int mouse_y;

          Uint8 mouse_state;

};

gui_button::gui_button()
{
    button_down = false;
    border_width = 2;
}

gui_button::~gui_button()
{
    ;
}

void gui_button::init(int x, int y, int w, int h)
{
    ;
}

void gui_button::handle_input(SDL_Event event)
{
      SDL_PumpEvents();
      if(SDL_GetMouseState(&mouse_x, &mouse_y)&SDL_BUTTON(1)){
           if(is_mouse_over_button(mouse_x, mouse_y) == true){
              button_down = true;
           }
      }

      else if(event.type == SDL_MOUSEBUTTONUP){
          if(event.button.button == SDL_BUTTON_LEFT){
              holdEventX = event.button.x;
              holdEventY = event.button.y;
              if(is_mouse_over_button(holdEventX, holdEventY) == true){
                  button_down = false;
              }
          }
      }

      else{
         button_down = false;
      }

      if( button_down == false){
                   show_button_up_image();
      }

      if( button_down == true){
          show_button_down_image();
      }
}

bool gui_button::button_is_down()
{
    return button_down;
}

bool gui_button::is_mouse_over_button(int x, int y)
{
           if( ( x > placeWindowRect.x )
                 && ( x < placeWindowRect.x + windowRect.w )
                 && ( y > placeWindowRect.y )
                 && ( y < placeWindowRect.y + windowRect.h ) )
                 {
                     return true;
                 }

            else
                return false;
}

void gui_button::show_button_down_image()
{

    horizontalBorderRect[0].x = 0;
    horizontalBorderRect[0].y = windowRect.h - border_width;
    horizontalBorderRect[1].x = 0;
    horizontalBorderRect[1].y = 0;

    verticalBorderRect[0].x = windowRect.w - border_width;
    verticalBorderRect[0].y = 0;
    verticalBorderRect[1].x = 0;
    verticalBorderRect[1].y = 0;
}

void gui_button::show_button_up_image()
{
    horizontalBorderRect[0].x = 0;
    horizontalBorderRect[0].y = 0;
    horizontalBorderRect[1].x = 0;
    horizontalBorderRect[1].y = windowRect.h - border_width;

    verticalBorderRect[0].x = 0;
    verticalBorderRect[0].y = 0;
    verticalBorderRect[1].x = windowRect.w - border_width;
    verticalBorderRect[1].y = 0;

}
