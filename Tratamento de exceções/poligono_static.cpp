#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class poligono {
	static int contador;
	string cor;
public:
	poligono(const string& c):cor(c) { contador++; }
	~poligono() { contador--; }
	static int get_contador() { return contador; }
	virtual float get_area()=0;
};

class retangulo : public poligono {
	float base;
	float altura;
public:
	retangulo(const string& c, float b, float a)
			:poligono(c), base(b), altura(a) {
		cout << "retangulo(" << base << ", " << altura << ")" << endl;
	}

	float get_area() {
		return base*altura;
	}
};

class circulo : public poligono {
	float raio;
public:
	circulo(const string& c, float r):poligono(c), raio(r) {
		cout << "circulo(" << raio << ")" << endl;
	}

	float get_area() {
		return (3.14*(raio*raio));
	}
};

int poligono::contador = 0;

int main(void) {
	float soma_area = 0;

	circulo c1("#323451", 20);
	soma_area += c1.get_area();

	retangulo r1("#243245", 10, 5);
	soma_area += r1.get_area();

	retangulo r2("#242342", 20, 2);
	soma_area += r2.get_area();

	circulo* pc1 = new circulo("#345555", 10);
	soma_area += pc1->get_area();

	cout << "Quantidade de poligonos criados: " << poligono::get_contador();
	cout << endl;

	cout << "Media das areas: " << soma_area / poligono::get_contador();
	cout << endl;



	return 0;
}
