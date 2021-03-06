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
    cout << "**                                          4 - INSTRUCCIONES                                          **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                      ----------------------------------------------------------                     **" << endl;
    cout << "**                                          0 - SALIR                                                  **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "*********************************************************************************************************" << endl;
    cout << "*********************************************************************************************************" << endl;


}

void Mostrarinstrucciones(){

    system("cls");

            cout << "............................................................................................." << endl;
            cout << endl << "                         INSTRUCCIONES " << endl;
            cout << "............................................................................................." << endl;
            cout << "  El juego está compuesto por cinco rondas por jugador y en cada ronda el jugador dispone" << endl;
            cout << "  de ilimitados lanzamientos." << endl << endl;

            cout << "  En cada lanzamiento el jugador tira los dados y se analiza los valores de las caras. " << endl << endl;

            cout << "  * Si las caras son distintas entre sí y ninguna de ellas es un as. Entonces el cerdo" << endl;
            cout << "  acumula trufas según la suma de las caras al total de la ronda." << endl;
            cout << "  Por ejemplo: 5 y 3. Acumula 8 trufas. Luego, puede decidir si volver a lanzar los dados" << endl;
            cout << "  o plantarse y ceder el turno al otro cerdo." << endl << endl;

            cout << "  * Si las caras son iguales entre sí y no son ases. Entonces el cerdo hizo un Oink y " << endl;
            cout << "  acumula trufas por el doble de la suma de las caras al total de la ronda." << endl;
            cout << "  Por ejemplo: 4 y 4. Acumula 16 trufas. También, está obligado a lanzar los dados una vez" << endl << endl;

            cout << "  * Si las caras son distintas entre sí y hay un as entre ellas. Pierde todas las trufas que " << endl;
            cout << "  venía acumulando en la ronda actual y automáticamente le cede el turno al otro cerdo." << endl << endl;

            cout << "  * Si dos de las caras son iguales entre sí y son ases. El cerdo se hunde en el barro y" << endl;
            cout << "  pierde todas las trufas que venía acumulando en las rondas anteriores y automáticamente" << endl;
            cout << "  le cede el turno al otro cerdo." << endl << endl;

            cout << "  * Si se está lanzando con tres dados y tres de las caras son iguales entre sí y son ases." << endl;
            cout << "  Aplica la misma quita de puntos que en el caso anterior pero dichos puntos se acumulan al" << endl;
            cout << "  otro cerdo en dicha ronda." << endl << endl;

            cout << "  El juego utiliza dos dados hasta que ambos cerdos superen (cada uno) las 50 trufas o alguno" << endl;
            cout << "  de ellos se hunda en el barro. A partir de allí, el juego se desarrolla con tres dados por" << endl;
            cout << "  lanzamiento (esto puede ocurrir incluso en el transcurso de una ronda)." << endl << endl;
            cout << "............................................................................................." << endl;

            system("pause");
            system("cls");

}


