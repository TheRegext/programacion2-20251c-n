///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>

///A partir de este fuente:
    /// Generar un proyecto con un men� (Agregar registros, listar registros y salir)
    ///Cada clase debe definirse en un .h distinto, y el desarrollo de sus m�todos
    ///hacerse en un cpp distinto
///Completar los m�todos faltantes de las clases
///Ver lo que devuelven los m�todos para dar los mensajes que correspondan


using namespace std;

class Fecha{
private:
    int dia, mes,anio;
public:
    void Cargar();
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }

};

void Fecha::Cargar(){
        cout<<"DIA ";
        cin>>dia;
        cout<<"MES ";
        cin>>mes;
        cout<<"ANIO ";
        cin>>anio;
    }

///fin de la clase Fechar

class Alumno{
 private:
    int legajo;
    char nombre[30];
    char apellido[30];
    char email[30];
    Fecha fechaNacimiento; ///COMPOSICI�N-> USAMOS UN OBJETO DE UNA CLASE COMO PROPIEAD DE OTRA CLASES
    int codigoCarrera;
    bool estado;
 public:
    void Cargar(int leg);
    void Mostrar();
    int getLegajo(){return legajo;}

    void setLegajo(int _legajo){legajo=_legajo;}
    void setEstado(bool _estado){estado=_estado;}
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
    estado=true;
}

void Alumno::Mostrar(){
    cout<<"LEGAJO "<<legajo<<endl;
    cout<<"NOMBRE "<<nombre<<endl;
    cout<<"APELLIDO "<<apellido<<endl;
    cout<<"EMAIL "<<email<<endl;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.Mostrar();
    cout<<"CARRERA "<<codigoCarrera<<endl;
}

class ArchivoAlumnos{
private:
    char nombre[30];
    int tamanioRegistro;
public:
    ArchivoAlumnos(const char *n="alumnos.dat"){
        strcpy(nombre, n);
        tamanioRegistro=sizeof(Alumno);
    }
    int agregarRegistro();
    bool listarRegistros();
    int buscarAlumno(int leg);///busca si hay un alumno en el archivo con el legajo que recibe
                              /// si lo encuentra devuelve la posici�n del registro en el archivo
                            ///si no le encuentra devuelve -1
    
    
    Alumno leerRegistro(int pos);
    bool bajaRegistro(int leg);
    int contarRegistros();
    bool modificarRegistro(Alumno reg, int pos);
};

int ArchivoAlumnos::buscarAlumno(int leg){///
    Alumno obj;
    FILE *pAlumno;
    pAlumno=fopen(nombre,"rb");

    if(pAlumno==nullptr){  ///NULL
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&obj, tamanioRegistro,1,pAlumno)==1){
       if(obj.getLegajo()==leg){
            return pos;
       }
       pos++;
    }

    fclose(pAlumno);
    return -1;
}

int ArchivoAlumnos::agregarRegistro(){
    Alumno obj;
    /// Que no se repita el legajo.
    int leg;
    cout<<"INGRESAR LEGAJO ";
    cin>>leg;
    int encontro=buscarAlumno(leg);
    if(encontro!=-1){
        cout<<"YA EXISTE EL LEGAJO"<<endl;
        return -2;
    }
    obj.Cargar(leg);
    FILE *pAlumno;
    pAlumno=fopen(nombre,"ab");
    if(pAlumno==nullptr){
        return -1;
    }

    int escribio=fwrite(&obj, tamanioRegistro,1,pAlumno);

    fclose(pAlumno);
    return escribio;
}

bool ArchivoAlumnos::listarRegistros(){
    Alumno obj;
    FILE *pAlumno;
    pAlumno=fopen(nombre,"rb");

    if(pAlumno==nullptr){  ///NULL
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }


    while(fread(&obj, tamanioRegistro,1,pAlumno)==1){
        obj.Mostrar();
        cout<<endl;
    }

    fclose(pAlumno);
    return true;
}

Alumno ArchivoAlumnos::leerRegistro(int pos){
    FILE *pAlu;
    Alumno reg;
    reg.setLegajo(-1);
    ///int pos=0;
    pAlu=fopen(nombre, "rb");
    if(pAlu==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
        return reg;
    }
    int cuanto=pos*sizeof(Alumno);
    int desde_donde=0;
    fseek(pAlu,cuanto, desde_donde);
    fread(&reg, tamanioRegistro,1, pAlu);
    fclose(pAlu);
    return reg;
}

bool ArchivoAlumnos::bajaRegistro(int leg){
    Alumno reg;
    ArchivoAlumnos archi;
    int pos=archi.buscarAlumno(leg);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg=archi.leerRegistro(pos);///en reg tengo el registro a borrar
    reg.setEstado(false);
    return archi.modificarRegistro(reg, pos);
}

int ArchivoAlumnos::contarRegistros(){
    FILE *pAlu;
    Alumno reg;

    pAlu=fopen(nombre, "rb");
    if(pAlu==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
        return -1;
    }
    fseek(pAlu,0, 2);///se ubica el puntero al final del archivo
    int cantByte=ftell(pAlu);///ftell() me dice cu�ntos bytes hay desde el inicio hasta la posici�n actual
    fclose(pAlu);
    return cantByte/tamanioRegistro;///son los registros totales. No diferencia si est�n o no borrados los registros
}

bool ArchivoAlumnos::modificarRegistro(Alumno reg, int pos){
    FILE *pAlu;
    pAlu=fopen(nombre, "rb+");
    if(pAlu==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
        return false;
    }
    fseek(pAlu,pos*sizeof(Alumno), 0);///se ubica el puntero al principio del registro a modificar
    bool modifico=fwrite(&reg, sizeof(Alumno),1,pAlu);
    fclose(pAlu);
    return modifico;
}

int main(){
    ArchivoAlumnos  archiAlu;

    if(archiAlu.agregarRegistro()!=1){
        cout<<"PROBLEMAS CON EL ARCHIVO"<<endl;
    }
    system("pause");
    if(archiAlu.listarRegistros()==false){
        cout<<" NO SE PUDO LEER EL ARCHIVO"<<endl;
    }

    cout<<endl;
	system("pause");
	return 0;
}
