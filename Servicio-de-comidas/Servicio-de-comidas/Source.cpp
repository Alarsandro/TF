#include <iostream>
#include"Lista.h"
#include<conio.h>
//Para trabajar con archivos
#include "string"
#include "Arbol.h"
#include "generador.h"
#include <vector>
using namespace std;
using namespace System;

void menu() {

    system("cls");
    cout << "Menu: \n";
    cout << "1. Generar datos y guardarlos en CSV \n";
    cout << "2. Mostrar orden del arbol segun EnOrden, PreOrden o PostOrden \n";
    cout << "3. Mostrar arbolAVL segun EnOrden, PreOrden o PostOrden \n";
    cout << "4. Ordenar N° pedido \n";
    cout << "5. Cargar datos del CSV\n";
    cout << "0. Salir \n";
    cout << "Opcion: ";
}


int main() {
    srand(time(NULL));
    //creamos la lista usadno la clase cliente
    //Lista<Cliente*>pLista;
    
    Generate generador;
    
    
    ofstream nomArch;
    int menu1 = 8, n_orden, auxA=0;
    int precio=0;
    int h = 0;
    string nombre, pedido;
    string p = "pollo";
    string ha = "hamburguesa";
    string he = "helado";
    //creamos un menu de opciones
    while (menu1 != 0) {
        Console::ForegroundColor = ConsoleColor::White;
        
        menu();
        cin >> menu1;

        switch (menu1)
        {

        case 1: {system("cls");
            //ingresamos datos del cliente
            /*int op;
            cout << "opcion 1 o 2;" << endl;
            cin >> op;
            if (op == 1)
            {
                generador.Givedata();
            }
            if (op == 2) {
                generador.ManualData();
            }*/

            generador.createData();
            system("pause");  system("cls");
            break; }

        case 2: {
            int x;
            int c;
            system("cls");
            cout << "Elige una opcion";
            cout << "1-En Orden \n 2-Post Orden \n 3-Pre Orden";
            cin >> c;

            if (c == 1)
            {
                cout << "\nArbol en EnOrden: ";
                generador.aC->enOrden();
            }
            if (c == 2) {
                cout << "\nArbol en PostOrden: ";
                generador.aC->postOrden();

            }if (c == 3)
            {
                cout << "\nArbol en PreOrden: ";
                generador.aC->preOrden();
            }

            cout << "\nCantidad de elementos del Arbol: " << generador.aC->cantidad();
            cout << "\nElemento minimo del Arbol: " << generador.aC->minimo();
            cout << "\nElemento maximo del Arbol: " << generador.aC->maximo();
            cout << "\nAltura del Arbol: " << generador.aC->altura();
            cout << "\nEliga el numero de pedido a buscar: ";
            cin >> x;
            cout << "\n" << generador.aC->buscar(x);
            cout << "\n";

            

            cout << "\nArbol en PreOrden: ";
            /*aC->PreOrden();*/


            system("pause");
            system("cls");
        }
              break;
        case 3:
            cout << "\nArbolAVL en PreOrden: ";
            generador.acAVL->preOrder();
            cout << "\n";          
            system("pause");
            break;
            generador.generarTXT();
            cout << "Lista generada en bloc de notas"; _sleep(800);

            break;
        case 4:

            generador.ordenar();
            generador.mostrar();


            system("pause");
            break;

        case 5:

            generador.setDataCSV();


        case 6:
            generador.mostrar();
            cout << "nodo\n" << generador.pLista.gethight();
            system("pause");

        case 7:
            generador.createData();
        }
        
        cout << "GRACIAS :)"; _sleep(800);
    }
}
