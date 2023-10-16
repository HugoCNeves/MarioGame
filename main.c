#include <stdio.h>
#include <conio.h>

char g[20][300], test, esc, dir_g01 = 'l';
int i,j,k = 0, tecla, tecla_pulo,x = 16,y = 25, x2 = 11, y2 = 60, y3, y3_1, y3_2, y3_3, y3_4, y3_5, y_cano1, x_cano1, y_cano2, x_cano2, 
	y_cano3, x_cano3, y_cano4, x_cano4, y_cano5, x_cano5, x3, pare = 0, jump, parar_att, parar_bloco_y3, parar_bloco_y3_1, parar_bloco_y3_2, parar_bloco_y3_3,
	parar_bloco_y3_4, colisaof = 0, colisaot = 0, y_limite, y_limite2, y_goomba_01 = 90, x_goomba_01 = 18, mov_g01, colisao_tg_01, colisao_fg_01,
	stop_g01, end;

void mapa(){
	
for (i = 0; i <= 19 ; i++){
	for (j = 0; j <= 59; j++){
		printf ("%c", g[i][j]);
		k +=1;
		if (k % 60 == 0){
			printf("\n");
		}
	}
}
}
void tela(){
for (i = 0; i <= 0 ; i++){
	for (j = 0; j <= 59; j++){
		g[i][j] = '_';
	}
}
for (i = 19; i <= 19 ; i++){
	for (j = 0; j <= 59; j++){
		g[i][j] = '"';
	}
}
for (i = 1; i <= 19 ; i++){
	for (j = 0; j <= 0; j++){
		g[i][j] = '|';
	}
}
for (i = 1; i <= 19 ; i++){
	for (j = 59; j <= 59; j++){
		g[i][j] = '|';
	}
}	
		
for (i = 1; i <= 18 ; i++){
	for (j = 1; j <= 58; j++){
		g[i][j] = ' ';
	}
}	
}
void limpar_pers(){
	g[x][y] = ' ';
	g [x+1][y] = ' ';
	g [x+1][y-1] = ' ';
	g [x+1][y+1] = ' ';
	g [x+2][y] = ' ';
	g[x][y+1] = ' ';
}
void colisao_bloco_cima(){
	if ((g[x-1][y+2] == '-' && g[x-1][y-1] == '-') || (g[x-1][y-1] == '-' && (g[x-2][y-1] == '=' || g[x-2][y-1] == '?')) || g[x-1][y+2] == '?' || (g[x-1][y+1] != '-' && g[x-2][y-2] == '?') || g[x-1][y-1] == '_' || g[x-1][y+1] == '_'){
	}
	else if (g[x-2][y+1] == '?'){
	g[x-2][y+1] = ' ';
	}
	else if (g[x-2][y] == '?'){
	g[x-2][y] = ' ';
	}
	else{
	if(g[x-2][y+1] != '|'){
	g[x-2][y+1] = ' ';
	}
	g[x-2][y] = ' ';
	
	if (g[x-1][y+3] != '-'){
	g[x-2][y+2] = ' ';
	}
	g[x-1][y+1] = ' ';
	g[x-3][y+1] = ' ';
}
	if (y+1 == y3){
		parar_bloco_y3 = 1;
	}
	if (y == y3_1 || (y+2 == y3_1 && g[x-2][y-1] != '=')){
		parar_bloco_y3_1 = 1;
	}
	if (y+1 == y3_2 && (g[x+4][y] != '-' && g[x+4][y-1] != '-' && g[x+4][y+1] != '-')){
		parar_bloco_y3_2 = 1;
	}
	if (y == y3_3 || (y+2 == y3_3 && g[x-2][y-1] != '=') && (g[x+4][y] == '-' && g[x+4][y-1] == '-' && g[x+4][y+1] == '-')){
		parar_bloco_y3_3 = 1;
	}
	if (y+1 == y3_4){
		parar_bloco_y3_4 = 1;
	}
}
void rebocar_margens(){
	g[0][25] = '_';
	g[0][26] = '_';
	g[0][24] = '_';
	for (i = 1; i <= 19 ; i++){
	for (j = 59; j <= 59; j++){
		g[i][j] = '|';
	}
}
	for (i = 1; i <= 19 ; i++){
	for (j = 0; j <= 0; j++){
		g[i][j] = '|';
	}
}
}
void pular(){
	for (jump = 0; jump <= 8; jump++){
		if (g[x-1][y+1] == '-' || g[x-1][y-1] == '-' || g[x-1][y] == '-' || g[x-1][y+2] == '-' || g [x-1][y-2] == '-' || g[x-1][y-1] == '_' || g[x-1][y+1] == '_'){
		colisao_bloco_cima();
		break;
	}
	x -= 1;
	g[x][y] = 'O';
	g[x+1][y] = '|';
	g [x+1][y-1] = '-';
	g [x][y+1] = '|';
	g [x+2][y] = '^';
	system ("cls");
	rebocar_margens();
	mapa();
	limpar_pers();
	g[x][y+1] = ' ';
	if (kbhit()){
		tecla_pulo = getch();
		if (tecla_pulo == 75){
			colisao_tras();
		if(colisaot == 1){
		continue;
	}
		y2 += 2;
		system("cls");
		obj_1();
		obj_2();
		canos();		
		mapa();	
	}
		if (tecla_pulo == 77){
			colisao_frente();
		if (colisaof == 1){
		continue;
	}
		y2 -= 2;
		system("cls");
		obj_1();
		obj_2();
		canos();		
		mapa();
	}
	}
	goomba_01();
	limite_mapa();
	if (g[x-1][y+1] == '-' || g[x-1][y-1] == '-' || g[x-1][y] == '-' || g[x-1][y+2] == '-' || g [x-1][y-2] == '-' || g[x-1][y-1] == '_'|| g[x-1][y+1] == '_'){
		colisao_bloco_cima();
		break;
	}
}
}
void obj_1(){
	if (y2 > 59 || g[x2][y2+2] == '?' || g[x2][y2-2] == '?'){
	g[x2][y2+2] = ' ';
	g[x2][y2-2] = ' ';
	test = '?';
	rebocar_margens();
	g[x2][y2] = test;
}
	g[x2+1][y2+2] = ' ';
	g[x2+1][y2-2] = ' ';
	g[x2+1][y2] = '-';
	rebocar_margens();
		
	g[x2-1][y2+2] = ' ';
	g[x2-1][y2-2] = ' ';
	g[x2-1][y2] = '-';
	rebocar_margens();
		
	g[x2][y2+1] = ' ';
	g[x2][y2-3] = ' ';
	g[x2][y2-1] = '|';
		
	g[x2][y2+3] = ' ';
	g[x2][y2+1] = '|';


}
void obj_2(){
	y3 = y2 + 10;
	y3_1 = y3 + 3;
	y3_2 = y3 + 6;
	y3_3 = y3 + 9;
	y3_4 = y3 + 12;
	x3 = x2 - 7;
	
	/*BLOCO 1*/
	
	if (parar_bloco_y3 == 0){
	g[x2][y3-2] = ' ';
	g[x2][y3+2] = ' ';
    g[x2][y3] = '=';
	
	g[x2+1][y3+2] = ' ';
	g[x2+1][y3-2] = ' ';
	g[x2+1][y3] = '-';		

	g[x2-1][y3+2] = ' ';
	g[x2-1][y3-2] = ' ';
	g[x2-1][y3] = '-';		

	g[x2][y3+3] = ' ';
	g[x2][y3-3] = ' ';
	g[x2][y3-1] = '|';

	g[x2][y3+1] = '|';
	}
	
	/*BLOCO 2*/

	if (parar_bloco_y3_1 == 0){
	if (g[x2][y3_1-2] != '|'){
		g[x2][y3_1-2] = ' ';
	}
	g[x2][y3_1+2] = ' ';
	g[x2][y3_1] = '?';
	}
	
	g[x2+1][y3_1-2] = ' ';
	g[x2+1][y3_1+2] = ' ';
	g[x2+1][y3_1] = '-';
		
	
	g[x2-1][y3_1+2] = ' ';
	g[x2-1][y3_1-2] = ' ';
	g[x2-1][y3_1] = '-';
		
	if (g[x2][y3_1-3] != '='){
		g[x2][y3_1-3] = ' ';
	}
	g[x2][y3_1-1] = '|';
	
	g[x2][y3_1+3] = ' ';
	g[x2][y3_1+1] = '|';
	
	/*BLOCO 3*/
	
	if (parar_bloco_y3_2 == 0){
	g[x2][y3_2+2] = ' ';
	g[x2][y3_2] = '=';

	g[x2+1][y3_2+2] = ' ';
	g[x2+1][y3_2-2] = ' ';
	g[x2+1][y3_2] = '-';

	g[x2-1][y3_2+2] = ' ';
	g[x2-1][y3_2-2] = ' ';
	g[x2-1][y3_2] = '-';

	if (g[x2][y3_2-3] != '?'){
		g[x2][y3_2-3] = ' ';
	}
	g[x2][y3_2+1] = ' ';
	g[x2][y3_2-1] = '|';

	g[x2][y3_2+3] = ' ';
	g[x2][y3_2+1] = '|';
	}
	
	/*BLOCO 4*/
	
	if (parar_bloco_y3_3 == 0){
	if (g[x2][y3_3-2] != '|'){
		g[x2][y3_3-2] = ' ';
	}
	g[x2][y3_3+2] = ' ';
	g[x2][y3_3] = '?';
	}
	g[x2+1][y3_3+2] = ' ';
	g[x2+1][y3_3-2] = ' ';
	g[x2+1][y3_3] = '-';
		
	g[x2-1][y3_3+2] = ' ';	
	g[x2-1][y3_3-2] = ' ';	
	g[x2-1][y3_3] = '-';

	g[x2][y3_3-1] = '|';


	g[x2][y3_3+3] = ' ';
	g[x2][y3_3+1] = '|';
	
	/*BLOCO 5*/
	
	if (parar_bloco_y3_4 == 0){
	g[x2][y3_4+2] = ' ';
	g[x2][y3_4] = '=';
	
	g[x2+1][y3_4-2] = ' ';
	g[x2+1][y3_4+2] = ' ';
	g[x2+1][y3_4] = '-';
	
	g[x2-1][y3_4-2] = ' ';	
	g[x2-1][y3_4+2] = ' ';
	g[x2-1][y3_4] = '-';
		
	if (g[x2][y3_4-3] != '?'){
		g[x2][y3_4-3] = ' ';
	}
	g[x2][y3_4+1] = ' ';
	g[x2][y3_4-1] = '|';
		
	g[x2][y3_4+3] = ' ';
	g[x2][y3_4+1] = '|';
	}
	
	/*BLOCO 6 (Em cima)*/
	
	if (y3 < 1 || y3_2 > 59 || g[x3][y3_2+2] == '?' || g[x3][y3_2-2] == '?'){
	g[x3][y3_2+2] = ' ';
	g[x3][y3_2-2] = ' ';
	test = '?';
	rebocar_margens();
	g[x3][y3_2] = test;
}
	g[x3+1][y3_2+2] = ' ';
	g[x3+1][y3_2-2] = ' ';
	g[x3+1][y3_2] = '-';
	rebocar_margens();
		
	g[x3-1][y3_2+2] = ' ';
	g[x3-1][y3_2-2] = ' ';
	g[x3-1][y3_2] = '-';
	rebocar_margens();
		
	g[x3][y3_2+1] = ' ';
	g[x3][y3_2-3] = ' ';
	g[x3][y3_2-1] = '|';
	rebocar_margens();
		
	g[x3][y3_2+3] = ' ';
	g[x3][y3_2+1] = '|';
	rebocar_margens();
}
void cair(){
	while ((g[x+3][y] == ' ' && g[x+3][y-1] == ' ' && g[x+3][y+1] == ' ') || x < 0){
	limpar_pers();
	x += 1;
	g[x][y] = 'O';
	g[x+1][y] = '|';
	g [x+1][y-1] = '-';
	g [x][y+1] = '|';
	g [x+2][y] = '^';
	system ("cls");
	rebocar_margens();
	mapa();
	if (kbhit()){
		tecla_pulo = getch();
		if (tecla_pulo == 75){
			colisao_tras();
		if(colisaot == 1){
		continue;
	}
		y2 += 2;
		system("cls");
		obj_1();
		obj_2();
		canos();		
		mapa();	
	}
		if (tecla_pulo == 77){
			colisao_frente();
		if (colisaof == 1){
		continue;
	}
		y2 -= 2;
		system("cls");
		obj_1();
		obj_2();
		canos();		
		mapa();
	}
	}
	goomba_01();
	limite_mapa();
	}
}
void desenhar_pers(){
g [x][y] = 'O';
g [x+1][y] = '|';
g [x+1][y-1] = '-';
g [x+1][y+1] = '-';
g [x+2][y] = '^';	
}
void canos(){
	
	/*CANO 1*/
	
	y_cano1 = y3 + 27;
	x_cano1 = x2 + 7;
	
	g[x_cano1][y_cano1+2] = ' ';
	g[x_cano1-1][y_cano1+2] = ' ';
	g[x_cano1-2][y_cano1+1] = ' ';
	g[x_cano1-2][y_cano1] = ' ';
	for (i = 1; i < 8 ; i ++){
		g[x_cano1-3][y_cano1+i] = ' ';
	}
	g[x_cano1-2][y_cano1+8] = ' ';
	g[x_cano1-2][y_cano1+7] = ' ';
	g[x_cano1-1][y_cano1+6] = ' ';
	g[x_cano1][y_cano1+6] = ' ';
	
	g[x_cano1][y_cano1-2] =  ' ';
	g[x_cano1-1][y_cano1-2] = ' ';
	g[x_cano1-2][y_cano1-3] = ' ';
	g[x_cano1-2][y_cano1-4] = ' ';
	for (i = -3; i < 4 ; i ++){
		g[x_cano1-3][y_cano1+i] = ' ';
	}
	g[x_cano1-2][y_cano1+4] = ' ';
	g[x_cano1-2][y_cano1+3] = ' ';
	g[x_cano1-1][y_cano1+2] = ' ';
	g[x_cano1][y_cano1+2] = ' ';
	
	g[x_cano1][y_cano1] = '|';
	g[x_cano1-1][y_cano1] = '|';
	g[x_cano1-2][y_cano1-1] = '_';
	g[x_cano1-2][y_cano1-2] = '|';
	for (i = -1; i < 6 ; i ++){
		g[x_cano1-3][y_cano1+i] = '_';
	}
	g[x_cano1-2][y_cano1+6] = '|';
	g[x_cano1-2][y_cano1+5] = '_';
	g[x_cano1-1][y_cano1+4] = '|';
	g[x_cano1][y_cano1+4] = '|';
/*
 _______
|_     _|
  |   | 
  |   |*/
  	
	
	/*CANO 2*/
	
	y_cano2 = y_cano1 + 30;
	x_cano2 = x_cano1 - 2;
	
	for (i = -1; i < 3; i++){
		g[x_cano2 + i][y_cano2+2] = ' ';
		g[x_cano2 + i][y_cano2+6] = ' ';
	}
	g[x_cano2-2][y_cano2+1] = ' ';
	g[x_cano2-2][y_cano2] = ' ';
	for (i = 1; i < 8 ; i ++){
		g[x_cano2-3][y_cano2+i] = ' ';
	}
	g[x_cano2-2][y_cano2+8] = ' ';
	g[x_cano2-2][y_cano2+7] = ' ';
	
	for (i = -1; i < 3; i++){
		g[x_cano2 + i][y_cano2-2] = ' ';
		g[x_cano2 + i][y_cano2+2] = ' ';
	}
	g[x_cano2-2][y_cano2-3] = ' ';
	g[x_cano2-2][y_cano2-4] = ' ';
	for (i = -3; i < 4 ; i ++){
		g[x_cano2-3][y_cano2+i] = ' ';
	}
	g[x_cano2-2][y_cano2+4] = ' ';
	g[x_cano2-2][y_cano2+3] = ' ';
	
	for (i = -1; i < 3; i++){
		g[x_cano2 + i][y_cano2] = '|';
		g[x_cano2 + i][y_cano2+4] = '|';
	}
	g[x_cano2-2][y_cano2-1] = '_';
	g[x_cano2-2][y_cano2-2] = '|';
	for (i = -1; i < 6 ; i ++){
		g[x_cano2-3][y_cano2+i] = '_';
	}
	g[x_cano2-2][y_cano2+6] = '|';
	g[x_cano2-2][y_cano2+5] = '_';
	
/*
 _______
|_     _|
  |   | 
  |   |
  |   |
  |   |*/
  
   
    /*CANO 3*/
    
    y_cano3 = y_cano2 + 30;
	x_cano3 = x_cano2 - 2;
	
	for (i = -1; i < 5; i++){
		g[x_cano3 + i][y_cano3+2] = ' ';
		g[x_cano3 + i][y_cano3+6] = ' ';
	}
	g[x_cano3-2][y_cano3+1] = ' ';
	g[x_cano3-2][y_cano3] = ' ';
	for (i = 1; i < 8 ; i ++){
		g[x_cano3-3][y_cano3+i] = ' ';
	}
	g[x_cano3-2][y_cano3+8] = ' ';
	g[x_cano3-2][y_cano3+7] = ' ';
	
	for (i = -1; i < 5; i++){
		g[x_cano3 + i][y_cano3-2] = ' ';
		g[x_cano3 + i][y_cano3+2] = ' ';
	}
	g[x_cano3-2][y_cano3-3] = ' ';
	g[x_cano3-2][y_cano3-4] = ' ';
	for (i = -3; i < 4 ; i ++){
		g[x_cano3-3][y_cano3+i] = ' ';
	}
	g[x_cano3-2][y_cano3+4] = ' ';
	g[x_cano3-2][y_cano3+3] = ' ';
	
	for (i = -1; i < 5; i++){
		g[x_cano3 + i][y_cano3] = '|';
		g[x_cano3 + i][y_cano3+4] = '|';
	}
	g[x_cano3-2][y_cano3-1] = '_';
	g[x_cano3-2][y_cano3-2] = '|';
	for (i = -1; i < 6 ; i ++){
		g[x_cano3-3][y_cano3+i] = '_';
	}
	g[x_cano3-2][y_cano3+6] = '|';
	g[x_cano3-2][y_cano3+5] = '_';
	
/*
 _______
|_     _|
  |   | 
  |   |
  |   |
  |   |
  |   |
  |   |*/
  
  
  		/*CANO 4*/
  		
	y_cano4 = y_cano3 + 30;
	x_cano4 = x_cano3;
	
	for (i = -1; i < 5; i++){
		g[x_cano4 + i][y_cano4+2] = ' ';
		g[x_cano4 + i][y_cano4+6] = ' ';
	}
	g[x_cano4-2][y_cano4+1] = ' ';
	g[x_cano4-2][y_cano4] = ' ';
	for (i = 1; i < 8 ; i ++){
		g[x_cano4-3][y_cano4+i] = ' ';
	}
	g[x_cano4-2][y_cano4+8] = ' ';
	g[x_cano4-2][y_cano4+7] = ' ';
	
	for (i = -1; i < 5; i++){
		g[x_cano4 + i][y_cano4-2] = ' ';
		g[x_cano4 + i][y_cano4+2] = ' ';
	}
	g[x_cano4-2][y_cano4-3] = ' ';
	g[x_cano4-2][y_cano4-4] = ' ';
	for (i = -3; i < 4 ; i ++){
		g[x_cano4-3][y_cano4+i] = ' ';
	}
	g[x_cano4-2][y_cano4+4] = ' ';
	g[x_cano4-2][y_cano4+3] = ' ';
	
	for (i = -1; i < 5; i++){
		g[x_cano4 + i][y_cano4] = '|';
		g[x_cano4 + i][y_cano4+4] = '|';
	}
	g[x_cano4-2][y_cano4-1] = '_';
	g[x_cano4-2][y_cano4-2] = '|';
	for (i = -1; i < 6 ; i ++){
		g[x_cano4-3][y_cano4+i] = '_';
	}
	g[x_cano4-2][y_cano4+6] = '|';
	g[x_cano4-2][y_cano4+5] = '_';
	
/*
 _______
|_     _|
  |   | 
  |   |
  |   |
  |   |
  |   |
  |   |*/
  
   
   /*CANO 5*/
   
   y_cano5 = y_cano4 + 36;
   x_cano5 = x_cano4 + 3;
   
   	for (i = 0; i < 8; i++){
   g[x_cano5][y_cano5-i+2+1] = ' ';
	}
	for (i = 0; i < 8; i++){
   g[x_cano5][y_cano5-i-2+1] = ' ';
	}
	for (i = 0; i < 8; i++){
   g[x_cano5-2][y_cano5-i+2+1] = ' ';
	}
	for (i = 0; i < 8; i++){
   g[x_cano5-2][y_cano5-i-2+1] = ' ';
	}
	for (i = 0; i < 4; i++){
   g[x_cano5-2+i][y_cano5-8] = ' ';
	}
	for (i = 0; i < 4; i++){
   g[x_cano5-2+i][y_cano5-12] = ' ';
	}
	g[x_cano5+1][y_cano5-6] = ' ';
	g[x_cano5+1][y_cano5-7] = ' ';
	g[x_cano5-3][y_cano5-6] = ' ';
	g[x_cano5-3][y_cano5-7] = ' ';
	g[x_cano5+1][y_cano5-5] = ' ';
	g[x_cano5-2][y_cano5-5] = ' ';
	g[x_cano5+1][y_cano5-10] = ' ';
	g[x_cano5+1][y_cano5-11] = ' ';
	g[x_cano5-3][y_cano5-10] = ' ';
	g[x_cano5-3][y_cano5-11] = ' ';
	g[x_cano5+1][y_cano5-9] = ' ';
	g[x_cano5-2][y_cano5-9] = ' ';
	
	for (i = 0; i < 8; i++){
   g[x_cano5][y_cano5-i+1] = '_';
	}
	for (i = 0; i < 8; i++){
   g[x_cano5-2][y_cano5-i+1] = '_';
	}
	for (i = 0; i < 4; i++){
   g[x_cano5-2+i][y_cano5-10] = '|';
	}
	g[x_cano5+1][y_cano5-8] = '_';
	g[x_cano5+1][y_cano5-9] = '_';
	g[x_cano5-3][y_cano5-8] = '_';
	g[x_cano5-3][y_cano5-9] = '_';
	g[x_cano5+1][y_cano5-7] = '|';
	g[x_cano5-2][y_cano5-7] = '|';
   
   
/*
	__
   |  |_______
   |
   |   _______
   |__|
        */
}
void colisao_frente(){
	if ((g[x][y+2] != ' '|| g[x+1][y+2] != ' ' || g[x+2][y+2] != ' ') && x > 3){
		colisaof = 1;
	}
}
void colisao_tras(){
	if ((g[x][y-2] != ' '|| g[x+1][y-2] != ' ' || g[x+2][y-2] != ' ')&& x > 3) {
		colisaot = 1;
	}
}
void limite_mapa(){
	y_limite = y2 - 60;
	if (y2 > 59){
		for (i = 0; i < 18; i++){
		g[1+i][y_limite+1] = ' ';
	}
		for (i = 0; i < 18; i++){
		g[1+i][y_limite-1] = '|';
	}
}
	y_limite2 = y_cano4 + 37;
	if (y_cano4 < 30){
		for (i = 0; i < 18; i++){
		g[1+i][y_limite2-1] = ' ';
	}
		for (i = 0; i < 18; i++){
		g[1+i][y_limite2+1] = '|';
	}
}
	
}
void goomba_01(){
	if (stop_g01 != 1){
	y_cano1 = y3 + 27;
    if (((g[x_goomba_01][y_goomba_01-2] == '|'|| g[x_goomba_01-1][y_goomba_01-2] == '|' || g[x_goomba_01-2][y_goomba_01-2] == '|') && y_goomba_01 < 59) || y_goomba_01 < 2){
		colisao_tg_01 = 1;
		dir_g01 = 'r';
	}
	if ((g[x_goomba_01][y_goomba_01+5] == '|'|| g[x_goomba_01-1][y_goomba_01+5] == '|' || g[x_goomba_01-2][y_goomba_01+5] == '|') && y_goomba_01 < 59){
		colisao_fg_01 = 1;
		dir_g01 = 'l';
	}
	if (dir_g01 == 'l' && (y_goomba_01 > 2 || g[x_goomba_01-2][y_goomba_01+5] != '|')){
		g[x_goomba_01-1][y_goomba_01+1] = ' ';
		g[x_goomba_01-2][y_goomba_01+2] = ' ';
		g[x_goomba_01-2][y_goomba_01+3] = ' ';
		g[x_goomba_01-1][y_goomba_01+4] = ' ';
		g[x_goomba_01-1][y_goomba_01+2] = ' ';
		g[x_goomba_01-1][y_goomba_01+3] = ' ';
		g[x_goomba_01][y_goomba_01+2] = ' ';
		g[x_goomba_01][y_goomba_01+3] = ' ';
	
		g[x_goomba_01-1][y_goomba_01-1] = ' ';
		g[x_goomba_01-2][y_goomba_01] = ' ';
		g[x_goomba_01-2][y_goomba_01+1] = ' ';
		g[x_goomba_01-1][y_goomba_01+2] = ' ';
		g[x_goomba_01-1][y_goomba_01] = ' ';
		g[x_goomba_01-1][y_goomba_01+1] = ' ';
		g[x_goomba_01][y_goomba_01] = ' ';
		g[x_goomba_01][y_goomba_01+1] = ' ';
	
		y_goomba_01 = (y_cano1 -7) - mov_g01;
	
		g[x_goomba_01-1][y_goomba_01-1] = '/';
		g[x_goomba_01-2][y_goomba_01] = '_';
		g[x_goomba_01-2][y_goomba_01+1] = '_';
		g[x_goomba_01-1][y_goomba_01+2] = '\\';
		g[x_goomba_01-1][y_goomba_01] = '*';
		g[x_goomba_01-1][y_goomba_01+1] = '*';
		g[x_goomba_01][y_goomba_01] = '/';
		g[x_goomba_01][y_goomba_01+1] = '\\';

		mov_g01 += 1;
}
	else if (dir_g01 == 'r' && (y_goomba_01 > 2 || g[x_goomba_01-2][y_goomba_01+5] != '|')){
		g[x_goomba_01-1][y_goomba_01] = ' ';
		g[x_goomba_01-2][y_goomba_01+1] = ' ';
		g[x_goomba_01-2][y_goomba_01+2] = ' ';
		g[x_goomba_01-1][y_goomba_01+3] = ' ';
		g[x_goomba_01-1][y_goomba_01+1] = ' ';
		g[x_goomba_01-1][y_goomba_01+2] = ' ';
		g[x_goomba_01][y_goomba_01+1] = ' ';
		g[x_goomba_01][y_goomba_01+2] = ' ';
	
		g[x_goomba_01-1][y_goomba_01+1] = ' ';
		g[x_goomba_01-2][y_goomba_01+2] = ' ';
		g[x_goomba_01-2][y_goomba_01+3] = ' ';
		g[x_goomba_01-1][y_goomba_01+4] = ' ';
		g[x_goomba_01-1][y_goomba_01+2] = ' ';
		g[x_goomba_01-1][y_goomba_01+3] = ' ';
		g[x_goomba_01][y_goomba_01+2] = ' ';
		g[x_goomba_01][y_goomba_01+3] = ' ';
	
		y_goomba_01 = (y_cano1 - 7) - (mov_g01);
	
		g[x_goomba_01-1][y_goomba_01+1] = '/';
		g[x_goomba_01-2][y_goomba_01+2] = '_';
		g[x_goomba_01-2][y_goomba_01+3] = '_';
		g[x_goomba_01-1][y_goomba_01+4] = '\\';
		g[x_goomba_01-1][y_goomba_01+2] = '*';
		g[x_goomba_01-1][y_goomba_01+3] = '*';
		g[x_goomba_01][y_goomba_01+2] = '/';
		g[x_goomba_01][y_goomba_01+3] = '\\';
	
		mov_g01 -= 1;
	}
}
else{
		g[x_goomba_01-1][y_goomba_01] = ' ';
		g[x_goomba_01-2][y_goomba_01+1] = ' ';
		g[x_goomba_01-2][y_goomba_01+2] = ' ';
		g[x_goomba_01-1][y_goomba_01+3] = ' ';
		g[x_goomba_01-1][y_goomba_01+1] = ' ';
		g[x_goomba_01-1][y_goomba_01+2] = ' ';
		g[x_goomba_01][y_goomba_01+1] = ' ';
		g[x_goomba_01][y_goomba_01+2] = ' ';
	
		g[x_goomba_01-1][y_goomba_01-1] = ' ';
		g[x_goomba_01-2][y_goomba_01] = ' ';
		g[x_goomba_01-2][y_goomba_01+1] = ' ';
		g[x_goomba_01-1][y_goomba_01+2] = ' ';
		g[x_goomba_01-1][y_goomba_01] = ' ';
		g[x_goomba_01-1][y_goomba_01+1] = ' ';
		g[x_goomba_01][y_goomba_01] = ' ';
		g[x_goomba_01][y_goomba_01+1] = ' ';
		
		g[x_goomba_01-1][y_goomba_01] = ' ';
		g[x_goomba_01-2][y_goomba_01+1] = ' ';
		g[x_goomba_01-2][y_goomba_01+2] = ' ';
		g[x_goomba_01-1][y_goomba_01+3] = ' ';
		g[x_goomba_01-1][y_goomba_01+1] = ' ';
		g[x_goomba_01-1][y_goomba_01+2] = ' ';
		g[x_goomba_01][y_goomba_01+1] = ' ';
		g[x_goomba_01][y_goomba_01+2] = ' ';
	
		g[x_goomba_01-1][y_goomba_01+1] = ' ';
		g[x_goomba_01-2][y_goomba_01+2] = ' ';
		g[x_goomba_01-2][y_goomba_01+3] = ' ';
		g[x_goomba_01-1][y_goomba_01+4] = ' ';
		g[x_goomba_01-1][y_goomba_01+2] = ' ';
		g[x_goomba_01-1][y_goomba_01+3] = ' ';
		g[x_goomba_01][y_goomba_01+2] = ' ';
		g[x_goomba_01][y_goomba_01+3] = ' ';
}
	if (g[x_goomba_01-3][y_goomba_01+2] == '^' || g[x_goomba_01-3][y_goomba_01+3] == '^' || g[x_goomba_01-2][y_goomba_01] == '^' || g[x_goomba_01-2][y_goomba_01+1] == '^'){
		stop_g01 = 1;
	}
	else if (dir_g01 == 'l'){
		if (g[x_goomba_01-3][y_goomba_01] == '^' || g[x_goomba_01-3][y_goomba_01] == '^'){
			stop_g01 = 1;
		}
	}
	
/* __    
  /**\   
   /\  */	
}
void entrar_cano(){
	if (y_cano5 -12 == y){
	end = 1;
	}
}

int main(){
y_cano4 = 187;
tela();
g [x2][y2] = test;
desenhar_pers();

mapa();
while (x != 200){
if(tecla != 224){
colisaof = 0;
colisaot = 0;
obj_1();
obj_2();
limite_mapa();
goomba_01();
canos();
cair();
limpar_pers();
desenhar_pers();
entrar_cano();
if (end == 1){
	break;
}
system ("cls");
mapa();
}
if (kbhit()){
tecla=getch();
system ("cls");
if (tecla == 77){/*direita*/
	colisao_frente();
	if (colisaof == 1){
		continue;
	}
	y2 -= 2;
}
else if(tecla == 75){/*esquerda*/
	colisao_tras();
	if(colisaot == 1){
		continue;
	}
	y2 += 2;
}
else if(tecla == 72){/*cima*/
	limpar_pers();
	pular();
}
else if (tecla == 224){
	continue;
}
else if (tecla == 27){
	system("cls");
	printf("Deseja sair?(S/N): ");
	scanf("%c", &esc);
	if (esc == 'S' || esc == 's'){
	break;
}
else if (esc == 'N' || esc == 'n'){
	continue;
}
}
desenhar_pers();
}
}

}

