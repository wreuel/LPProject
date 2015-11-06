#ifndef RETANGULO_H_INCLUDED
#define RETANGULO_H_INCLUDED
#include <iostream>
#include <cstring>
#include <allegro5/allegro.h>
#include <typeinfo>
#include "GameObject.h"

class Retangulo: public GameObject{
	public:
		float tamanho;
		
		Retangulo(std::string nome="Retangulo", float px=0, float py=0, float vx=0, float vy=0, float atr=0, float tam=1);

		void Start();

		void Update();

		void Render();

		int MouseDown(float x, float y);
};

#endif // RETANGULO_H_INCLUDED
