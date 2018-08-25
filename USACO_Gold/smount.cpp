#include <iostream>

using namespace std;

int arrs[100010]; 
int N; 

int main() {
    cin >> N; 
    for (int i = 0; i < N; i++){
        cin >> arrs[i]; 
    }
    bool UP = true; //try going up first 
    int best = -1, curr = 0, prev = 0; 
    for (int i = 0; i < N-1; i++){
        curr++; 
        if (arrs[i] > arrs[i+1]){
            if (UP) UP = false; //switch directions
            prev = i; //new starting point
        }
        else if (arrs[i] < arrs[i+1]){
            if (!UP) { //end of mountain
                UP = true; 
                i = prev;  //start at previous best place
                best = max(best, curr); 
                curr = 0; 
            }
        }
    }
    best = max(best, curr+1); 
    cout << best << endl; 
}
