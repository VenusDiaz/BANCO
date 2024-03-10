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
};