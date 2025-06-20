#include <iostream>
#include <locale>
#include <string>
#include <fstream>

struct Disciplina
{
    double notas[4], somaMedia, media;

    void setNota();
    void exibirNotas();
    void calcularMedia();
};

struct Aluno
{
    int ID = 0; // Inicializa o ID do aluno como 0
    std::string nome;
    int idade;
    Disciplina disciplinas[5];
    Aluno* proximo;

    void inserirInicio(Aluno*& cabeca){ // Insere um novo aluno no início da lista
        Aluno* novoAluno = new Aluno; // Cria um novo aluno
        novoAluno->ID = 0; // Inicializa o ID do novo aluno como 0
        novoAluno->setAluno(); // Define o aluno com os dados inseridos pelo usuário
        novoAluno->proximo = cabeca; // Define o próximo aluno como a cabeça da lista atual
        cabeca = novoAluno; // Define o novo aluno como a nova cabeça da lista
    }

    void inserirFinal(Aluno*& cabeca){ // Insere um novo aluno no final da lista
        Aluno* novoAluno = new Aluno;
        novoAluno->setAluno(); // Define o aluno com os dados inseridos pelo usuário
        novoAluno->proximo = nullptr; // Define o próximo aluno como nullptr, pois será o último da lista

        if (cabeca == nullptr) { // Se a lista estiver vazia, o novo aluno se torna a cabeça da lista
            novoAluno->ID = 1; // Inicializa o ID do novo aluno como 1
            cabeca = novoAluno;
            return;
        }else{
            Aluno* temp = cabeca; // Se a lista não estiver vazia, percorre até o final da lista
            int id = 1;
            while(temp->proximo != nullptr) { 
                temp = temp->proximo; // Avança para o próximo aluno na lista
                id++;
            }
            temp->proximo = novoAluno; // Define o novo aluno como o próximo do último aluno da lista
            novoAluno->ID = id + 1;
        }
    }

    void exibirListaAlunos(Aluno* cabeca) {
        while (cabeca != nullptr) {
            std::cout << "-----------------------------------" << std::endl;
            std::cout << "Aluno ID: " << cabeca->ID << std::endl; // Exibe o endereço do aluno como ID
            std::cout << "Nome: " << cabeca->nome << std::endl; // Exibe o nome do aluno
            std::cout << "Idade: " << cabeca->idade << std::endl; // Exibe a idade do aluno
            std::cout << "Disciplinas e Notas:" << std::endl; // Exibe as disciplinas e notas do aluno
            for (int i = 0; i < 5; i++) { 
                std::cout << "Disciplina " << i + 1 << ": "; // Exibe o número da disciplina
                cabeca->disciplinas[i].exibirNotas(); // Exibe as notas da disciplina 
            }
            cabeca = cabeca->proximo; // Avança para o próximo aluno na lista
        }
    }

    void setNome();
    void setIdade();
    void setAluno();
    void setNotaAluno();
    void exibirDisciplinasAluno();
    void exibirAluno();
};



