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
    FILE *pAlu;
    pAlu=fopen("alumnos.dat","rb"); ///wb->write escribir: modo que crea un archivo vacío
    if(pAlu==nullptr){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return -1;
    }

    while(fread(&obj,sizeof(Alumno),1,pAlu)==1){
        obj.Mostrar();
        cout<<endl;

    }
    /*int i=0;
    while(fread(&obj[i],sizeof(Alumno),1,pAlu)==1){
        obj[i].Mostrar();
        cout<<endl;
        i++;
    }
    */
    ///fread(obj,sizeof(Alumno),3,pAlu);
	fclose(pAlu);
	system("pause");
	return 0;
}
