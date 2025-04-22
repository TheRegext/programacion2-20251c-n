#ifndef FUNGLOBALES_H_INCLUDED
#define FUNGLOBALES_H_INCLUDED

bool altaAlumnos();
bool bajaLogica();
bool modificacionCarrera();
void verFtell();
int contarRegistrosActivos();
///fin de los prototipos

bool altaAlumnos(){
    Alumno reg;
    ArchivoAlumnos archiAlumnos("alumnos.dat");
    int leg;
    cout<<"INGRESAR LEGAJO ";
    cin>>leg;
    int encontro=archiAlumnos.buscarAlumno(leg);
    if(encontro>=0){
        cout<<"EL LEGAJO YA EXISTE "<<endl;
        return false;
    }
    reg.Cargar(leg);
    if(archiAlumnos.agregarRegistro(reg)==1) return true;
    return false;
}

bool bajaLogica(){
    Alumno reg;
    ArchivoAlumnos archiAlumnos("alumnos.dat");
    int leg;
    cout<<"INGRESAR LEGAJO ";
    cin>>leg;
    int encontro=archiAlumnos.buscarAlumno(leg);
    if(encontro<0){
        cout<<"EL LEGAJO NO EXISTE "<<endl;
        return false;
    }
    reg=archiAlumnos.leerRegistro(encontro);
    reg.setEstado(false);
    if(archiAlumnos.modificarRegistro(reg,encontro)==1) return true;
    return false;
}

bool modificacionCarrera(){
    Alumno reg;
    ArchivoAlumnos archiAlumnos("alumnos.dat");
    int leg, codigoCarrera;
    cout<<"INGRESAR LEGAJO ";
    cin>>leg;
    int encontro=archiAlumnos.buscarAlumno(leg);
    if(encontro<0){
        cout<<"EL LEGAJO NO EXISTE "<<endl;
        return false;
    }
    reg=archiAlumnos.leerRegistro(encontro);
    cout<<"INGRESAR CODIGO DE CARRERA NUEVO ";
    cin>>codigoCarrera;
    ///se tendrían que ver validaciones, aunque el set ya podría resolver eso
    reg.setCodigoCarrera(codigoCarrera);
    if(archiAlumnos.modificarRegistro(reg,encontro)==1) return true;
    return false;


}
void verFtell(){
        FILE *p;
        p=fopen("alumnos.dat", "rb");
        if(p==NULL)return;
        int tam=ftell(p);
        cout<<"VALOR DE ftell() AL ABRIR EL ARCHIVO EN MODO rb "<<tam<<endl<<endl;

        fseek(p, sizeof(Alumno),0);
        tam=ftell(p);
        cout<<"VALOR DE ftell() AL UBICAR EL PUNTERO EN EL FIN DEL PRIMER REGSITRO DEL ARCHIVO EN MODO rb "<<tam<<endl;

        fseek(p,0,2);
        tam=ftell(p);
        cout<<"VALOR DE ftell() AL UBICAR EL PUNTERO AL FINAL DEL ARCHIVO EN MODO rb "<<tam<<endl;

}

int contarRegistrosActivos(){
    ArchivoAlumnos archi;
    Alumno reg;
    int cantReg;
    cantReg=archi.contarRegistros();
    int i, activos=0;
    for(i=0;i<cantReg;i++){
            reg=archi.leerRegistro(i);
            if(reg.getEstado()==true) activos++;
    }
    return activos;
}

#endif // FUNGLOBALES_H_INCLUDED
