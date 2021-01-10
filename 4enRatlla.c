#include "include/4enRatlla.h"

/*
int main(){
t_bool fi_partida,jugada_valida;
int jugador,i,j;

	fi_partida=FALSE;
	jugada_valida=FALSE;
	jugador=JUG_1;
	inicialitzar();
	while (!fi_partida){
		do{
			X_torn(jugador);
			jugada_valida=jugar(simbol_jugador(jugador),&i,&j);
		}while (!jugada_valida);
		X_imprimir();
		if (evaluar_enratlla(i,j,RATLLA)){
			X_msg_guanyador(jugador);
			fi_partida=TRUE;
		}
		if (!fi_partida) canvia_jugador(&jugador);
	};
}
*/

char simbol_buit(){
return SBUIT;
}
void inicialitzar(){
int i,j;
	for (i=0;i<MAX;i++)
		for (j=0;j<MAX;j++)
			tab[i][j]=simbol_buit();
}

char simbol_jugador(int jugador){
	switch(jugador){
		case JUG_1: return SJUG_1;
		case JUG_2: return SJUG_2;
	}
}

t_bool jugar(char simbol,int *i,int *j){
	*j=X_obtener_columna();
	return ubicar(simbol,i,*j);
}

t_bool ubicar(char simbol,int *fila,int columna){
	*fila=0;
	while((tab[*fila][columna])!=simbol_buit() && ((*fila)<MAX)) (*fila)++;
	if ((*fila)<MAX) tab[*fila][columna]=simbol;
	return ((*fila)<MAX);
}

t_bool evaluar_enratlla(int i,int j,int NR){
int nsimbols=0;
	nsimbols=num_simbols(i,j,_HRZT);
	if (nsimbols>=NR) return TRUE;
	nsimbols=num_simbols(i,j,_VERT);
	if (nsimbols>=NR) return TRUE;
	nsimbols=num_simbols(i,j,_DIAA);
	if (nsimbols>=NR) return TRUE;
	nsimbols=num_simbols(i,j,_DIAB);
	if (nsimbols>=NR) return TRUE;
	return FALSE;
}

void seg_v(int *i,int *j){(*i)++;}
void ant_v(int *i,int *j){(*i)--;}
void seg_h(int *i,int *j){(*j)++;}
void ant_h(int *i,int *j){(*j)--;}
void seg_dA(int *i,int *j){(*i)++;(*j)++;}
void ant_dA(int *i,int *j){(*i)--;(*j)--;}
void seg_dB(int *i,int *j){(*i)++;(*j)--;}
void ant_dB(int *i,int *j){(*i)--;(*j)++;}

int num_simbols(int i,int j,int orientacio){
void (*seg)(int *,int *);
void (*ant)(int *,int *);
char simbol;
int n_simbols=1;
int f,c;
	simbol=tab[i][j];
	switch(orientacio){
		case _HRZT:seg=&seg_h;
			   ant=&ant_h;
			   break;
		case _VERT:seg=&seg_v;
			   ant=&ant_v;
			   break;
		case _DIAA:seg=&seg_dA;
			   ant=&ant_dA;
			   break;
		case _DIAB:seg=&seg_dB;
			   ant=&ant_dB;
			   break;
		default: exit(-1);
	}
	f=i;c=j;
	seg(&f,&c);
	while ((f>=0)&&(f<MAX)&&(c>=0)&&(c<MAX)&&(tab[f][c]==simbol)){seg(&f,&c);n_simbols++;}
	f=i;c=j;
	ant(&f,&c);
	while ((f>=0)&&(f<MAX)&&(c>=0)&&(c<MAX)&&(tab[f][c]==simbol)){ant(&f,&c);n_simbols++;}
	return n_simbols;
}


void canvia_jugador(int *jugador){
	switch(*jugador){
		case JUG_1:(*jugador)=JUG_2;
			   break;
		case JUG_2:(*jugador)=JUG_1;
			   break;
	}
}


//Funcions X
int X_obtener_columna(){
int columna;
	do{
		printf("\nColumna? ");
		scanf("%d",&columna);
	}while((columna<0) || (columna>=MAX));
	return(columna);
}


void X_imprimir(){
int i,j;
	for (i=MAX-1;i>=0;i--){
		for (j=0;j<MAX;j++)
			printf("%3c",tab[i][j]);
		printf("\n");
	}
	for (i=0;i<MAX;i++)
		printf("%3d",i);
	printf("\n");
}
void X_torn(int jugador){
	switch(jugador){
		case JUG_1:printf("%s (%c)","Torn de jugador 1",SJUG_1);
			   break;
		case JUG_2:printf("%s (%c)","Torn de jugador 2",SJUG_2);
			   break;
	}
}
void X_msg_guanyador(int jugador){
	printf("\n*****************************************\n");
	printf("\n   ENHORABONA!! HAS GUANYAT jugador:%d\n",jugador);
	printf("\n*****************************************\n");
}

void test(char *txt){
	printf("%s",txt);getchar();
}
