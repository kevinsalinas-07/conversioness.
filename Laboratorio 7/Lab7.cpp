#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void crearArchivo();
void leerArchivo(int numeros[], int &cantidad);
void clasificarNumeros(int numeros[], int cantidad);
void ordenarArchivo(string nombre);
void mostrarArchivo(string nombre);

int main()
{
    int numeros[200];
    int cantidad = 0;

    crearArchivo();
    leerArchivo(numeros, cantidad);
    clasificarNumeros(numeros, cantidad);

    cout << "\nContenido de pares.txt (antes de ordenar):\n";
    mostrarArchivo("pares.txt");

    cout << "\nContenido de impares.txt (antes de ordenar):\n";
    mostrarArchivo("impares.txt");

    ordenarArchivo("pares.txt");
    ordenarArchivo("impares.txt");

    cout << "\nContenido de pares.txt (ordenado):\n";
    mostrarArchivo("pares.txt");

    cout << "\nContenido de impares.txt (ordenado):\n";
    mostrarArchivo("impares.txt");

    return 0;
}

void crearArchivo()
{
    ofstream archivo("datos.txt");

    if (!archivo)
    {
        cout << "No se pudo crear datos.txt\n";
        return;
    }

    archivo << 10 << endl;
    archivo << 3 << endl;
    archivo << 8 << endl;
    archivo << 15 << endl;
    archivo << 2 << endl;
    archivo << 7 << endl;
    archivo << 12 << endl;
    archivo << 5 << endl;
    archivo << 1 << endl;
    archivo << 20 << endl;
    archivo << 50 << endl;
    archivo << 63 << endl;
    archivo << 34 << endl;
    archivo << 39 << endl;
    archivo << 26 << endl;
    archivo << 23 << endl;

    archivo.close();
    cout << "Archivo datos.txt creado con 16 numeros.\n";
}

void leerArchivo(int numeros[], int &cantidad)
{
    ifstream archivo("datos.txt");

    if (!archivo)
    {
        cout << "No se pudo abrir datos.txt\n";
        return;
    }

    cantidad = 0;

    while (archivo >> numeros[cantidad])
        cantidad++;

    archivo.close();

    cout << "Se leyeron " << cantidad << " numeros.\n";
}

void clasificarNumeros(int numeros[], int cantidad)
{
    ofstream pares("pares.txt");
    ofstream impares("impares.txt");

    for (int i = 0; i < cantidad; i++)
    {
        if (numeros[i] % 2 == 0)
            pares << numeros[i] << endl;
        else
            impares << numeros[i] << endl;
    }

    pares.close();
    impares.close();

    cout << "Numeros clasificados en pares.txt e impares.txt\n";
}

void ordenarArchivo(string nombre)
{
    ifstream entrada(nombre);

    int datos[200];
    int n = 0;

    while (entrada >> datos[n])
        n++;

    entrada.close();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (datos[j] > datos[j + 1])
            {
                int temp = datos[j];
                datos[j] = datos[j + 1];
                datos[j + 1] = temp;
            }
        }
    }

    ofstream salida(nombre);

    for (int i = 0; i < n; i++)
        salida << datos[i] << endl;

    salida.close();
}

void mostrarArchivo(string nombre)
{
    ifstream archivo(nombre);
    int num;

    while (archivo >> num)
        cout << num << endl;

    archivo.close();
}
