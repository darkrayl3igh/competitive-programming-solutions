// GALATIANS 4:16

#include "bits/stdc++.h"

using namespace std;

#define ll long long int
#define debug(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define newline cout << endl
#define input_stream \
    freopen("input.txt", "r", stdin);\
    freopen("output.txt", "w", stdout);

const int MOD = 1000000007;

ll gcd (ll a, ll b) {return (a ? gcd(b % a, a) : b);}
int mpow(int base, int exp) {
    base %= MOD;
    int result = 1;
    while (exp > 0) {
      if (exp & 1) result = ((ll)result * base) % MOD;
      base = ((ll)base * base) % MOD;
      exp >>= 1;
    }
    return result;
}  

void nothing(){
    return;
}

void solve(int D){   
    ll neg_x=(-1LL)*1e18; neg_x--;
    ll pos_x=1e18; pos_x++;
    ll neg_y=(-1LL)*1e18; neg_y--;
    ll pos_y=1e18; pos_y++;
    
    ll attack = 1;
    string response;
    
    while(true){
        if(attack==1){
            if(pos_x >= (neg_x+2) && pos_y >= (neg_y+2)){
                ll midx = (pos_x+neg_x)/2;
                ll midy = (pos_y+neg_y)/2;
                
                cout << attack << " " << midx << " " << midy << endl;
                cin >> response;
                
                if(response.compare("O")==0 || response.compare("FAILED")==0){
                    break;
                }
                
                if(response[0]=='X'){
                    neg_x = midx-1;
                    pos_x = midx+1;
                } else if(response[0]=='P'){
                    if(D==0){
                        pos_x=midx-1;
                    } else{
                        pos_x=midx;
                        neg_x--;
                    }
                } else{
                    if(D==0){
                        neg_x=midx+1;
                    } else{
                        neg_x=midx;
                        pos_x++;
                    }
                }
                if(response[1]=='Y'){
                    neg_y = midy-1;
                    pos_y = midy+1;
                } else if(response[1]=='P'){
                    if(D==0){
                        pos_y=midy-1;
                    } else{
                        pos_y=midy;
                        neg_y--;
                    }
                } else{
                    if(D==0){
                        neg_y=midy+1;
                    } else{
                        neg_y=midy;
                        pos_y++;
                    }
                }
                if(D==0){
                    nothing();
                }
                else{
                    if(pos_x<=(neg_x+3) && pos_y<=(neg_y+3)){
                        attack=2;
                    }
                }
            } else{
                attack=2;
                
                cout << attack << " " << neg_x << " " << neg_y << " " << pos_x << " " << pos_y << endl;
                cin >> response;
                
                break;
            }
        } else{
            if((pos_x==(neg_x+3))&&((pos_y==(neg_y+3)))){
                cout << attack << " " << neg_x << " " << neg_y << " " << neg_x+2 << " " << pos_y << endl;
                cin >> response;
                
                if(response.compare("O")==0){
                    break;
                } else if(response.compare("IN")==0){
                    pos_x=neg_x+2;
                } else{
                    neg_x=neg_x+2;
                    pos_x++;
                }
            }
            if((pos_x==(neg_x+2))&&((pos_y==(neg_y+3)))){
                cout << attack << " " << neg_x << " " << neg_y << " " << pos_x << " " << neg_y+2 << endl;
                cin >> response;
                
                if(response.compare("O")==0){
                    nothing();
                } else if(response.compare("IN")==0){
                    cout << attack << " " << neg_x << " " << neg_y << " " << pos_x << " " << neg_y+2 << endl;
                    cin >> response;
                } else{
                    cout << attack << " " << neg_x << " " << neg_y+2 << " " << pos_x << " " << neg_y+4 << endl;
                    cin >> response;
                }
                
                break;
            }
            if((pos_x==(neg_x+3))&&((pos_y==(neg_y+2)))){
                cout << attack << " " << neg_x << " " << neg_y << " " << neg_x+2 << " " << pos_y << endl;
                cin >> response;
                
                if(response.compare("O")==0){
                    nothing();    
                }
                else if(response.compare("IN")==0){
                    cout << attack << " " << neg_x << " " << neg_y << " " << neg_x+2 << " " << pos_y << endl;
                    cin >> response;
                } else{
                    cout << attack << " " << neg_x+2 << " " << neg_y << " " << neg_x+4 << " " << pos_y << endl;
                    cin >> response;
                }
                
                break;
            }
            else{
                cout << attack << " " << neg_x << " " << neg_y << " " << pos_x << " " << pos_y << endl;
                cin >> response;
                
                break;
            }
            
        }
        cout.flush();
    }
    cout.flush();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t = 1, q, d; cin >> t >> q >> d;
    while(t--){
        solve(d);
    }
    return 0;
}