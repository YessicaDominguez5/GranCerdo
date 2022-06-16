#include <iostream>
#include <clocale>
#include <unistd.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;
#include "GranCerdo.h"


// presentación
void MostrarPresentacion()
{
    cout << "*********************************************************************************************************" << endl;
    cout << "*********************************************************************************************************" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                                        BIENVENIDOS                        ^^--                      **" << endl;
    cout << "**                                                                        E  °    .                    **" << endl;
    cout << "**                                            AL                           .       . ~                 **" << endl;
    cout << "**                                                                          w . w./                    **" << endl;
    cout << "**                                        GRAN CERDO                                                   **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "*********************************************************************************************************" << endl;
    cout << "*********************************************************************************************************" << endl;
}




//Menú

void MostrarMenu()
{

    cout << "*********************************************************************************************************" << endl;
    cout << "*********************************************************************************************************" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                                           GRAN CERDO                                                **" << endl;
    cout << "**                      ----------------------------------------------------------                     **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                                          1 - JUGAR                                                  **" << endl;
    cout << "**                                          2 - ESTADÍSTICAS                                           **" << endl;
    cout << "**                                          3 - CERDITOS                                               **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                      ----------------------------------------------------------                     **" << endl;
    cout << "**                                          0 - SALIR                                                  **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "*********************************************************************************************************" << endl;
    cout << "*********************************************************************************************************" << endl;


}



// ¿Quién empieza el juego?

int QuienEmpieza()
{
    int vecdados1[2];
    int vecdados2[2];
    int acu1 = 0, acu2 = 0, mayordado1 = 0, mayordado2 = 0;
    int jugador = 0;
    bool salir = true;

    while (salir)
    {

        for (int i = 0 ; i < 2; i++ )
        {
            vecdados1[i] = (rand()% 6) + 1;
            acu1 += vecdados1[i];
            cout << "Dado " << i + 1 << " del cerdo 1: " << vecdados1[i] << endl;
            cout << "----------------------" << endl;

        }
        for (int i = 0 ; i < 2; i++ )
        {
            vecdados2[i] = (rand()% 6) + 1;
            acu2 += vecdados2[i];
            cout << "Dado " << i + 1 << " del cerdo 2: " << vecdados2[i] << endl;
            cout << "----------------------" << endl;

        }


        if(acu1 > acu2)
        {
            jugador = 1;
            salir = false;

        }

        else if (acu2 > acu1)
        {

            jugador = 2;
            salir = false;

        }
        else
        {
            if (vecdados1[0] > vecdados1[1])
            {

                mayordado1 = vecdados1[0];

            }
            else
            {
                mayordado1 = vecdados1[1];
            }


            if (vecdados2[0] > vecdados2[1])
            {

                mayordado2 = vecdados2[0];

            }
            else
            {
                mayordado2 = vecdados2[1];
            }

            if(mayordado1 > mayordado2)
            {

                jugador = 1;
                salir = false;


            }
            else if (mayordado2 > mayordado1)
            {
                jugador = 2;
                salir = false;

            }


        }
    } // fin del while
    return jugador;
}
