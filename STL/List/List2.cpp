#include <iostream>
#include <vector>
#include <list>

using namespace std;

int sumOfFirstAndLastElement (list<int> linkedList) {
   if (linkedList.empty ()) return -1;
   if (linkedList.size () == 1) return linkedList.front ();
   return linkedList.front () + linkedList.back ();
}

int verifyFunction (vector<int> v) {
	list<int> l(v.begin(), v.end());
	return sumOfFirstAndLastElement(l);
}

int main () {
    //...
    return 0;
}