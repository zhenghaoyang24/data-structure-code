#include<stdio.h>

// 斐波那契数
int fib(int m)
{
    // printf("%d ",m);
	if(m>=3)
	{
		return fib(m-1)+fib(m-2);
	}
	else{
		  return 1;
		 } 
}

int jiechegn(int e){
    if (e<=1)
       return 1;
    return e*jiechegn(e-1);
}

int main()
{
	int n;
	scanf("%d",&n);
	// printf("%d\n",fib(n));


    printf("%d的阶乘为%d\n",n,jiechegn(n));

    	return 0;
 } 
