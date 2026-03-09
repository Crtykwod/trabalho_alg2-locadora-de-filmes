#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
#define MAX_CHAR 50

//=========================
//  PRINCIPAIS  STRUCTS
//=========================
typedef struct {
  char nome[MAX];
  char cpf[16]; //campo unico da struct
  long int id_usuario;
  char phone[15];
  char email[MAX];

}USUARIOS;

typedef struct {
  char nome_plataforma[MAX]; //campo unico da struct
  long int id_plataforma;
  char categoria[MAX];
  float preco;
  char site_url[MAX];

}PLATAFORMAS;

typedef struct {
  char cpf_usuario_assinante[16];
  char nome_plataforma_contratada[MAX_CHAR];
  int id_assinatura;
  int ativa;
  float valor_pago;

}ASSINATURAS;

//=========================
//   FUNCOES AUXILIARES
//=========================
void LimparTerminal(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void LimparBuffer(){
    int c;

    while((c = getchar()) != '\n' && c != EOF);
}

//============================
//   FUNCOES DE VALIDACAO
//============================
//essa funcao de validar cpf ta dando problema quando eu digito mais que 16 digitos, mas ela funciona no codeblocks
void ValidarCpf(char *cpf){
    //000.000.000-00
    //usuario vai ficar aqui ate digitar nesse formato
    while(1){
        cpf[strcspn(cpf, "\n")] = '\0';

        if(strlen(cpf) == 14 && cpf[3] == '.' && cpf[7] == '.' && cpf[11] == '-'){
            break;
        }

        LimparTerminal();
        printf("CPF invalido.\n");
        printf("Digite novamente (000.000.000-00): ");
        fgets(cpf, 16, stdin);
    }
    LimparTerminal();
}

void ValidarTelefone(char *telefone){
    //(00)0000-0000
    while(1){
        telefone[strcspn(telefone, "\n")] = '\0';

        if(strlen(telefone) == 13 && telefone[0] == '(' && telefone[3] == ')' && telefone[8] == '-'){
            break;
        }

        LimparTerminal();
        printf("Telefone invalido.\n");
        printf("Digite novamente (00)0000-0000: ");
        fgets(telefone, 15, stdin);
    }
    LimparTerminal();

}

void ValidarEmail(char *email){
    //precisa ter um @
    int arroba = 0;

    while(1){
        email[strcspn(email, "\n")] = '\0';
        for(int i = 0 ; i < strlen(email); i++){
            if(email[i] == '@'){
                arroba = 1;
                return;
            }
        }


        LimparTerminal();
        printf("Por favor, insira um Email valido!\n");
        fgets(email, MAX_CHAR, stdin);

    }

    LimparTerminal();

}

void ValidarURL(char *URL){

    int tem_ponto = 0;
    for(int i = 0; URL[i] != '\n'; i++){
        if(URL[i] == '.'){
            tem_ponto = 1;
            break;
        }
    }

    while(tem_ponto == 0){
        LimparTerminal();
        printf("Digite um site valido:\n");
        fgets(URL, MAX_CHAR, stdin);
        for(int i = 0; URL[i] != '\n'; i++){
            if(URL[i] == '.'){
                tem_ponto = 1;
                break;
            }
        }
    }

    URL[strcspn(URL,"\n")] = '\0';

    LimparTerminal();
}

//===================================
//    GERENCIAMENTO DE CLIENTES
//===================================
void CadastrarNovoCliente(USUARIOS *BancoUsuarios, int *total_clientes){

    //cadastro do nome
    printf("-- Cadastro de clientes --\n\n");
    printf("Digite o nome do cliente: ");
    fgets(BancoUsuarios[*total_clientes].nome, MAX_CHAR, stdin);
    BancoUsuarios[*total_clientes].nome[strcspn(BancoUsuarios[*total_clientes].nome, "\n")] = '\0';
    LimparTerminal();

    //cadastro do cpfcpf
    printf("-- Cadastro de clientes --\n\n");
    printf("Digite o CPF do cliente (000.000.000-00): ");
    fgets(BancoUsuarios[*total_clientes].cpf, 16, stdin);
    ValidarCpf(BancoUsuarios[*total_clientes].cpf);

    //cadastro do telefone
    printf("-- Cadastro de clientes --\n\n");
    printf("Digite o telefone do usuario (00)0000-0000: ");
    fgets(BancoUsuarios[*total_clientes].phone, 15, stdin);
    ValidarTelefone(BancoUsuarios[*total_clientes].phone);

    //cadastro email
    printf("-- Cadastro de clientes --\n\n");
    printf("Digite o Email do usuario: ");
    fgets(BancoUsuarios[*total_clientes].email, MAX_CHAR, stdin);
    ValidarEmail(BancoUsuarios[*total_clientes].email);

    //cadastrando o id do usuario
    BancoUsuarios[*total_clientes].id_usuario = 1000 + *total_clientes;

    //mensagem de cadastro concluido
    LimparTerminal();
    printf("-- Cadastro de clientes --\n\n");
    printf("Usuario cadastrado com sucesso!\n");
    printf("Id do usuario: %ld\n\n", BancoUsuarios[*total_clientes].id_usuario);
    printf("Pressione ENTER para continuar.\n\n");
    getchar();
    LimparTerminal();
}

void BuscarCliente(USUARIOS *BancoUsuarios, int *total_clientes){
    LimparTerminal();

    printf("-- Buscar clientes --\n\n");
    printf("Digite o CPF do cliente que deseja buscar: ");
    char CPF[16];
    fgets(CPF, 16, stdin);
    ValidarCpf(CPF);

    int encontrado = 0;

    for(int i = 0; i < *total_clientes; i++){
        if(strcasecmp(CPF, BancoUsuarios[i].cpf) == 0){
            LimparTerminal();
            encontrado = 1;
            printf("-- Buscar clientes --\n\n");
            printf("Usuario encontrado!\n\n");
            printf("Nome: %s\n", BancoUsuarios[i].nome);
            printf("CPF: %s\n", BancoUsuarios[i].cpf);
            printf("Id do usuario: %ld\n", BancoUsuarios[i].id_usuario);
            printf("Telefone: %s\n", BancoUsuarios[i].phone);
            printf("Email: %s\n\n", BancoUsuarios[i].email);
            printf("Pressione ENTER para retornar.\n\n");
            getchar();
            LimparTerminal();

        }
    }

    if(encontrado == 0){
        LimparTerminal();
        printf("-- Buscar clientes --\n\n");
        printf("Cliente nao encontrado!\n");
        printf("Pressione ENTER para retornar.\n\n");
        getchar();
        LimparTerminal();
    }

}

void AlterarDadosClientes(USUARIOS *BancoUsuarios, int *total_clientes){
    printf("-- Alterar dados de clientes --\n\n");
    printf("Digite o CPF do cliente o qual os dados serao alterados: ");
    char CPF[16];
    fgets(CPF, 16, stdin);
    ValidarCpf(CPF);

    int encontrado = 0;
    int opcao_alteracao = 0;
    int localizador;

    for(localizador = 0; localizador < *total_clientes; localizador++){
        if(strcasecmp(CPF, BancoUsuarios[localizador].cpf) == 0){
            LimparTerminal();
            encontrado = 1;
            printf("-- Alterar dados de clientes --\n\n");
            printf("Usuario encontrado!\n");

            do{
                printf("Qual dado do usuario sera alterado?\n\n");
                printf("1 - Nome: %s\n", BancoUsuarios[localizador].nome);
                printf("2 - CPF: %s\n", BancoUsuarios[localizador].cpf);
                printf("3 - Telefone: %s\n", BancoUsuarios[localizador].phone);
                printf("4 - Email: %s\n", BancoUsuarios[localizador].email);
                printf("5 - Retornar.\n\n");
                printf("Escolha uma opcao: ");

                scanf("%d", &opcao_alteracao);
                getchar();

                LimparTerminal();
            }while(opcao_alteracao < 1 || opcao_alteracao > 5);

            if(opcao_alteracao == 1){
                LimparTerminal();
                char novo_nome[MAX_CHAR];

                printf("-- Alterar dados de clientes --\n\n");
                printf("Digite o novo nome do usuario:\n");
                fgets(novo_nome, MAX_CHAR, stdin);
                novo_nome[strcspn(novo_nome, "\n")] = '\0';
                LimparTerminal();

                printf("-- Alterar dados de clientes --\n\n");
                printf("Nome do usuario alterado com sucesso!\n\n");
                printf("Nome anterior: %s\n", BancoUsuarios[localizador].nome);
                printf("Novo nome: %s\n\n", novo_nome);
                printf("Pressione ENTER para continuar.\n\n");
                getchar();
                LimparTerminal();

                strcpy(BancoUsuarios[localizador].nome, novo_nome);

            }else if(opcao_alteracao == 2){
                LimparTerminal();
                char novo_cpf[MAX_CHAR];

                printf("-- Alterar dados de clientes --\n\n");
                printf("Digite o novo CPF do usuario (000.000.000-00): ");
                fgets(novo_cpf, 16, stdin);
                ValidarCpf(novo_cpf);
                LimparTerminal();

                printf("-- Alterar dados de clientes --\n\n");
                printf("CPF do usuario alterado com sucesso!\n\n");
                printf("CPF anterior: %s\n", BancoUsuarios[localizador].cpf);
                printf("Novo CPF: %s\n\n", novo_cpf);
                printf("Pressione ENTER para continuar.\n\n");
                getchar();
                LimparTerminal();

                strcpy(BancoUsuarios[localizador].cpf, novo_cpf);

            }else if(opcao_alteracao == 3){
                LimparTerminal();
                char novo_telefone[MAX_CHAR];

                printf("-- Alterar dados de clientes --\n\n");
                printf("Digite o novo telefone do usuario (00)0000-0000: ");
                fgets(novo_telefone, 15, stdin);
                ValidarTelefone(novo_telefone);
                LimparTerminal();

                printf("-- Alterar dados de clientes --\n\n");
                printf("Telefone do usuario alterado com sucesso!\n\n");
                printf("Telefone anterior: %s\n", BancoUsuarios[localizador].phone);
                printf("Novo telefone: %s\n\n", novo_telefone);
                printf("Pressione ENTER para continuar.\n\n");
                getchar();
                LimparTerminal();

                strcpy(BancoUsuarios[localizador].phone, novo_telefone);

            }else if(opcao_alteracao == 4){
                LimparTerminal();
                char novo_email[MAX_CHAR];

                printf("-- Alterar dados de clientes --\n\n");
                printf("Digite o novo email do usuario: ");
                fgets(novo_email, MAX_CHAR, stdin);
                ValidarEmail(novo_email);
                LimparTerminal();

                printf("-- Alterar dados de clientes --\n\n");
                printf("Email do usuario alterado com sucesso!\n\n");
                printf("Email anterior: %s\n", BancoUsuarios[localizador].email);
                printf("Novo email: %s\n\n", novo_email);
                printf("Pressione ENTER para continuar.\n\n");
                getchar();
                LimparTerminal();

                strcpy(BancoUsuarios[localizador].email, novo_email);

            }else{
                LimparTerminal();
                return;
            }

        }
    }

    if(encontrado == 0){
        LimparTerminal();
        printf("-- Alterar dados de clientes --\n\n");
        printf("Usuario nao encontrado!\n");
        printf("Pressione ENTER para retornar.\n\n");

        getchar();
        LimparTerminal();

    }
}

void ExcluirCliente(USUARIOS *BancoUsuarios, int *total_clientes){
    char CPF[16];
    int localizador;
    int encontrado = 0;
    int confirmacao;

    printf("-- Excluir clientes --\n\n");
    printf("Digite o CPF do cliente que sera excluido: ");
    fgets(CPF, 16, stdin);
    ValidarCpf(CPF);

    for(localizador = 0; localizador < *total_clientes; localizador++){
        if(strcasecmp(CPF, BancoUsuarios[localizador].cpf) == 0){
            LimparTerminal();
            encontrado = 1;
            printf("-- Excluir clientes --\n\n");
            printf("Usuario encontrado!\n\n");

            do{
                printf("Nome: %s\n", BancoUsuarios[localizador].nome);
                printf("CPF: %s\n", BancoUsuarios[localizador].cpf);
                printf("Id do usuario: %ld\n", BancoUsuarios[localizador].id_usuario);
                printf("Telefone: %s\n", BancoUsuarios[localizador].phone);
                printf("Email: %s\n\n", BancoUsuarios[localizador].email);
                printf("Confirma a exclusao?\n");
                printf("1 - Sim\n");
                printf("2 - Nao\n\n");

                scanf("%d", &confirmacao);
                getchar();

                LimparTerminal();
            }while(confirmacao < 1 || confirmacao > 2);

            if(confirmacao == 2){
            LimparTerminal();
            printf("-- Excluir clientes --\n\n");
            printf("Operacao cancelada!\n");
            printf("Pressione ENTER para continuar.\n\n");

            getchar();

            LimparTerminal();
            return;

            }else{
                for(int i=localizador; i < *total_clientes - 1; i++){
                    BancoUsuarios[i] = BancoUsuarios[i + 1];
                }

                (*total_clientes)--;

                LimparTerminal();
                printf("-- Excluir clientes --\n\n");
                printf("Cliente excluido com sucesso!\n");
                printf("Pressione ENTER para retornar.\n\n");
                getchar();
                LimparTerminal();
                return;
            }
        }
    }

    if(encontrado == 0){
        LimparTerminal();
        printf("-- Excluir clientes --\n\n");
        printf("Usuario nao encontrado!\n");
        printf("Pressione ENTER para retornar.\n\n");

        getchar();
        LimparTerminal();

    }

}

//===================================
//    GERENCIAMENTO DE PLATAFORMAS
//===================================
void CadastrarNovaPlataforma(PLATAFORMAS *BancoPlataformas, int *total_plataformas){

    printf("-- Cadastro de plataformas --\n\n");
    printf("Digite o nome da plataforma: ");
    fgets(BancoPlataformas[*total_plataformas].nome_plataforma, MAX_CHAR, stdin);
    BancoPlataformas[*total_plataformas].nome_plataforma[strcspn(BancoPlataformas[*total_plataformas].nome_plataforma, "\n")] = '\0';
    LimparTerminal();

    printf("-- Cadastro de plataformas --\n\n");
    printf("Digite a categoria da plataforma(filmes, musica, etc): ");
    fgets(BancoPlataformas[*total_plataformas].categoria, MAX_CHAR, stdin);
    BancoPlataformas[*total_plataformas].categoria[strcspn(BancoPlataformas[*total_plataformas].categoria, "\n")] = '\0';
    LimparTerminal();

    printf("-- Cadastro de plataformas --\n\n");
    printf("Digite o valor do servico: R$");
    scanf("%f", &BancoPlataformas[*total_plataformas].preco);
    getchar();
    LimparTerminal();

    printf("-- Cadastro de plataformas --\n\n");
    printf("Digite o site da plataforma: ");
    fgets(BancoPlataformas[*total_plataformas].site_url, MAX_CHAR, stdin);
    ValidarURL(BancoPlataformas[*total_plataformas].site_url);

    BancoPlataformas[*total_plataformas].id_plataforma = 5000 + *total_plataformas;

    LimparTerminal();
    printf("-- Cadastro de plataformas --\n\n");
    printf("Plataforma cadastrada com sucesso!\n");
    printf("Id da plataforma: %ld\n\n", BancoPlataformas[*total_plataformas].id_plataforma);
    printf("Pressione ENTER para continuar.\n\n");
    getchar();
    LimparTerminal();
}

void BuscarPlataforma(PLATAFORMAS *BancoPlataformas, int *total_plataformas){
    LimparTerminal();

    printf("-- Buscar plataformas --\n\n");
    printf("Digite o nome da plataforma que deseja buscar: ");
    char nome_busca[MAX_CHAR];
    fgets(nome_busca, MAX_CHAR, stdin);

    nome_busca[strcspn(nome_busca, "\n")] = '\0';

    int encontrado = 0;

    for(int localizador=0; localizador < *total_plataformas; localizador++){

        if(strcasecmp(nome_busca, BancoPlataformas[localizador].nome_plataforma) == 0){
            LimparTerminal();
            encontrado = 1;

            printf("-- Buscar plataformas --\n\n");
            printf("Plataforma encontrada!\n\n");

            printf("Nome: %s\n", BancoPlataformas[localizador].nome_plataforma);
            printf("ID da plataforma: %ld\n", BancoPlataformas[localizador].id_plataforma);
            printf("Categoria: %s\n", BancoPlataformas[localizador].categoria);
            printf("Preco: R$%.2f\n", BancoPlataformas[localizador].preco);
            printf("Site URL: %s\n\n", BancoPlataformas[localizador].site_url);

            printf("Pressione ENTER para retornar.\n\n");
            getchar();
            LimparTerminal();
        }
    }
    if(encontrado == 0){
        LimparTerminal();
        printf("-- Buscar plataformas --\n\n");
        printf("Plataforma nao encontrada!\n");
        printf("Pressione ENTER para retornar.\n\n");
        getchar();
        LimparTerminal();
    }

}

void AlterarDadosPlataformas(PLATAFORMAS *BancoPlataformas, int *total_plataformas){
    LimparTerminal();
    printf("-- Alterar dados de plataformas --\n\n");
    printf("Digite o nome da plataforma que deseja alterar os dados: ");
    char nome_busca[MAX_CHAR];
    fgets(nome_busca, MAX_CHAR, stdin);

    nome_busca[strcspn(nome_busca, "\n")] = '\0';

    int encontrado=0;
    int opcao_alteracao=0;
    int localizador;

    for(localizador=0; localizador < *total_plataformas; localizador++){
        if(strcasecmp(nome_busca, BancoPlataformas[localizador].nome_plataforma) == 0){
            LimparTerminal();
            encontrado = 1;
            printf("-- Alterar dados de plataformas --\n\n");
            printf("Plataforma encontrada!\n");

            do{
                printf("Qual dado do usuario sera alterado?\n\n");
                printf("1 - Nome: %s\n", BancoPlataformas[localizador].nome_plataforma);
                printf("2 - Categoria: %s\n", BancoPlataformas[localizador].categoria);
                printf("3 - Preco: R$%.2f\n", BancoPlataformas[localizador].preco);
                printf("4 - Site URL: %s\n", BancoPlataformas[localizador].site_url);
                printf("5 - Retornar.\n\n");
                printf("Escolha uma opcao: ");

                scanf("%d", &opcao_alteracao);
                getchar();

                LimparTerminal();
            }while(opcao_alteracao < 1 || opcao_alteracao > 5);

            if(opcao_alteracao == 1){
                LimparTerminal();
                char novo_nome[MAX_CHAR];
                printf("-- Alterar dados de plataformas --\n\n");
                printf("Digite o novo nome da Plataforma: ");
                fgets(novo_nome, MAX_CHAR, stdin);
                novo_nome[strcspn(novo_nome, "\n")] = '\0';
                LimparTerminal();
                
                printf("-- Alterar dados de plataformas --\n\n");
                printf("Nome da plataforma alterada com sucesso!\n\n");
                printf("Nome anterior: %s\n", BancoPlataformas[localizador].nome_plataforma);
                printf("Novo nome: %s\n\n", novo_nome);
                printf("Pressione ENTER para continuar.\n\n");
                getchar();
                LimparTerminal();

                strcpy(BancoPlataformas[localizador].nome_plataforma, novo_nome);

            }else if(opcao_alteracao == 2){
                LimparTerminal();
                char nova_categoria[MAX_CHAR];

                printf("-- Alterar dados de plataformas --\n\n");
                printf("Digite a nova categoria: ");
                fgets(nova_categoria, MAX_CHAR, stdin);
                nova_categoria[strcspn(nova_categoria, "\n")] = '\0';
                LimparTerminal();

                printf("-- Alterar dados de plataformas --\n\n");
                printf("Categoria alterada com sucesso!\n\n");
                printf("Categoria anterior: %s\n", BancoPlataformas[localizador].categoria);
                printf("Nova categoria: %s\n\n", nova_categoria);
                printf("Pressione ENTER para continuar.\n\n");
                getchar();
                LimparTerminal();

                strcpy(BancoPlataformas[localizador].categoria, nova_categoria);

            }else if(opcao_alteracao == 3){
                LimparTerminal();
                float novo_valor;

                printf("-- Alterar dados de plataformas --\n\n");
                printf("Digite o novo valor: ");
                scanf("%f", novo_valor);
                getchar();
                LimparTerminal();

                printf("-- Alterar dados de plataformas --\n\n");
                printf("Valor alterado com sucesso!\n\n");
                printf("Valor anterior: %.2f\n", BancoPlataformas[localizador].preco);
                printf("Novo valor: %.2f\n\n", novo_valor);
                printf("Pressione ENTER para continuar.\n\n");
                getchar();
                LimparTerminal();

                BancoPlataformas[localizador].preco = novo_valor;

            }else if(opcao_alteracao == 4){
                LimparTerminal();
                char nova_url[MAX_CHAR];

                printf("-- Alterar dados de plataformas --\n\n");
                printf("Digite a nova URL: ");
                fgets(nova_url, MAX_CHAR, stdin);
                LimparTerminal();

                printf("-- Alterar dados de plataformas --\n\n");
                printf("URL alterada com sucesso!\n\n");
                printf("URL anterior: %s\n", BancoPlataformas[localizador].site_url);
                printf("Nova URL: %s\n\n", nova_url);
                printf("Pressione ENTER para continuar.\n\n");
                getchar();
                LimparTerminal();

                strcpy(BancoPlataformas[localizador].site_url, nova_url);

            }else{
                LimparTerminal();
                return;
            }
        }
    }
    if(encontrado == 0){
        LimparTerminal();
        printf("-- Alterar dados de plataformas --\n\n");
        printf("Plataforma nao encontrada!\n");
        printf("Pressione ENTER para retornar.\n\n");

        getchar();
        LimparTerminal();
    }
}

void ExcluirPlataforma(PLATAFORMAS *BancoPlataformas, int *total_plataformas){
    char nome_busca[MAX_CHAR];
    int localizador;
    int encontrado = 0;
    int confirmacao = 0;

    printf("-- Excluir plataformas --\n\n");
    printf("Digite a plataforma que deseja excluir: ");
    fgets(nome_busca, MAX_CHAR, stdin);
    nome_busca[strcspn(nome_busca, "\n")] = '\0';

    for(localizador = 0; localizador < *total_plataformas; localizador++){
        if(strcasecmp(nome_busca, BancoPlataformas[localizador].nome_plataforma) == 0){
            LimparTerminal();
            encontrado = 1;
            printf("-- Excluir plataformas --\n\n");
            printf("Plataforma encontrada!\n\n");

            do{
                printf("Plataforma: %s\n", BancoPlataformas[localizador].nome_plataforma);
                printf("Categoria: %s\n", BancoPlataformas[localizador].categoria);
                printf("Valor: R$%.2f\n", BancoPlataformas[localizador].preco);
                printf("URL da plataforma: %s\n", BancoPlataformas[localizador].site_url);
                printf("ID da plataforma: %ld\n\n", BancoPlataformas[localizador].id_plataforma);

                printf("Confirmar exclusao?\n");
                printf("1 - Sim\n");
                printf("2 - Nao\n\n");

                scanf("%d", &confirmacao);
                getchar();
                LimparTerminal();
            }while(confirmacao < 1 || confirmacao > 2);

            if(confirmacao == 2){
                LimparTerminal();
                printf("-- Excluir plataformas --\n\n");
                printf("Operacao cancelada!\n");
                printf("Pressione ENTER para retornar.\n\n");
                getchar();

                LimparTerminal();
                return;

            }else{
                for(int i=localizador; i < *total_plataformas - 1; i++){
                    BancoPlataformas[i] = BancoPlataformas[i + 1];
                }

                (*total_plataformas)--;

                LimparTerminal();
                printf("-- Excluir plataformas --\n\n");
                printf("Plataforma excluida com sucesso!\n");
                printf("Pressione ENTER para retornar\n\n");
                getchar();
                LimparTerminal();
                return;
            }
        }
    }
    if(encontrado == 0){
        LimparTerminal();
        printf("-- Excluir plataformas --\n\n");
        printf("Plataforma nao encontrada!\n");
        printf("Pressione ENTER para retornar.\n\n");

        getchar();
        LimparTerminal();
    }

}

//===================================
//    GERENCIAMENTO DE ASSINATURAS
//===================================
void CadastrarNovaAssinatura(USUARIOS *BancoUsuarios, PLATAFORMAS *BancoPlataformas, ASSINATURAS *BancoAssinaturas, int *total_usuarios, int *total_plataformas, int *total_assinaturas){

    printf("-- Cadastro de assinaturas --\n\n");
    printf("Digite o cpf do cliente que sera vinculado a assinatura (000.000.000-00): ");
    fgets(BancoAssinaturas[*total_assinaturas].cpf_usuario_assinante, 16, stdin);
    ValidarCpf(BancoAssinaturas[*total_assinaturas].cpf_usuario_assinante);

    LimparTerminal();

    int localizadorc;
    int localizadorp;
    int confirmacao = 1;

    int encontrado_usuario = 0;

    for(localizadorc = 0; localizadorc < *total_usuarios; localizadorc++){
        if(strcasecmp(BancoAssinaturas[*total_assinaturas].cpf_usuario_assinante, BancoUsuarios[localizadorc].cpf) == 0){

            encontrado_usuario = 1;

            printf("-- Cadastro de assinaturas --\n\n");
            printf("Usuario encontrado!\n\n");
            printf("Nome: %s\n", BancoUsuarios[localizadorc].nome);
            printf("CPF: %s\n", BancoUsuarios[localizadorc].cpf);
            printf("Id do usuario: %ld\n", BancoUsuarios[localizadorc].id_usuario);
            printf("Telefone: %s\n", BancoUsuarios[localizadorc].phone);
            printf("Email: %s\n\n", BancoUsuarios[localizadorc].email);

            printf("Deseja vincula-lo a uma plataforma?\n");
            printf("1 - Sim.\n");
            printf("2 - Nao.\n\n");

            scanf("%d", &confirmacao);
            getchar();
            LimparTerminal();

            break;
        }
    }

    if(!encontrado_usuario){
        printf("-- Cadastro de assinaturas --\n\n");
        printf("Usuario nao encontrado!\n");
        printf("Cadastre o cliente antes de vincula-lo a uma plataforma!\n\n");
        printf("Pressione ENTER para retornar.\n\n");
        getchar();
        LimparTerminal();
        return;
    }

    if(confirmacao == 2){
        printf("-- Cadastro de assinaturas --\n\n");
        printf("Operacao cancelada!\n\n");
        printf("Pressione ENTER para continuar.\n\n");
        getchar();
        LimparTerminal();
        return;
    }

    printf("-- Cadastro de assinaturas --\n\n");
    printf("Digite o nome da plataforma que sera vinculada a assinatura: ");
    fgets(BancoAssinaturas[*total_assinaturas].nome_plataforma_contratada, MAX_CHAR, stdin);
    BancoAssinaturas[*total_assinaturas].nome_plataforma_contratada[strcspn(BancoAssinaturas[*total_assinaturas].nome_plataforma_contratada, "\n")] = '\0';
    LimparTerminal();

    int encontrado_plataforma = 0;

    for(localizadorp = 0; localizadorp < *total_plataformas; localizadorp++){
        if(strcasecmp(BancoAssinaturas[*total_assinaturas].nome_plataforma_contratada, BancoPlataformas[localizadorp].nome_plataforma) == 0){

            encontrado_plataforma = 1;

            printf("-- Cadastro de assinaturas --\n\n");
            printf("Plataforma encontrada!\n\n");
            printf("Nome: %s\n", BancoPlataformas[localizadorp].nome_plataforma);
            printf("Id da plataforma: %ld\n", BancoPlataformas[localizadorp].id_plataforma);
            printf("Categoria: %s\n", BancoPlataformas[localizadorp].categoria);
            printf("Preco: R$%.2f\n", BancoPlataformas[localizadorp].preco);
            printf("URL: %s\n\n", BancoPlataformas[localizadorp].site_url);

            printf("Deseja vincula-la a um cliente?\n");
            printf("1 - Sim.\n");
            printf("2 - Nao\n\n");

            scanf("%d", &confirmacao);
            getchar();
            LimparTerminal();

            break;
        }
    }

    if(!encontrado_plataforma){
        printf("-- Cadastro de assinaturas --\n\n");
        printf("Plataforma nao encontrada!\n");
        printf("Cadastre a plataforma antes de vincula-la a um cliente!\n\n");
        printf("Pressione ENTER para retornar.\n\n");
        getchar();
        LimparTerminal();
        return;
    }

    if(confirmacao == 2){
        printf("-- Cadastro de assinaturas --\n\n");
        printf("Operacao cancelada!\n\n");
        printf("Pressione ENTER para continuar.\n\n");
        getchar();
        LimparTerminal();
        return;
    }

    strcpy(BancoAssinaturas[*total_assinaturas].cpf_usuario_assinante, BancoUsuarios[localizadorc].cpf);
    strcpy(BancoAssinaturas[*total_assinaturas].nome_plataforma_contratada, BancoPlataformas[localizadorp].nome_plataforma);
    BancoAssinaturas[*total_assinaturas].ativa = 1;
    BancoAssinaturas[*total_assinaturas].valor_pago = BancoPlataformas[localizadorp].preco;
    BancoAssinaturas[*total_assinaturas].id_assinatura = 20000 + *total_assinaturas;

    printf("Assinatura criada com sucesso!\n\n");
    printf("Nome do usuario: %s\n", BancoUsuarios[localizadorc].nome);
    printf("CPF: %s\n", BancoAssinaturas[*total_assinaturas].cpf_usuario_assinante);
    printf("Plataforma Contratada: %s\n", BancoAssinaturas[*total_assinaturas].nome_plataforma_contratada);
    printf("Categoria do servico: %s\n\n", BancoPlataformas[localizadorp].categoria);
    printf("Pressione ENTER para continuar.\n\n");
    getchar();
    LimparTerminal();

    (*total_assinaturas)++;
}

void BuscarAssinatura(ASSINATURAS *BancoAssinaturas, int *total_assinaturas){
    LimparTerminal();

    char cpf[16];
    char plataforma[MAX_CHAR];
    int encontrado = 0;

    printf("-- Buscar assinatura --\n\n");
    printf("Digite o CPF do usuario assinante (000.000.000-00): ");
    fgets(cpf, 16, stdin);
    ValidarCpf(cpf);
    LimparTerminal();

    printf("-- Buscar assinatura --\n\n");
    printf("Digite o nome da plataforma: ");
    fgets(plataforma, MAX_CHAR, stdin);
    plataforma[strcspn(plataforma, "\n")] = '\0';

    for(int i = 0; i < *total_assinaturas; i++){
        if(strcasecmp(cpf, BancoAssinaturas[i].cpf_usuario_assinante) == 0 &&
           strcasecmp(plataforma, BancoAssinaturas[i].nome_plataforma_contratada) == 0){

            LimparTerminal();
            encontrado = 1;

            printf("-- Buscar assinatura --\n\n");
            printf("Assinatura encontrada!\n\n");

            printf("CPF do usuario: %s\n", BancoAssinaturas[i].cpf_usuario_assinante);
            printf("Plataforma: %s\n", BancoAssinaturas[i].nome_plataforma_contratada);
            printf("ID da assinatura: %d\n", BancoAssinaturas[i].id_assinatura);
            printf("Valor pago: R$%.2f\n", BancoAssinaturas[i].valor_pago);
            if(BancoAssinaturas[i].ativa){
                printf("Status: Ativa.\n");
            }else{
                printf("Status: Cancelada.\n\n");
            }
            

            printf("Pressione ENTER para retornar.\n\n");
            getchar();
            LimparTerminal();
        }
    }

    if(encontrado == 0){
        LimparTerminal();
        printf("-- Buscar assinatura --\n\n");
        printf("Assinatura nao encontrada!\n");
        printf("Pressione ENTER para retornar.\n\n");
        getchar();
        LimparTerminal();
    }
}

void AlterarDadosAssinatura(ASSINATURAS *BancoAssinaturas, int *total_assinaturas, PLATAFORMAS *BancoPlataformas, int *total_plataformas){
    LimparTerminal();

    char cpf[16];
    char plataforma[MAX_CHAR];

    printf("-- Alterar dados da assinatura --\n\n");
    printf("Digite o CPF do assinante: ");
    fgets(cpf, 16, stdin);
    ValidarCpf(cpf);
    LimparTerminal();

    printf("-- Alterar dados da assinatura --\n\n");
    printf("Digite o nome da plataforma: ");
    fgets(plataforma, MAX_CHAR, stdin);
    plataforma[strcspn(plataforma, "\n")] = '\0';

    int encontrado = 0;
    int opcao;
    int localizador;

    for(localizador = 0; localizador < *total_assinaturas; localizador++){
        if(strcasecmp(cpf, BancoAssinaturas[localizador].cpf_usuario_assinante) == 0 &&
           strcasecmp(plataforma, BancoAssinaturas[localizador].nome_plataforma_contratada) == 0){

            encontrado = 1;

            do{
                LimparTerminal();
                printf("-- Alterar dados da assinatura --\n\n");
                printf("Assinatura encontrada!\n");
                printf("Qual dado sera alterado?\n\n");
                printf("1 - Plataforma: %s\n", BancoAssinaturas[localizador].nome_plataforma_contratada);
                printf("2 - Valor pago: R$%.2f\n", BancoAssinaturas[localizador].valor_pago);
                printf("3 - Retornar\n\n");
                printf("Escolha uma opcao: ");
                scanf("%d", &opcao);
                getchar();

            }while(opcao < 1 || opcao > 3);

            if(opcao == 1){
                char nova_plataforma[MAX_CHAR];

                LimparTerminal();
                printf("-- Alterar dados da assinatura --\n\n");
                printf("Digite a nova plataforma: ");

                fgets(nova_plataforma, MAX_CHAR, stdin);
                nova_plataforma[strcspn(nova_plataforma, "\n")] = '\0';

                for(int i = 0; i < *total_plataformas; i++){
                    if(strcasecmp(nova_plataforma, BancoPlataformas[i].nome_plataforma) == 0){
                        strcpy(BancoAssinaturas[localizador].nome_plataforma_contratada, nova_plataforma);
                        BancoAssinaturas[localizador].valor_pago = BancoPlataformas[i].preco;

                        LimparTerminal();
                        printf("-- Alterar dados da assinatura --\n\n");
                        printf("Plataforma alterada com sucesso!\n");
                        printf("Pressione ENTER para continuar.\n\n");
                        getchar();
                        LimparTerminal();

                    }else{
                        LimparTerminal();
                        printf("-- Alterar dados da assinatura --\n\n");
                        printf("Plataforma nao encontrada!\n");
                        printf("Cadastre a plataforma antes de vincula-la a um cliente!\n\n");
                        printf("Pressione ENTER para retornar.\n\n");
                        getchar();
                        LimparTerminal();
                    }
                }


            }else if(opcao == 2){
                float novo_valor;

                LimparTerminal();
                printf("-- Alterar dados da assinatura --\n\n");
                printf("Digite o novo valor pago: ");
                scanf("%f", &novo_valor);
                getchar();

                BancoAssinaturas[localizador].valor_pago = novo_valor;

                LimparTerminal();
                printf("-- Alterar dados da assinatura --\n\n");
                printf("Valor individual da assinatura alterado com sucesso!");
                printf("Pressione ENTER para continuar.\n\n");
                getchar();
                LimparTerminal();

            }else{
                return;
            }
        }
    }

    if(encontrado == 0){
        LimparTerminal();
        printf("Assinatura nao encontrada!\n");
        printf("Pressione ENTER para retornar.\n\n");
        getchar();
        LimparTerminal();
    }
}
//--- MENUS ---
int MenuPrincipal(int opcao){
    printf("== Plataforma de Gerenciamento de Assinaturas ==\n\n");
    printf("1 - Gerenciamento de clientes.\n");
    printf("2 - Gerenciamento de plataformas.\n");
    printf("3 - Gerenciamento de assinaturas.\n");
    printf("4 - Sair.\n\n");
    printf("Escolha uma opcao: ");

    scanf("%d", &opcao);
    getchar();//consumindo a quebra de linha

    while(opcao < 1 || opcao > 4){
        LimparTerminal();
        printf("Digite uma opcao valida!\n");
        return MenuPrincipal(opcao);
    }

    LimparTerminal();
    return opcao;
}

int GerenciamentoDeClientes(){
    printf("-- Gerenciamento de clientes --\n\n");
    printf("1 - Cadastrar um novo cliente.\n");
    printf("2 - Buscar um cliente.\n");
    printf("3 - Alterar dados de um cliente.\n");
    printf("4 - Excluir um cliente.\n");
    printf("5 - Voltar.\n\n");
    printf("Escolha uma opcao: ");

    int opcao;
    scanf("%d", &opcao);
    getchar();//consumindo a quebra de linha

    while(opcao < 1 || opcao > 5){
        LimparTerminal();
        printf("Escolha uma opcao valida!\n");
        return GerenciamentoDeClientes();
    }

    LimparTerminal();

    return opcao;

}

int GerenciamentoDePlataformas(){
    printf("-- Gerenciamento de plataformas --\n\n");
    printf("1 - Cadastrar uma nova plataforma.\n");
    printf("2 - Buscar uma plataforma.\n");
    printf("3 - Alterar dados de uma plataforma.\n");
    printf("4 - Excluir uma plataforma.\n");
    printf("5 - Voltar.\n\n");
    printf("Escolha uma opcao: ");

    int opcao;
    scanf("%d", &opcao);
    getchar();//consumindo a quebra de linha

    while(opcao < 1 || opcao > 5){
        LimparTerminal();
        printf("Escolha uma opcao valida!\n");
        return GerenciamentoDePlataformas();
    }

    LimparTerminal();

    return opcao;

}

int GerenciamentoDeAssinaturas(){
    printf("-- Gerenciamento de assinaturas --\n\n");
    printf("1 - Cadastrar uma nova assinatura.\n");
    printf("2 - Buscar uma assinatura.\n");
    printf("3 - Alterar dados de uma assinatura.\n");
    printf("4 - Excluir uma assinatura.\n");
    printf("5 - Voltar.\n\n");
    printf("Escolha uma opcao: ");

    int opcao;
    scanf("%d", &opcao);
    getchar();//consumindo a quebra de linha

    while(opcao < 1 || opcao > 5){
        LimparTerminal();
        printf("Escolha uma opcao valida!\n");
        return GerenciamentoDeAssinaturas();
    }

    LimparTerminal();

    return opcao;

}

//===========================================
//    FUNCOES DE GERENCIAMENTO DE ARQUIVOS
//===========================================
int procurar_arquivo(USUARIOS **BancoUsuarios, int *total_clientes, PLATAFORMAS **BancoPlataformas, int *total_plataformas, ASSINATURAS **BancoAssinaturas, int *total_assinaturas){

    FILE *fArquivoBin = fopen("BancoDeDados.bin", "rb");
    int opcao_arquivo = 1;

    if(fArquivoBin == NULL){
        printf("Nao foi possivel localizar/abrir um arquivo existente nesse computador.\n");
        printf("Um novo sera criado.\n");
        printf("Pressione ENTER para continuar.\n\n");
        getchar();
        LimparTerminal();

        return 0;// retornando 0 pq deu errado
    }else{

        while(opcao_arquivo < 1 || opcao_arquivo > 2){
            printf("Foi localizado um arquivo existente nesse computador, deseja utiliza-lo?\n\n");
            printf("1 - Sim, irei utilizar o arquivo.\n");
            printf("2 - Nao, irei sobrescrever o arquivo.\n\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao_arquivo);
            getchar();
            LimparTerminal();
        }
    }

    if(opcao_arquivo == 2){
        fclose(fArquivoBin);
        return 0; //return 0 se nao abriu o arquivo
    }

    //lendo os clientes que estao no arquivo
    fread(total_clientes, sizeof(int), 1, fArquivoBin);

    if(*total_clientes > 0){
        *BancoUsuarios = (USUARIOS*) malloc(*total_clientes * sizeof(USUARIOS));
        fread(*BancoUsuarios, sizeof(USUARIOS), *total_clientes, fArquivoBin);
    }

    //lendo as plataformas que estao no arquivo
    fread(total_plataformas, sizeof(int), 1, fArquivoBin);

    if(*total_plataformas > 0){
        *BancoPlataformas = (PLATAFORMAS*) malloc(*total_plataformas * sizeof(PLATAFORMAS));
        fread(*BancoPlataformas, sizeof(PLATAFORMAS), *total_plataformas, fArquivoBin);
    }

    //lendo as assinaturas que estao no arquivo
    fread(total_assinaturas, sizeof(int), 1, fArquivoBin);

    if(*total_assinaturas > 0){
        *BancoAssinaturas = (ASSINATURAS*) malloc(*total_assinaturas * sizeof(ASSINATURAS));
        fread(*BancoAssinaturas, sizeof(ASSINATURAS), *total_assinaturas, fArquivoBin);
    }

    fclose(fArquivoBin);
    LimparTerminal();
    printf("Dados carregados com sucesso!\n");
    printf("Pressione ENTER para continuar.\n\n");
    getchar();

    return 1;//retornando 1 pq o programa conseguiu abrir e ler o arquivo com sucesso
}

//funcao principal
int main(){

    int total_clientes = 0;
    int total_plataformas = 0;
    int total_assinaturas = 0;

    USUARIOS *pBancoUsuarios = NULL;
    PLATAFORMAS *pBancoPlataformas = NULL;
    ASSINATURAS *pBancoAssinaturas = NULL;

    procurar_arquivo(&pBancoUsuarios, &total_clientes, &pBancoPlataformas, &total_plataformas,&pBancoAssinaturas, &total_assinaturas);

    while(1){
        int opcao = MenuPrincipal(opcao);

        if(opcao == 1){
            opcao = GerenciamentoDeClientes();
            if(opcao == 1){
                pBancoUsuarios = realloc(pBancoUsuarios, (total_clientes + 1) * sizeof(USUARIOS));
                CadastrarNovoCliente(pBancoUsuarios, &total_clientes);
                total_clientes++;
            }else if(opcao == 2){
                BuscarCliente(pBancoUsuarios, &total_clientes);
            }else if(opcao == 3){
                LimparTerminal();
                AlterarDadosClientes(pBancoUsuarios, &total_clientes);
            }else if(opcao == 4){
                LimparTerminal();
                ExcluirCliente(pBancoUsuarios, &total_clientes);
                if(total_clientes > 0){
                    pBancoUsuarios = realloc(pBancoUsuarios, total_clientes * sizeof(USUARIOS));
                }
            }else{
                continue;
            }
        }else if(opcao == 2){
            opcao = GerenciamentoDePlataformas();
            if(opcao == 1){
                pBancoPlataformas = realloc(pBancoPlataformas, (total_plataformas + 1) * sizeof(PLATAFORMAS));
                CadastrarNovaPlataforma(pBancoPlataformas, &total_plataformas);
                total_plataformas++;
            }else if(opcao == 2){
                BuscarPlataforma(pBancoPlataformas, &total_plataformas);
            }else if(opcao == 3){
                AlterarDadosPlataformas(pBancoPlataformas, &total_plataformas);
            }else if(opcao == 4){
                LimparTerminal();
                ExcluirPlataforma(pBancoPlataformas, &total_plataformas);
                if(total_plataformas > 0){
                    pBancoPlataformas = realloc(pBancoPlataformas, total_plataformas * sizeof(pBancoPlataformas));
                }
            }else{
                continue;
            }
        }else if(opcao == 3){
            opcao = GerenciamentoDeAssinaturas();
            if(opcao == 1){
                pBancoAssinaturas = realloc(pBancoAssinaturas, (total_assinaturas + 1) * sizeof(ASSINATURAS));
                CadastrarNovaAssinatura(pBancoUsuarios, pBancoPlataformas, pBancoAssinaturas, &total_clientes, &total_plataformas, &total_assinaturas);
            }else if(opcao == 2){
                BuscarAssinatura(pBancoAssinaturas, &total_assinaturas);
            }else if(opcao == 3){
                AlterarDadosAssinatura(pBancoAssinaturas, &total_assinaturas, pBancoPlataformas, &total_plataformas);
            }else{
                continue;
            }
        }else{
            exit(0);
        }
    }

    return 0;
}
