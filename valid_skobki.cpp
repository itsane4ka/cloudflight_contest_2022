class Solution {
public:
    bool isEven (string s)
    {
        if (s.size() % 2 == 0)
            return true;
        else
            return false;
    }
        
    bool isValid(string s) {
        if (!isEven(s)) return false;
        string str_flag = s;
        while (!s.empty())
        {
            if (!s.empty())
            {
                if (s.find("()") < s.size()-1)
                {
                    s.erase(s.find("()"), 2);
                }
            }
            if (!s.empty())
            {
                if (s.find("[]") < s.size()-1)
                {
                    s.erase(s.find("[]"), 2);
                }
            }
            if (!s.empty())
            {
                if (s.find("{}") < s.size()-1)
                {
                    s.erase(s.find("{}"), 2);
                }
            }
            if (str_flag == s)
                return false;
            str_flag = s;
        }
        return true;
    }
};