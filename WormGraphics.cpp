#include "WormGraphics.h"
#include "Point.hpp"

#define DEBUG

WormGraphics::WormGraphics()
{
	nextImgPosition = 1;
}

imgID WormGraphics::loadImg(char* fileName)
{
	imgID newImgID = 0;	//valor a devolver. hasta que no se cargue correctamente el bitmap, vale 0, lo que indica error
	if(nextImgPosition <= IMGSXMOVEMENT)	//entra si no esta lleno el arreglo de imagenes
	{
		ALLEGRO_BITMAP* imgPointer = al_load_bitmap(fileName);
		if (imgPointer != NULL)	//si se cargo correctamente, guardar el puntero
		{	
			wormImgs[nextImgPosition] = imgPointer;	//cargar el nuevo puntero en la prtimer posicion libre del arreglo de imagenes
				newImgID = nextImgPosition++;		//cargar la posicion donde se cargo exitosamente el bitmap
		}
	}
	return newImgID;	//devuelve cero si no se cargo correctamente el bitmap o si no hay mas lugar
}


void WormGraphics::drawImg(unsigned int tickCounter, Point p, int direction)
{
	al_draw_bitmap(wormImgs[imgOrder[tickCounter]],)
}
