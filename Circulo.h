#ifndef CIRCULO_H_INCLUDED
#define CIRCULO_H_INCLUDED
#include <iostream>
#include <cstring>
#include <typeinfo>
#include <allegro5/allegro.h>
#include "GameObject.h"

class Circulo: public GameObject{
	public:
		float raio;

		Circulo(std::string nome="Circulo", float px=0, float py=0, float vx=0, float vy=0, float atr=0, float r=1);

		void Start();

		void Update();

		void Render();

		int MouseDown(float x, float y);
};

#endif // CIRCULO_H_INCLUDED

