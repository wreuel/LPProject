#include <iostream>
#include <cstring>
#include <typeinfo>
#include <allegro5/allegro.h>
#include "GameObject.h"
#include "Circulo.h"
#include <math.h> 

Asteroide::Asteroide(std::string nome, float px, float py, float vx, float vy, float atr, float r) : GameObject(nome, px, py, vx, vy, atr, r){
	this->nome = "Teste";
    this->raio = r;
}

void Asteroide::Start(){
    std::cout << "Iniciei!" << std::endl;
}

void Asteroide::Update(){
    std::cout << "Atualize!" << std::endl;
}

void Asteroide::Render(){
    al_draw_filled_circle(this->posicao_x, this->posicao_y, this->raio, al_map_rgb(255, 255, 0));
}

int Asteroide::MouseDown(float x, float y){
	if (x <= this->posicao_x+raio && y <= this->posicao_y+raio){
		std::cout<<"Clicou no circulo!\n";
		return 1;
	}
	else {
		return 0;
	}
}
