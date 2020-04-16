/*
 * utn.h
 *
 *  Created on: 15 abr. 2020
 *      Author: Nicolas
 */

#ifndef UTN_H_
#define UTN_H_

void menu(float valorDeA,float valorDeB);


int sumar(float* pResultado,float operador1,float operador2);
int restar(float* pResultado,float operador1,float operador2);
int multiplicar(float* pResultado,float operador1,float operador2);
int dividir(float* pResultado,int operador1,int operador2);
int factorial (int* pResultado,int operador);

void imprimirResultados(float operadorA,float operadorB,float suma,float resta,float producto,float division, int factorialA, int factorialB,int retornoDiv, int retornoFactA,int retornoFactB);


int utn_getNumero(int* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);
int utn_getCaracter(char* pResultado, char* mensaje,char* mensajeError, int minimo,int maximo,int reintentos);



#endif /* UTN_H_ */
