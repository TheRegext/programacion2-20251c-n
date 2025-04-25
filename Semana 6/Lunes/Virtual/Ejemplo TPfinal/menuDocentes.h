#ifndef MENUDOCENTES_H_INCLUDED
#define MENUDOCENTES_H_INCLUDED
void menuDocentes(){
    int opc;
    while(true){
        system("cls");
        cout << "******ABML DOCENTES******" << endl;
        cout << "1. ALTA" << endl;
        cout << "2. BAJA" << endl;
        cout << "3. MODIFICAR EMAIL " << endl;
        cout << "4. LISTADO" << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << "************************" << endl;
        cout << "SELECCIONAR OPCION " << endl;
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                    break;
            case 2:
                    break;
            case 3:
                    break;
            case 4:
                    break;
            case 0: return;
                    break;
            default: cout<<"LA SELECCION NO ES CORRECTA"<<endl;

        }
        system("pause");
    }
    return;
 }


#endif // MENUDOCENTES_H_INCLUDED
