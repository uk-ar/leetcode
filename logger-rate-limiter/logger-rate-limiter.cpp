class Logger {
public:
    unordered_map<string,int>m;
    Logger() {
        
    }
    
    bool shouldPrintMessage(int t, string mes) {
        if(m.count(mes)==0 or m[mes]+10<=t){
            m[mes]=t;
            return true;
        }
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */