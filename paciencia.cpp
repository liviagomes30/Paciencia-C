/*
262228475 - LARISSA VITORIA MACHADO OLIVEIRA
262310236 - LIVIA GOMES DE SOUZA
*/


#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<conio2.h>
#include<windows.h>

#include "TADPilhaM1.h"


void Cartas(void)
{
	gotoxy(7,1);
	printf("A");
	
	gotoxy(6,2);
	printf("___");
	gotoxy(5,3);
	printf("|   |");
	gotoxy(5,4);
	printf("|   |");
	gotoxy(5,5);
	printf("|   |");
	gotoxy(6,5);
	printf("___");
	
	gotoxy(13,1);
	printf("B");
	
	gotoxy(12,2);
	printf("___");
	gotoxy(11,3);
	printf("|   |");
	gotoxy(11,4);
	printf("|   |");
	gotoxy(11,5);
	printf("|   |");
	gotoxy(12,5);
	printf("___");
	
	gotoxy(19,1);
	printf("C");
	
	gotoxy(18,2);
	printf("___");
	gotoxy(17,3);
	printf("|   |");
	gotoxy(17,4);
	printf("|   |");
	gotoxy(17,5);
	printf("|   |");
	gotoxy(18,5);
	printf("___");
	
	
	gotoxy(25,1);
	printf("D");
	
	gotoxy(24,2);
	printf("___");
	gotoxy(23,3);
	printf("|   |");
	gotoxy(23,4);
	printf("|   |");
	gotoxy(23,5);
	printf("|   |");
	gotoxy(24,5);
	printf("___");
	
	gotoxy(58,1);
	printf("L");
	
	
	gotoxy(60,2);
	printf("___");
	textbackground(4);
	gotoxy(59,3);
	printf("|...|");
	gotoxy(59,4);
	printf("|...|");
	gotoxy(59,5);
	printf("|   |");
	gotoxy(60,5);
	printf("___");
	textbackground(0);
	
	
	gotoxy(54,2);
	printf("___");
	gotoxy(53,3);
	printf("|   |");
	gotoxy(53,4);
	printf("|   |");
	gotoxy(53,5);
	printf("|   |");
	gotoxy(54,5);
	printf("___");

}

void CartaViradaI(char cor,int v, char n, int c, int l)
{
	if(cor == 'V')
	   textcolor(4);
	else
	   textcolor(0);
	
	gotoxy(c-1,l);
	printf(" ___ ");
	l++;
	textbackground(15);
	gotoxy(c-1,l);
	if(v == 10)
		printf("|%d%c|",v,n);
	else
		printf("|%d %c|",v,n);
	l++;
	gotoxy(c-1,l);
	printf("|%c %c|",n,n);
	l++;
	gotoxy(c-1,l);
	printf("|   |");
	gotoxy(c,l);
	printf("___");
	textcolor(15);
	textbackground(0);
	
}

void CartaViradaC(char cor,char v, char n, int c, int l)
{
	if(cor == 'V')
	   textcolor(4);
	else
	   textcolor(0);
	
	gotoxy(c-1,l);
	printf(" ___ ");
	l++;
	textbackground(15);
	gotoxy(c-1,l);
	printf("|%c %c|",v,n);
	l++;
	gotoxy(c-1,l);
	printf("|%c %c|",n,n);
	l++;
	gotoxy(c-1,l);
	printf("|   |");
	gotoxy(c,l);
	printf("___");
	textbackground(0);
	textcolor(15);
}

void Fileira(int c, int l)
{
	gotoxy(c,l);
	printf("___");
	l++;
	gotoxy(c-1,l);
	textbackground(4);
	printf("|...|");
	textbackground(0);
}

char ValorC(int v)
{
	if(v == 11)
	   return 'J';
	if(v == 12)
	   return 'Q';
	if(v == 13)
	   return 'K';
	if(v == 1)
	   return 'A';
}

// cartas não viradas
void MontarSeg(int topo,int C, int L)
{
	int i;
	for(i = topo-1,L=9; i>=0; i--) 
	{
		Fileira(C,L);
		L +=2;
    }
}

