#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

#define N 2001

using namespace std;

struct Arrow {
    int x;
    int y;
    int index;
    char direction;
    Arrow * neighbors;
};

int check[N][N];
vector<Arrow*> adj[N*N];

int main() {
    int n,m; cin>>n>>m;

    string str;
    int index = 0;
    for(int i=0; i<n; i++) {
        cin>>str;
        for(int j=0; j<m; j++) {
            if(str[j]!='.') {
                Arrow * newArrow = new Arrow();
                newArrow->x = i;
                newArrow->y = j;
                newArrow->index  = index;
                newArrow->direction = str[j];
                // find neighbors of this arrow and add them to the list.
                // ...
                // add this arrow to the list of all arrows.
                // arrows[index++] = newArrow;
                if(j>0 && check[i][j-1]!=-1) {
                    // check left
                    adj[index++].push_back(check[i][j-1]);
                }
                check[i][j] = i*m + j;
            } else {
                // mark this cell as empty.
                // check[i][j] = -1;
                check[i][j] = (j==0) ? -1 : check[i][j-1];
            }
        }
    }

    int ans = 0;
    queue<Arrow*> Q;

    // find and target the first arrow.
    while(!Q.empty()) {
        int sz = Q.size();
        for(int i=0; i<sz; i++) {       
            Arrow * current = Q.front();
            Q.pop();
            ans++;
            // find the neighbors of this arrow and add them to the queue.
            for (size_t i = 0; i < count; i++)
            {
                /* code */
            }
            
        }
    }
    cout<<ans<<endl;
    return 0;
}
