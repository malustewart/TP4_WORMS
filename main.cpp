#include <cstdlib>
#include <iostream>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

#define FPS 50.0

#include "Worm.h"
typedef unsigned int imgID;	//estaria bueno limitarlo a IMGSXMOVEMENT

imgID loadImg(graphInfo_t& move, string fileName);
unsigned int elementCount(string array[]);
void newEvent(Worm& w1, Worm& w2, Display& display,ALLEGRO_EVENT ev);
bool initAllegro();
void shutdownAllegro();
void shutdownAllegro(ALLEGRO_DISPLAY* display);
void shutdownAllegro(ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* eventQ, ALLEGRO_TIMER* timer);




int main(int argc, char** argv) 
{
	if(!initAllegro())	//si hubo error en la inicializacion de allegro, indicarlo y salir del programa
	{
		cout << "Error inicializando Allegro" << endl;
		return -1;
	}
	string bgFileName= "Scenario.png";
	Display bg(bgFileName);	//crear un display
	if(!bg.isValid())	//si hubo error en la inicializacion del display, indicarlo y salir del programa
	{
		cout << "Error en la inicializacion del display" << endl;
		return -1;		//PARA HACER: cambiar todos los -1 por un define de error
	}
	
	imgID loadedImgID;
	unsigned int fileCount;

	//cargar la info necesaria para dibujar al worm caminando en la estructura correspondiente
	graphInfo_t walk;		//guarda la informacion
	walk.nextImgPosition = 1;

	std::string walkImgFiles[] = {"wF1.png", "wF2.png", "wF3.png", "wF4.png", "wF5.png", 
	"wF6.png", "wF7.png", "wF8.png", "wF9.png", "wF10.png", "wF11.png", "wF12.png", 
	"wF13.png", "wF14.png", "wF15.png", 
	};

	fileCount = elementCount(walkImgFiles);	//obtener el numero de imagenes necesarias

	loadedImgID = 1;	//darle un valor distinto de cero ya que en cero indica error
	for( int i = 0; i < fileCount && loadedImgID; ++i)	//cargar todas las imagenes siempre que no haya error
		loadedImgID = loadImg(walk, walkImgFiles[i]);	//si hay error, loadImg devuelve cero
	
	if (!loadedImgID)	//indicar que hubo error y salir del programa
	{
		cout << "Error cargando imagenes de caminata" << endl;
		al_destroy_display(bg.getDisplay());
		shutdownAllegro();
		return -1;
	}

	imgID walkImgOrder[IMGSXMOVEMENT] = {
					4,4,4,4,4,3,3,3,
					4,5,6,7,8,9,10,11,11,12,13,14,15,4,
					4,5,6,7,8,9,10,11,11,12,13,14,15,4,
					4,5,6,7,8,9,10,11,11,12,13,14,15,4,};
	
	walk.imgOrder = &walkImgOrder;
	
	graphInfo_t jump;
	jump.nextImgPosition = 1;

	string jumpImgFiles[] = {"wF1.png", "wF2.png", "wF3.png", "wF4.png", "wF5.png", 
	"wF6.png", "wF7.png", "wF8.png", "wF9.png", "wF10.png", "wF11.png", "wF12.png", 
	"wF13.png", "wF14.png", "wF15.png", 
	};

	fileCount = elementCount(jumpImgFiles);
	for(int i = 0; i < fileCount && loadedImgID; ++i)
		loadedImgID = loadImg(jump, jumpImgFiles[i]);
	if (!loadedImgID)
	{
		cout << "Error cargando imagenes de salto." << endl;
		return -1;
	}

	imgID jumpImgOrder[IMGSXMOVEMENT] = {
					4,3,3,4,4,3,3,3,
					4,5,6,7,8,9,10,11,11,12,13,14,15,4,
					4,5,6,7,8,9,10,11,11,12,13,14,15,4,
					4,5,6,7,8,9,10,11,11,12,13,14,15,4,};
	
	jump.imgOrder = &jumpImgOrder;
	
	Worm w1(walk, jump, XMIN, LOOKRIGHT), w2(walk, jump, XMAX, LOOKLEFT);
	if(!w1.isValid())
	{
		cout << "Error en la inicializacion del worm 1." << endl;
		return -1;
	}
	else if(!w2.isValid())
	{
		cout << "Error en la inicializacion del worm 2." << endl;
		return -1;
	}
	
	ALLEGRO_EVENT_QUEUE *eventQ = al_create_event_queue();
	ALLEGRO_TIMER *timer = al_create_timer(1.0/FPS);

	if ( ! (timer = al_create_timer(1.0 / FPS)) ) 
	{
		cout << "Error en la creacion del timer" << endl;
		shutdownAllegro(bg.getDisplay(), eventQ, timer);
		return -1;
	}
	else if (!eventQ) {
		cout << "Error en la creacion de la cola de eventos" << endl;
		shutdownAllegro(bg.getDisplay(), eventQ, timer);
		return -1;
	}
	
	
	al_register_event_source(eventQ, al_get_timer_event_source(timer));
	al_register_event_source(eventQ, al_get_keyboard_event_source());
	al_register_event_source(eventQ, al_get_display_event_source(bg.getDisplay()));

	al_start_timer(timer);

	ALLEGRO_EVENT ev;

	do
	{
		if(!al_is_event_queue_empty(eventQ))
		{
			al_get_next_event(eventQ, &ev);
			newEvent(w1, w2, bg, ev);	
		}	
	} while (ev.type != ALLEGRO_EVENT_DISPLAY_CLOSE && ev.keyboard.keycode != ALLEGRO_KEY_ESCAPE);

	shutdownAllegro(bg.getDisplay(), eventQ, timer);

	return 0;
}

