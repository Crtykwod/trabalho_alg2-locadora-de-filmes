#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Data {
  int dia;
  int mes;
  int ano;
} Data;

typedef struct Cliente {
  int   id;
  char  nome[100];
  char  cpf[13]; //Apenas numeros + \n + \0
  char  phone[16]; //Apenas numeros +5534912345678 + 1 \n + 1 \0

} Cliente;

typedef struct Filme {
  int   id;
  char  titulo[100];
  char  genero[30];
  int   ano_lancamento;
  float preco_diaria;
  int   estoque;
} Filme;

typedef struct Locacao {
  int   id;
  int   id_cliente;
  int   id_filme;
  Data  data_locacao;
  Data  data_devolucao_prevista;
  int   foiDevolvido; //0 e 1
  float valor_pago;
} Locacao;

int my_strstr(char *str, char *word) {
  char *ponteiro_string = str;
  char *ponteiro_palavra = word;
  char *ponteiro_string_comeco;

  //ponteiro_string aponta para o primeiro endereço da string
  // *ponteiro_string mostra o conteúdo, ou seja, a letra

  //enquanto o conteudo de ponteiro nao for '\0' itere e avance o ponteiro
  for ( ; *ponteiro_string != '\0'; ponteiro_string++) {

    // verificamos se a letra no ponteiro da string é o mesmo do começo da palavra
    if (tolower(*ponteiro_string) == tolower(*word)) {

      // marcamos onde o ponteiro da string parou
      ponteiro_string_comeco = ponteiro_string;

      // redefinimos o ponteiro da palavra, caso ele tenha sido alterado em algum momento
      ponteiro_palavra = word;

      // enquanto nenhum dos ponteiros apontar para o fim ('\0') e o conteudo dos ponteiros forem iguais, avance os ponteiros;
      while ((*ponteiro_string != '\0' && *ponteiro_palavra != '\0') && (tolower(*ponteiro_string) == tolower(*ponteiro_palavra))) {
        ponteiro_string++;
        ponteiro_palavra++;
      }

      // se chegames ao final do ponteiro da palavra, então ela está presente na string, retorne sucesso.
      if (*ponteiro_palavra == '\0') return 1;

      // se não, volte o ponteiro da string para onde estavamos antes de comparar com a palavra.
      ponteiro_string = ponteiro_string_comeco;
    }
  }

  return 0;
}

int my_strcmp(char *str1, char *str2) {
  char *ptr_str1 = str1;
  char *ptr_str2 = str2;

  while (*ptr_str1 && *ptr_str2) {
    if (*ptr_str1 != *ptr_str2) return 1;
    ptr_str1++;
    ptr_str2++;
  }

  return 0;
}

int my_strlen(const char *str) {
  int count = 0;

  while (*str != '\0') {
    count++;

    // avança o ponteiro da string
    str++;
  }

  return count;
}

int isCpf(char *cpf) {
  if (my_strlen(cpf) != 11) return 0;

  // crio uma copia do ponteiro da string para poder iterar sobre ela sem perder a ref para a string original
  char *p = cpf;

  // isso aqui vai ver se o cpf não é 111.111.111-11
  int iguais = 1;
  while (*(p + 1)) {
    if (*p != *(p + 1)) {
      iguais = 0;
      break;
    }
    p++;
  }
  if (iguais) return 0;

  int soma, resto, digito1, digito2;
  int peso;

  soma = 0;
  peso = 10;
  p = cpf;

  for (int i = 0; i < 9; i++) {

    //soma é um int, então ele pega o valor char de p e subtrai '0', ou seja, '8' (em ascii é 56) - '0' que é igual a 48, retornando o int 8
    soma += (*p - '0') * peso;
    p++;
    peso--;
  }

  resto = soma % 11;
  if (resto < 2) digito1 = 0;
  else digito1 = 11 - resto;

  soma = 0;
  peso = 11;
  p = cpf;

  for (int i = 0; i < 10; i++) {
    soma += (*p - '0') * peso;
    p++;
    peso--;
  }

  resto = soma % 11;
  if (resto < 2) digito2 = 0;
  else digito2 = 11 - resto;

  // escrever assim é o mesmo que escrever cpf[9] e cpf[10]
  if ((*(cpf + 9) - '0') != digito1) return 0;
  if ((*(cpf + 10) - '0') != digito2) return 0;

  return 1;
}

int buscaCliente(Cliente *arr, int qtd, int idProcurado) {
  for (int i = 0; i < qtd; i++) {
    if (arr[i].id == idProcurado) {
      return i;
    }
  }
  return -1;
}

int buscaFilme(Filme *arr, int qtd, int idProcurado) {
  for (int i = 0; i < qtd; i++) {
    if (arr[i].id == idProcurado) {
      return i;
    }
  }
  return -1;
}

int buscaLocacao(Locacao *arr, int qtd, int idProcurado) {
  for (int i = 0; i < qtd; i++) {
    if (arr[i].id == idProcurado) {
      return i;
    }
  }
  return -1;
}

int main() {
  Cliente *clientes;
  Filme *filmes;
  Locacao *locacoes;

  int achou = my_strstr("que texto enorme gigante sobre O Poderoso Cheo. Caramba que sentença enorme, como alguem acharia uma frase aqui no meio?", "o poderoso chefao");

  printf("%d\n", achou);

  return 0;
}