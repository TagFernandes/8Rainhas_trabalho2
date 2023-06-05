/**
*@file rainhas.cpp
*/

// Copyright (c) 2023, Thiago Fernandes


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include "rainhas.hpp"

using std::cout; using std::cin;
using std::endl; using std::string;
using std::vector;

/**
* @brief Verifica tamanho da matriz inserida.
*
* Função verificaTamanho ira contar o numero de 0s e 1s no tabuleiro,
* caso haja mais ou menos de 64 pecas no tabuleiros, ela ira retornarm erro,
* bem como caso seja inserido um caractere diferente de "0" ou "1".
*
* @param filename nome do arquivo .txt que contem a matriz. 
* @return retorna 1 caso esteja tudo certo com a matiz,
*                 -1 caso seja um formato inválido
*                 -2 caso não seja possível abrir o arquivo.
*/
int verificaTamanho(const std::string& filename) {
    std::ifstream arquivo(filename);

    if (!arquivo) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return -2;
    }

    int contLetras = 0;
    int contNumeros = 0;
    char caractere;

    while (arquivo.get(caractere)) {
        if (isalpha(caractere)) {
            contLetras++;
        } else if (isdigit(caractere)) {
            contNumeros++;
        }
    }

    if (contNumeros != 64 && contLetras != 0) {
        cout << "numeros de caracteres: " << contNumeros << endl;
        return -1;
    }

    arquivo.close();

    return 1;
}

