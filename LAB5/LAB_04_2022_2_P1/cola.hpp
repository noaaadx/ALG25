#include <queue>

using Cola = std::queue<NodoArbol*>;


bool estaVacia(Cola &cola){
	return cola.empty();
}

void encolar(Cola& cola, NodoArbol* nodo){
	cola.push(nodo);
}

NodoArbol* desencolar(Cola &cola){
	NodoArbol *nodo = cola.front();
	cola.pop();
	return nodo;
}

int longitud(Cola &cola){
	return cola.size();
}