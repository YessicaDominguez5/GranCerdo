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


void jugar()
{
    string cerdo1, cerdo2;

    //nombre de los participantes
    cout << endl << "Ingresar nombre del cerdo: ";
    cin >> cerdo1;
    cout << endl;
    cout << endl << "Ingresar nombre del otro cerdo: ";
    cin >> cerdo2;
    cout << endl;

    system("cls");//limpia la pantalla

    //tirar dados para saber quién empieza
    srand(time(NULL)); // motor de generador de números
    int cerdo;
    string cerdoaux;

    cerdo = QuienEmpieza();

    cout << endl << "............................" << endl << endl;
    cout << "  Empieza el cerdo: " << endl;
    if (cerdo == 1)
    {
        cout << endl << "    " << cerdo1 << endl;
    }
    else
    {
        cout << endl << "    " << cerdo2 << endl;
        cerdoaux = cerdo1;
        cerdo1 = cerdo2;
        cerdo2 = cerdoaux; //para que el cerdo que empieza sea siempre el cerdo 1

    }

    cout << endl << "............................" << endl;
    cout << endl << "                            " << endl;


    int acutrufastotalesc1 = 0, acutrufastotalesc2 = 0, acutrufaslanzamientos = 0, contlanzamientos1 = 0,contlanzamientos2 = 0, vecrandnum[3] = {}, acutrufasronda1 = 0, acutrufasronda2 = 0;
    char continuar;
    string cerdoactual;
    bool noContinuar, bandera, hundido = false, conTres;



    for(int r = 1 ; r <= 5; r ++) // Rondas
    {
        acutrufaslanzamientos = 0;
        contlanzamientos1 = 0;
        contlanzamientos2 = 0;
        acutrufasronda1 = 0;
        acutrufasronda2 = 0;

        for(int c = 1; c <= 2; c++) // Jugadores
        {
            noContinuar = false;


            if(c == 1)
            {

                cerdoactual = cerdo1;

            }
            else
            {
                cerdoactual = cerdo2;
            }

            while(!noContinuar)
            {
                if (!bandera)
                {

                    system("pause");
                    continuar = 'S';
                    bandera = true;
                }
                else
                {

                    cout << "¿CONTINUAR? (S/N) " << endl;
                    cin >> continuar;
                    continuar = toupper(continuar);
                }

                switch(continuar)
                {

                case 'S':

                    system("cls");
                    if(c == 1)
                    {
                        contlanzamientos1++;
                    }
                    else
                    {
                        contlanzamientos2++;
                    }


                    if((acutrufastotalesc1 < 50 && acutrufastotalesc2 < 50)||(!hundido)) //jugar con 2 dados
                    {

                        for (int i = 0; i < 2; i++)
                        {
                            vecrandnum[i] = 0;

                            vecrandnum[i] = (rand()% 6)+ 1;

                        }
                    }
                    else
                    {
                        conTres = true;


                        for (int i = 0; i < 3; i++) // jugar con 3 dados
                        {

                            vecrandnum[i] = 0;

                            vecrandnum[i] = (rand()% 6)+ 1;


                        }
                    }
                    MostrarTablero(acutrufastotalesc1, acutrufastotalesc2, cerdo1, cerdo2, cerdoactual, r);
                    if (cerdoactual == cerdo1)
                    {
                        cout << "  TRUFAS DE LA RONDA: " << acutrufasronda1 << endl;
                    }
                    else
                    {
                        cout << "  TRUFAS DE LA RONDA: " << acutrufasronda2 << endl;
                    }

                    cout << "                                                                                                         " << endl;
                    if(cerdoactual == cerdo1)
                    {
                        cout << "       LANZAMIENTOS: " << contlanzamientos1 - 1 << endl;
                    }
                    else
                    {
                        cout << "       LANZAMIENTOS: " << contlanzamientos2 - 1 << endl;
                    }
                    cout << "                                                                                                         " << endl;


                    if(!conTres) // si hay que jugar con 2 dados
                    {

                        if((vecrandnum[0] != vecrandnum[1]) && (vecrandnum[0] != 1) && (vecrandnum[1] != 1)) // caras distintas y ninguna es as
                        {
                            acutrufaslanzamientos = vecrandnum[0] + vecrandnum[1];
                            if (cerdoactual == cerdo1)
                            {
                                acutrufastotalesc1 += acutrufaslanzamientos;
                                acutrufasronda1 += acutrufaslanzamientos;
                            }
                            else
                            {
                                acutrufastotalesc2 += acutrufaslanzamientos;
                                acutrufasronda2 += acutrufaslanzamientos;
                            }

                        }
                        else if((vecrandnum[0] == vecrandnum[1]) && (vecrandnum[0] != 1) && (vecrandnum[1] != 1)) // caras iguales y ninguna es as
                        {
                            cout << "                                 " << endl;
                            cout << "**********************" << endl;
                            cout << "OINK del cerdo " << cerdoactual << endl;
                            cout << "********************** " << endl;

                            acutrufaslanzamientos = (vecrandnum[0] * 2) + (vecrandnum[1] * 2);

                            if (cerdoactual == cerdo1)
                            {
                                acutrufastotalesc1 += acutrufaslanzamientos;
                                acutrufasronda1 += acutrufaslanzamientos;
                            }
                            else
                            {
                                acutrufastotalesc2 += acutrufaslanzamientos;
                                acutrufasronda2 += acutrufaslanzamientos;
                            }

                            bandera = false;

                        }
                        else if ((vecrandnum[0] != vecrandnum[1]) && ((vecrandnum[0] == 1) || (vecrandnum[1] == 1))) // caras distintas y hay un as
                        {


                            if (cerdoactual == cerdo1)
                            {
                                acutrufaslanzamientos = 0;
                                acutrufasronda1 += acutrufaslanzamientos;
                                acutrufastotalesc1 -= acutrufasronda1;
                                acutrufasronda1 = 0;


                            }
                            else
                            {
                                acutrufaslanzamientos = 0;
                                acutrufasronda2 += acutrufaslanzamientos;
                                acutrufastotalesc2 -= acutrufasronda2;
                                acutrufasronda2 = 0;



                            }
                            bandera = false;



                        }

                        else if ((vecrandnum[0] == 1) && (vecrandnum[1] == 1))// caras iguales  son ases
                        {

                            cout << "                                 " << endl;
                            cout << "************************************" << endl;
                            cout << "CERDO "<< cerdoactual <<" HUNDIDO EN EL BARRO!" << endl;
                            cout << "                                 " << endl;
                            cout << "************************************" << endl;

                            if (cerdoactual == cerdo1)
                            {
                                acutrufaslanzamientos = 0;
                                acutrufastotalesc1 = 0;
                                acutrufasronda1 = 0;
                            }
                            else
                            {
                                acutrufaslanzamientos = 0;
                                acutrufastotalesc2 = 0;
                                acutrufasronda2 = 0;
                            }

                            bandera = false;
                            hundido = true;
                        }
                    }
                    else   //se juega con 3 dados
                    {

                        // caras distintas y ninguna es as
                        if((vecrandnum[0] != vecrandnum[1]) && (vecrandnum[0] != vecrandnum[2])&&(vecrandnum[1] != vecrandnum[2])&&(vecrandnum[0] != 1) && (vecrandnum[1] != 1)&&(vecrandnum[2] != 1)
                    {
                        acutrufaslanzamientos = vecrandnum[0] + vecrandnum[1] + vecrandnum[2];
                            if (cerdoactual == cerdo1)
                            {
                                acutrufastotalesc1 += acutrufaslanzamientos;
                                acutrufasronda1 += acutrufaslanzamientos;
                            }
                            else
                            {
                                acutrufastotalesc2 += acutrufaslanzamientos;
                                acutrufasronda2 += acutrufaslanzamientos;
                            }

                        }
                        // caras iguales y ninguna es as
                        else if((vecrandnum[0] == vecrandnum[1]) && (vecrandnum[0] == vecrandnum[2])&&(vecrandnum[0] != 1) && (vecrandnum[1] != 1)&& (vecrandnum[2] != 1))
                    {
                        cout << "                                 " << endl;
                        cout << "**********************" << endl;
                        cout << "OINK del cerdo " << cerdoactual << endl;
                        cout << "********************** " << endl;

                        acutrufaslanzamientos = (vecrandnum[0] * 2) + (vecrandnum[1] * 2) + (vecrandnum[2]*2);

                            if (cerdoactual == cerdo1)
                            {
                                acutrufastotalesc1 += acutrufaslanzamientos;
                                acutrufasronda1 += acutrufaslanzamientos;
                            }
                            else
                            {
                                acutrufastotalesc2 += acutrufaslanzamientos;
                                acutrufasronda2 += acutrufaslanzamientos;
                            }

                            bandera = false;

                        }
                        // caras distintas y hay un as
                        else if ((vecrandnum[0] != vecrandnum[1]) && (vecrandnum[0] != vecrandnum[2])&& (vecrandnum[1] != vecrandnum[2])&& ((vecrandnum[0] == 1) || (vecrandnum[1] == 1)|| (vecrandnum[2] == 1)))
                    {


                        if (cerdoactual == cerdo1)
                            {
                                acutrufaslanzamientos = 0;
                                acutrufasronda1 += acutrufaslanzamientos;
                                acutrufastotalesc1 -= acutrufasronda1;
                                acutrufasronda1 = 0;


                            }
                            else
                            {
                                acutrufaslanzamientos = 0;
                                acutrufasronda2 += acutrufaslanzamientos;
                                acutrufastotalesc2 -= acutrufasronda2;
                                acutrufasronda2 = 0;



                            }
                            bandera = false;



                        }
                        // caras iguales  son ases

                        else if ((vecrandnum[0] == 1) && (vecrandnum[1] == 1) && (vecrandnum[2] == 1))
                    {

                        cout << "                                 " << endl;
                        cout << "************************************" << endl;
                        cout << "CERDO "<< cerdoactual <<" HUNDIDO EN EL BARRO!" << endl;
                        cout << "                                 " << endl;
                        cout << "************************************" << endl;

                        if (cerdoactual == cerdo1)
                            {
                                acutrufaslanzamientos = 0;
                                acutrufastotalesc1 = 0;
                                acutrufasronda1 = 0;
                            }
                            else
                            {
                                acutrufaslanzamientos = 0;
                                acutrufastotalesc2 = 0;
                                acutrufasronda2 = 0;
                            }

                            bandera = false;
                            hundido = true;
                        }


                    }

                    break;


                }


                MostrarJugada(cerdoactual, cerdo1, contlanzamientos1, contlanzamientos2, vecrandnum, acutrufaslanzamientos, c, acutrufasronda1, acutrufasronda2, conTres);


                if(!conTres)
                {

                    if((vecrandnum[0] == vecrandnum[1]) && (vecrandnum[0] != 1) && (vecrandnum[1] != 1))// caras iguales y ninguna es as
                    {

                        cout << "Tire nuevamente" << endl;


                    }
                    else if ((vecrandnum[0] != vecrandnum[1]) && ((vecrandnum[0] == 1) || (vecrandnum[1] == 1))) //caras distintas y alguno es 1
                    {

                        noContinuar = true;


                        cout << "Continúa el siguiente cerdo" << endl;




                    }
                    else if ((vecrandnum[0] == 1) && (vecrandnum[1] == 1)) // caras iguales  son ases
                    {
                        noContinuar = true;

                        cout << "Continúa el siguiente cerdo" << endl;


                    }
                }
                else
                {












                }


                break;

            case 'N':

                system("cls");


                cout << "Turno del próximo cerdo" << endl;

                noContinuar = true;
                bandera = false;


                break;

            default:
                cout << "¿Desea continuar lanzando?" << endl;
                break;
            } // switch continuar


        }// while no continuar

    } // for c

} // for r




}
//Funciones que salen de la función jugar

