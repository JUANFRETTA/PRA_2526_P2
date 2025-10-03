#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
#include "DyV.h"
using namespace std::chrono;
using namespace std;

int main() {
    // =====================
    // PRUEBAS ORDEN ASCENDENTE
    // =====================
    vector<int> asc = {1, 3, 5, 7, 9, 11};

    try {
        cout << "ASC: Buscar 7 -> pos: "
             << BinarySearch(7, asc, 0, asc.size() - 1) << endl;
        cout << "ASC: Buscar 1 -> pos: "
             << BinarySearch(1, asc, 0, asc.size() - 1) << endl;
        cout << "ASC: Buscar 11 -> pos: "
             << BinarySearch(11, asc, 0, asc.size() - 1) << endl;

        // No está
        cout << "ASC: Buscar 8 -> ";
        cout << BinarySearch(8, asc, 0, asc.size() - 1) << endl;
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    // =====================
    // PRUEBAS ORDEN DESCENDENTE
    // =====================
    vector<int> desc = {20, 17, 15, 10, 5, 2};

    try {
        cout << "DESC: Buscar 15 -> pos: "
             << BinarySearch_INV(15, desc, 0, desc.size() - 1) << endl;
        cout << "DESC: Buscar 20 -> pos: "
             << BinarySearch_INV(20, desc, 0, desc.size() - 1) << endl;
        cout << "DESC: Buscar 2 -> pos: "
             << BinarySearch_INV(2, desc, 0, desc.size() - 1) << endl;

        // No está
        cout << "DESC: Buscar 8 -> ";
        cout << BinarySearch_INV(8, desc, 0, desc.size() - 1) << endl;
    } catch (const out_of_range& e) {
        cout << e.what() << endl;
    }
	

    // PRUEBAS QUICKSORT

	    
    vector<int> v1 = {4, 23, 3, 8, 1, 11};
    vector<float> v2 = {5.2, 1.1, 10.45, 5.6, 7.1};
    vector<char> v3 = {'d', 'r', 'b', 'z', 'f'};

    template <typename T>
    void imprimir(vector<T>& v){
    	for(int i = 0; i<v.size()-1;i++){
		cout << v[i] << " ";
	
	}
		cout << endl;
    }

    imprimir(v1);
    cout << "Vector int ordenado:" << endl;
    quicksort(v1,0,v1.size()-1);
    imprimir(v1);

    imprimir(v2);
    cout << "Vector float ordenado:" << endl;
    quicksort(v1,0,v2.size()-1);
    imprimir(v2);

    imprimir(v3);
    cout << "Vector char ordenado:" << endl;
    quicksort(v1,0,v3.size()-1);
    imprimir(v3);




    srand(time(0)); // inicializar aleatorio

    // Creamos un vector grande de prueba
    int n = 100000;
    vector<int> datos(n);
    for (int i = 0; i < n; i++) datos[i] = rand();

    cout << "Prueba de QuickSort con " << n << " elementos\n";

    medirTiempo(datos, partition_last<int>, "Pivote último");
    medirTiempo(datos, partition_first<int>, "Pivote primero");
    medirTiempo(datos, partition_middle<int>, "Pivote central");
    medirTiempo(datos, partition_random<int>, "Pivote aleatorio");

    return 0;

}
