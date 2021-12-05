#include <bits/stdc++.h>

#define MAXSIDE 200
#define INF 201
#define MARKED 2
#define UNVISITED 0
#define VISITED 1

enum MOVE {R, L, UL, UR, LL, LR};

using namespace std;

unsigned char visited[MAXSIDE][MAXSIDE];
unsigned char chessBoard[MAXSIDE][MAXSIDE];
unsigned char pathTrace[MAXSIDE][MAXSIDE];

void printPath(int i_start, int j_start, int i_end, int j_end)
{
	if(i_start == i_end && j_start == j_end) return;

	if(pathTrace[i_end][j_end] == R) {
		printPath(i_start, j_start, i_end, j_end-2);
		cout<<"R ";
	}
	else if(pathTrace[i_end][j_end] == L) {
		printPath(i_start, j_start, i_end, j_end+2);
		cout<<"L ";
	}
	else if(pathTrace[i_end][j_end] == UL) {
		printPath(i_start, j_start, i_end+2, j_end+1);
		cout<<"UL ";
	}
	else if(pathTrace[i_end][j_end] == UR) {
		printPath(i_start, j_start, i_end+2, j_end-1);
		cout<<"UR ";
	}
	else if(pathTrace[i_end][j_end] == LL) {
		printPath(i_start, j_start, i_end-2, j_end+1);
		cout<<"LL ";
	}
	else if(pathTrace[i_end][j_end] == LR) {
		printPath(i_start, j_start, i_end-2, j_end-1);
		cout<<"LR ";
	}
}

void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    //  Print the distance along with the sequence of moves.
    for(int l = 0;l < n;l++)
    {
        for(int l1 = 0;l1 < n;l1++) chessBoard[l][l1] = INF, pathTrace[l][l1] = 0, visited[l][l1] = UNVISITED;
    }
    
    queue<int> qX, qY;
    qX.push(i_start), qY.push(j_start);
	chessBoard[i_start][j_start] = 0;	    

    while(!qX.empty())
    {
        int x = qX.front(), y = qY.front();
		qX.pop(), qY.pop();

		visited[x][y] = VISITED;
		
		if(y-1 >= 0 && x-2 >= 0 && visited[x-2][y-1] == UNVISITED) {
			qX.push(x-2), qY.push(y-1);
			visited[x-2][y-1] = MARKED;
			pathTrace[x-2][y-1] = UL;
			chessBoard[x-2][y-1] = chessBoard[x][y] + 1;
		}

		if(y+1 < n && x-2 >= 0 && visited[x-2][y+1] == UNVISITED) {
			qX.push(x-2), qY.push(y+1);
			visited[x-2][y+1] = MARKED;
			pathTrace[x-2][y+1] = UR;
			chessBoard[x-2][y+1] = chessBoard[x][y] + 1;
		}

		if(y+2 < n && visited[x][y+2] == UNVISITED) {
			qX.push(x), qY.push(y+2);
			visited[x][y+2] = MARKED;
			pathTrace[x][y+2] = R;
			chessBoard[x][y+2] = chessBoard[x][y] + 1;
		}

		if(y+1 < n && x+2 < n && visited[x+2][y+1] == UNVISITED) {
			qX.push(x+2), qY.push(y+1);
			visited[x+2][y+1] = MARKED;
			pathTrace[x+2][y+1] = LR;
			chessBoard[x+2][y+1] = chessBoard[x][y] + 1;
		}


		if(y-1 >= 0 && x+2 < n && visited[x+2][y-1] == UNVISITED) {
			qX.push(x+2), qY.push(y-1);
			visited[x+2][y-1] = MARKED;
			pathTrace[x+2][y-1] = LL;
			chessBoard[x+2][y-1] = chessBoard[x][y] + 1;
		}

		if(y-2 >= 0 && visited[x][y-2] == UNVISITED) {
			qX.push(x), qY.push(y-2);
			visited[x][y-2] = MARKED;
			pathTrace[x][y-2] = L;
			chessBoard[x][y-2] = chessBoard[x][y] + 1;
		}

	}

	if(chessBoard[i_end][j_end] == INF) cout<<"Impossible"<<endl;
	else {
		cout<<(int)chessBoard[i_end][j_end]<<endl;
		printPath(i_start, j_start, i_end, j_end);
		cout<<endl;
	}
}

int main() {
    int n;
    cin >> n;
    int i_start;
    int j_start;
    int i_end;
    int j_end;
    cin >> i_start >> j_start >> i_end >> j_end;
    printShortestPath(n, i_start, j_start, i_end, j_end);
    return 0;
}
