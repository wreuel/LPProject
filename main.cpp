#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <typeinfo>
#include "GameObject.h"
#include "GameObjectList.h"
#include "Circulo.h"
#include "Retangulo.h"


using namespace std;

int main() {

    if (!al_init()) {
		cout << "Erro inicializando allegro" << endl;
	}

	ALLEGRO_DISPLAY *tela = al_create_display(800, 600);
	ALLEGRO_TIMER *timer = al_create_timer(1.0/30.0);
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();

	al_install_keyboard();
	al_install_mouse();
	al_init_primitives_addon();


	al_register_event_source(fila_eventos, al_get_keyboard_event_source());
	al_register_event_source(fila_eventos, al_get_mouse_event_source());
	al_register_event_source(fila_eventos, al_get_timer_event_source(timer));


	

    bool finalized = false;
    GameObjectList *l = new GameObjectList();

    GameObject *bola = new Circulo();
    if (typeid(*bola) == typeid(Circulo)) {
        Circulo * item = (Circulo *) bola;
        item->posicao_x = 30;
        item->posicao_y = 30;
        item->raio = 10;
        std::cout<<"Teste"<<std::endl;
    }
    
    GameObject *ret = new Retangulo("Quadrado", 60, 60, 0, 0, 0, 10);
    l->Adicionar(bola);
    l->Adicionar(ret);
    
    ALLEGRO_EVENT evento;
	al_start_timer(timer);
	float pos_x, pos_y;
	cout<< "coisa1" <<endl;
	while (!finalized) {


		al_wait_for_event(fila_eventos, &evento);
		

		if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
				switch (evento.keyboard.keycode) {
					case ALLEGRO_KEY_ESCAPE:
						finalized = true;
						break;
				}
		}

		if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
			l->MouseDown(evento.mouse.x, evento.mouse.y);
		}

		if (evento.type == ALLEGRO_EVENT_TIMER) {
				// atualizar estado
			
				// desenhar
				bola->Render();
				ret->Render();
				al_flip_display();
				al_clear_to_color(al_map_rgb(255, 255, 255));
		}

	}

	return 0;
}
