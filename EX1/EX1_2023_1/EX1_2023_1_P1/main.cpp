/* 
 * File:   main.cpp
 * Author: USUARIO
 *
 * Created on 22 de mayo de 2025, 11:20 AM
 */

#include <iostream>
#include <iomanip>
#include <limits>

#include "funcionesLista.h"
#include "Estructuras.h"
#define MAX 8 //maximo de camiones
#define MAXT 4 //maximo de tortugas
using namespace std;
struct Camion{
    struct Lista lista;
};

void CargaCombinacion(int intento, int *cromo){
    int i=0;
    while(intento>0){
        cromo[i] = intento % MAXT;
        intento = intento / MAXT;
        i++;
    }
}
void LeerDatos(int nCamiones, int *MaxCarga, struct Camion *ArrCamiones){
    ifstream arch("Datos.txt", ios::in);
    int nPaquetes = 0, paquete, cantCamiones;
    arch>>cantCamiones;
    nCamiones = cantCamiones;
    for(int i=0; i<4; i++)arch>>MaxCarga[i];
    for(int i=0; i<cantCamiones; i++)construir(ArrCamiones[i].lista);
    while(true){
        arch>>paquete;
        if(arch.eof())break;
        if(paquete == 0) nPaquetes++;
        else insertarAlFinal(ArrCamiones[nPaquetes].lista, paquete);
    }
}
int ObtenerPesoCamion(struct Camion camion){
    int PesoTotal = 0;
    Nodo *recorrer = camion.lista.cabeza;
    while(recorrer){
        PesoTotal += recorrer->elemento;
        recorrer = recorrer->siguiente;
    }
    return PesoTotal;
}
void OrdenarLista(struct Lista &Camion, int tipo){
    Nodo *recorrido, *recorridoSig;
    for(int i=0; i<Camion.longitud; i++){
        recorrido = Camion.cabeza;
        recorridoSig = Camion.cabeza->siguiente;
        for(int k=0; k<= Camion.longitud; k++){
            if(tipo == 2){
                if(recorrido->elemento < recorridoSig->elemento){
                    recorrido->siguiente = recorrido->siguiente;
                    recorridoSig->siguiente = recorrido;
                    if(k == 0){
                        Camion.cabeza = recorridoSig;
                    }
                    Nodo *Aux = recorrido->siguiente;
                    recorrido = recorrido->siguiente;
                    recorridoSig = Aux;
                }else{
                    recorrido = recorridoSig;
                    recorridoSig = recorridoSig->siguiente;
                }
            }
            if(tipo == 1){
                if(recorrido->elemento > recorridoSig->elemento){
                    recorrido->siguiente = recorrido->siguiente;
                    recorridoSig->siguiente = recorrido;
                    if(k == 0){
                        Camion.cabeza = recorridoSig;
                    }
                    Nodo *Aux = recorrido->siguiente;
                    recorrido = recorrido->siguiente;
                    recorridoSig = Aux;
                }else{
                    recorrido = recorridoSig;
                    recorridoSig = recorridoSig->siguiente;
                }
            }
        }
    }
}
void fusionarListaIntercalado(struct Lista &original, struct Lista &sec){
    int i=0;
    Nodo *ListaPrincipal =original.cabeza;
    Nodo *ListaSec = sec.cabeza;
    Nodo *aux2 = nullptr;
    
    while(ListaSec != nullptr){
        if(ListaPrincipal != nullptr){
            if(i % 2 == 0){
                Nodo *Aux1 = ListaPrincipal->siguiente;
                ListaPrincipal->siguiente = ListaSec;
                aux2 = ListaSec->siguiente;
                ListaPrincipal->siguiente->siguiente = Aux1;
                ListaPrincipal = ListaPrincipal->siguiente;
                ListaPrincipal = ListaPrincipal->siguiente;
                original.longitud++;
            }else{
                ListaSec = aux2;
                ListaPrincipal = ListaPrincipal->siguiente;
            }
            i++;
        }else{
            insertarAlFinal(original, ListaSec->elemento);
            ListaSec = ListaSec->siguiente;
        }
    }
}
bool cumpleMision(int nCamiones, int *MaxCarga, struct Camion *ArrCamiones, int &solucion, int *cantRescatados){
    int opciones = pow(MAXT, nCamiones);
    int Cromo[MAX]{}, rescatados[MAXT]{};
    bool HaySolucion = true;
    for(int i=0; i<opciones; i++){
        CargaCombinacion(i, Cromo);
        
        for(int k=0; k<MAXT; k++)rescatados[k] = 0;
        for(int k=0; k<MAXT; k++)cantRescatados[k] = 0;
        for(int k=0; k<nCamiones; k++){
            int a = Cromo[k];
            int pesoCamion = ObtenerPesoCamion(ArrCamiones[k]);
            rescatados[a] += pesoCamion;
            cantRescatados[a]++;
        }
        HaySolucion = true;
        for(int k=0; k<MAXT; k++){
            if(rescatados[k] == 0 || rescatados[k] > MaxCarga[k] || cantRescatados[k] > 2){
                HaySolucion = false;
                break;
            }
        }
        if(HaySolucion == true){
            solucion = i;
            break;
        }
    }
}
void ImprimirSolucion(struct Camion *ArrCamiones, int nCamiones, int solucion, int cantRescatados){
    int Cromo[MAX]{};
    CargaCombinacion(solucion, Cromo);
    for(int i=0; i<MAXT; i++){
        if(i == 0) cout<< "Leonardo: ";
        if(i == 1) cout<< "Rafael: ";
        if(i == 2) cout<< "Donatelo: ";
        if(i == 3) cout<< "Miguel Angel: ";
        if(cantRescatados[i] == 1){
            for(int k=0; k<nCamiones; k++){
                if(Cromo[k] == i)imprime(ArrCamiones[k].lista);
            }
        }else{
            int lista1, lista2, cont= 0;
            for(int k=0; k<nCamiones; k++){
                if(Cromo[k] == i){
                    if(cont == 0){
                        lista1 = k; cont++;
                    }
                    lista2 = k;
                }
            }
            OrdenarLista(ArrCamiones[lista1].lista,1);
            OrdenarLista(ArrCamiones[lista2].lista,2);
            fusionarListaIntercalado(ArrCamiones[lista1].lista, ArrCamiones[lista2].lista);
            imprime(ArrCamiones[lista1].lista);
        }
    }
}


int main(int argc, char** argv) {
    int nCamiones, solucion = 0, cantRescatados[MAX]{};
    int MaxCarga[MAXT]{};
    struct Camion ArrCamiones[MAXT]{};
    
    //Parte A
    LeerDatos(nCamiones, MaxCarga, ArrCamiones);
    
    //Parte B
    if(cumpleMision(nCamiones, MaxCarga, ArrCamiones, solucion, cantRescatados)){
        
        cout<<"Las tortugas ninjas completaron su mision"<<endl;
        cout<<"Los camiones a salvar son: "<<endl;
        ImprimirSolucion(ArrCamiones, nCamiones, solucion, cantRescatados);
    }else{
        cout<< "Las tortugas ninjas NO completaron su mision"<<endl;
    }
    return 0;
}

