#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

#define pb push_back

using namespace std;

struct DoubleLinkedList {
    int val;
    DoubleLinkedList * prev, * next;
};

unordered_map<int,pair<DoubleLinkedList*,DoubleLinkedList*>> mp;
unordered_map<int,DoubleLinkedList*> mapToRoot;
unordered_set<DoubleLinkedList*> allLists;

int n;
int x,y;

int main() {

    cin>>n;
    int temp = n;
    while( temp-- ){
        cin>>x>>y;
        // x goes to front of y person.
        // find x and remove it from old position.
        vector<DoubleLinkedList *> personX = {nullptr,nullptr};
        if(mp.find(x)!=mp.end()) {
            personX[0] = mp[x].first;
            personX[1] = mp[x].second;
        }
        // find the current position of y and the add x to front of it.
        vector<DoubleLinkedList *> personY = {nullptr,nullptr};
        if(mp.find(y)!=mp.end()) {
            personY[0] = mp[y].first;
            personY[1] = mp[y].second;
        }
    }

    // answer to these queries.
    int Q; cin>>Q;
    string qStr;
    int val;
    while(Q--){
        cin>>qStr>>val;
        ///find position of the person 
        if(qStr[0]=='P') {

        } else {

        }
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