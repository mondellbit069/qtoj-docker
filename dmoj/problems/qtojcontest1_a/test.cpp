#include <bits/stdc++.h>
using namespace std;
long long lcm(long long a,long long b){return a/__gcd(a,b)*b;}
int main(int argc, char** argv) {
    ifstream inp(argv[1]);
    ifstream out(argv[2]);
    ifstream ans(argv[3]);
    int t;inp>>t;
    int ck = 0;
    while(t--){
    	long long x,y,n;
    	inp>>n;
    	out>>x>>y;
    	if(x>0&&y>0&&x<=n&&y<=n&&(lcm(x,y)+__gcd(x,y)==n)) continue;
    	else ck = 1;
    }
return ck;
}