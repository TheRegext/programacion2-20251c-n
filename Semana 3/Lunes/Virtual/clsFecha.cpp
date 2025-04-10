///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;
/*
struct fecha{
    int dia, mes, anio;
    //char nombreMes[20];
};
*/

///
///Clase: molde donde se definen las propiedades y el comportamiento
/// que tendrán los objetos de esa clase. Tipo de dato que se agrega

///Objeto: variable de una clase. Instancia de una clase

///Encapsulamiento: mecanismo que brinda un acceso seguro a las propiedades
/// de los objetos.
class Fecha{
        ///propiedades: variables de la clase, cosas que es necesario
        ///registrar para identificar el objeto
    private:
        int dia, mes, anio;
    public:///comportamiento: los métodos que determinan
            ///que cosa puede hacer el objeto
            ///Funciones de la clase
        void Cargar(){
            cout<<"DIA ";
            cin>>dia;
            cout<<"MES ";
            cin>>mes;
            cout<<"ANIO ";
            cin>>anio;
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

};///FIN DE LA CLASE

void Fecha::Mostrar(){
            cout<<"DIA "<<dia<<endl;
            cout<<"MES "<<mes<<endl;
            cout<<"ANIO "<<anio<<endl;
        }


void cargarVector(Fecha *v,int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i].Cargar();
    }
}
void mostrarVector(Fecha *v,int tam){
int i;
    for(i=0;i<tam;i++){
        v[i].MostrarEnLinea();
    }

}
int main(){

    ///Cargar();///funciones globales no pertenecen a ninguna clase
    Fecha hoy, otra, v[3];
	/*int a, b, c;
	hoy.Cargar(); ///que sólo pueden ser llamadas por los objetos de la clase
	otra.Cargar();
	if(hoy.getMes()==otra.getMes()){
        cout<<"MESES IGUALES"<<endl;
	}
	else{
        cout<<"NO COINCIDEN LOS MESES"<<endl;
	} */
    cargarVector(v,3);
    mostrarVector(v,3);
	system("pause");
	return 0;
}
