”, “ball”, “apple”, “art”, “ah” }
“htarfbp…”
根据下面的string去给上面list words排序。

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void str_sort(vector<string>& strs, const string& dict) {
    unordered_map<char, int> ranks;
    for(int i = 0; i < dict.size(); ++i) {
        ranks[dict[i]] = i;
    }
    auto compare=[&](const string& a, const string& b) {
        size_t len = std::min(a.length(), b.length());
        for(size_t i = 0; i < len; ++i) {
            auto r = ranks[a[i]] - ranks[b[i]];
            if(r < 0) return true;
            else if(r > 0) return false;
        }
        return a.length() < b.length();
        
    };
    sort(strs.begin(), strs.end(),compare);
    
}
int main() {
    // your code goes here
    vector<string>  strsets{"face", "ball", "apple", "art", "ah"};
    string compare{"htarfbp"};
    str_sort(strsets,compare);
    for (auto a:strsets)
        cout<<a<<endl;
    return 0;
}
