#include <iostream>
#include <string>
using namespace std;

struct Direccion
{
    string calle;
    int numero;
    string ciudad;
};

struct Estudiante
{
    string nombre;
    int edad;
    float calificaciones[5];
    Direccion direccion;
};

void ingresarEstudiantes(Estudiante estudiantes[], int *cantidad);
void mostrarEstudiantes(Estudiante estudiantes[], int cantidad);
void buscarEstudiante(Estudiante estudiantes[], int cantidad);
void modificarEstudiante(Estudiante estudiantes[], int cantidad);

int main()
{
    Estudiante estudiantes[100];
    int cantidad = 0;
    int opcion;

    do
    {
        cout << "\n Menu de estudiantes: \n";
        cout << "1. Agregar estudiante\n";
        cout << "2. Ver lista de estudiantes\n";
        cout << "3. Buscar estudiante\n";
        cout << "4. Modificar datos de estudiante\n";
        cout << "5. Salir\n";
        cout << "Eligi una opcion por favor: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            ingresarEstudiantes(estudiantes, &cantidad);
            break;
        case 2:
            mostrarEstudiantes(estudiantes, cantidad);
            break;
        case 3:
            buscarEstudiante(estudiantes, cantidad);
            break;
        case 4:
            modificarEstudiante(estudiantes, cantidad);
            break;
        case 5:
            cout << "\nSaliendo... gracias por usar el programa!\n";
            break;
        default:
            cout << "\nEsa opcion no existe, probá otra.\n";
        }

    } while (opcion != 5);

    return 0;
}

void ingresarEstudiantes(Estudiante estudiantes[], int *cantidad)
{
    int n;
    cout << "\nCuantos estudiantes queres ingresar? ";
    cin >> n;

    for (int i = *cantidad; i < *cantidad + n; i++)
    {
        cout << "\nEstudiante " << i + 1 << ":\n";
        cout << "Nombre (sin espacios): ";
        cin >> estudiantes[i].nombre;
        cout << "Edad: ";
        cin >> estudiantes[i].edad;

        cout << "Ingresa las 5 notas:\n";
        for (int j = 0; j < 5; j++)
        {
            cout << "Nota " << j + 1 << ": ";
            cin >> estudiantes[i].calificaciones[j];
        }

        cout << "Calle (sin espacios): ";
        cin >> estudiantes[i].direccion.calle;
        cout << "Numero de casa: ";
        cin >> estudiantes[i].direccion.numero;
        cout << "Ciudad (sin espacios): ";
        cin >> estudiantes[i].direccion.ciudad;
    }

    *cantidad += n;
    cout << "\nListo, se guardaron los datos!\n";
}

void mostrarEstudiantes(Estudiante estudiantes[], int cantidad)
{
    if (cantidad == 0)
    {
        cout << "\nNo hay estudiantes guardados todavia.\n";
        return;
    }

    cout << "\n Estudiantes registrados! \n";
    for (int i = 0; i < cantidad; i++)
    {
        cout << "\nEstudiante #" << i + 1 << endl;
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Edad: " << estudiantes[i].edad << endl;
        cout << "Notas: ";
        for (int j = 0; j < 5; j++)
        {
            cout << estudiantes[i].calificaciones[j];
            if (j < 4)
                cout << ", ";
        }
        cout << "\nDireccion: " << estudiantes[i].direccion.calle << " "
             << estudiantes[i].direccion.numero << ", "
             << estudiantes[i].direccion.ciudad << endl;
    }
}

void buscarEstudiante(Estudiante estudiantes[], int cantidad)
{
    if (cantidad == 0)
    {
        cout << "\nNo hay estudiantes guardados todavia.\n";
        return;
    }

    string nombreBuscado;
    cout << "\nEscribi el nombre del estudiante que queres buscar: ";
    cin >> nombreBuscado;

    bool encontrado = false;
    for (int i = 0; i < cantidad; i++)
    {
        if (estudiantes[i].nombre == nombreBuscado)
        {
            cout << "\nEstudiante encontrado:\n";
            cout << "Nombre: " << estudiantes[i].nombre << endl;
            cout << "Edad: " << estudiantes[i].edad << endl;
            cout << "Notas: ";
            for (int j = 0; j < 5; j++)
            {
                cout << estudiantes[i].calificaciones[j];
                if (j < 4)
                    cout << ", ";
            }
            cout << "\nDireccion: " << estudiantes[i].direccion.calle << " "
                 << estudiantes[i].direccion.numero << ", "
                 << estudiantes[i].direccion.ciudad << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
    {
        cout << "\nNo se encontro ningun estudiante con ese nombre.\n";
    }
}

void modificarEstudiante(Estudiante estudiantes[], int cantidad)
{
    if (cantidad == 0)
    {
        cout << "\nNo hay estudiantes guardados todavia.\n";
        return;
    }

    string nombreBuscado;
    cout << "\nDecime el nombre del estudiante que queres editar: ";
    cin >> nombreBuscado;

    bool encontrado = false;
    for (int i = 0; i < cantidad; i++)
    {
        if (estudiantes[i].nombre == nombreBuscado)
        {
            cout << "\nEstudiante encontrado, ingresa los nuevos datos:\n";
            cout << "Nuevo nombre (sin espacios): ";
            cin >> estudiantes[i].nombre;
            cout << "Nueva edad: ";
            cin >> estudiantes[i].edad;

            cout << "Nuevas 5 notas:\n";
            for (int j = 0; j < 5; j++)
            {
                cout << "Nota " << j + 1 << ": ";
                cin >> estudiantes[i].calificaciones[j];
            }

            cout << "Nueva calle (sin espacios): ";
            cin >> estudiantes[i].direccion.calle;
            cout << "Nuevo numero: ";
            cin >> estudiantes[i].direccion.numero;
            cout << "Nueva ciudad (sin espacios): ";
            cin >> estudiantes[i].direccion.ciudad;

            cout << "\nListo, datos actualizados!\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
    {
        cout << "\nNo hay ningun estudiante con ese nombre.\n";
    }
}
