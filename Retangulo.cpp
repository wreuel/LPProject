#include <iostream>
#include <cstring>
#include <allegro5/allegro.h>
#include <typeinfo>
#include "GameObject.h"
#include "Retangulo.h"

Retangulo::Retangulo(std::string nome, float px, float py, float vx, float vy, float atr, float tam) : GameObject(nome, px, py, vx, vy, atr, tam){
    this->tamanho = tam;
}

void Retangulo::Start(){
    std::cout << "Iniciei!" << std::endl;
}

void Retangulo::Update(){
    std::cout << "Atualize!" << std::endl;
}

void Retangulo::Render(){
	al_draw_filled_rectangle(this->posicao_x, this->posicao_y, this->posicao_x+tamanho, this->posicao_y+tamanho, al_map_rgb(255, 0, 0));
}

int Retangulo::MouseDown(float x, float y){
	if (x >= this->posicao_x && x <= this->posicao_x + this->tamanho &&
		y >= this->posicao_y && y <= this->posicao_y + this->tamanho){
		std::cout<<"Clicou no retangulo!\n";
		return 1;
	}
	else
		return 0;
}
