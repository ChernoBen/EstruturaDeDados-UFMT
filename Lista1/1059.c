#include <stdio.h>

/*
Faça um programa que mostre os números pares entre 1 e 100, inclusive.
*/
int main(){
    int count;
	for(count = 1; count <= 100; count ++){
        if((count%2)==0){
            printf("%d\n",count);
        }
    }
	return 0;
}