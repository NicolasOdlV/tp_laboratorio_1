
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
char opcion;
int operadorCompletadoA;
int operadorCompletadoB;
int casoEspecialDivision;
int casoEspecialFactorialOpA;
int casoEspecialFactorialOpB;
int retorno;
float numeroA;
float numeroB;
float rtdoSuma;
float rtdoResta;
float rtdoProducto;
float rtdoDivision;
int rtdoFactorialA;
int rtdoFactorialB;

menu(0,0);

		do
		{
				if((operadorCompletadoA && operadorCompletadoB)==0)
				{
					menu(numeroA,numeroB);
				}
				else if(operadorCompletadoA!=0)
				{
					menu(0,numeroB);
				}
				else if(operadorCompletadoB!=0)
				{
					menu(numeroA,0);
				}
			retorno=utn_getCaracter(&opcion,"Elija la letra de la opcion deseada: ","\nLa opcion no existe\n",'a','e',0);
			switch(opcion)
			{
				case 'a':
					if(retorno==0)
					{
						operadorCompletadoA=utn_getNumeroFlotante(&numeroA,"\nIngrese el numero del primer operador: \n","\nEl numero ha sobrepasado el rango permitido o no existe\n",-100000000,100000000,10);
					}
					break;
				case 'b':
					if(retorno==0)
					{
						operadorCompletadoB=utn_getNumeroFlotante(&numeroB,"\nIngrese el numero del segundo operador: \n","\nEl numero ha sobrepasado el rango permitido\n",-100000000,100000000,10);
					}
					break;
				case 'c':
					if((operadorCompletadoA && operadorCompletadoB)==0)
					{
						sumar(&rtdoSuma,numeroA,numeroB);
						restar(&rtdoResta,numeroA,numeroB);
						multiplicar(&rtdoProducto,numeroA,numeroB);
						casoEspecialDivision=dividir(&rtdoDivision,numeroA,numeroB);
						casoEspecialFactorialOpA=factorial(&rtdoFactorialA,numeroA);
						casoEspecialFactorialOpB=factorial(&rtdoFactorialB,numeroB);
						printf("\n\n\tSe han realizado todas las operaciones\n\n");
					}
					else
					{
						printf("\nPara poder ingresar en esta opción, deberá llenar el dato de cada operador.\n");
					}
						break;
				case 'd':

						if((operadorCompletadoA && operadorCompletadoB)==0)
						{
							imprimirResultados(numeroA,numeroB,rtdoSuma,rtdoResta,rtdoProducto,rtdoDivision,rtdoFactorialA,rtdoFactorialB,casoEspecialDivision,casoEspecialFactorialOpA,casoEspecialFactorialOpB);
						}
						else
						{
							printf("\nPara poder ingresar en esta opción, deberá llenar el dato de cada operador.\n");
						}
						break;
				case 'e':
					break;
				default:
					printf("\nERROR al ingresar la opcion, intente nuevamente\n");
					break;
			}
		}while(opcion != 'e');
	return EXIT_SUCCESS;
}
