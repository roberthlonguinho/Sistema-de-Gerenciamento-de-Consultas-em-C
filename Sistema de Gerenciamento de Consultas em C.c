#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//----------ALUNO-----------
// ROBERTH LONGUINHO DAVINO 

FILE *arq; // ponteiro para o arquivo.

struct consulta // variavel estruturada/para cadrastro das consultas.
{
  int CRM;
  char ESPC[100];
  int CPF;
  char NOME[100];
  int DIA, MES, HR, MNT;
};

int cont = 0; // contador para inclementar novas posicoes de cadrastro.

struct consulta limite[100]; // vetor que indica o limite de cnsultas que podem
                             // ser feitas no progama.

struct consulta cadastro() // funcao para o cadastro das consultas.
{

  struct consulta x;
  int i;
  arq=fopen("siscomed.bin","ab");
  printf(" Insira seu CRM:\n");
  scanf(" %d", &x.CRM);
  printf(" Insira a sua Epecialidade:\n");
  scanf(" %[^\n]", x.ESPC);
  printf(" Insira o N� do seu CPF:\n");
  scanf(" %d", &x.CPF);
  printf(" Insira seu Nome e Sobrenome:\n");
  scanf(" %[^\n]", x.NOME);
  printf(" Insira o DATA e M�S que deseja agendar sua consulta:\n");
  scanf(" %d %d", &x.DIA, &x.MES);
  printf(" Insira Horario que deseja ser Atendido :\n");
  scanf(" %d %d", &x.HR, &x.MNT);
  int jacadastrado = 0;

  for (i = 0; i < cont; i++) {

    if (limite[i].CPF == x.CPF && limite[i].DIA == x.DIA &&
        limite[i].MES == x.MES) {
      printf("\n Erro consulta ja cadrastrada \n");
      printf("\n-----------------------------\n");
      jacadastrado = 1;
    }
  }
  if (jacadastrado) {
    x.CPF = -1;
    return x;
  }
  printf("\nConsulta cadrastrada\n");
  printf("\n-----------------------------\n");
  fwrite(&x, sizeof(struct consulta), 1, arq);
  fclose(arq);
  return x;

}


void psq(struct consulta y){

  arq = fopen("siscomed.bin", "rb");
  while(fread(&y, sizeof(struct consulta), 1, arq)){
    printf("O CRM da consulta e:%d\n", y.CRM);
    printf("A especialidade da consulta e:%s\n", y.ESPC);
    printf("O cpf da consulta e:%d\n", y.CPF);
    printf("O nome do paciente e:%s\n", y.NOME);
    printf("O dia e mes da consulta e: %d %d\n", y.DIA, y.MES);
    printf("A hora e minutos da consulta e: %d %d\n", y.HR, y.MNT);
    printf("\n-----------------------------\n");

  }

}

