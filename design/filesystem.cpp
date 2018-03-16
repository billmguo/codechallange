struct Dentry {
    Dentry(const bool& flag) : isFile(flag) {}
    bool isFile;
    map<string, Dentry*> entries;
    string content; 
};

class FileSystem {
private:
    Dentry* root;
public:
    FileSystem() {
        root = new Dentry(false);
    }
    
    vector<string> ls(string path) {
        Dentry* dentry = getLastDentry(root, path, 0);
        vector<string> res;
        if (dentry->isFile) {
            int idx = path.find_last_of('/') + 1;    
            res.push_back(path.substr(idx));
        } else {
            for (auto iter = dentry->entries.begin(); iter != dentry->entries.end(); ++iter) {
                    res.push_back(iter->first);     
            } 
        }
        return res; 
    }
    
    void mkdir(string path) {
        getLastDentry(root, path, 0);
    }
    
    void addContentToFile(string filePath, string content) {
        Dentry* dentry = getLastDentry(root, filePath, 0);
        dentry->isFile = true;
        dentry->content += content;
    }
    
    string readContentFromFile(string filePath) {
        Dentry* dentry = getLastDentry(root, filePath, 0);
        return dentry->content;
    }
    
private:
    Dentry* getLastDentry(Dentry* dentry, const string& path, int idx) {
        if ( ++idx >= path.size()) {
            return dentry;
        }
        int next_slash_idx = path.find_first_of('/', idx);
        if (next_slash_idx == -1) {
            next_slash_idx = path.size();
        }
        string name = path.substr(idx, next_slash_idx - idx);
        auto& next_dentry = dentry->entries[name];
        if (next_dentry == NULL) { 
            next_dentry = new Dentry(false);
        }
        return getLastDentry(next_dentry, path, next_slash_idx);
    }
};
