//Prontuário do Paciente
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct dataNasc{
  int dia;
  int mes;
  int ano;
};

struct dataSintomas{
  int mes;
  int ano;
};

struct prontuario{
  char nome[100];
  long long cpf_pessoa;
  long long rg_pessoa;
  struct dataNasc DataNasc;
  char sexo; //m = masculino ou f = feminino.
  char nomeMae[100];
  char endereco[200];
  long cep;
  long long contato;
  char problemasRelatados[100];
  char tipoProblema[50];
  struct dataSintomas inicioSint;
  char doencas[200];
  float pressaoArterial;
  float indiceGlicemico;
  long protocoloAtendimento;
};

int main(){
  int n, qtdePessoas = 0;
  int posicao, aux;
  char escolha; //s = sim ou n = não.

  printf("\nSeja bem-vindo(a) ao PacientRegister!\n\n");

  printf("\nQuantas pessoas se deseja registrar? ");
  scanf("%d", &qtdePessoas);

  struct prontuario Prontuario[qtdePessoas];

  printf("\n\n");

  for(n = 1; n <= qtdePessoas; n++){
    printf("\nInsira o número do protocolo para registro do(a) paciente: ");
    scanf("%ld", &Prontuario[n].protocoloAtendimento);
    printf("\nQual é o nome do(a) paciente? ");
    scanf("%s", Prontuario[n].nome);
    printf("\nSexo (m/f): ");
    scanf("%s", &Prontuario[n].sexo);
    printf("\nData De Nascimento: ");
    printf("\n\tDia: ");
    scanf("%d", &Prontuario[n].DataNasc.dia);
    if(Prontuario[n].DataNasc.dia <= 0 && Prontuario[n].DataNasc.dia > 31){
      printf("\nDia inválido!");
    }
    printf("\tMês: ");
    scanf("%d", &Prontuario[n].DataNasc.mes);
    if(Prontuario[n].DataNasc.mes < 1 && Prontuario[n].DataNasc.mes > 12){
      printf("\nMês inválido!\n");
    }
    printf("\tAno: ");
    scanf("%d", &Prontuario[n].DataNasc.ano);
    if(Prontuario[n].DataNasc.ano < 0){
      printf("\nAno inválido!\n");
    }
    printf("\nCPF: ");
    scanf("%lld", &Prontuario[n].cpf_pessoa);  
    printf("\nRG: ");
    scanf("%lld", &Prontuario[n].rg_pessoa);
    printf("\nNome da Mãe: ");
    scanf("%s", Prontuario[n].nomeMae);
    printf("\nEndereço: ");
    scanf("%s", Prontuario[n].endereco);
    printf("\nCEP: ");
    scanf("%ld", &Prontuario[n].cep);
    printf("\nTelefone para contato: ");
    scanf("%lld", &Prontuario[n].contato);
    printf("\nQuais são os problemas que %s relata? ", Prontuario[n].nome);
    scanf("%s", Prontuario[n].problemasRelatados);
    printf("\nO problema relatado apresenta qual tipo de intensidade? ");
    scanf("%s", Prontuario[n].tipoProblema);
    printf("\nData de início dos sintomas: ");
    printf("\n\tMês: ");
    scanf("%d", &Prontuario[n].inicioSint.mes);
    if(Prontuario[n].inicioSint.mes < 1 && Prontuario[n].inicioSint.mes > 31){
      printf("\n\tMês inválido!\n");
    }
    printf("\tAno: ");
    scanf("%d", &Prontuario[n].inicioSint.ano);
    if(Prontuario[n].inicioSint.ano < 0){
      printf("\n\tAno inválido!\n");
    }
    printf("\nQual o histórico de doenças ocorridas com %s? ", Prontuario[n].nome);
    scanf("%s", Prontuario[n].doencas);
    printf("\nQual a pressão arterial do(a) paciente no momento da consulta? ");
    scanf("%f", &Prontuario[n].pressaoArterial);
    printf("\nQual o índice glicêmico que o(a) paciente apresentou durante a consulta? ");
    scanf("%f", &Prontuario[n].indiceGlicemico);
    //Fim
    printf("\n\n\tPaciente %d registrado!\n\n", n);

  }

  do{
    printf("\n\nQuer continuar (s = sim ou n = não)? ");
    scanf("%s", &escolha);
    if(escolha == 's'){
      printf("\nQual o número da posição do(a) paciente? ");
      scanf("%d", &posicao);
      aux = posicao;
      n = aux;
      if(posicao >= 1 && posicao <= qtdePessoas){
        printf("\nA posição %d refere-se ao(à) paciente de protocolo %ld, onde: \nNome do paciente: %s \nCPF: %lld \nRG: %lld \nData de Nascimento: %d/%d/%d \nSexo: %c \nNome da mãe: %s \nEndereço: %s - CEP: %ld \nTelefone de contato: %lld \nProblemas Relatados: %s \nIntensidade dos sintomas: %s \nInício dos sintomas: %d/%d \nHistórico de doenças: %s \nPressão Arterial aferida: %.2f \nÍndice Glicêmico medido: %.2f\n\n", n, Prontuario[n].protocoloAtendimento, Prontuario[n].nome, Prontuario[n].cpf_pessoa, Prontuario[n].rg_pessoa, Prontuario[n].DataNasc.dia, Prontuario[n].DataNasc.mes, Prontuario[n].DataNasc.ano, Prontuario[n].sexo, Prontuario[n].nomeMae, Prontuario[n].endereco, Prontuario[n].cep, Prontuario[n].contato, Prontuario[n].problemasRelatados, Prontuario[n].tipoProblema, Prontuario[n].inicioSint.mes, Prontuario[n].inicioSint.ano, Prontuario[n].doencas, Prontuario[n].pressaoArterial, Prontuario[n].indiceGlicemico);
      
      } else {
        printf("\n\tNão há registros de pacientes para a posição requerida!\n");
      }


    } else if(escolha == 'n'){
      printf("\n\tObrigado por utilizar nosso PacientRegister!\n");
    } else {
      printf("\n\tOpção inválida! Tente novamente...\n");
    }

  }while(escolha != 'n');


  return 0;
}