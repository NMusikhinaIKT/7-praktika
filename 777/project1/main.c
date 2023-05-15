#include <8052.h>
#include <htc.h>
 
int prov;

void imp(unsigned int cnt)
{
 do{ 
 if (cnt != 0){cnt--; P10 = 0;}
 else {P10 = 1;}
 }while(TF2 == 0);
 TF2 = 0; 
 if(P36 == 1)
 { 
 prov = 1;
 }
 if(P37 == 1)
 { 
 prov = 0;
 }
}

void main()
{
 prov = 1;

 P1 = 0xFE; 
 RCAP2H = 0xB8; 
 RCAP2L = 0x63; 
 
 T2CON &= 0xFC;
 ET2 = 1; 
 EA = 1; 
 T2CON |= 0x4; 
 while(1)
 {
 if (prov == 1)
  { 
  imp(580);//A KEY 
  }
 else imp(400);//B KEY

 if(P36 == 1)
  { 
  prov = 1;
  }
 if(P37 == 1)
  { 
  prov = 0;
  }
}
}
