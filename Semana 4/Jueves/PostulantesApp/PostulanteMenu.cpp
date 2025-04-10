#include "PostulanteMenu.h"
#include <iostream>
using namespace std;


void PostulanteMenu::mostrar(){

    int opcion;
    do{
    cout << "========================================================" << endl;
    cout << "        SISTEMA DE REGISTRO DE POSTULANTES" << endl;
    cout << "========================================================" << endl;
    cout << "1. Registrar nuevo postulante" << endl;
    cout << "2. Listar todos los postulantes" << endl;
    cout << "3. Buscar postulantes por puesto y experiencia" << endl;
    cout << "4. Mostrar postulantes contratados" << endl;
    cout << "5. Salir" << endl;
    cout << "===============================" << endl;
    cout << "Ingrese una opcion: ";

    cin >> opcion;

    switch(opcion) {
            case 1:
                // Función para registrar nuevo postulante
                break;
            case 2:
                // Función para listar postulantes
                break;
            case 3:
                // Función para buscar por puesto y experiencia
                break;
            case 4:
                // Función para mostrar contratados
                break;
            case 5:
                return;
                break;
            default:
                cout << "Opción inválida. Por favor, intente de nuevo." << endl;
        }

      cout << endl << endl;

    } while(opcion != 5);
}