//carga la imagen en memoria y guarda el puntero a dicha imagen en el arreglo correspodiente
imgID loadImg(graphInfo_t& graph, string fileName)
{
	graph.wormImgs[graph.nextImgPosition] = al_load_bitmap(fileName.c_str());
	return (graph.wormImgs[graph.nextImgPosition] ? graph.nextImgPosition++ :  0);	
}

//recibe un arreglo y devuelve la cantidad de elementos dentro del arreglo
unsigned int elementCount(string array[])
{
	return 15;								//PARA HACER: hacer andar esta funcion
}

void newEvent( Worm& w1, Worm& w2, Display& display, ALLEGRO_EVENT ev )
{
	if (ev.type == ALLEGRO_EVENT_TIMER)
	{	
		display.drawBackground();	//redibujar el fondo
		w1.update();				// de ser necesario, modificar posicion e imagen
		w2.update();
		display.showChanges();		//mostrar todos los cambios de imagen
	}
	else if(ev.type == ALLEGRO_EVENT_KEY_DOWN || ev.type == ALLEGRO_EVENT_KEY_UP)
	{		
		switch(ev.keyboard.keycode)
		{
			case ALLEGRO_KEY_A:
				w1.calcNewState (ev.type == ALLEGRO_EVENT_KEY_DOWN ? LEFT_PRESSED : LEFT_RELEASED);
				break;
			case ALLEGRO_KEY_W:		
				w1.calcNewState (ev.type == ALLEGRO_EVENT_KEY_DOWN ? UP_PRESSED : UP_RELEASED);
				break;			
			case ALLEGRO_KEY_D:
				w1.calcNewState (ev.type == ALLEGRO_EVENT_KEY_DOWN ? RIGHT_PRESSED : RIGHT_RELEASED);
				break;
			case ALLEGRO_KEY_LEFT:
				w2.calcNewState (ev.type == ALLEGRO_EVENT_KEY_DOWN ? LEFT_PRESSED : LEFT_RELEASED);
				break;
			case ALLEGRO_KEY_UP:		
				w2.calcNewState (ev.type == ALLEGRO_EVENT_KEY_DOWN ? UP_PRESSED : UP_RELEASED);
				break;			
			case ALLEGRO_KEY_RIGHT:
				w2.calcNewState (ev.type == ALLEGRO_EVENT_KEY_DOWN ? RIGHT_PRESSED : RIGHT_RELEASED);
				break;
			default:
				break;
		}
	}
}

bool initAllegro()
{
	if(!al_init())
		return false;
	else if(!al_init_image_addon())
		return false;
	else if (!al_init_primitives_addon())
	{
		al_shutdown_image_addon();
		return false;
	}
	else if(!al_install_keyboard())
	{
		al_shutdown_image_addon();
		al_shutdown_primitives_addon();
		return false;
	}
	return true;
}

void shutdownAllegro()
{
	al_uninstall_keyboard();
	al_shutdown_image_addon();
	al_shutdown_primitives_addon();
}
void shutdownAllegro(ALLEGRO_DISPLAY* display)
{
	al_destroy_display(display);
	al_uninstall_keyboard();
	al_shutdown_image_addon();
	al_shutdown_primitives_addon();
}
void shutdownAllegro(ALLEGRO_DISPLAY* display, ALLEGRO_EVENT_QUEUE* eventQ, ALLEGRO_TIMER* timer)
{
	al_destroy_event_queue(eventQ);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_uninstall_keyboard();
	al_shutdown_image_addon();
	al_shutdown_primitives_addon();
}