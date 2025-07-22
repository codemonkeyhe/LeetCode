/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-22
 * @tag  dfs,bfs,hashTable
 * @similar  126, 127, 433, 2452
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 *
 * https://leetcode.cn/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (36.89%)
 * Likes:    746
 * Dislikes: 0
 * Total Accepted:    63.2K
 * Total Submissions: 172.6K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 按字典 wordList 完成从单词 beginWord 到单词 endWord 转化，一个表示此过程的 转换序列 是形式上像 beginWord ->
 * s1 -> s2 -> ... -> sk 这样的单词序列，并满足：
 *
 * 每对相邻的单词之间仅有单个字母不同。
 * 转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词。注意，beginWord 不必是字典 wordList
 * 中的单词。
 * sk == endWord
 *
 *
 * 给你两个单词 beginWord 和 endWord ，以及一个字典 wordList 。请你找出并返回所有从 beginWord 到 endWord
 * 的 最短转换序列 ，如果不存在这样的转换序列，返回一个空列表。每个序列都应该以单词列表 [beginWord, s1, s2, ..., sk]
 * 的形式返回。
 *
 *
 *
 * 示例 1：
 * 输入：beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log","cog"]
 * 输出：[["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
 * 解释：存在 2 种最短的转换序列：
 * "hit" -> "hot" -> "dot" -> "dog" -> "cog"
 * "hit" -> "hot" -> "lot" -> "log" -> "cog"
 *
 *
 * 示例 2：
 * 输入：beginWord = "hit", endWord = "cog", wordList =
 * ["hot","dot","dog","lot","log"]
 * 输出：[]
 * 解释：endWord "cog" 不在字典 wordList 中，所以不存在符合要求的转换序列。
 *
 *
 *
 *
 * 提示：
 * 1 <= beginWord.length <= 5
 * endWord.length == beginWord.length
 * 1 <= wordList.length <= 500
 * wordList[i].length == beginWord.length
 * beginWord、endWord 和 wordList[i] 由小写英文字母组成
 * beginWord != endWord
 * wordList 中的所有单词 互不相同
 *
 *
 *
 *
 */

// @lc code=start
class Solution {
public:

    int counter = 0;

    // TLE33-38
    vector<vector<string>> findLaddersTLE(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>  res;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0) {
            return res;
        }

        queue<string> que;
        unordered_set<string> visited;
        que.push(beginWord);
        visited.insert(beginWord);
        unordered_map<string, vector<string> > fa2s;

        int step = 0;
        bool find = false;
        while(!que.empty()) {
            int cnt = que.size();
            unordered_set<string> sameLevel;
            for (int i = 0; i < cnt; i++) {
                auto cur = que.front();
                que.pop();
             //   cout << " CUR=" << cur << " SIM=";

                auto neis = getSimilar(cur, wordSet);
                for (auto& nei: neis)  {
              //      cout << " " << nei;
                    if (visited.count(nei)) {
                        continue;
                    }
                    //que.push(nei);
                    fa2s[cur].push_back(nei);
                    sameLevel.insert(nei);
                    if (nei == endWord) { // 构建path
                        find = true;
                    }
                }
               // cout << endl;
            }
            // sameLevel  all vistied
            for (auto& ss : sameLevel) {
                que.push(ss);
                visited.insert(ss);
            }
            if (find) {
                break;
            }
            step++;
        }
        if (!find) {
            return res;
        }
        /*
        for (auto& [fa, sons]: fa2s) {
            cout << " fa=" << fa << " SON=";
            for (auto& son: sons) {
                cout << " " << son ;
            }
            cout << endl;
        }
        */


        vector<string> path;
        path.push_back(beginWord);
        // TLE 原因，正向DFS会超时
        buildPath(beginWord, endWord, fa2s, path, res);
        cout << "DFSNUMV1=" << counter << endl;
        return res;
    }


    void buildPath(string& bw, string& ew, unordered_map<string, vector<string> >& fa2s,  vector<string>& path, vector<vector<string> >& res) {
        counter++;
        if (counter > 100000) {// for debug
            cout << counter << endl;
        }
        if (ew == bw) { // find one path
            //vector<string> one(path.begin(), path.end());
            // 不用copy ，下面会自动copy
            res.push_back(path);
            return;
        }

        if (fa2s.count(bw) == 0) {
            return;
        }
        auto& sons = fa2s[bw];
        for (auto& son: sons) {
            path.push_back(son);
            buildPath(son, ew, fa2s, path, res);
            path.pop_back();
        }

    }

    vector<string> getSimilar(string &cur, unordered_set<string> &ws) {
        vector<string> words;
        for (auto& ch : cur) {
            char oldV = ch;
            for (char i = 'a'; i <= 'z'; i++) {
                if (i == oldV) {
                    continue;
                }
                ch = i;
                if (ws.count(cur) ) {
                    words.push_back(cur);
                }
            }
            ch = oldV;
        }
        return words;
    }


/*
38/38 cases passed (15 ms)
Your runtime beats 73.42 % of cpp submissions
Your memory usage beats 46.48 % of cpp submissions (15.3 MB)
*/

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>  res;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.count(endWord) == 0) {
            return res;
        }

        queue<string> que;
        unordered_set<string> visited;
        que.push(beginWord);
        visited.insert(beginWord);
        unordered_map<string, vector<string> > s2fa;

        int step = 0;
        bool find = false;
        while(!que.empty()) {
            int cnt = que.size();
            unordered_set<string> sameLevel;
            for (int i = 0; i < cnt; i++) {
                auto cur = que.front();
                que.pop();

                auto neis = getSimilar(cur, wordSet);
                for (auto& nei: neis)  {
                    if (visited.count(nei)) {
                        continue;
                    }
                    //que.push(nei);
                    //fa2s[cur].push_back(nei);
                    s2fa[nei].push_back(cur);
                    sameLevel.insert(nei);
                    if (nei == endWord) { // 构建path
                        find = true;
                    }
                }
            }
            // sameLevel  all vistied
            for (auto& ss : sameLevel) {
                que.push(ss);
                visited.insert(ss);
            }
            if (find) {
                break;
            }
            step++;
        }
        if (!find) {
            return res;
        }
        vector<string> path;
        path.push_back(endWord);
        buildPathV2(beginWord, endWord, s2fa, path, res);
        //cout << "DFSNUM=" << counter << endl;
        return res;
    }

    void buildPathV2(string& bw, string& ew, unordered_map<string, vector<string> >& s2fa,  vector<string>& path, vector<vector<string> >& res) {
        //counter++;
        if (ew == bw) { // find one path
            vector<string> one(path.rbegin(), path.rend());
            res.push_back(one);
            return;
        }

        if (s2fa.count(ew) == 0) {
            return;
        }
        auto& fas = s2fa[ew];
        for (auto& fa: fas) {
            path.push_back(fa);
            buildPathV2(bw, fa, s2fa, path, res);
            path.pop_back();
        }
    }



};
// @lc code=end


