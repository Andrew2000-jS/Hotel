#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

using namespace std;

struct ClientData
{
    char firstName[20];
    char lastName[20];
    char address[100];
    unsigned int CI;
    unsigned int phoneNumber;
};

ClientData clientData;

void gotoxy(int x, int y);
void menu();
void validar(int Max_op, int mn);
void guardarTxT(ClientData clientData);
void efecto();
void modul_Habitac();
void modul_Reserv();
void modul_busqueda();
void agregar_cliente();

int valor, T = 10;
bool seguir = true, error = false;
char val[50];

int main()
{
    menu();
    return 0;
}

// Función para establecer el menú
void menu()
{
    do
    {
        efecto();
        // opciones
        gotoxy(30, 3);
        cout << "Menu de Opciones	";
        gotoxy(30, 4);
        cout << "----------------";
        gotoxy(25, 5);
        cout << "1. Modulo Registro de Habitaciones y clientes";
        gotoxy(25, 6);
        cout << "2. Modulo Registro de reservas y prereservas ";
        gotoxy(25, 7);
        cout << "3. Modulo Busqueda de habitaciones y clientes ";
        gotoxy(25, 8);
        cout << "4. Salir";
        gotoxy(25, 11);
        cout << "Escriba el numero de la opcion deseado :";
        cin >> val;
        // valido la entrada por el usuario
        validar(4, 1);
        switch (valor)
        {
        case 1:
            modul_Habitac();
            break;
        case 2:
            modul_Reserv();
            break;
        case 3:
            modul_busqueda();
            break;
        case 4:
            system("cls");
            efecto();
            gotoxy(30, 3);
            cout << "Gracias por utilizar el programa";
            seguir = false;
            break;
        }
    } while (seguir);
}

void modul_Habitac()
{
    do
    {
        efecto();
        // opciones
        gotoxy(26, 3);
        cout << " Modulo Registro de Habitaciones y clientes	";
        gotoxy(26, 4);
        cout << "-------------------------------------------";
        gotoxy(25, 5);
        cout << "1. Registrar cliente ";
        gotoxy(25, 6);
        cout << "2. Registrar Habitaciones";
        gotoxy(25, 7);
        cout << "3. Registrar Tipos de Habitaciones";
        gotoxy(25, 8);
        cout << "4. atras";
        gotoxy(25, 10);
        cout << "Escriba el numero de la opcion deseado :";
        cin >> val;
        // valido la entrada por el usuario
        validar(4, 2);
        switch (valor)
        {
        case 1:
            efecto();
            agregar_cliente();
            break;
        case 2:
            break;

        case 3:
            break;
        case 4:
            menu();
            break;
        }
    } while (seguir);
}

void modul_Reserv()
{
    do
    {
        efecto();
        // opciones
        gotoxy(26, 3);
        cout << "Modulo Registro de reservas y prereservas	";
        gotoxy(26, 4);
        cout << "------------------------------------------";
        gotoxy(25, 5);
        cout << "1. Registrar prereserva ";
        gotoxy(25, 6);
        cout << "2. Registrar reserva";
        gotoxy(25, 7);
        cout << "3. Registrar cobro";
        gotoxy(25, 8);
        cout << "4. atras";
        gotoxy(25, 10);
        cout << "Escriba el numero de la opcion deseado :";
        cin >> val;
        // valido la entrada por el usuario
        validar(4, 2);
        switch (valor)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            menu();
            break;
        }
    } while (seguir);
}

void modul_busqueda()
{
    do
    {
        efecto();
        gotoxy(26, 3);
        cout << " Modulo de busqueda de habitaciones y clientes	";
        gotoxy(26, 4);
        cout << "-------------------------------------------";
        gotoxy(25, 5);
        cout << "1. Buscar habitaciones ";
        gotoxy(25, 6);
        cout << "2. Buscar clientes";
        gotoxy(25, 7);
        cout << "3. atras";
        gotoxy(25, 10);
        cout << "Escriba el numero de la opcion deseado :";
        cin >> val;
        validar(3, 2);
        switch (valor)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            menu();
            break;
        }
    } while (seguir);
}

void efecto()
{
    system("cls");
    // Col_ini - final , Fil_ini - final
    int ci = 14, cf = 75, fi = 1, ff = 14;
    // iterador
    int o;
    // ciclo para las colunnas
    //===========================================================================================================
    for (o = ci; o <= cf; o++)
    {
        Sleep(T); // hace que el programa tarde unos milisegundos para ejecutar (da el efecto de mivimiento)
        // dibuja la colunna inicial
        gotoxy(o, fi);
        cout << "ß";
        // dibuja la colunna final
        gotoxy(o, ff);
        cout << "ß";
    }
    // ciclo para las filas
    for (o = fi; o <= ff; o++)
    {
        Sleep(T);
        // dibuja la fila inicial
        gotoxy(ci, o);
        cout << "Û";
        // dibuja la fila final
        gotoxy(cf, o);
        cout << "Û";
    }
    // para borrar el caracter sobresaliente
    gotoxy(ci, ff);
    cout << "ß";
    gotoxy(cf, ff);
    cout << "ß";
    //===========================================================================================================
}

void validar(int Max_op, int mn)
{
    valor = atoi(val);
    //==========================================================================
    if (valor > 0)
    {
        if (valor > Max_op)
        {
            gotoxy(25, 11);
            cout << "Debe de escoger un valor valido entre 1 y " << Max_op;
            getch();
            T = 0;
            error = true;
        }
        error = false;
    }
    else
    {
        gotoxy(25, 11);
        cout << "por favor digite numeros";
        getch();
        T = 0;
        error = true;
    }
    //==========================================================================
    // restablesco el menu correspondiente en el error
    if (error)
    {
        switch (mn)
        {
        case 1:
            menu();
            break;
        case 2:
            modul_Habitac();
            break;
        case 3:
            modul_Reserv();
            break;
        }
    }
}

void agregar_cliente()
{
    gotoxy(26, 3);
    cout << "Nombre del cliente: ";
    cin >> clientData.firstName;
    gotoxy(26, 4);
    cout << "Apellido del cliente: ";
    cin >> clientData.lastName;
    gotoxy(26, 5);
    cout << "Numero de telefono: ";
    cin >> clientData.phoneNumber;
    gotoxy(26, 6);
    cout << "Cedula: ";
    cin >> clientData.CI;
    gotoxy(26, 7);
    cout << "Direccion: ";
    cin >> clientData.address;
    gotoxy(26, 8);
    guardarTxT(clientData);
}

void showClient()
{
    cout << "Nombre : " << clientData.firstName << endl;
    cout << "Apellido : " << clientData.lastName << endl;
    cout << "Telefono : " << clientData.phoneNumber << endl;
    cout << "Cedula : V" << clientData.CI << endl;
}

void guardarTxT(ClientData clientData)
{
    ofstream file;                                                          // declarar archivo de la libreria
    file.open("C:/Users/andre/OneDrive/Escritorio/Clientes.txt", ios::app); // abrir archivo
    // edito
    file << "\n"
         << clientData.firstName << endl;
    file << clientData.lastName << endl;
    file << clientData.address << endl;
    file << clientData.CI << endl;
    file << clientData.phoneNumber;
    gotoxy(26, 10);
    cout << "Cliente agregado correctamente";
    system("pause>nul");
    file.close();
    getch();
}

// funcion gotoxy
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}