#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define max 50
#define max_usuarios 50

//menus
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
  char cpf[15]; //contandos hifens e pontos
  int id_usuario; //campo unico da struct
  char phone[14]; //contando parenteses e hifens
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

USUARIOS usuarios[max_usuarios];
int total_usuarios = 0;

//funcoes de cadastro
void cadastrar_usuario(){

  if(total_usuarios >= max_usuarios){
    printf("Limite de usuarios atingido!\n");
    return;
  }

  printf("Digite os dados do novo usuario.\n\n");
  printf("Nome: ");\
  getchar();
  fgets(usuarios[total_usuarios].nome, max, stdin);

  //pra remover o \n no final do nome do caba
  for(int i = 0; i < max; i++){
    if(usuarios[total_usuarios].nome[i] == '\n'){
      usuarios[total_usuarios].nome[i] = '\0';
    }
  }

  printf("CPF: ");
  fgets(usuarios[total_usuarios].cpf, 15, stdin);
  
  while(usuarios[total_usuarios].cpf[3]  != '.' || usuarios[total_usuarios].cpf[7]  != '.' || usuarios[total_usuarios].cpf[11] != '-'){

    limpar_terminal();
    printf("Digite os dados do novo usuario.\n\n");
    printf("Nome: %s\n", usuarios[total_usuarios].nome);
    printf("Por favor, insira o CPF no formato correto! (000.000.000-00)\n");
    printf("CPF: ");

    fgets(usuarios[total_usuarios].cpf, 15, stdin);
  }

  limpar_terminal();
  printf("Digite os dados do novo usuario.\n\n");
  printf("Nome: %s\n", usuarios[total_usuarios].nome);
  printf("CPF: %s\n", usuarios[total_usuarios].cpf);

  printf("Telefone: ");
  getchar();
  fgets(usuarios[total_usuarios].phone, 14, stdin);

  while(usuarios[total_usuarios].phone[0] != '(' || usuarios[total_usuarios].phone[3] != ')' || usuarios[total_usuarios].phone[8] != '-'){

    limpar_terminal();
    printf("Digite os dados do novo usuario.\n\n");
    printf("Nome: %s\n", usuarios[total_usuarios].nome);
    printf("CPF: %s\n", usuarios[total_usuarios].cpf);
    printf("Por favor, insira o TELEFONE no formato correto! (00)0000-0000\n");
    printf("Telefone: ");

    fgets(usuarios[total_usuarios].phone, 14, stdin);

  }

  limpar_terminal();
  printf("Digite os dados do novo usuario.\n\n");
  printf("Nome: %s\n", usuarios[total_usuarios].nome);
  printf("CPF: %s\n", usuarios[total_usuarios].cpf);
  printf("Telefone: %s\n", usuarios[total_usuarios].phone);

  int oi = 0;

  while(oi != 1){

    printf("Email: ");
    getchar();
    fgets(usuarios[total_usuarios].email, max, stdin);

    oi = 0;

    for(int i = 0; usuarios[total_usuarios].email[i] != '\0'; i++){
        if(usuarios[total_usuarios].email[i] == '@'){
            oi = 1;
            break;
        }
    }

    if(oi != 1){
      limpar_terminal();
      printf("Digite os dados do novo usuario.\n\n");
      printf("Nome: %s\n", usuarios[total_usuarios].nome);
      printf("CPF: %s\n", usuarios[total_usuarios].cpf);
      printf("Telefone: %s\n", usuarios[total_usuarios].phone);
      printf("Por favor, insira um Email valido!\n");
    }
  }

  //esse getchar eh pra forcar quem esta usando a apertar qualquer tecla pra continuar, mas a gente pode mudar isso depois
  limpar_terminal();
  printf("\nUsuario cadastrado com sucesso!\n");
  getchar();

  limpar_terminal();

  usuarios[max_usuarios].id_usuario++;
}

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
        if(input == 1){
          limpar_terminal();
          cadastrar_usuario();
        }
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