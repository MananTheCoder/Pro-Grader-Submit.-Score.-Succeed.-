#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define flf(i, a, b) for (int i = a; i < b; i++)
#define flb(i, a, b) for (int i = a; i > b; i--)
#define takeInt(n) int n; cin >> n
#define takeStr(str) string str; cin >> str
const int MOD = 1e9 + 7;
const long long INF = 1e18;

void solve() {
    // Solution
    takeInt(n1);
    takeInt(n2);
    takeInt(n3);

    stack<int> tmp ;
    stack<int> s1;
    stack<int> s2;
    stack<int> s3;
    int h1 =0 ;
    int h2 = 0;
    int h3 = 0;

    flf(i,0,n1){
        int temp ;
        cin>>temp;
        h1+=temp;
        tmp.push(temp);
    }
    while(!tmp.empty()){
        s1.push(tmp.top());
        tmp.pop();
    }

     flf(i,0,n2){
        int temp ;
        cin>>temp;
        h2+=temp;
        tmp.push(temp);
    }
    while(!tmp.empty()){
        s2.push(tmp.top());
        tmp.pop();
    }

     flf(i,0,n3){
        int temp ;
        cin>>temp;
        h3+=temp;
        tmp.push(temp);
    }
    while(!tmp.empty()){
        s3.push(tmp.top());
        tmp.pop();
    }

    while(h1!=h2 or h2!=h3 or h1!=h3){

        if(h1>=h2 and h1>=h3){
            h1-=s1.top();
            s1.pop();
        }
        else if(h2>=h1 and h2>=h3){
            h2-=s2.top();
            s2.pop();
        }
        else if(h3>=h2 and h3>=h1){
            h3-=s3.top();
            s3.pop();
        }
        if(h1<=0 or h2<=0 or h3<=0){
            cout<<0<<endl;
            return;
        }
    }
    cout<<h1<<endl;

}

int main() {
    fastIO;
    ll t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