/*
M1 fa2sons TLE
BFS构建图， 记录 父子关系，然后DFS寻路，TLE

M2 son2fas
BFS构建图， 记录 子父关系，然后DFS寻路，OK

为何M1的DFS会超时，因为从beginWord出发，DFS到endWord，会经过很多死路径，不可达endWord，这些路径的耗时导致TLE
而从endWord出发，反向寻找父节点，就避免了很多死路径
证明： 通过counter埋点可以看出，对于超时的Case33,
buildPathV2的DFSNUM=25，函数调用25次，找到所有路径
而buildPath到10万还在继续调用，没找到答案



Wrong Answer
28/38 cases passed (N/A)
Testcase
"red"
"tax"
["ted","tex","red","tax","tad","den","rex","pee"]
Answer
[["red","ted","tad","tax"],["red","ted","tex","tax"]]
Expected Answer
[["red","ted","tad","tax"],["red","ted","tex","tax"],["red","rex","tex","tax"]]



没有处理find导致TLE，有些没有答案的没必要DFS，直接return 空集
Time Limit Exceeded
33/38 cases passed (N/A)
Testcase
"aaaaa"
' +
  '"ggggg"
' +
  '["aaaaa","caaaa","cbaaa","daaaa","dbaaa","eaaaa","ebaaa","faaaa","fbaaa","gaaaa","gbaaa","haaaa","hbaaa","iaaaa","ibaaa","jaaaa","jbaaa","kaaaa","kbaaa","laaaa","lbaaa","maaaa","mbaaa","naaaa","nbaaa","oaaaa","obaaa","paaaa","pbaaa","bbaaa","bbcaa","bbcba","bbdaa","bbdba","bbeaa","bbeba","bbfaa","bbfba","bbgaa","bbgba","bbhaa","bbhba","bbiaa","bbiba","bbjaa","bbjba","bbkaa","bbkba","bblaa","bblba","bbmaa","bbmba","bbnaa","bbnba","bboaa","bboba","bbpaa","bbpba","bbbba","abbba","acbba","dbbba","dcbba","ebbba","ecbba","fbbba","fcbba","gbbba","gcbba","hbbba","hcbba","ibbba","icbba","jbbba","jcbba","kbbba","kcbba","lbbba","lcbba","mbbba","mcbba","nbbba","ncbba","obbba","ocbba","pbbba","pcbba","ccbba","ccaba","ccaca","ccdba","ccdca","cceba","cceca","ccfba","ccfca","ccgba","ccgca","cchba","cchca","cciba","ccica","ccjba","ccjca","cckba","cckca","cclba","cclca","ccmba","ccmca","ccnba","ccnca","ccoba","ccoca","ccpba","ccpca","cccca","accca","adcca","bccca","bdcca","eccca","edcca","fccca","fdcca","gccca","gdcca","hccca","hdcca","iccca","idcca","jccca","jdcca","kccca","kdcca","lccca","ldcca","mccca","mdcca","nccca","ndcca","occca","odcca","pccca","pdcca","ddcca","ddaca","ddada","ddbca","ddbda","ddeca","ddeda","ddfca","ddfda","ddgca","ddgda","ddhca","ddhda","ddica","ddida","ddjca","ddjda","ddkca","ddkda","ddlca","ddlda","ddmca","ddmda","ddnca","ddnda","ddoca","ddoda","ddpca","ddpda","dddda","addda","aedda","bddda","bedda","cddda","cedda","fddda","fedda","gddda","gedda","hddda","hedda","iddda","iedda","jddda","jedda","kddda","kedda","lddda","ledda","mddda","medda","nddda","nedda","oddda","oedda","pddda","pedda","eedda","eeada","eeaea","eebda","eebea","eecda","eecea","eefda","eefea","eegda","eegea","eehda","eehea","eeida","eeiea","eejda","eejea","eekda","eekea","eelda","eelea","eemda","eemea","eenda","eenea","eeoda","eeoea","eepda","eepea","eeeea","ggggg","agggg","ahggg","bgggg","bhggg","cgggg","chggg","dgggg","dhggg","egggg","ehggg","fgggg","fhggg","igggg","ihggg","jgggg","jhggg","kgggg","khggg","lgggg","lhggg","mgggg","mhggg","ngggg","nhggg","ogggg","ohggg","pgggg","phggg","hhggg","hhagg","hhahg","hhbgg","hhbhg","hhcgg","hhchg","hhdgg","hhdhg","hhegg","hhehg","hhfgg","hhfhg","hhigg","hhihg","hhjgg","hhjhg","hhkgg","hhkhg","hhlgg","hhlhg","hhmgg","hhmhg","hhngg","hhnhg","hhogg","hhohg","hhpgg","hhphg","hhhhg","ahhhg","aihhg","bhhhg","bihhg","chhhg","cihhg","dhhhg","dihhg","ehhhg","eihhg","fhhhg","fihhg","ghhhg","gihhg","jhhhg","jihhg","khhhg","kihhg","lhhhg","lihhg","mhhhg","mihhg","nhhhg","nihhg","ohhhg","oihhg","phhhg","pihhg","iihhg","iiahg","iiaig","iibhg","iibig","iichg","iicig","iidhg","iidig","iiehg","iieig","iifhg","iifig","iighg","iigig","iijhg","iijig","iikhg","iikig","iilhg","iilig","iimhg","iimig","iinhg","iinig","iiohg","iioig","iiphg","iipig","iiiig","aiiig","ajiig","biiig","bjiig","ciiig","cjiig","diiig","djiig","eiiig","ejiig","fiiig","fjiig","giiig","gjiig","hiiig","hjiig","kiiig","kjiig","liiig","ljiig","miiig","mjiig","niiig","njiig","oiiig","ojiig","piiig","pjiig","jjiig","jjaig","jjajg","jjbig","jjbjg","jjcig","jjcjg","jjdig","jjdjg","jjeig","jjejg","jjfig","jjfjg","jjgig","jjgjg","jjhig","jjhjg","jjkig","jjkjg","jjlig","jjljg","jjmig","jjmjg","jjnig","jjnjg","jjoig","jjojg","jjpig","jjpjg","jjjjg","ajjjg","akjjg","bjjjg","bkjjg","cjjjg","ckjjg","djjjg","dkjjg","ejjjg","ekjjg","fjjjg","fkjjg","gjjjg","gkjjg","hjjjg","hkjjg","ijjjg","ikjjg","ljjjg","lkjjg","mjjjg","mkjjg","njjjg","nkjjg","ojjjg","okjjg","pjjjg","pkjjg","kkjjg","kkajg","kkakg","kkbjg","kkbkg","kkcjg","kkckg","kkdjg","kkdkg","kkejg","kkekg","kkfjg","kkfkg","kkgjg","kkgkg","kkhjg","kkhkg","kkijg","kkikg","kkljg","kklkg","kkmjg","kkmkg","kknjg","kknkg","kkojg","kkokg","kkpjg","kkpkg","kkkkg","ggggx","gggxx","ggxxx","gxxxx","xxxxx","xxxxy","xxxyy","xxyyy","xyyyy","yyyyy","yyyyw","yyyww","yywww","ywwww","wwwww","wwvww","wvvww","vvvww","vvvwz","avvwz","aavwz","aaawz","aaaaz"]
Expected Answer
[["aaaaa","aaaaz","aaawz","aavwz","avvwz","vvvwz","vvvww","wvvww","wwvww","wwwww","ywwww","yywww","yyyww","yyyyw","yyyyy","xyyyy","xxyyy","xxxyy","xxxxy","xxxxx","gxxxx","ggxxx","gggxx","ggggx","ggggg"]]


*/

int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


