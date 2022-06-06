#include <iostream>
#include <stdlib.h>

using namespace std;

unsigned int ClientId = 0;

struct ClientData
{
    unsigned int id;
    char CI[15];
    char firstName[20];
    char lastName[20];
    char address[100];
    unsigned int phoneNumber;
};

struct Room
{
    unsigned int id;
    char description[100];
    int type;
    double price;
};

ClientData *clientData = new ClientData[50];

unsigned int findClient(unsigned int id)
{
    for (int i = 0; i <= ClientId; i++)
    {
        if (clientData[i].id == id)
        {
            return clientData[i].id;
        }
    }
}

void AddPerson()
{
    cout << "Ingrese nombre del cliente: ";
    cin >> clientData[ClientId].firstName;
    cout << "Ingrese apellido del cliente: ";
    cin >> clientData[ClientId].lastName;
    cout << "Ingrese numero de telefono: ";
    cin >> clientData[ClientId].phoneNumber;

    clientData[ClientId].id = ClientId;
    clientData[ClientId].id = ClientId++;
}

void showClient(unsigned int id)
{
    unsigned int index = findClient(id);
    cout << "Nombre : " << clientData[index].firstName << endl;
    cout << "Apellido : " << clientData[index].lastName << endl;
    cout << "Telefono : " << clientData[index].phoneNumber << endl;
}

void menu()
{
    unsigned int opt = 0;
    bool repeat = true;
    unsigned int clientId;

    do
    {

        system("cls");
        cout << "-----------------------------------------------------------------HOTEL-----------------------------------------------------------------" << endl;
        cout << "\n\n\t\t\tMenu de Opciones" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\t1. Agregar cliente" << endl;
        cout << "\t2. Buscar cliente" << endl;
        cout << "\t3. Mostrar todos los clientes" << endl;
        cout << "\t4. Ver habitaciones disponibles" << endl;
        cout << "\t5. Eliminar cliente" << endl;
        cout << "\t6. Salir" << endl;
        cout << "\n\tIngrese una opcion: ";
        cin >> opt;
        system("cls");
        // Ejecutar la opcion seleccionada
        switch (opt)
        {
        case 1:
            system("cls");
            AddPerson();
            cout << "Cliente agregado" << endl;
            system("pause>nul");
            break;
        case 2:
            system("cls");
            cout << "Ingrese el id del cliente: ";
            cin >> clientId;
            showClient(clientId);
            system("pause>nul");
            break;
        default:
            repeat = false;
            cout << "Adios";
            break;
        }
    } while (repeat);
};

int main()
{
    menu();
    return 0;
}
