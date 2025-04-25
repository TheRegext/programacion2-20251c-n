#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED

class Alumno{
 private:
    int legajo;
    char nombre[30];
    char apellido[30];
    char email[30];
    Fecha fechaNacimiento;
    int codigoCarrera;
    bool estado;///activo, borrado
 public:
    void Cargar(int leg);
    void Mostrar();
    int getLegajo(){return legajo;}
    void setCodigoCarrera(int cc){
        codigoCarrera=cc;
    }
    void setEstado(bool e){estado=e;}

    bool getEstado(){return estado;}
};


void Alumno::Cargar(int leg=0){
    if(leg==0){
    cout<<"LEGAJO ";
    cin>>legajo;
    ///
    }
    else{
        legajo=leg;
    }
    cout<<"NOMBRE ";
    cin>>nombre;
    cout<<"APELLIDO ";
    cin>>apellido;
    cout<<"EMAIL ";
    cin>>email;
    cout<<"FECHA DE NACIMIENTO "<<endl;
    fechaNacimiento.Cargar();
    cout<<"CARRERA ";
    cin>>codigoCarrera;
    estado=true;///si quiero que el sistema ignore el registro lo cambio a false
}

void Alumno::Mostrar(){
     if(estado==true){
        cout<<"LEGAJO "<<legajo<<endl;
        cout<<"NOMBRE "<<nombre<<endl;
        cout<<"APELLIDO "<<apellido<<endl;
        cout<<"EMAIL "<<email<<endl;
        cout<<"FECHA DE NACIMIENTO ";
        fechaNacimiento.Mostrar();
        cout<<"CARRERA "<<codigoCarrera<<endl;
     }
}



#endif // ALUMNO_H_INCLUDED
