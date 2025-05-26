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
/*
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

vector<string> strSplitBy2(string str, char delimiter) {
    size_t pos = 0;
    size_t prev = 0;
    vector<string> res;
    while ((pos = str.find(delimiter, pos)) != string::npos) {
        res.push_back(str.substr(prev, pos-prev));
        pos++;
        prev = pos;
    }
    res.push_back(str.substr(prev));
    return res;
}



*/


// support leetcode71
vector<string> strSplitBy(string& str, char delimiter) {
    stringstream ss;
    ss << str;
    vector<string> res;
    string tmp;
    while (getline(ss, tmp, delimiter)) {
        if (tmp.size() > 0) {
            res.push_back(tmp);
        }
    }
    return res;
}

vector<string> strSplitBy2(string& str, char delimiter) {
    size_t pos = 0;
    size_t prev = 0;
    vector<string> res;
    while ((pos = str.find(delimiter, pos)) != string::npos) {
        int len = pos - prev;
        if (len != 0) {
            res.push_back(str.substr(prev, len));
        }
        pos++;
        prev = pos;
    }
    string lastpart = str.substr(prev);
    if (lastpart.size() > 0) {
        res.push_back(lastpart);
    }
    return res;
}

// string 删除末尾字符
void remLast(string& str) {
    // C++
    // str.erase(str.end() - 1);
    //  C++ 11
    str.pop_back();
}

// frequently use
/*
isalpha()
isalnum()
isdigit()
islower()
isupper()




*/


/*

    int diff = 32;
    int diff = 'a' - 'A'; // 97-65

大写变小写、小写变大写 : 字符 ^= 32;
大写变小写、小写变小写 : 字符 |= 32;
小写变大写、大写变大写 : 字符 &= -33;



*/

/*
<algorithm>
min
max
swap

*/

#endif