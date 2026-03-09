#include <iostream>
using namespace std;


// * 
// * * 
// * * * 
// * * * * 
// * * * * *
/* 1. Star Increasing Triangle */
void pattern1(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            cout << "* ";
        cout << endl;
    }
}

// 1 
// 1 2 
// 1 2 3 
// 1 2 3 4 
// 1 2 3 4 5
/* 2. Number Increasing Triangle */
void pattern2(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }
}


// * * * * *
// * * * *
// * * *
// * *
// *
/* 3. Star Decreasing Triangle */
void pattern3(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++)
            cout << "* ";
        cout << endl;
    }
}

// 1 2 3 4 5
// 1 2 3 4
// 1 2 3
// 1 2
// 1
/* 4. Number Decreasing Triangle */
void pattern4(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }
}

// 1
// 2 2
// 3 3 3
// 4 4 4 4
// 5 5 5 5 5
/* 5. Same Number in Each Row */
void pattern5(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            cout << i << " ";
        cout << endl;
    }
}

// A
// B B
// C C C
// D D D D
// E E E E E
    // hard
/* 6. Capital Letters Pattern */
void pattern6(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            cout << char('A' + i - 1) << " ";
        cout << endl;
    }
}

// a
// a b
// a b c
// a b c d
// a b c d e
/* 7. Small Letters Pattern */
void pattern7(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            cout << char('a' + j - 1) << " ";
        cout << endl;
    }
}

// * * * * *
// *       *
// *       *
// *       *
// * * * * *
    // trick 
/* 8. Hollow Square */
void pattern8(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 || i == n || j == 1 || j == n)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }
}

// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
/* 9. Floyd’s Triangle */
void pattern9(int n) {
    int k = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            cout << k++ << " ";
        cout << endl;
    }
}

//     1
//    2 2
//   3 3 3
//  4 4 4 4
// 5 5 5 5 5
    // hard
/* 10. Right-Aligned Same Number Triangle */
void pattern10(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + j <= n)
                cout << " ";
            else
                cout << i << " ";
        }
        cout << endl;
    }
}


// 1
// 13
// 135
// 1357
// 13579
/* 11. Odd Number Pattern */
void pattern11(int n) {
    for (int i = 1; i <= n; i++) {
        int num = 1;
        for (int j = 1; j <= i; j++) {
            cout << num;
            num += 2;
        }
        cout << endl;
    }
}


//         1
//       2 1 2
//     3 2 1 2 3
//   4 3 2 1 2 3 4
// 5 4 3 2 1 2 3 4 5
    // hard
/* 12. Pyramid Number Pattern */
void pattern12(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 2 * (n - i); j++)
            cout << " ";
        for (int j = i; j >= 1; j--)
            cout << j << " ";
        for (int j = 2; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }
}

int main() {
    int choice, n;

    cout << "Enter number of rows: ";
    cin >> n;

    cout << "\nChoose Pattern (1 - 12): ";
    cin >> choice;

    cout << endl;

    switch (choice) {
        case 1: pattern1(n); break;
        case 2: pattern2(n); break;
        case 3: pattern3(n); break;
        case 4: pattern4(n); break;
        case 5: pattern5(n); break;
        case 6: pattern6(n); break;
        case 7: pattern7(n); break;
        case 8: pattern8(n); break;
        case 9: pattern9(n); break;
        case 10: pattern10(n); break;
        case 11: pattern11(n); break;
        case 12: pattern12(n); break;
        default: cout << "Invalid choice!";
    }

    return 0;
}