void PrimeiraCarta(TpPilhaM1 P, int C, int L)
{
    int pos;
    TpBaralho B;
    char valor;
    
    B = ElementoTOPO(P,2);
    
    if (B.valor > 10 || B.valor == 1)
    {
        valor = ValorC(B.valor);
        CartaViradaC(B.cor,valor, B.naipe, C, L);
    }
    else
        CartaViradaI(B.cor, B.valor, B.naipe,C, L);
}

void EmbaralharPilha(TpPilhaM1 &pilha) {
    // Inicializa a semente para a função rand() usando o tempo atual
    srand(time(NULL));

    int tamanho = pilha.TOPO1 + 1;
    TpBaralho temp;

    for (int i = tamanho - 1; i > 0; i--) {
        // Escolha aleatoriamente um índice entre 0 e i (inclusive)
        int j = rand() % (i + 1);

        temp = pilha.PILHA[i];
        pilha.PILHA[i] = pilha.PILHA[j];
        pilha.PILHA[j] = temp;
    }
}


TpPilhaM1 IniciarBaralho() {
    TpPilhaM1 pilha; 
    Inicializar(pilha); 

    TpBaralho baralho[52]; 
    PreencherBaralho(baralho); 
    
    // Empilha cada carta do baralho na pilha
    for (int i = 0; i < 52; i++) {
        PUSH(pilha, baralho[i],1);
    }
    EmbaralharPilha(pilha);
    return pilha;
}

void Clean(void)
{
	int l,c;
	
	for(l=6;l<30;l++) // l < 21
	{
		for(c=60;c<120;c++) // c < 91
		{
			gotoxy(c,l);
			printf("%c",255);
		}
	}
	gotoxy(1,1);
}

void Clear_Area(int row, int col, int end_row, int end_col) {
    for (int linha = row; linha <= end_row; linha++) {
        for (int coluna = col; coluna <= end_col; coluna++) {
            gotoxy(coluna, linha);
            printf(" ");
        }
    }
}


int Ver_pos(int pos,char Origem, TpPilhaM1 P1,TpPilhaM1 P2,TpPilhaM1 P3,TpPilhaM1 P4,TpPilhaM1 P5,TpPilhaM1 P6,TpPilhaM1 P7,TpPilhaM1 PN1,TpPilhaM1 PN2,TpPilhaM1 PN3,TpPilhaM1 PN4)
{
	int p;
	
	if(Origem == 'A')
		p = PN1.TOPO2;
	if(Origem == 'B')
		p = PN2.TOPO2;
	if(Origem == 'C')
		p = PN3.TOPO2;
	if(Origem == 'D')
		p = PN4.TOPO2;
	if(Origem == 'E')
		p = P1.TOPO2;
	if(Origem == 'F')
		p = P2.TOPO2;
	if(Origem == 'G')
		p = P3.TOPO2;
	if(Origem == 'H')
		p = P4.TOPO2;
	if(Origem == 'I')
		p = P5.TOPO2;
	if(Origem == 'J')
		p = P6.TOPO2;
	if(Origem == 'K')
		p = P7.TOPO2;
	
	if((52-p) >= pos)
		return p;
	else
		return -1;	
}


void Fileira_Virada(int c, int l, int n, int v, char cor)
{
	 if(cor == 'V')
	   textcolor(4);
	else
	   textcolor(0);
	   
	gotoxy(c-1,l);
	printf(" ___ ");
	l++;
	gotoxy(c-1,l);
	textbackground(15);
	if(v == 10)
		printf("|%d%c|",v,n);
	else
		printf("|%d %c|",v,n);
	textbackground(0);
	textcolor(15);
}

void Fileira_ViradaC(int c, int l, int n, char v, char cor)
{
	 if(cor == 'V')
	   textcolor(4);
	else
	   textcolor(0);
	   
	gotoxy(c-1,l);
	printf(" ___ ");
	l++;
	gotoxy(c-1,l);
	textbackground(15);
	printf("|%c %c|",v,n);
	textbackground(0);
	textcolor(15);
}

