#include <iostream>
#include <sstream>

using namespace std;

int* MergeSort(int* a, int n);
int* Merge(int* b, int* c, int* a, int sB, int sC);

int* MergeSort(int* a, int n) {
    if (n > 1) {

        int* b = new int[n/2];
        int* c = new int[n - n/2];

        //copy half arr to b
        for (int i = 0; i < n/2; i++) {
            b[i] = a[i];
        }

        //copy remainder to c
        for (int j = 0; j < n - n/2; j++) {
            c[j] = a[j + n/2];
        }

        b = MergeSort(b, n/2);
        c = MergeSort(c, n - n/2);
        return Merge(b, c, a, n/2, n - n/2);
    }

    return a;
}

int* Merge(int* b, int* c, int* a, int sB, int sC) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < sB && j < sC) {
        if (b[i] <= c[j]) {
            a[k] = b[i];
            i++;
        } 
        
        else {
            a[k] = c[j];
            j++;
        }

        k++;
    }

    if (i == sB) {
        while (j < sC) {
            a[k] = c[j];
            k++;
            j++;
        }
    }

    else {
        while (i < sB) {
            a[k] = b[i];
            k++;
            i++;
        }
    }

    return a;
}

int main() {

    int cases;

    cin >> cases;

    for (int c = cases; c > 0; c--) {

        int sz;

        cin >> sz;
        cin.ignore();

        
        string input;
        getline(cin, input);
        
        int* a = new int[sz];
        stringstream ss(input);

        for (int i = 0; i < sz; i++) {
            ss >> a[i];
        }

        a = MergeSort(a, sz);

        for (int j = 0; j < sz; j++) {
            cout << a[j] << " ";
        }

        cout << endl;

        delete[] a;
    }

    return 0;
}