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
trabalho/
├── main.cpp              # benchmark principal
├── sortingAlgorithms.h   # implementação dos 7 algoritmos de ordenação
├── arrayGenerator.h      # geração dos arrays de teste
├── mean.h                # cálculo da média filtrada
├── printTable.h          # impressão dos resultados no terminal e em .md
└── resultados.md         # resultados gerados após a execução
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

```bash
g++ main.cpp -o benchmark
./benchmark
```

Os resultados serão impressos no terminal e salvos em `resultados.md`.
