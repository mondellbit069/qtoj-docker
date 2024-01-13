#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;

void move(int &x, int &y, char direction) {
    if (direction == 'L') y--;
    else if (direction == 'R') y++;
    else if (direction == 'U') x--;
    else if (direction == 'D') x++;
}

bool inside(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int calculateXorSum(const string &path) {
    int x = 0, y = 0;
    int xorSum = a[x][y];
    for (char direction : path) {
        move(x, y, direction);
        if (!inside(x, y)) quitf(_wa, "The snake moves outside of the grid");
        xorSum ^= a[x][y];
    }
    if (x != n - 1 || y != n - 1) quitf(_wa, "The snake does not end at the bottom right cell");
    return xorSum;
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    n = inf.readInt();
    a = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = inf.readInt();

    string ja = ans.readToken(); // đọc chuỗi từ output mẫu
    string pa = ouf.readToken(); // đọc chuỗi từ output của người nộp bài

    // Kiểm tra xem chuỗi output của người nộp bài có quá dài không
    if (pa.size() > 5e6) {
        quitf(_wa, "Output is too long");
    }

    // Kiểm tra xem chuỗi output của người nộp bài có chứa ký tự không hợp lệ không
    for (char c : pa) {
        if (c != 'L' && c != 'R' && c != 'U' && c != 'D') {
            quitf(_wa, "Output contains invalid characters");
        }
    }

    // Tính toán tổng xor trên đường đi của output mẫu và output của người nộp bài
    int jaXorSum = calculateXorSum(ja);
    int paXorSum = calculateXorSum(pa);

    // So sánh tổng xor của output mẫu và output của người nộp bài
    if (jaXorSum > paXorSum) {
        quitf(_wa, "The xor sum of the participant's path is not optimal");
    }

    quitf(_ok, "The output is valid and optimal");
}
