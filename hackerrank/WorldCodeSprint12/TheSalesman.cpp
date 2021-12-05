#include <bits/stdc++.h>

using namespace std;

int minimumTime(vector <int> x) {
	//  Return the minimum time needed to visit all the houses.
	int maxX = x[0], minX = x[0];
	for(int l = 1;l < x.size();l++)
	{
		if(x[l] > maxX) maxX = x[l];
		else if(x[l] < minX) minX = x[l];
	}

	return maxX-minX;
}

int main() {
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; a0++){
		int n;
		cin >> n;
		vector<int> x(n);
		for(int x_i = 0; x_i < n; x_i++){
			cin >> x[x_i];
		}
		int result = minimumTime(x);
		cout << result << endl;
	}
	return 0;
}

