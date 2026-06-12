#pragma once

#include <vector>
#include <random>

using namespace std;

vector<int> genAscending(int n);
vector<int> genDescending(int n);
vector<int> genRandomNoDup(int n, mt19937& rng);
vector<int> genRandomWithDup(int n, mt19937& rng);
