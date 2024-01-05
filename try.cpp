#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{   
    int i,count=0,len;
    string s = "   fly me   to   the moon  ";
    len = s.length();
    cout << "The length of the txt string is: " << len <<"\n";
    i = len;
    while (i>=0) {
        if(s[i] != ' '){

        }
        i--;
        count++;
    }
    cout << count-1 ;
    return 0;
}