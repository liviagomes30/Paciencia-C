/* Listas Concorrentes 
 
 	*Aplicação em PILHAS MÚLTIPLAS
 	**CASO 1 -> para 2 PILHAS 
 	
 	_______________________________
 	|  |  |  |  |  |  |  |  |  |  | MAXPILHA[10]
 | 0   1  2  3  4  5  6  7  8  9  	  |
 |--->							  <---|
  TOPO 1	                      TOPO 2*/
  
//TADPILHAM1.H

#define MAXPILHA 52
#include<stdio.h>


struct TpBaralho
{
	int valor;
	char naipe, cor, status;	
};

struct TpPilhaM1
{
	int TOPO1, TOPO2;
	TpBaralho PILHA[MAXPILHA];
};

//operações associadas

void Inicializar(TpPilhaM1 &PM);
void PUSH(TpPilhaM1 &PM, int Elem, int NP);
TpBaralho POP(TpPilhaM1 &PM, int NP);
TpBaralho ElementoTOPO(TpPilhaM1 PM, int NP);
int PMVazia(int topo, int NP);
int PMCheia(int topo1, int topo2);
void ExibirPM(TpPilhaM1 PM, int NP);

void Inicializar(TpPilhaM1 &PM)
{
	PM.TOPO1 = -1;
	PM.TOPO2 = MAXPILHA;
}

//void PUSH(TpPilhaM1 &PM, int Elem, int NP)
//{
//	if (NP == 1)
//		PM.PILHA[++PM.TOPO1] = Elem;
//	else
//		PM.PILHA[--PM.TOPO2] = Elem;	
//}

void PUSH(TpPilhaM1 &PM, TpBaralho carta,int NP) {
	if (NP == 1)
		PM.PILHA[++PM.TOPO1] = carta;
	else
		PM.PILHA[--PM.TOPO2] = carta;
}

//int POP(TpPilhaM1 &PM, int NP)
//{
//	if (NP == 1)
//		return PM.PILHA[PM.TOPO1--];
//	else
//		return PM.PILHA[PM.TOPO2++];
//}

TpBaralho POP(TpPilhaM1 &PM, int NP)
{
	if (NP == 1)
		return PM.PILHA[PM.TOPO1--];
	else
		return PM.PILHA[PM.TOPO2++];
}

TpBaralho ElementoTOPO(TpPilhaM1 PM, int NP)
{
	if (NP == 1)
		return PM.PILHA[PM.TOPO1];
	else
		return PM.PILHA[PM.TOPO2];
}

int PMVazia(int topo, int NP)
{
	if(NP == 1) return topo == -1;
	else return topo == MAXPILHA;
}

int PMCheia(int topo1, int topo2)
{
	return topo1 + 1 == topo2;
}

//void ExibirPM(TpPilhaM1 PM, int NP)
//{
//	if (NP == 1)
//		while(!PMVazia(PM.TOPO1,NP))
//			  printf("%d",POP(PM,NP));
//	else
//		while(!PMVazia(PM.TOPO2,NP))
//			  printf("%d",POP(PM,NP));
//}

void ExibirPM(TpPilhaM1 PM, int NP) {
    if (NP == 1) {
        while (!PMVazia(PM.TOPO1, NP)) {
            TpBaralho carta = POP(PM, NP);
            printf("Valor: %d, Naipe: %c, Cor: %c, Status: %c\n", carta.valor, carta.naipe, carta.cor, carta.status);
        }
    } else {
        while (!PMVazia(PM.TOPO2, NP)) {
            TpBaralho carta = POP(PM, NP);
            printf("Valor: %d, Naipe: %c, Cor: %c, Status: %c\n", carta.valor, carta.naipe, carta.cor, carta.status);
        }
    }
}


void PreencherBaralho(TpBaralho baralho[]) 
{
    int i, j;
    int index = 0;

    // Loop para preencher o vetor com as cartas de cada naipe
    for (j = 3; j <= 6; j++) { // Loop para os naipes (copas, ouros, paus e espadas)
        for (i = 1; i <= 13; i++) { // Loop para os valores das cartas (de 1 a 13)
            baralho[index].valor = i;
            baralho[index].naipe = j;
            baralho[index].cor = (j == 3 || j == 4) ? 'V' : 'P'; // Atribui 'V' para copas e ouros, 'P' para paus e espadas
            baralho[index].status = 'A'; // Todas as cartas são inicialmente ativas
            index++;
        }
    }
}
