#include <cstdlib>

#include "worm.hpp"
#include "Point.hpp"
#include "Graphic.hpp"
#include "WormGraphics.h"

using namespace std;

int main(int argc, char** argv)
{
/*	Graphic d;
	d.AlInit();
	
	WormGraphics walking;
	
	char* imgFiles[15] = {"wF1.png", "wF2.png", "wF3.png", "wF4.png", "wF5.png", 
	"wF6.png", "wF7.png", "wF8.png", "wF9.png", "wF10.png", "wF11.png", "wF12.png", 
	"wF13.png", "wF14.png", "wF15.png", 
	};
	
	imgID a = 1;
	
	ALLEGRO_BITMAP* imgPointer = al_load_bitmap("wF1.png");

	Point p;
	p.setX(800.0);
	p.setY(300.0);
	
	imgID imgOrder[] = {
						//4,4,4,4,4,1,2,3,
						//4,4,4,4,4,3,2,3,
						4,4,4,4,4,3,3,3,
						//4,4,4,4,4,2,3,3,
						4,5,6,7,8,9,10,11,11,12,13,14,15,4,
						4,5,6,7,8,9,10,11,11,12,13,14,15,4,
						4,5,6,7,8,9,10,11,11,12,13,14,15,4,};
	
	for (int i=0; i<15 && a; ++i)
	{
		a = walking.loadImg(imgFiles[i]);
	}
	while (p.getX()>30)
	{	
		for(unsigned int tickCounter = 0; ++tickCounter < 50; al_rest(0.02))
		{
			al_draw_filled_rectangle(0,0,800,600,al_map_rgb(0,0,0));	//dibujar el fondo
			walking.drawImg( imgOrder[tickCounter], p);					//dibujar el gusanito
			al_flip_display();											//mostrar cambios en pantalla
			if(!((tickCounter-6)%14) && tickCounter>8)									//nueva posicion del gusano
				p.setX(p.getX()-9);
		}
	}
	

	
	
	d.AlShutdown();
	return 0;
 * */
}