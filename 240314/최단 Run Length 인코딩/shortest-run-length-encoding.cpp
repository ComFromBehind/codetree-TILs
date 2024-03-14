#include <iostream>
#include <string>
using namespace std;

string s;
string vec;
int ans=1e9;

void shift() {
    char temp = s[s.length() - 1];
    for (int i = s.length() - 1;i > 0;i--) {
        s[i] = s[i - 1];
    }
    s[0] = temp;
}

void counting() {
    int temp = 1;
    vec += s[0];
    for (int i = 1;i < s.length();i++) {
        if (s[i] == s[i - 1]) {
            temp++;
        }
        else {
            string tmp = to_string(temp);
            vec += tmp;
            vec += s[i];
            temp = 1;
            if (i == s.length() - 1) vec += to_string(1);
        }
    }
    if (temp != 1) {
        string tmp = to_string(temp);
        vec += tmp;
    }
    int candidate_ans = vec.length();
    ans = min(candidate_ans, ans);

}

int main() {

    cin >> s;



    for (int i = 0;i < s.length();i++) {
        vec.clear();
        shift();
        counting();
    }

    if (s.length() == 1)
        ans = 2;

    cout << ans;

    return 0;
}