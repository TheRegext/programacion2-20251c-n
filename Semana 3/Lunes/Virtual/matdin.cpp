///Ejercicio:
///Autor:DEK
///Fecha:
///Comentario:

# include<iostream>


using namespace std;

void cargarLibros(char (*matLibro)[100], int tam);
void mostrarLibros(char (*matLibro)[100], int tam);


int main(){
    char (*palabras)[100];
    int tam;
    cout<<"INGRESAR LA CANTIDAD DE LIBROS A CARGAR ";
    cin>>tam;
    palabras=new char[tam][100];

    if(palabras==nullptr){
        cout<<"ERROR DE MEMORIA"<<endl;
        return -1;
    }


	cargarLibros(palabras,tam);
	mostrarLibros(palabras, tam);
    delete []palabras;
    cout<<endl;
	system("pause");
	return 0;
}

void cargarLibros(char (*matLibro)[100], int tam){
    int i;
    for(i=0;i<tam;i++){
        cin>>matLibro[i];
    }

}
void mostrarLibros(char (*matLibro)[100], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<matLibro[i]<<endl;
    }

}
