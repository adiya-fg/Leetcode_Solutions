#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <unordered_map>

#define pb push_back

using namespace std;

struct DoubleLinkedList {
    int val;
    DoubleLinkedList * prev, * next;
};

unordered_map<int,pair<DoubleLinkedList*,DoubleLinkedList*>> mp;

int n;
int x,y;

int main() {

    cin>>n;
    int temp = n;
    while( temp-- ){
        cin>>x>>y;
        // x goes to front of y person.
        vector<DoubleLinkedList *> neighborsX = {nullptr,nullptr};
        if(mp.find(x)!=mp.end()) {
            neighborsX[0] = mp[x].first;
            neighborsX[1] = mp[x].second;
        }
        vector<DoubleLinkedList *> neighborsY = {nullptr,nullptr};
        if(mp.find(y)!=mp.end()) {
            neighborsY[0] = mp[y].first;
            neighborsY[1] = mp[y].second;
        }
    }

    // answer to these queries.
    int Q; cin>>Q;
    string qStr;
    int val;
    while(Q--){
        cin>>qStr>>val;
        cout<<val<<endl;
    }

    return 0;
}

/*
2
6 3
9 6
8
L 1
L 2
L 3
L 4
P 1
P 2
P 3
P 4
*/