#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//ARIS SOUZA DO CANTO 23/04/2021 11:51
//ALGORITMOS E ESTRUTURAS DE DADOS I - CAMPO MINADO
void n_bombasA(int n, char matriz[][n]){
	for (int lin = 1; lin <= n; lin++){
		for (int col = 1; col <= n; col++){
			matriz[lin][col] = '?';
		}
	} 
}
void n_bombasB(int l,int c, int n,char M[][n]){
	for (int lin = 1; lin <= l; lin++){
		for (int col = 1; col <= c; col++){
			M[lin][col] = '?';
		}
	}
	int cont_minas = 0.2 * (n*n);
	while (cont_minas > 0){
		int lin = rand() % n + 1;
		int col = rand() % n + 1 ;
		if (M[col][lin] == '*'){
			continue;
		}
		M[col][lin] = '*';
		--cont_minas;
	}
}
void exibe_mat(int  n,char M[][n]){
	printf("\n");
	for (int lin = 1; lin <= n; lin++){
		if(lin < 10){
			printf(" %d |", lin);
		}else{
			printf(" %d|", lin);
		}
		for (int col = 1; col <= n; col++){
			printf("%c  ", M[lin][col]);
		}
		printf("\n");
	}
	printf("   ");
	for(int i = 0; i < n; i++){
		printf("---");
	}
	printf("\n    ");
	for(int i = 0; i < n; i++){
		printf("%d  ", i+1);
	}
	printf("\n");
}
void mapa_vitoria(int tamanho,char mapa[][tamanho], char bomba_matriz[][tamanho]){
	printf("\n");
	for (int lin = 1; lin <= tamanho; lin++){
		if(lin < 10){
			printf(" %d |", lin);
		}else{
			printf(" %d|", lin);
		}
		for (int col = 1; col <= tamanho; col++){
			if(bomba_matriz[lin][col] == '?' && mapa[lin][col] != '?'){
				printf("%c  ",mapa[lin][col]);
			}else{
				if(mapa[lin][col] == '?' && bomba_matriz[lin][col] != '*'){
					bomba_matriz[lin][col] = '1';
					printf("%c  ",bomba_matriz[lin][col]);
				}else{
					printf("%c  ",bomba_matriz[lin][col]);
				}
			}
		}
		printf("\n");
	}
	printf("   ");
	for(int i = 0; i < tamanho; i++){
		printf("---");
	}
	printf("\n    ");
	for(int i = 0; i < tamanho; i++){
		printf("%d  ", i+1);
	}
	printf("\n");
}
void mapa_derrota(int tamanho,char mapa[][tamanho],char bomba_matriz[][tamanho]){
	printf("\n");
	for (int lin = 1; lin <= tamanho; lin++){
		if(lin < 10){
			printf(" %d |", lin);
		}else{
			printf(" %d|", lin);
		}
		for (int col = 1; col <= tamanho; col++){
			if(mapa[lin][col] == '?' && bomba_matriz[lin][col] != '*'){
				printf("%c  ",mapa[lin][col]);
			}else{
				if(bomba_matriz[lin][col] == '*' && mapa[lin][col] == '?'){
					printf("%c  ", bomba_matriz[lin][col]);
				}else{
					printf("%c  ",mapa[lin][col]);
				}
			}
		}
		printf("\n");
	}
	printf("   ");
	for(int i = 0; i < tamanho; i++){
		printf("---");
	}
	printf("\n    ");
	for(int i = 0; i < tamanho; i++){
		printf("%d  ", i+1);
	}
	printf("\n");
}
void atualiza_mapa(int tamanho,char mapa_matriz[][tamanho], char bomba_matriz[][tamanho], int linha, int coluna){
	int cont = 0;
	if (linha - 1 >= 0 && coluna - 1 >= 0 && bomba_matriz[linha - 1][coluna - 1] == '*'){ 
		cont++;
	}else if (linha - 1 >= 0 && bomba_matriz[linha - 1][coluna] == '*'){
		cont++;
	}else if (linha - 1 >= 0 && coluna + 1 < tamanho &&bomba_matriz[linha - 1][coluna + 1] == '*'){
		cont++;
	}else if (coluna - 1 >= 0 && bomba_matriz[linha][coluna - 1] == '*'){
		cont++;
  }else if (coluna + 1 < tamanho && bomba_matriz[linha][coluna + 1] == '*'){
		cont++;
	}else if (linha + 1 < tamanho && coluna - 1 >= 0 && bomba_matriz[linha + 1][coluna - 1] == '*'){
		cont++;
	}else if (linha + 1 < tamanho && bomba_matriz[linha + 1][coluna] == '*'){
		cont++;
	}else if (linha + 1 < tamanho && coluna + 1 < tamanho && bomba_matriz[linha + 1][coluna + 1] == '*'){
		cont++;
	}
	mapa_matriz[linha][coluna] = cont + '0';
}
int main(){
	printf("------------------------------------------------------------\n");
	printf("              UNIVERSIDADE FEDERAL DO AMAZONAS              \n");
	printf("        DISCIPLINA: ALGORITMOS E ESTRUTURAS DE DADOS I      \n");
	printf("                                                            \n");
	printf("                          1.JOGAR                           \n");
	printf("                          0.SAIR                            \n");
	printf("                                                            \n");
	printf("                    ALUNO: ARIS SOUZA                       \n");
	printf("------------------------------------------------------------\n");
	printf("Entre com a opcao desejada: ");
	int opcao;
	scanf("%d", &opcao);
	if(opcao == 1){
		int tamanho = 0;
		printf("Digite o tamanho da matriz desejada: ");
		scanf("%d",&tamanho);
		srand((unsigned int)time(NULL));
		char mapa_matriz[tamanho][tamanho];
		char bomba_matriz[tamanho][tamanho];
		int cont_minas;
		int l = tamanho;
		int c = tamanho;
		n_bombasA(tamanho,mapa_matriz);
		n_bombasB(l,c,tamanho, bomba_matriz); 
		int compara = 0;
		while (1){
			printf("\n");
			exibe_mat(tamanho,mapa_matriz);
			printf(" Digite a linha e coluna desejada: ");
			int linha = 1 ;
			int coluna = 1;
			scanf("%d %d",&linha,&coluna);
			if (linha <= 0 || linha > tamanho || coluna <= 0 || coluna > tamanho ){
				printf(" Entrada invalida \n");
				continue;
			}
			if (mapa_matriz[linha][coluna] != '?'){
				printf(" Esta posicao ja foi virada! \n");
				continue;
			}
			if (bomba_matriz[linha][coluna] == '*'){
				printf("VOCE PERDEU! FIM DE JOGO !\n");
				mapa_derrota(tamanho,mapa_matriz,bomba_matriz);
				break;
			}
			compara++;
			cont_minas = 0.2 * (tamanho*tamanho);
			if (compara == tamanho * tamanho - cont_minas){
				printf("PARABENS! VOCE VENCEU!\n");
				mapa_vitoria(tamanho,bomba_matriz,mapa_matriz);
				break;
			}
			atualiza_mapa(tamanho,mapa_matriz, bomba_matriz, linha, coluna);
		}
	}
	else if(opcao == 0){
		printf("VOCE SAIU DO JOGO\n");
	}
	else{
		printf("ENTRADA INVALIDA, ENTRE COM 1 OU 0! \n");
	}
	return 0;
}
