/*
 * utn.c
 *
 *  Created on: 15 abr. 2020
 *      Author: Nicolas
 */


#include <stdio.h>
#include <stdlib.h>
#include  <ctype.h>

/**\brief Muestra por consola el menu, con los valores de cada numero
 * \param valorDeA el valor del primer numero
 * \param valorDeB el valor del segundo numero
 * \return void
 */
void menu(float valorDeA,float valorDeB)
{
		printf("\n\t\tPresione la tecla");
		printf("\n\t(A) Valor del operando A= %.f",valorDeA);
		printf("\n\t(B) Valor del operando B= %.f",valorDeB);
		printf("\n\t(C) Calcular todas las operaciones");
		printf("\n\t(D) Mostrar resultados");
		printf("\n\t(E) Salir\n");
}

/**\brief Suma los numeros entre si
 * \param pResultado guarda el resultado de la suma en la dirreccion de memoria suministrada
 * \param operador1 el valor del primer numero
 * \param operador2 el valor del segundo numero
 * \return 0 si esta bien y -1 si hubo algun error
 */
int sumar(float* pResultado,float operador1,float operador2)
{
	int retorno=-1;
	float total;
	if(pResultado!=NULL)
	{
		retorno=0;
		total=operador1+operador2;
		*pResultado=total;
	}
	return retorno;
}
/**\brief Resta los numeros entre si
 * \param pResultado guarda el resultado de la suma en la dirreccion de memoria suministrada
 * \param operador1 el valor del primer numero
 * \param operador2 el valor del segundo numero
 * \return 0 si esta bien y -1 si hubo algun error
 */
int restar (float* pResultado,float operador1,float operador2)
{
	int retorno=-1;
	float total;
	if(pResultado!=NULL)
	{
		retorno=0;
		total=operador1-operador2;
		*pResultado=total;
	}

	return retorno;
}
/**\brief Multiplica los numeros entre si
 * \param pResultado guarda el resultado de la suma en la dirreccion de memoria suministrada
 * \param operador1 el valor del primer numero
 * \param operador2 el valor del segundo numero
 * \return 0 si esta bien y -1 si hubo algun error
 */
int multiplicar (float* pResultado,float operador1,float operador2)
{
	int retorno=-1;
	float total;
	if(pResultado!=NULL)
	{
		retorno=0;
		total=operador1*operador2;
		*pResultado=total;
	}
	return retorno;
}
/**\brief Divide los numeros entre si
 * \param pResultado guarda el resultado de la suma en la dirreccion de memoria suministrada
 * \param operador1 el valor del primer numero
 * \param operador2 el valor del segundo numero
 * \return 0 si esta bien y -1 si hubo algun error
 */
int dividir (float* pResultado,float operador1,float operador2)
{
	float resultado;
	int retorno = -1;

	if(pResultado != NULL && operador2 != 0)
	{
		resultado = operador1 / operador2;
		*pResultado = resultado;
		retorno=0;
	}
	return retorno;
}
/**\brief Calcula el factorial de un numero
 * \param pResultado guarda el resultado de la suma en la dirreccion de memoria suministrada
 * \param operador1 el valor del numero
 * \return 0 si esta bien y -1 si hubo algun error
 */
int factorial (int* pResultado,int operador)
{
	int retorno=-1;
	int i;
	int resultado=1;

	if(pResultado!= NULL)
	{
		if(operador==0)
		{
			*pResultado=1;
			retorno=0;
		}
		else if(operador>0)
		{
			retorno=0;
			for(i=operador;i>0;i--)
			        {
			            resultado=resultado*i;
			        }
			 *pResultado=resultado;
		}
	}
    return retorno;
}
/**\brief Imprime por consola los resultados de todas las operaciones (suma,resta,multiplicacion,division,factorial),
 * en las 2 ultimas operaciones evaluara el caso e imprimira segun corresponda.
 * \param operadorA el valor del primer numero
 * \param operadorB el valor del segundo numero
 * \param suma resultado de dicha operacion
 * \param resta resultado de dicha operacion
 * \param producto resultado de dicha operacion
 * \param division resultado de dicha operacion
 * \param factorialA resultado de dicha operacion
 * \param factorialB resultado de dicha operacion
 * \param retornoDiv es la variable que guarda un numero
 * \param retornoFactA es la variable que guarda un numero
 * \param retornoFactB es la variable que guarda un numero
 * \return void
 */

