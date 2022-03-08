// Program water level  controller 
#include<reg51.h>
sbit AA=P1^0; 
sbit BB=P1^1; 
sbit CC=P1^2;
sbit DD=P1^3; 
sbit EE=P1^4;  
sbit FF=P1^5;
sbit GG=P1^6; 
sbit HH=P1^7; 
sbit II=P3^0; 
sbit JJ=P3^1; 

sbit rs=P3^2; 
sbit rw=P3^3; 
sbit  e=P3^4; 
sbit MOTOR=P3^5;  
void delay(int X) 
{
int i,j;
for(i=0;i<X;i++)
  for(j=0;j<1000;j++);
}
void write(int j) 
{
rs=1;  
rw=0;  
P2=j; 
e=1;  
delay(10);
e=0;
return;
}
void cmd(int j) 
{
P2=j;  
rs=0;  
rw=0;  
e=1;  
delay(10);
e=0;
return;
}
void puts(char *a) 
{
unsigned int p=0;
for(;a[p]!=0;p++)
write(a[p]);
}
void lcd_init(void) 
{
cmd(0x38); 
delay(10);
cmd(0x0c); 
delay(10);     
cmd(0x01);
cmd(0x06); 
cmd(0x80); 
}
void main()
{
AA=BB=CC=DD=EE=FF=GG=HH=II=JJ=0;
while(1)
{
while(AA==0&&BB==0&&CC==0&&DD==0&&EE==0&&FF==0&&GG==0&&HH==0&&II==0&&JJ==0)  
  {
   lcd_init();       
   puts("  TANK EMPTY ");
   lcd_init(); 
   puts("  MOTOR  ON");
   MOTOR=1;
 }
while(AA==1&&BB==0&&CC==0&&DD==0&&EE==0&&FF==0&&GG==0&&HH==0&&II==0&&JJ==0)
  {
   lcd_init();
puts("WATER 10%");
 }
while(AA==1&&BB==1&&CC==0&&DD==0&&EE==0&&FF==0&&GG==0&&HH==0&&II==0&&JJ==0)
  {
   lcd_init();     
   puts("WATER 20%");      
  }
while(AA==1&&BB==1&&CC==1&&DD==0&&EE==0&&FF==0&&GG==0&&HH==0&&II==0&&JJ==0)
  {
  lcd_init();
   puts("WATER 30%");     
  }
while(AA==1&&BB==1&&CC==1&&DD==1&&EE==0&&FF==0&&GG==0&&HH==0&&II==0&&JJ==0)
  {
   lcd_init();
   puts("WATER 40%");     
    }
while(AA==1&&BB==1&&CC==1&&DD==1&&EE==1&&FF==0&&GG==0&&HH==0&&II==0&&JJ==0)
  {
 lcd_init();
   puts("WATER 50%");  
  }

while(AA==1&&BB==1&&CC==1&&DD==1&&EE==1&&FF==1&&GG==0&&HH==0&&II==0&&JJ==0)  
  {
   lcd_init();       
   puts("WATER 60%");       
  }
while(AA==1&&BB==1&&CC==1&&DD==1&&EE==1&&FF==1&&GG==1&&HH==0&&II==0&&JJ==0)  
  {
   lcd_init();       
   puts("WATER 70%");       
  }
while(AA==1&&BB==1&&CC==1&&DD==1&&EE==1&&FF==1&&GG==1&&HH==1&&II==0&&JJ==0)  
  {
   lcd_init();       
   puts("WATER 80%");       
  }
while(AA==1&&BB==1&&CC==1&&DD==1&&EE==1&&FF==1&&GG==1&&HH==1&&II==1&&JJ==0)  
  {
   lcd_init();       
   puts("WATER 90%");       
  }
while(AA==1&&BB==1&&CC==1&&DD==1&&EE==1&&FF==1&&GG==1&&HH==1&&II==1&&JJ==1)  
  {
   lcd_init();       
   puts("   TANK  FULL  ");
   lcd_init();       
 puts("   MOTOR  OFF  ");
   MOTOR=0;
 }
}
}