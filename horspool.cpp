 #include <iostream>
#include <string>
#include <vector>

using namespace std;

int horspool(string ptn,string str) {
// Calculate the shift table for the pattern
std::vector<int> shifts(256, ptn.length());
for (int i = 0; i < ptn.length() - 1; i++)
shifts[ptn[i]] = ptn.length() - i - 1;

// Perform the search
int n = str.length();
int m = ptn.length();
int skip;
for (int i = 0; i <= n - m; i += skip) {
skip = 0;
for (int j = m - 1; j >= 0; j--) {
if (str[i + j] != ptn[j]) {
skip = shifts[str[i + j]];
break;
}
}
if (skip == 0) return i;
}
return -1;
}

int main() {
char str[20],ptn[20];
cout<<"Enter the ptn \n";
cin>>ptn;
cout<<ptn<<endl;
cout<<"Enter the str \n";
cin>>str;
cout<<str<<endl;
int res = horspool(ptn, str);
if (res != -1)
std::cout << "Pattern found at index " << res << endl;
else
std::cout << "Pattern not found in text" << endl;
return 0;
}
