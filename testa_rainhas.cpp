/**
*@file testa_rainhas.cpp
*/

// Copyright (c) 2023, Thiago Fernandes

#define CATCH_CONFIG_MAIN
#include "rainhas.hpp"
#include "catch.hpp"

/**
* TEST_CASE - casos sem solução
*
*
* @param filename nome do arquivo .txt que contem o tabuleiro de xadrez. 
* @return retorna 0 caso alguma rainha esteja em posição em que possa atacar
*                  outra. Neste caso, o programa irá criar um arquivo txt com o
*                  nome "ataque - 'nome do arquivo correspondente'", mostrando
*                  as posições em que ocorrem ataques de rainhas.
*                 -2 caso não seja possível abrir o arquivo.                 
*/
TEST_CASE("solucoes invalidas para o problema", "[rainhas]") {
    REQUIRE(verifica_solucao_8_rainhas("teste_8_rainhas.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_13.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_14.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_15.txt") == 0);

    REQUIRE(verifica_solucao_8_rainhas("teste_1.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_2.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_3.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_4.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_5.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_6.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_7.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_8.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_9.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_10.txt") == 0);
}

/**
* TEST_CASE - casos com solução
* 
* @param filename nome do arquivo .txt que contem o tabuleiro de xadrez. 
* @return retorna 1 caso a disposição das rainhas no tabuleiro satisfaça
*                  o problema;
*                 -2 caso não seja possível abrir o arquivo.
*/
TEST_CASE("solucoes validas para o problema", "[rainhas]") {
    REQUIRE(verifica_solucao_8_rainhas("teste_11.txt") == 1);
}

/**
* TEST_CASE - casos com solução
* 
* @param filename nome do arquivo .txt que contem o tabuleiro de xadrez. 
* @return retorna -1 caso a matriz não seja 8x8 ou possua caracteres
*                    diferentes de "0" ou "1";
*                 -2 caso não seja possível abrir o arquivo.
*/
TEST_CASE("matriz invalida para o problema", "[rainhas]") {
    REQUIRE(verifica_solucao_8_rainhas("teste_12.txt") == -1);
    REQUIRE(verifica_solucao_8_rainhas("teste_16.txt") == -1);

    REQUIRE(verifica_solucao_8_rainhas("teste_17.txt") == -1);
    REQUIRE(verifica_solucao_8_rainhas("teste_18.txt") == -1);
}
