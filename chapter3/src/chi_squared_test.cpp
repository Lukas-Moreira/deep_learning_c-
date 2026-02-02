#include "../headers/chi_squared_test.hpp"

/**
 * @brief Funcao que executa um teste qui-quadrado para determinar se o desvio padrao da amostra
 * é igual ao desvio padrao da populacao.
 * 
 * @param population_std Desvio padrao esperado 
 * @param sample_std     Desvio padrao da amostra
 * @param sample_size    Tamanho da amostra
 * @param confidence     Limiar de erro (0.05 = 5%)
 * @return true          Se a hipotese nula for rejeitada
 * @return false         Se a hipotese nula nao for rejeitada
 */
bool chi_squared_test(
    float population_std,
    float sample_std,
    int sample_size,
    float confidence){

        float variance_rate = sample_std / population_std;
        variance_rate = variance_rate * variance_rate;

        float t_stat = (sample_size - 1) * variance_rate;

        chi_squared distro(sample_size - 1);

        float upper_limit = quantile(complement(distro, confidence / 2));
        float lower_limit = quantile(distro, confidence / 2);

        return t_stat > upper_limit && t_stat < lower_limit;
}

/**
 * @brief Funcao que executa um teste de para determinar se a media da amostra eh igual 
 * a media da populacao.
 * 
 * A hipotese nula afirma que a media da amostra e igual a media da populacao.
 *      - A funcao deve retornar verdadeiro se a hipotese nula for rejeitada. 
 * 
 * @param population_mean Media da populacao
 * @param sample_mean     Media da amostra
 * @param sample_std_dev  Desvio padrao da amostra
 * @param sample_size     Tamanho da amostra
 * @param confidence      Nivel de confianca (0.95 = 95%)
 * @return (True)         Verdadeiro se a hipotese nula for rejeitada;
 * @return (False)        Falso se a hipotese nula nao for rejeitada;
 */
bool t_test(
    float population_mean,
    float sample_mean,
    float sample_std_dev,
    int sample_size,
    float confidence
){
    float diff = sample_mean - population_mean;                         // Tira a diferenca entre media da amostra e media da populacao

    float t_stat = diff * sqrt(double(sample_size)) / sample_std_dev;   // Calcula o produto entre a diferenca e a raiz quadrada do tamanho da amostra, dividido pelo desvio padrao da amostra

    unsigned degrees_freedom = sample_size - 1;                         // Calcula os graus de liberdade

    students_t distro(degrees_freedom);                                 // Cria a distribuicao t de Student com os graus de liberdade

    float q = cdf(complement(distro, fabs(t_stat)));                    // Calcula a funcao de distribuicao acumulada complementar para o valor absoluto do t_stat

    float confidence_2 = confidence / 2;                                // Divide o nivel de confianca por 2 para considerar ambos os lados da distribuicao
 
   return q < confidence_2;                                             // Retorna verdadeiro se o valor calculado for menor que o nivel de confianca dividido por 2
}