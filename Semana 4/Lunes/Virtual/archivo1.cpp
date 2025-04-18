///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

class Alumno{
 private:
    int legajo;
    char nombre[30];
    char apellido[30];
    char email[30];
    int codigoCarrera;
 public:
    void Cargar();
    void Mostrar();
};

void Alumno::Cargar(){
    cout<<"LEGAJO ";
    cin>>legajo;
    cout<<"NOMBRE ";
    cin>>nombre;
    cout<<"APELLIDO ";
    cin>>apellido;
    cout<<"EMAIL ";
    cin>>email;
    cout<<"CARRERA ";
    cin>>codigoCarrera;
}

void Alumno::Mostrar(){
    cout<<"LEGAJO "<<legajo<<endl;
    cout<<"NOMBRE "<<nombre<<endl;
    cout<<"APELLIDO "<<apellido<<endl;
    cout<<"EMAIL "<<email<<endl;
    cout<<"CARRERA "<<codigoCarrera<<endl;
}

int main(){

    Alumno obj;
    obj.Cargar();
    ///llevar obj al archivo de alumnos
    FILE *pAlu;
    pAlu=fopen("alumnos.dat","ab"); ///wb->write escribir: modo que crea un archivo vacío ; ab-> agrega; rb-> lee solamente
    if(pAlu==nullptr){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return -1;
    }
    fwrite(&obj,sizeof obj,1,pAlu); ///sizeof(Alumno) tamaño del tipo de dato
    fclose(pAlu);
    cout<<endl;
	system("pause");
	return 0;
}