void criarArquivo(Aluno alunos[], int alunosRegistrados){
    std::ofstream escreve;
    escreve.open("alunos.txt");
    
    if (escreve.is_open())
    {
        for (int i = 0; i < alunosRegistrados; i++)
        {
            escreve << "Aluno ID: " << i+1 << "\n";
            escreve << "Nome: " << alunos[i].nome << "\n";
            escreve << "Idade: " << alunos[i].idade << "\n";
            for (int j = 0; j < 5; j++)
            {
                escreve << "Disciplina " << j+1 << ": ";
                for (int k = 0; k < 4; k++)
                {
                    escreve << alunos[i].disciplinas[j].notas[k] << " ";
                }
                escreve << "\n";
            }
            escreve << "-----------------------------------\n";
        }
        escreve.close();
        std::cout<<"Arquivo criado com sucesso!"<<std::endl;
    } else {
        std::cerr<<"Erro ao criar arquivo!"<<std::endl;
    }

}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    Aluno* alunos = nullptr;
    int* flag = new int(1);
    int* opcao = new int;
    
    do
    {
        if(alunos == nullptr) {
            std::cout<<"Nenhum aluno registrado, por favor adicione um aluno!"<<std::endl; // Cria o primeiro aluno
            alunos->inserirInicio(alunos); // Insere o primeiro aluno na lista
        }else{
            //std::cout<<"Alunos registrados: "<<std::endl;
            std::cout<<"Aluno selecionado atual: "<<alunos->ID<<std::endl;
            std::cout<<"Nome do aluno: "<<alunos->nome<<std::endl;
            std::cout<<"Idade do aluno: "<<alunos->idade<<std::endl;
            std::cout<<"1-Adicionar aluno, 2-Alterar notas, 3-Exibir aluno, 4-Exibir alunos, 5-Histórico, 6-Selecionar aluno 0-Sair"<<std::endl;
            std::cin>>*opcao;
        
            switch (*opcao)
            {
                case 1:
                    alunos->inserirFinal(alunos);

                break;
                case 2:
                    alunos->setNotaAluno();
                break;
                case 3:
                    alunos->exibirAluno();
                break;
                case 4:
                    alunos->exibirListaAlunos(alunos);
                break;
                case 6:
                /* std::cout<<"Escolha o aluno por ID: \n";
                    std::cin>>i;*/
                break;
                case 0:
                    std::cout<<"Programa encerrado!";
                    *flag = 0;
                break;
                default:
                    std::cerr<<"Opção inválida!"<<std::endl;
                break;
            }
        }
    } while (*flag == 1);

    //criarArquivo(alunos, alunos.);

    delete alunos;
    alunos = nullptr;
    delete flag;
    flag = nullptr;
    delete opcao;
    opcao = nullptr;
    return 0;
}


#pragma region Disciplina

void Disciplina::setNota()
{
    int posicaoNota;

    std::cout<<"Qual nota deseja modificar? (1 a 4)"<<std::endl;
    std::cin>>posicaoNota;

    if(posicaoNota >= 1 && posicaoNota <= 4)
    {
        std::cout<<"Digite a nota "<<posicaoNota<<":"<<std::endl;
        std::cin>>notas[posicaoNota-1];
        
        if(notas[posicaoNota-1] >= 0 && notas[posicaoNota-1] <= 10)
        {
        std::cout<<"Nota adicionada com sucesso!"<<std::endl;
        } else
        {
            std::cout<<"Erro! Digite a nota de 0 a 10!"<<std::endl;
            return setNota();
        }
        
    } else
    {
        std::cout<<"Erro! Escolha a nota de 1 a 4!"<<std::endl;
        return setNota();
    }  
}

void Disciplina::exibirNotas()
{
    for (int i = 0; i < 4; i++)
    {
        std::cout<<"Nota "<<i+1<<" "<<notas[i]<<std::endl;
    }
}

void Disciplina::calcularMedia()
{
    for (int i = 0; i < 4; i++)
    {
        somaMedia += notas[i];
    }
    notas[5] = somaMedia / 4;
}

#pragma endregion

#pragma region Aluno



void Aluno::setNome()
{
    std::cout<<"Digite o nome:"<<std::endl;
    std::cin>>nome;
}

void Aluno::setIdade()
{
    std::cout<<"Digite a idade de "<<nome<<":"<<std::endl;
    std::cin>>idade;
}

void Aluno::setAluno()
{
    std::cout<<"----Adicionar aluno----"<<std::endl;
    setNome();
    setIdade();
}

void Aluno::setNotaAluno()
{
    int i;
    std::cout<<"Qual disciplina deseja modificar nota: (1 a 5)"<<std::endl;
    std::cin>>i;
    if (i >= 1 && i <= 5)
    {
        disciplinas[i-1].setNota();
    }else{
        std::cout<<"Erro disciplina errada, digite valor de 1 a 5"<<std::endl;
        return setNotaAluno();
    }
}

void Aluno::exibirDisciplinasAluno()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout<<"Disciplina "<<i+1<<":"<<std::endl;
        disciplinas[i].exibirNotas();
    }
}

void Aluno::exibirAluno()
{
    std::cout<<"Nome: "<<nome<<"."<<std::endl;
    std::cout<<"Idade: "<<idade<<"."<<std::endl;
    exibirDisciplinasAluno();
}

#pragma endregion
