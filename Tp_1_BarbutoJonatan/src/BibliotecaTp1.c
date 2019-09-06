/*
 * BibliotecaTp1.c
 *
 *  Created on: 31 ago. 2019
 *      Author: alumno
 */

#include <stdio.h>


int sumar(int pNumeroA, int pNumeroB,int *pSuma)
{
	*pSuma = pNumeroA+pNumeroB;
	return 0;
}

int restar(int pNumeroA,int pNumeroB,int *pResta)
{
	*pResta = pNumeroA-pNumeroB;
	return 0;
}

int multiplicar(int pNumeroA,int pNumeroB,int *pMultiplicacion)
{
	*pMultiplicacion = pNumeroA*pNumeroB;
	return 0;
}

int dividir(int pNumeroA,int pNumeroB,float *pDivision)
{
	if(pNumeroB==0)
	{
		printf("No es posible dividir por cero");
	}
	else
	*pDivision = pNumeroA/pNumeroB;
	return 0;

}

int factorizar(int pNumeroA, int pNumeroB,int *pFactorialA, int *pFactorialB)
{
	int i=1;
	int aFact=1;
	int bFact=1;

	if(pNumeroA<0)
	{
		*pFactorialA=0;
	}
	if(pNumeroA==0)
	{
		*pFactorialA=1;
	}
	else
	{
		for(i=1;i<=pNumeroA;i++)
		{
			aFact=aFact*i;
		}
	*pFactorialA=aFact;
	}
	if(pNumeroB<0)
	{
		*pFactorialB=0;
	}
	if(pNumeroB==0)
	{
		*pFactorialB=1;
	}
	else
	{
		for(i=1;i<=pNumeroB;i++)
		{
			bFact=bFact*i;
		}
	*pFactorialB=bFact;
	}
	return 0;
}

int mostrarMenu(int *eleccionMenu,int *numeroA,int *numeroB)
{
	int flagA=0;
	int flagB=0;
	int flag3=0;
	int resultSuma;
	int resultResta;
	int resultMultiplicacion;
	float resultDivision;
	int resultFactorialA;
	int resultFactorialB;
	int flagMenu=0;


	do
	{
		if(flagMenu==0)
		{
			printf("1. Ingresar 1er operando (A=x)\n"
				"2. Ingresar 2do operando (B=y)\n"
				"3. Calcular todas las operaciones\n"
				"\ta) Calcular la suma (A+B)\n"
				"\tb) Calcular la resta (A-B)\n"
				"\tc) Calcular la division (A/B)\n"
				"\td) Calcular la multiplicacion (A*B)\n"
				"\te) Calcular el factorial (A!)\n"
				"4. Informar resultados\n"
				"\ta) El resultado de A+B es: r\n"
				"\tb) El resultado de A-B es: r\n"
				"\tc) El resultado de A/B es: r\n"
				"\td) El resultado de A*B es: r\n"
				"\te) El factorial de A es: r1 y El factorial de B es: r2\n"
				"5. Salir\n");

			scanf("\n%d",&*eleccionMenu);
		}
		if(flagMenu==1)
		{
			printf("1. Ingresar 1er operando (A=%d)\n"
					"2. Ingresar 2do operando (B=%d)\n"
					"3. Calcular todas las operaciones\n"
					"\ta) Calcular la suma (A+B)\n"
					"\tb) Calcular la resta (A-B)\n"
					"\tc) Calcular la division (A/B)\n"
					"\td) Calcular la multiplicacion (A*B)\n"
					"\te) Calcular el factorial (A!)\n"
					"4. Informar resultados\n"
					"\ta) El resultado de A+B es: %d\n"
					"\tb) El resultado de A-B es: %d\n",*numeroA,*numeroB,resultSuma,resultResta);

			if(*numeroB !=0)
			{
				printf("\tc) El resultado de A/B es: %.2f\n",resultDivision);
			}
			else
			{
				printf("\tc)No es posible dividir por cero\n");
			}
			printf("\td) El resultado de A*B es: %d\n"
				   "\te) El factorial de A es: %d y El factorial de B es: %d\n"
				   "5. Salir\n",resultMultiplicacion,resultFactorialA,resultFactorialB);

			scanf("\n%d",&*eleccionMenu);
		}


		switch(*eleccionMenu)
		{
			case 1:
				printf("Ingrese valor de A\n");
				scanf("\n%d",&*numeroA);
				flagA=1;
				break;
			case 2:
				printf("Ingrese valor de B\n");
				scanf("\n%d",&*numeroB);
				flagB=1;
				break;
			case 3:
				if(flagA==1 && flagB==1)
				{
					sumar(*numeroA,*numeroB,&resultSuma);
					restar(*numeroA,*numeroB,&resultResta);
					multiplicar(*numeroA,*numeroB,&resultMultiplicacion);
					dividir(*numeroA,*numeroB,&resultDivision);
					factorizar(*numeroA,*numeroB,&resultFactorialA,&resultFactorialB);
					flag3=1;
				}
				else
				{
					printf("Falta ingresar un valor\n");
				}
				flag3=1;
				break;
			case 4:
				if(flag3==1)
				{
					flagMenu=1;
				}
				else
				{
					printf("Falta realizar los calculos\n");
				}

				break;
			case 5:
				break;
			}
	}while(*eleccionMenu != 5);
	return 0;
}
