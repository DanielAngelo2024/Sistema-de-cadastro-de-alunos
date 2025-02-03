#include <iostream>
#include <locale>

struct Disciplina
{
    double notas[4], somaMedia, media;

    void setNota()
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
    void exibirNotas(){
        for (int i = 0; i < 4; i++)
        {
            std::cout<<"Nota "<<i+1<<" "<<notas[i]<<std::endl;
        }
        
    }
    void calcularMedia()
    {
        for (int i = 0; i < 4; i++)
        {
            somaMedia += notas[i];
        }
    notas[5] = somaMedia / 4;
    }
};

struct Aluno
{
    std::string nome;
    int idade;
    Disciplina disciplinas[5];

    void setNome(){
        std::cout<<"Digite o nome:"<<std::endl;
        std::cin>>nome;
    }
    void setIdade(){
        std::cout<<"Digite a idade de "<<nome<<":"<<std::endl;
        std::cin>>idade;
    }
    void setAluno(){
        std::cout<<"----Adicionar aluno----"<<std::endl;
        setNome();
        setIdade();
    }
    void setNotaAluno(){
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
    void exibirDisciplinasAluno(){
        for (int i = 0; i < 5; i++)
        {
            std::cout<<"Disciplina "<<i+1<<":"<<std::endl;
            disciplinas[i].exibirNotas();
        }
        
    }
    
    void exibirAluno(){
        std::cout<<"Nome: "<<nome<<"."<<std::endl;
        std::cout<<"Idade: "<<idade<<"."<<std::endl;
        exibirDisciplinasAluno();
    }
};

void exibirAlunos(Aluno alunos[], int alunosRegistrados){
    for (int i = 0; i < alunosRegistrados; i++)
    {
        std::cout<<"----------------------------------- \n"
        "Aluno ID: "<<i+1<<":"<<std::endl;
        alunos[i].exibirAluno();
    }
    
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    const int TOTAL_ALUNOS = 50;
    Aluno alunos[TOTAL_ALUNOS];
    int alunosRegistrados = 0;
    int flag = 1;
    int i = -1;
    int opcao;
    
    do
    {
        if (alunosRegistrados == 0)
        {
            std::cout<<"Sem aluno registrado, adicione uma aluno para começar! \n";
            opcao = 1;
        } else{
            std::cout<<"Alunos registrados: "<<alunosRegistrados<<std::endl;
            std::cout<<"Aluno selecionado atual: "<<alunos[i].nome<<" ID: "<<i+1<<std::endl;
            std::cout<<"1-Adicionar aluno, 2-Alterar notas, 3-Exibir aluno, 4-Exibir alunos, 5-Histórico, 6-Selecionar aluno 0-Sair"<<std::endl;
            std::cin>>opcao;
        }
        
        switch (opcao)
        {
            case 1:
                i++;
                alunos[i].setAluno();
                alunosRegistrados++;
                
            break;
            case 2:
                alunos[i].setNotaAluno();
            break;
            case 3:
                alunos[i].exibirAluno();
            break;
            case 4:
                exibirAlunos(alunos, alunosRegistrados);
            break;
            case 6:
                std::cout<<"Escolha o aluno por ID: \n";
                std::cin>>i;
                i--;
            break;
            case 0:
                std::cout<<"Programa encerrado!";
                flag = 0;
            break;
            default:
                std::cerr<<"Opção inválida!"<<std::endl;
            break;
        }
    } while (flag == 1);
}