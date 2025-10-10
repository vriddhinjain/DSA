#include <stdio.h>
#include <stdlib.h>

void TOH(int n,char s,char d,char t)
{
    if(n==1)
        printf("\n Move %d disc from %c to %c",n,s,d);
    else
    {
        TOH(n-1,s,t,d);
        printf("\n Move %d disc from %c to %c",n,s,d);
        TOH(n-1,t,d,s);
    }
}
int main()
{
    int n;
    printf("\n Read numbers of disc:");
    scanf("%d",&n);
    TOH(n,'S','D','T');
    return 0;
}
