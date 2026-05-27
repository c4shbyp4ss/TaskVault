# 📋 Todo List
> Gerenciador de tarefas simples rodando no terminal, desenvolvido em linguagem C.
> Adicione, liste e remova suas tarefas de forma rápida e prática!

---

## 📋 Índice
- [Sobre](#-sobre)
- [Demonstração](#-demonstração)
- [Funcionalidades](#-funcionalidades)
- [Pré-requisitos](#-pré-requisitos)
- [Instalação](#-instalação)
- [Como usar](#-como-usar)
- [Tecnologias](#-tecnologias)

---

## 📖 Sobre

O **Todo List** é um gerenciador de tarefas desenvolvido em C para rodar diretamente no terminal. O projeto foi criado com o objetivo de praticar e consolidar conhecimentos na linguagem C, explorando conceitos como controle de fluxo, manipulação de strings, arrays e interação com o usuário via terminal.

O usuário pode adicionar tarefas com nome e categoria, listá-las de forma organizada e removê-las quando concluídas. Tudo isso de forma simples, direto pelo terminal!

---

## 🎬 Demonstração

```
$ ./todolist

=======================================
       BEM-VINDO AO TODO LIST
=======================================

  Gerencie suas tarefas de forma
  simples e rapida pelo terminal.

  Pressione ENTER para continuar...

---------------------------------------
           MENU PRINCIPAL
---------------------------------------

  1. Adicionar tarefa
  2. Listar tarefas
  3. Remover tarefa
  0. Sair

---------------------------------------
Escolha uma opcao: _
```

> 💡 *GIF de demonstração será adicionado em breve.*

---

## ✅ Funcionalidades

- [x]  Tela de boas-vindas
- [x]  Menu principal interativo
- [x]  Adicionar tarefa com nome e categoria
- [x]  Listar tarefas cadastradas
- [x]  Remover tarefa por número com confirmação
- [x]  Aviso ao tentar adicionar com a lista cheia
- [x]  Tela de despedida

---

## 🔧 Pré-requisitos

Antes de começar, você vai precisar ter instalado:

- [GCC](https://gcc.gnu.org/) — compilador C (versão 11 ou superior recomendada)
- Sistema operacional: Linux / macOS / Windows (WSL)

Para verificar se o GCC está instalado:

```bash
gcc --version
```

---

## 🚀 Instalação

```bash
# Clone o repositório
git clone https://github.com/seu-usuario/todolist.git

# Entre na pasta do projeto
cd todolist

# Compile o projeto
gcc -o todolist main.c
```

---

## 💻 Como usar

```bash
# Execute o programa
./todolist
```

Após iniciar o programa:

1. Pressione **ENTER** na tela de boas-vindas
2. Escolha uma opção no menu principal
3. Para **adicionar**, informe o nome e a categoria da tarefa
4. Para **listar**, veja todas as tarefas cadastradas com suas categorias
5. Para **remover**, escolha o número da tarefa e confirme a remoção

---

## 🛠️ Tecnologias

| Tecnologia | Uso |
| --- | --- |
| C (C11) | Linguagem principal |
| GCC | Compilação |

---
