#include <iostream>
#include <string>
#include <limits>


using namespace std;

string mvString(string a, string b, int n){
    string s = "";
    s += b.substr(0, n);
    s += a;
    if(s.size()<b.size()){
        s += b.substr(s.size(), b.size()-1);
    }
    return s;
}

int diff(string a, string b){
    int cnt = 0;
    for(int i = 0 ; i < a.size() ; i++){
        if(a[i]!=b[i])cnt++;
    }
    return cnt;
}

int solution(string a, string b){
    int answer = numeric_limits<int>::max();
    int difCnt;

    if(a.size() == b.size()){
        return diff(a, b);
    }
    
    for(int i = 0 ; i <= b.size() - a.size() ; i++){
        difCnt = diff(mvString(a, b, i), b);
        if(difCnt==0)return 0;
        answer = min(answer, difCnt);
    }
    return answer;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    string a,b;
    cin>>a>>b;
    cout<<solution(a, b);
    
    return 0;
}
