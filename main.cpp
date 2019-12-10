#include <bits/stdc++.h>

using namespace std;

struct drib {
    unsigned long int a;
    unsigned long int b;
};

drib multiply_drib_by(drib d, unsigned long int a, unsigned long int b) {
    d.a *= a;
    d.b *= b;
    unsigned long int m = max(d.a, d.b);
    while (m > 0) {
        if (!(d.a % m) && !(d.b % m)) {
            d.a = d.a / m;
            d.b = d.b / m;
        }
        m--;
    };
    return d;
};

void swap(unsigned long int* a, unsigned long int* b) {
    unsigned long int temp = *a;
    *a = *b;
    *b = temp;
};

void my_sort(unsigned long int* arr, unsigned long int n) {
    // bubblesort from https://www.geeksforgeeks.org/bubble-sort/
    unsigned long int i, j;
    for (i = 0; i < n-1; i++) {
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr + j, arr + (j+1));
            };
        };
    };
};

bool next_permutation(unsigned long int* arr, unsigned long int n) {
    if (n > 1) {
        unsigned long int j, i, min_i;
        for (j = n - 2; (arr[j] >= arr[j + 1]); j--) {
            if (j == 0) {
                return false;
            };
        };
        min_i = j + 1;
        for (i = j + 1; i < n; i++) {
            if ((arr[i] < arr[min_i]) && (arr[i] > arr[j])) {
                min_i = i;
            };
        };
        swap(arr + j, arr + min_i);
        my_sort(arr + (j + 1), n - (j + 1));
        return true;
    }
    else {
        return false;
    };
};

void print_array(unsigned long int* arr, unsigned long int n, unsigned long int counter) {
    cout << "Permutation " << counter << ": [";
    if (n > 0) {
        cout << arr[0];
        for (unsigned long int i = 1; i < n; i++) {
            cout << ", " << arr[i];
        };
    }
    cout << "]" << endl;
};

void print_binom(unsigned long int n) {
    unsigned long int k;
    drib c = {1, 1};
    for (k = 0; k < n; k++) {
        cout << "(" << c.a << "/" << c.b << ")";
        cout << "*(a^" << k << ")*(b^" << (n - k) << ")";
        cout << " + ";

        c = multiply_drib_by(c, n - k, k + 1);
    };

    cout << "(" << c.a << "/" << c.b << ")";
    cout << "*(a^" << k << ")*(b^" << (n - k) << ")";
    cout << endl;
};

int main() {
    unsigned long int i, n;
    do {
        cout << "Enter n=";
        cin >> n;
    } while (n == 0);
    // 1 2 3 4 5 6 7 8 9 10
    // ...
    // 10 9 8 7 6 5 4 3 2 1
    unsigned long int* a = (unsigned long int*)calloc(n, sizeof(unsigned long int));
    for (i = 0; i < n; i++) {
        a[i] = i + 1;
    };

    unsigned long int counter = 0;
    do {
        counter++;
        print_array(a, n, counter);
    } while (next_permutation(a, n));

    free(a);

    cout << endl << "(a + b)^10 = ";
    print_binom(10);

    return 0;
};
