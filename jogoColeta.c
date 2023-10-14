#include<stdio.h>

void gm(int li, int col, char mat[][10], int *posPointsY, int *posPointsX){
	int l,j,pointsY=0,pointsX=0;
	
	pointsY = rand() % 9;
	pointsX = rand() % 9;

	if(pointsX > 9)
		pointsX = 8;
	if(pointsY > 9)
		pointsY = 8;

	for(l=0;l<li;l++){
		for(j=0;j<col;j++){
			mat[l][j] = '.';
			mat[pointsY][pointsX] = 'o';
		}
	}
	
	*posPointsY = pointsY;
	*posPointsX = pointsX;
}

void pm(int li, int col, char mat[][10]){
	int l, j;
	
	printf("\n");
	for(l=0;l<li;l++){
		printf("\t");
		for(j=0;j<col;j++){
			printf(" %c ",mat[l][j]);
		}
		printf("\n");
	}
}

int main(void){
	int lin=10, col=10,r=2,posX=0,posY=0,antX,antY,pointsX=0,pointsY=0,coins=10;
	char mat[10][10];
	char inp;//variável de controlhe
	
	srand(time(NULL));
	
	gm(lin,col,mat,&pointsY,&pointsX);
	pm(lin,col,mat);
	
	while(r==2){
	printf("\n\t\t COINS LEFT: %d\n",coins);
	printf("\t\tINPUT a w s or d\n");
	
	inp = _getch();//leitura do teclado
	
	if(inp == 'w'){ 
		posY--;
	}else if(inp == 's'){
		posY++;
	}else if(inp == 'a'){
		posX--;
	}else if(inp == 'd'){
		posX++;
	}
	
	if(posX < 0){
		posX = 0;	
	}else if(posX > 9){
		posX = 9;
	}
	
	if(posY < 0){
		posY = 0;
	}else if(posY > 9){
		posY = 9;
	}
	
	mat[posY][posX] = 'X';
	
	antY = posY;
	antX = posX; 
	
	system("cls");
	
	pm(lin,col,mat);
	
	mat[antY][antX] = '.';
	
	
	//Coleta de coins e geração
	if(posY == pointsY && posX == pointsX){
		gm(lin,col,mat,&pointsY,&pointsX);
		coins--;
	}
	//Vitória
	if(coins == 0){
		r = 0;
	}
}
	printf("\n\t\t** You Win **");
	
	getchar();//pause
	return 0;
}
