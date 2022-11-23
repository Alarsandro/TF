#pragma once
#include<functional>
using namespace std;


template<class T>
//Son las casillas de la lista
class Nodo
{
public:
	//declaramos publicas los atriibutos de nodo.
	T valor;
	Nodo<T>* anterior;
	Nodo<T>* siguiente;

public:
    //asignamos valores a los atributos del nodo
	Nodo(T v=0, Nodo<T>* ant = NULL, Nodo<T>* sig = NULL) {
		valor = v;
		anterior = ant;
		siguiente = sig;
	}

};
