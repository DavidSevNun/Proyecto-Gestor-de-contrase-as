#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;

 bool validarNum(char op[]){
                int i;
                for (i=0; i<strlen(op); i++){

                    if((!(op[i]>=48 && op[i]<=57)&&op[i]!=46)){
                        cout<<endl;
                        cout<<"\tSOLO INGRESE NUMEROS"<<endl<<endl;
                        system("pause>>cls");
                         return false;

                    }
                    }
                return true;
                }
//----------------VALIDAR NUMEROS


void gotoxy(int x,int y){
      COORD c;
      c.X = x;
      c.Y = y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);

 }
//---------------GOTOXY

void Interfaz(){
    gotoxy(5,2); cout<<char(201)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(187);
    gotoxy(5,3); cout<<char(186);
    gotoxy(5,4); cout<<char(186); gotoxy(78,4); cout<<char(186); gotoxy(78,5); cout<<char(186);gotoxy(78,6); cout<<char(186); gotoxy(78,7); cout<<char(186);gotoxy(78,8); cout<<char(186); gotoxy(78,3); cout<<char(186);
    gotoxy(5,5); cout<<char(186);
    gotoxy(5,6); cout<<char(186);
    gotoxy(5,7); cout<<char(186);
    gotoxy(5,8); cout<<char(186);
    gotoxy(5,9); cout<<char(200)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(205)<<char(188);
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
    void Insertar(string,string);
    void modify();
    void LogIn(string,string);

    void mostrar();

};//--------CLASS LISTA


// Encriptado y decriptado XOR
string XOR(string dato){
	char key = 'K';
	string output = dato;
	
	for (int i= 0; i < dato.size(); i++)
	 output[i] = dato[i] ^ key;
	 
	return output;
}//------------------------------


void menu(){
int opc;
string aux,aux2,data;
lista list;

do{
    system("cls");
    Interfaz();        
    gotoxy(5,3); cout<<"\t\t           Ingrese una opcion";
    gotoxy(5,5); cout<<char(186);cout<<"[1]Ingresar password\t[2]Mostrar sitios\t[3]Modificar password";
    gotoxy(65,8); cout<<"[4]Salir";
    gotoxy(20,7); cout<<"Su opcion: ";
    cin>>opc;

    switch(opc){

        case 1:
            system("cls");
            Interfaz();
            gotoxy(20,3); cout<<"Ingrese el sitio:"; //pedirle al usuario el sitio
            gotoxy(20,5); cout<<"sitio: ";
            gotoxy(27,5);
            cin>>aux;
            for (int i=0;i<aux.length();i++){

                aux[i] = toupper(aux[i]);//Convertir string a mayusculas

            }

            system("cls");
            Interfaz();
            gotoxy(20,4); cout<<"Ingrese su password: ";
            gotoxy(20,6); cout<<"password: ";
            gotoxy(32,6);
            cin>>aux2;
            aux2 = XOR(aux2);
        
            list.Insertar(aux,aux2);
            system("pause");

        break;

        case 2:
        
            system("cls");
            list.mostrar();

        break;


        case 3:
            
            list.modify();

        break;



    }

}while(opc!=4);

}

void lista::modify(){
    system("cls");
    string aux,linea;
    ifstream file;
    

        if(head==nullptr){

            system("cls");
            Interfaz();
            gotoxy(25,6);    cout<<"Lista vacia";

        }else{

            Interfaz();
            gotoxy(5,3); cout<<"Ingrese el sitio: ";
            cin>>aux;

            for (int i=0;i<aux.length();i++){

                aux[i] = toupper(aux[i]);//Convertir string a mayusculas

            }

            if(file.is_open()){

                 while(!file.eof()){

                    while(getline(file,linea)){

                        if(linea == aux){ //buscar coincidencias dentro del txt. 

                            Nodo *ptr = head;
                              do{
                                if(ptr->sitio == aux){

                                    string pass;
                                    system("cls");
                                    Interfaz();
                                    gotoxy(25,6);
                                    cout<<"Ingrese la nueva password:\n";
                                    cin>>pass;
                                    ptr->pswrd = pass;

                                    }  

                                    ptr = ptr->next;
                                }while(ptr!=nullptr);

                            }else{
                                system("cls");
                                Interfaz();
                                gotoxy(25,6);    cout<<"No se encontro el sitio";

                            }
                        }
                    }
                file.close();    
                }//IF file open
        }//IF vacia

    
}


