#pragma once
#include <string>
#include <sstream>

using namespace std;


class Cliente {
public:
//creamos variables para almacenar datos del cliente
	string nombre; 
    int n_orden;
	string pedido;
	int precio;
	int contraseņa;
	
	//Creamos un metodo para que aņada e ingrese respectivos valores.
	Cliente(string nm,int n, string ped, int prec, int contraseņa) {
		
		nombre = nm;
		n_orden = n;
		pedido = ped;
		precio = prec;
		contraseņa = contraseņa;

	}
//imprimimos los datos del cliente de forma ordenada
	string toString1() {
		ostringstream ss;
		ss << "(Nombre: ";
		ss << nombre;
		ss << ", numero de orden: ";
		ss << n_orden;
        ss << ", Pedido: ";
		ss << pedido;
		ss << ", Precio:";
		ss << precio;
		ss << ", Contraseņa:";
		ss << contraseņa;
		ss << " )";
		return (ss.str());
	}
	
};