/**
* Checagem de possíveis ataques.
*
* Função check irá realizar a checagem de todos os possíveis ataques de uma
* rainha. percorrendo a matriz a procura de rainhas na mesma linha, coluna ou
* diagonais. 
*
* @param filename nome do arquivo .txt que contem o tabuleiro de xadrez. 
* @return retorna 1 caso a disposição das rainhas no tabuleiro satisfaça
*                  o problema;
*                 0 caso alguma rainha esteja em posição em que possa atacar
*                  outra. Neste caso, o programa irá criar um arquivo txt com o
*                  nome "ataque - 'nome do arquivo correspondente'", mostrando
*                  as posições em que ocorrem ataques de rainhas;
*                 -1 caso o tabuleiro do arquivo não seja uma matriz 8x8;
*                 -2 caso não seja possível abrir o arquivo.
*/
int check(const std::string& filename) {
    if (verificaTamanho(filename) == -1) { return -1;}
    if (verificaTamanho(filename) == -2) { return -2;}

    std::ifstream arquivo(filename);

    std::string linha1, linha2, linha3, linha4, linha5, linha6, linha7, linha8;
    std::string linhaExtra;

    if (std::getline(arquivo, linha1) &&
        std::getline(arquivo, linha2) &&
        std::getline(arquivo, linha3) &&
        std::getline(arquivo, linha4) &&
        std::getline(arquivo, linha5) &&
        std::getline(arquivo, linha6) &&
        std::getline(arquivo, linha7) &&
        std::getline(arquivo, linha8) &&
        !std::getline(arquivo, linhaExtra)) {
    } else {
        std::cout <<
        "O arquivo contém menos de 8 linhas ou possui mais do que 8 linhas." <<
        std::endl;
        return -1;
    }

    arquivo.close();

    int valueReturn = 1;
    int arrayLine1[8];  //  Array para armazenar os 8 primeiros números
    int arrayLine2[8];
    int arrayLine3[8];
    int arrayLine4[8];
    int arrayLine5[8];
    int arrayLine6[8];
    int arrayLine7[8];
    int arrayLine8[8];

    // Extrai os 8 primeiros caracteres da string e os converte para inteiros
    int countLine = 0;
    int countTotal = 0;
    int* arrays[] = {
       arrayLine1, arrayLine2, arrayLine3, arrayLine4,
       arrayLine5, arrayLine6, arrayLine7, arrayLine8};

    vector<string> linhas =
      { linha1, linha2, linha3, linha4, linha5, linha6, linha7, linha8};

    int attackSameLine[8] = {10, 10, 10, 10, 10, 10, 10, 10};

    std::string ataques = "";  //  Armazena ataques

    for (int i = 0; i < 8; i++) {
        //  colocando lista em array de inteiros
        countLine = 0;
        for (int y = 0; y < 8; y++) {attackSameLine[y] = 10;}

        for (int j = 0; j < 8; j++) {
            if (linhas[i][j] - '0' == 1 || linhas[i][j] - '0' == 0) {
                arrays[i][j] = linhas[i][j] - '0';
                if (arrays[i][j] == 1) {
                    countLine += 1;
                    countTotal += 1;
                }
            } else { return -1;}  //  caracter diferente de 1 e 0
        }

        //  verificação ataque mesma linha
        if (countLine >=  2) {
            for (int x = 0; x < 8; x++) {
                if (arrays[i][x] == 1) {
                    for (int a = 0; a < 8; a++) {
                        if (attackSameLine[a] == 10) {
                            attackSameLine[a] = x;
                            break;
                        }
                    }
                }
            }
            for (int b = 0; b < 7; b++) {
                if (attackSameLine[b] != 10 && attackSameLine[b+1] != 10) {
                    ataques += std::to_string(i + 1); ataques += ",";
                    ataques += std::to_string(attackSameLine[b] + 1);
                    ataques += "            ";
                    ataques += std::to_string(i + 1); ataques += ",";
                    ataques += std::to_string(attackSameLine[b+1] + 1);
                    ataques += "\n";
                    valueReturn = 0;
                }
            }
        }
    }

    if (countTotal > 8 || countTotal < 8) {  //  mais ou menos de 8 rainhas
        std::cout << "matriz invalida" << std::endl;
        return -1;
    }


    //  verificacao colunas
    bool shouldBreak = false;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (arrays[i][j] == 1) {
                shouldBreak =  false;
                for (int y = i; y < 8; y++) {
                    for (int x = j; x < 8; x++) {
                        if (arrays[y][x] == 1 && i != y && x == j) {
                            ataques += std::to_string(i + 1); ataques += ",";
                            ataques += std::to_string(j + 1);
                            ataques += "            ";
                            ataques += std::to_string(y + 1); ataques += ",";
                            ataques += std::to_string(x + 1); ataques += "\n";

                            valueReturn = 0;
                            shouldBreak = true;
                            break;
                        }
                    }
                    if (shouldBreak) {break;}
                }
            }
        }
    }

    //  verificacao diagonais direita
    int cont = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (arrays[i][j] == 1) {
                cont = 1;
                for (int y = i + 1; y < 8; y++) {
                    if (j+cont >= 8) {
                        break;
                    }
                    if (arrays[y][j+cont] == 1) {
                        ataques += std::to_string(i + 1); ataques += ",";
                        ataques += std::to_string(j + 1);
                        ataques += "            ";
                        ataques += std::to_string(y + 1); ataques += ",";
                        ataques += std::to_string(j+cont + 1); ataques += "\n";
                        valueReturn = 0;
                        break;
                    }
                    cont += 1;
                }
            }
        }
    }

    //  verificacao diagonais esquerda
    cont = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (arrays[i][j] == 1) {
                cont = 1;
                for (int y = i + 1; y < 8; y++) {
                    if (j-cont < 0) {
                        break;
                    }
                    if (arrays[y][j-cont] == 1) {
                        ataques += std::to_string(i + 1); ataques += ",";
                        ataques += std::to_string(j + 1);
                        ataques += "            ";
                        ataques += std::to_string(y + 1); ataques += ",";
                        ataques += std::to_string(j-cont + 1); ataques += "\n";
                        valueReturn = 0;
                        break;
                    }
                    cont += 1;
                }
            }
        }
    }
    if (valueReturn == 0) {
        std::string nome = "ataques/ataques - ";
        nome += filename;
        std::ofstream arquivo(nome);

        if (arquivo.is_open()) {  // Verifica se o arquivo foi aberto
            arquivo << ataques;  // Escreve a mensagem no arquivo
            arquivo.close();  // Fecha o arquivo
        } else {
            std::cout << "Erro ao abrir o arquivo." << std::endl;
        }
    }
    return valueReturn;
}
/**
* Verifica o arquivo.
*
* Função verifica_solucao_8_rainhas é a função chamada pelo testa_rainhas.cpp
* que por sua vez chama as função de checagem na ordem certa para retornar a
* solução para o problema das 8 rainhas.
* @param filename nome do arquivo .txt que contem o tabuleiro de xadrez. 
* @return retorna 1 caso a disposição das rainhas no tabuleiro satisfaça
*                  o problema;
*                 0 caso alguma rainha esteja em posição em que possa atacar
*                  outra. Neste caso, o programa irá criar um arquivo txt com o
*                  nome "ataque - 'nome do arquivo correspondente'", mostrando
*                  as posições em que ocorrem ataques de rainhas;
*                 -1 caso o tabuleiro do arquivo não seja uma matriz 8x8;
*                 -2 caso não seja possível abrir o arquivo.
*/
int verifica_solucao_8_rainhas(const std::string& filename) {
    int valor = check(filename);

    if (valor == -1) {
        return -1;  //  matriz Inválida
    }
    if (valor == -2) {
        cout << "Erro ao abrir arquivo" << endl;
    }
    if (valor == 0) {  //  Problema que nao e solução
        return 0;
    }
    if (valor == 1) {  //  problema que satisfaz as 8 rainhas
        return 1;
    }

    return -1;
}
