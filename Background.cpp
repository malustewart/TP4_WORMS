#include "Background.hpp"


Display::Display (float _displayWidth, float _displayHeight)
{
	displayWidth = _displayWidth;		//cargar tamanio de display
	displayHeight = _displayHeight;
	
	valid = true;	//es true siempre y cuando no haya un error en la inicializacion de allegro
					//si se encuentra un error, se lo indica en esta variable y se llaman a las 
					//funciones de finalizacion correspondientes
	
    if(!al_init())
		valid = false;
    else if(!al_init_primitives_addon())
		valid = false;
			
    display = al_create_display(displayWidth, displayHeight);
	
    if(!display)
    {
        al_shutdown_primitives_addon();
		valid = false;
    }
	else if(!al_init_image_addon())
	{
		al_shutdown_primitives_addon();
		al_destroy_display(display);
		valid = false;
	};
	
}

void Display::Shutdown ()
{
    al_destroy_display(display);
    al_shutdown_primitives_addon();
}

void Display::drawBackground()
{
	al_draw_filled_rectangle(0, 0, BGWIDTH, BGHEIGHT, al_map_rgb(0, 0, 0));
}

bool Display::isValid()
{
	return valid;
}

void Display::showChanges()
{
	al_flip_display();
}

ALLEGRO_DISPLAY* Display::getDisplay()
{
	return display;
}