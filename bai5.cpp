#include<stdio.h>
int main(){
	long long x ,max = 0;
	while(scanf("%lld", &x) != EOF){
		if(x > max)
		max = x;
	}
	printf("%lld",max);
	return 0;
}