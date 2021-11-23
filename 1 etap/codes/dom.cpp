//////////////////////////
//Autor : Wiktor Lewicki//
//////////////////////////
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll fb[100], wynik=1e9, zm, idx, inf=1e18;
void check(ll akt, ll ile, ll lic){
	if(akt==1) wynik=min(wynik, ile-1);
	for(ll i=lic;i<=idx;i++){
		if(akt%fb[i]==0) check(akt/fb[i], ile+i+1, i);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>zm;
	fb[0]=1;
	fb[1]=1;
	for(int i=2;i<=86;i++){
		fb[i]=fb[i-1]+fb[i-2];
		if(fb[i]>zm) break;
		idx=i;
	}
	if(zm==1){
		cout<<1;
		return 0;
	}
	check(zm, 0, 2);
	if(wynik==1e9){
		cout<<"NIE";
		return 0;
	}
	cout<<wynik;
	return 0;
}
