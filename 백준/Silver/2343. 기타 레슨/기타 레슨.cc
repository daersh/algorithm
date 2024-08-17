#include <stdio.h>

int N,M,lesson[100010];

int Min(int n1, int n2)
{
	if(n1<n2)
		return n1;

	return n2;
}

int main()
{
	int i,l,r,mid,cnt,sum=0,max=0,ans=1000000000;

	scanf("%d %d",&N, &M);

	for(i=0;i<N;i++){
		scanf("%d",&lesson[i]);
		if(max<lesson[i])
			max=lesson[i];
	}

	l=max;
	r=1000000000;

	while(l<=r){
		mid=(l+r)/2;

		sum=0;
		cnt=1;
		for(i=0;i<N;){
			sum+=lesson[i];
			if(sum<=mid)
				i++;
			else{
				cnt++;
				sum=0;
			}
		}
		if(cnt<=M){
			ans=Min(ans,mid);
			r=mid-1;
		}
		else
			l=mid+1;
	}

	printf("%d\n",ans);

	return 0;
}