# Analise Comparativa dos Metodos de Ordenacao

Tempos em **nanossegundos** (media filtrada de 10 execucoes).  
Valores fora do intervalo `media +/- desvio padrao` sao descartados antes do calculo final.

## Cenario: Crescente sem repeticao

| n | Bubble (ns) | Insertion (ns) | Selection (ns) | Heap (ns) | Shell (ns) | Merge (ns) | Quick (ns) |
|--:|--:|--:|--:|--:|--:|--:|--:|
| 128 | 116 | 167 | 15924 | 4648 | 505 | 18611 | 986 |
| 256 | 167 | 269 | 70245 | 10347 | 1125 | 32805 | 2065 |
| 512 | 333 | 542 | 293838 | 23574 | 2463 | 68144 | 5611 |
| 1024 | 606 | 1000 | 1297111 | 22305 | 2556 | 115976 | 10801 |
| 2048 | 667 | 856 | 2348143 | 58995 | 7238 | 166398 | 15370 |
| 4096 | 1676 | 2167 | 6643060 | 97699 | 13816 | 227224 | 22255 |
| 8192 | 2948 | 3792 | 23216578 | 226509 | 28528 | 482054 | 52954 |
| 16384 | 5407 | 7565 | 90269949 | 496708 | 57732 | 920854 | 98657 |
| 32768 | 9315 | 12454 | 348391898 | 1150986 | 111109 | 1898768 | 209521 |
| 65536 | 18390 | 25708 | 1407107946 | 2519111 | 234786 | 3977854 | 446393 |

## Cenario: Decrescente sem repeticao

| n | Bubble (ns) | Insertion (ns) | Selection (ns) | Heap (ns) | Shell (ns) | Merge (ns) | Quick (ns) |
|--:|--:|--:|--:|--:|--:|--:|--:|
| 128 | 3426 | 3547 | 11713 | 1901 | 732 | 7306 | 963 |
| 256 | 10042 | 12053 | 54620 | 3990 | 1241 | 15349 | 1981 |
| 512 | 42278 | 37797 | 206463 | 9990 | 2477 | 32225 | 5296 |
| 1024 | 140601 | 143886 | 797222 | 17480 | 5982 | 55421 | 10370 |
| 2048 | 543963 | 543057 | 2868398 | 42657 | 11109 | 111463 | 20745 |
| 4096 | 2139137 | 2165958 | 10864298 | 87903 | 20776 | 231943 | 45736 |
| 8192 | 8652743 | 8691810 | 42299093 | 196389 | 42972 | 464449 | 110069 |
| 16384 | 34390559 | 34763536 | 168099657 | 452574 | 114213 | 1003239 | 220938 |
| 32768 | 144771458 | 140763361 | 673756797 | 1057719 | 247464 | 2021923 | 483662 |
| 65536 | 583910864 | 577567646 | 2674674182 | 2483536 | 489069 | 4122238 | 1085215 |

## Cenario: Aleatorio sem repeticao

| n | Bubble (ns) | Insertion (ns) | Selection (ns) | Heap (ns) | Shell (ns) | Merge (ns) | Quick (ns) |
|--:|--:|--:|--:|--:|--:|--:|--:|
| 128 | 4838 | 1903 | 14667 | 2302 | 1051 | 9694 | 949 |
| 256 | 16026 | 7132 | 50986 | 4472 | 2579 | 16236 | 2176 |
| 512 | 65768 | 20083 | 206384 | 11005 | 6361 | 33745 | 5328 |
| 1024 | 285155 | 81440 | 855313 | 19440 | 12713 | 75396 | 10704 |
| 2048 | 1122685 | 281562 | 2737417 | 40838 | 32181 | 139991 | 27009 |
| 4096 | 4234238 | 1129465 | 9252161 | 97000 | 97890 | 310646 | 86324 |
| 8192 | 16922281 | 4480500 | 33207320 | 247940 | 342917 | 615801 | 225282 |
| 16384 | 68252734 | 18133570 | 126697616 | 665815 | 1216051 | 1447110 | 922838 |
| 32768 | 277079903 | 71527357 | 494991800 | 1399594 | 1727042 | 2714149 | 1204562 |
| 65536 | 1190501718 | 288190916 | 1957701182 | 2978361 | 3698738 | 5437857 | 2526244 |

## Cenario: Aleatorio com repeticao

| n | Bubble (ns) | Insertion (ns) | Selection (ns) | Heap (ns) | Shell (ns) | Merge (ns) | Quick (ns) |
|--:|--:|--:|--:|--:|--:|--:|--:|
| 128 | 5604 | 1963 | 13557 | 2079 | 1074 | 9867 | 986 |
| 256 | 17750 | 6819 | 51000 | 4312 | 2458 | 16273 | 2296 |
| 512 | 66051 | 20021 | 205093 | 8396 | 7412 | 34412 | 4722 |
| 1024 | 294244 | 75208 | 779078 | 18625 | 12139 | 68685 | 10301 |
| 2048 | 1116208 | 288653 | 2597979 | 40380 | 32750 | 139829 | 27111 |
| 4096 | 4290977 | 1197224 | 8926745 | 98348 | 103682 | 302495 | 81908 |
| 8192 | 16594327 | 4483828 | 32335732 | 229213 | 326281 | 618884 | 205523 |
| 16384 | 66453327 | 17528590 | 124402199 | 551449 | 701281 | 1257058 | 471693 |
| 32768 | 272151058 | 71682815 | 489068578 | 1339839 | 1653569 | 2702141 | 1158361 |
| 65536 | 1169042905 | 287230542 | 1959177188 | 3036375 | 3718306 | 5527861 | 2564056 |

