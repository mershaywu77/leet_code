#include <map>
#include <iostream>

class Solution {
public:
    int romanToInt(string s) 
    {
        int result = 0;
        while (s.length())        
        {
            if (s.length()>=2)
            {
                string symbol = s.substr(0,2);
                auto it = m_roman_map.find(symbol);
                if (it != m_roman_map.end())
                {
                    result += it->second;
                    s = s.substr(2, s.length()-2);
                    continue;
                }
            }
            string symbol = s.substr(0,1);
            auto it = m_roman_map.find(symbol);
            if (it != m_roman_map.end())
            {
                result += it->second;
                s = s.substr(1, s.length()-1);
            }
            else
            {
                cout<<"Incorrect Input:"<< s << endl;
            }
        }
        return result;
    };
    Solution()
    {
        m_roman_map["CM"] = 900;
        m_roman_map["M"] = 1000;
        m_roman_map["CD"] = 400;
        m_roman_map["D"] = 500;
        m_roman_map["XC"] = 90;
        m_roman_map["C"] = 100;
        m_roman_map["XL"] = 40;
        m_roman_map["L"] = 50;
        m_roman_map["IX"] = 9;
        m_roman_map["X"] = 10;
        m_roman_map["IV"] = 4;
        m_roman_map["V"] = 5;
        m_roman_map["I"] = 1;
    };
private:
    std::map<string,int> m_roman_map;   
};
