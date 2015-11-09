#include <iostream>
#include <cstring>
#include <typeinfo>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "Nave.h"
using namespace std;


Nave::Nave(int px, int py){
	this->vida = MAX_VIDA;
	this->p_x = px;
	this->p_y = py-TAMANHO_NAVE-1;
	this->tamanho = TAMANHO_NAVE;
	this->municao = 100;
	this->kills =0;
}

void Nave::Start(){
    std::cout << "Nave Inciada!" << std::endl;
}

void Nave::Update(ALLEGRO_EVENT e){
    std::cout << "Nave Atualizada!" << std::endl;
    std::cout << "KEYDOWN: " << e.keyboard.keycode << endl;
    switch (e.keyboard.keycode) {
    	case ALLEGRO_KEY_D: case 83:
    		this->p_x+=10;
    		break;
    	case ALLEGRO_KEY_A: case 82:
    		this->p_x-=10;
    		break;
    	case ALLEGRO_KEY_W: case 84:
    		this->p_y-=10;
    		break;
    	case ALLEGRO_KEY_S: case 85:
    		this->p_y+=10;
    		break;
    	case 75:
    		std::cout << "SPACE: "<< endl;
    		break;
    }
    cout << "Teste";
}

void Nave::Render(){
    al_draw_filled_rectangle(this->p_x, this->p_y, this->p_x+tamanho, this->p_y+tamanho, al_map_rgb(255, 0, 0));
}




		