///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>
# include<cstring>


using namespace std;

const bool ACTIVOS=true;
const bool TODOS=false;


class Fecha{
    private:
        int dia, mes, anio;
    public:
         Fecha(int d=0, int m=0, int a=0);

         void Cargar();
         void Mostrar(void);
        ///setter
         void setDia(int dia){
             if(dia>=1 &&dia<=31)this->dia=dia;
             else this->dia=0;
             }
        void setMes(const int m){mes=m;}
        void setAnio(int a){anio=a;}
        ///getter
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};
 ///fin de la definici�n de la clase
///desarrollo de los m�todos
void Fecha::Cargar(){
            int d;
            cout<<"DIA ";
            cin>>d;
            setDia(d);
            cout<<"MES ";
            cin>>mes;
            cout<<"ANIO ";
            cin>>anio;
         }

void Fecha::Mostrar(){
             cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
         }

Fecha::Fecha(const int d,const int m,const int a){
            dia=d;
            mes=m;
            anio=a;
}
///fin de clase Fecha
///desarrollo de clase Alumno
class Alumno{
private:
    int legajo;
    char nombre[30];
    char apellido[30];
    Fecha fechaNacimiento;
    char email[50];
    int codigoCarrera;
    bool estado; ///propiedad que vamos a utilizar para definir si el registro est� o no activo (borrado)
public:
    int getLegajo(){return legajo;}
    void setLegajo(int l){legajo=l;}

    bool getEstado(){return estado;}
    void setEstado(bool e){estado=e;}

    int getCodigoCarrera(){return codigoCarrera;}

    void setFechaNacimiento(Fecha aux){
          fechaNacimiento=aux;
    }
    void Cargar(int leg=0);
    void Mostrar();
};
///M�todos de alumno
void Alumno::Cargar(int leg){
    if(leg==0){
        cout<<"LEGAJO ";
        cin>>legajo;
    }
    else legajo=leg;
    cout<<"NOMBRE ";
    cin>>nombre;
    cout<<"APELLIDO ";
    cin>>apellido;
    cout<<"FECHA DE NACIMIENTO ";
    fechaNacimiento.Cargar();
    cout<<"EMAIL ";
    cin>>email;
    cout<<"CARRERA ";
    cin>>codigoCarrera;
    estado=true;
}

void Alumno::Mostrar(){
    if(estado){
        cout<<"LEGAJO ";
        cout<<legajo<<endl;
        cout<<"NOMBRE ";
        cout<<nombre<<endl;
        cout<<"APELLIDO ";
        cout<<apellido<<endl;
        cout<<"FECHA DE NACIMIENTO "<<endl;
        fechaNacimiento.Mostrar();
        cout<<"EMAIL ";
        cout<<email<<endl;
        cout<<"CARRERA ";
        cout<<codigoCarrera<<endl;
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
        int leyo=fread(&reg,sizeof(Alumno),1,pAlumno);
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

    int ArchivoAlumnos::agregarRegistro(){
        Alumno obj;
        /// Que no se repita el legajo.
        int leg;
        cout<<"INGRESAR LEGAJO ";
        cin>>leg;
        int encontro=buscarRegistro(leg);
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
    
    int buscarRegistro(int leg, bool comoEsta=true){
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

bool altaRegistro();
bool bajaRegistro();
bool modificacionRegistro();
void listadoRegistros();

int main(){
    int opc;
    while(true){
        system("cls");
        cout<<"MENU ALUMNOS"<<endl;
        cout<<"1. ALTA REGISTRO"<<endl;
        cout<<"2. BAJA REGISTRO"<<endl;
        cout<<"3. MODIFICACION REGISTRO"<<endl;
        cout<<"4. LISTADO DE REGISTROS"<<endl;
        cout<<"0. FIN DEL PROGRAMA"<<endl;
        cout<<"*********************"<<endl;
        cout<<"SELECCIONAR OPCION "<<endl;
        cin>>opc;
        system("cls");
        switch(opc){
        case 1: if(altaRegistro()) cout<<"SE AGREGO EL REGISTRO"<<endl;
                else cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                break;
        case 2: if(bajaRegistro()) cout<<"EL REGISTRO FUE BORRADO "<<endl;
                else cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
                break;
        case 3: if(modificacionRegistro()) cout<<"REGISTRO MODIFICADO"<<endl;
                else cout<<"NO SE PUDO MODIFICAR EL REGISTRO "<<endl;
                break;
        case 4: listadoRegistros();
                break;
        case 0: return 0;
                break;
        default: cout<<"OPCION INCORRECTA";
                break;
        }
        system("pause");


    }


    cout<<endl;
    system("pause");
	return 0;
}

bool altaRegistro(){
    Alumno reg;
    ArchivoAlumnos archi;
    int legajo;
    cout<<"INGRESE EL LEGAJO DEL REGISTRO A AGREGAR ";
    cin>>legajo;
    int pos=archi.buscarRegistro(legajo,TODOS);
    if(pos!=-1){
        cout<<"EL LEGAJO YA EXISTE "<<endl;
        return false;
    }
    reg.Cargar(legajo);
    return archi.grabarRegistro(reg);
}

bool bajaRegistro(){
    Alumno reg;
    ArchivoAlumnos archi;
    int legajo;
    cout<<"INGRESAR LEGAJO A DAR DE BAJA ";
    cin>>legajo;
    int pos=archi.buscarRegistro(legajo, ACTIVOS);
    if(pos==-1) return false;
    ///leer el registro del archivo
    reg=archi.leerRegistro(pos);///en reg tengo el registro a borrar
    reg.setEstado(false);
    return archi.modificarRegistro(reg, pos);
}

bool modificacionRegistro(){
    Alumno reg;
    ArchivoAlumnos archi;
    int legajo;
    cout<<"INGRESAR LEGAJO PARA MODIFICAR LA FECHA DE NACIMIENTO ";
    cin>>legajo;
    int pos=archi.buscarRegistro(legajo,ACTIVOS);
    if(pos==-1) return false;
    ///leer el registro del archivo
    cout<<"INGRESAR LA NUEVA FECHA DE NACIMIENTO ";
    Fecha nueva;
    nueva.Cargar();
    reg=archi.leerRegistro(pos);///en reg tengo el registro a borrar
    reg.setFechaNacimiento(nueva);
    return archi.modificarRegistro(reg, pos);
}


void listadoRegistros(){
    ArchivoAlumnos archi;
    archi.listarRegistros();
}










































