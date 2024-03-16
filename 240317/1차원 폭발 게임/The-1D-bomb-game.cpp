#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v{ 101 };
vector<int> vv;
vector<int> w;
int arr[101];

void vector_input() { // 실제 값을 가진 배열만 v로 넘어감..  w에는 중복에 대한 카운팅 정보가 담김.
   
    w.clear();

    int temp = v.size();

    v.clear();

    w.push_back(0); //w에는 index가 담김.
    for (int i = 0;i < temp;i++) {
        if (arr[i] != 0) {
            v.push_back(arr[i]);
            if (v.size() > 1 && v[v.size() - 1] != v[v.size() - 2]) {
                w.push_back(v.size()-1);
            }
        }
    }
    if (v.size() > 1 && v[v.size() - 1] == v[v.size() - 2]) {
        w.push_back(v.size());
    }
}

int counting() { //v -> 실제 배열, w -> 중복에 대한 index
    
    int temp = 0;

    for (vector<int>::iterator it = w.begin() + 1;it != w.end();it++) {
        if (*it - *(it - 1) >= m) {
            temp++;
            for (int i = *(it - 1);i < *it;i++) {
                v[i] = 0;
            }
        }
    }

    v.erase(remove(v.begin(), v.end(), 0), v.end());

    for (int i = 0;i < v.size();i++) {
        arr[i] = v[i];
    }

    if (temp != 0) return 1;
    else return 0;
}

int main() {
    
    cin >> n >> m;

    if (m == 1)
    {
        cout << 0;
        exit(0);
    }

    int cnt = 0;

    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }

    v.resize(n);

    vector_input();
    
    int c = counting();
    
    if (c == 0){
        cout << v.size()<<"\n";
        for (int i = 0;i < v.size();i++) {
            cout << v[i] << "\n";
        }
        exit(0);
    }
    
    while (c != 0) {
        if (c == 0) {
            break;
        }
        else {
            vector_input();
            c = counting();
        }
    }
    
    cout << v.size()<<"\n";
    for (int i = 0;i < v.size();i++) {
        cout << v[i] << "\n";
    }


}