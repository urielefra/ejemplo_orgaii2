#include <stdio.h>


void mostrarSudoku (int *addres)
{
	int i;
	for (i = 0; i < 81; ++i)
	{
		if ((i%9)==0)
		{
			printf("\n");
		}
		printf(" %d",addres[i]);
	}
	printf("\n");
	printf("\n");
}
int filas (int *sudoku,int posicion)//posicion es indice
{
	//para filas
	int decenas;
	decenas=posicion;
	decenas=decenas/10;
	decenas=decenas*10; //me dejas las decenas
	decenas=posicion-decenas;//me deja al inicio de cada fila

	int i;//...
	for ( i = 0; i < 9; ++i)
	{
		if (sudoku[posicion]==sudoku[decenas])
		{
			return 0;
		}
		decenas=decenas+10;
	}
	return 1;
}

int valido (int *sudoku, int posicion)
{
	if (filas(sudoku, posicion))
	{
		return 0;//si es verdad me retorna falso
	}
}

int backtracking ( int *sudoku, int casillas)
{
	printf("entra\n");

	if (casillas>81)//lleva las cuentas de las casillas
	{

		return 1;
	}
	else
	{

		if (sudoku[casillas]!=0)
		{
			return backtracking(sudoku,casillas+1);//recorre el sudoku si ya esta 
		}											//llena la casilla
		else
		{
			int i;//fuck c....
			for ( i = 1; i < 10; ++i)//me da los candidatos
			{
				sudoku[casillas]=i;//los escribre en el arreglo

				if (valido(sudoku,casillas))//casilla es el indice a evaluar
				 {
				 	if (backtracking(sudoku,casillas+1))//si es valido continua 
				 	{					//colocando valores sino busca otro
				 		return 1;   //candidato
				 	}
				 } 
			}
		}
	}
}

int main ()
{
	int matSudoku[81]={5, 3, 0, 1, 7, 0, 0, 0, 0,6, 0, 0, 1, 9, 5, 0, 0, 0,0, 9, 8, 0, 0, 0, 0, 6, 0, 8, 0, 0, 0, 6, 0, 0, 0, 3, 4, 0, 0, 8, 0, 3, 0, 0, 1, 7, 0, 0, 0, 2, 0, 0, 0, 6, 0, 6, 0, 0, 0, 0, 2, 8, 0, 0, 0, 0, 4, 1, 9, 0, 0, 5, 0, 0, 0, 0, 8, 0, 0, 7, 9};

/*
.byte 5, 3, 0, 1, 7, 0, 0, 0, 0

.byte 6, 0, 0, 1, 9, 5, 0, 0, 0

.byte 0, 9, 8, 0, 0, 0, 0, 6, 0

.byte 8, 0, 0, 0, 6, 0, 0, 0, 3    MATRIZ INICIAL  	⊂(￣(ｴ)￣)⊃

.byte 4, 0, 0, 8, 0, 3, 0, 0, 1

.byte 7, 0, 0, 0, 2, 0, 0, 0, 6

.byte 0, 6, 0, 0, 0, 0, 2, 8, 0

.byte 0, 0, 0, 4, 1, 9, 0, 0, 5

.byte 0, 0, 0, 0, 8, 0, 0, 7, 9

*/

	
	backtracking(matSudoku,0);
	mostrarSudoku(matSudoku);

	return 0;

}