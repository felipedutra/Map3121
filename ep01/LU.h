/***************************************************************/
/**                                                           **/
/**   Felipe Dutra Teixeira                        11806851   **/
/**   Exercicio-Programa 01                                   **/
/**   Professor: Clodoaldo Grotta Ragazzo                     **/
/**   Turma: (01)                                             **/
/**                                                           **/
/***************************************************************/
#ifndef LU_H
#define LU_H
#include <string>
#include <iostream>

using namespace std;
    class LU {
        public:
          LU(int n, int sig_figs, string nomeDoArquivo, string nomeDoArquivoD);
          virtual ~LU();
          int decompositrix();
          void printmatrix();
          void solveMatrix();
          int readFile();
          int readFileD();
          int productLU();
          int productAX();
          private:
          int sig_figs;
          int n;
          string nomeDoArquivo;
          string nomeDoArquivoD;
          double * a;
          double * d;
          double * b;
          double * c;
          double * l;
          double * v;
          double * x;

    };

    #endif // LU_H
