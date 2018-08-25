#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll; 

const int maxN = 110; 
const int maxH = 1000000; //going to be double the max hay just cuz, lol changing from 1e5 to 1e6 fixed last test case
const ll INF = 1LL << 40; 
int N, H; 
ll P[maxN]; 
ll C[maxN]; 
ll dp[maxH]; //dp 

int main() {
    cin >> N >> H; 
    for (int i = 0;i < N; i++){
        cin >> P[i] >> C[i]; 
    }
    for (int i = 1; i< maxH; i++){
        dp[i] = INF; 
    }
    ll best = INF;  
    for (int i = 0; i <= N; i++){
        for (int j = 0; j<= 2*H; j++){
            if (dp[j] < INF) {
                if (j >= H){
                    best = min(dp[j], best); //finding best sol
                }
                if (j + P[i] < maxH) dp[j+P[i]] = min(dp[j+P[i]], dp[j] + C[i]);  //update 
            }
        }
    }
    cout << best << endl; 
}
