#include <iostream>
using namespace std;

int main() {
   int vec[5]{};
   int *pVec = nullptr;
   
   pVec = new int[1000000];
   
   if(pVec == nullptr){
      cout << "No pudo solicitar memoria :(" << endl;
      /// exit(500); /// cierra el prograba y fuerza el return del main con el 500
      return -1;
   }
   
   
   cout << "Esto funciona!" << endl;
   
   delete [] pVec;
	
	return 0;
}

