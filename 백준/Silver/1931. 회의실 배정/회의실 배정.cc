#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){


  int n;
  cin >> n;
  vector<pair<int,int>> meetings(n);
  
  for(int i=0; i<n; i++) cin>> meetings[i].second >> meetings[i].first ;
  
  sort(meetings.begin(), meetings.end());

  int count = 0;
  int last_end_time = 0;
  for(const auto& meeting : meetings){
    if(meeting.second >= last_end_time){
      last_end_time = meeting.first;
      count = count + 1;
    }
  }
  
  cout << count ;
}