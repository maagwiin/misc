#include <stdio.h>
#define TAM 3
int vez;

int menu();
void limpa();
void zera(int tab[][TAM]);
void mostra(int tab[][TAM]);
void jogar(int tab[][TAM]);
int checaJ(int tab[][TAM], int lin, int col);
int checaL(int tab[][TAM]);
int checaC(int tab[][TAM]);
int checaD(int tab[][TAM]);
int checaV(int tab[][TAM], int vez);
int checaF(int tab[][TAM], int vez);
void jogada(int tab[][TAM]);


int main(){
	int tab[TAM][TAM], continuar;
	limpa();
	zera(tab);
	do{
		vez = 1;
		continuar = menu();
		if(continuar == 1){
			jogar(tab);
		}
	}while(continuar);
	return 0;
}


int menu(){
	int opcao;
	printf("\tJogo da velha\n");
	printf("Selecione a opção:\n");
	printf("1-Jogar\n");
	printf("0-Sair\n");
	scanf("%d", &opcao);
	switch(opcao){
		case 1:
			limpa();
		case 0:
			break;
		default:
			limpa();
			printf("Opção inválida, tente novamente\n\n");
	}
	return opcao;
}

void limpa(){
	int count=0;
	while(count!=100){
		printf("\n");
		count++;
	}
}

void zera(int tab[][TAM]){
	int lin, col;
	for(lin=0; lin<TAM; lin++){
		for(col=0; col<TAM; col++){
			tab[lin][col]=0;
		}
	}
}

void mostra(int tab[][TAM]){
	int lin, col;
	limpa();
	printf("\n");
	for(lin = 0; lin < TAM; lin++){
		for(col = 0; col < TAM; col++){
			if(tab[lin][col]==0){
				printf("   ");
			}
			else{
				if(tab[lin][col]==1){
					printf(" X ");
				}
				else{
					printf(" O ");
				}
			}
			if(col != TAM-1){
				printf("|");
			}
		}
		printf("\n");
	}
	printf("\n");
}
void jogar(int tab[][TAM]){
	limpa();
	zera(tab);
	do{
		mostra(tab);
		jogada(tab);
	}while(checaF(tab, vez) != 1);
}

int checaJ(int tab[][TAM], int lin, int col){
	if(lin<0 || lin > (TAM-1) || col < 0 || col > (TAM-1) || tab[lin][col] != 0){
		return 1;
	}
	else{
		return 0;
	}
}

int checaLinha(int tabuleiro[][DIM])
{
    int linha, coluna,
        soma;
 
    for(linha = 0 ; linha < DIM ; linha++)
    {
        soma=0;
 
        for(coluna = 0 ; coluna < DIM ; coluna++)
            soma += tabuleiro[linha][coluna];
 
        if(soma==DIM || soma == (-1)*DIM)
            return 1;
    }
 
    return 0;
}
 
int checaColuna(int tabuleiro[][DIM])
{
    int linha, coluna,
        soma;
 
 
    for(coluna = 0 ; coluna < DIM ; coluna++)
    {
        soma=0;
 
        for(linha = 0 ; linha < DIM ; linha++)
            soma += tabuleiro[linha][coluna];
 
        if(soma==DIM || soma == (-1)*DIM)
            return 1;
    }
 
    return 0;
}
 
int checaDiagonal(int tabuleiro[][DIM])
{
    int linha,
        diagonal_principal=0,
        diagonal_secundaria=0;
 
    for(linha = 0 ; linha < DIM ; linha++)
    {
        diagonal_principal += tabuleiro[linha][linha];
        diagonal_secundaria += tabuleiro[linha][DIM-linha-1];
    }
 
    if(diagonal_principal==DIM || diagonal_principal==(-1)*DIM ||
       diagonal_secundaria==DIM || diagonal_secundaria==(-1)*DIM)
       return 1;
 
    return 0;
}
 
int checaEmpate(int tabuleiro[][DIM])
{
    int linha, coluna;
 
    for(linha = 0 ; linha < DIM ; linha++)
        for(coluna = 0 ; coluna < DIM ; coluna++)
            if(tabuleiro[linha][coluna] == 0)
                return 0;
 
    return 1;
}
 
int checaTermino(int tabuleiro[][DIM], int vez)
{
    if(checaLinha(tabuleiro))
    {
        printf("Jogo encerrado. Jogador %d venceu !\n\n", (vez%2)+1);
        exibeTabuleiro(tabuleiro);
        return 1;
    }
 
    if(checaColuna(tabuleiro))
    {
        printf("Jogo encerrado. Jogador %d venceu !\n\n", (vez%2)+1);
        exibeTabuleiro(tabuleiro);
        return 1;
    }
 
    if(checaDiagonal(tabuleiro))
    {
        printf("Jogo encerrado. Jogador %d venceu !\n\n", (vez%2)+1);
        exibeTabuleiro(tabuleiro);
        return 1;
    }
 
    if(checaEmpate(tabuleiro))
    {
        printf("Jogo encerrado. Ocorreu um empate! !\n\n");
        exibeTabuleiro(tabuleiro);
        return 1;
    }
 
    return 0;
}


void jogada(int tab[][TAM]){
	int lin, col;
	vez++;

	do{
		printf("Linha: ");
		scanf("%d", &lin);
		lin--;

		printf("Coluna: ");
		scanf("%d", &col);
		col--;

		if(checaJ(tab, lin, col) != 0){
			printf("Opção inválida, tente novamente\n");
		}
	}while(checaJ(tab, lin, col) != 0);

	if(vez%2){
		tab[lin][col]= -1;
	}
	else{
		tab[lin][col]= 1;
	}
}