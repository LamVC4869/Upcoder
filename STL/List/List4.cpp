#include <bits/stdc++.h>

using namespace std;

list<int> changeValue(list<int> l, int k, int x) {
    list<int>::iterator it = l.begin ();
    //dich con tro toi vi tri k
	advance (it, k - 1);
    *it = x;
    return l;
}

vector<int> verifyFunction(vector<int> v, int k, int x) {
	list<int> l(v.begin(), v.end());
	l = changeValue(l, k, x);
	vector<int> vec(l.begin(), l.end());
	return vec;
}