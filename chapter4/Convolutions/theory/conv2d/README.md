# conv2d

Implementação de **convolução 2D** em C++ com `Eigen`, com três abordagens:

- `conv2D`: convolução válida (*valid convolution*), sem padding.
- `conv2D_Padded`: aplica padding explícito com cópia para matriz expandida.
- `conv2D_Optimizer`: versão otimizada por ROI (*Region of Interest*), evitando alocar a matriz com padding completo.

## Visualização

![Convolution 2D Diagram](./conv.svg)


## Estrutura

- `conv2D.hpp`: implementação das funções/lambdas de convolução.
- `conv2D.cpp`: exemplo executável com matriz de entrada e kernel fixos.
- `benchmarks/convolutions.cpp`: benchmark comparando as três abordagens.
- `CMakeLists.txt`: configuração de build (executável e benchmark).

## Pré-requisitos

- CMake >= 3.10
- Compilador com suporte a C++17
- `Eigen3`
- (Opcional, para benchmark) `Google Benchmark`

> O `CMakeLists.txt` exige `find_package(Eigen3 REQUIRED)`.
> Para benchmark, habilite `BENCH=ON` e tenha `benchmark` instalado no sistema.

## Build e execução (exemplo)

No diretório `conv2d`:

```bash
cmake -S . -B build -DEXEC=ON -DBENCH=OFF
cmake --build build
./build/conv2D
```

Esse executável imprime:

- saída da convolução sem padding;
- saída da convolução com padding;
- saída da convolução otimizada.

## Build e execução (benchmark)

```bash
cmake -S . -B build-bench -DEXEC=OFF -DBENCH=ON
cmake --build build-bench
./build/benchmarks/convolutions
```

O benchmark mede as três versões para tamanhos `64`, `128` e `256`.

## Observações técnicas

- Sem padding:
  - linhas de saída: `I_rows - K_rows + 1`
  - colunas de saída: `I_cols - K_cols + 1`
- Com padding `p`:
  - linhas de saída: `I_rows - K_rows + 2p + 1`
  - colunas de saída: `I_cols - K_cols + 2p + 1`
- A versão otimizada reduz overhead de memória ao evitar a matriz expandida completa.

## Dica

Se o benchmark não compilar por falta da biblioteca `benchmark`, mantenha `-DBENCH=OFF` para compilar apenas o executável principal.
