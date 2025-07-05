#include <iostream>
using namespace std;
#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"

struct NodoArbol * c_crearNuevoNodo(struct NodoArbol * izquierda, int elemento,
        struct NodoArbol * derecha) 
{
    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    return nuevo;
}

void aplicar_arbol_rec(NodoArbol* &nodo_resultado,
        NodoArbol* nodo_paquete, NodoArbol* nodo_sistema) 
{
    if (esNodoVacio(nodo_paquete) or esNodoVacio(nodo_sistema)) 
            return;
    
    int valor = nodo_paquete->elemento + 
                numeroNodosRecursivo(nodo_sistema) - 
                numeroHojasRecursivo(nodo_sistema);  
    
    nodo_resultado = c_crearNuevoNodo(nullptr, valor, nullptr);
    
    aplicar_arbol_rec(nodo_resultado->izquierda, nodo_paquete->izquierda, nodo_sistema->izquierda);
    aplicar_arbol_rec(nodo_resultado->derecha, nodo_paquete->derecha, nodo_sistema->derecha);
}

struct ArbolBinarioBusqueda aplicar_arbol(
        ArbolBinarioBusqueda &paquetes, 
        ArbolBinario &sistema) 
{
    ArbolBinarioBusqueda resultado;
    aplicar_arbol_rec(resultado.arbolBinario.raiz,
                      paquetes.arbolBinario.raiz, 
                      sistema.raiz);
    return resultado;
}

bool esABB(struct NodoArbol* nodo, int min_val = -100000, int max_val = 100000){
    if(esNodoVacio(nodo)) return true;
    if(nodo->elemento <= min_val or nodo->elemento>=max_val) return false;
    return esABB(nodo->izquierda, min_val, nodo->elemento) and
            esABB(nodo->derecha, nodo->elemento, max_val);
}

int sumarNodos(struct NodoArbol* nodo){
    if(esNodoVacio(nodo)) return 0;
    return nodo->elemento + sumarNodos(nodo->izquierda) + sumarNodos(nodo->derecha);
}

bool determinar_anomalia(ArbolBinarioBusqueda resultado) {
    NodoArbol* raiz = resultado.arbolBinario.raiz;
    return esABB(raiz) && (sumarNodos(raiz) % 2 == 0);
}

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol_paquetes;
    construir(arbol_paquetes);
    insertar(arbol_paquetes, 5);
    insertar(arbol_paquetes, 3);
    insertar(arbol_paquetes, 9);   
    cout << "In-Order arbol_paquetes:" << endl;
    enOrden(arbol_paquetes);
        
    struct ArbolBinario arbol_sistema;
    construir(arbol_sistema);  
    plantarArbolBinario(arbol_sistema.raiz, nullptr, 1, nullptr);
    plantarArbolBinario(arbol_sistema.raiz->izquierda, nullptr, 7, nullptr);
    plantarArbolBinario(arbol_sistema.raiz->derecha, nullptr, 8, nullptr);
    plantarArbolBinario(arbol_sistema.raiz->izquierda->izquierda, nullptr, 2, nullptr);
    plantarArbolBinario(arbol_sistema.raiz->izquierda->derecha, nullptr, 3, nullptr);    
    cout << "\nIn-Order arbol_sistema:" << endl;
    recorrerEnOrden(arbol_sistema);
    
    struct ArbolBinarioBusqueda arbol_resultado = aplicar_arbol(arbol_paquetes, arbol_sistema);
    cout << "\nIn-Order arbol_resultado:" << endl;
    enOrden(arbol_resultado);
    cout << endl;

    // Determinar si hay anomalías
    if (determinar_anomalia(arbol_resultado)) {
        cout << "Sin eventos sospechosos" << endl;
    } else {
        cout << "Anomalia detectada" << endl;
    }
    
    return 0;
}
