///////////////////////////
// Autor: Wiktor Lewicki //
///////////////////////////
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
const int N = 5e5 + 5;
const ll inf = 1e15;
vector<pair<pair<int, int>, pair<int, int>>> mon;
vector<int> idx;
int n, ans, tab[N], k;
ll d[4*N], push[4*N];
bitset<N> odw;
void add(int x,  ll ile){
	d[x]+=ile;
	push[x]+=ile;
}
void pushuj(int x){
	add(x*2, push[x]);
	add(x*2+1, push[x]);
	push[x]=0;
}
void build(int x, int l, int r){
	if(l==r){
		if(l<=n) d[x]=tab[l];
		if(!d[x]) d[x]=inf;
		return;
	}
	int sr = (l+r)/2;
	build(x*2, l, sr);
	build(x*2+1, sr+1, r);
	d[x]=min(d[x*2], d[x*2+1]);
}
void update(int x, int l, int r, int a, int b, ll val){
	if(a<=l&&r<=b){
		add(x, val);
		return;
	}
	pushuj(x);
	int sr=(l+r)/2;
	if(a<=sr){
		update(x*2, l, sr, a, b, val);
	}
	if(sr<b){
		update(x*2+1, sr+1, r, a, b, val);
	}
	d[x]=min(d[x*2], d[x*2+1]);
}
ll query(int x, int l, int r, int a, int b){
	if(a<=l&&r<=b){
		return d[x];
	}
	pushuj(x);
	ll res=1e15;
	int sr=(l+r)/2;
	if(a<=sr){
		res=min(res, query(x*2, l, sr, a, b));
	}
	if(sr<b){
		res=min(res, query(x*2+1, sr+1, r, a, b));
	}
	d[x]=min(d[x*2], d[x*2+1]);
	return res;
}
bool cmp(pair<pair<int, int>, pair<int, int>>a, pair<pair<int, int>, pair<int, int>>b){
	if(a.first.second==b.first.second){
		return a.first.first < b.first.first;
	}
	return a.first.second < b.first.second;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int rozm=1;
	for(int i=1;i<=n;i++){
		int a, b;
		cin>>a>>b;
		if(a<=b){
			mon.pb({{a, b}, {0, i}});
		}
	}
	sort(mon.begin(), mon.end(), cmp);
	for(int i=0;i<(int)mon.size();i++){
		if(i&&mon[i].first.second==mon[i-1].first.second) k++;
		mon[i]={{mon[i].first.first, mon[i].first.second}, {i+1-k, mon[i].second.second}};
	}
	mon.pb({{0, 0}, {0, 0}});
	sort(mon.begin(), mon.end());
	n=mon.size()-1;
	for(int i=1;i<=n;i++){
		tab[mon[i].second.first]=mon[i].first.second;
	}
	while(rozm<n+1){
		rozm*=2;
	}
	build(1, 1, rozm);
	for(int i=1;i<=n;i++){
		update(1, 1, rozm, mon[i].second.first, rozm, -mon[i].first.first);
		if(d[1]<0){
			update(1, 1, rozm, mon[i].second.first, rozm, mon[i].first.first);
			continue;
		}
		idx.pb(mon[i].second.second);
		odw[mon[i].second.second] = true;
	}
	sort(mon.begin(), mon.end(), cmp);
	cout<<(int)idx.size()<<"\n";
	int wsk=1;
	for(int i=1;i<=n;i++){
		if(odw[mon[i].second.second]){
			cout<<mon[i].second.second<<" "<<wsk<<"\n";
			wsk+=mon[i].first.first;
		}
	}
	return 0;
}
