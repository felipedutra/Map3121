/***************************************************************/
/**                                                           **/
/**   Felipe Dutra Teixeira                        11806851   **/
/**   Exercicio-Programa 01                                   **/
/**   Professor: Clodoaldo Grotta Ragazzo                     **/
/**   Turma: (01)                                             **/
/**                                                           **/
/***************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "LU.h"
using namespace std;
int main () {
  int n,sig;
  string name, nameD;
  int answer = 1;
  cout << "Hello, welcome to the LU tridiagonal decomposer, and solver program " << endl;
  cout << "Copyright by: Felipe Dutra, 11806851, eletrical engineering student at Polytechnic of São Paulo" << endl;
  while ( answer != 0) {
    cout << "What do you want to do?" << endl;
    cout << "1. Decompose A tridiagonal matrix into LU." << endl;
    cout << "2. To be continued...   " <<endl;
    cout << "0. To finish the application" <<endl;
    cin >> answer;
    if (answer == 1) {

      cout << "What's the size of the matrix Anxn?" <<endl;
      cin >> n;
      cout << "How many signicant figures do you wish to use?" <<endl;
      cin >> sig;
      cout << "What's the name of the file that contains the matrix Anxn?" <<endl;
      cin >> name;
      cout << "Do you want a solution for a linear system? (y/n)"<< endl;
      cin >> nameD;
      if (nameD == "y") {
        cout << "What's the name of the file that contains the matrix Dnx1 ?" <<endl;
        cin >> nameD;
      } else {
        nameD = "null";
      }

    //name = "matriz4.txt";
    //n = 4;
    //nameD = "matrizD.txt";
    LU *lu1 = new LU(n,sig,name,nameD);
    lu1->readFile();
    lu1->readFileD();
    lu1->decompositrix();
    lu1->solveMatrix();
    lu1->printmatrix();
    lu1->productLU();
    lu1->productAX();
  }
  cout << "\n " << endl;
  }

  return 0;
}

//g++ *.cpp -Wall -ansi -O3 -std=c++11  -o a ; .a
//clang++ *.cpp -Wall -ansi -O3 -std=c++11  -o a ; ./a
