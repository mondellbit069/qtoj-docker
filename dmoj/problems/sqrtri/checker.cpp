#include "testlib.h"
#include <cmath>

bool isPerfectSquare(int x) {
    int root = round(sqrt(x));
    return root * root == x;
}

bool isValid(int a, int b, int c, int L, int R) {
    return L <= a && a < b && b < c && c <= R && isPerfectSquare(a + b) && isPerfectSquare(b + c) && isPerfectSquare(c + a);
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int T = inf.readInt();
    for (int t = 0; t < T; ++t) {
        int L = inf.readInt();
        int R = inf.readInt();

        int a = ouf.readInt(-1, R);
        int b = ouf.readInt(-1, R);
        int c = ouf.readInt(-1, R);

        int ja = ans.readInt(-1, R);
        int jb = ans.readInt(-1, R);
        int jc = ans.readInt(-1, R);

        if (ja == -1 && jb == -1 && jc == -1) {
            if (a != -1 || b != -1 || c != -1) {
                quitf(_wa, "The output is not -1 -1 -1, but the judge's answer is -1 -1 -1");
            }
            continue;
        }

        // if (a != ja || b != jb || c != jc) {
        //     quitf(_wa, "The output does not match the judge's answer");
        // }

        if (!isValid(a, b, c, L, R)) {
            quitf(_wa, "The numbers do not satisfy the conditions");
        }
    }

    quitf(_ok, "The output is valid");
}
