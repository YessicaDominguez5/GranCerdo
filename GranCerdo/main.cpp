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
            cout << "Ingresar nombre del cerdo: ";
            cin >> cerdo1;
            cout << endl;
            cout << "Ingresar nombre del otro cerdo: ";
            cin >> cerdo2;
            cout << endl;

            system("cls");

            //tirar dados para saber qui�n empieza
            srand(time(NULL)); // motor de generador de n�meros
            int cerdo;
            string cerdoaux;

            cerdo = QuienEmpieza();

            cout << endl << "............................" << endl << endl;
            cout << "Empieza el cerdo: " << endl;
            if (cerdo == 1)
            {
                cout << cerdo1 << endl;
            }
            else
            {
                cout << cerdo2 << endl;
                cerdoaux = cerdo1;
                cerdo1 = cerdo2;
                cerdo2 = cerdoaux;

            }

            cout << endl << "............................" << endl;

///
            int acutrufastotalesc1 = 0, acutrufastotalesc2 = 0, acutrufasronda = 0, contlanzamientos = 0, vecrandnum[2] = {}, vecrandnumtres[3] = {};
            char continuar;
            string cerdoactual;


            for(int r = 1 ; r <= 5; r ++) // Rondas
            {


                for(int c = 1; c <= 2; c++) // Jugadores
                {
                    acutrufasronda = 0;


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


                    while( continuar == 'S' ) //Lanzamientos
                    {
                        system("cls");
                        contlanzamientos++;

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
                        cout << "**                                                                                                     **" << endl;
                        cout << "**   GRAN CERDO                                                                                        **" << endl;
                        cout << "** --------------------------------------------------------------------------------------------------- **" << endl;
                        cout << "**   " << cerdo1 << "                            //                                      " << cerdo2 << "            **" << endl;
                        cout << "**                                                                                                     **" << endl;
                        cout << "**" << acutrufastotalesc1 << "TRUFAS ACUMULADAS. "   << acutrufastotalesc2 << "TRUFAS ACUMULADAS.         **" << endl;
                        cout << "**                                                                                                     **" << endl;
                        cout << "**  -------------------------------------------------------------------------------------------------- **" << endl;
                        cout << "**                                                                                                     **" << endl;
                        cout << "**  TURNO DE:  " << cerdoactual << "                                                                         **" << endl;
                        cout << "**                                                                                                     **" << endl;
                        cout << "**  RONDA #  " << r << "                                                                                     **" << endl;
                        cout << "**                                                                                                     **" << endl;
                        cout << "**  TRUFAS DE LA RONDA:  " << acutrufasronda << "                                                          **" << endl;
                        cout << "**                                                                                                     **" << endl;
                        cout << "**  LANZAMIENTOS:  " << contlanzamientos - 1 << "                                                          **" << endl;
                        cout << "** --------------------------------------------------------------------------------------------------  **" << endl;
                        cout << "**                                                                                                     **" << endl;
                        cout << "**  LANZAMIENT0   #" << contlanzamientos << "                                                               **" << endl;
                        cout << "**                                                                                                     **" << endl;
                        cout << "**                                                                                                     **" << endl;
                        cout << "**                                                                                                     **" << endl;
                        cout << "**  Dado 1:    " << vecrandnum[0] << "         Dado 2:       " << vecrandnum[1] << "                                           **" << endl;
                        cout << "**                                                                                                     **" << endl;
                        cout << "**                                                                                                     **" << endl;
                        cout << "**                                                                                                     **" << endl;
                        // cout << "**  �SUMASTE " <<     << " TRUFAS!!!                                                                   **" << endl;
                        cout << "**                                                                                                     **" << endl;
                        cout << "**                                                                                                     **" << endl;
                        cout << "**      �CONTINUAR? (S/N)                                                                              **" << endl;
                        cout << "*********************************************************************************************************" << endl;
                        cout << "*********************************************************************************************************" << endl;


                        if((vecrandnum[0] != vecrandnum[1]) && (vecrandnum[0] != 1) && (vecrandnum[1] != 1))
                        {
                            acutrufasronda = vecrandnum[0] + vecrandnum[1];
                            if (cerdoactual == cerdo1)
                            {
                                acutrufastotalesc1 += acutrufasronda;
                            }
                            else
                            {
                                acutrufastotalesc2 += acutrufasronda;
                            }

                            cin >> continuar;

                        }
                        else if((vecrandnum[0] == vecrandnum[1]) && (vecrandnum[0] != 1) && (vecrandnum[1] != 1))
                        {

                            cout << "OINK!"<< endl;

                            acutrufasronda = (vecrandnum[0] * 2) + (vecrandnum[1] * 2);
                            if (cerdoactual == cerdo1)
                            {
                                acutrufastotalesc1 += acutrufasronda;
                            }
                            else
                            {
                                acutrufastotalesc2 += acutrufasronda;
                            }

                        }
                        else if ((vecrandnum[0] != vecrandnum[1]) && ((vecrandnum[0] == 1) || (vecrandnum[1] == 1)))
                        {
                            acutrufasronda = 0;
                            continuar = 'N';
                            c++;

                        }

                        else if ((vecrandnum[0] == vecrandnum[1]) && (vecrandnum[0] == 1) && (vecrandnum[1] == 1))
                        {

                            cout << "CERDO HUNDIDO EN EL BARRO!" << endl;

                            if (cerdoactual == cerdo1)
                            {
                                acutrufasronda = 0;
                                acutrufastotalesc1 = 0;
                            }
                            else
                            {
                                acutrufasronda = 0;
                                acutrufastotalesc2 = 0;
                            }

                            continuar = 'N';
                            c++;


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
            cout << "La opci�n es incorrecta" << endl;
            cout << "Intente de nuevo" << endl;
            cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl << endl;

            system("pause");
        }

    } // fin del while menu











    return 0;
}