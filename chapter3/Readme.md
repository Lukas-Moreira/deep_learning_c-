# Capítulo 3 — Testando Códigos de Deep Learning

O livro Deep Learning in C++ aborda os fundamentos do deep learning, incluindo a construção e treinamento de redes neurais. O Capítulo 3 foca em testar códigos de deep learning, aqui o foco do autor é fornercer um pensamento crítico sobre a pespectiva do funcionamento dos módulos que compõem uma rede neural.

## Pontos abordados
- Introdução ao Google Test Framework para testes unitários em C++.
- Entendendo a natureza estocástica de uma rede neural e como isso afeta o desempenho em caso de má implementação.
- Estratégia de testes baseado em hipótese de testes:
    - Teste de hypotese nula.
    - Teste de hipótese alternativa.
- Teste de Qui-quadrado para avaliar a distribuição dos pesos.
- Implementação da função de inicialização Glorot e sua importância.
- Implementação de funções de ativação (ReLU, Sigmoid, Tanh) e seus respectivos testes.

## Sinergia dos objetos estudados

Cada componente estudado tem por trás de si uma série de interações que impactam no diretamente no desempenho de uma rede neural. Sendo assim, o autor começa o capítulo com a seguinte reflexão: 

```latex
"[...] em geral, quando implementamos um novo algoritimo, é muito difícil determinar se uma perfomance ruim é devido a uma ineficiência do algoritimo ou a um erro de implementação. [...]". 

```

Dessa forma, o que o autor propõe é uma visão de entender a natureza de cada componente e como visar como suas excessões podem impactar negativamente o desemepenho, por exemplo: 
    - **Má implementação de funções de ativação:** pode ocasionar valores incorretos.
    - **Má distribuição dos pesos de inicialização:** pode levar a Vanishing/Exploding Gradients ou inviesar o aprendizado.
---