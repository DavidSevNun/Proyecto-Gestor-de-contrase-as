#include<iostream>
#include<cstdlib>
#include <conio.h>
#include<windows.h>
#include <string>
using namespace std;

void gotoxy(int x,int y){
      COORD c;
      c.X = x;
      c.Y = y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);

 }
//---------------GOTOXY

void Interfaz(){
    gotoxy(5,2); cout<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(187);
    gotoxy(5,3); cout<<char(186);
    gotoxy(5,4); cout<<char(186); gotoxy(70,4); cout<<char(186); gotoxy(70,5); cout<<char(186);gotoxy(70,6); cout<<char(186); gotoxy(70,7); cout<<char(186);gotoxy(70,8); cout<<char(186); gotoxy(70,3); cout<<char(186);
    gotoxy(5,5); cout<<char(186);
    gotoxy(5,6); cout<<char(186);
    gotoxy(5,7); cout<<char(186);
    gotoxy(5,8); cout<<char(186);
    gotoxy(5,9); cout<<char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(188);
    gotoxy(32,7);
}//--------Interfaz


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
    gotoxy(25,8); cout<<"Dato ingresado correctamente";
};//-----------Insertar nodo


void menu(){
system("cls");
Interfaz();
int opc;
string aux;
lista list;

do{
    gotoxy(5,3); cout<<"\t\t           Ingrese una opcion";
    gotoxy(5,5); cout<<char(186);cout<<"\t[1]Ingresar password\t[2]Mostrar passwords\t[3]Salir";
    gotoxy(20,7); cout<<"Su opcion: ";

cin>>opc;

    switch(opc){

    case 1:
    system("cls");
        Interfaz();
        gotoxy(20,3); cout<<"Ingrese su password: \n";
        gotoxy(20,5); cout<<"Pswrd:________________________________";
        gotoxy(32,5);
        cin>>aux;
        list.Insertar(aux);
        system("pause");
    break;

    case 2:
        system("cls");
        list.mostrar();

    break;
    }

}while(opc!=3);

}



int main(){
system("cls");
system("color 07");
//gotoxy(30,5); imprimir en el centro de interfaz

int opc;
do{
Interfaz();
gotoxy(25,3); cout<<"[1]Log in\t[2]Sign in";
gotoxy(30,6); cout<<"Opcion: [   ]"; gotoxy(40,6); cin>>opc;

    switch(opc){

    case 1:
        menu();
    break;

    case 2:



    break;

    default:
        gotoxy(30,5); cout<<"Opcion no valida";
    break;

    }

}while(opc!= 1 && opc!=2);

return 0;}