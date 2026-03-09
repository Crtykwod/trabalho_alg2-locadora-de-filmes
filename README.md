# Plataforma de Gerenciamento de Assinaturas

Trabalho prático da disciplina de Algoritmos II. Sistema de gerenciamento de assinaturas de plataformas de streaming, desenvolvido em C.

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

- Cadastrar nova assinatura (vinculando cliente a uma plataforma)
- Buscar assinatura por CPF e plataforma
- Alterar dados da assinatura (plataforma ou valor)
- Cancelar assinatura

### Persistência de dados

- Os dados são salvos automaticamente em arquivo binário (`banco_dados.bin`) ao encerrar o programa
- Um arquivo de texto legível (`banco_dados.txt`) também pode ser gerado
- Ao iniciar, o programa detecta se já existe um arquivo salvo e oferece a opção de carregá-lo

## Compilação

Requisitos: GCC (MinGW no Windows ou GCC nativo no Linux/macOS)

```bash
gcc main.c -o locadora
```

## Execução

```bash
./locadora        # Linux/macOS
locadora.exe      # Windows
```

## Estrutura do projeto

```
├── main.c           # Código-fonte principal
├── banco_dados.bin  # Arquivo binário de dados (gerado em tempo de execução)
├── banco_dados.txt  # Arquivo texto de dados (gerado em tempo de execução)
└── README.md
```

## Estruturas de dados

| Struct        | Campos                                                                              |
| ------------- | ----------------------------------------------------------------------------------- |
| `USUARIOS`    | nome, cpf, id_usuario, phone, email                                                 |
| `PLATAFORMAS` | nome_plataforma, id_plataforma, categoria, preco, site_url                          |
| `ASSINATURAS` | cpf_usuario_assinante, nome_plataforma_contratada, id_assinatura, ativa, valor_pago |
