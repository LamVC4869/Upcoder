#include <iostream>

using namespace std;

int main(){
    int N, M;
    cin >> N;
    cin >> M;
    int zigzagArray[N][M];
    int value = 1;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            // Đi từ trái sang phải
            for (int j = 0; j < M; ++j) {
                zigzagArray[i][j] = value++;
            }
        } else {
            // Đi từ phải sang trái
            for (int j = M - 1; j >= 0; --j) {
                zigzagArray[i][j] = value++;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << zigzagArray[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
