
//-------------Prueba1
#include<iostream>
#include<cstdlib>

using namespace std;



class Nodo{
    public:
    string pswrd;
    Nodo *next;

} *head=nullptr, *tail=nullptr;
//------------------CLASS NODO------------

class lista{
    private:
    Nodo *head=nullptr;
    Nodo *tail=nullptr;

public:

    void Insertar(string);
    void modify();

    void mostrar();

};//--------CLASS LISTA

void lista::mostrar(){

Nodo *list;
int i=1;

list = head;

if(head!=nullptr){
    do{

        cout<<i<<".-"<<list->pswrd<<endl;
        list = list->next;
        i++;
    }while(list!=nullptr);
    system("pause");

}cout<<"Lista vacia\n";

}//-------------MOSTRAR LISTA------------


void lista::Insertar(string contra){

Nodo *Nuevo = new Nodo();
Nuevo->pswrd = contra;

    if(head==nullptr)
    {
        head = Nuevo;
        head->next = nullptr;
        tail = Nuevo;

    }else{

        tail->next = Nuevo;
        Nuevo->next = nullptr;
        tail = Nuevo;
    }

    cout<<"Dato ingresado correctamente\n";
};//-----------Insertar nodo


void menu(){
int opc;
string aux;
lista list;

do{
cout<<"\n\n\nIngrese una opcion\n";
cout<<"[1]Ingresar contrasena\t[2]Mostrar contrasenas\t[3]Salir\n\n";
cout<<"Su opcion: ";
cin>>opc;

    switch(opc){

    case 1:
    system("cls");
        cout<<"Ingrese la contrasena: \n";
        cin>>aux;
        list.Insertar(aux);
    break;

    case 2:
        system("cls");
        list.mostrar();

    break;


    }

}while(opc!=3);

}


int main(){
system("color 70");

menu();


return 0;}