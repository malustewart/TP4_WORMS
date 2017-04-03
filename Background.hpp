#ifndef Display_hpp
#define Display_hpp

#include <stdio.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>


#define FLOORY 616		//coordenada Y del piso donde se apoyan los worms
#define XMIN 701.0		//borde izquierdo de donde se mueven los worms
#define XMAX 1212.0		//borde derecho de donde se mueven los worms
#define BGWIDTH 1300	//ancho imagen de fondo	PARA HACER: ,conseguir los valores correctos que estos los invente
#define BGHEIGHT 800	//altura imagen de fondo

class Display		//PARA HACER: cambiarle el nombre a display, o a otro que sea mas apropiado
{
public:
	bool isValid();
    Display(float displayWidth = BGWIDTH, float displayHeight = BGHEIGHT);
    void Shutdown();		//PARA HACER: hacerlo bien con destructor
	void drawBackground();
	void showChanges();
	ALLEGRO_DISPLAY* getDisplay();
private:
	bool valid;
	ALLEGRO_DISPLAY* display;
	float displayWidth;
	float displayHeight;
};

#endif /* Background_hpp */
