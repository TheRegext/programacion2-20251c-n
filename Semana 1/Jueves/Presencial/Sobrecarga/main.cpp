#include <iostream>
using namespace std;

int sumar (int num1, int num2, int num3);
float sumar (float num1, float num2);
int sumar (int vec[5]);
int sumar (int num1 = 100, int num2 = 200);


int main()
{
    int a = 10, b = 20, c = 30;

    float x = 1.1, y = 2.2;

    int vec[5] = {1, 2, 3, 4, 5};


    cout << sumar(a, b, c) << endl;  // 60
    cout << sumar(a, b) << endl;  // 30
    cout << sumar(a) << endl;  // 210
    cout << sumar() << endl;  // 300
    cout << sumar(x, y) << endl; // 3.333
    cout << sumar(vec) << endl; // 15



    return 0;
}

int sumar(int num1, int num2, int num3){
    return num1 + num2 + num3;
}
int sumar (int num1, int num2){
    return num1 + num2;
}
float sumar(float num1, float num2){
    return num1 + num2;
}
int sumar(int vec[5]){
    int suma = 0, i;
    for(i=0; i<5; i++){
        suma += vec[i];
    }
    return suma;
}

