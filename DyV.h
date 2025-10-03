#include <vector>
#include <stdexcept>
#include <chrono>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
using namespace std::chrono;

template <typename T>

int BinarySearch(T x, std::vector<T>& v, int ini, int fin){
	if(ini > fin){
		throw std::out_of_range("No se encuentra en el array");
	}
	int medio = (ini + fin)/2;
	if(v[medio] == x){
		return medio;
	}
	else if(v[medio]>x){
		return BinarySearch(x,v,ini,medio-1);
	}
	else{
		return BinarySearch(x,v,medio+1,fin);
	}
}

template <typename T>

int BinarySearch_INV(T x, std::vector<T>& v, int ini, int fin){
	if(ini > fin){
		throw std::out_of_range("No se encuentra en el array");
	}

	int medio = (ini + fin)/2;
	if(v[medio] == x) {
		return medio;
	}

	else if(v[medio] < x){
		return BinarySearch_INV(x,v,ini,medio-1);
	}
	else{
		return BinarySearch_INV(x,v,medio+1,fin);
	}
}


template <typename T>
int partition(std::vector<T>& v, int ini, int fin){
	T x = v[fin];
	int i = ini;
	for(int j = ini;j<fin;i++){
		if(v[j]<= x){
			swap(v[i],v[j]);
			i++;
		}
	}
	swap(v[i],v[fin]);
	return i;
}


template <typename T>
void swap(T a, T b){
	T aux = a;
	a = b;
	b = aux;
}

template <typename T>
void quicksort(std::vector<T>& v, int ini, int fin){
	if(ini<fin){
		int pivot = partition(v,ini,fin);
		quicksort(v,ini, pivot-1);
		quicksort(v,pivot+1, fin);
	}
}



// -----------------------------
// Partition con pivote al final
// -----------------------------
template <typename T>
int partition_last(std::vector<T>& v, int ini, int fin) {
    T pivote = v[fin];
    int i = ini;
    for (int j = ini; j < fin; j++) {
        if (v[j] <= pivote) {
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[fin]);
    return i;
}

// -----------------------------
// Partition con pivote al inicio
// -----------------------------
template <typename T>
int partition_first(std::vector<T>& v, int ini, int fin) {
    swap(v[ini], v[fin]); // mueve el primero al final
    return partition_last(v, ini, fin);
}

// -----------------------------
// Partition con pivote central
// -----------------------------
template <typename T>
int partition_middle(std::vector<T>& v, int ini, int fin) {
    int mid = ini + (fin - ini) / 2;
    swap(v[mid], v[fin]); // mueve el central al final
    return partition_last(v, ini, fin);
}

// -----------------------------
// Partition con pivote aleatorio
// -----------------------------
template <typename T>
int partition_random(std::vector<T>& v, int ini, int fin) {
    int rand_index = ini + rand() % (fin - ini + 1);
    swap(v[rand_index], v[fin]); // mueve un aleatorio al final
    return partition_last(v, ini, fin);
}

// -----------------------------
// QuickSort genérico con puntero a función de partición
// -----------------------------
template <typename T>
void quicksort2(std::vector<T>& v, int ini, int fin,
               int (*partition_func)(std::vector<T>&, int, int)) {
    if (ini < fin) {
        int pivot = partition_func(v, ini, fin);
        quicksort2(v, ini, pivot - 1, partition_func);
        quicksort2(v, pivot + 1, fin, partition_func);
    }
}


template <typename T>
void medirTiempo(std::vector<T> v, 
                 int (*partition_func)(std::vector<T>&, int, int),
                 const string& nombre) {
    auto start = high_resolution_clock::now();
    quicksort2(v, 0, v.size() - 1, partition_func);
    auto end = high_resolution_clock::now();
    auto duracion = duration_cast<microseconds>(end - start);
    cout << nombre << " tardó: " << duracion.count() << " microsegundos\n";
}






