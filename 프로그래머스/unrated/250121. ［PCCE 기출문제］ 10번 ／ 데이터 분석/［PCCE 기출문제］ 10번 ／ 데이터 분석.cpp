#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int s;

bool cmp(const vector<int>&a,const vector<int>&b){
    return a[s] < b[s];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    if(ext == "code")
        s = 0;
    else if(ext == "date")
        s = 1;
    else if(ext == "maximum")
        s = 2;
    else if(ext == "remain")
        s = 3;
    cout << s;
    for(int i=0;i<data.size();i++)
    {
        if(data[i][s]<val_ext)
            answer.push_back(data[i]); // 기준에 맞는 데이터 삽입
    }

    // 정렬 기준 설정
    if(sort_by=="code")
        s = 0;
    else if(sort_by == "date")
        s = 1;
    else if(sort_by == "maximum")
        s = 2;
    else if(sort_by == "remain")
        s = 3;

    sort(answer.begin(),answer.end(),cmp);
    return answer;
        
}

