#include "../headers/utils.hpp"

void out_vector(const vector_middle& vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Sort vector
 * 
 * Embora eu tenha tentado melhorar a performance do algoritmo de ordenação,
 * acabei optando por um bubble sort simples para manter o código didático e
 * fácil de entender. Porém, acabei deixando o código mais lento.
 * 
 * @param vec 
 * @return vector_middle 
 */
vector_middle sort_vector(vector_middle& vec) {
    for (size_t i = 0; i < vec.size(); i++)
        for (size_t j = i + 1; j < vec.size(); j++)
            if (vec[j] < vec[i])
            {
                float temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }

    return vec;
}

/**
 * @brief Find middle index of vector
 * 
 * Calcula a mediana de um vetor de floats.
 * 
 * 
 * 
 * Tentei usar o bubble sort para ordenar o vetor, mas deixei o código mais lento.
 * 
 * @param vec 
 * @return float 
 */
float find_middle_index(const vector_middle& vec) {
    
    const size_t N = vec.size();

    if (N ==0)
        throw invalid_argument("Vector is empty");

    vector_middle cp = vec; 

    // std::sort(cp.begin(), cp.end());
    // cp = sort_vector(cp); 

#ifdef DEBUG
    std::cout << "Vector before nth_element: " << std::endl; // demora mais tempo para ordenar
    out_vector(cp);
#endif

    std::nth_element(cp.begin(), cp.begin() + cp.size()/2, cp.end());

#ifdef DEBUG
    std::cout << "Vector after nth_element: " << std::endl;
    out_vector(cp);
#endif

    float result = cp[N / 2];

    if (N % 2 == 0) {
        result = (result + cp[(N / 2) - 1]) / 2;
    }

    return result;
}

