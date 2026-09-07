#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    // character hashing
    string s = "aabgbsaa";
    vector<int> hash2(50, 0); // only 26 char in alphabet, so 50 size is enough.
    
    for (int i = 0; i < s.size(); i++)
    hash2[s[i] - 'a']++;
    
    for (int i = 0; i < s.size(); i++)
    cout << char(i + 'a') << " appeared : " << hash2[i] << endl;
    

    return 0;
}