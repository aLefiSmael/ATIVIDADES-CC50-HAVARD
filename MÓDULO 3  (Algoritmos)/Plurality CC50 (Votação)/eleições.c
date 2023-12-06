/* PROGRAMA FEITO PARA FAZER UMA ELEI��O COM NO M�MINO 2 E NO M�XIMO 9 CANDIDOS, E NO MINIMO 1 ELEITOR O NO M�NIMO 100 ELEITORES*/
             /*A INFORMA��O DA QUANTIDADE DE CANDIDATOS E ELEITORES DEVE SER PASSADO NO IN�CIO ANTES DA VOTA��O*/

             #include <stdio.h>
             #include <math.h>
             #include <ctype.h>
             #include <locale.h>
             #include <string.h>

struct candidato_eleicao
{
    char nome[20];
    int votos;
};
            

int main(void)
{
    setlocale(LC_ALL,"Portuguese_Brazil");
    
    printf("PROGRAMA FEITO PARA FAZER UMA ELEI��O COM NO M�NIMO 2 E NO M�XIMO 9 CANDIDOS, E NO MINIMO 1 ELEITOR O NO M�XIMO 100 ELEITORES.\n\n");
    int filtro;
    
    /*AQUI EU PEGO A QUANTIDADE DE CANDIDATOS NAS ELEI��ES*/

    char ncandidatosletra[100]; /*USEI UMA ARRAY DE 100 PARA EVITAR BUGS POR PARTE DO USU�RIO AO INFORMAR O N�MERO, COMO POR EXEMPLO DIGITAR LETRAS. */
    int ncandidatos;

    do
    {
    printf("\nINFORME A QUANTIDADE DE CANDIDATOS QUE IR�O PARTICIPAR DO VOTA��O.(M�NIMO 2 E NO M�XIMO 9 CANDIDOS): ");
    fgets(ncandidatosletra,100,stdin);
    filtro = 0;
    ncandidatos = atoi(ncandidatosletra);
    if (isdigit(ncandidatosletra[0])&&(isspace(ncandidatosletra[1]))&&((1<ncandidatos)&&(ncandidatos<10))) /*FILTRO EXCELENTE PARA EVITAR BUGS, COMO UM CARACTERE ACABAR SE PASSANDO POR INT*/
    filtro=1;       

    } while (filtro==0);

    /*AGORA � A ETAPA DE PEGAR O NOME DE TODOS OS CANDITADOS, E DEIXAR TODOS COM 0 VOTOS INICIALMENTE*/

    struct candidato_eleicao candidato[ncandidatos];

    printf("\nAGORA INFORME O NOME DOS %d CANDITADOS.(S� pode usar letras sem acento, n�o pode usar outro tipo de caractere.",ncandidatos);
    for (int i = 0; i < ncandidatos; i++)
    {
        do
        {
        printf("\nQUAL � O NOME DO %d CANDIDATO?\n",i+1);
        fgets(candidato[i].nome,20,stdin);
        int tam = strlen(candidato[i].nome);
        filtro = 1;
        
        for (int n = 0; n < tam; n++)
        {
        if(!(isalpha(candidato[i].nome[n])))
        filtro = 0;
        break;
        }
        } while (filtro==0);
        
    }
    
    
    /*AQUI EU PEGO A QUANTIDADE DE ELEITORES NAS ELEI��ES*/

    char neleitoresletra[100]; /*USEI UMA ARRAY DE 100 PARA EVITAR BUGS POR PARTE DO USU�RIO AO INFORMAR O N�MERO, COMO POR EXEMPLO DIGITAR LETRAS. */
    int neleitores;

    do
    {
    printf("\nAGORA INFORME O N�MERO DE ELEITORES QUE IR�O PARTICIPAR DO VOTA��O.(M�NIMO 1 E NO M�XIMO 100 ELEITORES): ");
    fgets(neleitoresletra,100,stdin);
    filtro = 0;
    neleitores = atoi(neleitoresletra);
    if ((isdigit(neleitoresletra[0]))&&(isspace(neleitoresletra[1]))&&((0<neleitores)&&(neleitores<10)))
    filtro = 1;
    else if ((isdigit(neleitoresletra[0]))&&(isdigit(neleitoresletra[1]))&&(isspace(neleitoresletra[2]))&&((0<neleitores)&&(neleitores<100)))
    filtro = 1;
    else if (isdigit(neleitoresletra[0])&&isdigit(neleitoresletra[1])&&isdigit(neleitoresletra[2])&&(isspace(neleitoresletra[3]))&&(neleitores==100))
    filtro = 1;
    } while (filtro==0);

    /*AQUI EU INFORMO SOBRE AS ELEI��ES V�O COME�AR, E EU DOU AS INSTRU��ES*/

    printf("\nAS ELEI��ES COM %d CANDIDATOS E %d ELEITORES VAI COME�AR.\n",ncandidatos,neleitores);
    printf("\nOS NOMES DOS CANDIDATOS S�O: \n");
    for (int i = 0; i < ncandidatos; i++)
    {
        int tam = strlen(candidato[i].nome);
        for (int n = 0; n < tam-1; n++)
        {
        printf("%c",candidato[i].nome[n]);
        }
        if (i==ncandidatos-1)
        printf(".");
        else
        printf(", ");
    }
    
    printf("\nAGORA, PODEM VOTAR EM ORDEM ELEITORES, ESCREVA O NOME CORRETO DO CANDIDATO.RESPEITANDO LETRA MAIUSCULO A MIN�SCULA.\n\n");
    char voto[20];
    char nulo[] = "NULO\n";

    for (int i = 0; i < ncandidatos; i++)
    {
    candidato[i].votos=0;
    }
    
    
    for (int i = 0; i < neleitores; i++)
    {
      do
      {
        printf("POR FAVOR, ELEITOR N�MERO %d DE O SEU VOTO PARA UM CANDIDATO DIGITANDO O NOME DELE OU DIGITE 'NULO' PARA VOTAR NULO: ",i+1);
        fgets(voto,20,stdin);
        filtro = 0;

        for (int v = 0; v < ncandidatos; v++)
        {
        if (!(strcmp(voto,candidato[v].nome)))
        {
        filtro = 1;
        candidato[v].votos++;
        break;
        }
        }
        if (filtro==0)
        if (!(strcmp(voto,nulo)))
        filtro = 1;   
        
      } while (filtro == 0);
      
    }
    
    //AGORA VOU FAZER O CALCULO E INFORMAR O VENCEDOR, ESTOU FELIZ QUE DEU CERTO, POIS CUSTEI ARRUMAR O FILTRO PARA EVITAR BUGS, N�O � OBRIGAT�RIO NA TAREFA, MAS MELHOR ALGO MAIS COMPLEXO PARA EU APRENDER DE VERDADE*/
  
  int votacao1 = 0;
  int votacao2 = 0;
  char vencedor[20];

  for (int i = 0; i < ncandidatos; i++)
  {
    if ((candidato[i].votos>votacao1)&&(candidato[i].votos!=0))
    {
    votacao1 = candidato[i].votos;
    strcpy(vencedor,candidato[i].nome);
    }  
  }
   for (int i = 0; i < ncandidatos; i++)
  {
    if (strcmp(candidato[i].nome, vencedor))
    {
    if (candidato[i].votos>votacao2)
    {
    votacao2 = candidato[i].votos;
    }  
    }  
  }

  if ((votacao1!=0)&&(votacao2!=0)&&(votacao1)==(votacao2))
  printf("\nA ELEI��O TERMINOU EMPATADA.\n");
  else if(votacao1==0)
  printf("\nA ELEI��O N�O TEVE VENCEDORES, POIS HOUVE 0 VOTOS PARA TODOS OS CANDIDATOS.\n");
  else
  printf("\nO VENCEDOR DA ELEI��O FOI: %s\n",vencedor);
  
    
    system("pause");
    return(0);
}