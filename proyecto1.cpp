#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

// Clase contenida
struct TPunto
{
    string n;
    float x;
    float y;
   
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
        void agregarPunto(string n, float x, float y)
        {
            listaPuntos.push_back({n, x, y});
            grabarArchivo();
           
        }
        void listarPuntos()
        {
            if (listaPuntos.size()>100)
            do
            {
                for (auto punto: listaPuntos)
                    cout << punto.n << " (" << punto.x << ", " << punto.y << ")" << endl;               
            }
            while (listaPuntos.size()<=100);
            else
            {
                for (auto punto: listaPuntos)
                    cout << punto.n << " (" << punto.x << ", " << punto.y << ")" << endl;
            }
          
        }
        void eliminarPuntoPorNombre(string n) //Moverse de atras para adelante en el vector
        {
            for (int i = listaPuntos.size() -1; i >=0; i--)
            {
                if (listaPuntos[i].n == n)
                    listaPuntos.erase(listaPuntos.begin()+i);
            }
            grabarArchivo();
           
        }
        void listarPuntosCercanos()
        {
            for (auto punto: listaPuntos)
                if (sqrt(punto.x*punto.x+punto.y*punto.y)<=10)
                    cout << punto.n << " (" << punto.x << ", " << punto.y << ")" << endl;
        }
        
        void grabarArchivo()
        {
            // Creando el archivo
            ofstream archivo(nombreArchivo);
            archivo << "Nombre, posX, posY" << endl;
            for (auto punto: listaPuntos)
                archivo << punto.n << ", "<< punto.x << ", " << punto.y << endl;
            archivo.close();
        }
       void leerArchivo()
        {
            ifstream archivo(nombreArchivo);
            vector<string> datos;
            string texto;
            while (getline(archivo, texto))
            {
                datos.push_back(texto);
            }
            archivo.close();
        }
        void distancia()
        {
            for (auto punto: listaPuntos)
                if (sqrt(punto.x*punto.x+punto.y*punto.y)<=10)
                {
                    cout << punto.n << " (" << punto.x << ", " << punto.y << ")" << endl;
                }
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
        cout << "3. Listar 100 primeros puntos. "<< endl;
        cout << "4. Listar los puntos ubicados a menos de 10 metros. "<< endl;
        cout << "5. Calcular la distancia promedio entre cada punto. "<< endl;
        cout << "6. Determinar la distancia entre los puntos mas lejanos. "<< endl;
        cout << "7. Determinar la distancia más corta entre los puntos. "<< endl;
        cout << "8. "<< endl;
        cout << "9. "<< endl;


        
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
        float x,y;
        string n;
    
        // Creamos un switch de opciones
        switch (opcion)
        {
            case 1:
                system("clear");
                cout << "Ingrese el nombre del Punto: "; cin >> n;
                cout << "Ingrese el valor de X: "; cin >> x;
                cout << "Ingrese el valor de Y: "; cin >> y;
                mapa.agregarPunto(n,x,y);
                
                break;
            case 2: 
                system("clear");
                cout << "Ingrese el nombre del punto a borrar: "; cin >> n;
                mapa.eliminarPuntoPorNombre(n);
                
                break;
            case 3:
                system("clear");
                cout << "Los 100 primeros puntos son: " << endl;
                mapa.listarPuntos();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.get();
                
                break;
            case 4:
                system("clear");
                cout << "Los puntos ubicados a menos de 10 metros son: " << endl;
                mapa.listarPuntosCercanos();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.get();
                           
                break;
            case 5:
                system("clear");
                cout << "La distancia promedio entre cada punto es: " << endl;
                
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
            case 6:
                system("clear");
                cout << "La distancia entre los puntos mas lejanos es: " << endl;
                
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
            case 7:
                system("clear");
                cout << "La distancia entre los puntos mas cercanos es: " << endl;
                
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
            case 8:
                system("clear");
                cout << "FALTA LLENAR" << endl;
                
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
            case 9:
                system("clear");
                cout << "FALTA LLENAR" << endl;
                
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cin.get();
                break;
                
        }
    }
     while (opcion !=0);
        
    return 0;
}