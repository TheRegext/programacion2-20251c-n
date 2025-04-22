///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>

using namespace std;

///clase Fecha

///Asignarle valores a un objeto Alumno, luego cargar una fecha, y por último comparar informar si la fecha de nacimiento del alumno
///es igual a la fecha cargada.

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

};


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
    Alumno obj;
    Fecha aux;
    int anio;
    cout<<"INGRESE EL ANIO ";
    cin>>anio;
    aux=obj.getFechaNacimiento();
    /*if(aux.getAnio()==anio){
        cout<<"EL ALUMNO NACIO EN EL ANIO INGRESADO "<<endl;
    }
    else{
        cout<<"EL ALUMNO NO NACIO EN EL ANIO INGRESADO "<<endl;
    } */

    if(obj.getFechaNacimiento().getAnio()==anio){
        cout<<"EL ALUMNO NACIO EN EL ANIO INGRESADO "<<endl;
    }
    else{
        cout<<"EL ALUMNO NO NACIO EN EL ANIO INGRESADO "<<endl;
    }



	system("pause");
	return 0;
}