void lista::mostrar(){
    system("cls");
    Interfaz(); 
    gotoxy(15,2); cout<<"Sitios donde tiene passwords guardadas: ";
Nodo *list;
int i=1;
int cont = 0;
list = head;

    if(head!=nullptr){

        do{
                if(cont==4){

                    gotoxy(10,3); cout<<i<<".-"<<list->sitio<<endl;
                    cont = 0;

                }else{

                    cout<<i<<".-"<<list->sitio<<"  ";
                    cont++;
                }
            
            list = list->next;
            i++;
        }while(list!=nullptr);

        system("pause");

    }else{
        system("cls");
        Interfaz();
        gotoxy(30,6);        cout<<"Lista vacia\n";

    }
}//-------------MOSTRAR LISTA------------

void lista::RegistrarUsuario(){
system("cls");
Interfaz();
ofstream file;
string user,pswrd,txt;
file.open("LogIn.txt",fstream::out |fstream::app);

    if(file.is_open()){

        gotoxy(25,4); cout<<"Ingrese el nombre de usuario:";
        cin>>user;
        for (int i=0;i<user.length();i++){

            user[i] = toupper(user[i]);

         }

        gotoxy(25,6); cout<<"Ingrese su password:";
        cin>>pswrd;
        pswrd = XOR(pswrd);
        txt = user + " " + pswrd; 
        file<<txt<<endl;
        file.close();
    }
    
}

void lista::LogIn(string datos,string user){
ifstream file; 
string linea;
system("pause");
file.open("LogIn.txt",ios::in);

    if(file.is_open()){

        while(!file.eof()){

            while(getline(file,linea)){

                if(linea == datos){ //buscar dentro del txt.  datos es el usuario y contraseña ingresados
                    
                    system("cls");
                    Interfaz();
                    gotoxy(30,4); cout<<"Sesion iniciada";
                    gotoxy(30,6); cout<<"Bienvenido, "<<user<<endl;
                    gotoxy(25,8); system("pause");
                    menu();

                }else{
                    system("cls");
                    Interfaz();
                    cout<<"No se encontro el usuario\n";
                    cout<<"\t";system("pause");

                }
            }
        }
       file.close();    
    }else{
        system("cls");
        Interfaz();
        gotoxy(15,6); cout<<"No hay usuarios registrados...\n";
        gotoxy(20,8); system("pause");
    }
}


void lista::Insertar(string sitio,string pass){
string data;
Nodo *Nuevo = new Nodo();
ofstream file;

Nuevo->sitio = sitio;
Nuevo->pswrd = pass;

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
        data = sitio + " " + pass;
            
            file.open("contrasenas.txt",ios::out|ios::app);

            if(file.is_open()){

                file<<data<<endl;//guardar datos en txt

            }
    gotoxy(25,8); cout<<"Dato ingresado correctamente\n";
};//----------------------------------------------------Insertar nodo



//-----------------------------MAIN---------------------------
int main(){

system("color 07");
//gotoxy(30,5); imprimir en el centro de interfaz
lista list;
int opc;
char OPC[5];
bool val = false;
string user, pswrd,txt,aux;

do{
     do{
        system("cls");
        Interfaz();
        gotoxy(30,3); cout<<"[1]Log in\t[2]Sign in"; 
        gotoxy(65,8); cout<<"[3]Salir";
        gotoxy(35,6); cout<<"Opcion: [   ]"; gotoxy(45,6); cin>>OPC;
        
        val=validarNum(OPC);

    }while(val==false);

        opc=atoi(OPC);

    switch(opc){

    case 1:
        system("cls");
        Interfaz();
        gotoxy(20,3); cout<<"Ingrese su usuario: ";
        cin>>user;
        for (int i=0;i<user.length();i++){

            user[i] = toupper(user[i]);//Convertir string a mayusculas

         }

        gotoxy(20,5); cout<<"Ingrese su password: ";
        cin>>pswrd;
        aux = XOR(pswrd);
        txt = user + " " + aux;
        list.LogIn(txt,user);

    break;

    case 2:

        list.RegistrarUsuario();

    break;

    default:
            system("cls");
    break;

    }

}while(opc!=3);


return 0;}