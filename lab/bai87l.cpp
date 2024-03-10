#include <iostream>

using namespace std;

struct Team {
    string name;
    int like, comment, share;
};

int point (Team a) {
    return a.like + a.comment * 2 + a.share * 3;
}

void Sort (Team arr[], int count) {
    Team a;
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (point (arr[i]) < point (arr[j])) {
                a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
}

void output (Team arr[]) {
    cout << arr[0].name << endl << arr[1].name << endl << arr[2].name;
}

int main () {
    Team arr[1000];
    int count = 0;
    while (true) {
        Team a;
        cin >> a.name >> a.like >> a.comment >> a.share;
        if (a.name == "000") {
            break;
        }
        arr[count] = a;
        count++;
    }
    Sort (arr, count);
    output (arr);
    return 0;
}