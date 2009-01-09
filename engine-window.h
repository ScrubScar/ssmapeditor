class gui_window
{
    public:
        gui_window();
        virtual ~gui_window();

        void main_init(int x, int y, int w, int h, SDL_Surface *levelSurface);
        void set_border_width(int width);
        void show(SDL_Event event);

    protected:
        void draw_borders();
        void update_borders();
        virtual void handle_input(SDL_Event event);
        virtual void init(int x, int y, int w, int h);

        imageLoad image_loader;
        SDL_Surface * canvas_buffer;
        SDL_Surface * generic_window;
        SDL_Surface * main_window;
        SDL_Surface * window_buffer;
        SDL_Surface * window_border_vertical;
        SDL_Surface * window_border_horizontal;
        SDL_Surface * window_border_vertical_top;
        SDL_Surface * window_border_horizontal_top;

        SDL_Rect windowRect;
        SDL_Rect placeWindowRect;

        SDL_Rect horizontalBorderRect[2];
        SDL_Rect verticalBorderRect[2];
        SDL_Rect horizontalBorderClipRect;
        SDL_Rect verticalBorderClipRect;

        bool window_has_focus;

        int border_width;

};

gui_window::gui_window()
{

    generic_window = NULL;
    windowRect.x = 0;
    windowRect.y = 0;
    windowRect.w = 0;
    windowRect.h = 0;

    window_has_focus = false;

}

gui_window::~gui_window()
{

    generic_window = NULL;
    windowRect.x = 0;
    windowRect.y = 0;
    windowRect.w = 0;
    windowRect.h = 0;

    window_has_focus = false;

}

void gui_window::main_init(int x, int y, int w, int h, SDL_Surface *levelSurface)
{
    main_window = levelSurface;
    generic_window = image_loader.load_image("windowBG.bmp");
    window_buffer = image_loader.load_image("windowBG.bmp");
    canvas_buffer = image_loader.load_image("canvas.bmp");
    window_border_vertical = image_loader.load_image("window-border.gif");
    window_border_vertical_top = image_loader.load_image("window-border-top.gif");
    window_border_horizontal = image_loader.load_image("window-border-horizontal.gif");
    window_border_horizontal_top= image_loader.load_image("window-border-horizontal-top.gif");

    windowRect.x = 0;
    windowRect.y = 0;
    windowRect.w = w;
    windowRect.h = h;

    placeWindowRect.x = x;
    placeWindowRect.y = y;

    border_width = 0;

    verticalBorderClipRect.x = 0;
    verticalBorderClipRect.y = 0;
    verticalBorderClipRect.w = border_width;
    verticalBorderClipRect.h = windowRect.h;

    verticalBorderRect[0].x = 0;
    verticalBorderRect[0].y = 0;
    verticalBorderRect[1].x = windowRect.w - border_width;
    verticalBorderRect[1].y = 0;

    horizontalBorderClipRect.x = 0;
    horizontalBorderClipRect.y = 0;
    horizontalBorderClipRect.w = windowRect.w;
    horizontalBorderClipRect.h = border_width;

    horizontalBorderRect[0].x = 0;
    horizontalBorderRect[0].y = 0;
    horizontalBorderRect[1].x = 0;
    horizontalBorderRect[1].y = windowRect.h - border_width;



    init(x,y,w,h);

}

void gui_window::init(int x, int y, int w, int h)
{
    ;
}


void gui_window::show(SDL_Event event)
{
    handle_input(event);
    if( border_width >= 0 && border_width <= 5 ){
        draw_borders();
    }

    SDL_BlitSurface(generic_window, &windowRect, main_window, &placeWindowRect);
    SDL_BlitSurface(window_buffer, &windowRect, generic_window, NULL);
}

void gui_window::handle_input(SDL_Event event)
{
    ;
}

void gui_window::set_border_width(int width)
{
    border_width = width;
    update_borders();
}

void gui_window::draw_borders()
{
    SDL_BlitSurface(window_border_vertical_top, &verticalBorderClipRect, generic_window, &verticalBorderRect[0]);
    SDL_BlitSurface(window_border_vertical, &verticalBorderClipRect, generic_window, &verticalBorderRect[1]);
    SDL_BlitSurface(window_border_horizontal_top, &horizontalBorderClipRect, generic_window, &horizontalBorderRect[0]);
    SDL_BlitSurface(window_border_horizontal, &horizontalBorderClipRect, generic_window, &horizontalBorderRect[1]);
}

void gui_window::update_borders()
{
        verticalBorderClipRect.w = border_width;
        verticalBorderRect[1].x = windowRect.w - border_width;
        horizontalBorderClipRect.h = border_width;
        horizontalBorderRect[1].y = windowRect.h - border_width;
}
