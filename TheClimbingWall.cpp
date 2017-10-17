//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <cmath>
#include <queue>

using namespace std;
typedef pair<double, double> pii;
pii hold[10001];
bool step[10001];

int main()
{
    queue<int> holds, steps;
    int h, f;
    int i, j;
    
    cin >> h >> f;
    for(i=1;i<=f;i++){
        cin >> hold[i].first >> hold[i].second;
        if(hold[i].second<=1000)
            holds.push(i), steps.push(1);
    }
    
    while(!holds.empty()){
        int po=holds.front(), s=steps.front();
        holds.pop(), steps.pop();
        for(i=1;i<=f;i++)
            if(sqrt((hold[i].first-hold[po].first)*(hold[i].first-hold[po].first)+(hold[i].second-hold[po].second)*(hold[i].second-hold[po].second))<=1000 && step[i]==false){
                step[i]=true, holds.push(i), steps.push(s+1);
                if(hold[i].second>=h-1000){
                    cout << s+1 << endl;
                    return 0;
                }
            }
    }
    
    return 0;
}
