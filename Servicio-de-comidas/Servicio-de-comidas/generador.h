#pragma once
#include "Cliente.h"
#include <fstream> 
#include <vector>
#include "Lista.h"
#include "iostream"
#include "conio.h"
#include "time.h"
#include "HashTable.h"
#include"ArbolAVL.h"
#include"Arbol.h"
using namespace std;
using namespace System;

string nombreA[] = { "sandro","julian","pepe","juan","joshua","giovanni","lucio","samuel","pepe","jorge","jose","luis","lucho", "jhonny","lujan","belligham" };
string pedidoA[] = { "pollo y papas","pan con pollo","jugo de manzana","jugo de moras","pan con pavo", "pan con huevo","hamburguesa de pollo","hamburguesa de carne" };

vector<Cliente>pvector;

void imprimir(int e) {
	cout << e << endl;
	//printf("%d ", e);
}



class Generate {
public:

	AVLTree<int>* acAVL = new AVLTree<int>(imprimir, [](int a, int b) -> bool {		return a > b; });
	ArbolBB<int>* aC = new ArbolBB<int>(imprimir);
	Lista<Cliente*>pLista;
	HashTable<Cliente>* hasht;
	fstream Myfile;
	ofstream filewrite;
	ifstream fileread;
	
public:

	Generate() { 
		hasht = new HashTable<Cliente>(10000);
		// crear lista
	};

	~Generate(){};
	
	//void Givedata(){
	//	

	//		Random r;
	//		string pedido;
	//		string nombre;
	//		int n_orden;
	//		int precio;
	//		
	//		precio = costoA[r.Next(0, 25)];
	//		pedido = pedidoA[r.Next(0, 7)];
	//		nombre = nombreA[r.Next(0, 12)];
	//		n_orden = costoA[r.Next(0, 25)];

	//		Cliente* gp1 = new Cliente(nombre, n_orden, pedido, precio);
	//		ingresamos el cliente en la lista
	//		pLista.InsertarFinal(gp1);
	//		createData(nombre, n_orden, pedido, precio);
	//		aC->insertar(n_orden);
	//		acAVL->insertar(n_orden);
	//	
	//}

	//void ManualData() {
	//	string pedido;
	//	string nombre;
	//	int n_orden;
	//	int precio;
	//	Random r;
	//	cout << "Ingrese nombre: \n"; cin >> nombre;
	//	cout << "\nEscriba su pedido(pollo,hamburguesa, helado): \n";
	//	cin >> pedido;
	//	int aux = r.Next(1, 1000);
	//	int n_ordeni = r.Next(1, 7);
	//	auto g_orden = [](int n_ordeni, long aux) {//uso de lambda para obtener el numero de orden
	//		return n_ordeni + aux; };
	//	n_orden = g_orden(aux, n_ordeni);
	//	cout << "\nNumero de pedido: \n" << n_orden << endl;
	//	//precios: 15-7-5 para p,ha,he

	//	Cliente* p1 = new Cliente(nombre, n_orden, pedido, precio);
	//	createData(nombre, n_orden, pedido, precio);
	//	pLista.InsertarFinal(p1);

	//	aC->insertar(n_orden);
	//	acAVL->insertar(n_orden);


	//}


	/*void getData(string nombre,int n_orden, string pedido, int precio) {


		Myfile.open("data.csv", ios::app);
		
		int nombreespaciador = nombre.find(" ");
		if (nombre[nombreespaciador]==32)
		{
			nombre = " " + nombre + " ";
		}	
		Myfile << nombre + ", " << n_orden << " ," << pedido << " ," << precio << endl;
		
		Myfile.close();

	}*/

	//imprimi
	void createData() {
		fileread.close();
		filewrite.open("data.csv", ios::out);

			for(int i=0;i<1000;++i){
				Random r;
				string pedido;
				string nombre;
				int n_orden;
				int precio;
				int contraseña;



				contraseña = rand() % 9999 + 1;
				precio =rand() % 100+1 ;
				pedido = pedidoA[rand() % 7];
				nombre =nombreA[rand() % 12];
				n_orden = rand() % 100+45;



		filewrite << nombre << " , " << n_orden << " , " << pedido << " , " << precio << " , " << contraseña << endl;
		Cliente* gp1 = new Cliente(nombre, n_orden, pedido, precio, contraseña);
		Cliente phash(nombre, n_orden, pedido, precio, contraseña);
		//ingresamos el cliente en la lista
		pLista.InsertarFinal(gp1);
		aC->insertar(n_orden);

		pvector.push_back(phash);
		//acAVL->insertar(n_orden);


		hasht->insert(nombre, phash);
		acAVL->insert(n_orden);
			
			}
		
		filewrite.close();
		fileread.open("data.csv", ios::in);
	}





	void setDataCSV() {
		//guarda datos generados en el csv
		ifstream archivo("data.csv");
		string linea;
		char delimitador = ',';

		while (getline(archivo,linea))
		{

			stringstream stream(linea);
			string nombre, n_orde, pedido, preci,contraseñ;


			getline(stream, nombre, delimitador);
			getline(stream, n_orde, delimitador);
			getline(stream, pedido, delimitador);
			getline(stream, preci, delimitador);
			getline(stream, contraseñ, delimitador);


			int n_orden = stoi(n_orde);
			int precio = stoi(preci);
			int contraseña = stoi(contraseñ);


			Cliente *p1= new Cliente(nombre, n_orden, pedido,precio, contraseña);
			Cliente phash(nombre, n_orden, pedido, precio, contraseña);

			pLista.InsertarFinal(p1);

			aC->insertar(n_orden);
			
			hasht->insert(nombre, phash);
			acAVL->insert(n_orden);

		}

		archivo.close();

	}

	

	void ordenar() {
		pLista.ordenar();
	}

	void mostrar(){
		pLista.mostrarBoleta();
	}

	void generarTXT(){
		pLista.Generartxt();
	}

};

