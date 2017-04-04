#include "Background.hpp"


Display::Display(std::string bgFileName)
{	
	valid = true;	//es true siempre y cuando no haya un error
					//si se encuentra un error, se lo indica en esta variable
	display = al_create_display(al_get_bitmap_width(scenario), al_get_bitmap_height(scenario));
	if(!display)
		valid = false;		
}

void Display::Shutdown ()
{
    al_destroy_display(display);
}

void Display::drawBackground()
{
//	al_draw_filled_rectangle(0, 0, BGWIDTH, BGHEIGHT, al_map_rgb(0, 0, 0));
//	al_draw_bitmap(scenario, 0, 0, 0);
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