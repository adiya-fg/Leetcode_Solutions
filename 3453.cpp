#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <climits>
#include <queue>
#include <map>
#include <unordered_map>
 
#define min(x,y) ((x<y) ? x : y)
#define max(x,y) ((x>y) ? x : y)

#define N 50001
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define INF 1000000000
 
using namespace std;


class Solution {
private:
    //create data list and sort that
    vector<vector<int>> points;
public:

    double Solver(double line) {
        //scan line by line
        //then clear and create new Segment tree for each lines

    }

    double separateSquares(vector<vector<int>>& squares) {
        double ans=0;
        points.clear();
        unordered_map<int,int> line_to_numX, line_to_numY;

        for(auto &data : squares) {
            int x1 = data[0];
            int x2 = data[0] + data[2];
            int y1 = data[1];
            int y2 = data[1] + data[2];
            if(line_to_numX.find(x1)==line_to_numX.end()) {
                line_to_numX[x1] = line_to_numX.size();
            }
            if(line_to_numX.find(x2)==line_to_numX.end()) {
                line_to_numX[x2] = line_to_numX.size();
            }
            if(line_to_numY.find(y1)==line_to_numY.end()) {
                line_to_numY[y1] = line_to_numY.size();
            }
            if(line_to_numY.find(y2)==line_to_numY.end()) {
                line_to_numY[y2] = line_to_numY.size();
            }
            vector<int> tempVector;
            tempVector.push_back(x2);
            tempVector.push_back(y2);
            tempVector.push_back(x1);
            tempVector.push_back(y1); 
            points.push_back(tempVector);
        }
        sort(points.begin(),points.end());

        double total = Solver(0);

        return ans;
    }
};