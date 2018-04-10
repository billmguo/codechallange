class FileSystem {
public:
    FileSystem() {
        
    }
    
    vector<string> ls(string path) {
        auto pn = GetNode(path);
        if (pn->is_file)
            return {pn->name};

        vector<string> vs;
        for (auto a:pn->childs)
            vs.push_back(p.first);
        return vs;
    }
    
    void mkdir(string path) {
        auto pn = GetNode(path);
    }
    
    void addContentToFile(string filePath, string content) {
        auto pn = GetNode(filePath);
        pn->is_file = true;
        pn->content += content;
    }
    
    string readContentFromFile(string filePath) {
        auto pn = GetNode(filePath);
        return pn->content;
    }

private:
    struct Node{
        string name;
        string content;
        bool is_file = false;
        map<string, Node*> childs;           
    };
    
    Node* GetNode(const string& path){
        auto p = root;
        stringstream ss(path);
        string token;
        while(getline(ss, token, '/')) {            
            if(token.empty()) continue;            
            if(!p->childs.count(token)){
                p->childs[token] = new Node();
            }            
            p = p->childs[token];
            p->name = token;
        }            
        return p;
    }    
    
    Node* root = new Node();  
};
