#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
int main(){
	int gd=DETECT,gm;
	int x,y,i=0,j;
	initgraph(&gd,&gm,"c://TURBOC3//BGI");
	while(!kbhit()){
		circle(20+i,384,14);        //head
		line(20+i,400,20+i,430);    //chest
		line(20+i,430,12+i,454);    //leg left
		line(20+i,430,28+i,454);    //leg right
		line(20+i,410,10+i,420);    //left hand
		line(20+i,410,30+i,420);    //right hand
		line(30+i,420,30+i,360);    //umbral handle
		line(0+i,360,60+i,360);     //umbrela bottom;
		arc(30+i,360,0,180,30);     //umbrela above;
		for(j=0;j<600;++j){
			x=rand()%651;
			y=rand()%451;
			line(x-2,y+2,x,y);
		}

		delay(10);
		cleardevice();++i;
	}
	getch();
	closegraph();
}
