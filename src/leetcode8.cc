#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class AutoMachine{
public:
    AutoMachine():m_state("begin"), m_number(0), m_flag(1){

    }
    int charToTag(char c){
        if(c == ' '){
            return 0;
        }else if(c == '+' || c == '-'){
            return 1;
        }else if(c >= '0' && c <= '9'){
            return 2;
        }else{
            return 3;
        }
    }
    void changeState(char c){
        m_state = m_states[m_state][charToTag(c)];

        if(m_state == "in flag"){
            m_flag = c == '+' ? 1 : -1;
        }else if(m_state == "in number"){
            m_number = m_number * 10 + (c - '0');
            if(m_flag == 1 && m_number > INT32_MAX){
                m_number = INT32_MAX;
            }else if(m_flag == -1 && m_number > (int64_t)INT32_MAX + 1){
                m_number = (int64_t)INT32_MAX + 1;
            }
        }
    }
    int getResult(){
        return m_flag * m_number;
    }
    bool isStop(){
        return m_state == "end";
    }
private:
    unordered_map<string, vector<string>> m_states = {
        {"begin", {"begin", "in flag", "in number", "end"}},
        {"in flag", {"end", "end", "in number", "end"}},
        {"in number", {"end", "end", "in number", "end"}},
        {"end", {"end", "end", "end", "end"}},
    };
    string m_state;
    int64_t m_number;
    int m_flag;
};


class Solution {
public:
    int myAtoi(string s) {
        AutoMachine am;
        for(auto it : s){
            if(am.isStop() == false){
                am.changeState(it);
            }else{
                break;
            }
        }

        return am.getResult();
    }
};