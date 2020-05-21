#include<regx52.h>
char so[]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
char i;
int dem1,dem2;
unsigned char chuc1,donvi1,chuc2,donvi2;
//== P0 = dèn 1+4 , P1= dèn 2+3
#define led11 P3_0
#define led12 P3_1
#define led21 P3_2
#define led22 P3_3
#define ledR1 P2_3
#define ledY1 P2_4
#define ledG1 P2_5
#define ledR2 P2_0
#define ledY2 P2_1
#define ledG2 P2_2
#define dbx1 P3_4
#define dbd1 P3_5
#define dbx2 P3_6
#define dbd2 P3_7
#define bat 0
#define tat 1
void delay(int time){
	while(time--);
}
void main(){
	while(1){
		dem1=30; dem2=25;
		//-------- dèn do 1 4 , dèn xanh 2 3 
		ledR1 = bat;
		ledG2 = bat;
		dbx1 = bat;dbd2 = bat;
		while(dem2!=-1&&dem1!=4){
			chuc1 = dem1/10; 	donvi1 = dem1%10;
			chuc2 = dem2/10;  donvi2 = dem2%10;
		//---------- sang led 7 doan doi
			for(i=0;i<=10;i++){
				led11 = bat; led21 = bat;
				P0=so[chuc1];
				P1=so[chuc2];
				delay(5000);
				led11 = tat; led21 = tat;
				
				led12 = bat; led22 = bat; 
				P0=so[donvi1]; // dèn 1 4
				P1=so[donvi2]; // den 2 3
				delay(5000);
				led12 = tat; led22 = tat;	
			}
			dem1--; dem2--;
		}
		//-------- den vang 2 3
	  ledG2 = tat;
		ledY2 = bat;
		while(dem1!=-1){
			chuc1 = dem1/10;  donvi1 = dem1%10;
			for(i=0;i<=10;i++){
				led11 = bat; led21=bat;
				P0=P1=so[chuc1];
				delay(5000);
				led11 = tat; led21=tat;
				dbx1 = bat;dbd2= bat;
				led12 = bat; led22 = bat;
				P0=P1=so[donvi1];
				delay(5000);
				led12 = tat; led22=tat;
			}
			dbx1 = tat;dbd2= tat;
			dem1--;
		}
		ledR1 = tat; ledY2 = tat; dbd1= bat; dbx2 = bat;
		//===== dèn do 2 3 , den xanh 1 4 
		dem1=25; dem2=30;
		ledR2 = bat; ledG1 = bat;
		while(dem1!=-1&&dem2!=4){
			chuc1 = dem1/10; 	donvi1 = dem1%10;
			chuc2 = dem2/10;  donvi2 = dem2%10;
		//---------- sang led 7 doan doi
			for(i=0;i<=10;i++){
				led11 = bat; led21 = bat;
				P0=so[chuc1];
				P1=so[chuc2];
				delay(5000);
				led11 = tat; led21 = tat;
				
				led12 = bat; led22 = bat; 
				P0=so[donvi1]; // dèn 1 4
				P1=so[donvi2]; // den 2 3
				delay(5000);
				led12 = tat; led22 = tat;	
			}
			dem1--; dem2--;
		}
		//==== den vang  1 4 
		ledG1 = tat; ledY1 = bat;
		while(dem2!=-1){
			chuc2 = dem2/10;  donvi2 = dem2%10;
			for(i=0;i<=10;i++){
				led21 = bat; led11=bat;
				P1=P0=so[chuc2];
				delay(5000);
				led21 = tat;led11=tat;
				dbd1 = bat;dbx2= bat;
				led22 = bat; led12=bat;
				P1=P0=so[donvi2];
				delay(5000);
				led22 = tat;led12=tat;
			}
			dem2--;dbd1= tat;dbx2=tat;
		}
		ledY1 = tat;
	}
}