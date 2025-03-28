#include <iostream>
using namespace std;

int* otraFuncion(){
   int j;
   pVec = new int[5]{1000, 2000, 3000, 4000, 5000};
   j = 5;
   
   return pVec;
}

int main() {
   int m;
   
   m = 5;
   int * pVec2 = otraFuncion();
   
   cout << pVec2[0] << endl;
   
   delete [] pVec2;
	
	return 0;
}

