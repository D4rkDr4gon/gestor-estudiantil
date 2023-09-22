#include<iostream>
#include<string.h>
#include<string>
using namespace std;

//Declaracion de estructuras
struct Beneficio{
	char nombre[50];
	int costo;
};
struct Aux{
        char nombreBeneficio[50];
        char nuevoNombre[50];
        int nuevoCosto;
};
//Variables globales
Beneficio beneficio;
Aux aux;

//Prototipo de funcion
void agregar_beneficio();
void listar_beneficio();
void modificar_beneficio();
void eliminar_beneficio();

//Funcion principal
int main(){
int opc;

//Menu de pantalla de beneficios
        cout<<"Gestor de beneficios               ";              
        cout<<"\n 1. Agregar                      ";
        cout<<"\n 2. Listar                       ";
        cout<<"\n 3. Modificar costo/nombre       ";
        cout<<"\n 4. Eliminar                     ";
        cout<<"\n 5. Salir                        ";
        cout<<"\n---------------------------------";
        cout<<"\nOperacion: ";
//Opciones de beneficios
do{
    cin>>opc;
    cin.ignore();
	switch(opc){
		case 1: agregar_beneficio();                        break;
		case 2: listar_beneficio();                         break;
		case 3: modificar_beneficio();                      break;
		case 4: eliminar_beneficio();                       break;
		case 5: cout<<"\nDatos actualizados exitosamente";
                cout<<"\n---------------------------------";break;
		default: cout<<"\nOpcion invalida, por favor ingrese"; 
		         cout<<"\nuna nueva operacion: ";break;
	} 
}while(opc != 5);
}

//Definicion de funcion
void agregar_beneficio(){
    bool band = false;
			    
	FILE* archivo = fopen("Registros_Beneficios.dat","ab");
    	if(archivo == NULL){
            cout<<"\nNo se pudo abrir el archivo.";
            cout<<"\n---------------------------------";
	    	cout<<"\nNueva operacion: ";
            band = true;
        }
    
    if(band == false){
        cout<<"Nombre: ";
     	cin.getline(beneficio.nombre,sizeof(beneficio.nombre));
    	cout<<"Costo: ";
    	cin>>beneficio.costo;
        cin.ignore();

        fwrite(&beneficio,sizeof(Beneficio),1,archivo);
		fclose(archivo);
	    	cout<<"\nBeneficio agregado con exito";
            cout<<"\n---------------------------------";
	    	cout<<"\nNueva operacion: ";
    }
}

void listar_beneficio(){
    bool band = false;

    FILE* archivo = fopen("Registros_Beneficios.dat","rb");
    if(archivo == NULL){
        cout<<"\nNo se pudo abrir el archivo.";
        cout<<"\n---------------------------------";
		cout<<"\nNueva operacion: ";
        band = true;
    }

    if(band == false){
	    while(fread(&beneficio,sizeof(Beneficio),1,archivo) == 1){
            cout<<"Nombre: "<<beneficio.nombre<<", Costo: "<<beneficio.costo<<endl;
        }
            cout<<"\n---------------------------------";
        	cout<<"\nNueva operacion: ";
        fclose(archivo);
    }
}

void modificar_beneficio(){
    bool band=false;
    
    FILE* archivo = fopen("Registros_Beneficios.dat", "rb+");
    if (archivo == NULL) {
        cout<<"\nNo se pudo abrir el archivo.";
        cout<<"\n---------------------------------";
        cout<<"\nNueva operacion: ";
        band = true;
    }

    if(band == false){
    
    cout<<"Nombre del beneficio a modificar: ";
    cin.getline(aux.nombreBeneficio, 50);
    cout<<"Nuevo nombre: ";
    cin.getline(aux.nuevoNombre, 50);
    cout<<"Nuevo costo: ";
    cin>>aux.nuevoCosto;

    cin.ignore();

    bool buscar = false;
       while (fread(&beneficio, sizeof(Beneficio), 1, archivo) == 1){
            if (strcmp(beneficio.nombre,aux.nombreBeneficio) == 0){
                
                // Modificar el nombre y el costo
                strcpy(beneficio.nombre, aux.nuevoNombre);
                beneficio.costo = aux.nuevoCosto;
                buscar = true;
                
                // Mueve la posición actual de lectura/escritura hacia atrás para sobrescribir el registro
                fseek(archivo, -static_cast<long>(sizeof(Beneficio)), SEEK_CUR);
                fwrite(&beneficio, sizeof(Beneficio), 1, archivo);
                break; // Termina la búsqueda ya que se encontró y modificó el beneficio
            }
        }

     fclose(archivo);

        if(buscar == true) {
            cout<<"\nBeneficio modificado con exito.";
            cout<<"\n---------------------------------";
            cout<<"\nNueva operacion: ";
        }else {
            cout<<"\nBeneficio no encontrado.";
            cout<<"\n---------------------------------";
            cout<<"\nNueva operacion: ";
        }
    }
}

void eliminar_beneficio(){
    bool band = false;

    FILE* archivo = fopen("Registros_Beneficios.dat", "rb+");
        if(archivo == NULL){
            cout<<"\nNo se pudo abrir el archivo.";
            cout<<"\n---------------------------------";
	    	cout<<"\nNueva operacion: ";
           band = true;
        }       

    if(band == false){
        cout<<"Nombre del beneficio a eliminar: ";
        cin.getline(aux.nombreBeneficio,50);
        cin.ignore();

        FILE* archivoTemporal = fopen("temporal.dat", "wb+");  
    
        bool buscar = false;

        while(fread(&beneficio.nombre, sizeof(Beneficio), 1, archivo) == 1){
            if(strcmp(beneficio.nombre, aux.nombreBeneficio) != 0){
                fwrite(&beneficio.nombre, sizeof(Beneficio), 1, archivoTemporal);
                buscar = true;
            }
        }
            fclose(archivo);
            fclose(archivoTemporal);

            if(buscar == true){
                if(remove("Registros_Beneficios.dat") == 0 &&
                    rename("temporal.dat", "Registros_Beneficios.dat") == 0){
                    cout<<"\nBeneficio eliminado con exito.";
                    cout<<"\n---------------------------------";
	    	        cout<<"\nNueva operacion: ";
                }else{
                    cout<<"\nError al renombrar el archivo.";
                    cout<<"\n---------------------------------";
	    	        cout<<"\nNueva operacion: ";
                }
            }else{
                cout<<"\nBeneficio no encontrado.";
                cout<<"\n---------------------------------";
	        	cout<<"\nNueva operacion: ";
                remove("temporal.dat"); // Eliminar el archivo temporal si no se realizó ninguna modificación.
            }
    }
}