// cartas viradas
void MontarSeg_V(int C, int &L, TpPilhaM1 M,TpPilhaM1 &D)
{
	int i;
	TpBaralho B;
	char valor;
	
	for(i = M.TOPO1-1; i>=0; i--) 
	{
		B = POP(M,1);
		if (B.valor > 10 || B.valor == 1)
    	{
        	valor = ValorC(B.valor);
        	Fileira_ViradaC(C,L,B.naipe,valor,B.cor);
    	}
		else		
			Fileira_Virada(C,L,B.naipe,B.valor,B.cor);
		L +=2;
    }
}

 int Alterar_Fileira(TpPilhaM1 &M, TpPilhaM1 &D, int C, int L)
{
	TpBaralho B,A;
	int val;
	
	A = ElementoTOPO(M,1); //origem
	B = ElementoTOPO(D,2); // destino
	
	if(PMVazia(D.TOPO1,1) && PMVazia(D.TOPO2,2)) // duas fileiras vazias no topo 1
	{

		if(A.valor == 13) 
		{
			L += ((D.TOPO1 + 1)+(52 - D.TOPO2))*2;
			if(M.TOPO1 == 0)
			{
				PUSH(D,POP(M,1),2);
				PrimeiraCarta(D,C,L);
				val =1;
			}
			else
			{
			
				MontarSeg_V(C,L,M,D);
				while(!PMVazia(M.TOPO1,1))
					  PUSH(D,POP(M,1),2);
				PrimeiraCarta(D,C,L);
				val =1;
			}
			
		}
		else
			val = -1;
	}
	else
	{
		if(A.valor == B.valor-1 && A.cor != B.cor)
		{
			L += (((D.TOPO1 + 1)+(52 - D.TOPO2))*2);
			if(M.TOPO1 == 0)
			{
				PUSH(D,POP(M,1),2);
				PrimeiraCarta(D,C,L);
				val =1;
			}
			else
			{
				MontarSeg_V(C,L,M,D);
				while(!PMVazia(M.TOPO1,1))
					  PUSH(D,POP(M,1),2);
				PrimeiraCarta(D,C,L);
				val =1;
			}
		
		}
		else
			val = -1;
	}
	
	return val;
}

int Alterar_Naipes(TpPilhaM1 &M, TpPilhaM1 &D,int C, int L)
{
	TpBaralho B,A;
	int val;
	
	A = ElementoTOPO(M,1);
	B = ElementoTOPO(D,2);

	// depurar
	gotoxy(84, 22);
	//printf("Alterar_Naipes - A: %d, b: %d",A.valor, B.valor);
		
	if(!PMVazia(D.TOPO2,2))
	{
		 if(A.valor == B.valor+1)
		 {
		 	if(A.naipe == B.naipe)
		 	{
		 		PUSH(D,POP(M,1),2);
		 		PrimeiraCarta(D,C,L);
		 		val = 1;
		 	}
		 	else
		 		val = -1;
		 }
		 else
		 	val = -1;
	}
	else
	{
		if(A.valor == 1)
		{
			PUSH(D,POP(M,1),2);
		 	PrimeiraCarta(D,C,L);
		 	val = 1;
		}
		else
			val = -1;
	}
		
	return val;
}

void Apagar_Naipes(TpPilhaM1 O, int C, int L)
{
	if(!PMVazia(O.TOPO2,2))
		PrimeiraCarta(O,C,L);
	else
	{
		gotoxy(C,L);
		printf("___");
		L++;
		gotoxy(C-1,L);
		printf("|   |");
		L++;
		gotoxy(C-1,L);
		printf("|   |");
		L++;
		gotoxy(C-1,L);
		printf("|   |");
		gotoxy(C,L);
		printf("___");
	}
}

void Clean_Pos(int c, int l)
{
	int pc = c+4,i;
	
	for(;l<40;l++)
	{
		for(i=c-1;i<pc;i++)
		{
			gotoxy(i,l);
			printf("%c",255);
		}
	}
	gotoxy(1,1); // voltar inicio após movimento
}

void Apagar_Fileira(TpPilhaM1 &O, int C, int L)
{
	
	L += (((52-O.TOPO2) + (O.TOPO1 +1))*2);
	Clean_Pos(C,L);
	if(!PMVazia(O.TOPO1,1))
	{
		L =9;
		L +=O.TOPO1*2;
		if(PMVazia(O.TOPO2,2))
		{
			PUSH(O,POP(O,1),2);
		}
		else
		{
			L =9;
			L +=(O.TOPO1 + (52-O.TOPO2))*2;
		}
		
		PrimeiraCarta(O,C,L);
	}
	else
	{
		
		if(!PMVazia(O.TOPO2,2))
		{
			L =9;
			L +=(51 - O.TOPO2)*2;
			PrimeiraCarta(O,C,L);
		}
	}
}

