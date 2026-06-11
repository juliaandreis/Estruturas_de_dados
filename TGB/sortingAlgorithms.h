#include <vector>
#include <algorithm>

using namespace std;

// --- Bubble Sort ---
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// --- Insertion Sort ---
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// --- Selection Sort ---
void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j; 
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

// --- Heap Sort ---
// "Desce" o elemento i trocando-o com o maior filho enquanto não respeitar a regra pai >= filhos
static void heapify(vector<int>& arr, int size, int i) {
    int largest = i; // Começa assumindo que o pai é o maior
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && arr[left] > arr[largest]) largest = left;    // esquerdo é maior?
    if (right < size && arr[right] > arr[largest]) largest = right; // direito é maior?
    // Se nenhuma condição acima for verdadeira, o nó já está no lugar certo

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heapSort(vector<int>& arr) {
    int size = arr.size();

    // Ao final, arr[0] contém o maior elemento de todo o array
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    // A cada iteração, arr[0] é o maior do heap ainda ativo
    // Trocar com arr[i] coloca esse maior na posição final correta
    // O heap encolhe (tamanho i)
    for (int i = size - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// --- Shell Sort ---
void shellSort(vector<int>& arr) {
    int size = arr.size();

    // Sequência de Knuth: começa em 1 e cresce com h = 3h + 1 até o maior h menor que size/3
    int h = 1;
    while (h < size / 3) h = 3 * h + 1;

    // Reduz h até chegar em 1, aplicando insertion sort com espaçamento h a cada rodada
    while (h >= 1) {
        // Insertion sort com espaçamento h
        // i começa em h pois os primeiros h elementos já estão em seus subarrays de tamanho 1 (trivialmente ordenados)
        for (int i = h; i < size; i++) {
            int temp = arr[i]; // Elemento a ser inserido na posição correta
            int j = i;

            // Desloca elementos do subarray com espaçamento h que são maiores que temp
            // para abrir espaço para a inserção de temp
            while (j >= h && arr[j - h] > temp) {
                arr[j] = arr[j - h];
                j -= h;
            }

            // Insere temp na posição correta dentro do subarray de gap h
            arr[j] = temp;
        }

        h = (h - 1) / 3;  // Próximo h da sequência de Knuth (inverso de 3h+1)
    }
}

// --- Merge Sort ---
// MergeSort divide o array recursivamente ao meio e intercala os subarrays ordenados.
static void mergeHelper(vector<int>& arr, int left, int mid, int right) {
    // Calcula o tamanho de cada metade
    int leftArrSize  = mid - left + 1;
    int rightArrSize = right - mid;

    // Cria arrays temporários para cada metade
    vector<int> L(leftArrSize), R(rightArrSize);

    // Copia os elementos para os arrays temporários
    for (int i = 0; i < leftArrSize; i++)  L[i] = arr[left + i];
    for (int j = 0; j < rightArrSize; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Intercala os dois subarrays de volta em arr[left..right]
    // Compara o menor elemento de cada metade e insere o menor
    while (i < leftArrSize && j < rightArrSize)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    // Copia os elementos restantes de L[], se houver
    while (i < leftArrSize)  arr[k++] = L[i++];

    // Copia os elementos restantes de R[], se houver
    while (j < rightArrSize) arr[k++] = R[j++];
}

// Divide recursivamente o array e chama mergeHelper para ordenar
static void mergeSortRec(vector<int>& arr, int left, int right) {
    if (left >= right) return;           // Caso base: subarray de tamanho 0 ou 1 já está ordenado
    int mid = left + (right - left) / 2; // Evita overflow ao calcular o meio
    mergeSortRec(arr, left, mid);        // Ordena a metade esquerda
    mergeSortRec(arr, mid + 1, right);   // Ordena a metade direita
    mergeHelper(arr, left, mid, right);  // Intercala as duas metades ordenadas
}

void mergeSort(vector<int>& arr) {
    mergeSortRec(arr, 0, (int)arr.size() - 1);
}

// --- Quick Sort ---
// Posiciona o pivô (mediana de três) em seu lugar definitivo
// No final, tudo à esquerda de p é <= pivô, tudo à direita é > pivô
static int quickPartition(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    // Ordena arr[low], arr[mid], arr[high] e coloca a mediana em arr[high]
    if (arr[low] > arr[mid])  swap(arr[low], arr[mid]);
    if (arr[low] > arr[high]) swap(arr[low], arr[high]);
    if (arr[mid] > arr[high]) swap(arr[mid], arr[high]);
    swap(arr[mid], arr[high]); // Pivo vai para arr[high]
    int pivot = arr[high];
    int i = low - 1; // i aponta para o último elemento menor ou igual ao pivô

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[++i], arr[j]); // Move elemento para a região <= pivô
        }
    }

    swap(arr[i + 1], arr[high]); // Coloca o pivô em sua posição definitiva
    return i + 1;
}

// Divide e ordena recursivamente os subarrays à esquerda e à direita do pivô
static void quickSortRec(vector<int>& arr, int low, int high) {
    if (low < high) {  // subarray com 2 ou mais elementos, continua dividindo
        int pi = quickPartition(arr, low, high);
        quickSortRec(arr, low, pi - 1);  // Ordena elementos menores que o pivô
        quickSortRec(arr, pi + 1, high); // Ordena elementos maiores que o pivô
    }
}

void quickSort(vector<int>& arr) {
    if ((int)arr.size() > 1)
        quickSortRec(arr, 0, (int)arr.size() - 1);
}