void psqCRM(struct consulta y){
  int CRM;
  printf(" Insira o CRM para pesquisa:\n");
  scanf(" %d", &CRM);

    arq = fopen("siscomed.bin", "rb");
    while(fread(&y, sizeof(struct consulta), 1, arq)){
        if(y.CRM==CRM){

      printf("\n-----------------------------\n");
      printf("O CRM da consulta e:%d\n", y.CRM);
      printf("A especialidade da consulta e:%s\n", y.ESPC);
      printf("O cpf da consulta e:%d\n", y.CPF);
      printf("O nome do paciente e :%s\n", y.NOME);
      printf("O dia e mes da consulta e: %d %d\n", y.DIA, y.MES);
      printf("A hora e minutos da consulta e: %d %d\n", y.HR, y.MNT);
      printf("\n-----------------------------\n");
    }
}

}
  void psqESPC(struct consulta y){
  char ESPC[100];
  printf(" Insira a especialidade para pesquisa:\n");
  scanf(" %[^\n]",ESPC);
    arq = fopen("siscomed.bin", "rb");
    while(fread(&y, sizeof(struct consulta), 1, arq)){
      if(strcmp (ESPC,y.ESPC)==0){
      printf("\n-----------------------------\n");
      printf("O CRM da consulta e:%d\n", y.CRM);
      printf("A especialidade da consulta e:%s\n", y.ESPC);
      printf("O cpf da consulta e:%d\n", y.CPF);
      printf("O nome do paciente e:%s\n", y.NOME);
      printf("O dia e mes da consulta e: %d %d\n", y.DIA, y.MES);
      printf("A hora e minutos da consulta e: %d %d\n", y.HR, y.MNT);
      printf("\n-----------------------------\n");
    }
}
    
}
      void psqCPF(struct consulta y){
        int CPF;
        printf(" Digite o seu numero de CPF para pesquisar CONSULTA:\n");
        scanf(" %d", &CPF);
          arq = fopen("siscomed.bin", "rb");
          while(fread(&y, sizeof(struct consulta), 1, arq)){
            if(CPF == y.CPF){
            printf("\n-----------------------------\n");
            printf("O CRM da consulta e:%d\n", y.CRM);
            printf("A especialidade da consulta e:%s\n", y.ESPC);
            printf("O cpf da consulta e:%d\n", y.CPF);
            printf("O nome do paciente e:%s\n", y.NOME);
            printf("O dia e mes da consulta e: %d %d\n", y.DIA, y.MES);
            printf("A hora e minutos da consulta e: %d %d\n", y.HR, y.MNT);
            printf("\n-----------------------------\n");
          }
      
    }
  }


    void psqDM(struct consulta y){
      int DIA, MES;
      printf(" Insira DATA E MES para pesquisa de CONSULTA: \n");
      printf(" Digite o DIA:\n");
      scanf(" %d", &DIA);
      printf(" Digite o MES \n");
      scanf(" %d", &MES);
        arq = fopen("siscomed.bin", "rb");
        while(fread(&y, sizeof(struct consulta), 1, arq)){
          if(DIA == y.DIA && MES == y.MES){
          printf("\n-----------------------------\n");
          printf("O CRM da consulta e:%d\n", y.CRM);
          printf("A especialidade da consulta e:%s\n", y.ESPC);
          printf("O cpf da consulta e:%d\n", y.CPF);
          printf("O nome do paciente e:%s\n", y.NOME);
          printf("O dia e mes da consulta e: %d %d\n", y.DIA, y.MES);
          printf("A hora e minutos da consulta e: %d %d\n", y.HR, y.MNT);
          printf("\n-----------------------------\n");
        }

  }
}

int main() {
  int opcao; // variavel para escolha de uma op��o do menu.

  struct consulta p; // variavel estruturada para chama da fun��o cadrastro.

  do // opcoes do menu/dentro do la�o de repeti��o.
  {

    printf("----------MENU DE OPCOES-----------\n");
    printf("1. CADRASTRO DE CONSULTA:\n");
    printf("2. PESQUISA DE CONSULTAS:\n");
    printf("3. PESQUISA DE CONSULTAS CRM:\n");
    printf("4. PESQUISA DE CONSULTAS POR ESPC:\n");
    printf("5. PESQUISA DE CONSULTAS POR CPF:\n");
    printf("6. PESQUISA DE CONSULTAS POR DIA/MES:\n");
    printf("7. SAIR DO SISTEMA");
    printf("\n------------------------------------\n");
    printf(" ESCOLHA UMA OPCAO:\n");
    scanf(" %d", &opcao);
    printf("\n------------------------------------\n");


    switch (opcao) // switch de opcoes.
    {

    case 1:           // opcao de cadrastro.
      p = cadastro(); // chamada da fun��o.
      if (p.CPF > -1) {
        limite[cont] = p;
        cont++;
      }
      
    break;

    case 2:
    psq(p);
    break;

    case 3:
    psqCRM(p);
    break;

    case 4:
    psqESPC(p);
    break;

    case 5:
    psqCPF(p);
    break;

    case 6:
    psqDM(p);
    break;
  
    }

  } while (opcao != 7);
}

