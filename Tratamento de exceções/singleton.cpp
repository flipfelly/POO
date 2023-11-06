#include <iostream>

using std::cout;
using std::endl;

class singleton {
	static singleton* _instance;
	singleton(){}
public:
	static singleton* get_instance() {
		if (_instance == NULL) {
			_instance = new singleton();
		}
		return _instance;
	}
	void print_info() {
		cout << "singleton::print_info()" << endl;
	}

};

singleton* singleton::_instance = NULL;

int main(void) {
	cout << "Inicia execucao" << endl;

	singleton* s = singleton::get_instance();

	s->print_info();


}
