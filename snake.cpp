Esteban Peluffo - T00081095
Ronaldo Rojas - T00076558

#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80
#define ESC 27


int dir = 3;
int velocidad = 100;
int x = 10;
int y = 12;
int tam =3;
int cuerpo[200][2];
int n =1;
int xc = 30;
int yc = 15;
int score = 0;

char tecla;

void gotoxy (int x, int y){
	HANDLE hCon;
	COORD dwPos;
	
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
	
}

void pintar(){
	
	//Lineas horizontales.
	for (int i=2; i<78;i++){
		gotoxy (i,3);
		printf("%c",205);
		gotoxy (i,23);
		printf("%c",205);
	}
	//Lineas verticales.
	for (int i=4;i<23;i++){
		gotoxy (2,i);
		printf("%c",186);
		gotoxy (77,i);
		printf("%c",186);
	}
	// Esquinas.
	gotoxy(2,3);
	printf("%c",201);
	gotoxy(2,23);
	printf("%c",200);
	gotoxy(77,3);
	printf("%c",187);
	gotoxy(77,23);
	printf("%c",188);
}

Borrar_cuerpo(){
	gotoxy(cuerpo[n][0],cuerpo[n][1]);
	printf(" ");
	
}

guardar_posicion(){
	cuerpo[n][0]=x;
	cuerpo[n][1]=y;
	n++;
	if (n==tam){
		n=1;
	}
}

void dibujar_cuerpo(){
	for(int i=1; i<tam;i++){
		gotoxy(cuerpo[i][0],cuerpo[i][1]);
		printf("*");
	}
}
void cambiar_velocidad(){
	velocidad=velocidad+3;
	
}

void comida(){
	if (x==xc && y==yc){
		xc=(rand()%73)+4;
		yc=(rand()%18)+5;
		tam++;
		score=score+10;
		gotoxy(xc,yc);
		printf("%c",207);
		cambiar_velocidad();
	}
}


void puntos(){
	gotoxy(3,1);
	printf("SCORE:  %d", score);
}
teclear(){
	if (kbhit()){
		tecla=getch();
		switch(tecla){
	case ARRIBA:
		if(dir !=2){
			dir=1;
		}
		break;
		case ABAJO:
			if (dir !=1){
				dir=2;
			}
			break;
			case DERECHA:
				if(dir !=4){
					dir=3;
				}
				break;
				case IZQUIERDA:
					if(dir!=3){
						dir =4;
					}
					break;
				
			
			
		}
	}
}

bool game_over(){
	if (y==3 || y ==23 || x==2 || x==77){
		return true;
	}
	for (int j=tam-1;j>0; j--){
		if(cuerpo[j][0]==x && cuerpo[j][1]==y){
			return true;
		}
	}
	return false;
}


int main () {
	
	pintar();
	gotoxy(xc,yc);
	printf("%c",207);
	
	while(tecla != ESC && !game_over()){
		
		//Borrar cuerpo
		Borrar_cuerpo();

		// Guardar nueva posicion 
		guardar_posicion();
		// pintar cuerpo 
		dibujar_cuerpo();  
		// controlar comida 
		comida();
		// controlar puntos 
		puntos();
		// controlar teclas 
		teclear();
		teclear();
		// identifica direccion 
		if (dir==1){
			y--;
			
		}
		if (dir==2){
			y++;
		}
		if (dir==3){
			x++;
		}
		if (dir==4){
			x--;
		}
		
		// controlar velocidad
		Sleep (velocidad);
		
		
	}
	
	gotoxy  (35,12);
	printf ("GAME_OVER");

	system("pause>NULL");
	return 0;
}
