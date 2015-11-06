#define LARGURA 800
#define ALTURA 600
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <typeinfo>
#include "Nave.h"
#include "GameObject.h"
#include "GameObjectList.h"
#include "Circulo.h"
#include "Retangulo.h"


using namespace std;

int main() {

    if (!al_init()) {
		cout << "Erro inicializando allegro" << endl;
	}


	ALLEGRO_DISPLAY *tela = al_create_display(LARGURA, ALTURA);
	ALLEGRO_TIMER *timer = al_create_timer(1.0/30.0);
    ALLEGRO_EVENT_QUEUE *fila_eventos = al_create_event_queue();

	al_install_keyboard();
	al_install_mouse();
	al_init_primitives_addon();

	/*Iniciar Eventos */
	al_register_event_source(fila_eventos, al_get_keyboard_event_source());
	al_register_event_source(fila_eventos, al_get_mouse_event_source());
	al_register_event_source(fila_eventos, al_get_timer_event_source(timer));

	/*Variavel que verifica estado do jogo*/
    bool finalized = false;

    /*Player/Nave Do Jogador*/
    Nave *navePlayer = new Nave(LARGURA/2, ALTURA); 

    /*Lista de Objetos (Inimigos ou Asteroides)*/
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

	while (!finalized) {


		al_wait_for_event(fila_eventos, &evento);
		

		if (evento.type == ALLEGRO_EVENT_KEY_DOWN) {
			if(evento.keyboard.keycode == 59) {
				finalized = true;
			}
			else {
				navePlayer->Update(evento);
				//cout << "KEYDOWN: " << evento.keyboard.keycode << endl;
			}
			
				/*switch (evento.keyboard.keycode) {
					case ALLEGRO_KEY_ESCAPE:
						//finalized = true;
						break;
					case 4:
						navePlayer->Update();
						//cout << "KEYDOWN: " << evento.keyboard.keycode << endl;
						break;
				}*/
			
		}

		if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
			l->MouseDown(evento.mouse.x, evento.mouse.y);
		}

		if (evento.type == ALLEGRO_EVENT_TIMER) {
				// atualizar estado

				// desenhar
				navePlayer->Render();
				bola->Render();
				ret->Render();
				al_flip_display();
				al_clear_to_color(al_map_rgb(255, 255, 255));
		}

	}

	return 0;
}
