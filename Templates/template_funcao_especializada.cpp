#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

template <>
const char* max(const char* a, const char* b) {
    return (strcmp(a,b) > 0) ? a : b;
}

int main() {
    int res_max_int = max(100, 99);
    double res_max_double = max(0.7374, 9.2345);
    const char* res_max_str = max("ABACAXI", "BATATA");

    cout << "Valor maximo (int): " << res_max_int << endl;
    cout << "Valor maximo (double): " << res_max_double << endl;
    cout << "Valor maximo (char*): " << res_max_str << endl;

    return 0;
}