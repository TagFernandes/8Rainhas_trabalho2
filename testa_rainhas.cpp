// Copyright (c) 2023, Thiago Fernandes

#define CATCH_CONFIG_MAIN
#include "rainhas.hpp"
#include "catch.hpp"

TEST_CASE("solucoes invalidas para o problema", "[rainhas]") {
    REQUIRE(verifica_solucao_8_rainhas("teste_8_rainhas.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_Beta3.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_Beta4.txt") == 0);
    REQUIRE(verifica_solucao_8_rainhas("teste_Beta5.txt") == 0);
}

TEST_CASE("solucoes validas para o problema", "[rainhas]") {
    REQUIRE(verifica_solucao_8_rainhas("teste_Beta1.txt") == 1);
}

TEST_CASE("matriz invalida para o problema", "[rainhas]") {
    REQUIRE(verifica_solucao_8_rainhas("teste_Beta2.txt") == -1);
}
