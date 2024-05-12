/*
faca um programa que se possa definir relacoes correlatas como
a investigacao de seus tipos, calculo da composicao de relacoes, etc.
Assim, construa um pequeno sistema em qualquer linguagem de programacao capaz de:
- definir ate 6 conjuntos com ate 5 elemntos cada;
- definir ate 5 relacoes como matrizes sobre estes conjuntos;
- verificar os tipos de uma relacao
- calcular a relacao dual(e permitir verificar o tipo da relacao dual);
- calcular(e armazenar) a composicao de duas relacoes e permitir todas as acoes acima
sobre a relacao resultante.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> 

#define N_conjuntos 6
#define N_elementos 5

int r_funcional(int n_elem, int **mat) {
    int i, j, count;
    for (i = 0; i < n_elem; i++) {
        count = 0; // Inicializa o contador para cada linha
        for (j = 0; j < n_elem; j++) {
            if (mat[i][j] == 1) {
                count++;
            }
        }
        if (count != 1) {
            printf("Nao e uma Relacao Funcional\n\n");
            return 0; // Se uma linha nao tem exatamente um "1", a matriz nao eh funcional
        }
    }
    printf("E uma Relacao Funcional\n\n");
    return 1; // Se todas as linhas tiverem exatamente um "1", a matriz eh funcional
}

int r_injetora(int n_elem, int **mat) {
    int i, j, count;
    for (i = 0; i < n_elem; i++) {        
        for (j = 0; j < n_elem; j++) {
			count = 0; // Inicializa o contador para cada coluna
            if (mat[i][j] == 1) {
                count++;
            }
        }
        if (count != 1) {
            printf("Nao e uma Relacao Injetora\n\n");
            return 0; // Se uma linha n�o tem exatamente um "1", a matriz nao eh Injetora
        }
    }
    printf("E uma Relacao Injetora\n\n");
    return 1; // Se todas as linhas tiverem exatamente um "1", a matriz eh Injetora
}

int r_total(int n_elem, int **mat){
	int i, j, LinhaNula = 0;
	
	for (i = 0; i < n_elem; i++) {   
		LinhaNula = 1;
        for (j = 0; j < n_elem; j++) {
        	if (mat[i][j] != 0) {
                LinhaNula = 0;//A LINHA N�O � NULA
            }
        }
        if(LinhaNula == 1){
        	printf("A matriz nao e Total\n\n");
        	return 0;
		}
    }
    printf("A matriz e Total\n\n");
    return 1;
}

int r_sobrejetora(int n_elem, int **mat){
	int i, j, ColunaNula = 0;
	
	for (j = 0; j < n_elem; j++) {   
		ColunaNula = 1;
        for (i = 0; i < n_elem; i++) {
        	if (mat[i][j] != 0) {
                ColunaNula = 0;//A LINHA N�O � NULA
            }
        }
        if(ColunaNula == 1){
        	printf("A matriz nao e Sobrejetora\n\n");
        	return 0;
		}
    }
    printf("A matriz e Sobrejetora\n\n");
    return 1;
}

int Monorelacao_Epirelacao(int Funcional, int Injetora, int Total, int Sobrejetora){
	int Monomorfismo = 0, Epimorfismo = 0;
	if(Total == 1 && Injetora == 1){
		Monomorfismo = 1;
	}
	if(Funcional == 1 && Sobrejetora == 1){
		Epimorfismo = 1;
	}
	
	int Isomorfismo = 0;
	
	if(Epimorfismo == 1 && Monomorfismo == 1){
		Isomorfismo = 1;
	}
	
	//IMPRESSAO DO RELATORIO
	if(Monomorfismo == 1){
		printf("A matriz faz Monorelacao (Total e Injetora)!\n\n");
	}else{
		printf("A matriz nao faz Monorelacao (nao e Total e Injetora ao mesmo tempo)!\n\n");
	}
	if(Epimorfismo == 1){
		printf("A matriz faz Epirelacao (Funcional e Sobrejetora)!\n\n");
	}else{
		printf("A matriz nao faz Epirelacao (nao e Funcional e Sobrejetora ao mesmo tempo)!\n\n");
	}
	if(Isomorfismo == 1){
		printf("A matriz e Isomorfismo (Monorelacao e Epirelacao)!\n\n");
	}else{
		printf("A matriz nao e Isomorfismo (nao e Monorelacao e Epirelacao ao mesmo tempo)!\n\n");
	}
	
	return 1;
}

void imprime_matriz(int n_elem, int **mat) {
    int i, j;
    printf("Matriz Relacao:\n");
    for (i = 0; i < n_elem; i++) {
        for (j = 0; j < n_elem; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n\n");
    }
}

int main() {
    int n_elem, n_conj;	
    int op;	
	
    do {		
        printf("====== MENU ======\n");
        printf("1 - Manual\n");
        printf("2 - Automatico (DESATIVADO)\n");
        printf("3 - Sair\n");
        printf("==================\n");
        printf("Escolha uma opcao: ");
        scanf("%d",&op);
        system("cls");
		
        switch(op) {
            case 1:
                printf("Insira a quantidade de conjuntos (maximo 6): ");
                scanf("%d", &n_conj);
                
                printf("Insira a quantidade de elementos de cada conjunto (maximo 5): ");
                scanf("%d", &n_elem);
                system("cls");
                
                int **conjuntos = (int **)malloc(n_conj * sizeof(int *));
                int i, j, resp;
                
                for (i = 0; i < n_conj; i++) {
                    conjuntos[i] = (int *)malloc(n_elem * sizeof(int));
                    printf("Digite os valores do conjunto %c: \n", i + 'A');
                    for (j = 0; j < n_elem; j++) {
                        printf("Elemento %d: ", j);
                        scanf("%d", &conjuntos[i][j]);
                    }
                    system("cls");
                }
                
                int **mat = (int **)malloc(n_elem * sizeof(int *));
                for (i = 0; i < n_elem; i++) {
                    mat[i] = (int *)malloc(n_elem * sizeof(int));
                }
                
                for (i = 0; i < n_elem; i++) {
                    for (j = 0; j < n_elem; j++) {
                        printf("O elemento %d faz relacao com elemento %d? (0 - nao, 1 - sim): ", conjuntos[0][i], conjuntos[1][j]);
                        scanf("%d", &resp);
                        mat[i][j] = resp;
                    }
                    system("cls");
                }
                
                // Exemplo de como voce pode acessar os elementos dos conjuntos
                printf("\nConjuntos inseridos:\n");
                for (i = 0; i < n_conj; i++) {
                    printf("Conjunto %c: ", i+65);
                    printf("{");
                    for (j = 0; j < n_elem; j++) {
                    printf("%d ", conjuntos[i][j]);
                    }
                    printf("}");
                    printf("\n\n");
                }   
                /*
                // Gerando os pares ordenados e armazenando na matriz        
                for (i = 0; i < n_conj; i++) {
                    printf("R: %c = ",i+65);
                    
                    for (j = 0; j < n_elem; j++) {
                        if(i != j){
                            printf("{%d, %d} ", conjuntos[i][j], i + 1);
                        }
                    }
                    printf("\n");
                }
                */
                
                int Funcional = 0, Injetora = 0, Total = 0, Sobrejetora = 0;
                
                imprime_matriz(n_elem, mat);
                Funcional = r_funcional(n_elem, mat);
                Injetora = r_injetora(n_elem, mat);
                Total = r_total(n_elem, mat);
                Sobrejetora = r_sobrejetora(n_elem, mat);
                
                Monorelacao_Epirelacao(Funcional, Injetora, Total, Sobrejetora);
                
                // Liberando a memoria alocada
                for (i = 0; i < n_conj; i++) {
                    free(conjuntos[i]);
                }
                free(conjuntos);
                
                for (i = 0; i < n_elem; i++) {
                    free(mat[i]);
                }
                free(mat);
                
                printf("\n\n");
            break;
            case 2:
    			
            break;
            case 3:
                printf("Saindo.....\n");
                sleep(1); // Aguarda 1 segundo antes de sair
                return 0; // Retorna 0 para sair do programa
            break;
            default:
                printf("opcao invalida, tente novamente!\n\n");
                system("pause");
                system("cls");
        }
        
    } while(op != 3);
    
    return 0;
}

