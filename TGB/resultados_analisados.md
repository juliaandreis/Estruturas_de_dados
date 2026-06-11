# Analise Comparativa dos Metodos de Ordenacao

Tempos em **nanossegundos** (media filtrada de 10 execucoes).  
Valores fora do intervalo `media +/- desvio padrao` sao descartados antes do calculo final.

## Cenario: Crescente sem repeticao

| n | Bubble (ns) | Insertion (ns) | Selection (ns) | Heap (ns) | Shell (ns) | Merge (ns) | Quick (ns) |
|--:|--:|--:|--:|--:|--:|--:|--:|
| 128 | 704 | 1250 | 42412 | 21732 | 6231 | 149468 | 9524 |
| 256 | 1646 | 3000 | 200662 | 64625 | 12982 | 253021 | 18926 |
| 512 | 2829 | 5234 | 746851 | 57094 | 21292 | 359633 | 15354 |
| 1024 | 2548 | 3724 | 1339896 | 139528 | 23860 | 537766 | 47546 |
| 2048 | 6750 | 10275 | 4924724 | 257660 | 45860 | 746125 | 66069 |
| 4096 | 8729 | 13167 | 18001946 | 535072 | 108000 | 1534097 | 157463 |
| 8192 | 18130 | 26984 | 70951993 | 1087458 | 197333 | 3002708 | 306028 |
| 16384 | 35523 | 53401 | 285926869 | 2328822 | 460991 | 6430953 | 701470 |
| 32768 | 68394 | 113106 | 1147010472 | 4966411 | 981361 | 13418411 | 1518068 |
| 65536 | 157738 | 237917 | 4581119356 | 10349120 | 2125307 | 27439588 | 3215917 |

## Cenario: Decrescente sem repeticao

| n | Bubble (ns) | Insertion (ns) | Selection (ns) | Heap (ns) | Shell (ns) | Merge (ns) | Quick (ns) |
|--:|--:|--:|--:|--:|--:|--:|--:|
| 128 | 40364 | 29079 | 20844 | 8042 | 4089 | 40653 | 5755 |
| 256 | 160991 | 114458 | 83116 | 20676 | 9102 | 88798 | 11214 |
| 512 | 632866 | 461672 | 324643 | 47857 | 17982 | 176631 | 26489 |
| 1024 | 2505505 | 1810345 | 1263204 | 109472 | 38500 | 364097 | 58307 |
| 2048 | 10905594 | 6841639 | 4960719 | 237813 | 89769 | 746176 | 130922 |
| 4096 | 40013863 | 27073357 | 19408452 | 510867 | 170912 | 1699167 | 300565 |
| 8192 | 158075149 | 108024464 | 78259119 | 1079271 | 356694 | 3156844 | 635641 |
| 16384 | 647995266 | 436620922 | 307342050 | 2278357 | 956510 | 6471131 | 1396333 |
| 32768 | 2562404762 | 1750358131 | 1227334896 | 4848074 | 1855361 | 13301686 | 3014369 |
| 65536 | 9885878042 | 6963178416 | 4903736319 | 10173079 | 3825875 | 27356894 | 6493238 |

## Cenario: Aleatorio sem repeticao

| n | Bubble (ns) | Insertion (ns) | Selection (ns) | Heap (ns) | Shell (ns) | Merge (ns) | Quick (ns) |
|--:|--:|--:|--:|--:|--:|--:|--:|
| 128 | 38384 | 14807 | 22047 | 8468 | 5771 | 42787 | 4370 |
| 256 | 150699 | 56320 | 81636 | 22708 | 16500 | 94562 | 9759 |
| 512 | 622861 | 216060 | 308213 | 51199 | 42963 | 191234 | 23505 |
| 1024 | 2585390 | 876344 | 1197757 | 120250 | 95454 | 425162 | 54531 |
| 2048 | 10758834 | 3540531 | 4641551 | 273463 | 229880 | 857940 | 139281 |
| 4096 | 43589625 | 13727699 | 18251617 | 615616 | 505352 | 1761583 | 339422 |
| 8192 | 179194179 | 53559536 | 72004281 | 1364352 | 1364818 | 3788974 | 770496 |
| 16384 | 749030509 | 217286042 | 286934548 | 2927471 | 2585536 | 7621893 | 1653417 |
| 32768 | 3080645932 | 867766245 | 1146906227 | 6246732 | 6066691 | 15810273 | 3521394 |
| 65536 | 12742561118 | 3489628458 | 4588012714 | 13451315 | 12889655 | 32428347 | 7509656 |

## Cenario: Aleatorio com repeticao

