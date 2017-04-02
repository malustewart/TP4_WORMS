#ifndef Graphic_hpp
#define Graphic_hpp

#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>


class Graphic
{
public:
    int  AlInit (unsigned int xMax = 800, unsigned int yMax = 600);
    void AlShutdown ();
private:
	ALLEGRO_DISPLAY* display;
};


#endif /* Graphic_hpp */
