class Codec {

public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
         string str="";
         serialize(root, str);
         return str;
    }
    
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        int index = 0;
        return deserialize(data, index);
    }
    
    void serialize(Node* root, string &str) {
       if (!root)
           return;
        str += '[';
        str += to_string(root->val);
        for (auto a:root->children) {
            serialize(a, str);
        }
        str += ']';
    }
    Node* deserialize(string &data, int index) {
        if (data.empty())
            return NULL;
        if (data[index] == '[')
            index++;
        Node *node = new Node(data[index] - '0');
        index++;
        while (data[index] != ']') {
            node->children.push_back(deserialize(data, index));  
        }
        index++;
        return node;
    }
    
};
