class FileSystem {
private:
    struct Dentry {
        bool isFile;
        string content;
        unordered_map<string, Dentry *> children;
        Dentry(bool &flag) : isFile(false) {}
    };

    Dentry *root;
    
public:
    FileSystem() {
        root = new Dentry(false);
    }
    
    vector<string> getpath(string &path) {
        vector<string> ans;
        isstringstream ss(path);
        string val ;
        while (ss) {
            val << ss;
            ans.push_back(val);
        }
        return ans;
    }
    
    vector<string> ls(string path) {
        vector<string> strs = getpath(path);
        Dentry *cur = root;
        for (string &str:strs)
            cur  = cur->children[str];

        if (cur->isFile)
            return {strs.back()};
        
        vector<string> ans;
        for (auto &p:cur->children) 
            ans.push_back(p.first);
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    void mkdir(string path) {
        vector<string> strs = getpath(path);
        Dentry *cur = root;
        for (auto &str:strs) {
            if (!cur->children.count(str)))
                cur->children[str] = new Dentry();
            cur = cur->children[str];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> strs = getpath(filePath);
        Dentry *cur = root;
        for (string &str : strs) {
            if (!cur->children.count(str))
                cur->children[str] = new Dentry();
            cur = cur->children[str];
        }
        cur->isFile = true;
        cur->content += content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> strs = getpath(filePath);
        Dentry *cur = root;
        for (string &str : strs)
            cur = cur->children[str];
        return cur->content;
    }
