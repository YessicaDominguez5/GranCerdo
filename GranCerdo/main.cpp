#include <iostream>
#include <clocale> //setlocale
#include <unistd.h> //sleep(3);
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

#include "GranCerdo.h"

using namespace std;



int main()
{
    setlocale(LC_ALL,"spanish"); // para caracteres especiales

    MostrarPresentacion();
    int mayorpuntosdevictoria = 0;
    string jugadorganador;

    char menu;

    bool salir;

    sleep(3); // frena 3 segundos la pantalla}

    while(!salir)
    {


        system("cls"); // limpia la pantalla anterior

        MostrarMenu();

        cin >> menu;

        switch(menu)
        {

        case '1':
        {

            jugar(mayorpuntosdevictoria, jugadorganador);

            break;
        }
        case '2':

            MostrarEstadistica(mayorpuntosdevictoria, jugadorganador);

            break;

        case '3':

            break;

        case '0':
            salir = true;
            break;

        default:

            system("cls");
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
            cout << "La opción es incorrecta" << endl;
            cout << "Intente de nuevo" << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;

            system("pause");
            break;
        }

    } // fin del while menu

     system("cls");
     MostrarDespedida();

    return 0;
}
