#include <iostream>
#include <cstring>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <typeinfo>
#include "GameObject.h"
#include "GameObjectList.h"
#include "Circulo.h"
#include "Retangulo.h"


using namespace std;
    GameObjectList::GameObjectList() {
        this->inicio = NULL;
    }


	void GameObjectList::Adicionar(GameObject *item) {
	    /*NoDaLista *novo = new NoDaLista();
        novo->prox = NULL;
        novo->valor = item; 

        NoDaLista *aux = lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;*/

        NoDaLista * novo = new NoDaLista();
        novo->valor = item;
        novo->prox = NULL;

        if(this->inicio == NULL){
            this->inicio = novo;
        }
        else {
            NoDaLista *atual;
            atual = this->inicio;
            while(atual->prox !=NULL){
                atual=atual->prox;
            }
            atual->prox = novo;
        }


    }


   /* Queue *novoItem = new Queue;
    novoItem->item = v;
    novoItem->proximo = NULL;
 
    if(f == NULL) {
        f = novoItem;
    }
    else {
        Queue *aux = f;
        while(aux->proximo !=NULL) {
            aux = aux->proximo;
        }
        aux->proximo = novoItem;
    }
    return f;*/

    int GameObjectList::MouseDown(float x, float y){
        NoDaLista *aux = inicio;
        std::cout<<"Posicao do x do clic: " << x << std::endl;
        std::cout<<"Posicao do y do clic: " << y << std::endl;    
        while (aux != NULL)
        {
            if(aux->valor->MouseDown(x,y)) {
                return 1;
                break;
            }
            aux = aux->prox;
        }
        return 0;
    }
