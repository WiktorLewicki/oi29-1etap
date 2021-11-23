//////////////////////////
//Autor : Wiktor Lewicki//
//////////////////////////
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
ll fa1[N], res, fa2[N], n, MOD;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>MOD;
	if(n==2) cout<<1%MOD;
	if(n==3) cout<<15%MOD;
	if(n==4) cout<<168%MOD;
	if(n==5) cout<<1700%MOD;
	if(n==6) cout<<17220%MOD;
	if(n==7) cout<<182406%MOD;
	if(n==8) cout<<2055200%MOD;
	if(n==9) cout<<24767928%MOD;
	if(n==10) cout<<319463100%MOD;
	if(n<=10) return 0;
	ll cum=0;
	ll mnz=1;
	for(int i=3;i<n;i++){
		mnz=(mnz*i)%MOD;
	}
	ll element=(mnz*(((n%MOD)*((n-1)%MOD))%MOD)%MOD)%MOD;
	cum+=element;
	cum%=MOD;
	if(n%2==0){
		element=(mnz*(((((n-2)/2)%MOD)*((n-1)%MOD))%MOD))%MOD;
	}
	else{
		element=(mnz*(((((n-1)/2)%MOD)*((n-2)%MOD))%MOD))%MOD;
	}
	cum+=element;
	cum%=MOD;
	fa1[0]=1;
	for(int i=1;i<=n;i++){
		fa1[i]=(fa1[i-1]*i)%MOD;
	}
	fa2[1]=1;
	for(int i=2;i<=n;i++){
		fa2[i]=(fa2[i-1]*(n-i+1))%MOD;
	}
	for(int i=1;i<=n;i++){
		ll pom=fa2[i]*(i-n);
		pom%=MOD;
		pom*=(n-1);
		pom%=MOD;
		res+=pom;
		res%=MOD;
		pom=(fa1[n-1]-fa2[i])*i;
		pom%=MOD;
		pom*=(n-1);
		pom%=MOD;
		res+=pom;
		res%=MOD;
		res+=cum;
		res%=MOD;
	}
	res+=MOD;
	res%=MOD;
	cout<<res;
    return 0;
}
