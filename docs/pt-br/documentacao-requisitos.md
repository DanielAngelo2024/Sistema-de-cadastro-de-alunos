# 📘 Documentação do Sistema de Cadastro de Alunos

## 1. Descrição Geral
O **Sistema de Cadastro de Alunos** é um projeto acadêmico desenvolvido como desafio no segundo período da graduação em Engenharia de Software.  
Seu objetivo é aplicar conceitos fundamentais de algoritmos, estruturas de dados, alocação dinâmica de memória e modularização de código em linguagem **C++**.  

O sistema será evoluído progressivamente, acompanhando o avanço dos conteúdos abordados em sala de aula, incorporando novos conceitos e técnicas conforme a necessidade.

---

## 2. Requisitos Funcionais (RF)

- **RF01** – O sistema deve permitir o cadastro de novos alunos.  
- **RF02** – O sistema deve exigir o cadastro de disciplinas vinculadas ao professor.  
- **RF03** – O sistema deve registrar notas para cada aluno em suas respectivas disciplinas.  
- **RF04** – O sistema deve permitir a alteração de notas previamente registradas.  
- **RF05** – O sistema deve exibir os dados do aluno atualmente selecionado.  
- **RF06** – O sistema deve permitir a seleção de um aluno na lista.
- **RF07** – O sistema deve exibir a lista completa de alunos cadastrados.  
- **RF08** – O sistema deve exibir uma mensagem apropriada caso não haja alunos cadastrados.  
- **RF09** – O sistema deve permitir a remoção de alunos da lista.  
- **RF10** – O sistema deve permitir que o usuário encerre a execução a qualquer momento.  
- **RF11** - O sistema deve exigir o cadastro do professor
- **RF12** - O sistema deve exibir uma mensagem de encerramento

---

## 3. Requisitos Não Funcionais (RNF)

- **RNF01** – O sistema deve ser implementado em linguagem de programação **C++**.  
- **RNF02** – O sistema deve utilizar **structs** para modelar alunos e disciplinas.  
- **RNF03** – O sistema deve implementar o cadastro de alunos utilizando **lista**.  
- **RNF04** – O sistema deve utilizar **ponteiros** para manipulação dinâmica de memória.  
- **RNF05** – O código deve ser modularizado em funções protótipo, favorecendo clareza e reutilização.  
- **RNF06** – O sistema deve possuir interface textual simples e intuitiva, executada em **console/terminal**.  
- **RNF07** – O sistema deve otimizar o uso de memória por meio da alocação dinâmica.  

---

## 4. Arquitetura Monolítica

### 4.1. Camada de Interface
- O sistema deve disponibilizar menus interativos no terminal para navegação do usuário.  
- O sistema deve capturar as entradas fornecidas pelo usuário (nome, matrícula, disciplina, nota e opções de menu).  
- O sistema deve apresentar mensagens informativas, de erro ou de confirmação das operações realizadas.  

### 4.2. Camada de Negócios
- O sistema deve conter as regras para cadastro de alunos e disciplinas.  
- O sistema deve controlar o registro e a alteração de notas.  
- O sistema deve validar as operações de seleção de alunos.  
- O sistema deve impedir operações em listas vazias.  
- O sistema deve implementar regras de adição e remoção em lista.  

### 4.3. Camada de Dados
- O sistema deve conter as estruturas de dados fundamentais:
  - **Aluno**: nome, matrícula, lista de disciplinas.  
  - **Disciplina**: nome da disciplina e nota correspondente.  
- O sistema deve gerenciar a lista de alunos.  
- O sistema deve fornecer funções para inclusão, exclusão, busca e alteração de dados em memória.  

---

## 5. Componentes Principais

1. **Menu Principal**  
   - Responsável por exibir as opções disponíveis e direcionar o fluxo da aplicação.  

2. **Componente de Cadastro de Alunos**  
   - Responsável por criar um novo aluno e inseri-lo na lista.  

3. **Componente de Cadastro de Disciplinas e Notas**  
   - Responsável por registrar disciplinas e respectivas notas para os alunos.  

4. **Componente de Alteração de Notas**  
   - Responsável por localizar um aluno e atualizar suas notas.  

5. **Componente de Seleção de Aluno**  
   - Responsável por selecionar um aluno pelo índice (array) ou posição na lista.  

6. **Componente de Exibição de Alunos**  
   - Responsável por exibir os dados do aluno atual ou de todos os alunos cadastrados.  
   - Deve exibir mensagem apropriada quando não houver registros.  

7. **Componente de Remoção de Aluno** *(em desenvolvimento)*  
   - Responsável por excluir um aluno da lista.  

8. **Gerenciador de Lista**  
   - Responsável por manipular a lista de alunos.  
 
