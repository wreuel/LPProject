#include <iostream>
#include <cstring>
#include <typeinfo>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "Nave.h"


Nave::Nave(){
	this->vida = MAX_VIDA;
	this->p_x = 400;
	this->p_y = 600-TAMANHO_NAVE-1;
	this->tamanho = TAMANHO_NAVE;
	this->municao = 100;
	this->kills =0;
}

void Nave::Start(){
    std::cout << "Nave Inciada!" << std::endl;
}

void Nave::Update(){
    std::cout << "Nave Atualizada!" << std::endl;
}

void Nave::Render(){
    al_draw_filled_rectangle(this->p_x, this->p_y, this->p_x+tamanho, this->p_y+tamanho, al_map_rgb(255, 0, 0));
}




		