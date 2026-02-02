#include <vector>
#include <gtest/gtest.h>
#include "../headers/myfunctions.hpp"

using vector = std::vector<int>;

TEST(SigmoidTest, BaseCases){
    float actual_value = sigmoid(-10);
    float expected_value = 0;

    EXPECT_NEAR(actual_value, expected_value, 1e-7f) << "Teste do limite inferior da função sigmoid falhou";

    EXPECT_NEAR(sigmoid(100.), 1., 1e-7f) << "Teste do limite superior da função sigmoid falhou";

    EXPECT_NEAR(sigmoid(0.), .5, 1e-7f) << "Teste do ponto central da função sigmoid falhou";
}

TEST(OddCase, BaseCases){

    vector vec1 = {9, 4, 1, 11, 20, -1, 2};

    EXPECT_EQ(4, find_middle(vec1));
}

TEST(EvenCase, BaseCases){

    vector vec2 = {9, 4, 11, 20, -1, 2};

    EXPECT_EQ(4, find_middle(vec2));
}

TEST(CheckEmptyVector, BaseCases){

    vector vec1;

    EXPECT_THROW(find_middle(vec1), std::invalid_argument);
}

TEST(CheckGlorot, StatCases){
    int fan_in = 6;
    int fan_out = 5;

    auto pesos = glorot_initializer(fan_in, fan_out);

    const int N = pesos.size();

    EXPECT_EQ(N, fan_in * fan_out) << "Teste do tamanho do inicializador Glorot falhou";

    float soma = std::accumulate(pesos.begin(), pesos.end(), 0.0);

    float media = soma / N;

    float tol = 0.0;

    auto variancia =  [&tol, &media](const float val){
        const float diif = val - media;
        tol += diif * diif;
    };

    std::for_each(pesos.begin(), pesos.end(), variancia);

    float desvio_atual = sqrt(tol / (N-1));

    float desvio_esperado = sqrt(2. / (fan_in + fan_out));

    bool desvio_rejeitado = chi_squared_test(desvio_esperado, desvio_atual, N, 0.05);

    if (desvio_rejeitado){
        FAIL() << "Os pesos gerados pelo inicializador Glorot não seguem a distribuição esperada";
    }

    bool media_rejeitada = t_test(0., media, desvio_atual, N, 0.05);

    if (media_rejeitada){
        FAIL() << "A média dos pesos gerados pelo inicializador Glorot difere significativamente de zero";
    }
}