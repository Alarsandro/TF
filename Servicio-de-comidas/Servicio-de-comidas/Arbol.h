#pragma once
#include <iostream>
#include <functional>

template <class T>
class NodoAB {
public:
	T elemento;
	NodoAB* izq;
	NodoAB* der;
};

template <class T>
class ArbolBB {
	typedef std::function<int(T, T)> Comp; // funcion lambda
	NodoAB<T>* raiz;
	void(*procesar)(T); // Puntero a funcion
	Comp comparar; // lambda a criterio de comparacion

	bool _buscar(NodoAB<T>* nodo, T e) {
		if (nodo == nullptr) return false;
		else {
			int r = comparar(nodo->elemento, e);
			if (r == 0) return true;
			else if (r < 0) return _buscar(nodo->der, e);
			else return _buscar(nodo->izq, e);
		}
	}

	NodoAB<T>* _obtener(NodoAB<T>* nodo, T e) {
		if (nodo == nullptr) return nullptr;
		else {
			int r = comparar(nodo->elemento, e);
			if (r == 0) return true;
			else if (r < 0) return _obtener(nodo->der, e);
			else return _obtener(nodo->izq, e);
		}
	}

	bool _insertar(NodoAB<T>*& nodo, T e) {
		if (nodo == nullptr) {
			nodo = new NodoAB<T>();
			nodo->elemento = e;
			return true;
		}
		else {
			int r = comparar(nodo->elemento, e);
			if (r == 0) return false;
			else if (r < 0) return _insertar(nodo->der, e);
			else return _insertar(nodo->izq, e);
		}
	}

	int _minimo(NodoAB<T>* nodo) {
		if (nodo->izq == nullptr) return nodo->elemento;
		else return _minimo(nodo->izq);
	}

	int _maximo(NodoAB<T>* nodo) {
		if (nodo->der == nullptr) return nodo->elemento;
		else return _maximo(nodo->der);
	}
	

	void _preOrden(NodoAB<T>* nodo) {
		if (nodo == nullptr) return;
		procesar(nodo->elemento);
		_preOrden(nodo->izq);
		_preOrden(nodo->der);
	}

	void _enOrden(NodoAB<T>* nodo) {
		if (nodo == nullptr) return;
		_enOrden(nodo->izq);
		procesar(nodo->elemento);
		_enOrden(nodo->der);
	}

	void _postOrden(NodoAB<T>* nodo) {
		if (nodo == nullptr) return;
		_postOrden(nodo->izq);
		_postOrden(nodo->der);
		procesar(nodo->elemento);
	}

	int _cantidad(NodoAB<T>* nodo) {
		//La cantidad de nodos del árbol es:
		//	0 si es vacío
		//	1 + la cantidad de nodos por la izquierda + la cantidad de nodos por la derecha
		if (nodo == nullptr)
			return 0;
		else
		{
			int ci, cd;
			ci = _cantidad(nodo->izq);
			cd = _cantidad(nodo->der);
			return 1 + ci + cd;
		}

	}

	int _altura(NodoAB<T>* nodo) {
		//La altura del árbol es:
		//	0 si es vacío
		//	la mayor de las alturas por la izquierda y por la derecha, las cuáles son 0 si son vacías ó 1 + la altura por la izq(o der) en caso contrario

		if (nodo == nullptr)
			return 0;
		else
		{
			int ai, ad;
			ai = 1 + _altura(nodo->izq);
			ad = 1 + _altura(nodo->der);
			return ai > ad ? ai : ad;
		}
	}

	bool _vacio() {
		return raiz == nullptr;
	}

public:
	ArbolBB(void(*otroPunteroAFuncion)(T)) {
		this->procesar = otroPunteroAFuncion;
		this->comparar = [](T a, T b)->int {return a - b; };
		raiz = nullptr;
	}

	bool insertar(T e) {
		return _insertar(raiz, e);
	}

	bool buscar(T e) {
		return _buscar(raiz, e);
	}

	int minimo() {
		return _minimo(raiz);
	}

	int maximo() {
		return _maximo(raiz);
	}

	void preOrden() {
		return _preOrden(raiz);
	}

	void enOrden() {
		return _enOrden(raiz);
	}

	void postOrden() {
		return _postOrden(raiz);
	}

	int altura() {
		return _altura(raiz);
	}

	int cantidad() {
		return _cantidad(raiz);
	}
};