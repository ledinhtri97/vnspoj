#include <cstdio>

int tim(){
	int n;
	int a[100], b[100];
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		int j=i;
		while(j>0 && a[j-1]>a[j]){
			int t = a[j];
			a[j] = a[j-1];
			a[j-1] = t;
			t = b[j];
			b[j] = b[j-1];
			b[j-1] = t;
			j--;
		}
	}
	int i=0;
	while(i<n-1 && a[i]<0) i++;

	if(i==0) return b[i];
	if(i==n-1) if(a[i]<0) return b[i];
	
	int t=0, t1=0, j=0;
	if(i>n-i) { 
		i--;
		while(i-j>=0 && i+j+1<n){
			t += b[i-j]+b[i+j+1];
			j++;
		}
		t1 = b[i];
		j=1;
		while(i-j>=0 && i+j<n){
			t1+=b[i-j]+b[i+j];
			j++;
		}
	}else { 
	while(i-j-1>=0 && i+j<n) {
		t += b[i+j]+b[i-j-1];
		j++;
	}
		t1 = b[i];
		j=1;
		while(i-j>=0 && i+j<n){
			t1+=b[i-j]+b[i+j];
			j++;
		}
	}
	if(t>t1)
	return t;
	return t1;
}

int main(){
	printf("%d\n", tim());
	return 0;
}
