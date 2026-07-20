#include<stdio.h>
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		long long n;
		scanf("%lld", &n);
		for(long long i = 2; i * i <= n;i++){
			if(n % i == 0){
				int count  = 0;
				while(n % i == 0){
					count++;
					n /= i;
				}
				printf("%lld %d\n",i,count);
			}
		}
		if(n > 1)
			printf("%lld 1\n",n);
		if(t)
			printf("\n");
	}
	return 0;
}