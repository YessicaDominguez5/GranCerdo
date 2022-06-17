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

    char menu;
    string cerdo1, cerdo2;
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

            //nombre de los participantes
            cout << endl << "Ingresar nombre del cerdo: ";
            cin >> cerdo1;
            cout << endl;
            cout << endl << "Ingresar nombre del otro cerdo: ";
            cin >> cerdo2;
            cout << endl;

            system("cls");

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
                cerdo2 = cerdoaux;

            }

            cout << endl << "............................" << endl;
            cout << endl << "                            " << endl;

///
            int acutrufastotalesc1 = 0, acutrufastotalesc2 = 0, acutrufaslanzamientos = 0, contlanzamientos1 = 0,contlanzamientos2 = 0, vecrandnum[2] = {}, vecrandnumtres[3] = {}, acutrufasronda1 = 0, acutrufasronda2 = 0;
            char continuar;
            string cerdoactual;
            bool noContinuar, bandera;



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


                            if (acutrufastotalesc1 < 50 && acutrufastotalesc2 < 50) //jugar con 2 dados
                            {

                                for (int i = 0; i < 2; i++)
                                {
                                    vecrandnum[i] = 0;

                                    vecrandnum[i] = (rand()% 6)+ 1;

                                }
                            }
                            else
                            {


                                for (int i = 0; i < 3; i++) // jugar con 3 dados
                                {

                                    vecrandnumtres[i] = (rand()% 6)+ 1;


                                }
                            }
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

                            }




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
                            cout << "     Dado 1:    " << vecrandnum[0] << "         Dado 2:       " << vecrandnum[1] << "                    " << endl;
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

                            if((vecrandnum[0] == vecrandnum[1]) && (vecrandnum[0] != 1) && (vecrandnum[1] != 1))                 // caras iguales y ninguna es as
                            {

                                cout << "Tire nuevamente" << endl;


                            }
                            else if ((vecrandnum[0] != vecrandnum[1]) && ((vecrandnum[0] == 1) || (vecrandnum[1] == 1)))    //caras distintas y alguno es 1
                            {

                                noContinuar = true;


                                cout << "Continúa el siguiente cerdo" << endl;




                            }
                            else if ((vecrandnum[0] == 1) && (vecrandnum[1] == 1))  // caras iguales  son ases
                            {
                                noContinuar = true;

                                cout << "Continúa el siguiente cerdo" << endl;


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


            break;
        }
        case '2':



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
        }

    } // fin del while menu


    return 0;
}
