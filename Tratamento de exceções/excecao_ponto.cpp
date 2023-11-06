#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class ponto_exception {
	string msg;
public:
	ponto_exception(const string& s):msg(s) { }
	void print_info() { cout << msg << endl; }
};

class ponto {
	float x;
	float y;
public:
	ponto(float xx, float yy) {
		if ((xx < 0) || (yy < 0))
			throw new ponto_exception("NEG");
		x = xx;
		y = yy;
	}
	void print_info() {
		cout << "X: " << x << " Y: " << y << endl;
	}
};

int main(void) {

	input_values:
	try {
		float xx, yy;
		cout << "Digite x: ";
		cin >> xx;
		cout << "Digite y: ";
		cin >> yy;
		ponto* p1 = new ponto(xx, yy);
		p1->print_info();

	} catch (ponto_exception* e) {
		cout << "Excecao lancada: ";
		e->print_info();
		cout << "Digite os valores novamente!" << endl;
		goto input_values;
	}

	cout << "Fim!" << endl;

	return 0;
}
