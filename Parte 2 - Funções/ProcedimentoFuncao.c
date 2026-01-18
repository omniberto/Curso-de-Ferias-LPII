#include <stdio.h>
#include <stdlib.h>

void printfmod_procedimento(){
    printf("Esse e um procedimento\nAqui nada e retornado.\n");
}

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