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

  printf("PLATAFORMA DE GERENCIAMENTO DE ASSINATURAS\n\n");
  printf("Escolha umas das seguintes opcoes:\n");
  printf("1 - Cadastrar um novo usuario.\n");
  printf("2 - Cadastrar um novo servico de streaming.\n");
  printf("3 - Consultar dados de uma assinatura.\n\n");

  int a;
  scanf("%d", &a);
  return a;
}

int consulta_assinatura(int a) {

  printf("CONSULTA DE DADOS DE ASSINATURAS\n\n");
  printf("Escolha umas das seguintes opcoes:\n");
  printf("1 - Consulta por cliente.\n");
  printf("2 - Consulta por plataforma.\n");
  printf("3 - Consultar assinatura especifica.\n\n");

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

  int teste;

  teste = menu_principal();
  limpar_terminal();

  if (teste <= 0 || teste > 3) {
    while (1) {
      limpar_terminal();
      printf("Por favor insira uma opcao valida!\n");
      teste = menu_principal();
      if (teste >= 1 && teste <= 3) {
        break;
      }

    }
  }
  limpar_terminal();

  if (teste == 1) {

    limpar_terminal();
  } else if (teste == 2) {

    limpar_terminal();
  } else {
    consulta_assinatura(teste);
    limpar_terminal();
  }

  return 0;

}