#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Jogador {
    public:
        Jogador(int number
                , std::string name
                , std::string position) : m_number{number}
                                        , m_name{name}
                                        , m_position{position} {}
        void PrintTitulares() {
            std::cout << "_____________________________________________"<< std::endl;
            std::cout << m_number << "," << m_name << "," << m_position << std::endl;
        }

        void PrintSuplentes() {
            std::cout << "_____________________________________________"<< std::endl;
            std::cout << m_number << "," << m_name << "," << m_position << std::endl;
        }
        int getNumber() const;
        std::string getName() const;
        std::string getPostition() const;
        void addPlayerTitulares(Jogador Valor);
        void addPlayerSuplentes(Jogador valor);

    protected:
        int m_number = -1;
        int op{-1};
        std::string m_name;
        std::string m_position;
//    private:
//        int m_number = -1;
//        std::string m_name;
//        std::string m_position;
private:
         std::vector<Jogador> titulares;
         std::vector<Jogador> suplentes;
};

//Getters

int Jogador::getNumber() const {
    return m_number;
}
std::string Jogador::getName() const {
    return m_name;
}
std::string Jogador::getPostition() const {
    return m_position;
}

void Jogador::addPlayerTitulares(Jogador valor) {
  titulares.push_back(valor);
}

void Jogador::addPlayerSuplentes(Jogador valor) {
  suplentes.emplace_back(valor);
}

int main() {
    int op = -1;
    std::vector<Jogador> titulares;
    std::vector<Jogador> suplentes;
    while(true){
        std::cout << std::endl;
        std::cout << " (1)Carregar Titulares - (2)Carregar Suplentes " << std::endl;
        std::cout << " (3) Mostrar Titulares - (4) Mostrar Suplentes" << std::endl;
        std::cout << " (5) Expulsar Jogador  - (6) Subtituição Jogador" << std::endl;
        std::cout <<"Opção: " << std::endl;
        std::cin >> op;
           if(op == 1){
            std::cout << "Carregando Titulares......." << std::endl;
            std::ifstream in;
            std::ofstream out;
            out.open("FutHistorico.txt", std::ios_base::app);
            in.open("FutTeamA.txt");
            while(!in.eof()) {
                int number = -1;
                std::string name;
                std::string position;

                in >> number >> name >> position;

                out << number << " " << name << " " << position << std::endl;

                titulares.emplace_back(number, name, position);
            std::cout << "Titulares Carregados OK..." << std::endl;
            std::cout << std::endl;
            }// while in.eof() titulares
           } else if(op == 2){
               std::cout << "Carregando Suplentes......." << std::endl;
               std::ifstream in;
               std::ofstream out;
               in.open("FutSupA.txt");
               while(!in.eof()) {
                   int number = -1;
                   std::string name;
                   std::string position;

                   in >> number >> name >> position;

                   out << number << " " << name << " " << position << std::endl;

                   suplentes.emplace_back(number, name, position);

                   std::cout << "Suplentes Carregados OK..." << std::endl;
                   std::cout << std::endl;
               }//while in.eof() suplentes
           } else if (op == 3){
                std::cout << "Lista de Titulares" << std::endl;
                for(auto jogador : titulares) jogador.PrintTitulares();
//               for (size_t i = 0; i < titulares.size(); ++i) {
//                  std::cout << i << ". "
//                            << titulares[i].getNumber() << " "
//                            << titulares[i].getName() << " "
//                            << titulares[i].getPostition() << std::endl;
//               } //for titulares
           } else if (op == 4){
               std::cout << "Lista de Suplentes" << std::endl;
               for(auto jogador : suplentes) jogador.PrintSuplentes();
               for (size_t i = 0; i < suplentes.size(); ++i) {
                  std::cout << i << ". "
                            << suplentes[i].getNumber() << " "
                            << suplentes[i].getName() << " "
                            << suplentes[i].getPostition() << std::endl;
               }// for suplentes
           } else if (op == 5){
               for(auto jogador : titulares) jogador.PrintTitulares();
                   std::cout << std::endl;

                   int bye = -1;
                   std::cout << "Entre o numero do jogador a Expulsar: " << std::endl;
                   std::cin >> bye;
                   std::cout << "Expulsando jogador.... " << bye << std::endl;
                   std::vector<Jogador>::iterator it = titulares.begin();
                   for( ; it != titulares.end(); it++) {
                       if ((*it).getNumber() == bye) {
                           break;
                       }
                   }
                   titulares.erase(it);
                   for(auto jogador : titulares) jogador.PrintTitulares();
                   std::cout << std::endl;
                   std::cout << "OK Jogador: "<< bye << " Foi Expulso" << std::endl;
           } else if (op == 6){
               std::string name;
               std::string position;
               for(auto jogador : titulares) jogador.PrintTitulares();
                   std::cout << std::endl;
                   int number = -1;
                   //sai jogador para o banco
                   std::cout << "Entre o numero nome e posição do jogador a Sair: (5 jog5 defesa) :" << std::endl;
                   std::cin >> number >> name >> position;
                   std::cout << "Saindo jogador.... " << number << std::endl;
                   std::vector<Jogador>::iterator it = titulares.begin();
                   for( ; it != titulares.end(); it++) {
                       if ((*it).getNumber() == number) {
                           break;
                       }
                   }
                   titulares.erase(it);
                   for(auto jogador : titulares) jogador.PrintTitulares();
                     std::cout << std::endl;
                     for(auto jogador : suplentes) jogador.PrintSuplentes();
                     std::cout << std::endl;
                    std::cout << std::endl;
                    std::cout << "OK Jogador: "<< number << " "<< name <<" "<< position <<" Foi para o banco de Suplentes" << std::endl;
                   suplentes.emplace_back(number,name,position);
                   for(auto jogador : suplentes) jogador.PrintSuplentes();
                      //Entra jogador do banco para o campo
                       std::cout << std::endl;
                       std::cout << "Entre o numero nome e posição do jogador a Entrar: (5 jog5 defesa) :" << std::endl;
                       std::cin >> number >> name >> position;
                       std::cout << "Entrando jogador.... " << number << std::endl;
                       std::vector<Jogador>::iterator ite = suplentes.begin();
                       for( ; ite != suplentes.end(); ite++) {
                           if ((*ite).getNumber() == number) {
                               break;
                           }
                       }
                       suplentes.erase(it);
                       //Entra jogador do banco para o campo
                       for(auto jogador : suplentes) jogador.PrintSuplentes();
                         std::cout << std::endl;
                         for(auto jogador : titulares) jogador.PrintTitulares();
                         std::cout << std::endl;
                        std::cout << std::endl;
                        std::cout << "OK Jogador: "<< number << " "<< name <<" "<< position <<" Entrou a jogar..." << std::endl;
                       titulares.emplace_back(number,name,position);
           }else if (op == 7){
               break;
           }
     }//while true

    return EXIT_SUCCESS;
}











