#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

vector<int> genAscending(int n) {
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1); // iota preenche o array com valores sequenciais a partir de 1
    return arr;
}

vector<int> genDescending(int n) {
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    reverse(arr.begin(), arr.end());
    return arr;
}

vector<int> genRandomNoDup(int n, mt19937& rng) { // mt19937 é um gerador de números aleatórios
    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);
    shuffle(arr.begin(), arr.end(), rng); // Embaralha aleatoriamente
    return arr;
}

vector<int> genRandomWithDup(int n, mt19937& rng) {
    vector<int> arr(n);
    uniform_int_distribution<int> dist(1, max(1, n / 2)); // Gaarante distribuição uniforme dentro do intervalo
    // Como o intervalo é metade do tamanho do array, repetições são inevitáveis

    for (int& x : arr) x = dist(rng);
    return arr;
}
