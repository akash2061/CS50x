#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i,j,n;
    while(1){
        n = get_int("Height: ");
        if(n>=1 && n<=8){
            break;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("#");
        }
        printf("\n");
    }
}