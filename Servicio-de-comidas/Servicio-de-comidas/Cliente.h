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
	int contraseña;
	
	//Creamos un metodo para que añada e ingrese respectivos valores.
	Cliente(string nm,int n, string ped, int prec, int contraseña) {
		
		nombre = nm;
		n_orden = n;
		pedido = ped;
		precio = prec;
		contraseña = contraseña;

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
		ss << ", Contraseña:";
		ss << contraseña;
		ss << " )";
		return (ss.str());
	}
	
};