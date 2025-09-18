![C++](https://img.shields.io/badge/language-C++-blue.svg)  
![Status](https://img.shields.io/badge/status-in%20development-yellow)  
![License](https://img.shields.io/badge/license-MIT-green)

---

## 📘 Sobre o Projeto / About the Project

O **Sistema de Cadastro de Alunos** é um projeto acadêmico desenvolvido como desafio no segundo período do curso de **Engenharia de Software**.  
O objetivo é aplicar conceitos fundamentais de **algoritmos, estruturas de dados, listas, ponteiros e modularização de código em C++**.  

The **Student Registration System** is an academic project developed as a challenge during the second semester of the **Software Engineering** degree.  
Its purpose is to apply fundamental concepts of **algorithms, data structures, lists, pointers, and modularization in C++**.  

O sistema será atualizado continuamente com novas funcionalidades, de acordo com os conteúdos apresentados em sala de aula.  
The system will be continuously updated with new features according to the course content presented in class.  

---

## 📂 Estrutura da Documentação / Documentation Structure

A documentação do sistema está disponível em múltiplos idiomas:  
The system documentation is available in multiple languages:  

- 🇧🇷 [Documentação em Português (PT-BR)](./docs/pt-br/documentacao-requisitos.md)  
- 🇺🇸 [Documentation in English (EN)](./docs/en/requirements-documentation.md)  

---

## ⚙️ Funcionalidades Principais / Main Features

- Cadastro de alunos / Student registration  
- Cadastro de disciplinas vinculadas a professores / Registration of subjects linked to teachers  
- Registro e alteração de notas / Grade registration and modification  
- Listagem e exibição de alunos cadastrados / Listing and displaying registered students  
- Remoção de alunos / Student removal  
- Mensagens apropriadas para lista vazia / Appropriate messages when the list is empty  
- Encerramento da aplicação sob comando do usuário / Application termination upon user command  

---

## 🏗️ Arquitetura / Architecture

O sistema segue uma **arquitetura monolítica**, ou seja, todas as funcionalidades estão integradas em um único código, sem separação de camadas físicas.  
The system follows a **monolithic architecture**, meaning all functionalities are integrated within a single codebase, without physical layer separation.

Apesar de monolítico, o código é modularizado em funções protótipo, facilitando manutenção e futura evolução.  
Although monolithic, the code is modularized into prototype functions, facilitating maintenance and future evolution.  

1. **Interface Layer / Camada de Interface** – menus interativos no console / interactive menus in the console.  
2. **Business Layer / Camada de Negócios** – regras de negócio (cadastro, alteração, validações) / business rules (registration, modification, validations).  
3. **Data Layer / Camada de Dados** – estruturas (`structs`, listas, ponteiros) / data structures (`structs`, lists, pointers).  
