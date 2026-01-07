#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include <algorithm>

struct Member {
    int age;
    string name;
};

bool compare(const Member& a, const Member& b) {
    return a.age < b.age; // 나이가 적은 순(오름차순)
}

int main(){
    int N;
    cin >> N;
    vector<Member> members(N);
    vector<string> time_table;

    for(int i=0; i<N; i++){
        cin >> members[i].age >> members[i].name;
    }

    stable_sort(members.begin(), members.end(), compare);
    for(int i=0; i<N; i++) cout << members[i].age << " " << members[i].name << "\n";
    return 0;
}