#include <stdio.h>

int main(void) {
  int x,i,j,counter;
  scanf("%d",&x);
  printf("\n");
  // for(i=0;i<=x+2;i++){
  //   for(j=0;j<=x+2;j++){
  //     if(((j-i)*-1)<0){
  //       printf("%d ",(j-i));
  //     }else{
  //       printf("%d ",((j-i)*-1));
  //     }
  //     counter+=1;
  //   }
  //   printf("\n");
  // }
  for(i=1;i<=x;i++){
    for(j=x;j>=1;j--){
      if(((i-j)*-1)<0){
        printf("%d ",((i-j)-x )*-1);
        //printf("%d ",(i-j)+x*-1);
        counter+=1;
      }else{
        printf("%d ",(i-j)-x*-1);
        //printf("%d ",(j-i)-x);
      }
    }
    printf("\n");
  }
 

  printf("%d",counter);
  return 0;
}