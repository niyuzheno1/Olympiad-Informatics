/*GPL Lisence 
Status: Accepted
*/
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;

int maps[1010][1010], r, c;
vector<string> go;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

bool withinrange(int x, int y){
	return (x<r) && (y  <c) && x >= 0 && y >=0; 
}

void flood(int x, int y){
	queue<pii> qp;
	qp.push(make_pair(x,y));
	while(!qp.empty()){
		pii tmp = qp.front();
		int nx = tmp.first;
		int ny = tmp.second;
		qp.pop();
		for(int i = 0; i < 4;++i){
			int ux = nx + dx[i];
			int uy = ny + dy[i];
			if(withinrange(ux,uy) && maps[ux][uy] == -1&& go[ux][uy] == go[nx][ny])
			{
				maps[ux][uy] = maps[nx][ny];
				qp.push(make_pair(ux,uy));
			}
		}
	}
}

map<char, string> typeuser;

int main() {
	typeuser['0'] = "binary";
	typeuser['1'] = "decimal";
	cin >> r >> c;
	for(int i = 0; i < r; ++i){
		string tmp;
		cin >> tmp;
		go.push_back(tmp);
	}
	memset(maps,0xff, sizeof(maps));
	int id = 0;
	for(int i = 0; i <r; ++i){
		for(int j = 0; j < c; ++ j)
		if(maps[i][j] == -1){
			maps[i][j] = id;
			flood(i,j);
			++id;
		}
	}
	int n;
	cin>>n;
	for(int i = 0; i < n;++i){
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		--r1; --c1; --r2; --c2;
		if(maps[r1][c1] == maps[r2][c2]){
			cout<<typeuser[go[r1][c1]]<<endl;
		}else{
			cout<<"neither"<<endl;
		}
	
	}
	// your code goes here
	return 0;
}
