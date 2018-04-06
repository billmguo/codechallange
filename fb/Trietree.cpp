这道题有个Follow up就是当搜索的单词中存在星号时怎么做，其中星号代表任何长度的字符串，包括空字符串，跟之前那道Wildcard Matching中星号的定义一样，那么此时我们该怎么做呢。其实也不是很难，我们拿个简单的例子来分析一下：
addWord("word") search("*rd")
好，我们的前缀树是这样的结构: root -> 'w' -> 'o' -> 'r' -> 'd'，我们要搜索的单词是以星号开头的，我们的方法是如果检测到了星号，那么我们首先来看，
如果星号是最后一个字符，后面再没东西了，说明此时匹配成功了，直接返回true。否则我们看当前的字符和星号后面的一个字符是否匹配，
这里'w'和'r'不匹配，那么我们继续来匹配"ord"和"*rd"，同理，现在'o'和'r'还是失配的，那么我们继续来匹配"rd"和"*rd"，现在'r'和'r'匹配上了，
那么跳过星号来匹配"rd"和"rd"，可以成功匹配上。注意，就算现在'r'和'r'匹配上了，我们还是要匹配"d"和"*rd"，因为害怕出现下面这种情况：
addWord("rdrd")
search("*rd")
第一个匹配上的'r'后，"rdrd"和"rd"实际上是失配的，我们一直要保留星号，直到第二个匹配上的'r'，"rd"和"rd"才能成功匹配。还有一点要注意的是，
当星号后面又跟了星号'*'或者'.'，我们统一将其当作成功匹配来进一步处理，参见代码如下：
// Follow up, word contains '*'
class WordDictionary {
public:
    struct TrieNode {
    public:
        TrieNode *child[26];
        bool isWord;
        TrieNode() : isWord(false) {
            for (auto &a : child) a = NULL;
        }
    };
      
    WordDictionary() {
        root = new TrieNode();
    }
      
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *p = root;
        for (auto &a : word) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
  
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return searchWord(word, root, 0);
    }
      
    bool searchWord(string &word, TrieNode *p, int i) {
        if (i == word.size()) return p->isWord;
        if (word[i] == '*') {
            if (i + 1 == word.size())) return true;
            if (searchWord(word, p, i + 1)) return true;
            for (auto &a:p->child) {
                if (a && search(word, a, i))
                    return true;
            }
            for (auto &a : p->child) {
                if (a && (a->child[word[i + 1] - 'a'] || word[i + 1] == '.' || word[i + 1] == '*') && searchWord(word, a, i + 1)) 
                    return true;
                if (a && searchWord(word, a, i)) return true;
            }
            return false;
        } else if (word[i] == '.') {
            for (auto &a:p->child) {
                if (a && searchWord(word, a, i + 1))
                    return true;
            }
            return false;
        } else {
            return p->child[word[i] - 'a'] && searchWord(word, p->child[word[i] - 'a'], i + 1);
        }
    }
      
private:
    TrieNode *root;
};
