///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

void cargarVector(int *v, int tam);
void mostrarVector(int *v, int tam);
int *pedirMemoria(int tam);

int main(){
    int *pInt, tam;
    cout<<"INGRESAR LA CANTIDAD DE ELEMENTOS DEL VECTOR ";
    cin>>tam;
    ///pInt=new int[tam];
    pInt=pedirMemoria(tam);
    if(pInt==nullptr){
        cout<<"ERROR DE MEMORIA"<<endl;
        return -1;
    }
	cargarVector(pInt,tam);
	mostrarVector(pInt, tam);
    delete []pInt;
    cout<<endl;
	system("pause");
	return 0;
}

void cargarVector(int *v, int tam){
    int indice;
    for(indice=0;indice<tam;indice++){
        cout<<"INGRESAR NUMERO ENTERO "<<endl;
        cin>>v[indice]; ///*(v+indice)
    }
}

void mostrarVector(int v[], int tam){
    int indice;
    for(indice=0;indice<tam;indice++){
        cout<<v[indice]<<"\t";
    }
}

int *pedirMemoria(int tam){
    int *pAux;
    pAux=new int[tam];
    return pAux;
}