void IniciarJogo(TpPilhaM1 &PilhaBaralho,TpPilhaM1 &P1,TpPilhaM1 &P2,TpPilhaM1 &P3,TpPilhaM1 &P4,TpPilhaM1 &P5,TpPilhaM1 &P6,TpPilhaM1 &P7)
{
	char op,Origem,Destino,res,Montagem = 'S';
	int pos,topo,i,p,val,C,L;
	TpBaralho Elem;
	TpPilhaM1 PN1,PN2,PN3,PN4,Movimentar;
    Inicializar(PN1); // Inicializa as pilhas dos naipes
    Inicializar(PN2);
    Inicializar(PN3);
    Inicializar(PN4);
   
	
	gotoxy(60,9);
	printf("INICIAR JOGO [ENTER]");
	op =  toupper(getch());
	
	while(op != 13 && op != 27)
		op =  toupper(getch());
		
	Clean();
	gotoxy(60,8);
	textcolor(15);
	printf("MOVIMENTACAO [ESC para SAIR]");
	gotoxy(60,10);
	printf("MONTE DE ORIGEM: ");
	Origem =  toupper(getch());
	while((Origem < 'A' || Origem > 'L') && Origem != 27)
		  Origem =  toupper(getch());
			  
	while(Montagem == 'S' && Origem != 27)
	{		
		if(Origem != 'L' )
		{
			if(Origem!= 'A' && Origem!= 'B' && Origem!= 'C' && Origem!= 'D')
			{
				gotoxy(60,11);
				printf("POSICAO: ");
				gotoxy(60,18);
				printf("*Para digitar a posicao da carta corretamente:");
				gotoxy(60,19);
				printf("Considere apenas as cartas viradas para cima");
				gotoxy(60,20);
				printf("Digite 1 para mover a primeira carta, de cima para baixo.");
				gotoxy(60,21);
				printf("Se houverem cartas abaixo, serao movidas tambem.");
				do {
					gotoxy(60, 16);
					printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255);
					
					fflush(stdin);
			        gotoxy(69, 11);
			        scanf("%d", &pos);
			        topo = Ver_pos(pos, Origem, P1, P2, P3, P4, P5, P6, P7, PN1, PN2, PN3, PN4);
			
			        if (pos < 1 || pos > 13 || topo == -1) {
			            gotoxy(60, 16);
			            textcolor(4);
			            printf("POSICAO INVALIDA.");
			            textcolor(15);
			            getch();
			
			            gotoxy(69, 11);
			            printf("%c%c%c%c%c%c%c%c", 255, 255, 255, 255, 255, 255, 255, 255);
			        }
			
			    } while (pos < 1 || pos > 13 || topo == -1);
			}
		}
		// baralho de compra
		else
		{
			if(!PMVazia(PilhaBaralho.TOPO1,1) || !PMVazia(PilhaBaralho.TOPO2,2))
			{
				gotoxy(60,11);
				printf("VIRAR CARTA[V] || USAR TOPO [T]");
				
				gotoxy(60,12);
				printf(">: ");
				do
				{
					res =  toupper(getch());
				}while(res != 'V' && res != 'T');
				
				if(res == 'T')
				{
					
					topo = PilhaBaralho.TOPO2;
					pos = 0;
				}
				else
				{
					if(PMVazia(PilhaBaralho.TOPO1,1) && !PMVazia(PilhaBaralho.TOPO2,2))
					{
						while(!PMVazia(PilhaBaralho.TOPO2,2))
							PUSH(PilhaBaralho,POP(PilhaBaralho,2),1);
					}
					PUSH(PilhaBaralho,POP(PilhaBaralho,1),2);
					PrimeiraCarta(PilhaBaralho,54,2);
					topo = -1;
				}
			}
			else
			{
				gotoxy(60,11);
				printf("MONTE VAZIO");
			}
			
			
		}
		
		if(topo != -1)
		{
			gotoxy(60,14);
			printf("DESTINO:  ");
			Destino =  toupper(getch());
			while(Destino < 'A' || Destino > 'K' )
		  		  Destino =  toupper(getch());
		  	
		  	Inicializar(Movimentar);
		  	
		  	if(Origem!= 'A' && Origem!= 'B' && Origem!= 'C' && Origem!= 'D' && Origem!= 'L')
		  	{
		  		p = ((52-topo)-pos) + topo; // numero de cartas a serem movidas
			  	for(i = topo; i <= p; i++)
			  	{
					if(Origem == 'E')
				       PUSH(Movimentar,POP(P1,2),1);
					if(Origem == 'F')
					   PUSH(Movimentar,POP(P2,2),1);
					if(Origem == 'G')
					   PUSH(Movimentar,POP(P3,2),1);
					if(Origem == 'H')
					   PUSH(Movimentar,POP(P4,2),1);
					if(Origem == 'I')
					   PUSH(Movimentar,POP(P5,2),1);
					if(Origem == 'J')
					   PUSH(Movimentar,POP(P6,2),1);
					if(Origem == 'K')
					   PUSH(Movimentar,POP(P7,2),1);
			  		
			  	}
		  	}
		  	else
		  	{
		  		if(Origem == 'A')
				   PUSH(Movimentar,POP(PN1,2),1);
				if(Origem == 'B')
				   PUSH(Movimentar,POP(PN2,2),1);
				if(Origem == 'C')
				   PUSH(Movimentar,POP(PN3,2),1);
				if(Origem == 'D')
				   PUSH(Movimentar,POP(PN4,2),1);
				if(Origem == 'L')
				   PUSH(Movimentar,POP(PilhaBaralho,2),1);
			}
			
			if(Destino == 'A')
			{
				C= 6;
				L= 2;
				val = Alterar_Naipes(Movimentar,PN1,C,L);
			}
			if(Destino == 'B')
			{
				C= 12;
				L= 2;
				val = Alterar_Naipes(Movimentar,PN2,C,L);
			}
			if(Destino == 'C')
			{
				C= 18;
				L= 2;
				val = Alterar_Naipes(Movimentar,PN3,C,L);
			}
			if(Destino == 'D')
			{
				C= 24;
				L= 2;
				val = Alterar_Naipes(Movimentar,PN4,C,L);
			}
			if(Destino == 'E')
			{
				C=6;
				L=9;
				val = Alterar_Fileira(Movimentar,P1,C,L);
			}
			if(Destino == 'F')
			{
				C=12; 
				L=9;
				val = Alterar_Fileira(Movimentar,P2,C,L);
			}
			if(Destino == 'G')
			{
				C=18; 
				L=9;
				val = Alterar_Fileira(Movimentar,P3,C,L);
			}
			if(Destino == 'H')
			{
				C=24;
				L=9;
				val = Alterar_Fileira(Movimentar,P4,C,L);
			}
			if(Destino == 'I')
			{
				C=30; 
				L=9;
				val = Alterar_Fileira(Movimentar,P5,C,L);
			}
			if(Destino == 'J')
			{
				C=36; 
				L=9;
				val = Alterar_Fileira(Movimentar,P6,C,L);
			}
			if(Destino == 'K')
			{
				C=42; 
				L=9;
				val = Alterar_Fileira(Movimentar,P7,C,L);
			}
			
			
			if(val == -1)
			{
				if(Origem == 'A')
				{
					while(!PMVazia(Movimentar.TOPO1,1))
						  PUSH(PN1,POP(Movimentar,1),2);
				}
				if(Origem == 'B')
				{
					while(!PMVazia(Movimentar.TOPO1,1))
						  PUSH(PN2,POP(Movimentar,1),2);
				}
				if(Origem == 'C')
				{
					while(!PMVazia(Movimentar.TOPO1,1))
						  PUSH(PN3,POP(Movimentar,1),2);
				}
				if(Origem == 'D')
				{
					while(!PMVazia(Movimentar.TOPO1,1))
						  PUSH(PN4,POP(Movimentar,1),2);
				}
				if(Origem == 'L')
				{
					while(!PMVazia(Movimentar.TOPO1,1))
						  PUSH(PilhaBaralho,POP(Movimentar,1),2);
				} 
				if(Origem == 'E')
				{
					while(!PMVazia(Movimentar.TOPO1,1))
						  PUSH(P1,POP(Movimentar,1),2);
				}
				if(Origem == 'F')
				{
					while(!PMVazia(Movimentar.TOPO1,1))
						  PUSH(P2,POP(Movimentar,1),2);
				}
				if(Origem == 'G')
				{
					while(!PMVazia(Movimentar.TOPO1,1))
						  PUSH(P3,POP(Movimentar,1),2);
				}
				if(Origem == 'H')
				{
					while(!PMVazia(Movimentar.TOPO1,1))
						  PUSH(P4,POP(Movimentar,1),2);
				}
				if(Origem == 'I')
				{
					while(!PMVazia(Movimentar.TOPO1,1))
						  PUSH(P5,POP(Movimentar,1),2);
				}
				if(Origem == 'J')
				{
					while(!PMVazia(Movimentar.TOPO1,1))
						  PUSH(P6,POP(Movimentar,1),2);
				}
				if(Origem == 'K')
				{
					while(!PMVazia(Movimentar.TOPO1,1))
						  PUSH(P7,POP(Movimentar,1),2);
				}
				
				gotoxy(60,16);
				textcolor(4);
				printf("MOVIMENTO INVALIDO");
				textcolor(0);
				getch();
			}
			else
			{
				if(Origem == 'A')
				{
					C= 6;
					L= 2;
					Apagar_Naipes(PN1,C,L);
				
				}
				if(Origem == 'B')
				{
					C= 12;
					L= 2;
					Apagar_Naipes(PN2,C,L);
				}
				if(Origem == 'C')
				{
					C= 18;
					L= 2;
					Apagar_Naipes(PN3,C,L);
				}
				if(Origem == 'D')
				{
					C= 24;
					L= 2;
					Apagar_Naipes(PN4,C,L);
				}
				if(Origem == 'E')
				{
					C=6;
					L=9;
					Apagar_Fileira(P1,C,L);
				}
				if(Origem == 'F')
				{
					C=12; 
					L=9;
					Apagar_Fileira(P2,C,L);
				}
				if(Origem == 'G')
				{
					C=18; 
					L=9;
					Apagar_Fileira(P3,C,L);
				}
				if(Origem == 'H')
				{
					C=24;
					L=9;
					Apagar_Fileira(P4,C,L);
				}
				if(Origem == 'I')
				{
					C=30; 
					L=9;
					Apagar_Fileira(P5,C,L);
				}
				if(Origem == 'J')
				{
					C=36; 
					L=9;
					Apagar_Fileira(P6,C,L);
				}
				if(Origem == 'K')
				{
					C=42; 
					L=9;
					Apagar_Fileira(P7,C,L);
				}
				if(Origem == 'L')
				{
					C=54; 
					L=2;
					Apagar_Naipes(PilhaBaralho,C,L);
				}
				
				gotoxy(60,16);
				textcolor(3);
				printf("MOVIMENTO EXECUTADO");
				getch();
				textcolor(15);
			}
		}
		
		if(PMVazia(P1.TOPO1,1) && PMVazia(P2.TOPO1,1) && PMVazia(P3.TOPO1,1) && PMVazia(P4.TOPO1,1) && PMVazia(P5.TOPO1,1) && PMVazia(P6.TOPO1,1) && PMVazia(P7.TOPO1,1))
		{
			Montagem = 'N';
			Clean();
			gotoxy(60,9);
			printf("PARABENS!!");
			
		}
		else
		{
			Clean();
			gotoxy(60,7);
			textcolor(15);
			printf("MOVIMENTACAO");
			gotoxy(60,9);
			printf("MONTE DE ORIGEM: ");
			Origem =  toupper(getch());
			while((Origem < 'A' || Origem > 'L' )&& Origem != 27)
				  Origem =  toupper(getch());
		}
		
	}	

}

