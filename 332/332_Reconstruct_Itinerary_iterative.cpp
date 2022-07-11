// @algorithm @lc id=332 lang=cpp 
// @title reconstruct-itinerary


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <functional>
#include <stack>
#include "algm/algm.h"
using namespace std;
// @test([["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]])=["JFK","MUC","LHR","SFO","SJC"]
// @test([["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]])=["JFK","ATL","JFK","SFO","ATL","SFO"]
// @test([["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]])=["JFK","NRT","JFK","KUL"]
// @test([["EZE","TIA"],["EZE","HBA"],["AXA","TIA"],["JFK","AXA"],["ANU","JFK"],["ADL","ANU"],["TIA","AUA"],["ANU","AUA"],["ADL","EZE"],["ADL","EZE"],["EZE","ADL"],["AXA","EZE"],["AUA","AXA"],["JFK","AXA"],["AXA","AUA"],["AUA","ADL"],["ANU","EZE"],["TIA","ADL"],["EZE","ANU"],["AUA","ANU"]]) = []

class Solution {
public:
    vector<string> ans = {};
    stack<string> stk;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, priority_queue<string, vector<string>, greater<string>>> mp;
        int tic_size = tickets.size();
        for (auto vs: tickets) {
            mp[vs[0]].push(vs[1]);
        }
        stk.push("JFK");
        auto ticket_it = mp.find("JFK");
        while(ticket_it != mp.end() || !stk.empty()) {
            if (ticket_it != mp.end()) {
                stk.push(ticket_it->second.top());
                ticket_it->second.pop();
                if (ticket_it->second.empty()) {
                    mp.erase(ticket_it);
                }
                ticket_it = mp.find(stk.top());
            } else {
                if (stk.size() == tic_size + 1) {
                    while (!stk.empty()) {
                        ans.push_back(stk.top());
                        stk.pop();
                    }
                } else {
                    ans.push_back(stk.top());
                    stk.pop();
                    if (!stk.empty()) {
                        ticket_it = mp.find(stk.top());
                    }
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans; 
    }

};