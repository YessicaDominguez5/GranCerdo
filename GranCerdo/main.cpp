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
    bool salir = false;

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
            cout << "Empieza el cerdo: " << endl;
            if (cerdo == 1)
            {
                cout << endl << cerdo1 << endl;
            }
            else
            {
                cout << endl << cerdo2 << endl;
                cerdoaux = cerdo1;
                cerdo1 = cerdo2;
                cerdo2 = cerdoaux;

            }

            cout << endl << "............................" << endl;

///
            int acutrufastotalesc1 = 0, acutrufastotalesc2 = 0, acutrufaslanzamientos = 0, contlanzamientos1 = 0,contlanzamientos2 = 0, vecrandnum[2] = {}, vecrandnumtres[3] = {}, acutrufasronda1 = 0, acutrufasronda2 = 0;
            char continuar;
            string cerdoactual;


            for(int r = 1 ; r <= 5; r ++) // Rondas
            {
                acutrufaslanzamientos = 0;
                contlanzamientos1 = 0;
                contlanzamientos2 = 0;
                acutrufasronda1 = 0;
                acutrufasronda2 = 0;

                for(int c = 1; c <= 2; c++) // Jugadores
                {

                    if(c == 1)
                    {

                        cerdoactual = cerdo1;

                    }
                    else
                    {
                        cerdoactual = cerdo2;
                    }


                    cout << "Escriba S para jugar: ";
                    cin >> continuar;
                    continuar = toupper(continuar);


                    while( continuar == 'S' || continuar =='s' ) //Lanzamientos
                    {
                        system("cls");
                        if(c == 1)
                        {
                            contlanzamientos1++;
                        }
                        else
                        {
                            contlanzamientos2++;
                        }

                        for (int i = 0; i < 2; i++)
                        {

                            vecrandnum[i] = 0;

                        }


                        if (acutrufastotalesc1 < 50 && acutrufastotalesc2 < 50)
                        {

                            for (int i = 0; i < 2; i++)
                            {

                                vecrandnum[i] = (rand()% 6)+ 1;

                            }
                        }
                        else
                        {


                            for (int i = 0; i < 3; i++)
                            {

                                vecrandnumtres[i] = (rand()% 6)+ 1;


                            }
                        }


                        cout << "*********************************************************************************************************" << endl;
                        cout << "*********************************************************************************************************" << endl;
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
                        cout << "       TRUFAS DE LA RONDA:  " << acutrufaslanzamientos << "                                                     " << endl;
                        cout << "                                                                                                         " << endl;
                        if(cerdoactual == cerdo1)
                        {
                            cout << "       LANZAMIENTOS: " << contlanzamientos1 - 1 << endl;
                        }
                        else
                        {
                            cout << "       LANZAMIENTOS: " << contlanzamientos2 - 1 << endl;
                        }
                        cout << " -----------------------------------------------------------------------------------------------------  " << endl;


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



                            cout << "OINK del jugador "<< cerdoactual << endl;

                            sleep(3);

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



                        }
                        else if ((vecrandnum[0] != vecrandnum[1]) && ((vecrandnum[0] == 1) || (vecrandnum[1] == 1))) // caras distintas y ha un as
                        {
                            acutrufaslanzamientos = 0;

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

                        else if ((vecrandnum[0] == 1) && (vecrandnum[1] == 1))// caras iguales  son ases
                        {


                            cout << "CERDO "<< cerdoactual <<" HUNDIDO EN EL BARRO!" << endl;

                            sleep(3);

                            if (cerdoactual == cerdo1)
                            {
                                acutrufaslanzamientos = 0;
                                acutrufastotalesc1 = 0;
                            }
                            else
                            {
                                acutrufaslanzamientos = 0;
                                acutrufastotalesc2 = 0;
                            }


                        }



                        cout << "*********************************************************************************************************" << endl;
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
                        cout << "                             ¡SUMASTE " << acutrufaslanzamientos   << " TRUFAS!!!                               " << endl;
                        cout << "                                                                                                         " << endl;
                        cout << "                                                                                                         " << endl;
                        cout << "        ¿CONTINUAR? (S/N)                                                                                " << endl;
                        cout << "*********************************************************************************************************" << endl;
                        cout << "*********************************************************************************************************" << endl;




                        if((vecrandnum[0] != vecrandnum[1]) && (vecrandnum[0] != 1) && (vecrandnum[1] != 1))
                        {
                            cin >> continuar;

                        }

                        else if((vecrandnum[0] == vecrandnum[1]) && (vecrandnum[0] != 1) && (vecrandnum[1] != 1))
                        {

                            continuar = 'S';

                            cout << "Tire nuevamente" << endl;

                            system("pause");


                        }
                        else if ((vecrandnum[0] != vecrandnum[1]) && ((vecrandnum[0] == 1) || (vecrandnum[1] == 1)))
                        {

                            continuar = 'N';

                            cout << "Continúa el siguiente cerdo" << endl;

                            system("pause");


                        }
                        else if ((vecrandnum[0] == 1) && (vecrandnum[1] == 1))
                        {
                            continuar = 'N';

                            cout << "Continúa el siguiente cerdo" << endl;

                            system("pause");
                        }



                    }

                }

            }


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
