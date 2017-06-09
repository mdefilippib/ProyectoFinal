#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

// Clase contenida
struct TPunto
{
    int x;
    int y;
    string nombre;
};

// Clase contenedor
class CMapa
{
    string nombreArchivo;
    string ciudad;
    vector<TPunto> listaPuntos; // Agregar puntos relacion 1 a muchos
    public:
    
        // Declaracion de constructores
        CMapa()
        {
            ciudad = "Lima";
            nombreArchivo = "datos.txt";
        }
        
        CMapa(string ciudad, string nombreArchivo)
        {
            this->ciudad = ciudad;
            this->nombreArchivo = nombreArchivo;
        }
        
        // Metodos de Procesamiento
        void agregarPunto(string nombre, int x, int y)
        {
            listaPuntos.push_back({nombre, x,y});
            grabarArchivo();
        }
        void listarPuntos()
        {
            leerArchivo();
            for (auto punto: listaPuntos)
                cout << "Punto x,y = (" << nombre << punto.x << ", " << punto.y << ")" << endl;
            

        }
        void eliminarPuntoPorX(int x) //Moverse de atras para adelante en el vector
        {
            for (int i = listaPuntos.size() -1; i >=0; i--)
            {
                if (listaPuntos[i].x == x)
                    listaPuntos.erase(listaPuntos.begin()+i);
            }
            grabarArchivo();
        }
        
        void grabarArchivo()
        {
            // Creando el archivo
            ofstream archivo(nombreArchivo);
            archivo << "posX, posY" << endl;
            for (auto punto: listaPuntos)
                archivo << punto.x << ", " << punto.y << endl;
            archivo.close();
        }
        
          void leerArchivo()
        {
            // Creando el archivo
            ifstream archivo(nombreArchivo);
            archivo << "posX, posY" << endl;
            for (auto punto: listaPuntos)
                archivo << punto.x << ", " << punto.y << endl;
            archivo.close();
        }
};

// Metodo Menu
int menu()
{
     int opcion = 0;
     
    do
    {
        system ("clear");
        cout << "MENU" << endl;
        cout << string(4, '~') << endl << endl;
        
        cout << "1. Agregar una nueva posición." << endl;
        cout << "2. Eliminar una posición por nombre." <<  endl;
        cout << "3. Listar 100 primeros puntos. "<< endl
        cout << "4. Listar los puntos ubicados a menos de 10 metros. "<< endl
        cout << "5. Calcular la distancia promedio entre cada punto. "<< endl
        cout << "6. Determinar la distancia entre los puntoss mas lejanos. "<< endl
        cout << "7. Determinar la distancia más corta entre los puntos. "<< endl
        cout << "8.  "<< endl
        cout << "9.  "<< endl


        
        cout << "0. Para salir" << endl <<  endl;
        cout << "Opcion : ";
        cin >> opcion;
        return opcion;
    }
    while (opcion < 0 || opcion > 9);
}

int main()
{
    CMapa mapa;       // Mapa de Lima
    int opcion = 0;
    do 
    {
        opcion = menu();    // Opcion del menu
        int x,y;
        string nombre;
        // Creamos un switch de opciones
        switch (opcion)
        {
            case 1:
                system("clear");
                cout << "Ingrese el valor de X: "; cin >> x;
                cout << "Ingrese el valor de Y: "; cin >> y;
                mapa.agregarPunto(x,y);
                break;
            case 2: 
                system("clear");
                cout << "Ingrese el nombre del punto a borrar: "; cin >> nombre;
                mapa.eliminarPuntoPorX(x);
                break;
            case 3:
                system("clear");
                mapa.listarPuntos();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
            case 4:
                system("clear");
                cout << "Los 100 primeros puntos son: ";
                break;
            case 5:
                system("clear
                cout << "Los puntos ubicados a menos de 10 metros son: ";
                break;
            case 6:
                system("clear");
                cout << "La distancia promedio es: ";
                break;
            case 7:
                system("clear");
                cout << 
                break;
            case 8:
                system("clear");
                break;
            case 9:
                system("clear");
                break;
                
        }
    }
     while (opcion !=0);
        
    return 0;
}