void jugar(int &mayorpuntosdevictoria, string &jugadorganador)
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
    int contoinkc1 = 0, contoinkc2 = 0, masTrufasc1 = 0, masTrufasc2 = 0, cada50trufasc1 = 0, cada50trufasc2 = 0, oinksc1 = 0, oinksc2 = 0, mayorlanzamientoc1 = 0, total1 = 0, total2 = 0;
    int mayorlanzamientoc2 = 0, cerdoCodicioso1 = 0, cerdoCodicioso2 = 0, humCerdoprimo1 = 0, humCerdoprimo2 = 0;
    char continuar;
    string cerdoactual;
    bool noContinuar, bandera, hundido = false, conTres = false,banderaprimo = false;



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

                    cout << "żCONTINUAR? (S/N) " << endl;
                    cin >> continuar;
                    continuar = toupper(continuar);
                }

                switch(continuar)
                {

                case 'S':
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


                    if( (acutrufastotalesc1 > 50 && acutrufastotalesc2 > 50) || hundido  ) //jugar con 3 dados
                    {

                        conTres = true;

                        for (int i = 0; i < 3; i++)
                        {

                            vecrandnum[i] = 0;

                            vecrandnum[i] = (rand()% 6)+ 1;

                        }


                    }
                    else // jugar con 2 dados
                    {

                        for (int i = 0; i < 2; i++)
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


                    if(!conTres)// si hay que jugar con 2 dados
                    {

                        int conprimo0 = 0, conprimo1 = 0, conprimo2 = 0;
                        bool esprimo0 = false, esprimo1 = false;

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
                            for (int p = 1; p <= 6; p++)
                            {

                                if(vecrandnum[0] % p == 0)
                                {
                                    conprimo0 ++;
                                }

                                if(vecrandnum[1] % p == 0)
                                {
                                    conprimo1 ++;

                                }
                            }

                            if(conprimo0 == 2)
                            {
                                esprimo0 = true;
                            }
                            if(conprimo1 == 2)
                            {
                                esprimo1 = true;
                            }
                            if(esprimo0 == true && esprimo1 == true && banderaprimo == false)
                            {

                                if(c==1)
                                {
                                    humCerdoprimo1 =5;

                                    cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                }
                                else
                                {

                                    humCerdoprimo2 = 5;
                                    cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                }

                                banderaprimo = true;


                            }





                        }
                        else if((vecrandnum[0] == vecrandnum[1]) && (vecrandnum[0] != 1) && (vecrandnum[1] != 1)) // caras iguales y ninguna es as
                        {
                            cout << "                                 " << endl;
                            cout << "**********************" << endl;
                            cout << "OINK del cerdo " << cerdoactual << endl;
                            cout << "********************** " << endl;

                            if(c == 1)
                            {
                                contoinkc1++;
                            }
                            else
                            {
                                contoinkc2++;
                            }

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
                            for (int p = 1; p <= 6; p++)
                            {

                                if(vecrandnum[0] % p == 0)
                                {
                                    conprimo0 ++;
                                }

                                if(vecrandnum[1] % p == 0)
                                {
                                    conprimo1 ++;

                                }
                            }

                            if(conprimo0 == 2)
                            {
                                esprimo0 = true;
                            }
                            if(conprimo1 == 2)
                            {
                                esprimo1 = true;
                            }
                            if(esprimo0 == true && esprimo1 == true && banderaprimo == false)
                            {

                                if(c==1)
                                {
                                    humCerdoprimo1 = 5;
                                    cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                }
                                else
                                {

                                    humCerdoprimo2 = 5;
                                    cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                }

                                banderaprimo = true;


                            }

                            bandera = false; // no pregunta continuar s/n

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
                            for (int p = 1; p <= 6; p++)
                            {

                                if(vecrandnum[0] % p == 0)
                                {
                                    conprimo0 ++;
                                }

                                if(vecrandnum[1] % p == 0)
                                {
                                    conprimo1 ++;

                                }
                            }

                            if(conprimo0 == 2)
                            {
                                esprimo0 = true;
                            }
                            if(conprimo1 == 2)
                            {
                                esprimo1 = true;
                            }
                            if(esprimo0 == true && esprimo1 == true && banderaprimo == false)
                            {

                                if(c==1)
                                {
                                    humCerdoprimo1 = 5;
                                    cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                }
                                else
                                {

                                    humCerdoprimo2 = 5;
                                    cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                }

                                banderaprimo = true;


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
                            for (int p = 1; p <= 6; p++)
                            {

                                if(vecrandnum[0] % p == 0)
                                {
                                    conprimo0 ++;
                                }

                                if(vecrandnum[1] % p == 0)
                                {
                                    conprimo1 ++;

                                }
                            }

                            if(conprimo0 == 2)
                            {
                                esprimo0 = true;
                            }
                            if(conprimo1 == 2)
                            {
                                esprimo1 = true;
                            }
                            if(esprimo0 == true && esprimo1 == true && banderaprimo == false)
                            {

                                if(c==1)
                                {
                                    humCerdoprimo1 = 5;
                                    cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                }
                                else
                                {

                                    humCerdoprimo2 = 5;
                                    cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                }

                                banderaprimo = true;


                            }

                            bandera = false;
                            hundido = true;
                        }
                    }
                    else   //se juega con 3 dados
                    {
                        int conprimo0 = 0, conprimo1 = 0, conprimo2 = 0;
                        bool esprimo0 = false, esprimo1 = false, esprimo2 = false;


                        if((vecrandnum[0] != vecrandnum[1]) && (vecrandnum[0] != vecrandnum[2])&&(vecrandnum[1] != vecrandnum[2])&&(vecrandnum[0] != 1) && (vecrandnum[1] != 1)&&(vecrandnum[2] != 1))
                        {
                            acutrufaslanzamientos = vecrandnum[0] + vecrandnum[1] + vecrandnum[2];// caras distintas y ninguna es as
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
                            for (int p = 1; p <= 6; p++)
                            {

                                if(vecrandnum[0] % p == 0)
                                {
                                    conprimo0 ++;
                                }

                                if(vecrandnum[1] % p == 0)
                                {
                                    conprimo1 ++;

                                }
                                if(vecrandnum[2]% p == 0)
                                {
                                    conprimo2++;

                                }
                            }

                            if(conprimo0 == 2)
                            {
                                esprimo0 = true;
                            }
                            if(conprimo1 == 2)
                            {
                                esprimo1 = true;
                            }
                            if(conprimo2 == 2)
                            {

                                esprimo2 = true;
                            }
                            if(esprimo0 == true && esprimo1 == true && esprimo2 == true && banderaprimo == false)
                            {

                                if(c==1)
                                {
                                    humCerdoprimo1 = 7;
                                    cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                }
                                else
                                {

                                    humCerdoprimo2 = 7;
                                    cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                }

                                banderaprimo = true;


                            }

                        }

                        else if((vecrandnum[1] == vecrandnum[2] && vecrandnum[1] != vecrandnum[0]) || (vecrandnum[0] == vecrandnum[2] && vecrandnum[0] != vecrandnum[1]) || (vecrandnum[0] == vecrandnum[1] && vecrandnum[0] != vecrandnum[2]))
                        {

                            if (vecrandnum[0] != 1 && vecrandnum[1] != 1 && vecrandnum[2] != 1)
                            {

                                // 2 caras iguales y una distinta (ninguna es as)

                                // 4 5 5
                                // 5 4 5
                                // 5 5 4


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
                                for (int p = 1; p <= 6; p++)
                                {

                                    if(vecrandnum[0] % p == 0)
                                    {
                                        conprimo0 ++;
                                    }

                                    if(vecrandnum[1] % p == 0)
                                    {
                                        conprimo1 ++;

                                    }
                                    if(vecrandnum[2]% p == 0)
                                    {
                                        conprimo2++;

                                    }
                                }

                                if(conprimo0 == 2)
                                {
                                    esprimo0 = true;
                                }
                                if(conprimo1 == 2)
                                {
                                    esprimo1 = true;
                                }
                                if(conprimo2 == 2)
                                {

                                    esprimo2 = true;
                                }
                                if(esprimo0 == true && esprimo1 == true && esprimo2 == true && banderaprimo == false)
                                {

                                    if(c==1)
                                    {
                                        humCerdoprimo1 =7;
                                        cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                    }
                                    else
                                    {

                                        humCerdoprimo2 = 7;
                                        cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                    }

                                    banderaprimo = true;


                                }



                            }
                            else if (vecrandnum[0] == 1 || vecrandnum[1] == 1 || vecrandnum[2] == 1)
                            {

                                // 3 caras iguales y hay un as

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
                                for (int p = 1; p <= 6; p++)
                                {

                                    if(vecrandnum[0] % p == 0)
                                    {
                                        conprimo0 ++;
                                    }

                                    if(vecrandnum[1] % p == 0)
                                    {
                                        conprimo1 ++;

                                    }
                                    if(vecrandnum[2]% p == 0)
                                    {
                                        conprimo2++;

                                    }
                                }

                                if(conprimo0 == 2)
                                {
                                    esprimo0 = true;
                                }
                                if(conprimo1 == 2)
                                {
                                    esprimo1 = true;
                                }
                                if(conprimo2 == 2)
                                {

                                    esprimo2 = true;
                                }
                                if(esprimo0 == true && esprimo1 == true && esprimo2 == true && banderaprimo == false)
                                {

                                    if(c==1)
                                    {
                                        humCerdoprimo1 =7;
                                        cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                    }
                                    else
                                    {

                                        humCerdoprimo2 = 7;
                                        cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                    }

                                    banderaprimo = true;


                                }

                                bandera = false;
                                noContinuar = true; // si hay un as tiene que cambiar de jugador



                            }



                        }


                        // caras iguales y ninguna es as
                        else if((vecrandnum[0] == vecrandnum[1]) && (vecrandnum[0] == vecrandnum[2])&&(vecrandnum[0] != 1) && (vecrandnum[1] != 1)&& (vecrandnum[2] != 1))
                        {
                            cout << "                                 " << endl;
                            cout << "**********************" << endl;
                            cout << "OINK del cerdo " << cerdoactual << endl;
                            cout << "********************** " << endl;

                            if(c == 1)
                            {
                                contoinkc1++;
                            }
                            else
                            {
                                contoinkc2++;
                            }

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
                            for (int p = 1; p <= 6; p++)
                            {

                                if(vecrandnum[0] % p == 0)
                                {
                                    conprimo0 ++;
                                }

                                if(vecrandnum[1] % p == 0)
                                {
                                    conprimo1 ++;

                                }
                                if(vecrandnum[2]% p == 0)
                                {
                                    conprimo2++;

                                }
                            }

                            if(conprimo0 == 2)
                            {
                                esprimo0 = true;
                            }
                            if(conprimo1 == 2)
                            {
                                esprimo1 = true;
                            }
                            if(conprimo2 == 2)
                            {

                                esprimo2 = true;
                            }
                            if(esprimo0 == true && esprimo1 == true && esprimo2 == true && banderaprimo == false)
                            {

                                if(c==1)
                                {
                                    humCerdoprimo1 =7;
                                    cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                }
                                else
                                {

                                    humCerdoprimo2 = 7;
                                    cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                }

                                banderaprimo = true;


                            }


                            bandera = false;

                        }
                        // caras distintas y hay un as
                        else if ((vecrandnum[0] != vecrandnum[1]) && (vecrandnum[0] != vecrandnum[2])&& (vecrandnum[1] != vecrandnum[2]) && ((vecrandnum[0] == 1) || (vecrandnum[1] == 1)|| (vecrandnum[2] == 1)))
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
                            for (int p = 1; p <= 6; p++)
                            {

                                if(vecrandnum[0] % p == 0)
                                {
                                    conprimo0 ++;
                                }

                                if(vecrandnum[1] % p == 0)
                                {
                                    conprimo1 ++;

                                }
                                if(vecrandnum[2]% p == 0)
                                {
                                    conprimo2++;

                                }
                            }

                            if(conprimo0 == 2)
                            {
                                esprimo0 = true;
                            }
                            if(conprimo1 == 2)
                            {
                                esprimo1 = true;
                            }
                            if(conprimo2 == 2)
                            {

                                esprimo2 = true;
                            }
                            if(esprimo0 == true && esprimo1 == true && esprimo2 == true && banderaprimo == false)
                            {

                                if(c==1)
                                {
                                    humCerdoprimo1 =7;
                                    cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                }
                                else
                                {

                                    humCerdoprimo2 = 7;
                                    cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                }

                                banderaprimo = true;


                            }

                            bandera = false;



                        }
                        // caras iguales  son ases

                        else if (vecrandnum[0] == 1 && vecrandnum[1] == 1 && vecrandnum[2] == 1)
                        {

                            cout << "                                 " << endl;
                            cout << "************************************" << endl;
                            cout << "CERDO "<< cerdoactual <<" HUNDIDO EN EL BARRO!" << endl;
                            cout << "                                 " << endl;
                            cout << "************************************" << endl;

                            if (cerdoactual == cerdo1)
                            {
                                acutrufaslanzamientos = 0;
                                acutrufastotalesc2 += acutrufastotalesc1;
                                acutrufastotalesc1 = 0;
                                acutrufasronda1 = 0;
                            }
                            else
                            {
                                acutrufaslanzamientos = 0;
                                acutrufastotalesc1 += acutrufastotalesc2;
                                acutrufastotalesc2 = 0;
                                acutrufasronda2 = 0;
                            }
                            for (int p = 1; p <= 6; p++)
                            {

                                if(vecrandnum[0] % p == 0)
                                {
                                    conprimo0 ++;
                                }

                                if(vecrandnum[1] % p == 0)
                                {
                                    conprimo1 ++;

                                }
                                if(vecrandnum[2]% p == 0)
                                {
                                    conprimo2++;

                                }
                            }

                            if(conprimo0 == 2)
                            {
                                esprimo0 = true;
                            }
                            if(conprimo1 == 2)
                            {
                                esprimo1 = true;
                            }
                            if(conprimo2 == 2)
                            {

                                esprimo2 = true;
                            }
                            if(esprimo0 == true && esprimo1 == true && esprimo2 == true && banderaprimo == false)
                            {

                                if(c==1)
                                {
                                    humCerdoprimo1 =7;
                                    cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                }
                                else
                                {

                                    humCerdoprimo2 = 7;
                                    cout <<"El cerdo " << cerdoactual << " es el ganador por el bonus de los números primos" << endl;

                                }

                                banderaprimo = true;


                            }


                            bandera = false;
                            hundido = true;
                        }

                    }


                    MostrarJugada(cerdoactual, cerdo1, contlanzamientos1, contlanzamientos2, vecrandnum, acutrufaslanzamientos, c, acutrufasronda1, acutrufasronda2, conTres, mayorlanzamientoc1, mayorlanzamientoc2);


                    if(!conTres) // con 2 dados
                    {

                        if((vecrandnum[0] == vecrandnum[1]) && (vecrandnum[0] != 1) && (vecrandnum[1] != 1))// caras iguales y ninguna es as
                        {

                            cout << "Tire nuevamente" << endl;


                        }
                        else if ((vecrandnum[0] != vecrandnum[1]) && ((vecrandnum[0] == 1) || (vecrandnum[1] == 1))) //caras distintas y alguno es 1
                        {

                            noContinuar = true;

                            if(r == 5) // si estamos en la ronda 5
                            {
                                if(c == 2) // si es la ronda 5 y el ultimo jugador, quiere decir que es la ultima ronda y jugada
                                {
                                    system("pause");

                                }
                                else
                                {
                                    cout << "Continúa el siguiente cerdo" << endl;
                                }
                            }
                            else
                            {
                                cout << "Continúa el siguiente cerdo" << endl;
                            }




                        }
                        else if ((vecrandnum[0] == 1) && (vecrandnum[1] == 1)) // caras iguales  son ases
                        {
                            noContinuar = true;

                            if(r == 5)
                            {
                                if(c == 2)
                                {
                                    system("pause");

                                }
                                else
                                {
                                    cout << "Continúa el siguiente cerdo" << endl;
                                }
                            }
                            else
                            {
                                cout << "Continúa el siguiente cerdo" << endl;
                            }


                        }
                    }
                    else // con 3 dados
                    {

                        // caras iguales y ninguna es as
                        if((vecrandnum[0] == vecrandnum[1]) && (vecrandnum[0] == vecrandnum[2])&&(vecrandnum[0] != 1) && (vecrandnum[1] != 1)&& (vecrandnum[2] != 1))
                        {

                            cout << "Tire nuevamente" << endl;

                        } // caras distintas y hay un as
                        else if ((vecrandnum[0] != vecrandnum[1]) && (vecrandnum[0] != vecrandnum[2])&& (vecrandnum[1] != vecrandnum[2])&& ((vecrandnum[0] == 1) || (vecrandnum[1] == 1)|| (vecrandnum[2] == 1)))
                        {

                            noContinuar = true;


                            if(r == 5)
                            {
                                if(c == 2)
                                {
                                    system("pause");

                                }
                                else
                                {
                                    cout << "Continúa el siguiente cerdo" << endl;
                                }
                            }
                            else
                            {
                                cout << "Continúa el siguiente cerdo" << endl;
                            }



                        }
                        else if((vecrandnum[1] == vecrandnum[2] && vecrandnum[1] != vecrandnum[0]) || (vecrandnum[0] == vecrandnum[2] && vecrandnum[0] != vecrandnum[1]) || (vecrandnum[0] == vecrandnum[1]                         && vecrandnum[0] != vecrandnum[2]))
                        {

                            if (vecrandnum[0] == 1 || vecrandnum[1] == 1 || vecrandnum[2] == 1)
                            {
                                noContinuar = true;

                                if(r == 5)
                                {
                                    if(c == 2)
                                    {
                                        system("pause");

                                    }
                                    else
                                    {
                                        cout << "Continúa el siguiente cerdo" << endl;
                                    }
                                }
                                else
                                {
                                    cout << "Continúa el siguiente cerdo" << endl;
                                }




                            }

                        }
                        else if ((vecrandnum[0] == 1) && (vecrandnum[1] == 1) && (vecrandnum[2] == 1)) // 3 ases
                        {

                            noContinuar = true;

                            if(r == 5)
                            {
                                if(c == 2)
                                {
                                    system("pause");

                                }
                                else
                                {
                                    cout << "Continúa el siguiente cerdo" << endl;
                                }
                            }
                            else
                            {
                                cout << "Continúa el siguiente cerdo" << endl;
                            }




                        }



                    }

                }
                break; // Fin del switch 'S'

                case 'N':

                    system("cls");


                    cout << "Turno del próximo cerdo" << endl;

                    noContinuar = true;
                    bandera = false;


                    break;

                default:
                    cout << "żDesea continuar lanzando?" << endl;
                    break;
                } // switch continuar



            }// while no continuar

        } // for c


    } // for r

    system("cls");

    cout<< "*************************************************************************" << endl;
    cout<< "*                                                                       *" << endl;
    cout<< "*                       JUEGO TERMINADO!                                *" << endl;
    cout<< "*                       FIN DE LOS LANZAMIENTOS!                        *" << endl;
    cout<< "*                                                                       *" << endl;
    cout<< "*                                                                       *" << endl;
    cout<< "*************************************************************************" << endl;

    system("pause");




    //puntos de victoria
    if(acutrufastotalesc1 > acutrufastotalesc2)
    {

        masTrufasc1 += 5;


    }
    else if(acutrufastotalesc2 > acutrufastotalesc1)
    {

        masTrufasc2 += 5;

    }
    else
    {
        masTrufasc1 +=5;
        masTrufasc2 += 5;


    }

    cada50trufasc1 += (acutrufastotalesc1 / 50);
    cada50trufasc2 += (acutrufastotalesc2 / 50);

    oinksc1 += (contoinkc1 * 2);
    oinksc2 += (contoinkc2 * 2);

    if(mayorlanzamientoc1 > mayorlanzamientoc2)
    {

        cerdoCodicioso1 += 3;

    }
    else if(mayorlanzamientoc2 > mayorlanzamientoc1)
    {
        cerdoCodicioso2 += 3;
    }
    else
    {

        cerdoCodicioso1 += 3;
        cerdoCodicioso2 += 3;


    }

    system("cls");


    cout << "********************************************************************************************************* " << endl;
    cout << "********************************************************************************************************* " << endl;
    cout << "                                        *  GRAN CERDO  *                                                  " << endl;
    cout << " ******************************************************************************************************** " << endl;
    cout << "         HITO          *       " << cerdo1 << "                                    "  <<  cerdo2 << "                     " << endl;
    cout << " ******************************************************************************************************** " << endl;
    cout << " Más trufas en total   * " << masTrufasc1 << " PDV ("<< acutrufastotalesc1 << " trufas)                  " << masTrufasc2 << " (" << acutrufastotalesc2 << " trufas) " << endl;
    cout << " -------------------------------------------------------------------------------------------------------- "  << endl;
    cout << " Cada 50 trufas        * " << cada50trufasc1 << " PDV (" << cada50trufasc1 * 50 << " trufas)                 " << cada50trufasc2 << " PDV (" << cada50trufasc2 * 50 << " trufas)" << endl;
    cout << " -------------------------------------------------------------------------------------------------------- " << endl;
    cout << " Oinks                 * " << oinksc1 << " PDV (" << contoinkc1 << " oinks)                 " << oinksc2 << " PDV (" << contoinkc2 << " oinks)" << endl;
    cout << " -------------------------------------------------------------------------------------------------------- " << endl;
    cout << " Cerdo codicioso       * " << cerdoCodicioso1 << " PDV (" << mayorlanzamientoc1 << " lanzamientos)          " << cerdoCodicioso2 << " PDV (" << mayorlanzamientoc2 << " lanzamientos)" << endl;
    cout << " -------------------------------------------------------------------------------------------------------- " << endl;
    cout << " Humcerdo Primo                " << humCerdoprimo1 << " PDV                   " <<  humCerdoprimo2 << " PDV        " << endl;
    cout << " -------------------------------------------------------------------------------------------------------- " << endl;
    total1 = masTrufasc1 + cada50trufasc1 + oinksc1 + cerdoCodicioso1 + humCerdoprimo1;
    total2 = masTrufasc2 + cada50trufasc2 + oinksc2 + cerdoCodicioso2 + humCerdoprimo2;


    cout << " TOTAL                    " << total1  << " PDV                                       " << total2 << " PDV"  << endl;
    cout << "                                                                                                          " << endl;
    cout << "                                                                                                          " << endl;

    if (total1 > total2)
    {

        cout << "EL GANADOR ES " << cerdo1 << " CON " << total1 << " PUNTOS DE VICTORIA" << endl << endl;
        if(total1 > mayorpuntosdevictoria)
        {

            jugadorganador = cerdo1;
            mayorpuntosdevictoria = total1;


        }
    }
    else
    {
        cout << "EL GANADOR ES " << cerdo2 << " CON " << total2 << " PUNTOS DE VICTORIA" << endl << endl;

        if(total2 > mayorpuntosdevictoria)
        {

            jugadorganador = cerdo2;
            mayorpuntosdevictoria = total2;


        }

    }
    cout << "                                                                                                          " << endl;
    cout << "*********************************************************************************************************" << endl;
    cout << "*********************************************************************************************************" << endl;

    system("pause");





}



