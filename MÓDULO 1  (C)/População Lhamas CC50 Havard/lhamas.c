/*PROGRAMA PARA CALCULAR QUANTIDADE DE ANOS NECESS�RIOS PARA A POPULA��O DE LHAMAS ADQUIRIREM UMA NOVA QUANTIDADE DA POPULA��O EM RELE��O A UMA ANTIGA INFORMADA.*/

#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(void)

{
 setlocale(LC_ALL,"portuguese_brazil");

 int populacaoinicial,populacaofinal,populacao,anos=0,vida=0,morte=0;

 printf("\nESSE PROGRAMA FOI CRIADO PARA CALCULAR QUANTIDADE DE ANOS NECESS�RIOS PARA A POPULA��O DE LHAMAS ADQUIRIREM UMA NOVA QUANTIDADE DA POPULA��O EM RELE��O A UMA ANTIGA INFORMADA.\n");

 // Solicite o valor inicial ao usu�rio

 printf("Informe o n�mero inicial da popula��o de lhamas:\n");
 scanf("%d",&populacaoinicial);
 while (getchar() != '\n');

 while (populacaoinicial<9)
 {
    printf("\nA popula��o de lhamas precisa ser de pelo menos 9,informe o n�mero inicial da popula��o de lhamas:\n");
    scanf("%d",&populacaoinicial);
    while (getchar() != '\n');
 }
 
 // Solicite o valor final ao usu�rio

 printf("\nInforme o n�mero final da popula��o de lhamas:\n");
 scanf("%d",&populacaofinal);
 while (getchar() != '\n');

 while (populacaofinal<populacaoinicial)
 {
    printf("\nA popula��o final de lhamas precisa ser igual ou maior a popula��o inicial,informe o n�mero final da popula��o de lhamas:\n");
    scanf("%d",&populacaofinal);
    while (getchar() != '\n');
 }

// Calcule o n�mero de anos at� o limite

populacao = populacaoinicial;

while (populacao<populacaofinal)
{
   vida=populacao/3;
   morte=populacao/4;
   populacao = (populacao + (vida - morte));
   anos++;
}

// Imprima o n�mero de anos

if (anos==1)
   printf("Ser� necess�rio 1 ano para a popula��o inicial de %d atingir %d lhamas.",populacaoinicial,populacaofinal);
else
   printf("Ser� necess�rio %d anos para a popula��o inicial de %d atingir %d lhamas.",anos,populacaoinicial,populacaofinal);

system("PAUSE");

return(0);

}