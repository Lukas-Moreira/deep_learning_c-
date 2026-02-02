#include "../headers/myfunctions.hpp"

/**
 * @brief Funcao que calcula a funcao sigmoide
 * 
 * A funcao sigmoide eh definida como:
 *      1 / (1 + exp(-z))
 * 
 * A função é definida da seguite forma:
 * 
 * sigmoid(z) =
 *         1, se z >= 45
 *         0, se z <= -45
 *         e 1 / (1 + exp(-z)), caso contrario 
 * 
 * @param z valor de entrada
 * @return float
 */
float sigmoid(float z){
    float result;

    if(z >= 45.f){
        return result = 1.f;
    }
    else if(z <= -45.f){
        return result = 0.f;
    }
    else{
        return result = 1.f / (1.f + exp(-z));
    }
}

/**
 * @brief Funcao que encontra o valor medio de um vetor
 * 
 * A funcao encontra o valor medio de um vetor de inteiros.
 * 
 * Obs: Nesse caso a função ainda não foi otimizada pois ainda
 * faz a ordenação do vector.
 * 
 * @param arr conjuto de dados a serem analisados
 * @return int object que se encontra no meio do vetor
 */
int find_middle(vector & arr){
    const int N = arr.size();

    if (N == 0) 
        throw std::invalid_argument("cannot find middle of an empty vector");

    vector cp = arr;

    std::sort(cp.begin(), cp.end());

    return cp[N / 2];
}

/**
 * @brief Funcao que inicializa os pesos de uma rede neural
 * 
 * Xavier Glorot e Yoshua Bengio propuseram um metodo de inicializacao
 * dos pesos em redes neurais em seu artigo "Understanding the difficulty
 * of training deep feedforward neural networks" (2010).
 * 
 * A funcao abaixo implementa o metodo Xavier Normal Initialization, que eh
 * definido pela distribuicao normal:
 * 
 *  W ~ U(0, sqrt(2./(fan_in + fan_out)))
 * 
 * Onde:
 *     W = pesos
 *     fan_in = numero de neuronios de entradas
 *     fan_out = numero de neuronios de saidas
 * 
 * O que ela faz eh criar um vetor de tamanho fan_in * fan_out. Ela eh interessante
 * pois evita o problema do gradiente desaparecer ou explodir durante o treinamento.
 * Sua ideia principal eh fazer com que a variancia dos gradientes seja a mesma em todas
 * as camadas da rede neural. 
 * 
 * @param fan_in   Neuronios de entrada
 * @param fan_out  Neuronios de saida
 * @return weigths Vetor de pesos inicializados 
 */
std::vector<float> glorot_initializer (int fan_in, int fan_out){
    
    int tamanho = fan_in * fan_out;                               // Tamanho do vetor de pesos

    float desvio_padrao = sqrt(2. / (fan_in + fan_out));         // Desvio padrao da distribuicao uniforme

    unsigned semente = chrono::now().time_since_epoch().count();

    rand_t gerador(semente);

    uniform_dist distribuicao(.0, desvio_padrao);

    std::vector<float> resultado(tamanho);

    std::generate(resultado.begin(), resultado.end(),
                  [&gerador, &distribuicao]() { 
                    return distribuicao(gerador); 
                    }
                );

    return resultado;
}