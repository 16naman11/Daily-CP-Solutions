#include <stdio.h>

int main() 
{
    int n,count,i=2,c=0;
    for(n=2;n<1000;n++)
    {count=0;
        for(i=1;i<=n;i++)
        {
            if(n%i==0)
            {
                count=count+1;
            } 
        }
            if(count==2)
            {
                printf("%d\n",n);
                c++;
            }
            if(c>100)
            {
                    break;
            }
        
    }
    return 0;
}
