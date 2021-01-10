#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAX 8
#define JUG_1 1
#define SJUG_1 '*'
#define JUG_2 2
#define SJUG_2 'O'
#define SBUIT '-'

#define RATLLA 4
#define _HRZT	1
#define _VERT	2
#define _DIAA	3
#define _DIAB	4

#define t_bool int

void inicialitzar();
char simbol_jugador(int jugador);
char simbol_buit();
t_bool jugar(char simbol,int *i,int *j);
t_bool ubicar(char simbol,int *fila,int columna);
t_bool evaluar_enratlla(int i,int j,int NR);
int num_simbols(int i,int j,int orientacio);
void seg_v(int *i,int *j);
void ant_v(int *i,int *j);
void seg_h(int *i,int *j);
void ant_h(int *i,int *j);
void seg_dA(int *i,int *j);
void ant_dA(int *i,int *j);
void seg_dB(int *i,int *j);
void ant_dB(int *i,int *j);
void canvia_jugador(int *jugador);

int X_obtener_columna();
void X_imprimir();
void X_torn(int jugador);
void X_msg_guanyador(int jugador);
void test(char *txt);

char tab[MAX][MAX];
t_bool fi_partida,jugada_valida;