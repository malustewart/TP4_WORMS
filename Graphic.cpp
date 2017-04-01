
//

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

int  Graphic::AlInit ( ALLEGRO_DISPLAY* display, unsigned int xMax, unsigned int yMax)
{
    if(!al_init())
    {
        fprintf(stderr, "failed to initialize allegro!\n");
        
        return -1;
    }
    if(!al_init_primitives_addon())
    {
        fprintf(stderr, "failed to initialize primitives!\n");
        
        return -1;
    }    
    display = al_create_display(xMax, yMax);
    
    if(!display)
    {
        al_shutdown_primitives_addon();
        
        fprintf(stderr, "failed to create display!\n");
        
        return -1;
    }
}


////////////////////////////////////////////// AlShutdown ////////////////////////////////////////////
//
// Recibe: xMax e yMax (tamaño máximo del display).
//
// Devuelve:
//
//  Se cierra todo lo que se inicializó previamente de Allegro.
//
//////////////////////////////////////////////////////////////////////////////////////////////////////

void Graphic::AlShutdown ( ALLEGRO_DISPLAY *  display)
{
    al_destroy_display(display);
    
    al_shutdown_primitives_addon();
    
    al_destroy_display(display);
}