// ¿Quién empieza el juego?

int QuienEmpieza()
{
    int vecdados1[2];
    int vecdados2[2];
    int acu1 = 0, acu2 = 0, mayordado1 = 0, mayordado2 = 0;
    int jugador = 0;
    bool salir = true;

    while (salir) // Si al tirar los dados se empata y los valores de las caras también empatan, se va a seguir tirando hasta que se desempate
    {

        for (int i = 0 ; i < 2; i++ ) // se tiran los 2 dados de un cerdo
        {
            vecdados1[i] = (rand()% 6) + 1;
            acu1 += vecdados1[i];
            cout << "                        " << endl;
            cout << "------------------------" << endl;
            cout << "  Dado " << i + 1 << " del cerdo 1: " << vecdados1[i] << endl;
            cout << "------------------------" << endl;

        }
        for (int i = 0 ; i < 2; i++ ) // se tiran los 2 dados del otro cerdo
        {
            vecdados2[i] = (rand()% 6) + 1;
            acu2 += vecdados2[i];
            cout << "                        " << endl;
            cout << "------------------------" << endl;
            cout << "  Dado " << i + 1 << " del cerdo 2: " << vecdados2[i] << endl;
            cout << "------------------------" << endl;

        }


        if(acu1 > acu2) //¿La suma de los dados del que tiró primero es mayor a la suma de los dados del que tiró segundo?
        {
            jugador = 1;
            salir = false;

        }

        else if (acu2 > acu1)
        {

            jugador = 2;
            salir = false;

        }
        else // si es empate ¿Quién tiene el mayor valor de la cara del dado?
        {
            if (vecdados1[0] > vecdados1[1]) //dado 1 en la primer tirada ¿es mayor al dado 1 en la segunda tirada?
            {

                mayordado1 = vecdados1[0];

            }
            else
            {
                mayordado1 = vecdados1[1];
            }


            if (vecdados2[0] > vecdados2[1])//dado 2 en la primer tirada ¿es mayor al dado 2 en la segunda tirada?
            {

                mayordado2 = vecdados2[0];

            }
            else
            {
                mayordado2 = vecdados2[1];
            }

            if(mayordado1 > mayordado2) //¿Quién es mayor? ¿La mayor cara de dado 1 o la mayor cara de dado 2?
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
    return jugador; //retorna el número de jugador que empieza
}


void MostrarTablero(int acutrufastotalesc1,int acutrufastotalesc2, string cerdo1, string cerdo2, string cerdoactual, int r)
{
    cout << "                                                                                                         " << endl;
    cout << " ------------------------------------------------------------------------------------------------------  " << endl;
    cout << "                                         GRAN CERDO                                                      " << endl;
    cout << " ------------------------------------------------------------------------------------------------------  " << endl;
    cout << "                         " << cerdo1 << ": " << acutrufastotalesc1 << " TRUFAS ACUMULADAS.               " << endl;
    cout << "                                                                                                         " << endl;
    cout << "                         " << cerdo2 << ": " << acutrufastotalesc2 << " TRUFAS ACUMULADAS.               " << endl;
    cout << "                                                                                                         " << endl;
    cout << " ------------------------------------------------------------------------------------------------------  " << endl;
    cout << "                                                                                                         " << endl;
    cout << "                               TURNO DE:  " << cerdoactual << "                                          " << endl;
    cout << "                                                                                                         " << endl;
    cout << "       RONDA #  " << r << "                                                                              " << endl;
    cout << "                                                                                                         " << endl;

}

void MostrarJugada(string cerdoactual, string cerdo1, int contlanzamientos1, int contlanzamientos2, int vecrandnum[2],int acutrufaslanzamientos, int c, int acutrufasronda1, int acutrufasronda2, bool conTres)
{
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                                                                                         " << endl;
    if(cerdoactual == cerdo1)
    {
        cout << "      LANZAMIENTO # " << contlanzamientos1 << endl;
    }
    else
    {
        cout << "      LANZAMIENTO # " << contlanzamientos2 << endl;
    }

    cout << "                                                                                                         " << endl;
    cout << "                                                                                                         " << endl;
    cout << "                                                                                                         " << endl;
    if (!conTres)
    {
        int d1 = vecrandnum[0];
        int d2 = vecrandnum[1];
        cout << "  Dado 1:    " << endl;
        MostrarDados(d1);
        cout << "  Dado 2:    " << endl;
        MostrarDados(d2);
        cout << "                    " << endl;
        cout << "                                                                                                         " << endl;
    }
    else
    {
        int d1 = vecrandnum[0], d2 = vecrandnum[1], d3 = vecrandnum[2];
        cout << "  Dado 1:   " << endl;
        MostrarDados(d1);
        cout << "  Dado 2:   " << endl;
        MostrarDados(d2);
        cout << "  Dado 3:   " << endl;
        MostrarDados(d3);
        cout << "                                                                                                         " << endl;
    }


    cout << "                                                                                                         " << endl;
    cout << "                                                                                                         " << endl;
    cout << "                                                                                                         " << endl;
    cout << "                             ¡SUMASTE " << acutrufaslanzamientos   << " TRUFAS!!!                        " << endl;
    cout << "                                                                                                         " << endl;

    if (c == 1)
    {
        cout << "                                                     TRUFAS DE LA RONDA: " << acutrufasronda1 << endl;
    }
    if (c == 2)
    {
        cout << "                                                     TRUFAS DE LA RONDA: " << acutrufasronda2 << endl;
    }

    cout << "                                                                                                         " << endl;
    cout << "                                                                                                         " << endl;
    cout << "                                                                                                         " << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;


}
void MostrarDados( int num)
{
    switch(num)
    {

    case 1:
    {
        cout << "                    +---------+" << endl;
        cout << "                    |         |" << endl;
        cout << "                    |    *    |" << endl;
        cout << "                    |         |" << endl;
        cout << "                    +---------+" << endl;

    }
    break;

    case 2:
    {

        cout << "                    +---------+" << endl;
        cout << "                    | *       |" << endl;
        cout << "                    |         |" << endl;
        cout << "                    |       * |" << endl;
        cout << "                    +---------+" << endl;


    }
    break;

    case 3:
    {

        cout << "                    +---------+" << endl;
        cout << "                    | *       |" << endl;
        cout << "                    |    *    |" << endl;
        cout << "                    |       * |" << endl;
        cout << "                    +---------+" << endl;


    }
    break;
    case 4:
    {

        cout << "                    +---------+" << endl;
        cout << "                    | *     * |" << endl;
        cout << "                    |         |" << endl;
        cout << "                    | *     * |" << endl;
        cout << "                    +---------+" << endl;
    }
    break;
    case 5:
    {

        cout << "                    +---------+" << endl;
        cout << "                    | *     * |" << endl;
        cout << "                    |    *    |" << endl;
        cout << "                    | *     * |" << endl;
        cout << "                    +---------+" << endl;
    }
    break;

    case 6:
    {

        cout << "                    +---------+" << endl;
        cout << "                    | *     * |" << endl;
        cout << "                    | *     * |" << endl;
        cout << "                    | *     * |" << endl;
        cout << "                    +---------+" << endl;
    }
    }
}





