class FileSystem {
public:
    class File {
        public:
            bool isDir = true;
            unordered_map<string, File*> files;
            string content = "";

            File() {}

            File(bool id) {
                isDir = id;
            }
    };
    
    File* root;
    
    FileSystem() {
        root = new File();
    }
    
    vector<string> ls(string path) {
        File* cur = root;
        int next=0,prev=1;
        while ((next = path.find('/', prev)) != string::npos) {
            cur = cur->files[path.substr(prev, next-prev)];
            prev = next+1;
        }
        // leftover segment after last slash
        // watch out for "/" input, only do this if there's a segment
        // after the first /
        if (path.substr(prev).size() != 0) {
            cur = cur->files[path.substr(prev, next-prev)];
        }
        
        vector<string> ret;
        if (cur->isDir) {
            for (const auto& f : cur->files) {
                ret.push_back(f.first);
            }
        } else {
            ret.push_back(path.substr(prev));
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
    
    void mkdir(string path) {
        File* cur = root;
        int next=0,prev=1;
        while ((next = path.find('/', prev)) != string::npos) {
            string pathSegment = path.substr(prev, next-prev);
            if (cur->files.find(pathSegment) == cur->files.end()) {
                cur->files.insert({pathSegment, new File()});
            }
            cur = cur->files[pathSegment];
            prev = next+1;
        }
        // leftover segment after last slash
        string pathSegment = path.substr(prev);
        if (cur->files.find(pathSegment) == cur->files.end()) {
            cur->files.insert({pathSegment, new File()});
        }
    }
    
    void addContentToFile(string filePath, string content) {
        File* cur = root;
        int next=0,prev=1;
        while ((next = filePath.find('/', prev)) != string::npos) {
            string pathSegment = filePath.substr(prev, next-prev);
            if (cur->files.find(pathSegment) == cur->files.end()) {
                cur->files.insert({pathSegment, new File(false)});
            }
            cur = cur->files[pathSegment];
            prev = next+1;
        }
        // leftover segment after last slash
        string pathSegment = filePath.substr(prev);
        if (cur->files.find(pathSegment) == cur->files.end()) {
            cur->files.insert({pathSegment, new File(false)});
        }
        cur = cur->files[pathSegment];
        cur->content += content;
    }
    
    string readContentFromFile(string filePath) {
        File* cur = root;
        int next=0,prev=1;
        while ((next = filePath.find('/', prev)) != string::npos) {
            cur = cur->files[filePath.substr(prev, next-prev)];
            prev = next+1;
        }
        // leftover segment after last slash
        cur = cur->files[filePath.substr(prev)];
        return cur->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
