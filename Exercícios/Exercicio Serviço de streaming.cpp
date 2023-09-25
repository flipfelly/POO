#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

#define QNT 3 

class Musica{
    string titulo;
    string artista;
    public:
        Musica(string _ti,string _art): titulo(_ti), artista(_art) {} //inicalização dos atributos
        
        //get e set
        string getti(){ return titulo; }
        void setti(string _ti){ titulo = _ti; }

        string getart(){ return artista; }
        void setart(string _art){ artista = _art; }

        virtual void tocar() = 0; //função virtual pura

        
};

class MusicaLocal: public Musica{
    string caminho;

    public:
    MusicaLocal(string _cam, string _ti, string _art): caminho(_cam), Musica(_ti,_art){}; //Inicialização dos atributos
    
    //get e set
    string getcam(string _cam){return caminho;}
    void setcam(string _cam){caminho = _cam;}

    void tocar(){
        cout<<"Tocando:"<<endl;
        cout<< "Titulo: " << getti() << endl;
        cout<< "Artista: " << getart() << endl;
        cout<< "Caminho do arquivo: " << caminho<<endl;
    }


};

class MusicaStreaming: public Musica{
    string url;

    public:
    MusicaStreaming(string _ur, string _ti, string _art): url(_ur), Musica(_ti,_art){}

    //get e set

    string getur(string _ur){return url;}
    void setur(string _ur){url = _ur;}

    void tocar(){
        cout<<"Tocando:"<<endl;
        cout<< "Titulo: " << getti() << endl;
        cout<< "Artista: " << getart() << endl;
        cout<< "Url do arquivo: " << url <<endl;
    }
};

int main(){

    MusicaLocal* musica[QNT];

    MusicaStreaming* musica1[QNT];

    int val;

    cout<<"Deseja cadastrar musicas onde? \n 1- Local \n 2- Online"<<endl;
    cin >> val;



    for (int i = 0; i<QNT; i++){
        if (val == 1){

            string titu,caminho,artista;

            cout<<"Digite o título da musica: "<<endl;
            //getline(cin, titu); não estava funcionando
            cin>>titu;

            cout<<"Digite o artista: "<<endl;
            //getline(cin,artista);
            cin>>artista;

            cout<<"Digite o caminho da musica: "<< endl;
            //getline(cin,caminho);
            cin>>caminho;

            musica[i] = new MusicaLocal(caminho,titu,artista);
        }
        else if (val ==2){
           
            string tit,url,artista;

            cout<<"Digite o título da musica: ";
            //getline(cin,tit);
            cin>> tit;

            cout<<"Digite o artista: "<<endl;
            //getline(cin,artista);
            cin>> artista;

            cout<<"Digite o url da musica: "<<endl;
            //getline(cin,url);
            cin>> url;

            musica1[i] = new MusicaStreaming(url,tit,artista);
        
        }
    }
    for (int i = 0; i < QNT; i++) {
		musica[i]->tocar();
	}
    //for (int i = 0; i < QNT; i++) {
		//musica1[i]->tocar();
	//}






    return 0;
}