| n | Bubble (ns) | Insertion (ns) | Selection (ns) | Heap (ns) | Shell (ns) | Merge (ns) | Quick (ns) |
|--:|--:|--:|--:|--:|--:|--:|--:|
| 128 | 39125 | 14922 | 21453 | 7677 | 5917 | 42972 | 5398 |
| 256 | 148685 | 55421 | 81079 | 26977 | 15991 | 93224 | 11917 |
| 512 | 621479 | 218222 | 306198 | 56621 | 38000 | 201454 | 24630 |
| 1024 | 2554911 | 870078 | 1198980 | 124438 | 90620 | 413745 | 64880 |
| 2048 | 10516911 | 3546896 | 4725274 | 271935 | 216016 | 859370 | 149255 |
| 4096 | 44062882 | 13679476 | 18206089 | 614722 | 519625 | 1807995 | 330731 |
| 8192 | 182201780 | 54131416 | 71991042 | 1366403 | 1174031 | 3718792 | 765884 |
| 16384 | 752777472 | 217764104 | 294731993 | 2974813 | 2607229 | 7942266 | 1730120 |
| 32768 | 3113239423 | 873624083 | 1145400599 | 6241474 | 5631625 | 15869440 | 3626306 |
| 65536 | 12689476881 | 3482298078 | 4587076360 | 13406394 | 12509144 | 32718125 | 7745477 |

## Método mais eficiente por cenário e tamanho

### Crescente sem repeticao

| n | Melhor algoritmo | Tempo (ns) |
|--:|---|--:|
| 128 | Bubble | 704 |
| 256 | Bubble | 1.646 |
| 512 | Bubble | 2.829 |
| 1024 | Bubble | 2.548 |
| 2048 | Bubble | 6.750 |
| 4096 | Bubble | 8.729 |
| 8192 | Bubble | 18.130 |
| 16384 | Bubble | 35.523 |
| 32768 | Bubble | 68.394 |
| 65536 | Bubble | 157.738 |

### Decrescente sem repeticao

| n | Melhor algoritmo | Tempo (ns) |
|--:|---|--:|
| 128 | Shell | 4.089 |
| 256 | Shell | 9.102 |
| 512 | Shell | 17.982 |
| 1024 | Shell | 38.500 |
| 2048 | Shell | 89.769 |
| 4096 | Shell | 170.912 |
| 8192 | Shell | 356.694 |
| 16384 | Shell | 956.510 |
| 32768 | Shell | 1.855.361 |
| 65536 | Shell | 3.825.875 |

### Aleatorio sem repeticao

| n | Melhor algoritmo | Tempo (ns) |
|--:|---|--:|
| 128 | Quick | 4.370 |
| 256 | Quick | 9.759 |
| 512 | Quick | 23.505 |
| 1024 | Quick | 54.531 |
| 2048 | Quick | 139.281 |
| 4096 | Quick | 339.422 |
| 8192 | Quick | 770.496 |
| 16384 | Quick | 1.653.417 |
| 32768 | Quick | 3.521.394 |
| 65536 | Quick | 7.509.656 |

### Aleatorio com repeticao

| n | Melhor algoritmo | Tempo (ns) |
|--:|---|--:|
| 128 | Heap | 7.677 |
| 256 | Shell | 15.991 |
| 512 | Shell | 38.000 |
| 1024 | Shell | 90.620 |
| 2048 | Shell | 216.016 |
| 4096 | Shell | 519.625 |
| 8192 | Shell | 1.174.031 |
| 16384 | Shell | 2.552.182 |
| 32768 | Shell | 5.567.292 |
| 65536 | 12509144 |

## Conclusão

De acordo com os resultados, pode-se afirmar que não existe um único algoritmo mais eficiente para todos os casos, o desempenho depende do estado inicial e tamanho do array.

O Bubble Sort surpreendeu no cenário crescente, pois ele detecta que o array já está ordenado na primeira passagem e encerra, tornando-se O(n).

O Shell Sort com a sequência de Knuth foi o mais eficiente no cenário decrescente e no aleatório com repetição.

O Quick Sort teve melhor performance nos cenários aleatórios, confirmando sua eficiência média O(n log n) na prática.

O Selection Sort foi consistentemente o pior algoritmo em todos os cenários, sempre O(n²) independente do estado do array.

O Merge Sort manteve comportamento estável e previsível em todos os cenários, mas seu overhead de alocação de memória temporária a cada chamada recursiva o tornou mais lento que Quick Sort e Shell Sort na maioria dos casos.

Então, para dados desconhecidos ou aleatórios, o Quick Sort é a melhor escolha. Para dados parcialmente ordenados ou com padrões específicos, algoritmos como Bubble Sort (crescente) e Shell Sort (decrescente) podem superar até os algoritmos teoricamente superiores.
