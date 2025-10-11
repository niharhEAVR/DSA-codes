#include <iostream>
#include <vector>
using namespace std;

int main()
{
    {
        // // numbers hashing
        // int arr[] = {2, 3, 2, 5, 3, 2};
        // int n = 6;

        // vector<int> hash(10, 0); // hash array (size 10 for simplicity)

        // for (int i = 0; i < n; i++)
        // {
        //     hash[arr[i]]++; // hash[arr[i]] means count of that number
        // }

        // for (int i = 0; i < 10; i++)
        // {
        //     if (hash[i] > 0)
        //     {
        //         cout << i << " occurs " << hash[i] << " times" << endl;
        //     }
        // }
    }

    {
        // character hashing
        string s = "fheufgeckebndqakjcibgw";

        int asciiValue = 'a';
        int asciiValuediff = 'f' - 'a';
        cout<<asciiValue<<endl;

        vector<int> hash(100, 0); 

        for (auto ch : s)
        {
            hash[ch-'a']++; // we are getting the ASCII values difference between them, and inside the hash function the values aumotically converts into int
        }


        for (auto ch : s)
        {
            if (hash[ch-'a'] > 0)
            {
                cout << ch << " occurs " << hash[ch-'a'] << " times" << endl;
            }
        }
    }

    return 0;
}