void imprimirResultados (float operadorA,float operadorB,float suma,float resta,float producto,float division, int factorialA, int factorialB,int retornoDiv, int retornoFactA,int retornoFactB)
{

	printf("\nEl resultado de %.3f+%.3f es: %.3f\n",operadorA,operadorB,suma);
	printf("El resultado de %.3f-%.3f es: %.3f\n",operadorA,operadorB,resta);
	printf("El resultado de %.3f*%.3f es: %.3f\n",operadorA,operadorB,producto);
	if(retornoDiv!=0)
	{
		printf("ERROR, prohibido dividir por 0 (cero)\n");
	}else
	{
		printf("El resultado de %.3f/%.3f es: %.3f\n",operadorA,operadorB,division);
	}

	printf("\n\nACLARACION, los numeros decimales han sido truncados para realizar dicho factorial.\n\n");

	if((retornoFactA && retornoFactB)!=0)
	{
		printf("No se puede realizar el factorial de numeros negativos");
	}
	else if((retornoFactA==0 && retornoFactB!=0)||(retornoFactA!=0 && retornoFactB==0))
	{
		if(retornoFactA==0)
		{
			printf("El factorial de %.3f es: %d\tEl factorial de %.3f no se puede realizar (numero negativo)\n",operadorA,factorialA,operadorB);
		}
		else
		{
			printf("El factorial de %.3f no se puede realizar (numero negativo)\tEl factorial de %.3f es: %d\n",operadorA,operadorB,factorialB);
		}
	}
	else
	{
		printf("El factorial de %d es: %d\tEl factorial de %d es: %d\n",(int)operadorA,factorialA,(int)operadorB,factorialB);
	}
}

/**\brief Solicita al usuario un numero entero
 * pResultado variable que guardara el dato del usuario
 * mensaje interaccion con el usuario
 * mensajeError mensaje para que el usuario sea notificado de un error
 * minimo numero minimo de la funcion
 * maximo numero maximo de la funcion
 * reintentos cantidad de oportunidades para que el usuario ingrese el dato correcto
*/
int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos)
{
	setbuf(stdout,NULL);
	int retorno=-1;
	int bufferInt;
	if(pResultado!= NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%d",&bufferInt);
	}
	if(bufferInt<minimo||bufferInt>maximo)
	{
		for(;reintentos>0;reintentos--)
			{
				printf("%s",mensaje);
				fflush(stdin);
				scanf("%d",&bufferInt);

				if(!(bufferInt<minimo||bufferInt>maximo))
				{
					*pResultado=bufferInt;
					retorno=0;
					break;
				}
			}
	}
	else
	{
		*pResultado=bufferInt;
		retorno=0;
	}
	return retorno;
}
/**\brief Solicita al usuario un numero decimal
 * pResultado variable que guardara el dato del usuario
 * mensaje interaccion con el usuario
 * mensajeError mensaje para que el usuario sea notificado de un error
 * minimo numero minimo de la funcion
 * maximo numero maximo de la funcion
 * reintentos cantidad de oportunidades para que el usuario ingrese el dato correcto
*/
int utn_getNumeroFlotante(float* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos)
{
	setbuf(stdout,NULL);
	int retorno=-1;
	float bufferFloat;
	if(pResultado!= NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%f",&bufferFloat);
	}
	if(bufferFloat<minimo||bufferFloat>maximo)
	{
		for(;reintentos>0;reintentos--)
			{
				printf("%s",mensaje);
				fflush(stdin);
				scanf("%f",&bufferFloat);

				if(!(bufferFloat<minimo||bufferFloat>maximo))
				{
					*pResultado=bufferFloat;
					retorno=0;
					break;
				}
			}
	}
	else
	{
		*pResultado=bufferFloat;
		retorno=0;
	}
	return retorno;
}
/**\brief Solicita al usuario un caracter
 * pResultado variable que guardara el dato del usuario
 * mensaje interaccion con el usuario
 * mensajeError mensaje para que el usuario sea notificado de un error
 * minimo numero minimo de la funcion
 * maximo numero maximo de la funcion
 * reintentos cantidad de oportunidades para que el usuario ingrese el dato correcto
*/
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos)
{
	setbuf(stdout,NULL);
	int retorno=-1;
	char bufferChar;
	if(pResultado!= NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%c",&bufferChar);
	}
	bufferChar=tolower(bufferChar);
	if(bufferChar<minimo||bufferChar>maximo)
	{
		for(;reintentos>0;reintentos--)
			{
				printf("%s",mensaje);
				fflush(stdin);
				scanf("%c",&bufferChar);

				if(!(bufferChar<minimo||bufferChar>maximo))
				{
					*pResultado=bufferChar;
					retorno=0;
					break;
				}
			}
	}
	else
	{
		*pResultado=bufferChar;
		retorno=0;
	}
	return retorno;
}
