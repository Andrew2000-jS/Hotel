#include <iostream>
using namespace std;

unsigned int ClientId = 0;

struct ClientData
{
    unsigned int id;
    char firstName[20];
    char lastName[20];
    unsigned int phoneNumber;
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

int main()
{
    AddPerson();
    showClient(0);

    return 0;
}
