#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Aplicacao.h"

/*Essa função tem como objetivo apresentar para o usuário o elemento do início da fila
(de acordo com o seu tipo). E/OU retornar o  elemento que foi desenfileirado*/
void ImprimirItem(void *e, int tipo, int opcao){

    char msg[100];
    char mat[20];

    /*Definindo a mensagem que será apresentada para o usuário*/
    if(opcao == 6){
        strcpy(msg, "\nO elemento removido foi:");
       
    }else{
        strcpy(msg, "\nO elemento do início da fila é:");
    }

    switch (tipo){
        case 1:
            /*O elemento é uma struct*/
            printf("%s\n", msg);    
            printf("%s", ((aluno *)e)->nome);
            printf("%d anos\n", ((aluno *)e)->idade);
            printf("%s\n", ((aluno *)e)->curso);
            break;
        case 2:
            /*O elemento é um float*/
            printf("%s %.2f\n", msg, *(float *) e); 
            
            break;
        case 3:
            /*O elemento é um caracter*/
            printf("%s %c\n", msg, *(int *) e);
            
            break;
        case 4:
            /*O elemento é um inteiro*/
            printf("%s %d\n", msg, *(int *) e);
            
            break;
        case 5:
            /*O elemento é uma string*/
            strcpy(mat, e);
            printf("%s %s\n", msg, mat);
            
            break;
            
        default:
            break;
    }
}


/*Função de menu, aqui são implementadas as opções apresentadas
para o usuário na função main*/
void Menu(fila *f, int opcao, int tipo){
    /*Variáveis de entrada, serão inicializadas pelo usuário*/
    float notaFloat;
    char materia[20];
    char notaChar;
    int notaInt, retorno, tRetornado;
    void *eRetornado;
    elemento *eRemovido, *eInicio;
    aluno a;
    
    switch (opcao){
        case 0:
            /*Caso 0: Sair*/
            printf("\n\n#########################\n");
            printf("\nEncerrando o programa!\n");
            printf("\n#########################\n");

            break;

        case 1:
            /*Caso 1: Inserir struct*/
            printf("\nInforme o nome do aluno:\n");
            setbuf(stdin, 0); //limpar buffer para receber novos dados
            fgets (a.nome, 20, stdin);
            
            printf("\nInforme a idade do aluno:\n");
            setbuf(stdin, 0); //limpar buffer para receber novos dados
            scanf("%d", &a.idade);

            printf("\nInforme o curso do aluno:\n");
            setbuf(stdin, 0); //limpar buffer para receber novos dados
            fgets (a.curso, 50, stdin);
            
            
            /*Enfileirando*/
            retorno = inserir(f, &a, sizeof(a), tipo);

            if(retorno == 0){
                printf("\nAluno inserido com sucesso!\n");
            }else{
                printf("\nErro ao inserir o aluno!\n");
            }

            break;

        case 2:
            /*Caso 2: Inserir float*/
            printf("\nInforme a nota do aluno (float):\n");
            setbuf(stdin, 0); //limpar buffer para receber novos dados
            scanf("%f", &notaFloat);

            /*Enfileirando*/
            retorno = inserir(f, &notaFloat, sizeof(notaFloat), tipo);
 
            if(retorno == 0){
                printf("\nNota inserida com sucesso!\n");
            }else{
                printf("\nErro ao inserir a nota!\n");
            }

            break;

        case 3:
            /*Caso 3: Inserir char*/
            printf("\nInforme o conceito do aluno (char):\n");
            setbuf(stdin, 0); //limpar buffer para receber novos dados
            scanf("%c", &notaChar);

            /*Enfileirando*/
            retorno = inserir(f, &notaChar, sizeof(notaChar), tipo);

            if(retorno == 0){
                printf("\nConceito inserido com sucesso!\n");
            }else{
                printf("\nErro ao inserir o conceito!\n");
            }

            break;

        case 4:
            /*Caso 4: Inserir int*/
            printf("\nInforme a nota do aluno (int):\n");
            setbuf(stdin, 0); //limpar buffer para receber novos dados
            scanf("%d", &notaInt);

            /*Enfileirando*/
            retorno = inserir(f, &notaInt, sizeof(notaInt), tipo);

            if(retorno == 0){
                printf("\nNota inserida com sucesso!\n");
            }else{
                printf("\nErro ao inserir a nota!\n");
            }

            break;

        case 5:
            /*Caso 5: Inserir string*/
            printf("\nInforme a matéria (string):\n");
            setbuf(stdin, 0); //limpar buffer para receber novos dados
            fgets (materia, 20, stdin);
 
            /*Enfileirando*/
            retorno = inserir(f, &materia, sizeof(materia), tipo);

            if(retorno == 0){
                printf("\nMatéria inserida com sucesso!\n");
            }else{
                printf("\nErro ao inserir a matéria!\n");
            }

            break;
        
        case 6:
            /*Caso 6: Desenfileirar*/
            eRemovido = retirar(f);
            
            /*Se o elemento retornado pela função retirar() for igual a 
            NULL significa que a fila estava vazia ou algo deu errado*/
            if(eRemovido != NULL){
                /*Se o elemento for diferente de NULL então imprime o
                elemento removido em tela*/

                eRetornado = verElemento(eRemovido);
                tRetornado = verTipo(eRemovido);
                ImprimirItem(eRetornado, tRetornado, opcao);

                /*Dado que nas funções retirar() e verElemento foi alocado espaço 
                de memória para o elemento removido, aqui estamos liberando esse espaço*/
                destroiElemento(eRemovido);
                free(eRetornado);
            }

            
            break;

        case 7:
            /*Caso 7: Imprimir elemento do início*/

            /*Busca no início*/
            eInicio = verInicio(f);
            
            /*Se o elemento retornado pela função verInicio() for igual a 
            NULL significa que a fila estava vazia ou algo deu errado */
            if (eInicio != NULL){
                /*Se o elemento for diferente de NULL então imprime o elemento
                do início em tela*/
                
                eRetornado = verElemento(eInicio);
                tRetornado = verTipo(eInicio);
                ImprimirItem(eRetornado, tRetornado, opcao);

                /*Dado que nas funções verInicio() e verElemento foi alocado espaço 
                de memória para o elemento do início, aqui estamos liberando esse espaço*/
                destroiElemento(eInicio);
                free(eRetornado);
            }
            
            break;

        case 8:
            /*Caso 8: Verificar fila cheia*/
            retorno = verificarCheia(f);

            if(retorno == 0){
                printf("\nA fila está cheia!\n");
            }else{
                printf("\nA fila não está cheia!\n");
            }

            break;
        
        case 9:
            /*Caso 9: Verificar fila vazia*/
            retorno = verificarVazia(f);

            if(retorno == 0){
                printf("\nA fila está vazia!\n");
            }else{
                printf("\nA fila não está vazia!\n");
            }

            break;

        default:
            printf("\nOpção inválida!\n");

            break;
    }

}

