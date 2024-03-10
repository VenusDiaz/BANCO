#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Banco
{
private:
    string id;
    vector<string> ventanillasIds;
    string supervisorDeVentanillasId;
    vector<string> empleadosIds;

public:
    Banco(string idParam) // idParam = 234231
    {
        id = idParam;
        cout << "Se creo banco con ID: " << id << endl;
    };

    string getId()
    {
        return id;
    }
};