//Funciones que salen de la función jugar

// żQuién empieza el juego?

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


        if(acu1 > acu2) //żLa suma de los dados del que tiró primero es mayor a la suma de los dados del que tiró segundo?
        {
            jugador = 1;
            salir = false;

        }

        else if (acu2 > acu1)
        {

            jugador = 2;
            salir = false;

        }
        else // si es empate żQuién tiene el mayor valor de la cara del dado?
        {
            if (vecdados1[0] > vecdados1[1]) //dado 1 en la primer tirada żes mayor al dado 1 en la segunda tirada?
            {

                mayordado1 = vecdados1[0];

            }
            else
            {
                mayordado1 = vecdados1[1];
            }


            if (vecdados2[0] > vecdados2[1])//dado 2 en la primer tirada żes mayor al dado 2 en la segunda tirada?
            {

                mayordado2 = vecdados2[0];

            }
            else
            {
                mayordado2 = vecdados2[1];
            }

            if(mayordado1 > mayordado2) //żQuién es mayor? żLa mayor cara de dado 1 o la mayor cara de dado 2?
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

        if(salir == true)
        {
            cout<< " Hubo un empate! Se volverá a tirar los dados!"<<endl;
            cout<< "_________________________________________________"<<endl;
            system("pause");
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

void MostrarJugada(string cerdoactual, string cerdo1, int contlanzamientos1, int contlanzamientos2, int vecrandnum[3],int acutrufaslanzamientos, int c, int acutrufasronda1, int acutrufasronda2, bool conTres, int &mayorlanzamientoc1, int &mayorlanzamientoc2)
{
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << "                                                                                                         " << endl;
    if(cerdoactual == cerdo1)
    {
        cout << "      LANZAMIENTO # " << contlanzamientos1 << endl;
        if(contlanzamientos1 > mayorlanzamientoc1)
        {

            mayorlanzamientoc1 = contlanzamientos1;
        }
    }
    else
    {
        cout << "      LANZAMIENTO # " << contlanzamientos2 << endl;

        if(contlanzamientos2 > mayorlanzamientoc2)
        {

            mayorlanzamientoc2 = contlanzamientos2;
        }
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
    cout << "                             ˇSUMASTE " << acutrufaslanzamientos   << " TRUFAS!!!                        " << endl;
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

void MostrarDespedida()
{

    cout << "*********************************************************************************************************" << endl;
    cout << "*********************************************************************************************************" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                   GRACIAS POR JUGAR!!!!                                                             **" << endl;
    cout << "**                                                                           ^^--                      **" << endl;
    cout << "**                                                                        E  °    .                    **" << endl;
    cout << "**                                  HASTA PRONTO!!                         .       . ~                 **" << endl;
    cout << "**                                                                          w . w./                    **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "**                                                                                                     **" << endl;
    cout << "*********************************************************************************************************" << endl;
    cout << "*********************************************************************************************************" << endl;





}

void MostrarEstadistica(int mayorpuntosdevictoria,string jugadorganador)
{

    if(mayorpuntosdevictoria == 0)
    {

        system("cls");

        cout << "No se ha jugado una partida hasta el momento" << endl;

        sleep(3);

    }
    else
    {
        system("cls");

        cout << "*********************************************************************************************************" << endl;
        cout << "*********************************************************************************************************" << endl;
        cout << "                                                                                                         " << endl;
        cout << "                                                                                                         " << endl;
        cout << "                                                                                                         " << endl;
        cout << "                                                                                                         " << endl;
        cout << "              El jugador que obtuvo más puntos de victoria es: " << jugadorganador << "                  " << endl;
        cout << "                                                                                                         " << endl;
        cout << "                                                                                                         " << endl;
        cout << "                  con " << mayorpuntosdevictoria << " puntos de victoria.                                " << endl;
        cout << "                                                                                                         " << endl;
        cout << "                                                                                                         " << endl;
        cout << "                                                                                                         " << endl;
        cout << "                                                                                                         " << endl;
        cout << "*********************************************************************************************************" << endl;
        cout << "*********************************************************************************************************" << endl;

        sleep(3);

    }
}










