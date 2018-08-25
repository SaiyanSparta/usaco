#include <iostream>

using namespace std;

int arrs[2510][10]; //f(x,y) where x is length, y is # of cuts left 

int main() {
    int N; 
    cin >> N; 
    for (int i = 1; i<= N; i++){
        arrs[i][0] = 1;  //one way; f(x, 0) is 1 
    }

    for (int y = 1; y < 4; y++){
        for (int x = 1; x <= N; x++){
           for (int i = 1; i <= x/2; i++){
                arrs[x][y] += arrs[x-i][y-1]; 
           }
        }
    }
    cout << arrs[N][3] << endl; 
}
