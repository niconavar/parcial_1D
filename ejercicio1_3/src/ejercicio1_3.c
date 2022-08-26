/*
 ============================================================================
Ejercicio 1-3: ingresar 3 números y mostrar el número del medio, sólo si existe. En
caso de que no exista también informarlo.
Ejemplo:
1 5 3 el 3 es del medio
5 1 5 no hay número del medio
3 5 1 el 3 es del medio
3 1 5 el 3 es del medio
5 3 1 el 3 es del medio
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	setbuf(stdout,NULL);

	int num;
	int num2;
	int num3;

	printf("ingrese primer numero: \n");
	scanf("%d", &num);
	printf("ingrese segundo numero: \n");
	scanf("%d", &num2);
	printf("ingrese tercer numero: \n");
	scanf("%d", &num3);

	if(num > num2 && num <num3)
	{
		printf("el numero %d es el del medio de %d %d %d", num, num, num2, num3);
	}
	else
	{
		if(num2 > num && num2 < num3)
		{
			printf("el numero %d es el del medio de %d %d %d", num2, num, num2, num3);
		}
		else
		{
			if(num3 > num && num3 < num2)
			{
				printf("el numero %d es el del medio de %d %d %d", num3, num, num2, num3);
			}
			else
			{
				printf("no hay numero medio");
			}
		}
	}


	return EXIT_SUCCESS;
}
