class Folder;

class Common {
    string m_name;
    Folder* m_parent;
    long lastUpdated;
    long lastAccessed;
    
public:
    Common(std::string const & name):m_name(name),m_parent(nullptr){}
    virtual ~Common(){};
    virtual void open() { /*Whatever*/}
    virtual void draw() const {/*Whatever*/}
    virtual Folder* getParent() const { return m_parent; };
    virtual void setParent(Folder* parent);
};

class Folder : public Common {
    unordered_set<Common*> m_child;
public:
    Folder(const string & name): Common(name){}
    virtual void open(){/*Whatever*/}
    virtual void draw() const {/*Whatever*/}
    int getsize() {
        int size = 0;
        for (auto e:m_child)
            size += e->size();
        return size;
    }

    int numberOfFiles()  {
        int count = 0;
        for (auto e : m_child){
            if (Folder *v == dynamic_cast<Folder*> e){
                count++; // Directory counts as a file
                count += d->numberOfFiles ();
            }
            else if  (File *f == dynamic_cast<File*> e)       
                count++;            
        }
        return count;
    }
 
    void addChild(Common * child) {
        auto parent = child -> getParent();
        if (parent && parent != this) {
            parent ->removeChild(child);
        }
        if (!m_child.count(child)) {
            child->setParent(this);
            m_child.insert(child);
            
        }
    }
    void removeChild(Common* child) {
        if (m_child[child])
            m_child.erase(child);
    }
};

class File : public Common {
    // Whatever
    int size;
    string content; 
public:
    File(std::string const & name): Common(name){}
    string getcontents() {
        return contents;
    }
    void setcontents(string &c) {
        content = c;
    }
    virtual void open(){/*Whatever*/};

};
