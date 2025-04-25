#include <iostream>

using namespace std;

#include "menuAlumnos.h"
#include "menuDocentes.h"

int main(){
    int opc;
    while(true){
        system("cls");
        cout << "******MENU PRINCIPAL******" << endl;
        cout << "1. MENU ALUMNOS" << endl;
        cout << "2. MENU PROFESORES" << endl;
        cout << "3. MENU MATERIA " << endl;
        cout << "4. INSCRIPCIONES" << endl;
        cout << "5. REPORTES"<<endl;
        cout << "6. MANTENIMIENTO "<<endl;
        cout << "0. FIN DEL PROGRAMA" << endl;
        cout << "************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: menuAlumnos();
                    cout<<endl;
                    break;
            case 2: menuDocentes();
                    break;
            case 3:
                    break;
            case 4:
                    cout<<endl;
                    break;
            case 5:
                    break;
            case 6:
                    break;

            case 0: return 0;
                    break;
            default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;

        }
        system("pause");
    }
    return 0;
}
