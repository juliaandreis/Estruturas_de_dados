#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <functional>
#include <random>
#include <iomanip>
#include "sortingAlgorithms.h"
#include "arrayGenerator.h"
#include "printTable.h"
#include "mean.h"

using namespace std;
using namespace chrono;

const int RUNS = 10;

// --- BENCHMARK ---

long long run(function<void(vector<int>&)> sortFunction, const vector<int>& original) {
    vector<int> arr = original;
    auto start = high_resolution_clock::now();
    sortFunction(arr);
    auto end = high_resolution_clock::now();
    return duration_cast<nanoseconds>(end - start).count();
}

int main(){
    vector<int> sizes = {128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};

    vector<string> algNames = {"Bubble", "Insertion", "Selection", "Heap", "Shell", "Merge", "Quick"};

    vector<function<void(vector<int>&)>> algorithms = {bubbleSort, insertionSort, selectionSort, heapSort, shellSort, mergeSort, quickSort};
    
    mt19937 rng(42); // Semente fixa para reproducibilidade dos arrays aleatorios

    struct Scenario {
        string name;
        function<vector<int>(int)> gen; // Função que recebe n e retorna o array pronto
    };

    vector<Scenario> scenarios = {
        {"Crescente sem repeticao", [](int n) {return genAscending(n);}},
        {"Decrescente sem repeticao", [](int n) {return genDescending(n);}},
        {"Aleatorio sem repeticao", [&](int n) {return genRandomNoDup(n, rng);}},
        {"Aleatorio com repeticao", [&](int n) {return genRandomWithDup(n, rng);}},
    };

    // Gera nome do arquivo com data e hora atual
    time_t now = time(0);
    tm* t = localtime(&now);
    char filename[32];
    strftime(filename, sizeof(filename), "resultados_%Y%m%d_%H%M%S.md", t);

    // Abre o arquivo resultados.md para escrita
    ofstream mdFile(filename);
    mdFile << "# Analise Comparativa dos Metodos de Ordenacao\n\n";
    mdFile << "Tempos em **nanossegundos** (media filtrada de " << RUNS << " execucoes).  \n";
    mdFile << "Valores fora do intervalo `media +/- desvio padrao` sao descartados antes do calculo final.\n\n";

    // Abre o arquivo arrays.txt para armazenar os arrays gerados
    ofstream arraysFile("arrays.txt");

    for (Scenario& scenario : scenarios) {
        // Matriz de resultados 7 × 10 — 7 algoritmos, 10 tamanhos, results[algorithm_idx][size_idx]
        vector<vector<double>> results(algorithms.size(), vector<double>(sizes.size()));

        for (int size_idx = 0; size_idx < (int)sizes.size(); size_idx++) {
            int n = sizes[size_idx];

            // Gera o array original uma vez e todos os algoritmos recebem o mesmo array
            vector<int> original = scenario.gen(n);

            // Salva o array gerado no arquivo
            arraysFile << "[" << scenario.name << "] n=" << n << "\n";
            for (int i = 0; i < n; i++)
                arraysFile << original[i] << (i < n - 1 ? " " : "\n");
            arraysFile << "\n";

            for (int algorithm_idx = 0; algorithm_idx < (int)algorithms.size(); algorithm_idx++) {
                cerr << "[" << scenario.name << "] n=" << setw(6) << n
                     << " | " << left << setw(10) << algNames[algorithm_idx] << "\r";
                cerr.flush();

                // Executa o algoritmo 10 vezes, guardando cada tempo
                vector<double> times(RUNS);
                for (int r = 0; r < RUNS; r++)
                    times[r] = (double) run(algorithms[algorithm_idx], original);

                // Calcula a média filtrada das 10 execuções e salva na posição [algoritmo][tamanho]
                results[algorithm_idx][size_idx] = meanCalc(times);
            }
        }

        printTableConsole(scenario.name, sizes, algNames, results); // imprime no terminal
        writeMdTable(mdFile, scenario.name, sizes, algNames, results); // imprime no arquivo .md
    }

    arraysFile.close();
    mdFile.close();
    cout << "\nResultados salvos em " << filename << "\n";
    cout << "Arrays salvos em arrays.txt\n";
    return 0;
}
