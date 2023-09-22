#include <iostream>
#include <string>
using namespace std;

// Declaración de estructuras
struct Beneficio {
    string nombre;
    int costo;
};

struct Aux {
    string nombreBeneficio;
    string nuevoNombre;
    int nuevoCosto;
};

// Variables globales
Beneficio beneficio;
Aux aux;

// Prototipo de funciones
void agregar_beneficio();
void listar_beneficio();
void modificar_beneficio();
void eliminar_beneficio();

// Función principal
int main() {
    int opc;

    do {
        // Menu de pantalla de beneficios
        cout << "\nGestor de beneficios             ";
        cout << "\n 1. Agregar                      ";
        cout << "\n 2. Listar                       ";
        cout << "\n 3. Modificar costo/nombre       ";
        cout << "\n 4. Eliminar                     ";
        cout << "\n 5. Salir                        ";
        cout << "\n---------------------------------";
        cout << "\nOperacion: ";
        // Opciones de beneficios
        cin >> opc;
        cin.ignore();
        switch (opc) {
            case 1:
                agregar_beneficio();
                break;
            case 2:
                listar_beneficio();
                break;
            case 3:
                modificar_beneficio();
                break;
            case 4:
                eliminar_beneficio();
                break;
            case 5:
                cout << "\nDatos actualizados exitosamente";
                cout << "\n---------------------------------";
                break;
            default:
                cout << "\nOpcion invalida, por favor ingrese";
                cout << "\nuna nueva operacion: ";
                break;
        }
    } while (opc != 5);

    return 0;
}

// Definicion de funcion
void agregar_beneficio() {
    bool band = false;
    FILE* archivo = fopen("logrosYbeneficios.txt", "ab");
    if (archivo == NULL) {
        cout << "\nNo se pudo abrir el archivo.";
        cout << "\n---------------------------------";
        cout << "\nNueva operacion: ";
        band = true;
    }
    if (band == false) {
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, beneficio.nombre);
        cout << "Costo: ";
        cin >> beneficio.costo;
        cin.ignore();

        fwrite(&beneficio, sizeof(Beneficio), 1, archivo);
        fclose(archivo);
        cout << "\nBeneficio agregado con exito";
        cout << "\n---------------------------------";
    }
}

void listar_beneficio() {
    bool band = false;
    FILE* archivo = fopen("logrosYbeneficios.txt", "rb");
    if (archivo == NULL) {
        cout << "\nNo se pudo abrir el archivo.";
        cout << "\n---------------------------------";
        band = true;
    }

    if (band == false) {
        while (fread(&beneficio, sizeof(Beneficio), 1, archivo) == 1) {
            cout << "Nombre: " << beneficio.nombre << ", Costo: " << beneficio.costo << endl;
        }
        cout << "\n---------------------------------";
        fclose(archivo);
    }
}

void modificar_beneficio() {
    bool band = false;
    FILE* archivo = fopen("logrosYbeneficios.txt", "rb+");
    if (archivo == NULL) {
        cout << "\nNo se pudo abrir el archivo.";
        cout << "\n---------------------------------";
        band = true;
    }

    if (band == false) {
        cout << "Nombre del beneficio a modificar: ";
        cin.ignore();
        getline(cin, aux.nombreBeneficio);
        cout << "Nuevo nombre: ";
        getline(cin, aux.nuevoNombre);
        cout << "Nuevo costo: ";
        cin >> aux.nuevoCosto;
        cin.ignore();

        bool buscar = false;
        while (fread(&beneficio, sizeof(Beneficio), 1, archivo) == 1) {
            if (beneficio.nombre == aux.nombreBeneficio) {
                // Modificar el nombre y el costo
                beneficio.nombre = aux.nuevoNombre;
                beneficio.costo = aux.nuevoCosto;
                buscar = true;
                // Mueve la posición actual de lectura/escritura hacia atrás para sobrescribir el registro
                fseek(archivo, -static_cast<long>(sizeof(Beneficio)), SEEK_CUR);
                fwrite(&beneficio, sizeof(Beneficio), 1, archivo);
                break; // Termina la búsqueda ya que se encontró y modificó el beneficio
            }
        }
        fclose(archivo);

        if (buscar == true) {
            cout << "\nBeneficio modificado con exito.";
            cout << "\n---------------------------------";
        } else {
            cout << "\nBeneficio no encontrado.";
            cout << "\n---------------------------------";
        }
    }
}

void eliminar_beneficio() {
    bool band = false;

    FILE* archivo = fopen("logrosYbeneficios.txt", "rb+");
    if (archivo == NULL) {
        cout << "\nNo se pudo abrir el archivo.";
        cout << "\n---------------------------------";
        band = true;
    }

    if (band == false) {
        cout << "Nombre del beneficio a eliminar: ";
        cin.ignore();
        getline(cin, aux.nombreBeneficio);
        bool buscar = false;

        FILE* archivoTemporal = fopen("temporal.txt", "wb+");
        while (fread(&beneficio, sizeof(Beneficio), 1, archivo) == 1) {
            if (beneficio.nombre != aux.nombreBeneficio) {
                fwrite(&beneficio, sizeof(Beneficio), 1, archivoTemporal);
                buscar = true;
            }
        }
        fclose(archivo);
        fclose(archivoTemporal);

        if (buscar == true) {
            if (remove("logrosYbeneficios.txt") == 0 && rename("temporal.txt", "logrosYbeneficios.txt") == 0) {
                cout << "\nBeneficio eliminado con exito.";
                cout << "\n---------------------------------";
            } else {
                cout << "\nError al renombrar el archivo.";
                cout << "\n---------------------------------";
            }
        } else {
            cout << "\nBeneficio no encontrado.";
            cout << "\n---------------------------------";
            remove("temporal.txt"); // Eliminar el archivo temporal si no se realizó ninguna modificación.
        }
    }
}
