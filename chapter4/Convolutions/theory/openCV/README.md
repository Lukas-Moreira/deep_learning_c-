# OpenCV Edge Detection (Sobel)

Implementação de **detecção de bordas com filtros Sobel** em C++ usando `Eigen` e `OpenCV`.

## Descrição

O programa aplica os operadores Sobel (G_x e G_y) a uma imagem em escala de cinza para detectar bordas horizontais e verticais.

- `G_x`: detecta bordas **verticais** (gradiente em x)
- `G_y`: detecta bordas **horizontais** (gradiente em y)

## Estrutura


- `openCV.cpp`: programa principal que carrega a imagem "chess.jpg", aplica os filtros Sobel e exibe os resultados.
- `conv2D.hpp`: implementação da função `conv2D_Padded()` para convolução 2D com padding.

## Pré-requisitos

- CMake >= 3.10
- Compilador com suporte a C++17
- `Eigen3`
- `OpenCV` >= 4.0

## Build e execução

No diretório do projeto:

```bash
cmake -S . -B build
cmake --build build
./build/openCV
```

O programa exibe:
- Imagem original
- Resultado do filtro G_x (bordas verticais)
- Resultado do filtro G_y (bordas horizontais)

## Observações técnicas

- Usa `padding = 1` para manter as dimensões da saída iguais à entrada
- Converte a imagem para escala de cinza antes de aplicar os filtros
- Converte resultados para formato `CV_8UC1` (8-bit unsigned char) para exibição

