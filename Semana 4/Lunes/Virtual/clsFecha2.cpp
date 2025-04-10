///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

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
            cin>>(*this).dia;  ///puntero->dia
            cout<<"MES ";
            cin>>this->mes;
            cout<<"ANIO ";
            cin>>this->anio;
        }
        void Mostrar();
        void MostrarDireccion(){
            cout<<this<<endl;
            ///this es un puntero que contiene la dirección del objeto que llamó al método
        }
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


int main(){

    Fecha obj, hoy;
    obj.Mostrar();
    cout<<&obj<<endl;///dirección de obj
    obj.MostrarDireccion();
    cout<<endl;
    cout<<&hoy<<endl;///dirección de obj
    hoy.MostrarDireccion();
	system("pause");
	return 0;
}
