#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#define max 50
#define max_char 50
int idglobal_usuarios = 1000;

void limpar_terminal() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

//menus
int menu_principal() {

  //Create Read Update Delete
  printf("PLATAFORMA DE GERENCIAMENTO DE ASSINATURAS DE STREAMING\n\n");
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
  char cpf[15]; //campo unico da struct; 15 contandos hifens e pontos
  int id_usuario; 
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

USUARIOS usuarios[max];
int total_usuarios = 0;
PLATAFORMAS plataformas[max];
int total_plataformas = 0;

//funcoes de cadastro
void cadastrar_usuario(){

  if(total_usuarios >= max){
    limpar_terminal();
    printf("Limite de usuarios atingido!\n");
    getchar();
    return;
  }

  printf("Digite os dados do novo usuario.\n\n");
  printf("Nome: ");
  getchar();
  fgets(usuarios[total_usuarios].nome, max_char, stdin);

  //pra remover o \n no final do nome do caba
  for(int i = 0; i < max_char; i++){
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
    fgets(usuarios[total_usuarios].email, max_char, stdin);

    //removedor de \n
    for(int i = 0; i < max_char; i++){
      if(usuarios[total_usuarios].email[i] == '\n'){
        usuarios[total_usuarios].email[i] = '\0';
      }
    }

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

  idglobal_usuarios++;
  total_usuarios++;
  usuarios[max].id_usuario = idglobal_usuarios + 1;
}

void cadastrar_plataforma(){

  if(total_plataformas >= max){
    limpar_terminal();
    printf("Limite de plataformas atingido!\n");
    getchar();
    return;
  }

  printf("Digite os dados da nova plataforma.\n\n");
  printf("Nome: ");
  getchar();
  fgets(plataformas[total_plataformas].nome_plataforma, max_char, stdin);

  //pra remover o \n no final do nome do servico
  for(int i = 0; i < max_char; i++){
    if(plataformas[total_plataformas].nome_plataforma[i] == '\n'){
      plataformas[total_plataformas].nome_plataforma[i] = '\0';
    }
  }

  printf("Categoria: ");
  fgets(plataformas[total_plataformas].categoria, max_char, stdin);
  
  //pra remover o \n no final da categoria
  for(int i = 0; i < max_char; i++){
    if(plataformas[total_plataformas].categoria[i] == '\n'){
      plataformas[total_plataformas].categoria[i] = '\0';
    }
  }

  printf("Valor: R$");
  scanf("%f", &plataformas[total_plataformas].preco);

  

  printf("Site: ");
  getchar();
  fgets(plataformas[total_plataformas].site_url, max_char, stdin);

  int ponto_final = 0;

  while(ponto_final == 0){

    ponto_final = 0;

    for(int i = 0; plataformas[total_plataformas].site_url[i] != '\0'; i++){
      if(plataformas[total_plataformas].site_url[i] == '.'){
        ponto_final = 1;
        break;
      }
    }
    if(ponto_final == 0){
      limpar_terminal();
      printf("Digite os dados da nova plataforma.\n\n");
      printf("Nome: %s\n", plataformas[total_plataformas].nome_plataforma);
      printf("Categoria: %s\n", plataformas[total_plataformas].categoria);
      printf("Valor: R$%.2f\n", plataformas[total_plataformas].preco);
      printf("Por favor, insira um Site valido!\n");
      printf("Site: ");
      fgets(plataformas[total_plataformas].site_url, max_char, stdin);
    }
  }


  //pra remover o \n
  for(int i = 0; i < max_char; i++){
    if(plataformas[total_plataformas].site_url[i] == '\n'){
      plataformas[total_plataformas].site_url[i] = '\0';
    }
  }

  limpar_terminal();
  printf("\nPlataforma cadastrada com sucesso!\n");
  getchar();
  limpar_terminal();

}

//funcoes de consulta
void consultar_usuario(){

  char consulta_cpf[15];

  printf("Digite o CPF do usuario o qual os dados serao consultados:\n\n");
  getchar();
  fgets(consulta_cpf, 15, stdin);

  while(consulta_cpf[3] != '.' || consulta_cpf[7] != '.' || consulta_cpf[11] != '-'){

    limpar_terminal();
    printf("Por favor, insira o CPF no formato correto! (000.000.000-00)\n");
    printf("Digite o CPF do usuario o qual os dados serao consultados: \n\n");

    fgets(consulta_cpf, 15, stdin);
    
    //pra remover a quebra de linha
    for(int i = 0; i < 15; i++){
      if(consulta_cpf[i] == '\n'){
      consulta_cpf[i] = '\0';
      break;
      }
    }
  }

  int encontrado = 0;
  for(int i = 0; i < total_usuarios; i++){
    if(strcmp(usuarios[i].cpf, consulta_cpf) == 0){

      limpar_terminal();
      printf("Usuario encontrado!\n\n");
      printf("Nome: %s\n", usuarios[i].nome);
      printf("CPF: %s\n", usuarios[i].cpf);
      printf("Id do usuario: %d\n", usuarios[i].id_usuario);
      printf("Telefone: %s\n", usuarios[i].phone);
      printf("Email: %s\n", usuarios[i].email);

      encontrado = 1;
      break;
    }
  }

  if(encontrado == 0){
    limpar_terminal();
    printf("Usuario nao encontrado!\n\n");
    getchar();
  }

  getchar();
}

//funcoes de alteracao
void alterar_usuario(){

  char procurar_cpf[15];

  printf("Digite o CPF do usuario o qual os dados serao alterados: \n\n");
  getchar();
  fgets(procurar_cpf, 15, stdin);

  while(procurar_cpf[3] != '.' || procurar_cpf[7] != '.' || procurar_cpf[11] != '-'){

    limpar_terminal();
    printf("Por favor, insira o CPF no formato correto! (000.000.000-00)\n");
    printf("Digite o CPF do usuario o qual os dados serao alterados: \n\n");

    fgets(procurar_cpf, 15, stdin);
    
    //pra remover a quebra de linha
    for(int i = 0; i < 15; i++){
      if(procurar_cpf[i] == '\n'){
      procurar_cpf[i] = '\0';
      break;
      }
    }
  }

  /*esse inteiro "usuario" serve como um localizador do usuario apos ele ser encontrado,
  acredito que seria possivel utilizar ponteiros, mas ainda nao estou confiante pra isso*/
  int opcao_de_alteracao;
  int usuario = 0;
  int encontrado = 1;
  for(int i = 0; i < total_usuarios; i++){
    encontrado = strcmp(usuarios[i].cpf, procurar_cpf);
    if(encontrado == 0){

      while(1){
        usuario = i;
        limpar_terminal();
        printf("Qual dado do usuario sera alterado?\n");
        printf("Escolha uma das opcoes abaixo:\n\n");
        printf("1 - Nome: %s\n", usuarios[i].nome);
        printf("2 - CPF: %s\n", usuarios[i].cpf);
        printf("3 - Telefone: %s\n", usuarios[i].phone);
        printf("4 - Email: %s\n", usuarios[i].email);
        printf("5 - Voltar\n\n");

        scanf("%d", &opcao_de_alteracao);

        while(opcao_de_alteracao < 1 || opcao_de_alteracao > 5){
          limpar_terminal();
          printf("Qual dado do usuario sera alterado?\n");
          printf("Escolha uma das opcoes abaixo:\n");
          printf("Por favor escolha uma opcao valida!\n\n");
          printf("1 - Nome: %s\n", usuarios[i].nome);
          printf("2 - CPF: %s\n", usuarios[i].cpf);
          printf("3 - Telefone: %s\n", usuarios[i].phone);
          printf("4 - Email: %s\n", usuarios[i].email);
          printf("5 - Voltar\n\n");

          scanf("%d", &opcao_de_alteracao);
        }

        //alterar nome
        if(opcao_de_alteracao == 1){
          limpar_terminal();
          printf("Digite o novo nome do usuario:\n\n");
          getchar();
          fgets(usuarios[usuario].nome, max_char, stdin);

          //removedor de \n
          for(int i = 0; i < max_char; i++){
            if(usuarios[usuario].nome[i] == '\n'){
              usuarios[usuario].nome[i] = '\0';
            }
          }

          limpar_terminal();
          printf("Alteracao realizada com sucesso!\n");
          getchar();
        }

        //alterar cpf
        if(opcao_de_alteracao == 2){
          limpar_terminal();
          printf("Digite o novo CPF do usuario:\n\n");
          getchar();
          fgets(usuarios[usuario].cpf, 15, stdin);
        
          while(usuarios[usuario].cpf[3]  != '.' || usuarios[usuario].cpf[7]  != '.' || usuarios[usuario].cpf[11] != '-'){

          limpar_terminal();
          printf("Por favor, insira o CPF no formato correto! (000.000.000-00)\n");
          printf("Digite o novo CPF do usuario:\n\n");
          fgets(usuarios[usuario].cpf, 15, stdin);
          }

          limpar_terminal();
          getchar();
          printf("Alteracao realizada com sucesso!\n");
          getchar();
        }

        //alterar telefone
        if(opcao_de_alteracao == 3){
          limpar_terminal();
          printf("Digite o novo telefone do usuario:\n\n");
          getchar();
          fgets(usuarios[usuario].phone, 14, stdin);

          while(usuarios[usuario].phone[0] != '(' || usuarios[usuario].phone[3] != ')' || usuarios[usuario].phone[8] != '-'){

          limpar_terminal();
          printf("Por favor, insira o TELEFONE no formato correto! (00)0000-0000\n");
          printf("Digite o novo telefone do usuario:\n\n");
          fgets(usuarios[usuario].phone, 14, stdin);

          }

          limpar_terminal();
          getchar();
          printf("Alteracao realizada com sucesso!\n");
          getchar();
        }

        //alterar email
        if(opcao_de_alteracao == 4){
          limpar_terminal();
          printf("Digite o novo email do usuario:\n\n");
          getchar();
          fgets(usuarios[usuario].email, max_char, stdin);

          int a = 0;
          for(int i = 0; usuarios[usuario].email[i] != '\0'; i++){
            if(usuarios[usuario].email[i] == '@'){
              a = 1;
            }
          }

          //removedor de \n
          for(int i = 0; i < max_char; i++){
            if(usuarios[usuario].email[i] == '\n'){
              usuarios[usuario].email[i] = '\0';
            }
          }
          
          while(a != 1){
            limpar_terminal();
            printf("Por favor, insira um Email valido!\n");
            printf("Digite o novo email do usuario:\n\n");
            fgets(usuarios[usuario].email, max_char, stdin);

            //removedor de \n
            for(int i = 0; i < max_char; i++){
              if(usuarios[usuario].email[i] == '\n'){
                usuarios[usuario].email[i] = '\0';
              }
            }

            for(int i = 0; usuarios[usuario].email[i] != '\0'; i++){
            if(usuarios[usuario].email[i] == '@'){
              a = 1;
            }
            }
          }

        limpar_terminal();
        printf("Alteracao realizada com sucesso!\n");
      }

        if(opcao_de_alteracao == 5){
          break;
        }
      }
  
    }else{
      limpar_terminal();
      printf("Usuario nao encontrado!\n\n");
    }
  }
}

int main(){

  while(1){
    
    limpar_terminal();

    int input;

    //escolha principal
    input = menu_principal();
    limpar_terminal();
    
    //forcando o usuario a escolher uma opcao valida
    while (input <= 0 || input > 5){
      limpar_terminal();
      printf("Por favor insira uma opcao valida!\n");
      input = menu_principal();
    }

    limpar_terminal();

    while(1){

      if(input == 1){
        input = realizar_cadastro();
        if(input == 1){
          limpar_terminal();
          cadastrar_usuario();
          input = 1;
        }else if(input == 2){
          limpar_terminal();
          cadastrar_plataforma();
          input = 1;
        }

        //forcando o usuario a escolher uma opcao valida 
        while (input <= 0 || input > 4){
          limpar_terminal();
          printf("Por favor insira uma opcao valida!\n");
          input = realizar_cadastro();
        }
        if(input == 4){
          break;
        }

        }else if(input == 2){
        input = realizar_consulta();
        if(input == 1){
          limpar_terminal();
          consultar_usuario();
          getchar();
          limpar_terminal();
          input = 2;
        }

        //forcando o usuario a escolher uma opcao valida
        while (input <= 0 || input > 4){
          limpar_terminal();
          printf("Por favor insira uma opcao valida!\n");
          input = realizar_consulta(); 
        }
        
        if(input == 4){
          break;
        }

      }else if(input == 3){
        input = realizar_alteracao();
        if(input == 1){
          limpar_terminal();
          alterar_usuario();
          getchar();
          limpar_terminal();
          input = 3;
        }

        //forcando o usuario a escolher uma opcao valida
        while (input <= 0 || input > 4) {
          limpar_terminal();
          printf("Por favor insira uma opcao valida!\n");
          input = realizar_alteracao(); 

        }
        if(input == 4){
            break;
        }
      
      }else if(input == 4){
        input = realizar_exclusao();

        //forcando o usuario a escolher uma opcao valida
        while (input <= 0 || input > 4) {
          limpar_terminal();
          printf("Por favor insira uma opcao valida!\n");
          input = realizar_exclusao();
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