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
  char *p1 = str;
  char *p2 = word;
  char *p1_start;

  for (; *p1++; ) {
    if (tolower(*p1) == tolower(*word)) {
      p1_start = p1;
      p2 = word;

      while ((*p1 != '\0' && *p2 != '\0') && (tolower(*p1) == tolower(*p2))) {
        p1++;
        p2++;
      }

      if (*p2 == '\0') return 1;

      p1 = p1_start;
    }
  }

  return 0;
}

int my_strlen(const char *str) {
  int count = 0;

  while (*str++) count++;

  return count;
}

int isCpf(char *cpf) {
  if (my_strlen(cpf) != 11) return 0;

  char *p = cpf;

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
    soma += (*p++ - '0') * peso--;
  }

  resto = soma % 11;
  if (resto < 2) digito1 = 0;
  else digito1 = 11 - resto;

  soma = 0;
  peso = 11;
  p = cpf;

  for (int i = 0; i < 10; i++) {
    soma += (*p++ - '0') * peso--;
  }

  resto = soma % 11;
  if (resto < 2) digito2 = 0;
  else digito2 = 11 - resto;

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

  int achou = my_strstr("que texto enorme gigante sobre O Poderoso Chefao. Caramba que sentença enorme, como alguem acharia uma frase aqui no meio?", "o poderoso chefao");

  printf("%d\n", achou);

  return 0;
}