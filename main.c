#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define max 50

//funcoes
void limpar_terminal() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

int menu_principal() {

  //Create Read Update Delete
  printf("PLATAFORMA DE GERENCIAMENTO DE ASSINATURAS\n\n");
  printf("Escolha umas das seguintes opcoes:\n");
  printf("1 - Realizar um cadastro de clientes, plataformas ou assinaturas.\n");
  printf("2 - Consultar os dados de clientes, plataformas, ou assinaturas.\n");
  printf("3 - Alterar as informacoes de clientes, plataformas ou assinaturas.\n");
  printf("4 - Excluir os dados de clientes, plataformas ou assinaturas.\n");
  printf("5 - Sair\n\n");

  int a;
  scanf("%d", &a);
  return a;
}

int realizar_cadastro(){

  printf("O que voce deseja cadastrar?\n\n");
  printf("1 - Cadastro de clientes.\n");
  printf("2 - Cadastro de plataformas.\n");
  printf("3 - Cadastro de assinaturas.\n");
  printf("4 - Voltar\n\n");

  int a;
  scanf("%d", &a);
  return a;
}

int realizar_consulta(){

  printf("O que voce deseja consultar?\n\n");
  printf("1 - Consultar clientes.\n");
  printf("2 - Consultar plataformas.\n");
  printf("3 - Consultar assinaturas.\n");
  printf("4 - Voltar\n\n");

  int a;
  scanf("%d", &a);
  return a;
}

int realizar_alteracao(){

  printf("O que voce deseja alterar?\n\n");
  printf("1 - Alterar dados de clientes.\n");
  printf("2 - Alterar dados de plataformas.\n");
  printf("3 - Alterar dados de assinaturas.\n");
  printf("4 - Voltar\n\n");

  int a;
  scanf("%d", &a);
  return a;
}

int realizar_exclusao(){

  printf("O que voce deseja excluir?\n\n");
  printf("1 - Excluir clientes.\n");
  printf("2 - Excluir plataformas.\n");
  printf("3 - Excluir assinaturas.\n");
  printf("4 - Voltar\n\n");

  int a;
  scanf("%d", &a);
  return a;
}

//structs
typedef struct {
  int dia;
  int mes;
  int ano;

}DATAS;

typedef struct {
  char nome[max];
  char cpf[14]; //contandos hifens e pontos
  int id_usuario; //campo unico da struct
  char phone[13]; //contando parenteses e hifens
  char email[max];

}USUARIOS;

typedef struct {
  char nome_plataforma[max]; //campo unico da struct
  int id_plataforma;
  char categoria[max];
  float preco;
  char site_url[max];

}PLATAFORMAS;

typedef struct {
  int id_usuario;
  int id_plataforma;
  int id_assinatura; //campo unico da struct
  DATAS data_inicio_assinatura;
  DATAS data_proxima_cobranca;
  int ativa;
  float valor_pago;

}ASSINATURAS;

int main() {

  while(1){
    
    limpar_terminal();

    int input;

    //escolha principal
    input = menu_principal();
    limpar_terminal();
    
    //forcando o usuario a escolher uma opcao valida
    if (input <= 0 || input > 5){
      while (1) {
        limpar_terminal();
        printf("Por favor insira uma opcao valida!\n");
        input = menu_principal();
        if(input >= 1 && input <= 5) {
          break;
        }

      }
    }

    limpar_terminal();

    while(1){

      if(input == 1){
        input = realizar_cadastro();
        //forcando o usuario a escolher uma opcao valida
        if(input <= 0 || input > 4){
          while (1) {
            limpar_terminal();
            printf("Por favor insira uma opcao valida!\n");
            input = realizar_cadastro();
            if(input >= 1 && input <= 4){
              break;
            }

          }
        }
        if(input == 4){
          break;
        }

      }else if(input == 2){
        input = realizar_consulta();

        //forcando o usuario a escolher uma opcao valida
        if(input <= 0 || input > 4){
          while (1) {
            limpar_terminal();
            printf("Por favor insira uma opcao valida!\n");
            input = realizar_consulta();
            if(input >= 1 && input <= 4) {
              break;
            }
          }
        }
        if(input == 4){
          break;
        }

      }else if(input == 3){
        input = realizar_alteracao();
        //forcando o usuario a escolher uma opcao valida
        if(input <= 0 || input > 4){
          while (1) {
            limpar_terminal();
            printf("Por favor insira uma opcao valida!\n");
            input = realizar_alteracao();
            if(input >= 1 && input <= 4) {
              break;
            }

          }
        }
        if(input == 4){
            break;
          }
      
      }else if(input == 4){
        input = realizar_exclusao();

        //forcando o usuario a escolher uma opcao valida
        if(input <= 0 || input > 4){
          while (1) {
            limpar_terminal();
            printf("Por favor insira uma opcao valida!\n");
            input = realizar_exclusao();
            if(input >= 1 && input <= 4) {
              break;
            }

          }
        }
        if(input == 4){
          break;
        }

      }else if(input == 5){
        return 0;
      }
    }
  }

  return 0;

}