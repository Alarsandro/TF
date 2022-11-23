#pragma once
#include "Nodo.h"
#include "Cliente.h"
//#include"generador.h"
#include <fstream> 
#include<functional>

using namespace std;

typedef unsigned int uint; //siempre positivo
//creacion de template
template <class T>
class Lista {
private:
	Nodo<T>* inicio;

public:
	Lista() { inicio = NULL; }
	~Lista();
	void InsertarFinal(T v);
	void mostrarBoleta();
	void Generartxt();
	void ordenar();
	int gethight();
	void setFunc(function<void(T)> write);
};
//implementación




//libera espacio
template<class T>
Lista<T>::~Lista() {
	Nodo<T>* temp;
	while (inicio != NULL) {
		temp = inicio;
		inicio = inicio->siguiente;
		delete temp;
		temp = NULL;
	}
	delete inicio;
	inicio = NULL;
}
//insertamos la boleta en la lista
template<class T>
void Lista<T>::InsertarFinal(T v) {
	Nodo<T>* nodo = new Nodo<T>(v);
	if (inicio == NULL)
		inicio = nodo;
	else {
		inicio->anterior = nodo;
		nodo->siguiente = inicio;
		inicio = nodo;
	}
}
//mostramos la boleta con los datos ingresados
template<class T>
void Lista<T>::mostrarBoleta() {
	Nodo<T>* nodo = inicio;
	cout << "Lista de pedidos -> \n ";

	do {
		Cliente* clien = (Cliente*)(nodo->valor);
		cout << clien->toString1();

		if (nodo != NULL)
		{
			cout << " \n ";
		}

		nodo = nodo-> siguiente;


	} while (nodo != NULL);
	cout << "\n";

}


template<class T>
int Lista<T>::gethight() {
	Nodo<T>* nodo = inicio;
	
	int r = 0;
	do{
		
		Cliente* clien = (Cliente*)(nodo->valor);		
		nodo = nodo->siguiente;
		r++;

	}while (nodo != NULL);
	cout << "\n";

	return r;
}



template<class T>
void Lista<T>::Generartxt() {
	ofstream nomArch;
	Nodo<T>* nodo = inicio;
	nomArch.open("miArchivo.txt", ios::out);
	if (nomArch.is_open())
	{


		do {
			Cliente* clien = (Cliente*)(nodo->valor);
			nomArch << clien->toString1();

			if (nodo != NULL)
			{
				nomArch << " \n "<<endl;
			}

			nodo = nodo->siguiente;


		} while (nodo != NULL);
		nomArch << "\n";

		//Cerramos el archivo
		nomArch.close();
	}

}

template<class T>
void Lista<T>::ordenar() {

	Nodo<T>* nodo = inicio;
	Nodo<T>* aux = NULL;
	Cliente* cliente1;
	Cliente* cliente2;
	Cliente* auxClien;

	while (nodo->siguiente != NULL)
	{
		aux = nodo->siguiente;
		while (aux != NULL)
		{
			cliente1 = (Cliente*)(nodo->valor);
			cliente2 = (Cliente*)(nodo->valor);
			if (cliente1->n_orden > cliente2->n_orden)
			{
				auxClien = nodo->valor;
				nodo->valor = aux->valor;
				aux->valor = auxClien;
			}
			aux = aux->siguiente;
		}
		nodo = nodo->siguiente;
	}
}











