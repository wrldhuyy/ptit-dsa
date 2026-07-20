#include<stdio.h>
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		double s = 0;
		if(n % 2 == 0){
			for(int i = 2; i <= n; i+=2)
				s += 1.0/i;
		} else{
			for(int i = 1; i <= n; i+=2)
			s += 1.0/i;
		}
		printf("%6.lf\n", s);
	}
	return 0;
}