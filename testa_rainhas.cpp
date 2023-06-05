// Copyright (c) 2023, Thiago Fernandes

#define CATCH_CONFIG_MAIN
#include "rainhas.hpp"
#include "catch.hpp"

TEST_CASE("solucoes invalidas para o problema", "[rainhas]") {
    REQUIRE(verifica_solucao_8_rainhas("teste_8_rainhas.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_3.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_4.txt") == 0);
}

TEST_CASE("solucoes validas para o problema", "[rainhas]") {
    REQUIRE(verifica_solucao_8_rainhas("teste_1.txt") == 1);
}

TEST_CASE("matriz invalida para o problema", "[rainhas]") {
    REQUIRE(verifica_solucao_8_rainhas("teste_2.txt") == -1);
}
