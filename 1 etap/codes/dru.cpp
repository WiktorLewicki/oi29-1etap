//////////////////////////
// Autor: Wiktor Lewicki//
//////////////////////////
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e3 + 5;
string tab[N];
vector<int> odp;
int kub[N], kub_temp[N];
bitset<N> odw[N], czy;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin>>n>>m;
	int rozm=n*m;
	for(int i=1;i<=n;i++){
		string pom;
		tab[i]+=".";
		cin>>pom;
		tab[i]+=pom;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			kub[(int)tab[i][j]]++;
		}
	}
	int one_case=0;
	for(int i=97;i<=122;i++){
		if(kub[i]) one_case++;
	}
	if(one_case==1){
		for(int i=1;i<=n;i++){
			if(n%i==0){
				odp.pb(i);
				czy[i]=true;
			}
		}
		for(int i=1;i<=m;i++){
			if(!czy[i]&&m%i==0){
				odp.pb(i);
			}
		}
		sort(odp.begin(), odp.end());
		cout<<(int)odp.size()<<"\n";
		for(auto v : odp){
			cout<<v<<" ";
		}
		return 0;
	}
	for(int k=1;k<=m;k++){
		bool ok = false;
		if(rozm%k) continue;
		string pom = ".";
		for(int i=97;i<=122;i++){
			kub_temp[i]=0;
		}
		int ile = rozm/k;
		for(int z=1;z<=k;z++){
			pom+=tab[1][z];
			kub_temp[(int)tab[1][z]]+=ile;
		}
		for(int i=97;i<=122;i++){
			if(kub[i]!=kub_temp[i])
			ok = true;
			break;
		}
		if(ok) continue;
		bool czy_da = false;
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				if(odw[i][j]) continue;
				bool check = false;
				int lic=1;
				if(i+k-1<=n){
					for(int p=i;p<=i+k-1;p++){
						if(odw[p][j]||(tab[p][j]!=pom[lic])){
							break;
						}
						if(p==i+k-1){
							check = true;
							for(int a=i;a<=i+k-1;a++){
								odw[a][j] = true;
							}
						}
						lic++;
					}
				}
				
				if(check){
					continue;
				}
				if(j+k-1<=m){
					lic=1;
					for(int p=j;p<=j+k-1;p++){
						if(odw[i][p]||(tab[i][p]!=pom[lic])){
							break;
						}
						if(p==j+k-1){
							check = true;
							for(int a=j;a<=j+k-1;a++){
								odw[i][a] = true;
							}
						}
						lic++;
					}
				}
				if(!check){
					czy_da = true;
					break;
				}
			}
			if(czy_da){
				break;
			}
		}
		if(!czy_da){
			odp.pb(k);
			czy[k] = true;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				odw[i][j] = false;
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		if(czy[k]) continue;
		bool ok = false;
		if(rozm%k) continue;
		string pom = ".";
		for(int i=97;i<=122;i++){
			kub_temp[i]=0;
		}
		int ile = rozm/k;
		for(int z=1;z<=k;z++){
			pom+=tab[z][1];
			kub_temp[(int)tab[z][1]]+=ile;
		}
		for(int i=97;i<=122;i++){
			if(kub[i]!=kub_temp[i])
			ok = true;
			break;
		}
		if(ok) continue;
		bool czy_da = false;
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				if(odw[i][j]) continue;
				bool check = false;
				int lic=1;
				if(i+k-1<=n){
					for(int p=i;p<=i+k-1;p++){
						if(odw[p][j]||tab[p][j]!=pom[lic]){
							break;
						}
						if(p==i+k-1){
							check = true;
							for(int a=i;a<=i+k-1;a++){
								odw[a][j] = true;
							}
						}
						lic++;
					}
				}
				if(check) continue;
				if(j+k-1<=m){
					lic=1;
					for(int p=j;p<=j+k-1;p++){
						if(odw[i][p]||tab[i][p]!=pom[lic]){
							break;
						}
						if(p==j+k-1){
							check = true;
							for(int a=j;a<=j+k-1;a++){
								odw[i][a] = true;
							}
						}
						lic++;
					}
				}
				if(!check){
					czy_da = true;
					break;
				}
			}
			if(czy_da) break;
		}
		if(!czy_da){
			odp.pb(k);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				odw[i][j] = false;
			}
		}
	}
	cout<<(int)odp.size()<<"\n";
	sort(odp.begin(), odp.end());
	for(auto v : odp){
		cout<<v<<" ";
	}
	return 0;
}
