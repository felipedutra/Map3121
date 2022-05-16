# MapEP
Para utilizar o programa em um mac ou linux, utilize os seguintes comandos:
- Mac:
clang++ *.cpp -Wall -ansi -O3 -std=c++11  -o a
./a
- Linux:
g++ *.cpp -Wall -ansi -O3 -o a
./a
Para compilar em um windows, utilize g++ ou docker com linux. Pois com codeblocks o código não possui os mesmos valores.

Após compilar e executar 'a' você terá que escolher a função.
Passo 1) Digite 1 para prosseguir ou 0 para terminar o programa.
Passo 2) Digite o número de linhas da matriz Anxn.
Passo 3) Digite o número algoritmos signicativos que você quer utilizar.
Passo 4) Digite o nome do arquivo que contém a matriz Anxn.(Somente a matriz Anxn pode estar nesse arquivo).
Passo 5) Digite 'y' para obter a matriz solução ou digite 'n' para somente decompor a matriz A em matrizes L e U.
Passo 6) Digite o nome do arquivo que contém a matriz D1xn

Após isso você receberá as matrizes L, U, X. Assim como uma cópia das matrizes A,D e as matrizes produto LU e AX, que deverão ser iguais as matrizes A e D, respectivamente.
