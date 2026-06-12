#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;

// Imprime a tabela no terminal
void printTableConsole(const string& scenario, const vector<int>& sizes,
                       const vector<string>& algNames,
                       const vector<vector<double>>& results);

// Imprime a tabela em formato Markdown
void writeMdTable(ofstream& file, const string& scenario, const vector<int>& sizes,
                  const vector<string>& algNames,
                  const vector<vector<double>>& results);
