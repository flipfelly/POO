#include <iostream>
#include <vector>
#include <algorithm>
#include <type_traits>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::begin;
using std::end;

template <typename T>
class container {
    vector<T> elementos;
public:
    container() { elementos = vector<T>(); }

    void inserir(const T& elemento) {
        elementos.push_back(elemento);
    }

    void remover(const T& elemento) {
        elementos.erase(std::remove(elementos.begin(), elementos.end(), elemento), elementos.end());
    }

    bool busca(const T& elemento) {
        return std::find(elementos.begin(), elementos.end(), elemento) != elementos.end();
    }

    T& get_elemento(int index) {
        return elementos[index];
    }

    int tamanho() {
        return (int) elementos.size();
    }
};


template <typename T>
void print_elementos(container<T>& cont) {

    for (int i = 0; i < cont.tamanho(); i++) {
        cout << cont.get_elemento(i) << " ";
    }
    cout << endl;
}

int main(void) {
    container<int> cont_int;

    cont_int.inserir(1);
    cont_int.inserir(2);
    cont_int.inserir(3);
    cont_int.inserir(4);
    cont_int.inserir(5);

    cont_int.remover(5);

    print_elementos(cont_int);

    container<string> cont_str;

    cont_str.inserir("Hello world!");
    cont_str.inserir("Alo Brasil!");
    cont_str.inserir("POO");

    print_elementos(cont_str);

    return 0;
}