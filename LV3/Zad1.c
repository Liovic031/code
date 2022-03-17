#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct KOMPLEKSNI {
	float re;
	float im;
}br1,br2,rez;

void opciOblik(float a, float b){
	if(b<0)
		printf("z = %.2f%.2f*i",a,b);
	else
		printf("z = %.2f+%.2f*i",a,b);
}

void zbrajanje(float a, float b, float c, float d){
	float re,im;
	re=a+c;
	im=b+d;
	
	
	if(im<0)
		printf("\nZbrajanje : %.2f%.2f*i",re,im);
	else
		printf("\nZbrajanje : %.2f+%.2f*i",re,im);
	
}

void oduzimanje(float a, float b, float c, float d){
	float re,im;
	re=a-c;
	im=b-d;
	
	if(im<0)
		printf("\nOduzimanje : %.2f%.2f*i",re,im);
	else
		printf("\nOduzimanje : %.2f-%.2f*i",re,im);
	
}

void mnozenje(float a, float b, float c, float d){
	float re,im;
	re=a*c-b*d;
	im=a*d-b*c;
	if(im<0)
		printf("\nMnozenje : %.2f%.2f*i",re,im);
	else
		printf("\nMnozenje : %.2f-%.2f*i",re,im);
}

void dijeljenje(float a, float b, float c, float d){
	float re,im,naz;
	re=a*c-b*d;
	im=b*c-a*d;
	naz=c*c+d*d;
	
	if(im<0)
		printf("\nDijeljenje : %.2f%.2f*i/(%.2f)",re,im,naz);
	else
		printf("\nDijeljenje : %.2f-%.2f*i/(%.2f)",re,im,naz);
	
}

void modul(float a, float b){
	float z;
	z=sqrt(a*a+b*b);
	
	printf(" z = %.2f",z);
}

int main(int argc, char *argv[]) {
	
	printf("Unesi br1 Re: ");
	scanf("%f",&br1.re);
	printf("Unesi br1 Im: ");
	scanf("%f",&br1.im);
	printf("Unesi br2 Re: ");
	scanf("%f",&br2.re);
	printf("Unesi br2 Im: ");
	scanf("%f",&br2.im);
	
	zbrajanje(br1.re,br1.im,br2.re,br2.im);
	oduzimanje(br1.re,br1.im,br2.re,br2.im);
	mnozenje(br1.re,br1.im,br2.re,br2.im);
	dijeljenje(br1.re,br1.im,br2.re,br2.im);
	printf("\nmodul br1"); modul(br1.re,br1.im);
	printf("\nmodul br2"); modul(br2.re,br2.im);
	return 0;
}