#ifndef GRANCERDO_H_INCLUDED
#define GRANCERDO_H_INCLUDED
using namespace std;

//presentaci�n
void MostrarPresentacion();

//Men�

void MostrarMenu();

// �Qui�n empieza el juego?

int QuienEmpieza();


void jugar();

void MostrarTablero(int acutrufastotalesc1,int acutrufastotalesc2, string cerdo1, string cerdo2, string cerdoactual, int r);

void MostrarJugada(string cerdoactual, string cerdo1, int contlanzamientos1, int contlanzamientos2, int vecrandnum[2],int acutrufaslanzamientos, int c, int acutrufasronda1, int acutrufasronda2, bool conTres);

void MostrarDados(int vecrandnum[3]);





#endif // GRANCERDO_H_INCLUDED
