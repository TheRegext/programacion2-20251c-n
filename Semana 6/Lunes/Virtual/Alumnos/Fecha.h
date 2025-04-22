#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

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

#endif // FECHA_H_INCLUDED
