/**
 * @file
 * @brief
 * @author MonkeyHe
 * @version  1.0
 * @date 2025-07-23
 * @tag  trie, dfs
 * @similar 208, 211, 212
 */

/*

*/


#include "stdio.h"
#include "stdlib.h"
#include "common.h"
#include <iostream>

using namespace std;

/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 *
 * https://leetcode.cn/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (43.16%)
 * Likes:    949
 * Dislikes: 0
 * Total Accepted:    128.9K
 * Total Submissions: 297.5K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * 给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words， 返回所有二维网格上的单词 。
 * 单词必须按照字母顺序，通过 相邻的单元格
 * 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
 *
 *
 *
 * 示例 1：
 * 输入：board =
 * [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]],
 * words = ["oath","pea","eat","rain"]
 * 输出：["eat","oath"]
 *
 *
 * 示例 2：
 * 输入：board = [["a","b"],["c","d"]], words = ["abcb"]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 12
 * board[i][j] 是一个小写英文字母
 * 1 <= words.length <= 3 * 10^4
 * 1 <= words[i].length <= 10
 * words[i] 由小写英文字母组成
 * words 中的所有字符串互不相同
 *
 *
 */

// @lc code=start
class TrieNode {

public:
    TrieNode() {
        child = vector<TrieNode*>(26, NULL);
        word = "";
    }

    vector<TrieNode*> child;
    string word;
};



class Solution {
  public:
    //M1 复用79方法
    vector<string> findWordsTLE(vector<vector<char>> &board, vector<string> &words) {
        vector<string> res;
        for (auto &word : words) {
            if (exist(board, word)) {
                res.push_back(word);
            }
        }
        return res;
    }

