#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n,mean,median,modus;
    int hitung = 0;
    int hitungTemp;
    int modusTemp;
    vector<int> arr;
 
    cin >> n;
    if (n > 0) {
        int elmt;
        for (int i = 0; i < n; i++) {
            cin >> elmt;
            arr.push_back(elmt);
        }
    }
 
    // mean
    if (n <= 0) {
        cout << "-" << endl;
    }
    else {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        cout << (float)sum / n << endl;
    }
 
    // median
    if (n <= 0) {
        cout << "-" << endl;
    }
    else {
        vector<int> arr2(arr);
        sort(arr2.begin(),arr2.end());
        if (n % 2 == 1) {
            cout << arr2[n/2] << endl;
        }
        else {
            cout << (float)(arr2[(n/2)-1] + arr2[(n/2)]) / 2 << endl;
        }
    }
 
    // modus
    if (n <= 0) {
        cout << "-" << endl;
    }
    else {
        hitung = count(arr.begin(),arr.end(),arr[0]);
        modus = arr[0];
        for (int i = 1; i < n; i++) {
            modusTemp = arr[i];
            hitungTemp = count(arr.begin(),arr.end(),arr[i]);
            if (hitungTemp > hitung) {
                modus = arr[i];
                hitung = hitungTemp;
            }
            else if (hitungTemp == hitung) {
                if (modusTemp < modus) {
                    modus = modusTemp;
                }
            }
        }
        cout << modus << endl;
    }
 
    // push_back modus
    if (n <= 0) {
        cout << "-" << endl;
    }
    else {
        for (int i = 0; i < hitung; i++) {
            arr.push_back(modus);
        }
        for (int i = 0; i < arr.size()-1; i++) {
            cout << arr[i] << " ";
        }
        cout << arr[arr.size()-1] << endl;
    }
 
    // arr size
    if (n <= 0) {
        cout << 0 << endl;
    }
    else {
        cout << arr.size() << endl;
    }
    return 0;
}
