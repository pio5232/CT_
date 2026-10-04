class Solution {
public:
    enum { LEFT_PAR = 0, RIGHT_PAR, STAR, ENUM_MAX };
    bool checkValidString(string s) {

        stack<int> par_stack;
        stack<int> star_stack;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                par_stack.push(i);
            else if (s[i] == '*')
                star_stack.push(i);
            else // (s[i] == ')')
            {
                if (par_stack.size())
                    par_stack.pop();
                else if (star_stack.size())
                    star_stack.pop();
                else
                    return false;
            }

            // cout << format("i : {}, s[i] : {}, cnt '(' : {}, cnt '*' : {}\n",i, s[i], par_stack.size(), star_stack.size());
        }

        // (이 남은 경우
        while (par_stack.size()) 
        {
            if(star_stack.empty())
            return false;

            if(star_stack.top() < par_stack.top())
            return false;

            par_stack.pop();
            star_stack.pop();
        }
        return true;
    }
};