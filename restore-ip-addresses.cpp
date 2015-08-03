 vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        if(s.size() > 12)
            return ret;
        for(int i = 0; i < s.size(); i ++)
        {// [0, i]
            for(int j = i+1; j < s.size(); j ++)
            {// [i+1, j]
                for(int k = j+1; k < s.size()-1; k ++)
                {// [j+1, k], [k+1, s.size()-1]
                    string ip1 = s.substr(0, i+1);
                    string ip2 = s.substr(i+1, j-i);
                    string ip3 = s.substr(j+1, k-j);
                    string ip4 = s.substr(k+1);
                    if(check(ip1) && check(ip2) && check(ip3) && check(ip4))
                    {
                        string ip = ip1 + "." + ip2 + "." + ip3 + "." + ip4;
                        ret.push_back(ip);
                    }
                }
            }
        }
        return ret;
    }
    bool check(string s) {
        if (s.size() > 1 && s[0] == '0') return false;
        int res = atoi(s.c_str());
        return res <= 255 && res >= 0;
    }
};
