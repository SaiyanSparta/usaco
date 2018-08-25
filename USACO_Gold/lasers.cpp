#include <iostream>
#include <fstream>
#include <vector>
#include <queue> 
#include <algorithm>

using namespace std; 

ofstream fout("lasers.out"); 
ifstream fin("lasers.in"); 
struct Point{
	int x, y, ind, dist; 
};
#define REP(i,a,b) \
	for (int i = int(a); i<int(b); i++)

const int maxN = 100010; 

int N, xl, yl, xb, yb; //laser and barn x/y coords 
Point x[maxN]; 

class prioritize{public: bool operator ()(Point&p1, Point&p2){return p1.dist>p2.dist;}};

int Dijkstra(){
	bool mark[maxN] = {false};  //mark by index 
	priority_queue< Point, vector<Point>, prioritize> pq;
	Point start = {xl, yl}; 
	start.dist = 0; 
	pq.push(start); 
	while (!pq.empty()){
		Point curr = pq.top(); 
		pq.pop(); 
		if (mark[curr.ind]) continue; 
		mark[curr.ind] = true; 

		if ((curr.x == xb) || (curr.y == yb)){ //barn is in line of fire
			return curr.dist; 
		}
		REP(j, 0, N){
			if (!mark[x[j].ind] && ((x[j].x == curr.x) || (x[j].y == curr.y))) { //if mirror is unmarked and is in the line of fire
				Point temp = x[j]; 
				temp.dist += curr.dist; 
				pq.push(temp); 
			}
		}	
	}
	return -1; 
}

int main() {
	fin >> N >> xl >> yl >> xb >> yb; 
	REP(i, 0, N){
		int a, b; 
		fin >> a >> b; 
		Point temp = {a,b,i, 1}; 
		x[i] = temp; 
	}

	fout << Dijkstra() << endl; 
}