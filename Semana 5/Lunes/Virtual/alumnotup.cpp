///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include <iostream>
# include <cstring>


using namespace std;

//# include "alumno.h"/// tiene las clases Alumno y la clase ArchivoAlumno

class Alumno{
private:
    int legajo;
    char nombre[30];
    char apellido[30];
    char email[50];
    bool estado;
public:
    void Mostrar();
    void setLegajo(int leg){legajo=leg;}
    int getLegajo(){return legajo;}
    bool getEstado(){return estado;}




};

void Alumno::Mostrar(){
    if(estado){
        cout<<"LEGAJO ";
        cout<<legajo<<endl;
        cout<<"NOMBRE ";
        cout<<nombre<<endl;
        cout<<"APELLIDO ";
        cout<<apellido<<endl;
        cout<<"EMAIL ";
        cout<<email<<endl;
    }
}

class ArchivoAlumnos{
private:
    char nombre[50];
    int tamanioRegistro;
public:
    ArchivoAlumnos(const char *n="alumnos.dat"){
        strcpy(nombre, n);
        tamanioRegistro=sizeof(Alumno);
    }
    bool grabarRegistro(Alumno reg){
        FILE *pAlumno;
        pAlumno=fopen(nombre,"ab" );//si no puede hacer la apertura fopen devuelve NULL
        if(pAlumno==NULL) return false;
        int escribio=fwrite(&reg,tamanioRegistro,1,pAlumno);
        fclose(pAlumno);
        return escribio;

    }

    bool leerRegistroAlumno(Alumno &reg){
        FILE *pAlumno;
        pAlumno=fopen(nombre,"rb" );//si no puede hacer la apertura fopen devuelve NULL
        if(pAlumno==NULL) return false;
        int leyo=fread(&reg,tamanioRegistro,1,pAlumno);
        fclose(pAlumno);
        return leyo;
    }

    bool listarRegistros(){
        FILE *pAlu;
        Alumno reg;
        pAlu=fopen(nombre, "rb");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return false;
        }

        while(fread(&reg,tamanioRegistro,1,pAlu)==1){
            reg.Mostrar();
            cout<<endl;
        }

        fclose(pAlu);
        return true;
    }

    int buscarRegistro(int leg, bool comoEsta){
        FILE *pAlu;
        Alumno reg;
        int pos=0;
        pAlu=fopen(nombre, "rb");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return -2;
        }
        if(comoEsta==true){
            while(fread(&reg,tamanioRegistro,1,pAlu)==1){
                if(reg.getLegajo()==leg &&reg.getEstado()){
                    fclose(pAlu);
                    return pos;
                }
                pos++;
            }
        }
        else{
            while(fread(&reg,tamanioRegistro,1,pAlu)==1){
                if(reg.getLegajo()==leg){
                    fclose(pAlu);
                    return pos;
                }
                pos++;
            }
        }
        fclose(pAlu);
        return -1;
    }
    Alumno leerRegistro(int ubicacion){
        FILE *pAlu;
        Alumno reg;
        reg.setLegajo(-1);
        ///int pos=0;
        pAlu=fopen(nombre, "rb");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return reg;
        }
        int cuanto=ubicacion*tamanioRegistro;
        int desde_donde=0;
        fseek(pAlu,cuanto, desde_donde);
        fread(&reg, tamanioRegistro,1, pAlu);
        fclose(pAlu);
        return reg;
    }
    int contarRegistros(){
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
    bool modificarRegistro(Alumno reg, int pos){
        FILE *pAlu;
        pAlu=fopen(nombre, "rb+");
        if(pAlu==NULL){
            cout<<"NO SE PUDO ABRIR EL ARCHIVO "<<endl;
            return false;
        }
        fseek(pAlu,pos*tamanioRegistro, 0);///se ubica el puntero al principio del registro a modificar
        bool escribio=fwrite(&reg, tamanioRegistro,1,pAlu);
        fclose(pAlu);
        return escribio;
    }


};
int main(){
  
	system("pause");
	return 0;
}
