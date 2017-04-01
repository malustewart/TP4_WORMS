

//

#ifndef Graphic_hpp
#define Graphic_hpp


#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_color.h>      // NO OLVIDAR AGREGAR EN EL LINKER DEL PROYECTO
#include <allegro5/allegro_primitives.h> // NO OLVIDAR AGREGAR EN EL LINKER DEL PROYECTO
#include <allegro5/allegro_audio.h>
#include<allegro5/allegro_acodec.h>
#include<allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>
#include<math.h>


class Graphic
{
public:
    int  AlInit (ALLEGRO_DISPLAY * display, unsigned int xMax, unsigned int yMax);
    
    void AlShutdown (ALLEGRO_DISPLAY * display);
};


#endif /* Graphic_hpp */
