/*PROGRAMA DE UMA ATIVIDADE DO CC50 CRIADO PARA LER UM ARQUIVO E ENCONTAR IMAGENS QUE FORAM EXCLU�DAS*/

/*incluindo as bibliotecas que usarei no programa*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <locale.h>

typedef uint8_t BYTE; //defino uint8_t como BYTE para facilitar(8 bits)
 
int main(void)

{

/*aqui vou deixar como serto usar pt-br*/

setlocale(LC_ALL,"Portuguese_Brazil.1252");

/*vou come�ar abrindo o arquivo que irei ler*/

FILE *cartao  = fopen("card.raw","rb"); //ponteiro FILE que apontar� para o arquivo que eu irei ler


if(cartao==NULL)  //se houver erro ao abrir o arquivo � informado ao usu�rio

    {

    printf("ERRO AO ABRIR O ARQUIVO");

    system("pause");

    return(0);

    }


BYTE *leitor = malloc(512*sizeof(BYTE));  //cria ponteiro com 512 bytes de espa�o para ler os blocos

if (leitor == NULL) // Verifica se houve erro de mem�ria insuficiente e se houver retorna a informa��o ao usu�rio
   {

   printf("N�o h� mem�ria suficiente");
   fclose(cartao);
   system("pause");
   return (0);
  
   }

int tam = fread(leitor, sizeof(BYTE), 512, cartao); //int tam � uma vari�vel ver se � o �ltimo byte do arquivo

int fim = 0,foto = 0; // fim para determinar o fim do arquivo para parar de ler blocos e esse int foto � para ir nomeando as n fotos que ser�o recuperadas
char nomearq[20];
FILE *criarfoto = NULL;

while (fim == 0)
{

   if ((leitor[0] == 0xff) && (leitor[1] == 0xd8) && (leitor[2] == 0xff) && ((leitor[3] & 0xf0) == 0xe0))  //verifica os 4 primeiros bytes de um bloco de 512 bytes para ver se � um arquivo JPEG
{

    if (criarfoto!=NULL)
   {
    fclose(criarfoto);
   }

    sprintf(nomearq,"Foto_%03i.jpg",foto);

    foto++;

    criarfoto = fopen(nomearq,"wb");

    if (criarfoto==NULL)

    {

    printf("ERRO AO ABRIR O ARQUIVO");
    free(leitor);
    fclose(cartao);
    if (foto==1)
    fclose(criarfoto);
    
    system("pause");

    return(0);

    }
}

   if (criarfoto != NULL)
   {
   fwrite(leitor,sizeof(BYTE),512,criarfoto);
   }
   
   tam = fread(leitor,sizeof(BYTE),512,cartao);

   if (tam<512)
    {
        fim = 1;
    }

}

fclose(criarfoto);
fclose(cartao);
free(leitor);


return(0);

}