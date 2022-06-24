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

    char menu, confirmacion;

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

            system("cls");

            cout << "Nombre del grupo: Pig Plus Plus" << endl << endl;
            cout << "Integrantes:" << endl << endl;
            cout << "Dominguez Yessica Natalia - legajo 25475" << endl << endl;
            cout << "D'Orazio Nicolás - legajo 24963" << endl << endl;
            cout << "Fernandez Franco - legajo 25901" << endl << endl;
            cout << "Vega Santiago Tomás - legajo 24577" << endl << endl;

            system("pause");

            break;

        case '0':
            cout << "¿Está seguro que desea salir? S/N" << endl;
            cin >> confirmacion;
            confirmacion = toupper(confirmacion);
            if(confirmacion == 'S')
            {
                salir = true;

            }
            else if(confirmacion == 'N')
            {



            }
            else
            {

                cout << "opción incorrecta" << endl;
                system("pause");


            }

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
