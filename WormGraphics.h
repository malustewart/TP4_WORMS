#ifndef WORMGRAPHICS_H
#define WORMGRAPHICS_H

#include <string>
#include "Point.hpp"
#include "worm.hpp"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#define IMGSXMOVEMENT 20	//cuantas veces se dibuja para los movimientos

typedef unsigned int imgID;

class Worm;

class WormGraphics
{
private:
	ALLEGRO_BITMAP* wormImgs[IMGSXMOVEMENT+1];	//contiene todas las imagenes necesarias del movimiento.
												//se desreferencia como wormImgs[loadedImgs]. loaded Imgs es del tipo imgID.
												//se deja libre la posicion cero ya que imgID = 0 es indicadora de error 
	imgID nextImgPosition;						//inicializar en 1	
	imgID imgOrder[IMGSXMOVEMENT];
public:
	WormGraphics();
	imgID loadImg(char* fileName);
	void drawImg(Worm* w);
};

#endif /* WORMGRAPHICS_H */

