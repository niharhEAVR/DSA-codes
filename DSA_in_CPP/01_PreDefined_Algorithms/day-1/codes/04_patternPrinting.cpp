#include <iostream>
using namespace std;

/* 1. Increasing consecutive numbers per row */
void pattern1() {
    int num = 0;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            cout << ++num << " ";
        }
        num = i;
        cout << endl;
    }
}

/* 2. Reverse numbers per row */
void pattern2() {
    for (int i = 1; i <= 5; i++) {
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << endl;
    }
}

/* 3. Same alphabet in a row */
void pattern3() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            cout << char('a' + i) << " ";
        }
        cout << endl;
    }
}

/* 4. Alphabet shifting pattern */
void pattern4() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << char('a' + i + j) << " ";
        }
        cout << endl;
    }
}

/* 5. Reverse alphabet triangle */
void pattern5() {
    for (int i = 0; i < 5; i++) {
        char ch = 'A' + 4 - i;
        for (int j = 0; j <= i; j++) {
            cout << ch++ << " ";
        }
        cout << endl;
    }
}

/* 6. Number-star mirror pattern */
void pattern6() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 6 - i; j++)
            cout << j << " ";

        for (int j = 1; j < i; j++)
            cout << "* ";

        for (int j = 1; j < i; j++)
            cout << "* ";

        for (int j = 6 - i; j >= 1; j--)
            cout << j << " ";

        cout << endl;
    }
}

/* 7. Right aligned inverted stars */
void pattern7() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j < i; j++)
            cout << "  ";
        for (int j = 1; j <= 6 - i; j++)
            cout << "* ";
        cout << endl;
    }
}

/* 8. Right aligned star triangle */
void pattern8(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + j <= n)
                cout << "  ";
            else
                cout << "* ";
        }
        cout << endl;
    }
}

/* 9. Continuous alphabet triangle */
void pattern9(int n) {
    int ch = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << char('A' + ch - 1) << " ";
            ch++;
        }
        cout << endl;
    }
}

/* 10. Center aligned star pyramid */
void pattern10(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + j <= n)
                cout << " ";
            else
                cout << "* ";
        }
        cout << endl;
    }
}

/* 11. Number palindrome pyramid */
void pattern11() {
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5 - i; j++)
            cout << "  ";
        for (int j = 1; j <= i; j++)
            cout << j << " ";
        for (int j = i - 1; j >= 1; j--)
            cout << j << " ";
        cout << endl;
    }
}

/* 12. Diamond star pattern */
void pattern12(int n) {
    for (int i = 1; i <= (2 * n - 1); i++) {
        int stars = (i <= n) ? i : (2 * n - i);
        for (int j = 1; j <= stars; j++)
            cout << "* ";
        cout << endl;
    }
}

/* 13. Heart pattern */
void pattern13(int n) {
    for (int i = n / 2; i <= n; i += 2) {
        for (int j = 1; j < n - i; j += 2)
            cout << " ";
        for (int j = 1; j <= i; j++)
            cout << "*";
        for (int j = 1; j <= n - i; j++)
            cout << " ";
        for (int j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }

    for (int i = n; i >= 1; i--) {
        for (int j = i; j < n; j++)
            cout << " ";
        for (int j = 1; j <= (2 * i - 1); j++)
            cout << "*";
        cout << endl;
    }
}

/* 14. Number triangle right aligned */
void pattern14(int n) {
    int k = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + j <= n)
                cout << "  ";
            else
                cout << k++ << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    pattern1();
    cout << endl;

    pattern2();
    cout << endl;

    pattern3();
    cout << endl;

    pattern4();
    cout << endl;

    pattern5();
    cout << endl;

    pattern6();
    cout << endl;

    pattern7();
    cout << endl;

    pattern8(n);
    cout << endl;

    pattern9(n);
    cout << endl;

    pattern10(n);
    cout << endl;

    pattern11();
    cout << endl;

    pattern12(n);
    cout << endl;

    pattern13(n);
    cout << endl;

    pattern14(n);

    return 0;
}
