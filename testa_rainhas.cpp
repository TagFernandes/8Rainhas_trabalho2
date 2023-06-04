// Copyright (c) 2023, Thiago Fernandes

#include <iostream>
#include <string>

#define CATCH_CONFIG_MAIN
#include "rainhas.hpp"
#include "catch.hpp"

TEST_CASE("solucoes invalidas para o problema", "[rainhas]") {
    REQUIRE(verifica_solucao_8_rainhas("teste_8_rainhas.txt") == 0);
}
