    #include <bits/stdc++.h>

    using namespace std;

    struct Point {
        int x, y;
    };

    void Diem_xa_O_nhat (Point a[], int n) {
        int max = 0;
        for (int i = 0; i < n; i++) {
            int r = pow (a[i].x, 2) + pow (a[i].y, 2);
            if (r > max) max = r;
        }
        for (int i = 0; i < n; i++) {
            int r = pow(a[i].x, 2) + pow(a[i].y, 2);
            if (r == max) {
                cout << "(" << a[i].x << "," << a[i].y << ")" << endl;
                break;
            }
        }
    }

    void D_max_2_diem (Point a[], int n) {
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = pow (a[j].x - a[i].x, 2) + pow (a[j].y - a[i].y, 2);
                if (d > max) max = d;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = pow (a[j].x - a[i].x, 2) + pow (a[j].y - a[i].y, 2);
                if (d == max) {
                    cout << "(" << a[i].x << "," << a[i].y << ")" << " " << "(" << a[j].x << "," << a[j].y << ")" << endl;
                    break;
                } 
            }
        }
    }

    void Y_max_of_point(Point a[], int n) {
    int max_y = a[0].y;
    vector<Point> v;

    // Tìm giá trị y lớn nhất
    for (int i = 1; i < n; i++) {
        if (a[i].y > max_y) {
            max_y = a[i].y;
        }
    }

    // Lọc các điểm có y bằng max_y
    for (int i = 0; i < n; i++) {
        if (a[i].y == max_y) {
            v.push_back(a[i]);
        }
    }

    if (v.size() == 1) {
        cout << "(" << v[0].x << ',' << v[0].y << ")";
    } else {
        int max_x = v[0].x;

        // Tìm giá trị x lớn nhất trong các điểm có y bằng max_y
        for (int i = 1; i < v.size(); i++) {
            if (v[i].x > max_x) {
                max_x = v[i].x;
            }
        }

        // In ra các điểm có x bằng max_x
        for (int i = 0; i < v.size(); i++) {
            if (v[i].x == max_x) {
                cout << "(" << v[i].x << ',' << v[i].y << ")";
            }
        }
    }
}

    int main () {
        Point a[1000];
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
        Diem_xa_O_nhat (a, n);
        D_max_2_diem (a, n);
        Y_max_of_point (a, n);
        return 0;
    }