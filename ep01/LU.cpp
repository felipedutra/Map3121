/***************************************************************/
/**                                                           **/
/**   Felipe Dutra Teixeira                        11806851   **/
/**   Exercicio-Programa 01                                   **/
/**   Professor: Clodoaldo Grotta Ragazzo                     **/
/**   Turma: (01)                                             **/
/**                                                           **/
/***************************************************************/
#include "LU.h"
#include <fstream>
#include <stdexcept>
using namespace std;

    LU::LU(int n, int sig_figs, string nomeDoArquivo, string nomeDoArquivoD) {
      this->n = n;
      this->sig_figs = sig_figs;
      this->nomeDoArquivo = nomeDoArquivo;
      this->nomeDoArquivoD = nomeDoArquivoD;
      this->a = new double[n];
      this->b = new double[n];
      this->c = new double[n];
      this->l = new double[n];
      this->v = new double[n];
      this->d = new double[n];
      this->x = new double[n];
        //ctor
        cout << " " << endl;
        for ( int i = 0; i < n; i++) {
        a[i] = 0;
        b[i] = 0;
        c[i] = 0;
        d[i] = 10;
        l[i] = 0;
        v[i] = 0;
        }
        if( sig_figs > 16) {
          this->sig_figs = 16;

        }

    }

    LU::~LU() {
        //dtor
    }
int  LU::productLU(){
// retorna a matriz A a partir de L e U
cout << "A matriz obtida do produto LU é:"<<endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      if (i == j){
        cout << 1*v[i] << " ";
      }else if (i == j - 1) {
        cout << 1*c[i] << " ";
      }else if (i == j + 1) {
        cout << l[i-1]*v[i-1] << " ";
      }else if (j > i + 1 || j < i - 1 ) {
        cout << "0 ";
      }
    }
    cout << " "<<endl;
  }
return 0;




}
int  LU::productAX(){
  // retorna a matriz A a partir de L e U
  cout << "A matriz obtida do produto AX é:"<<endl;
  d[0] = b[0]*x[0] +c[0]*x[1];
  cout <<d[0] <<endl;
  for (int i = 1; i < n-1; i++) {
    d[i] = a[i]*x[i-1] + b[i]*x[i]+ c[i]*x[i+1];
    cout << d[i] <<endl;
  }
  d[n-1] = a[n-1]*x[n-2] + b[n-1]*x[n-1];
  cout << d[n-1] <<endl;
return 0;




}
int  LU::readFile() {
  double x;
//  cout << "Opening file..." <<endl;
  ifstream input(nomeDoArquivo, ios::in);
  if (input.fail() ) {
      input.close();
      throw invalid_argument("Arquivo nao encontrado");
      return 0;
  }
  //LENDO O ARQUIVO DA MATRIZ A
  for(int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      if (i == j) {
        input >> b[i];
      }
      else if (i == j - 1) {
      input >> c[i];
      } else if ( i == 0 && j == n - 1){
          input >> a[0];
      } else if ( i == n - 1 && j == 0){
          input >> c[n - 1];
      } else if (i == j + 1 ) {
        input >> a[i];
      } else {
        input >> x;
    }
    }


  }

  input.close();

return 0;
}
int  LU::decompositrix() {
  int chose = 0;
  if (a[0] != 0 && c[n-1] != 0) {
    chose = 1;

  }
  if (chose == 0) {
    cout << "Decomposing..." <<endl;
    v[0] = b[0];
    for (int i = 0; i < n; i++) {
      l[i] = a[i+1]/v[i];
      v[i+1] = b[i+1] - l[i+1]*c[i];
  //    cout << "v " << v[i+1]<<endl;
  //    cout << "c " << c[i]<<endl;
  //    cout << "l " << l[i+1]<<endl;
    }
  }
  else if (chose == 1) {
    cout << "Ainda não produzi algoritmo" <<endl;
    return 1;
  }


  return 0;
}
void LU::printmatrix() {
      cout << " A matriz A é: " <<endl;
      for ( int i = 0; i < n; i++) {
        for ( int j = i - 1; j > 0; j--) { // Preenchendo de zeros antes da diagonal
          if ( i == n - 1 && j == i - 1){
              cout << c[n - 1] <<" ";
            }else {
              cout <<  "0 ";
            }
        }

        if (i != 0) {
          cout << a[i] <<  " ";
        }


        cout << b[i] <<  " ";
        if (i != n - 1) {
          cout << c[i] <<  " ";
        }
        for ( int j = i; j < n - 2; j++) {
          //cout <<  "0 ";
          if ( i == 0 && j == n - 3){
            cout << a[0];
          } else {
            cout <<  "0 ";
          }
        }
        cout << " " << endl;
      }
      cout << " A matriz L é: " <<endl;
      for ( int i = 0; i < n; i++) {
        for ( int j = i - 1; j > 0; j--) {
          cout <<  "0 ";

        }
        if (i != 0) {
          cout << l[i] <<  " ";
        }

        cout << 1 <<  " ";
        //if (i != n - 1) {
          //cout << c[i] <<  " ";
        //}
        for ( int j = i; j < n - 1; j++) {
          cout <<  "0 ";
        }
        cout << " " << endl;
      }
      cout << " A matriz U é: " <<endl;
      for ( int i = 0; i < n; i++) {
        for ( int j = i; j > 0; j--) {
          cout <<  "0 ";

        }
        cout << v[i] <<  " ";

        //cout << b[i] <<  " ";
        if (i != n - 1) {
          cout << c[i] <<  " ";
        }
        for ( int j = i; j < n - 2; j++) {
          cout <<  "0 ";
        }
        cout << " " << endl;
      }
      if (nomeDoArquivoD =="null") {
      return;
      }

        cout << " A matriz D é: " <<endl;
        for ( int i = 0; i < n; i++) {
          cout << d[i] << endl;

        }
        cout << " A matriz X é: " <<endl;
        for ( int i = 0; i < n; i++) {
          cout << setprecision(sig_figs) << fixed;
          cout << x[i] << endl;

        }


  }
int LU::readFileD() {
  //LENDO O ARQUIVO DA MATRIZ D
  //cout <<"LENDO O ARQUIVO DA MATRIZ D"<<endl;
  if (nomeDoArquivoD =="null" ) {
    return 0;
  }

     ifstream input(nomeDoArquivoD);
    if (input.fail() ) {
        input.close();
        throw invalid_argument("File not found");
        return 0;
      }

      for(int i = 0; i < n; i++) {

            input >> d[i];

          }





  input.close();
  return 1;
}
void LU::solveMatrix() {
  x[0] = d[0];

  for (int i = 1; i < n; i++) {
    x[i] = d[i] - l[i]*x[i-1];

  }
  x[n-1] = x[n-1]/v[n-1];
  for (int i = n - 2; i >= 0; i--) {
      x[i] = x[i]-c[i]*x[i+1];
      x[i] = x[i]/v[i];

  }


}
