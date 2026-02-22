# Deep Learning in C++

Este repositório é uma **biblioteca de estudos, experimentos e implementações práticas** baseadas no livro **_Deep Learning in C++_**, com foco em **entendimento conceitual**, **implementação matemática** e **validação estatística** dos principais tópicos de Deep Learning.

O objetivo **não é criar um framework**, mas sim **aprender profundamente** como redes neurais funcionam “por dentro”, implementando tudo do zero em **C++**.

---

## Objetivos do Repositório

- Estudar Deep Learning a partir de implementações em **C++**, sem o uso de frameworks de alto nível  
- Relacionar diretamente os conceitos teóricos do livro com **código executável e testável**  
- Explorar a **natureza estocástica** de modelos de Deep Learning por meio de testes estatísticos  
- Validar matematicamente inicializações, funções de ativação e gradientes  
- Consolidar o aprendizado através de **experimentos, exercícios e testes**

---

## 📖 Referências

<details>

<summary><strong>Machine Learning with C++ by C. Ebukson, Hilario</strong></summary>

- **Livro:** *Machine Learning with C++: Practical implementation of AI and ML Algorithms in C++*
- **Autor:**
    -  C. Ebukson, Hilario
- **Link para compra:** [Amazon](https://www.amazon.com.br/Machine-Learning-Practical-Implementation-Algorithms/dp/B0G2JDGPZJ)

</details>

<details>

<summary><strong>Deep Learning in Modern C++ by Carlos d'Oleron, Luiz</strong></summary>

- **Livro:** *Deep Learning in Modern C++: End-to-end development and implementation of deep learning algorithms*
- **Autor:**
  - Carlos d'Oleron, Luiz
- **Editora:** BPB Publications India
- **Link para compra:** [Amazon](https://www.amazon.com.br/Deep-Learning-Modern-End-end/dp/9365893518/ref=sr_1_1?adgrpid=1143493892111494&dib=eyJ2IjoiMSJ9.xqRnjEpKsnFB1od33e0KDFVlDh-gKKzedXsgluHSzydKg-ZpMqvH50Bcw7hHGesTNqL9OMvgQqlEI1fCS781TLviwL1qRZe9y33rxIIeqsojgFYhLCWTjPy8SkTuUXR66T3ywapuiET9q29VIHAwOFqK9IdVFT62MnZ9gNtAQcOVTFqo5IE623OV0Y07qiYLijkDUHWZGDlFT7eEUq7PdjwB7KtX0wwk-jBIMJUmj73FmpwiR4wyrce9A_JcFp34hHaLq4aSOcIpggmfW1YOhr0hZQqH6ZgytLxQDOdYcAo.vm4aqKZ630_XD-9OtQJj0yju0wJoJCkU82ksr2LPyN0&dib_tag=se&hvadid=71468534015869&hvbmt=be&hvdev=c&hvlocphy=293406&hvnetw=o&hvqmt=e&hvtargid=kwd-71469095914600%3Aloc-20&hydadcr=29374_14611257&keywords=deep+learning+in+c%2B%2B&mcid=3f477eb4b6e8337eb80c31516dcbcbed&msclkid=fef5304f422d144575f759cfaf9e1819&qid=1770057149&sr=8-1&ufe=app_do%3Aamzn1.fos.fcd6d665-32ba-4479-9f21-b774e276a678)

</details>
---

## Conteúdos Abordados

- Algoritmos de testes em deep learning
- Convoluções 2D, detecção de bordas e Tensores
- Redes totalmente conectadas (Fully Connected Networks)
- Funções de custo
- Funções de ativação:
  - Sigmoid
  - Tanh
  - ReLU
  - Softmax
  - Cálculo de gradiente com regra da cadeia
- Utilização de Pooling layers
- Gradiente descendente e otimização
- Backpropagation
- Underfitting, Overfitting and Regularization
- Implementando otimizadores 

---

## Estrutura do Repositório

```text

📁 chapter3                     # Testing Deep Learning Code
├── 📁 headers/
│   ├── ⚡myfunctions.hpp        # Funções auxiliares usadas nos experimentos do capítulo
│   └── ⚡chi_squared_test.hpp   # Teste de hipótese (Qui-Quadrado)
├── src/
│   ├── ⚡myfunctions.cpp        # Implementação das funções auxiliares
│   └── ⚡chi_squared_test.cpp   # Teste estatístico ligado à natureza estocástica dos modelos
├── tests/
│   └── ⚡test_sorting.cpp       # Exemplo de testes com GoogleTest
├── 📁 exercises/                # Exercícios do capítulo
│   └── 📁 benchmark
│        │    └── ⚡ middle.cpp
│        ├── 📁 headers
│        │    ├── ⚡ activation_functions.hpp
│        │    └── ⚡ utils.hpp
│        ├── 📁 src
│        │    ├── ⚡ activation_funtions.cpp
│        │    └── ⚡ utils.cpp
│        └── 📁 tests
│             ├── ⚡ act_func.cpp
│             └── ⚡ middle.cpp
│
📁 chapter4                     # Convolutions
├── 📁 Convolutions/
     └── 📁 theory
         └── 📁 conv2d
              ├── 📁 benchmarks
              │   └── ⚡ convolutions.cpp    # Benchmarks de testes de implementação
              ├── conv2D.cpp                # Exemplo de utilização
              ├── conv2D.hpp                # Construtores das funções
              └── CMakeLists.txt            # Compiler
```

## Tecnologias Utilizadas

- Linguagem: C++17+

- Bibliotecas:
    - Eigen (álgebra linear)
    - Boost.Math (distribuições estatísticas)
    - Build: CMake
    - Versionamento: Git + Git Flow

## 📌 Status do Repositório

- 🔄 Em desenvolvimento contínuo
- 📖 Evolui junto com a leitura do livro e estudos teóricos

## Autor

<details>

<summary><strong>Sobre o Autor</strong></summary>

- **Lukas L. Moreira**
- **Engenheiro Eletricista de Telecomunicações • Deep Learning • Sistemas Embarcados**
- LinkedIn: [Lukas Moreira](www.linkedin.com/in/lukas-moreira-dev)

</details>

---