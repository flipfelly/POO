#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;

//const nao altera os atributos da classe
class Funcionario{

    string nome;
    int idade;

    public:
    Funcionario(string _no, int _id): nome(_no),idade(_id){}
    
    //gets e sets
    string getnome(string _no){return nome;}
    void setnome(string _no){nome = _no;}

    int getid(int _id){return idade;}
    void setidade(int _id){idade = _id;}

    virtual void exibir_detalhes(){
        cout << "Funcionario: " << endl;
        cout << "Nome: " << nome << endl;
        cout << "Idade: " << idade << endl;
    }

    friend ostream& operator <<(ostream& os, const Funcionario& funcionario){ //Sobrecarga do operador << 
        os << "Dados do funcionario: " << endl;
        os << "Nome: " << funcionario.nome << endl;
        os << "Idade: " << funcionario.idade << endl;

        return os;
    }

};

class Gerente : public Funcionario{ // classe gerente que herda publicamente de funcionario 
    
    string departamento;
    int nivel_acesso;

    public: 
    Gerente( string _no, int _id ,string _dep, int _ac) : Funcionario(_no,_id), departamento(_dep), nivel_acesso(_ac){}
    
    // gets e sets

    string getdep(){return departamento;}
    void setdep(string _dep){departamento = _dep;}

    int getac(){return nivel_acesso;}
    void setac(int _ac){nivel_acesso = _ac;}

    void exibir_detalhes() override{
        Funcionario::exibir_detalhes();
        cout << "Departamento: " <<  departamento << endl;
        cout << "Nivel de acesso: " << nivel_acesso << endl;
    }

    void def_nivel_acesso (int i){
        nivel_acesso = i;
    }
};

class Dev : protected Funcionario{

    string linguagem;

    public:
    Dev(string _no,int _id, string _li) : Funcionario(_no,_id), linguagem(_li){}

    // get e set
    string getli(){return linguagem;}
    void setli( string _li){linguagem = _li;}

    void exibir_detalhes() override{
        Funcionario::exibir_detalhes();
        cout << "Linguagem de programação: " << linguagem << endl;
    }

};

class Analista : private Funcionario{
    string proj_atual;

    public:
    Analista(string _no,int _id, string _pro) : Funcionario (_no,_id), proj_atual(_pro){}

    //get e set

    string getpro(){return proj_atual;}
    void setpro(string _pro){proj_atual = _pro;}

    void exibir_detalhes() override{
        Funcionario::exibir_detalhes();
        cout << "Projeto atual: " << proj_atual  << endl;
    }

    void alt_proj (const string& i){//Passagem por referencia 
        proj_atual = i;
    }
};

class Func_estagiario : public Dev, public Analista {//herança multipla
    int duracao_est;

    public:
    Func_estagiario(string _no,int _id, string _li, string _pro , int _du) : Analista(_no, _id, _pro), Dev(_no, _id, _li), duracao_est(_du){}

    //get e set
    int getdu( int _du){return duracao_est;}
    void setdu(int _du){duracao_est = _du;}

    void exibir_detalhes() override{
        cout << "Detalhes estagiario: " << endl;
        Analista::exibir_detalhes();
        cout << "Linguagem de programacao: " << getli() << endl;
        cout << "Duracao do estagio: " << duracao_est <<endl;

    }
};

int main (){
    
    Funcionario emp1("João", 30);
    Gerente ger1("Maria", 35, "TI", 1);
    Dev dev1("Carlos", 28, "C++");
    Analista ana1("Laura", 27, "Projeto A");
    Func_estagiario est1("Lucas", 22, "Java", "Projeto B", 6);

    est1.exibir_detalhes();
    cout<< endl;
    cout << emp1;
    cout<<endl;
    ger1.exibir_detalhes();
    cout<<endl;
    dev1.exibir_detalhes();
    cout<<endl;
    ana1.exibir_detalhes();

    return 0;
}