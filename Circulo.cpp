#include <iostream>
#include <cstring>
#include <typeinfo>
#include <allegro5/allegro.h>
#include "GameObject.h"
#include "Circulo.h"
#include <math.h> 

Circulo::Circulo(std::string nome, float px, float py, float vx, float vy, float atr, float r) : GameObject(nome, px, py, vx, vy, atr, r){
	this->nome = "Teste";
    this->raio = r;
}

void Circulo::Start(){
    std::cout << "Iniciei!" << std::endl;
}

void Circulo::Update(){
    std::cout << "Atualize!" << std::endl;
}

void Circulo::Render(){
    al_draw_filled_circle(this->posicao_x, this->posicao_y, this->raio, al_map_rgb(255, 0, 0));
}

int Circulo::MouseDown(float x, float y){
	float area;
	//Formula da distancia entre dois pontos
	//area = sqrt( pow(x-this->posicao_x,2) + pow(y-this->posicao_y,2) );
	if (x <= this->posicao_x+raio && y <= this->posicao_y+raio){
		std::cout<<"Clicou no circulo!\n";
		return 1;
	}
	else {
		return 0;
	}
}
