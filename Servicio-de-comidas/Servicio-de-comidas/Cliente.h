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
	int contrase�a;
	
	//Creamos un metodo para que a�ada e ingrese respectivos valores.
	Cliente(string nm,int n, string ped, int prec, int contrase�a) {
		
		nombre = nm;
		n_orden = n;
		pedido = ped;
		precio = prec;
		contrase�a = contrase�a;

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
		ss << ", Contrase�a:";
		ss << contrase�a;
		ss << " )";
		return (ss.str());
	}
	
};