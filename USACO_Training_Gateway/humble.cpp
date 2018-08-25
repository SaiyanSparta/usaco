/**
	ID: tylerzh1
	PROB: humble
	LANG: C++11
**/
 

#include <iostream>
#include <set>
#include <fstream>

using namespace std;

ofstream fout("humble.out");
ifstream fin("humble.in"); 

const int maxK = 105; 
long long arrs[maxK]; 

int main() {
    int K, N; 
    fin >> K >> N; 
    for (int i = 0; i < K; i++){
        fin >> arrs[i]; 
    }

    set<long long> nums; 
    nums.insert(1); 
    auto it = nums.begin(); 
    int m = N; 
    for (; m > 0; m--) {
        long long cur = *it; 
        long long last = *nums.rbegin(); 
        for (int i = 0; i < K; i++){
            long long x = 1LL*cur*arrs[i]; 
            if ( (nums.size() < N + 10) || (x < last)) {
                nums.insert(x);  //add in new humble number
            }
        }
        it++; 
    }
    fout << *it << endl; 
}
