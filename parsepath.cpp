/*
parrse成路径，然后返回其中图片文件的路径长度。
*/
int findlongestpath(string s){
    int res = 0;
    int len = s.size();
    if (len == 0) return res;
    int i = 0;
    int pre = 0;
    int level = 0;
    unordered_map<string,int> hmap;
    while( i < len ) {
        int count = 0;
        while(i<len && s[i]!='\n' && isvalid(s[i])) i++;
        string sub = s.substr(0,i-pre);
        hmap[level] = sub;
        while(i<len && s[i++]=='\t' && isvalid(s[i])) { count++; level = count };
        if (isfilename(sub)){
            string filepath;
            for (int i=0;i<level;i++){
                filepath = filepath + hmap[i] + "/";
            }
            filepath += sub;
            if (filepath.size() > maxl)
            {
                res = filepath;
            }
        }        
    }
    return res;
}

