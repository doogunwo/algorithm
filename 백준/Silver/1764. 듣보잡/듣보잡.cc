	#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
 
int main(){
    
    int N, M; cin >> N >> M;
    string str1 = "";
    unordered_map<string, int> umap;
    vector<string> ansVec;
    for(int i = 0; i<N; i++){
        cin >> str1;
        umap[str1] = 0;
    }
    string str2 = "";
    for(int i = 0; i<M; i++){
        cin >> str2;
        if(umap.find(str2)!=umap.end()){    //보도 못한 사람이 듣도 못한 사람 명단에도 있으면
            ansVec.push_back(str2);
        }
    }
    
    sort(ansVec.begin(), ansVec.end());
    cout << ansVec.size() << "\n";
    for(int i = 0; i<ansVec.size(); i++){
        cout << ansVec[i] << "\n";
    }
    
    return 0;
}