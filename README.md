# Plataforma de Gerenciamento de Assinaturas (Streaming)

Trabalho prático da disciplina de **Algoritmos II**.

Este projeto implementa, em **C**, um sistema em modo texto para **cadastrar clientes, plataformas de streaming e assinaturas**, permitindo também **salvar/carregar dados** em arquivo binário e **gerar um relatório** em arquivo `.txt`.

---

## Autores

- Marcos Franco Oliveira Junior — **12421BSI240**
- Carlos Samuel Soares Pereira — **1211BSI239**
- Alex Ribeiro da Mata — **12421BSI376**
- João Antonônio Correa Vieira Rodrigues — **12421BSI356**

## Sumário

- [Visão geral](#visão-geral)
- [Funcionalidades](#funcionalidades)
- [Como compilar](#como-compilar)
- [Como executar](#como-executar)
- [Guia rápido de uso (menus)](#guia-rápido-de-uso-menus)
- [Persistência de dados (carregar/salvar)](#persistência-de-dados-carregarsalvar)
- [Formatos de entrada e validações](#formatos-de-entrada-e-validações)
- [Estruturas de dados](#estruturas-de-dados)
- [Arquivos gerados](#arquivos-gerados)

---

## Visão geral

O programa mantém três “cadastros” em memória:

- **Clientes** (`USUARIOS`) — identificados unicamente por **CPF**.
- **Plataformas** (`PLATAFORMAS`) — identificadas unicamente por **nome da plataforma**.
- **Assinaturas** (`ASSINATURAS`) — vínculo entre **CPF do cliente** e **plataforma**, contendo status (ativa/cancelada) e valor pago.

A interação é feita por **menus no terminal**.

---

## Funcionalidades

### Clientes

- Cadastrar novo cliente (nome, CPF, telefone, e-mail)
- Buscar cliente por CPF
- Alterar dados de um cliente
- Excluir cliente

### Plataformas

- Cadastrar nova plataforma (nome, categoria, preço, URL)
- Buscar plataforma por nome
- Alterar dados de uma plataforma
- Excluir plataforma

### Assinaturas

- Cadastrar assinatura (vinculando **cliente existente** a **plataforma existente**)
- Buscar assinatura por **CPF + plataforma**
- Alterar dados da assinatura (trocar plataforma e/ou valor pago)
- Cancelar assinatura

### Relatório

- Gerar relatório em arquivo texto (`banco_dados.txt`)

---

## Como compilar

Requisitos:

- GCC (Linux/macOS) ou MinGW (Windows)

Compilação (Linux/macOS):

```bash
gcc main.c -o locadora
```

> Dica: se o seu GCC exigir, você pode tentar `-Wall -Wextra` para ver avisos.

---

## Como executar

Linux/macOS:

```bash
./locadora
```

Windows:

```bash
locadora.exe
```

---

## Guia rápido de uso (menus)

Ao iniciar, o programa pode detectar um arquivo binário existente (`banco_dados.bin`) e pergunta se você quer:

- **(1) Usar os dados salvos** (carregar do arquivo), ou
- **(2) Sobrescrever** (começar com base vazia).

### Menu principal

1. Gerenciamento de clientes
2. Gerenciamento de plataformas
3. Gerenciamento de assinaturas
4. Gerar arquivo de relatório
5. Sair

### Fluxo recomendado (primeira utilização)

1. Cadastre **clientes**.
2. Cadastre **plataformas**.
3. Cadastre **assinaturas** vinculando um CPF a uma plataforma.
4. Gere relatório quando quiser conferir os registros em texto.
5. Saia para salvar seus dados no binário.

---

## Persistência de dados (carregar/salvar)

O projeto utiliza dois arquivos principais:

- `banco_dados.bin`: **persistência binária** (usada para recarregar dados na próxima execução).
- `banco_dados.txt`: **relatório legível** (gerado pelo menu “Gerar Arquivo de Relatorio”).

### Quando os dados são salvos

- Ao escolher **“Sair”**, o programa salva automaticamente em `banco_dados.bin`.
- Ao escolher **“Gerar Arquivo de Relatorio”**, além de gerar `banco_dados.txt`, também salva o `.bin`.

---

## Formatos de entrada e validações

O programa faz validações simples de formato para alguns campos. Para evitar erros, digite exatamente como abaixo:

### CPF

Formato esperado:

- `000.000.000-00`

### Telefone

Formato esperado:

- `(00)0000-0000`

> Observação: o prompt do programa pode variar entre 4 ou 5 dígitos antes do hífen, mas a validação atual aceita **13 caracteres** no formato acima.

### E-mail

- Precisa conter pelo menos um `@`.

### URL da plataforma

- Precisa conter pelo menos um ponto `.` (ex.: `netflix.com`).

### Observação sobre nomes

- A busca de cliente/plataforma é feita por **comparação sem diferenciar maiúsculas/minúsculas**.
- Para assinaturas, a busca/alteração usa **CPF + nome da plataforma**.

---

## Estruturas de dados

| Struct        | Campos principais                                                                             |
| ------------- | --------------------------------------------------------------------------------------------- |
| `USUARIOS`    | `nome`, `cpf`, `id_usuario`, `phone`, `email`                                                 |
| `PLATAFORMAS` | `nome_plataforma`, `id_plataforma`, `categoria`, `preco`, `site_url`                          |
| `ASSINATURAS` | `cpf_usuario_assinante`, `nome_plataforma_contratada`, `id_assinatura`, `ativa`, `valor_pago` |

IDs são atribuídos automaticamente:

- Cliente: `1000 + índice`
- Plataforma: `5000 + índice`
- Assinatura: `20000 + índice`

---

## Arquivos gerados

Estrutura típica do projeto:

``` text
├── main.c
├── banco_dados.bin
├── banco_dados.txt
└── README.md
```

- `banco_dados.bin` é criado/atualizado pelo programa.
- `banco_dados.txt` é gerado quando você escolhe a opção de **relatório** no menu.

---
