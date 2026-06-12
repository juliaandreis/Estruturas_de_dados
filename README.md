# Análise Comparativa dos Métodos de Ordenação

Universidade do Vale do Rio dos Sinos  
Trabalho GB - Algoritmos e Programação: Estruturas de Dados  
Autores - Julia Renata Andreis, Tobias Klein Steyer, Artur Brenner Schmitt  

## Descrição

Implementação e análise comparativa de tempo dos principais algoritmos de ordenação:
Bubble Sort, Insertion Sort, Selection Sort, Heap Sort, Shell Sort, Merge Sort e Quick Sort.

Os algoritmos são testados em 4 cenários e 10 tamanhos de array diferentes.
Os tempos são medidos em nanossegundos e calculados com base na média filtrada de 10 execuções.

## Estrutura do projeto

```
.
├── Makefile                # script de compilação
├── README.md               # este arquivo
├── arrays.txt              # arrays gerados na última execução
├── resultados_analisados.md # análise final com conclusão e tabelas comparativas
└── TGB/
    ├── main.cpp                 # benchmark principal
    ├── sortingAlgorithms.h/.cpp # 7 algoritmos de ordenação
    ├── arrayGenerator.h/.cpp    # geração dos arrays de teste
    ├── mean.h/.cpp              # cálculo da média filtrada
    └── printTable.h/.cpp        # impressão dos resultados no terminal e em .md
```

## Cenários de teste

| # | Cenário |
|---|---------|
| 1 | Crescente sem repetição |
| 2 | Decrescente sem repetição |
| 3 | Aleatório sem repetição |
| 4 | Aleatório com repetição |

## Tamanhos de array

128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536

## Metodologia

Para cada combinação de algoritmo, cenário e tamanho:
1. O array original é gerado uma única vez
2. O algoritmo é executado 10 vezes sobre cópias do array original
3. Calcula-se a média e o desvio padrão das 10 execuções
4. Descartam-se os tempos fora do intervalo `média ± desvio padrão`
5. Calcula-se a média final apenas com os valores restantes

## Como compilar e executar

A partir da raiz do projeto:

```bash
make
./TGB/benchmark
```

O `make` só recompila o que mudou. Se aparecer `make: Nothing to be done for 'all'`, significa que já está compilado e pronto para executar.

Para forçar uma recompilação do zero:

```bash
make clean
make
```

Compilação manual (sem Makefile):

```bash
g++ -std=c++17 -O2 -Wall -Wextra -I./TGB \
    TGB/main.cpp TGB/arrayGenerator.cpp TGB/mean.cpp TGB/printTable.cpp TGB/sortingAlgorithms.cpp \
    -o TGB/benchmark
./TGB/benchmark
```

A execução produz dois arquivos na raiz do projeto:
- `resultados_YYYYMMDD_HHMMSS.md` — tabelas de tempos por cenário (nome com data e hora da execução)
- `arrays.txt` — arrays usados como entrada em cada cenário/tamanho (sobrescrito a cada execução)

## Análise

O arquivo `resultados_analisados.md` contém a análise final feita manualmente sobre os resultados, com tabelas indicando o método mais eficiente e o menos eficiente para cada cenário e tamanho de array, além de uma conclusão geral sobre o desempenho dos algoritmos.
