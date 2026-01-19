#include <stdio.h>
#include <stdlib.h>
/*  
    Um procedimento não precisa retornar nada ao ser chamado, servindo apenas para executar um bloco de código.
    Seu uso mais comum é quando precisa-se imprimir coisas na tela de um jeito formatado.
    Mas não se engane, este não seu único uso.
    Procedimentos geralmente não fornecem tratamento de erros, então, se algo falhar na execução não se terá um melhor entendimento do erro.
*/
void printfmod_procedimento(){
    printf("Esse e um procedimento\nAqui nada e retornado.\n");
}

/*  
    Uma função precisa retornar algo ao ser chamada.
    Comumente utilizada para funções de processamento de dados, ou para verificação de erros.
    Só porquê a função retorna algo, ela não necessariamente precisa ser atribuída à alguma variável quando chamada.
*/
int printfmod_funcao(){
    printf("Essa e uma funcao\nAqui retorno -1 como valor.\n");
    return -1;
}

int main(void){
    
    if (printfmod_funcao() == -1){
        printfmod_procedimento();
    }

    return 0;
}