#ifndef GRANCERDO_H_INCLUDED
#define GRANCERDO_H_INCLUDED
using namespace std;

//presentación
void MostrarPresentacion();

//Menú

void MostrarMenu();

// ¿Quién empieza el juego?

int QuienEmpieza();


void jugar(int &mayorpuntosdevictoria,string &jugadorganador);

void MostrarTablero(int acutrufastotalesc1,int acutrufastotalesc2, string cerdo1, string cerdo2, string cerdoactual, int r);

void MostrarJugada(string cerdoactual, string cerdo1, int contlanzamientos1, int contlanzamientos2, int vecrandnum[3],int acutrufaslanzamientos, int c, int acutrufasronda1, int acutrufasronda2, bool conTres, int &mayorlanzamientoc1, int &mayorlanzamientoc2);

void MostrarDados(int num);

void MostrarEstadistica(int mayorpuntosdevictoria,string jugadorganador);
void Mostrarinstrucciones();
void MostrarDespedida();




#endif // GRANCERDO_H_INCLUDED
