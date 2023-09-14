#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n,m,y=0,g,l,i;
    // TODO: Prompt for start size
    while(1){
        n = get_int("Start Size: ");
        if(n>=9){
            break;
        }
    }
    // TODO: Prompt for end size
    while(1){
        m = get_int("End Size: ");
        if(m>=n){
            break;
        }
    }
    // TODO: Calculate number of years until we reach threshold
    for(i=n;i<m;i++){
        if(n < m){
        g = n/3;
        l = n/4;
        n = n+g-l;
        y++;
        }else{
            break;
        }
    }
    // TODO: Print number of years
    printf("Years: %d\n",y);
}