    bool exist(vector<vector<char>> &board, string word) {
        int ch0 = word[0];
        int row = board.size();
        int col = board[0].size();
        visited = vector<vector<int>>(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == ch0) {
                    if (dfs(board, i, j, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    vector<vector<int>> visited;

    bool dfs(vector<vector<char>> &board, int i, int j, string &word, int idx) {
        if (visited[i][j]) { // visited
            return false;
        }
        if (word[idx] != board[i][j]) {
            return false;
        }
        if (idx >= word.size() - 1) {
            return true;
        }
        int row = board.size();
        int col = board[0].size();
        visited[i][j] = 1;

        // up
        if (i > 0 && dfs(board, i - 1, j, word, idx + 1)) {
            return true;
        }
        // donw
        if (i < row - 1 && dfs(board, i + 1, j, word, idx + 1)) {
            return true;
        }
        // left
        if (j > 0 && dfs(board, i, j - 1, word, idx + 1)) {
            return true;
        }
        // right
        if (j < col - 1 && dfs(board, i, j + 1, word, idx + 1)) {
            return true;
        }

        visited[i][j] = 0;
        return false;
    }

    void addWord(TrieNode* tire, string& word) {
        TrieNode* cur = tire;
        for (auto& ch: word) {
            int idx = ch - 'a';
            if (cur->child[idx] == NULL) {
                cur->child[idx] = new TrieNode();
            }
            cur = cur->child[idx];
        }
        cur->word = word;
    }

    // M2
    unordered_set<string> hs;
    vector<string> res2;
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        TrieNode* tire = new TrieNode();

        int row = board.size();
        int col = board[0].size();
        visited = vector<vector<int>>(row, vector<int>(col, 0));

        for (auto& word : words) {
            addWord(tire, word);
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // M2V1
                //dfsTrie(board, i, j, tire);

                // M2 V2
                dfsTrie2(board, i, j, tire);
            }
        }

        //M2V1
        //vector<string> res1(hs.begin(), hs.end());
        //return res1;

        return res2;
    }


    void dfsTrie(vector<vector<char>> &board, int i, int j, TrieNode* tire) {
        int idx = board[i][j] - 'a';
        if (tire->child[idx] == NULL) {
            return ;
        }

        TrieNode* son = tire->child[idx];
        if (son->word.size() > 0) {
            hs.insert(son->word);
        }

        int row = board.size();
        int col = board[0].size();
        visited[i][j] = 1;

        // up
        if (i > 0 && !visited[i-1][j]) {
            dfsTrie(board, i - 1, j, son);
        }
        // donw
        if (i < row - 1 && !visited[i+1][j]) {
            dfsTrie(board, i + 1, j, son);
        }
        // left
        if (j > 0 && !visited[i][j-1]) {
            dfsTrie(board, i, j - 1, son);
        }
        // right
        if (j < col - 1 && !visited[i][j + 1]) {
            dfsTrie(board, i, j + 1, son);
        }

        visited[i][j] = 0;
        return ;
    }


    void dfsTrie2(vector<vector<char>> &board, int i, int j, TrieNode* tire) {
        int idx = board[i][j] - 'a';
        if (tire->child[idx] == NULL) {
            return ;
        }

        TrieNode* son = tire->child[idx];
        if (son->word.size() > 0) {
            res2.push_back(son->word);
            son->word = "";
        }

        int row = board.size();
        int col = board[0].size();
        visited[i][j] = 1;

        // up
        if (i > 0 && !visited[i-1][j]) {
            dfsTrie2(board, i - 1, j, son);
        }
        // donw
        if (i < row - 1 && !visited[i+1][j]) {
            dfsTrie2(board, i + 1, j, son);
        }
        // left
        if (j > 0 && !visited[i][j-1]) {
            dfsTrie2(board, i, j - 1, son);
        }
        // right
        if (j < col - 1 && !visited[i][j + 1]) {
            dfsTrie2(board, i, j + 1, son);
        }

        visited[i][j] = 0;

        return ;
    }
};
// @lc code=end


/*
Time Limit Exceeded
63/65 cases passed (N/A)
Testcase
[["m","b","c","d","e","f","g","h","i","j","k","l"],["n","a","a","a","a","a","a","a","a","a","a","a"],["o","a","a","a","a","a","a","a","a","a","a","a"],["p","a","a","a","a","a","a","a","a","a","a","a"],["q","a","a","a","a","a","a","a","a","a","a","a"],["r","a","a","a","a","a","a","a","a","a","a","a"],["s","a","a","a","a","a","a","a","a","a","a","a"],["t","a","a","a","a","a","a","a","a","a","a","a"],["u","a","a","a","a","a","a","a","a","a","a","a"],["v","a","a","a","a","a","a","a","a","a","a","a"],["w","a","a","a","a","a","a","a","a","a","a","a"],["x","y","z","a","a","a","a","a","a","a","a","a"]]
' +
  '["aaaaaaaaaa","aaaaaaaaab","aaaaaaaaac","aaaaaaaaad","aaaaaaaaae","aaaaaaaaaf","aaaaaaaaag","aaaaaaaaah","aaaaaaaaai","aaaaaaaaaj","aaaaaaaaak","aaaaaaaaal","aaaaaaaaam","aaaaaaaaan","aaaaaaaaao","aaaaaaaaap","aaaaaaaaaq","aaaaaaaaar","aaaaaaaaas","aaaaaaaaat","aaaaaaaaau","aaaaaaaaav","aaaaaaaaaw","aaaaaaaaax","aaaaaaaaay","aaaaaaaaaz","aaaaaaaaba","aaaaaaaabb","aaaaaaaabc","aaaaaaaabd","aaaaaaaabe","aaaaaaaabf","aaaaaaaabg","aaaaaaaabh","aaaaaaaabi","aaaaaaaabj","aaaaaaaabk","aaaaaaaabl","aaaaaaaabm","aaaaaaaabn","aaaaaaaabo","aaaaaaaabp","aaaaaaaabq","aaaaaaaabr","aaaaaaaabs","aaaaaaaabt","aaaaaaaabu","aaaaaaaabv","aaaaaaaabw","aaaaaaaabx","aaaaaaaaby","aaaaaaaabz","aaaaaaaaca","aaaaaaaacb","aaaaaaaacc","aaaaaaaacd","aaaaaaaace","aaaaaaaacf","aaaaaaaacg","aaaaaaaach","aaaaaaaaci","aaaaaaaacj","aaaaaaaack","aaaaaaaacl","aaaaaaaacm","aaaaaaaacn","aaaaaaaaco","aaaaaaaacp","aaaaaaaacq","aaaaaaaacr","aaaaaaaacs","aaaaaaaact","aaaaaaaacu","aaaaaaaacv","aaaaaaaacw","aaaaaaaacx","aaaaaaaacy","aaaaaaaacz","aaaaaaaada","aaaaaaaadb","aaaaaaaadc","aaaaaaaadd","aaaaaaaade","aaaaaaaadf","aaaaaaaadg","aaaaaaaadh","aaaaaaaadi","aaaaaaaadj","aaaaaaaadk","aaaaaaaadl","aaaaaaaadm","aaaaaaaadn","aaaaaaaado","aaaaaaaadp","aaaaaaaadq","aaaaaaaadr","aaaaaaaads","aaaaaaaadt","aaaaaaaadu","aaaaaaaadv","aaaaaaaadw","aaaaaaaadx","aaaaaaaady","aaaaaaaadz","aaaaaaaaea","aaaaaaaaeb","aaaaaaaaec","aaaaaaaaed","aaaaaaaaee","aaaaaaaaef","aaaaaaaaeg","aaaaaaaaeh","aaaaaaaaei","aaaaaaaaej","aaaaaaaaek","aaaaaaaael","aaaaaaaaem","aaaaaaaaen","aaaaaaaaeo","aaaaaaaaep","aaaaaaaaeq","aaaaaaaaer","aaaaaaaaes","aaaaaaaaet","aaaaaaaaeu","aaaaaaaaev","aaaaaaaaew","aaaaaaaaex","aaaaaaaaey","aaaaaaaaez","aaaaaaaafa","aaaaaaaafb","aaaaaaaafc","aaaaaaaafd","aaaaaaaafe","aaaaaaaaff","aaaaaaaafg","aaaaaaaafh","aaaaaaaafi","aaaaaaaafj","aaaaaaaafk","aaaaaaaafl","aaaaaaaafm","aaaaaaaafn","aaaaaaaafo","aaaaaaaafp","aaaaaaaafq","aaaaaaaafr","aaaaaaaafs","aaaaaaaaft","aaaaaaaafu","aaaaaaaafv","aaaaaaaafw","aaaaaaaafx","aaaaaaaafy","aaaaaaaafz","aaaaaaaaga","aaaaaaaagb","aaaaaaaagc","aaaaaaaagd","aaaaaaaage","aaaaaaaagf","aaaaaaaagg","aaaaaaaagh","aaaaaaaagi","aaaaaaaagj","aaaaaaaagk","aaaaaaaagl","aaaaaaaagm","aaaaaaaagn","aaaaaaaago","aaaaaaaagp","aaaaaaaagq","aaaaaaaagr","aaaaaaaags","aaaaaaaagt","aaaaaaaagu","aaaaaaaagv","aaaaaaaagw","aaaaaaaagx","aaaaaaaagy","aaaaaaaagz","aaaaaaaaha","aaaaaaaahb","aaaaaaaahc","aaaaaaaahd","aaaaaaaahe","aaaaaaaahf","aaaaaaaahg","aaaaaaaahh","aaaaaaaahi","aaaaaaaahj","aaaaaaaahk","aaaaaaaahl","aaaaaaaahm","aaaaaaaahn","aaaaaaaaho","aaaaaaaahp","aaaaaaaahq","aaaaaaaahr","aaaaaaaahs","aaaaaaaaht","aaaaaaaahu","aaaaaaaahv","aaaaaaaahw","aaaaaaaahx","aaaaaaaahy","aaaaaaaahz","aaaaaaaaia","aaaaaaaaib","aaaaaaaaic","aaaaaaaaid","aaaaaaaaie","aaaaaaaaif","aaaaaaaaig","aaaaaaaaih","aaaaaaaaii","aaaaaaaaij","aaaaaaaaik","aaaaaaaail","aaaaaaaaim","aaaaaaaain","aaaaaaaaio","aaaaaaaaip","aaaaaaaaiq","aaaaaaaair","aaaaaaaais","aaaaaaaait","aaaaaaaaiu","aaaaaaaaiv","aaaaaaaaiw","aaaaaaaaix","aaaaaaaaiy","aaaaaaaaiz","aaaaaaaaja","aaaaaaaajb","aaaaaaaajc","aaaaaaaajd","aaaaaaaaje","aaaaaaaajf","aaaaaaaajg","aaaaaaaajh","aaaaaaaaji","aaaaaaaajj","aaaaaaaajk","aaaaaaaajl","aaaaaaaajm","aaaaaaaajn","aaaaaaaajo","aaaaaaaajp","aaaaaaaajq","aaaaaaaajr","aaaaaaaajs","aaaaaaaajt","aaaaaaaaju","aaaaaaaajv","aaaaaaaajw","aaaaaaaajx","aaaaaaaajy","aaaaaaaajz","aaaaaaaaka","aaaaaaaakb","aaaaaaaakc","aaaaaaaakd","aaaaaaaake","aaaaaaaakf","aaaaaaaakg","aaaaaaaakh","aaaaaaaaki","aaaaaaaakj","aaaaaaaakk","aaaaaaaakl","aaaaaaaakm","aaaaaaaakn","aaaaaaaako","aaaaaaaakp","aaaaaaaakq","aaaaaaaakr","aaaaaaaaks","aaaaaaaakt","aaaaaaaaku","aaaaaaaakv","aaaaaaaakw","aaaaaaaakx","aaaaaaaaky","aaaaaaaakz","aaaaaaaala","aaaaaaaalb","aaaaaaaalc","aaaaaaaald","aaaaaaaale","aaaaaaaalf","aaaaaaaalg","aaaaaaaalh","aaaaaaaali","aaaaaaaalj","aaaaaaaalk","aaaaaaaall","aaaaaaaalm","aaaaaaaaln","aaaaaaaalo","aaaaaaaalp","aaaaaaaalq","aaaaaaaalr","aaaaaaaals","aaaaaaaalt","aaaaaaaalu","aaaaaaaalv","aaaaaaaalw","aaaaaaaalx","aaaaaaaaly","aaaaaaaalz","aaaaaaaama","aaaaaaaamb","aaaaaaaamc","aaaaaaaamd","aaaaaaaame","aaaaaaaamf","aaaaaaaamg","aaaaaaaamh","aaaaaaaami","aaaaaaaamj","aaaaaaaamk","aaaaaaaaml","aaaaaaaamm","aaaaaaaamn","aaaaaaaamo","aaaaaaaamp","aaaaaaaamq","aaaaaaaamr","aaaaaaaams","aaaaaaaamt","aaaaaaaamu","aaaaaaaamv","aaaaaaaamw","aaaaaaaamx","aaaaaaaamy","aaaaaaaamz","aaaaaaaana","aaaaaaaanb","aaaaaaaanc","aaaaaaaand","aaaaaaaane","aaaaaaaanf","aaaaaaaang","aaaaaaaanh","aaaaaaaani","aaaaaaaanj","aaaaaaaank","aaaaaaaanl","aaaaaaaanm","aaaaaaaann","aaaaaaaano","aaaaaaaanp","aaaaaaaanq","aaaaaaaanr","aaaaaaaans","aaaaaaaant","aaaaaaaanu","aaaaaaaanv","aaaaaaaanw","aaaaaaaanx","aaaaaaaany","aaaaaaaanz","aaaaaaaaoa","aaaaaaaaob","aaaaaaaaoc","aaaaaaaaod","aaaaaaaaoe","aaaaaaaaof","aaaaaaaaog","aaaaaaaaoh","aaaaaaaaoi","aaaaaaaaoj","aaaaaaaaok","aaaaaaaaol","aaaaaaaaom","aaaaaaaaon","aaaaaaaaoo","aaaaaaaaop","aaaaaaaaoq","aaaaaaaaor","aaaaaaaaos","aaaaaaaaot","aaaaaaaaou","aaaaaaaaov","aaaaaaaaow","aaaaaaaaox","aaaaaaaaoy","aaaaaaaaoz","aaaaaaaapa","aaaaaaaapb","aaaaaaaapc","aaaaaaaapd","aaaaaaaape","aaaaaaaapf","aaaaaaaapg","aaaaaaaaph","aaaaaaaapi","aaaaaaaapj","aaaaaaaapk","aaaaaaaapl","aaaaaaaapm","aaaaaaaapn","aaaaaaaapo","aaaaaaaapp","aaaaaaaapq","aaaaaaaapr","aaaaaaaaps","aaaaaaaapt","aaaaaaaapu","aaaaaaaapv","aaaaaaaapw","aaaaaaaapx","aaaaaaaapy","aaaaaaaapz","aaaaaaaaqa","aaaaaaaaqb","aaaaaaaaqc","aaaaaaaaqd","aaaaaaaaqe","aaaaaaaaqf","aaaaaaaaqg","aaaaaaaaqh","aaaaaaaaqi","aaaaaaaaqj","aaaaaaaaqk","aaaaaaaaql","aaaaaaaaqm","aaaaaaaaqn","aaaaaaaaqo","aaaaaaaaqp","aaaaaaaaqq","aaaaaaaaqr","aaaaaaaaqs","aaaaaaaaqt","aaaaaaaaqu","aaaaaaaaqv","aaaaaaaaqw","aaaaaaaaqx","aaaaaaaaqy","aaaaaaaaqz","aaaaaaaara","aaaaaaaarb","aaaaaaaarc","aaaaaaaard","aaaaaaaare","aaaaaaaarf","aaaaaaaarg","aaaaaaaarh","aaaaaaaari","aaaaaaaarj","aaaaaaaark","aaaaaaaarl","aaaaaaaarm","aaaaaaaarn","aaaaaaaaro","aaaaaaaarp","aaaaaaaarq","aaaaaaaarr","aaaaaaaars","aaaaaaaart","aaaaaaaaru","aaaaaaaarv","aaaaaaaarw","aaaaaaaarx","aaaaaaaary","aaaaaaaarz","aaaaaaaasa","aaaaaaaasb","aaaaaaaasc","aaaaaaaasd","aaaaaaaase","aaaaaaaasf","aaaaaaaasg","aaaaaaaash","aaaaaaaasi","aaaaaaaasj","aaaaaaaask","aaaaaaaasl","aaaaaaaasm","aaaaaaaasn","aaaaaaaaso","aaaaaaaasp","aaaaaaaasq","aaaaaaaasr","aaaaaaaass","aaaaaaaast","aaaaaaaasu","aaaaaaaasv","aaaaaaaasw","aaaaaaaasx","aaaaaaaasy","aaaaaaaasz","aaaaaaaata","aaaaaaaatb","aaaaaaaatc","aaaaaaaatd","aaaaaaaate","aaaaaaaatf","aaaaaaaatg","aaaaaaaath","aaaaaaaati","aaaaaaaatj","aaaaaaaatk","aaaaaaaatl","aaaaaaaatm","aaaaaaaatn","aaaaaaaato","aaaaaaaatp","aaaaaaaatq","aaaaaaaatr","aaaaaaaats","aaaaaaaatt","aaaaaaaatu","aaaaaaaatv","aaaaaaaatw","aaaaaaaatx","aaaaaaaaty","aaaaaaaatz","aaaaaaaaua","aaaaaaaaub","aaaaaaaauc","aaaaaaaaud","aaaaaaaaue","aaaaaaaauf","aaaaaaaaug","aaaaaaaauh","aaaaaaaaui","aaaaaaaauj","aaaaaaaauk","aaaaaaaaul","aaaaaaaaum","aaaaaaaaun","aaaaaaaauo","aaaaaaaaup","aaaaaaaauq","aaaaaaaaur","aaaaaaaaus","aaaaaaaaut","aaaaaaaauu","aaaaaaaauv","aaaaaaaauw","aaaaaaaaux","aaaaaaaauy","aaaaaaaauz","aaaaaaaava","aaaaaaaavb","aaaaaaaavc","aaaaaaaavd","aaaaaaaave","aaaaaaaavf","aaaaaaaavg","aaaaaaaavh","aaaaaaaavi","aaaaaaaavj","aaaaaaaavk","aaaaaaaavl","aaaaaaaavm","aaaaaaaavn","aaaaaaaavo","aaaaaaaavp","aaaaaaaavq","aaaaaaaavr","aaaaaaaavs","aaaaaaaavt","aaaaaaaavu","aaaaaaaavv","aaaaaaaavw","aaaaaaaavx","aaaaaaaavy","aaaaaaaavz","aaaaaaaawa","aaaaaaaawb","aaaaaaaawc","aaaaaaaawd","aaaaaaaawe","aaaaaaaawf","aaaaaaaawg","aaaaaaaawh","aaaaaaaawi","aaaaaaaawj","aaaaaaaawk","aaaaaaaawl","aaaaaaaawm","aaaaaaaawn","aaaaaaaawo","aaaaaaaawp","aaaaaaaawq","aaaaaaaawr","aaaaaaaaws","aaaaaaaawt","aaaaaaaawu","aaaaaaaawv","aaaaaaaaww","aaaaaaaawx","aaaaaaaawy","aaaaaaaawz","aaaaaaaaxa","aaaaaaaaxb","aaaaaaaaxc","aaaaaaaaxd","aaaaaaaaxe","aaaaaaaaxf","aaaaaaaaxg","aaaaaaaaxh","aaaaaaaaxi","aaaaaaaaxj","aaaaaaaaxk","aaaaaaaaxl","aaaaaaaaxm","aaaaaaaaxn","aaaaaaaaxo","aaaaaaaaxp","aaaaaaaaxq","aaaaaaaaxr","aaaaaaaaxs","aaaaaaaaxt","aaaaaaaaxu","aaaaaaaaxv","aaaaaaaaxw","aaaaaaaaxx","aaaaaaaaxy","aaaaaaaaxz","aaaaaaaaya","aaaaaaaayb","aaaaaaaayc","aaaaaaaayd","aaaaaaaaye","aaaaaaaayf","aaaaaaaayg","aaaaaaaayh","aaaaaaaayi","aaaaaaaayj","aaaaaaaayk","aaaaaaaayl","aaaaaaaaym","aaaaaaaayn","aaaaaaaayo","aaaaaaaayp","aaaaaaaayq","aaaaaaaayr","aaaaaaaays","aaaaaaaayt","aaaaaaaayu","aaaaaaaayv","aaaaaaaayw","aaaaaaaayx","aaaaaaaayy","aaaaaaaayz","aaaaaaaaza","aaaaaaaazb","aaaaaaaazc","aaaaaaaazd","aaaaaaaaze","aaaaaaaazf","aaaaaaaazg","aaaaaaaazh","aaaaaaaazi","aaaaaaaazj","aaaaaaaazk","aaaaaaaazl","aaaaaaaazm","aaaaaaaazn","aaaaaaaazo","aaaaaaaazp","aaaaaaaazq","aaaaaaaazr","aaaaaaaazs","aaaaaaaazt","aaaaaaaazu","aaaaaaaazv","aaaaaaaazw","aaaaaaaazx","aaaaaaaazy","aaaaaaaazz"]
Expected Answer
["aaaaaaaaij","aaaaaaaaih","aaaaaaaaaj","aaaaaaaaaa","aaaaaaaaah","aaaaaaaagh","aaaaaaaagf","aaaaaaaaaf","aaaaaaaaap","aaaaaaaaon","aaaaaaaaop","aaaaaaaaef","aaaaaaaaed","aaaaaaaaar","aaaaaaaaqp","aaaaaaaaqr","aaaaaaaaad","aaaaaaaaat","aaaaaaaasr","aaaaaaaast","aaaaaaaacd","aaaaaaaacb","aaaaaaaaav","aaaaaaaaut","aaaaaaaauv","aaaaaaaajk","aaaaaaaaji","aaaaaaaaak","aaaaaaaaai","aaaaaaaahi","aaaaaaaahg","aaaaaaaaag","aaaaaaaaao","aaaaaaaafg","aaaaaaaafe","aaaaaaaaaq","aaaaaaaapo","aaaaaaaapq","aaaaaaaabc","aaaaaaaabm","aaaaaaaanm","aaaaaaaano","aaaaaaaaae","aaaaaaaaas","aaaaaaaarq","aaaaaaaars","aaaaaaaade","aaaaaaaadc","aaaaaaaaau","aaaaaaaats","aaaaaaaatu","aaaaaaaakl","aaaaaaaakj","aaaaaaaaal","aaaaaaaaab","aaaaaaaaan","aaaaaaaalk","aaaaaaaaac","aaaaaaaaay","aaaaaaaaaw","aaaaaaaavu","aaaaaaaavw","aaaaaaaaaz","aaaaaaaayz","aaaaaaaayx","aaaaaaaawv","aaaaaaaawx","aaaaaaaaza","aaaaaaaazy"]


考虑以下情况。假设给定一个所有单元格都是 a 的二维字符网格和单词列表 ["a", "aa", "aaa", "aaaa"] 。当我们使用方法一来找出所有同时在二维网格和单词列表中出现的单词时，我们需要遍历每一个单元格的所有路径，会找到大量重复的单词。

为了缓解这种情况，我们可以将匹配到的单词从前缀树中移除，来避免重复寻找相同的单词。因为这种方法可以保证每个单词只能被匹配一次；所以我们也不需要再对结果集去重了。

作者：力扣官方题解
链接：https://leetcode.cn/problems/word-search-ii/solutions/1000172/dan-ci-sou-suo-ii-by-leetcode-solution-7494/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

*/


int main() {
    Solution s;
}


/*
Tips
M1

M2

*/


