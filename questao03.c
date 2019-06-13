#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


// fun��o que ir� ser usada para gerar os valores
void * function (void *arg) {
    int *valor = (int *)(arg); //transforma em int o argumento passado (tamanho de 1000 em 1000)
	int i, j;
	int cont = 0; //contador que ser� diferente de 0 se o n�mero n�o for primo

	for(i = (*valor - 1000); i <= *valor; i++){
        for(j = 2; j < i; j++){   //percorre todos os valores de 2 at� antes de chegar no n�mero que estamos testando se � primo
            if(i % j == 0)  //teste para primo
                cont += 1;  //se n�o for primo, o contador n�o ser� mais o zero
        }
        if(cont == 0){
            printf("%i ", i);  //imprime apenas se for primo. Sabemos se � ou n�o primo pelo contador
        }
        cont = 0; //zera o contador para iniciar um novo ciclo de testes
	}
}

int main () {
    int tam = 100;  //usado para definir a quantidade de threads
	pthread_t t[tam];
	int i;
	int a[100]; //guardar todos os argumentos

	for(i = 0; i < 100; i++){ //define todos os argumentos, com valores de 1000 em 1000
        a[i] = (i + 1) * 1000;
	}

	for(i = 0; i < tam; i++){
        pthread_create(&t[i], NULL, function, (void *)(&a[i]));
	}

	for(i = 0; i < tam; i++){
        pthread_join(t[i], NULL);
	}

	exit(0);
}
