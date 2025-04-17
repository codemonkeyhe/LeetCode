#ifndef  __TOOL_H__
#define  __TOOL_H__

#include <vector>
#include <iostream>
#include <sstream>
using namespace std;



// ##########   Int to String

/*
C++11
string std::to_string(int num)

C style
snprintf

*/

// before C++11
string itostr(int i) {
    stringstream ss;
    ss << i;
    // return ss.str();
    string tmp;
    ss >> tmp;
    return tmp;
}



// ############  String to int
/*
C++
int std::stoi(string str)

C  atoi atol atoll
int       atoi( const char* str );
long      atol( const char* str );
long long atoll( const char* str );  // C++11

*/


//  itostr and strtoi  are mirror code
int strtoi(string str) {
    // istringstream ss(str);
    stringstream ss;
    ss << str;
    int res;
    ss >> res;
    return res;
}



// split string
// str demo: "aaa   bbb      cccc" , can have many spaces between each string
vector<string> strSplit(string str) {
    stringstream ss;
    ss << str;
    vector<string> res;
    string tmp;
    while (ss >> tmp) {
        res.push_back(tmp);
    }
    return res;
}

// only for one delimiter string, if too many spaces between strings, not use
vector<string> strSplitBy(string str, char delimiter) {
    stringstream ss;
    ss << str;
    vector<string> res;
    string tmp;
    while (getline(ss, tmp, delimiter)) {
        res.push_back(tmp);
    }
    return res;
}


// string 删除末尾字符
void remLast(string& str) {
    //C++
    //str.erase(str.end() - 1);
    // C++ 11
    str.pop_back();
}

#endif