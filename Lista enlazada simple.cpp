#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <string>
#include <fstream>
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
    string usuario;
    string pswrdUsuario;
    string sitio;
    string pswrd;
    Nodo *next;

} *head=nullptr, *tail=nullptr;
//------------------CLASS NODO------------

class lista{
    private:
    Nodo *head=nullptr;
    Nodo *tail=nullptr;

public:
    void RegistrarUsuario();
    void Insertar(string);
    void modify();
    void LogIn(string);

    void mostrar();

};//--------CLASS LISTA

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
        gotoxy(20,3); cout<<"Ingrese su password: \n"; //pedirle al usuario el sitio
        gotoxy(20,5); cout<<"Pswrd:________________________________";
        gotoxy(32,5);
        cin>>aux;
        //encriptar, return pswrd encriptada y mandarla a insertar();
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

void lista::mostrar(){
Nodo *list;
int i=1;

list = head;

    if(head!=nullptr){

        do{

            cout<<i<<".-"<<list->sitio<<endl;
            list = list->next;
            i++;
        }while(list!=nullptr);

        system("pause");

    }cout<<"Lista vacia\n";
}//-------------MOSTRAR LISTA------------

void lista::RegistrarUsuario(){
system("cls");
Interfaz();
ofstream file;
string user,pswrd,txt;
file.open("contrasenas.txt",fstream::out |fstream::app);

    if(file.is_open()){

        gotoxy(25,4); cout<<"Ingrese el nombre de usuario:";
        cin>>user;
        gotoxy(25,6); cout<<"Ingrese su password:";
        cin>>pswrd;
        txt = user + " " + pswrd; //Ya creada la funcion de encriptado, mandarle desde aqui los datos y guardarlos en el txt
        //file<<txt<<endl;
        file.close();
    }
    menu();
}

void lista::LogIn(string datos){
system("cls");
Interfaz();
ifstream file; 
string linea;
file.open("contrasenas.txt",fstream::out |fstream::app);

    if(file.is_open()){

        while(!file.eof()){

            while(getline(file,linea)){

                if(linea == datos){ //buscar dentro del txt.  datos es el usuario y contraseña ingresados

                    gotoxy(25,4); cout<<"Sesion iniciada";
                    menu();

                }else{

                    cout<<"No se encontro";

                }
            }
        }
       file.close();    
    }
}


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





int main(){
system("cls");
system("color 07");
//gotoxy(30,5); imprimir en el centro de interfaz
lista list;
int opc;
string user, pswrd,txt;
do{
Interfaz();
gotoxy(25,3); cout<<"[1]Log in\t[2]Sign in";
gotoxy(30,6); cout<<"Opcion: [   ]"; gotoxy(40,6); cin>>opc;

    switch(opc){

    case 1:
        gotoxy(25,3); cout<<"Ingrese su usuario: ";
        cin>>user;
        gotoxy(25,5); cout<<"Ingrese su password: ";
        cin>>pswrd;
        txt = user + " " + pswrd;
        list.LogIn(txt);

    break;

    case 2:

        list.RegistrarUsuario();

    break;

    default:
        gotoxy(30,5); cout<<"Opcion no valida";
    break;

    }

}while(opc!= 1 && opc!=2);

return 0;}