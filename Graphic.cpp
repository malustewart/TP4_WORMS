#include "Graphic.hpp"

//////////////////////////////////////////////// AlInit ///////////////////////////////////////////////
//
// Recibe: xMax e yMax (tamaño máximo del display).
//
// Devuelve: el display que se utilizará.
//
//  Se inicializa todo lo necesario de Allegro.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

int  Graphic::AlInit ( unsigned int xMax, unsigned int yMax)
{
    if(!al_init())
    {

    }
    else if(!al_init_primitives_addon())
    {

    }    
    display = al_create_display(xMax, yMax);
    if(!display)
    {
        al_shutdown_primitives_addon();
    }
	else if(!al_init_image_addon())
	{
		al_shutdown_primitives_addon();
		al_destroy_display(display);
	};
}


////////////////////////////////////////////// AlShutdown ////////////////////////////////////////////
//
//	Devuelve:
//
//  Se cierra todo lo que se inicializó previamente de Allegro.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

void Graphic::AlShutdown ()
{
    al_destroy_display(display);
    
    al_shutdown_primitives_addon();
}




