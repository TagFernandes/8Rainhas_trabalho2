#ifndef RAINHAS_HPP_
#define RAINHAS_HPP_

// Copyright (c) 2023, Thiago Fernandes

#include <string>

/**
* Verifica o arquivo.
*
* Função verifica_solucao_8_rainhas é a função chamada pelo testa_rainhas.cpp,
* localizada no programa rainhas.cpp
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
int verifica_solucao_8_rainhas(const std::string& filename);

#endif  // RAINHAS_HPP_
