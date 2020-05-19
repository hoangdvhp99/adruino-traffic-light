#include<regx52.h>
char so[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
char i;
int dem,n;
unsigned char chuc,donvi;
#define led1 P2_0
#define led2 P2_1
#define ledR P2_4
#define ledY P2_5
#define ledG P2_6
#define bat 0
#define tat 1
void delay(int time){
	while(time--);
}
void main(){
	while(1){
		dem=30;
		//-------- dèn do 
		ledR = bat;
		while(dem!=0){
			chuc = dem/10;
			donvi = dem%10;
			//---------- sang led 7 doan doi
			for(i=0;i<=10;i++){
				led1 = bat;
				P0=so[chuc];
				delay(5000);
				led1 = tat;
				
				led2 = bat;
				P0=so[donvi];
				delay(5000);
				led2=tat;	
			}
			dem--;
		}
		ledR = tat;
		//-------- den vang
		for(i = 1;i<=3;i++){
			ledY = bat;
			delay(100000);
		}
		ledY=tat;
		//-------- den xanh
		ledG = bat;
		dem =15;
		while(dem!=0){
			chuc = dem/10;
			donvi = dem%10;
			//---------- sang led 7 doan doi
			for(i=0;i<=10;i++){
				led1 = bat;
				P0=so[chuc];
				delay(5000);
				led1 = tat;
				
				led2 = bat;
				P0=so[donvi];
				delay(5000);
				led2=tat;	
			}
			dem--;
			//-----------------------------
		}
		//------- den vang
		for(i = 1;i<=3;i++){
			ledY = bat;
			delay(100000);
		}
		ledY = tat;
		ledG = tat;
	}
}