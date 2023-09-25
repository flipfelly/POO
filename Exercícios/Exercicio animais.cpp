#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Animal{

    public:
        string nome;
        int idade;

        Animal(string _nome, int _id){
            nome = _nome;
            idade = _id;
        }
        ~Animal(){}

        void setnome(string _nome);
        string getnome ();

        void setidade(int _id);
        int getidade();
};

class Papagaio : public Animal{
        
        float envergadura;
        string falante;

        public:

        Papagaio(float _en, string _fa, string _nome, int _id):Animal(_nome, _id){ // inicia nome e idade de animal para que nao haja a necessidade de declaração
            envergadura = _en;
            falante = _fa;
        }
        ~Papagaio(){}

        void setenvergadura(float _en);
        float getenvergadura();

        void setfalante(string _fa);
        string getfalante();

         void Mostra_papagaio(){
            cout<< "Dados papagaio:" << endl;
            cout<<"Nome: "<< nome << endl;
            cout<< "Idade: "<< idade << endl;
            cout<< "Envergadura: "<< envergadura << endl;
            cout<< "É falante? : "<< falante << endl;
        }

};

class Gato : public Animal{
        
        string pelugem;
        float unhas;

        public:

        Gato(string _pe, float _unhas, string _nome, int _id):Animal(_nome, _id){
            pelugem = _pe;
            unhas = _unhas;
        }
        ~Gato(){}

        void setpelugem(string _pe);
        string getpelugem();

        void setunhas(float _unhas);
        float getunhas();

        void Mostra_gato(){
            cout<< "Dados Gato:" << endl;
            cout<<"Nome: "<< nome << endl;
            cout<< "Idade: "<< idade << endl;
            cout<< "Pelugem: "<< pelugem << endl;
            cout<< "Tamanho unhas: "<< unhas << endl;
        }

};

int main(){

    int animal, quantidade = 100;

    cout<<"Qual Animal deseja cadastrar?"<< endl << "1-Papagaio" << endl << "2-Gato"<<endl;
    cin>>animal;


    Papagaio* papagaio[quantidade];
    Gato* gato [quantidade];

    string nome, resp;
    int idade, i=0;
    float envergadura, unhas;
    string falante, pelugem;


    switch(animal){
        case 1:
            do{
                cout<< "Digite o nome do papagaio: "<<endl;
                cin>> nome;
                cout<< "Digite a idade do papagaio: "<<endl;
                cin>> idade;
                cout << "Digite a envergadura do papagaio; "<<endl;
                cin>> envergadura;
                cout<<"O papagaio é falante?"<<endl;
                cin>> falante;
                
                papagaio[i] = new Papagaio(envergadura, falante, nome, idade);
                i++;

                cout<< "deseja cadastrar mais um papagaio?"<<endl;
                cin>> resp;


        }while (resp == "s" || resp =="S");
        break;
        case 2:
            do{
                cout<< "Digite o nome do gato: "<<endl;
                cin>> nome;
                cout<< "Digite a idade do gato: "<<endl;
                cin>> idade;
                cout << "Digite o tipo de pelagem do gato: "<<endl;
                cin>> pelugem;
                cout<<"Digite o tamanho das unhas do gato: "<<endl;
                cin>> unhas;
                
                gato[i] = new Gato(pelugem, unhas, nome, idade);
                i++;

                cout<< "deseja cadastrar mais um gato?"<<endl;
                cin>> resp;

        }while (resp == "s" || resp =="S");
        break;     
            
    }

    //papagaio[1]->Mostra_papagaio();
    gato[1]->Mostra_gato();






    return 0;
}

