#include <iostream>
#include <vector>
#include <string>
#include "DyV.h"
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

    return 0;
}
