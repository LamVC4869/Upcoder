#include <bits/stdc++.h>

using namespace std;

list<int> deleteFrontBack(list<int> l) {
	//xoa phan tu dau
	l.pop_front ();
	//xoa phan tu cuoi
    l.pop_back ();
    return l;
}

vector<int> verifyFunction(vector<int> v) {
	list<int> l(v.begin(), v.end());
	l = deleteFrontBack(l);
	vector<int> ans(l.begin(), l.end());
	return ans;
}