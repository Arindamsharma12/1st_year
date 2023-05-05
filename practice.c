#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool isPerfectSquare(int num){
    float sroot = sqrt(num);
    printf("%f\n",sroot);
    if((float)num == sroot * sroot){
        return true;
    }    
    else{
        return false;
    }
}

int main(){
    int num;
    printf("Enter number:\n");
    scanf("%d",&num);
    if(isPerfectSquare(num)){
        printf("1");
    }
    else{
        printf("0");
    }
    return 0;
}