#include <vector>
#include <cmath>

using namespace std;

double meanCalc(vector<double>& times) {
    int n = times.size();

    // Media de todas as 10 execucoes
    double mean = 0.0;
    for (double t : times) mean += t;
    mean /= n;

    // Variancia
    double variance = 0.0;
    for (double t : times) {
        double diff = t - mean;
        variance += diff * diff;
    }
    variance /= (n - 1);

    // Desvio padrao
    double stdev = sqrt(variance);

    double sum = 0;
    int count = 0;

    // Remove valores fora de [media - desvio padrao, media + desvio padrao]
    for (double t : times) {
        if (t >= mean - stdev && t <= mean + stdev) {
            sum += t;
            count++;
        }
    }

    return sum / count;
}
