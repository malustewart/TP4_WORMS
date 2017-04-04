#ifndef Display_hpp
#define Display_hpp

#include <stdio.h>
#include <string>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_image.h>

#define FLOORY 616		//coordenada Y del piso donde se apoyan los worms
#define XMIN 701		//borde izquierdo de donde se mueven los worms
#define XMAX 1212		//borde derecho de donde se mueven los worms
#define BGWIDTH 1300	//ancho imagen de fondo	PARA HACER: ,conseguir los valores correctos que estos los invente
#define BGHEIGHT 800	//altura imagen de fondo
#define SCALINGFACTOR 0.5

class Display		//PARA HACER: cambiarle el nombre a display, o a otro que sea mas apropiado
{
public:
    Display(std::string bgFileName = "Scenario.png");
	ALLEGRO_DISPLAY* getDisplay();
    void Shutdown();		//PARA HACER: hacerlo bien con destructor
	void drawBackground();
	void showChanges();
	bool isValid();
private:
	bool valid;
	ALLEGRO_DISPLAY* display;
	ALLEGRO_BITMAP* scenario;
	float displayWidth;
	float displayHeight;
};

#endif /* Background_hpp */
