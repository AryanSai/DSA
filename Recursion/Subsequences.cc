#include <iostream>
using namespace std;

void helper(string s, string temp, int i){
    if(s.size() == i){ //base case 
        cout << temp << endl;
        return;
    }
    // take the current character
    helper(s, temp + s[i], i + 1);
    // don't take the current character
    helper(s, temp, i + 1);
}

void subsequences(string s){
    helper(s, "", 0);
}

int main()
{
    subsequences("abc");
    return 0;
}