void MostrarFileiras(TpPilhaM1 &PilhaBaralho, TpPilhaM1 &P1,TpPilhaM1 &P2,TpPilhaM1 &P3,TpPilhaM1 &P4,TpPilhaM1 &P5,TpPilhaM1 &P6,TpPilhaM1 &P7) 
{
	int L,C,pos,i,topo;
	char valor;
	TpBaralho B;

	Cartas();

	gotoxy(7,8);
	printf("E");
	PUSH(P1,POP(P1,1),2);
	PrimeiraCarta(P1,6,9);
		
	
	gotoxy(13,8);
	printf("F");
	topo = P2.TOPO1;
	L=9;
	C=12;
	MontarSeg(topo,C,L);
	L = (topo*2)+9;
	PUSH(P2,POP(P2,1),2);
	PrimeiraCarta(P2,C,L);
	
	gotoxy(19,8);
	printf("G");
	topo = P3.TOPO1;
	L=9;
	C=18;
	MontarSeg(topo,C,L);
	L = (topo *2)+9;
	PUSH(P3,POP(P3,1),2);
	PrimeiraCarta(P3,C,L);
	
	gotoxy(25,8);
	printf("H");
	topo = P4.TOPO1;
	L=9;
	C=24;
	MontarSeg(topo,C,L);
	L = (topo*2)+9;
	PUSH(P4,POP(P4,1),2);
	PrimeiraCarta(P4,C,L);
	
	gotoxy(31,8);
	printf("I");
	topo = P5.TOPO1;
	L=9;
	C=30;
	MontarSeg(topo,C,L);
	L = (topo*2)+9;
	PUSH(P5,POP(P5,1),2);
	PrimeiraCarta(P5,C,L);
	
	gotoxy(37,8);
	printf("J");
	topo = P6.TOPO1;
	L=9;
	C=36;
	MontarSeg(topo,C,L);
	L = (topo*2)+9;
	PUSH(P6,POP(P6,1),2);
	PrimeiraCarta(P6,C,L);
	
	gotoxy(43,8);
	printf("K");
	topo = P7.TOPO1;
	L=9;
	C=42;
	MontarSeg(topo,C,L);
	L = (topo*2)+9;
	PUSH(P7,POP(P7,1),2);
	PrimeiraCarta(P7,C,L);
	
	IniciarJogo(PilhaBaralho,P1,P2,P3,P4,P5,P6,P7);
	
}

