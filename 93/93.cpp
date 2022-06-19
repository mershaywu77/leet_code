class Solution {
private:
    vector<string> res;
    string ip;
    int ip_sub; // how many segment are analyzed
    // s[start]..s[end] is a valid sub net segment
    // 02 is invalid, >255 is invalid, non digit str is invalid
    bool isValid(const string& s, int start, int end)
    {
        int num = 0;
        if (start > end) //important to exlcude empty str
            return false;
        if (s[start] == '0' && start != end)
            return false;
        if (end - start >= 3)
            return false;
        for(int i = start; i <= end; i++)
        {
            if (!isdigit(s[i]))
                return false;
            num = num*10 + s[i] - '0';
            if (num > 255)
                return false;
        }
        return true;
    }
    void backtrack(const string& s, int start, string& ip)
    {
        if (ip_sub == 3)
        {
            if (isValid(s, start, s.size()-1))
            {
                res.push_back(ip + s.substr(start));
            }
            return;
        }
        for(int i = start; i < s.size() && i - start < 3; ++i)
        {
            if (isValid(s, start, i))
            {
                string cache = ip;
                ip.append(s.substr(start, i-start+1));
                ip.push_back('.');
                ++ip_sub;
                backtrack(s, i + 1, ip);
                --ip_sub;
                ip = cache;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        //min s like "0000", max like "255255255255"
        int n = s.size();
        if (n < 4 || n > 12)
            return res;
        backtrack(s, 0, ip);
        return res;
    }
};