#include <iostream>
using namespace std;
int main()
{

    int numsecreto = 777, numintento;
    do
    {
        cout << "ingresa un numero entero" << endl;
        cin >> numintento;
        if (numintento == numsecreto)
        {
            cout << "Adinivinaste el numero! " << endl;
        }
        else if (numintento > numsecreto)
        {
            cout << "El numero ingresado es muy alto" << endl;
        }
        else
        {
            cout << " El numero ingresado es muy bajo" << endl;
        }

    } while (numsecreto != numintento);

    return 0;
}