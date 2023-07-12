#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

typedef struct myfifo fifo;
struct myfifo{
  int cpf;
  string nome;
  string email;
  fifo * prox; //ponteiro para axuiliar
};
//ponteiro do tipo do strcut 
fifo *primeiro;
fifo *ultimo;

void construtor() {
    //Vai apontar para NULL
    primeiro = ultimo = NULL;
}
bool vazia() {
//se ultimou ou primeiro for nulo
    if(ultimo == NULL || primeiro == NULL)
    return true;
    else
    return false;
}

string inserirNome(){
    string nome1;
    cout << "Insira o seu NOME: " << endl;
    cin >> nome1;
    return nome1;
}
string inserirEmail(){
    string email1;
    cout << "Insira o seu E-MAIL: " << endl;
    cin >> email1;
    return email1; 
}
int inserirCpf(){
    int cpf1;
    cout << "Insira o seu CPF: " << endl;
    cin >> cpf1;
    return cpf1;
}
void inserir() {
    int mycpf;
    string mynome;
    string myemail;
    mynome = inserirNome();
    myemail = inserirEmail();
    mycpf = inserirCpf();
//COMANDO DE ALOCACAO DE MEMORIA DINANMICA 
    fifo * newfifo = (fifo*)malloc(sizeof(fifo));
    if (newfifo == NULL){
        cout << "Não tem mais memoria ... ERRO!\n" << endl;
        system("sleep 4");
        return;
    }
    
    //tratar atributos de dados
    newfifo -> nome = mynome;
    newfifo -> email = myemail;
    newfifo -> cpf = mycpf;
    //se for o primeiro numero aponta para NULL
    if ( vazia() == true ){
        primeiro = newfifo;//vai receber o primeiro
    }
    else {
        //se for o segundo em diante
        ultimo->prox = newfifo;
    }
    
    newfifo->prox = NULL;    
    ultimo = newfifo;

}
void remover(){
    //ponteiro temporario temp
    fifo *temp;
    if (vazia() == true) return;
    
    temp = primeiro;
    primeiro = temp -> prox;
    //free excluir
    free(temp);
}
void listar(){
    fifo *temp;
    temp = primeiro;
    system("clear");
    while(temp != NULL){
        cout << "NOME: " <<temp->nome << endl;
        cout << "E-MAIL: " <<temp->email << endl;
        cout << "CPF: " <<temp->cpf << endl;
        cout << "\n";
        //novo temp vai ser o proximo
        temp = temp->prox;
    }
    system("sleep 4");
}
void destrutor(){
    //ponteiro temporario
    fifo *temp, *aux;
    temp = primeiro;
    system("clear");
    while(temp != NULL){
        aux = temp;
        //novo temp vai ser o proximo
        temp = temp -> prox;
        free(aux);
    }
    cout << "Fila destruida...!\n" << endl;
    system("sleep 4");
}
int menu(){
    int item;
    system("clear");
    cout << "**** MENU ****" << endl;
    cout << "\n1- Insira\n2- Remover\n3- Exibir\n4-Sair" << endl;
    cout << "Item>";
    cin >> item;
    return item;
}
void controle() {
construtor();
    do{
        switch(menu()){
            case 1:
           inserir();
            break;
            case 2:
            remover();
            break;
            case 3:
            listar();
            break;
            case 4:
            exit(0);
            break;
            default:
            cout << "EROO!";
            break;
        }
    }while(true);
    destrutor();
} 
int main(){
    setlocale(LC_ALL,"Portuguese");
    controle();
    destrutor();
    return 0;
}