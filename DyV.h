#include <vector>
#include <stdexcept>
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

