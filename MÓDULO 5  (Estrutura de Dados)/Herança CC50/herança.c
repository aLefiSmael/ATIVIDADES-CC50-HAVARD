// Fazer um programa que simula o tipo sangu�neo de uma determinada gera��o

// As combina��es poss�veis de tipo sangu�neo, ent�o, s�o: OO, OA, OB, AO, AA, AB, BO, BA e BB.

// Para isso vou usar �rvore bin�ria e a fun��o rand() vai me ajudar a fazer a simula��o

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>

typedef struct arvore
{
    char sangue[3];
    struct arvore *left;
    struct arvore *right;

} arvore;

typedef arvore *ptr_arv;

void criarfamilia(ptr_arv arv, int aux, int sorteio);
void mostrarfamilia(char **familiares, ptr_arv arv, int ngeracoes, int aux);

int main()
{

    setlocale(LC_ALL, "Portuguese");

    srand(time(NULL));

    int sorteio = 0;

    printf("\nPROGRAMA FEITO PARA SIMULAR O TIPO SANGU�NEO DE UMA X GERA��O DE PARENTES SEUS COM BASE NO SEU TIPO SANGU�NEO.");
    printf("\nPOR EXEMPLO, SE SEU TIPO SANGU�NEO FOR AO, SUA M�E PODE TER O TIPO AB E SEU PAI BO.\n");

    printf("INFORME O SEU TIPO SANGU�NEO(LETRAS MAI�SCULAS exp:AB):  ");

    char user[3];
    scanf("%s", user);

    while ((strcmp(user, "OO")) && (strcmp(user, "OA")) && (strcmp(user, "OB")) && (strcmp(user, "AO")) && (strcmp(user, "AA")) && (strcmp(user, "AB")) && (strcmp(user, "BO")) && (strcmp(user, "BA")) && (strcmp(user, "BB")))
    {
        printf("\nTIPO SANGU�NEO INV�LIDO, INFORME O SEU TIPO SANGU�NEO(LETRAS MAI�SCULAS exp:AB):  ");
        scanf("%s", user);
    }

    printf("\nAGORA INFORME O N�MERO DE GERA��ES QUE VOC� DESEJA SIMULAR, M�NIMO 1 E M�XIMO 3:  ");
    int ngeracoes;
    scanf("%d", &ngeracoes);
    while (ngeracoes > 3 || ngeracoes < 1)
    {
        printf("\nN�MERO INV�LIDO,INFORME O N�MERO DE GERA��ES QUE VOC� DESEJA SIMULAR, M�NIMO 1 E M�XIMO 3:  ");
        scanf("%d", &ngeracoes);
    }

    printf("\n\n");

    int aux = ngeracoes;
    ngeracoes = 0;
    char aux2[10];
    char **familiares = malloc(3 * sizeof(aux2));
    familiares[0] = "PAIS";
    familiares[1] = "AV�S";
    familiares[2] = "BISAV�S";

    ptr_arv arv;
    arv = (ptr_arv)malloc(sizeof(arvore));
    strcpy(arv->sangue, user);
    arv->left = NULL;
    arv->right = NULL;

    criarfamilia(arv, aux, sorteio);
    mostrarfamilia(familiares, arv, ngeracoes, aux);

    for (int i = 2; i < 0; i--)
    {
        free(familiares[i]);
    }

    system("pause");
    return 0;
}

// sorteio = rand() % 3 + 1; // isso aqui serve para gerar o n�mero aleat�rio

void criarfamilia(ptr_arv arv, int aux, int sorteio)
{
    if (aux > 0)
    {
        aux--;
        arv->left = (ptr_arv)malloc(sizeof(arvore));
        arv->left->left = NULL;
        arv->left->right = NULL;
        do
        {
            sorteio = rand() % 3 + 1;
            switch (sorteio)
            {
            case 1:
                arv->left->sangue[0] = 'A';
                break;
            case 2:
                arv->left->sangue[0] = 'O';
                break;
            case 3:
                arv->left->sangue[0] = 'B';
                break;

            default:
                break;
            }
            sorteio = rand() % 3 + 1;
            switch (sorteio)
            {
            case 1:
                arv->left->sangue[1] = 'A';
                break;
            case 2:
                arv->left->sangue[1] = 'O';
                break;
            case 3:
                arv->left->sangue[1] = 'B';
                break;

            default:
                break;
            }
            arv->left->sangue[2] = '\0';
        } while ((arv->left->sangue[0] != arv->sangue[0]) && (arv->left->sangue[1] != arv->sangue[0]));

        criarfamilia(arv->left, aux, sorteio);
        arv->right = (ptr_arv)malloc(sizeof(arvore));
        arv->right->left = NULL;
        arv->right->right = NULL;
        do
        {
            sorteio = rand() % 3 + 1;
            switch (sorteio)
            {
            case 1:
                arv->right->sangue[0] = 'A';
                break;
            case 2:
                arv->right->sangue[0] = 'O';
                break;
            case 3:
                arv->right->sangue[0] = 'B';
                break;

            default:
                break;
            }
            sorteio = rand() % 3 + 1;
            switch (sorteio)
            {
            case 1:
                arv->right->sangue[1] = 'A';
                break;
            case 2:
                arv->right->sangue[1] = 'O';
                break;
            case 3:
                arv->right->sangue[1] = 'B';
                break;

            default:
                break;
            }
            arv->left->sangue[2] = '\0';
        } while ((arv->right->sangue[0] != arv->sangue[1]) && (arv->right->sangue[1] != arv->sangue[1]));
        criarfamilia(arv->right, aux, sorteio);
    }
}

void mostrarfamilia(char **familiares, ptr_arv arv, int ngeracoes, int aux)
{
    if (aux >= 0)
    {
        aux--;
        ngeracoes++;
        if (arv->left != NULL)
        {
            mostrarfamilia(familiares, arv->left, ngeracoes, aux);
        }
        if (arv->left != NULL)
        {
            mostrarfamilia(familiares, arv->right, ngeracoes, aux);
        }

        if (ngeracoes == 1)
        {
            printf("O SEU TIPO SANGU�NEO �:[%s].\n ", arv->sangue);
        }
        else
        {
            printf("O TIPO SANGU�NEO DE UM DOS SEUS %s �:[%s].\n ", familiares[ngeracoes - 2], arv->sangue);
        }

        free(arv);
    }
}