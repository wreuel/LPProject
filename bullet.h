#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED
#include <iostream>
#include <cstring>
#include <typeinfo>
#include <allegro5/allegro.h>
#include "GameObject.h"

class Bullet: public GameObject{
	public:
		float tamanho;
		int	id;

		Bullet(std::string nome="Circulo", float px=0, float py=0, float vx=0, float vy=0, float atr=0, float tamanho=5);

		void Start();

		void Update();

		void Render();

		int MouseDown(float x, float y);
};

#endif // BULLET_H_INCLUDED

