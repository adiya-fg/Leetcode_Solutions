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
    int data;
    int rootLoc;
    DoubleLinkedList * prev;
    DoubleLinkedList * next;
    DoubleLinkedList(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
        rootLoc = 0;
    }
};

unordered_map<int,DoubleLinkedList*> prevElem, nextElem;
unordered_map<int,DoubleLinkedList*> mapToRoot;
unordered_set<DoubleLinkedList*> allLists;

int n;
int x,y;

void removeCurrent(vector<DoubleLinkedList *> neighbors) {
    // case: TT

    //////////////


}

int main() {

    cin>>n;
    int temp = n;
    while( temp-- ){
        cin>>x>>y;

        // find X's location and remove it from old position.
        vector<DoubleLinkedList *> personX = {nullptr,nullptr};
        if(prevElem.find(x)!=prevElem.end()) {
            personX[0] = prevElem[x];        
        }
        if(nextElem.find(x)!=nextElem.end()) {
            personX[1] = nextElem[x];        
        }
        DoubleLinkedList * newRoot;
        DoubleLinkedList * newTail;
        // create new linked list
        if(personX[0]==nullptr) {
            newRoot = new DoubleLinkedList(x-1);
            if(personX[1]==nullptr) {
                newTail = new DoubleLinkedList(x+1);
            } else {
                newTail = personX[1];
            }
            newRoot ->next = newTail;
            newTail -> prev = newRoot;
            allLists.insert(newRoot);
        } else {
            //update already created a linked list.
            newRoot = personX[0];
            newTail = personX[1];
            // find next element of it and connect them.
            if(newTail==nullptr) {

            } else{
                newRoot ->next = newTail;
                newTail -> prev = newRoot;                
            }
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