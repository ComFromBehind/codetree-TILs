#include <iostream>
#include <utility>
#include <vector>
#include <tuple>
#include <map>
using namespace std;

int t, n;



int row;
int col;
char dir;
int weight;
int intdir;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


map<pair<int, int>, pair<int, int>> m;


pair<int, int> vlist[101];
pair<int, int> wlist[101];
int dir_arr[101];
int wei_arr[101];

int trans_dir(char a) {
    if (a == 'L') return 2;
    if (a == 'R') return 0;
    if (a == 'D') return 3;
    if (a == 'U') return 1;
}

void vlist_clear() {
    for (int i = 0;i <= 100;i++) {
        vlist[i] = { -1,-1 };
        dir_arr[i] = -1;
    }
}


vector<int> indexlist;
vector<int> eraser;

//void print() {
//    for (int i = 0;i < n;i++) {
//        (dir_arr[i] == -1) ? cout << "0" : cout << "1";
//        cout << "\n";
//        cout << vlist[i].first << " " << vlist[i].second << " " << "\n";
//    }
//}

int flag = 0;
int ans = 0;
int sz;

void print() {
    for (int i = 0;i < indexlist.size();i++) {
        cout << vlist[indexlist[i]].first << " " << vlist[indexlist[i]].second << " " << wei_arr[indexlist[i]] << "\n";
    }
}

int main() {

  

    cin >> t;
    int cnt = 0;
    while (t--) {
        cin >> n;
        cnt++;
        ans = 0;
        flag = 0;

        //초기화 공부해볼것..
        vlist_clear();

        indexlist.clear();

        for (int i = 0;i < n;i++) { //ball 등록과정
            cin >> row >> col >> weight >> dir;
            row += 1001;
            col += 1001;
            vlist[i] = { row - 1,col - 1 };
            wei_arr[i] = weight;
            wlist[i] = vlist[i];
            intdir = trans_dir(dir);
            dir_arr[i] = intdir;
            indexlist.push_back(i);
        }
        
        
        
        int max_t = 2002;
        int timer = 1;

        while (max_t--) {
            flag = 0;

            sz = indexlist.size();
            for (int i = 0; i < sz;i++) {
                wlist[indexlist[i]] = vlist[indexlist[i]];
            }
            //for(int i=0;i<sz;i++)


            eraser.clear();
            for (int i = 0;i < sz;i++) {

                row = vlist[indexlist[i]].first;
                col = vlist[indexlist[i]].second;

                if (row < 0 || row>2000 || col < 0 || col>2000) {


                    eraser.push_back(i);
                    continue;
                }

                intdir = dir_arr[indexlist[i]];
                weight = wei_arr[indexlist[i]];
                vlist[indexlist[i]] = { row + dx[intdir], col + dy[intdir] };
            }

            for (int i = eraser.size() - 1;i >= 0;i--) {
                indexlist.erase(indexlist.begin() + eraser[i]);
            }

            sz = indexlist.size();
            eraser.clear();

            for (int i = 0;i < sz;i++) {
                row = vlist[indexlist[i]].first;
                col = vlist[indexlist[i]].second;

                int bef_row = wlist[indexlist[i]].first;
                int bef_col = wlist[indexlist[i]].second;

                for (int j = i;j < sz;j++) {
                    if (j == i) continue;
                    if (wlist[indexlist[j]] == vlist[indexlist[i]]) {
                        if (wlist[indexlist[i]] == vlist[indexlist[j]]) {
                            
                            if (wei_arr[indexlist[i]] > wei_arr[indexlist[j]]) {
                                eraser.push_back(j);
                            }
                            else if (wei_arr[indexlist[i]] < wei_arr[indexlist[j]]) {
                                eraser.push_back(i); 
                            }
                            else {
                                eraser.push_back(i); 
                            }
                            flag = 1;
                            
                            
                          
                            ans = timer;
                        }
                    }
                }
            }

            for (int i = eraser.size() - 1;i >= 0;i--) {
                indexlist.erase(indexlist.begin() + eraser[i]);
            }

            sz = indexlist.size();
            eraser.clear();
            flag = 0;
            timer++;
            m.clear();
            
            
    

            for (int i = 0;i < sz; i++) {

               
                row = wlist[indexlist[i]].first;
                col = wlist[indexlist[i]].second;
                intdir = dir_arr[indexlist[i]];
                weight = wei_arr[indexlist[i]];
                vlist[indexlist[i]] = { row + dx[intdir], col + dy[intdir] };
                row = row + dx[intdir];
                col = col + dy[intdir];

                auto it = m.find({ row,col });
                
                if (it == m.end()) {
                    m.insert({ {row,col},{wei_arr[indexlist[i]],i} });
                    
                }
                else {
                    pair<int, int> temp = it->second;
                    if (temp.first > wei_arr[indexlist[i]]) {
                        
                        eraser.push_back(i);
                       

                    }
                    else {
                        
                        eraser.push_back(temp.second);
                        m[{row, col}] = { wei_arr[indexlist[i]],i };
                        
                    }
                    flag = 1;
                    
                   

                }
                

            }
            

            for (int i = eraser.size()-1;i >=0;i--) {
                indexlist.erase(indexlist.begin() + eraser[i]);
            }
          
            if (flag == 1) {
                ans = timer;

            }
            timer++;


        }

        if (ans == 0) {
            cout << -1 << "\n";
        }
        else cout << ans << "\n";
    }
}