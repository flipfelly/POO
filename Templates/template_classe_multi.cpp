#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename T, typename U>
class par {
    T primeiro;
    U segundo;
public:
    par(T p, U s):primeiro(p), segundo(s) {}

    void print_info() {
        cout << "Par: " << primeiro << ", " << segundo << endl;
    }
};

int main(void) {
    par<int, double> p1(10, 3.1415);
    par<string, char> p2("Hello world!", 'Z');

    p1.print_info();
    p2.print_info();

    return 0;
}

