#include <iostream>
#include <fstream>
#include <filesystem>
#include "windows.h"

void crearArchivos(int cantidad);
int contarArchivosDeDirectorio();
void listarArchivosDeDirectorio();
void mostrarDetalles();

using namespace std;

int main()
{
    int cantidad;

    cout << "Cuantos archivos quiere crear \n";
    cin >> cantidad;
    crearArchivos(cantidad);
    cout << contarArchivosDeDirectorio();
    cout << "\n";
    listarArchivosDeDirectorio();
    mostrarDetalles();

    return 0;
}

void crearArchivos(int cantidad) {
    string nombreArchivo="documento";
    int i= cantidad, linea;
    for(i=0; i<cantidad; i++){
        ofstream file;
        file.open("C:\\Users\\alumno\\Desktop\\Progra\\" + nombreArchivo + to_string(i) +".txt");
        // Agregar líneas según el número de archivo
        for (int j = 1; j <= i; j++) {
            file << "Línea " << j << endl;
        }

        file.close();
    }
    cout << "Archivos creados: " << i - 1 << endl;
}


void listarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    hFind = FindFirstFile("C:\\Users\\alumno\\Desktop\\Progra\\*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "Ruta incorrecta";
    else
    {
        cout << findFileData.cFileName << '\n'; //El primer archivo
        // Listamos todos los archivos

        while (FindNextFile(hFind, &findFileData) != 0)
            cout << findFileData.cFileName << '\n';
    }
}

int contarArchivosDeDirectorio(){
    WIN32_FIND_DATA findFileData;
    HANDLE          hFind;
    int cantidadDeArchivos=0;
    hFind = FindFirstFile("C:\\Users\\alumno\\Desktop\\Progra*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE)
        cout << "Ruta incorrecta";
    else
        while (FindNextFile(hFind, &findFileData)!=0){
            cantidadDeArchivos=cantidadDeArchivos+1;

        }
    return cantidadDeArchivos-1;
}

void mostrarDetalles(){
    std::filesystem::directory_iterator directoryIterator("C:\\Users\\alumno\\Desktop\\Progra");
    for (const auto& entry : directoryIterator) {
        if (!std::filesystem::is_directory(entry.status())) {
            std::cout << entry.path().filename() << " "
                      << file_size(entry.path()) << std::endl;
        }
    }
}
