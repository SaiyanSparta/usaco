/**
	ID: tylerzh1
	PROB: contact
	LANG: C++14
**/

#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ofstream fout("contact.out"); 
ifstream fin("contact.in"); 

struct dumb {
    int ct = 0; 
    string txt; 
};

bool comp(dumb a, dumb b) {
    if (a.ct != b.ct) return a.ct > b.ct; 
    else if (a.txt.size() != b.txt.size() ) {
        return a.txt.size() < b.txt.size(); 
    }
    else {
        return a.txt < b.txt;
    }
}

const int maxS = 200000; 
dumb arrs[maxS]; 

int main() {
    int p = 1e5+3; 
    int A, B, N; 
    fin >> A >> B >> N; 
    string text="", temp; 
    while (fin >> temp) {
        text += temp; 
    }

    for (int l = A; l <= B; l++){ //iterate on length 
        if (l > text.size()) break; 
        int h = 1; 
        for (int i = 0; i < l-1; i++){
            h = (h*2)%p;  //create pow(b, l-1) % p
        }
        // Create first hash
        int curHash = 0; 
        for (int i = 0; i < l; i++){
            curHash = (curHash*2+text[i])%p; 
        }
        
        // Slide 
        for (int i = 0; i <= text.size()-l; i++){
            if (arrs[curHash].ct == 0) { //means has not appeared yet
                arrs[curHash].txt = text.substr(i, l);  
            }
            arrs[curHash].ct++; 

            // Roll the Hash over 
            if (i < text.size() - l) {
                curHash = ( (curHash - h*text[i])*2+text[i+l] ) % p; 
                curHash = (curHash + p) % p; //negatives 
            }
        }
    }
    
    sort(arrs, arrs+maxS, comp); 
    
    int i = 0; 
    for (int j = 0; j < N; j++){
        if (arrs[i].ct == 0) break; 
        int counter = 1; 
        fout << arrs[i].ct << endl << arrs[i].txt; 
        while (arrs[i].ct == arrs[i+1].ct) {
            if (counter % 6 == 0) {
                fout << endl; 
                fout << arrs[i+1].txt; 
            }
            else fout << " " << arrs[i+1].txt; 
            counter++; 
            i++;
        }
        fout << endl; 
        i++; 
    }
}