int main() {
    /*Inicializando/criando a fila e as demais variáveis*/
    int tamMax = 4;
    fila *f = criar(tamMax);

    int opcao = -1;
    int tipo = 0;
    
    /*Enquanto o usuário não digita 0 para encerrar a aplicação, a mesma fica no
    loop apresentando o menu*/
    while(opcao != 0){
        
        printf("\n\n############ MENU ############\n");
        printf("Escolha uma opção:\n");

        printf("0.  Sair\n");
        printf("1.  Inserir aluno (enfileirar struct)\n");
        printf("2.  Inserir nota do aluno (enfileirar float)\n");
        printf("3.  Inserir conceito do aluno (enfileirar caracter)\n");
        printf("4.  Inserir nota do aluno (enfileirar int)\n");
        printf("5.  Inserir matéria (enfileirar string)\n");
        printf("6.  Desenfileirar\n");
        printf("7.  Ver elemento do início da fila\n");
        printf("8.  Verificar se a fila está cheia\n");
        printf("9.  Verificar se a fila está vazia\n");
    
        scanf("%d", &opcao);

        /*Verifica o tipo da informação que será enfileirada, esse tipo será correspondente a opção 
        selecionada no menu.*/
        if(opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 || opcao == 5){
            tipo = opcao;
        }

        /*Chamada da função Menu*/
        Menu(f, opcao, tipo);

    }

    /*Ao encerrar a aplicação a fila será destruída*/
    destruir(f); 
    
    return 0;
}
