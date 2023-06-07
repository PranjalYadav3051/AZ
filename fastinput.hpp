#include <bits/stdc++.h>
using namespace std;
ifstream fin;
ofstream fout;
 
template <typename T>
ostream& operator <<(ostream& output, const vector<T>& data)
{
    for (const T& x : data)
        output << x <<" ";
    return output;
}
 
template<typename T>
istream& operator>>(istream& input,vector<T>& data){
    for (auto& item : data) {
        input >> item;
    }
    return input;
}