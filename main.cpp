#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>>tree,up;
int l;
void dfs(int x,int p = 0){
    up[x][0] = p;
    for(int i = 1 ; i <= l;i++) up[x][i] = up[up[x][i-1]][i-1];
    for(auto i:tree[x])
        if(i != p)
            dfs(i,x);
}
int findKthAncestor(int v,int k){
    for(int bit = l;bit >= 0;bit--)
		if((k & (1<<bit))) 
			v = up[v][bit];
		
	return v;
}
int get_lca(int a,int b){
    if(depth[a] != depth[b]){
        if(depth[a] < depth[b])
            swap(a,b);
        a = binsearch(a,abs(depth[a] - depth[b]));
    }
    if(a == b) return a;
    for(int bit = l; bit >= 0;bit--)
            if(up[a][bit] != up[b][bit]){
                a = up[a][bit];
                b = up[b][bit]; 
            }
    return up[a][0];
}
int main(){
    ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n,a,b,constraints = 1e5; cin>>n;
    tree.resize(n);
    l = log2(constraints)+1;
    up.resize(constraints,vector<int>(l));
    for(int i = 1 ; i < n;i++){
        cin>>a>>b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dfs(0);
    
}