void PrepararJogo(TpPilhaM1 &PilhaBaralho, TpPilhaM1 &P1,TpPilhaM1 &P2,TpPilhaM1 &P3,TpPilhaM1 &P4,TpPilhaM1 &P5,TpPilhaM1 &P6,TpPilhaM1 &P7) 
{
    TpBaralho carta;
    TpBaralho baralho[52];

    // Preencha as sete fileiras
    for (int i = 0; i < 7; i++) 
	{
        for (int j = 0; j <= i; j++) 
		{ // <= para incluir a primeira carta virada para cima
            carta = POP(PilhaBaralho, 1); 
            if (j == i) 
			{ // Se for a última carta da pilha, vire-a para cima
                carta.status = 'A'; // Virar a carta para cima
            } 
			else 
			{
                carta.status = 'I'; 
            }
           
            switch (i) 
			{
                case 0: PUSH(P1, carta,1); break;
                case 1: PUSH(P2, carta,1); break;
                case 2: PUSH(P3, carta,1); break;
                case 3: PUSH(P4, carta,1); break;
                case 4: PUSH(P5, carta,1); break;
                case 5: PUSH(P6, carta,1); break;
                case 6: PUSH(P7, carta,1); break;
            }
        }
    }
    MostrarFileiras(PilhaBaralho,P1,P2,P3,P4,P5,P6,P7);
}

void Comecar(void)
{
	char op=13;
	
	
	while (op != 27)
	{
		
		TpPilhaM1 P1,P2,P3,P4,P5,P6,P7;
	    Inicializar(P1); 
	    Inicializar(P2);
	    Inicializar(P3);
	    Inicializar(P4);
	    Inicializar(P5);
	    Inicializar(P6);
	    Inicializar(P7);
		TpPilhaM1 pilhaBaralho = IniciarBaralho();
    	PrepararJogo(pilhaBaralho,P1,P2,P3,P4,P5,P6,P7);
    	
    	gotoxy(60,12);
    	printf("[ENTER] NOVO JOGO");
    	gotoxy(60,13);
    	printf("[ESC] SAIR");
    	op =  toupper(getch());
    	clrscr();
	
	}
	clrscr();
	Clear_Area(6, 3, 35, 50);
	gotoxy(40,9);
		printf("FIM DE JOGO");
    
}

int main()
{
	Comecar();
    gotoxy(1,20);
    getch();
    return 0;
}
