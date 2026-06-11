#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

// Imprime a tabela no terminal
void printTableConsole(const string& scenario, const vector<int>& sizes,
                       const vector<string>& algNames,
                       const vector<vector<double>>& results) {

    const int COL = 15; // largura de cada coluna
    
    // Imprime o cabeçalho
    cout << "\n=== Cenario: " << scenario << " ===\n";
    cout << left << setw(8) << "n";
    for (const auto& name : algNames)
        cout << setw(COL) << name;
    
    cout << "\n" << string(8 + COL * algNames.size(), '-') << "\n";

    // Imprime as linhas de dados
    for (int i = 0; i < (int)sizes.size(); i++) {
        cout << setw(8) << sizes[i];
        for (int j = 0; j < (int)algNames.size(); j++)
            cout << setw(COL) << fixed << setprecision(0) << results[j][i];
        cout << "\n";
    }
    cout << "\n";
}

// Imprime a tabela em formato Markdown
void writeMdTable(ofstream& file, const string& scenario, const vector<int>& sizes,
                  const vector<string>& algNames,
                  const vector<vector<double>>& results) {
    
    // Imprime o cabeçalho
    file << "## Cenario: " << scenario << "\n\n";
    file << "| n |";
    for (const auto& name : algNames)
        file << " " << name << " (ns) |";
    
    file << "\n|--:|";
    for (size_t i = 0; i < algNames.size(); i++) file << "--:|";
    file << "\n";
    
    // Imprime as linhas de dados
    for (int i = 0; i < (int)sizes.size(); i++) {
        file << "| " << sizes[i] << " |";
        for (int j = 0; j < (int)algNames.size(); j++)
            file << " " << fixed << setprecision(0) << results[j][i] << " |";
        file << "\n";
    }
    file << "\n";
}
