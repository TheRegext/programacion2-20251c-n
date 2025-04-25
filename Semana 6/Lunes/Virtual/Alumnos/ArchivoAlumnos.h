#ifndef ARCHIVOALUMNOS_H_INCLUDED
#define ARCHIVOALUMNOS_H_INCLUDED

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
    int agregarRegistro(Alumno reg);
    bool listarRegistros();
    int buscarAlumno(int leg);
    Alumno leerRegistro(int pos);
    int modificarRegistro(Alumno reg, int pos);
    int contarRegistros();
};

int ArchivoAlumnos::buscarAlumno(int leg){///
    Alumno obj;
    FILE *pAlumno;
    pAlumno=fopen(nombre,"rb");

    if(pAlumno==nullptr){  ///NULL
        ///cout<<"ERROR DE ARCHIVO"<<endl;
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

int ArchivoAlumnos::agregarRegistro(Alumno reg){

    FILE *pAlumno;
    pAlumno=fopen(nombre,"ab");
    if(pAlumno==nullptr){
        return -1;
    }

    int escribio=fwrite(&reg, tamanioRegistro,1,pAlumno);

    fclose(pAlumno);
    return escribio;
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
       /// cout<<"ERROR DE ARCHIVO"<<endl;
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
    Alumno obj;
    FILE *pAlumno;
    pAlumno=fopen(nombre,"rb");
    obj.setCodigoCarrera(0);
    if(pAlumno==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return obj;
    }

    fseek(pAlumno,pos*tamanioRegistro,0);
    fread(&obj, tamanioRegistro,1,pAlumno);

    fclose(pAlumno);
    return obj;

}

int ArchivoAlumnos::modificarRegistro(Alumno reg, int pos){
    FILE *pAlumno;
    pAlumno=fopen(nombre,"rb+");/// con + se le agrega al modo lo que no puede hacer
    ///rb->leer; wb->empezar de  un archivo; ab->para agregar registro
    if(pAlumno==nullptr){
        return -1;
    }

    fseek(pAlumno, pos*tamanioRegistro,0);
    int escribio=fwrite(&reg, tamanioRegistro,1,pAlumno);

    fclose(pAlumno);
    return escribio;
}

/*int ArchivoAlumnos::contarRegistros(){
    Alumno obj;
    FILE *pAlumno;
    pAlumno=fopen(nombre,"rb");

    if(pAlumno==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }

    int cantReg=0;
    while(fread(&obj, tamanioRegistro,1,pAlumno)==1){
        cantReg++;
    }

    fclose(pAlumno);
    return cantReg;


} */

int ArchivoAlumnos::contarRegistros(){
    FILE *pAlumno;
    pAlumno=fopen(nombre,"rb");

    if(pAlumno==nullptr){  ///NULL
       /// cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
    fseek(pAlumno,0,2);
    int tam=ftell(pAlumno);

    fclose(pAlumno);
    int cantReg;
    cantReg=tam/tamanioRegistro;
    return cantReg;
}
#endif // ARCHIVOALUMNOS_H_INCLUDED
