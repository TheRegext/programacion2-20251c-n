///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>

using namespace std;

///clase Fecha

///Sobrecarga de operadores: es un mecanismo que permite agregarle funcionalidad a los operadores del lenguaje.
///Se puede escribir código en cada sobrecarga (métodos de una clase en particular) que se ejecutará cuando el operador sea utilizado

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int dia=0, int mes=0, int anio=0){
            this->dia=dia;
            this->mes=mes;
            this->anio=anio;
        }
        void Cargar(){
            cout<<"DIA ";
            cin>>dia;
            cout<<"MES ";
            cin>>this->mes;
            cout<<"ANIO ";
            cin>>this->anio;
        }
        void Mostrar();

        void MostrarEnLinea(){cout<<dia<<"/"<<mes<<"/"<<anio<<endl;}
        ///modificar cada propiedad
        void setDia(int d){dia=d;}///acá es donde se deberían hacer las validaciones
        void setMes(int d){mes=d;}
        void setAnio(int d){anio=d;}
        ///sacar hacia afuera el valor de cada propiedad
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

        ///sobrecarga de operadores
        bool operator==(Fecha aux);
        bool operator==(const char *mes);

};

bool Fecha::operator==(Fecha aux){
    if(dia!=aux.dia) return false;
    if(mes!=aux.mes) return false;
    if(anio!=aux.anio) return false;
    return true;
}

bool Fecha::operator==(const char *nombreMes){
    char meses[12][20]={"ENERO","FEBRERO","MARZO","ABRIL"};
    if(strcmp(meses[mes-1], nombreMes)==0) return true;
    return false;

}


void Fecha::Mostrar(){
            cout<<"DIA "<<dia<<endl;
            cout<<"MES "<<mes<<endl;
            cout<<"ANIO "<<anio<<endl;
        }



///fin clase Fecha

class Alumno{
 private:
    int legajo;
    char nombre[30];
    char apellido[30];
    char email[30];
    Fecha fechaNacimiento;
    int codigoCarrera;
 public:
    Alumno(int l=123, const char *n="nada", const char *ape="nada", const char *em="vacio", int cc=1){
        legajo=l;
        strcpy(nombre,n);
        strcpy(apellido,ape);
        codigoCarrera=cc;

    }
    void Cargar();
    void Mostrar();
    int getAnio(){return fechaNacimiento.getAnio();}

    Fecha getFechaNacimiento(){return fechaNacimiento;}
    void setFechaNacimiento(Fecha aux){fechaNacimiento=aux;}
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
    fechaNacimiento.Cargar();
    cout<<"CARRERA ";
    cin>>codigoCarrera;
}

void Alumno::Mostrar(){
    cout<<"LEGAJO "<<legajo<<endl;
    cout<<"NOMBRE "<<nombre<<endl;
    cout<<"APELLIDO "<<apellido<<endl;
    cout<<"EMAIL "<<email<<endl;
    fechaNacimiento.Mostrar();
    cout<<"CARRERA "<<codigoCarrera<<endl;
}





int main(){

    Fecha aux;
    Fecha nacimiento;

    char mes[20];
    cout<<"INGRESE EL MES ";
    cin>>mes;

    aux.Cargar();
    nacimiento.Cargar();

    ///if(aux.operator==(nacimiento))
    if(aux==nacimiento){
        cout<<"LAS DOS FECHAS SON IGUALES ";
    }
    else{
        cout<<"LAS FECHAS SON DISTINTAS";
    }
    //aux.Cargar();///fecha para comparar


    ///if(aux==mes){
    /*if(aux.operator==(mes)){
        cout<<"LOS MESES SON IGUALES ";
    }
    else{
        cout<<"LOS MESES SON DISTINTOS";
    }
      */
    cout<<endl;
	system("pause");
	return 0;
}
