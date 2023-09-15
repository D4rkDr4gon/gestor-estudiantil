#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

//aumentar al cumplir ciertos logros:
//
//acreditar materia (100)
//promocionar materia (500)
//recursar materia (-500)
//equipo de inv (1000)
//trabajo (500)
//paso de nivel (1500) (todas las materias del nivel acreditadas)

struct Logros{
    string nombre;
    string descripcion;
    int ganancias;
};


void NuevoLogro(){
    Logros logros;
    //abro el archivo
    FILE* archivo = fopen("Logros.txt", "at+");
    //reviso si existe el archivo
    if(archivo == nullptr){
        cout << "No se encontro el archivo" << endl;
    }
    //creo nuevo logro y lo asigno a la variable
    cout << "crear nuevo logro: " << endl;
    cout << "Ingrese el nombre del logro: ";
    getline(cin, logros.nombre);
    cout << "Ingrese la descripcion del logro: ";
    getline(cin, logros.descripcion);
    cout << "Ingrese cuantos meritos obtiene del logro: ";
    cin >> logros.ganancias;

    fwrite(&logros, sizeof(Logros), 1, archivo);
    fclose(archivo);
    }



int main(){
    NuevoLogro();

    return 0;
}