## Método mais eficiente por cenário e tamanho

### Crescente sem repeticao

| n | Melhor algoritmo | Tempo (ns) | Pior algoritmo | Tempo (ns) |
|--:|---|--:|---|--:|
| 128 | Bubble | 116 | Merge | 18.611 |
| 256 | Bubble | 167 | Selection | 70.245 |
| 512 | Bubble | 333 | Selection | 293.838 |
| 1024 | Bubble | 606 | Selection | 1.297.111 |
| 2048 | Bubble | 667 | Selection | 2.348.143 |
| 4096 | Bubble | 1.676 | Selection | 6.643.060 |
| 8192 | Bubble | 2.948 | Selection | 23.216.578 |
| 16384 | Bubble | 5.407 | Selection | 90.269.949 |
| 32768 | Bubble | 9.315 | Selection | 348.391.898 |
| 65536 | Bubble | 18.390 | Selection | 1.407.107.946 |

### Decrescente sem repeticao

| n | Melhor algoritmo | Tempo (ns) | Pior algoritmo | Tempo (ns) |
|--:|---|--:|---|--:|
| 128 | Shell | 732 | Selection | 11.713 |
| 256 | Shell | 1.241 | Selection | 54.620 |
| 512 | Shell | 2.477 | Selection | 206.463 |
| 1024 | Shell | 5.982 | Selection | 797.222 |
| 2048 | Shell | 11.109 | Selection | 2.868.398 |
| 4096 | Shell | 20.776 | Selection | 10.864.298 |
| 8192 | Shell | 42.972 | Selection | 42.299.093 |
| 16384 | Shell | 114.213 | Selection | 168.099.657 |
| 32768 | Shell | 247.464 | Selection | 673.756.797 |
| 65536 | Shell | 489.069 | Selection | 2.674.674.182 |

### Aleatorio sem repeticao

| n | Melhor algoritmo | Tempo (ns) | Pior algoritmo | Tempo (ns) |
|--:|---|--:|---|--:|
| 128 | Quick | 949 | Selection | 14.667 |
| 256 | Quick | 2.176 | Selection | 50.986 |
| 512 | Quick | 5.328 | Selection | 206.384 |
| 1024 | Quick | 10.704 | Selection | 855.313 |
| 2048 | Quick | 27.009 | Selection | 2.737.417 |
| 4096 | Quick | 86.324 | Selection | 9.252.161 |
| 8192 | Quick | 225.282 | Selection | 33.207.320 |
| 16384 | Heap | 665.815 | Selection | 126.697.616 |
| 32768 | Quick | 1.204.562 | Selection | 494.991.800 |
| 65536 | Quick | 2.526.244 | Selection | 1.957.701.182 |

### Aleatorio com repeticao

| n | Melhor algoritmo | Tempo (ns) | Pior algoritmo | Tempo (ns) |
|--:|---|--:|---|--:|
| 128 | Quick | 986 | Selection | 13.557 |
| 256 | Quick | 2.296 | Selection | 51.000 |
| 512 | Quick | 4.722 | Selection | 205.093 |
| 1024 | Quick | 10.301 | Selection | 779.078 |
| 2048 | Quick | 27.111 | Selection | 2.597.979 |
| 4096 | Quick | 81.908 | Selection | 8.926.745 |
| 8192 | Quick | 205.523 | Selection | 32.335.732 |
| 16384 | Quick | 471.693 | Selection | 124.402.199 |
| 32768 | Quick | 1.158.361 | Selection | 489.068.578 |
| 65536 | Quick | 2.564.056 | Selection | 1.959.177.188 |

## Conclusão

De acordo com os resultados, pode-se afirmar que não existe um único algoritmo mais eficiente para todos os casos, o desempenho depende do estado inicial e tamanho do array.

O Bubble Sort surpreendeu no cenário crescente, pois ele detecta que o array já está ordenado na primeira passagem e encerra, tornando-se O(n).

O Shell Sort com a sequência de Knuth foi o mais eficiente no cenário decrescente.

O Quick Sort teve melhor performance nos cenários aleatórios, com e sem repetição, confirmando sua eficiência média O(n log n) na prática. A única exceção foi o aleatório sem repetição em n=16384.

O Insertion Sort, assim como o Bubble Sort, se beneficia de dados já ordenados, mas foi consistentemente mais lento que ele no cenário crescente. Nos cenários aleatórios superou o Bubble Sort, e no decrescente teve desempenho praticamente igual ao Bubble.

O Selection Sort foi consistentemente o pior algoritmo em quase todos os casos, sempre O(n²) sem qualquer otimização para casos favoráveis. A única exceção foi o crescente em n=128, onde o Merge Sort ficou em último por causa da recursão em arrays muito pequenos.

O Heap Sort manteve desempenho estável O(n log n) em todos os cenários, sem overhead de memória extra como o Merge Sort. Nos cenários aleatórios, mostrou-se mais rápido que o Shell Sort a partir de n=4096 e superou o Quick Sort no aleatório sem repetição em n=16384.

O Merge Sort manteve comportamento estável e previsível em todos os cenários, mas o tempo de alocação de memória temporária a cada chamada recursiva o tornou mais lento que Quick Sort, Shell Sort e Heap Sort na maioria dos casos, sendo inclusive o pior algoritmo no crescente em n=128.

Então, para dados desconhecidos ou aleatórios, o Quick Sort é a melhor escolha. Para dados parcialmente ordenados ou com padrões específicos, algoritmos como Bubble Sort (crescente) e Shell Sort (decrescente) podem superar até os algoritmos teoricamente superiores.
