///////////////////////////
// Autor: Wiktor Lewicki //
///////////////////////////
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int kub[N], tab[N], check[N], connect[N], ile, lic, n;
vector<int> blocked[N], cord[N], kraw[N];
vector<pair<int, int>> answer, pzm;
long long ans=1;
bitset<N> priority, used, odw;
bool cmp(pair<int, int>a, pair<int, int>b){
	if(a.second==b.second){
		return a.first < b.first;
	}
	return a.second < b.second;
}
void dfs(int x){
	odw[x] = true;
	ile++;
	for(auto v : kraw[x]){
		if(!odw[v]){
			dfs(v);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	bool ok = false;
	for(int i=1;i<=n;i++){
		cin>>tab[i];
		if(!kub[tab[i]]) lic++;
		kub[tab[i]]++;
		cord[tab[i]].pb(i);
		if(kub[tab[i]]>2){
			ok = true;
		}
	}
	if(ok){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(cord[i].size()==2&&cord[i][1]-cord[i][0]!=2){
			cout<<0;
			return 0;
		}
	}
	priority[0]=true;
	for(int i=1;i<=n-1;i++){
		if(used[i]) continue;
		used[i]=true;
		if(i<n-1&&tab[i]==tab[i+2]){
			used[i+2]=true;
			check[i]=i+1;
			check[i+2]=i+1;
			priority[i+1]=true;
			blocked[i+1].clear();
			blocked[i+1].pb(tab[i]);
		}
		else if(!priority[i-1]&&!priority[i+1]){
			blocked[i-1].pb(tab[i]);
			blocked[i+1].pb(tab[i]);
		}
		else if(!priority[i-1]&&priority[i+1]){
			priority[i-1]=true;
			check[i]=i-1;
			blocked[i-1].clear();
			blocked[i-1].pb(tab[i]);
		}
		else if(priority[i-1]&&!priority[i+1]){
			check[i]=i+1;
			blocked[i+1].clear();
			blocked[i+1].pb(tab[i]);
			priority[i+1]=true;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	if(priority[n-1]&&blocked[n-1][0]!=tab[n]){
		cout<<0;
		return 0;
	}
	priority[n-1]=true;
	check[n]=n-1;
	blocked[n-1].clear();
	blocked[n-1].pb(tab[n]);
	used[n]=true;
	for(int i=n-2;i>=1;i--){
		if(check[i]) continue;
		if(!priority[i-1]&&priority[i+1]){
			check[i]=i-1;
			priority[i-1]=true;
			blocked[i-1].clear();
			blocked[i-1].pb(tab[i]);
		}
		else if(priority[i-1]&&!priority[i+1]){
			check[i]=i+1;
			priority[i+1]=true;
			blocked[i+1].clear();
			blocked[i+1].pb(tab[i]);
		}
		else if(priority[i-1]&&priority[i+1]){
			cout<<0;
			return 0;
		}
	}
	lic=0;
	for(int i=1;i<=n;i++){
		if(!kub[i]) lic++;
	}
	for(int i=1;i<=lic;i++){
		ans*=i;
		ans%=MOD;
	}
	for(int i=1;i<=n;i++){
		if(!priority[i]){
			if(blocked[i].size()==1){
				pzm.pb({blocked[i][0], 0});
			}
			else if(blocked[i].size()==2){
				if(blocked[i][0]>blocked[i][1]){
					swap(blocked[i][0], blocked[i][1]);
				}
				pzm.pb({blocked[i][0], blocked[i][1]});
			}
		}
	}
	used.reset();
	long long opt=1;
	sort(pzm.begin(), pzm.end(), cmp);
	for(int i=0;i<(int)pzm.size();i++){
		if(used[i]) continue;
		used[i] = true;
		if(i+1<(int)pzm.size()&&pzm[i].second==0&&pzm[i]==pzm[i+1]){
			used[i+1] = true;
			opt*=2;
			opt%=MOD;
		}
		else{
			answer.pb(pzm[i]);
		}
	}
	for(auto v : answer){
		if(v.second){
			kraw[v.first].pb(v.second);
			kraw[v.second].pb(v.first);
		}
	}
	for(auto v : answer){
		if(!odw[v.first]){
			ile=0;
			dfs(v.first);
			opt*=(ile+1);
			opt%=MOD;
		}
	}
	ans=(ans*opt)%MOD;
	cout<<ans;
	return 0;
}
