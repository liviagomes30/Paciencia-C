#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<conio2.h>

int main()
{
	int i,p,m=6;
	char o;

/*	textbackground(0);
	textcolor(4);
	gotoxy(5,5);
	printf("%c",201); //superior esquerdo
	textcolor(3);
	gotoxy(5,8);   
	printf("%c",200); // inferior esquerdo
	textcolor(2);
	gotoxy(10,5);
	printf("%c",187); // superior direito
	textcolor(1);
	gotoxy(10,8);
	printf("%c",188); // inferior direito
	textcolor(0); 

	gotoxy(8,5); 
	printf("%c",205); // horizontal
	gotoxy(8,8); 
	printf("%c",205);


	gotoxy(5,6); 
	printf("%c",186); // vertical
	gotoxy(10,6); 
	printf("%c",186);*/


/*	for(i = 6 ; i < 9; i++)
	{
		gotoxy(i,5); 
		printf("%c",'_'); // horizontal
		gotoxy(i,8); 
		printf("%c",'_');
	}

	for(i = 6 ; i < 9; i++)
	{
		gotoxy(5,i); 
		printf("%c",'|'); // vertical
		gotoxy(9,i); 
		printf("%c",'|');
	}

	gotoxy(7,6); 
	printf("%c",'A'); */
	
	
	
/*	for(p = 1 ; p<5; p++)
	{
		
		for(i = m ; i < m+3; i++)
		{
			gotoxy(i,2); 
			printf("%c",'_'); // horizontal
		//	textbackground(4);
			gotoxy(i,5); 
			printf("%c",'_');
			textbackground(0);
		}
	
		for(i = 3 ; i < 6; i++)
		{
			gotoxy(m-1,i); 
			printf("%c",'|'); // vertical
		/*	if(i<5)
			{
				textbackground(4);
				gotoxy(m,i);
				printf("...");
				textbackground(0);
			}
			gotoxy(m+3,i); 
			printf("%c",'|');
		}
		
		m+=6;
		
	}*/
	
	
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
	printf("E");
	
	textbackground(4);
	gotoxy(60,2);
	printf("___");
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

	
	gotoxy(21,90); 
	
	textcolor(0);
	printf("%c",5);
}
