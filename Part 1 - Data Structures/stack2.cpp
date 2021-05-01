#include <iostream>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

/*Stack: Parantheses problems
isBalanced,closingIndex, encodeParantheses, maxDepth, maxBalancedLength, minRev*/

bool isBalanced(string str){
    stack<char> stk;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(') stk.push(str[i]);
        if(str[i]==')'){
            if(stk.empty() || stk.top()==')') return false;
            if(stk.top()=='(') stk.pop();
        }
    }
    if(stk.empty()) return true;
    return false;
}

int closingIndex(string str,int openingIndex){
    if(str[openingIndex]!=')') return -1;
    stack<int> stk;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(') stk.push(str[i]);
        if(str[i]==')'){
            stk.pop();
            if(stk.empty()) return i;
        }
    }
    return -1;
}

string encodeParantheses(string str){
    stack<int> stk;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(') stk.push(i);
        if(str[i]==')'){
            if(!stk.empty()){
                str.replace(i,1,"1");
                str.replace(stk.top(),1,"0");
                stk.pop();
            }
            else str.replace(i,1,"-1");
        }
    }
    while(!stk.empty()){
        str.replace(stk.top(),1,"-1");
        stk.pop();
    }
    return str;
}

int maxDepth(string str){
    int ans = 0, temp = 0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            temp++;
            ans = max(ans,temp);
        }
        if(str[i]==')'){
            if(temp<=0) return -1;
            else temp--;
        }
    }
    if(temp==0) return ans;
    return -1;
}

int maxBalancedLength(string str){
    stack<int> stk;
    stk.push(-1);
    int len=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(') stk.push(i);
        if(str[i]==')'){
            stk.pop();
            if(!stk.empty()) len=max(len,i-stk.top());
            else stk.push(i);
        }
        cout<<str[i]<<"\t"<<len<<endl;
    }
    return len;
}

int minRev(string str){
    if(str.length()%2==1) return -1;
    stack<char> stk;
    for(int i=0;i<str.length();i++){
        if(!stk.empty() && stk.top()=='(' && str[i]==')') stk.pop();
        else stk.push(str[i]);
    }
    int n=stk.size(),m=0;
    while(!stk.empty() && stk.top()=='('){
        stk.pop(); m++;
    }
    return n/2+m%2;
}

/*Stack: Expression Evaluation problems
checkRedundancy, simplify
Infix2Postfix, Prefix2Postfix, Infix2Prefix, Postfix2Prefix, Prefix2Infix, Postfix2Infix
evaluatePostfix, evaluatePrefix, evaluateInfix,*/

bool checkRedundancy(string str){
    stack<char> stk;
    for(int i=0;i<str.length();i++){
        if(str[i]==')'){
            char top = stk.top();
            stk.pop();

            int c=0;
            while(top!='('){
                c++;
                top=stk.top();
                stk.pop();
            }
            if(c==0||c==1) return true;
        }
        else stk.push(str[i]);
    }
    return false;
}

string simplify(string exp){
    //Constraint: Expression should contain only + and - operators.
    string str="";
    stack<int> stk;
    stk.push(0);

    for(int i=0;i<exp.length();i++){
        if (exp[i]=='+'){
            if (stk.top()==1) str += '-';
            if (stk.top()==0) str += '+';
        }
        else if (exp[i]=='-'){
            if (stk.top()==1) str += '+';
            if (stk.top()==0) str += '-';
        }
        else if (exp[i]=='(' && i>0) {
            if (exp[i - 1]=='+') stk.push(stk.top());
            if (exp[i - 1]=='-'){
                if(stk.top()==1) stk.push(0);
                else stk.push(1);
            }
        }
        else if (exp[i]==')') stk.pop();
        else str += exp[i];
    }
    return str;
}

string Infix2Postfix(string exp){
    string str="";
    stack<int> stk;

    map<char,int> prec;
    prec['+'] = 1; prec['-'] = 1;
    prec['*'] = 2; prec['/'] = 2;
    prec['^'] = 3;

    for(int i=0;i<exp.length();i++){
        if(isalpha(exp[i])) str+= exp[i];

        else if(exp[i]=='(') stk.push(exp[i]);

        else if(exp[i]==')'){
            while(!stk.empty() && stk.top()!='('){
                str+=stk.top(); stk.pop();
            }
            if(!stk.empty() && stk.top()!='(') return "";
            else stk.pop();
        }
        else{
            while(!stk.empty() && prec[exp[i]]<=prec[stk.top()]){
                str+=stk.top(); stk.pop();
            }
            stk.push(exp[i]);
        }
    }
    while(!stk.empty()){
        str+=stk.top(); stk.pop();
    }
    return str;
}

string Prefix2Postfix(string exp){
    stack<string> stk;
    for(int i=exp.length()-1;i>=0;i--){
        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'){
            string top1 = stk.top(); stk.pop();
            string top2 = stk.top(); stk.pop();
            stk.push(top1+top2+exp[i]);
        }
        else stk.push(string(1,exp[i]));
    }
    return stk.top();
}

string Infix2Prefix(string exp){
    string infix = exp;
    reverse(infix.begin(),infix.end());

    for(int i=0;i<infix.length();i++){
        if(infix[i]=='('){
            infix[i]=')'; i++;
        }
        if(infix[i]==')'){
            infix[i]='('; i++;
        }
    }

    string prefix = Infix2Postfix(infix);
    reverse(prefix.begin(),prefix.end());

    return prefix;
}

string Postfix2Prefix(string exp){
    stack<string> stk;
    for(int i=0;i<exp.length();i++){
        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'){
            string top1 = stk.top(); stk.pop();
            string top2 = stk.top(); stk.pop();
            stk.push(exp[i]+top2+top1);
        }
        else stk.push(string(1,exp[i]));
    }
    return stk.top();
}

string Prefix2Infix(string exp){
    stack<string> stk;
    for(int i=exp.length()-1;i>=0;i--){
        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='/'){
            string top1 = stk.top(); stk.pop();
            string top2 = stk.top(); stk.pop();
            stk.push("("+top1+exp[i]+top2+")");
        }
        else stk.push(string(1,exp[i]));
    }
    return stk.top();
}

string Postfix2Infix(string exp){
    stack<string> stk;
    for(int i=0;i<exp.length();i++){
        if(isalpha(exp[i])){
            string op(1,exp[i]);
            stk.push(op);
        }
        else{
            string top1 = stk.top(); stk.pop();
            string top2 = stk.top(); stk.pop();
            stk.push("("+top2+exp[i]+top1+")");
        }
    }
    return stk.top();
}

int evaluatePostfix(string exp){
    stack<int> stk;

    for(int i=0;i<exp.length();i++){
        if(exp[i]==' ') continue;

        else if(isdigit(exp[i])){
            int num=0;
            while(isdigit(exp[i])){
                num = 10*num + (int)(exp[i]-'0');
                i++;
            }
            i--;
            stk.push(num);
        }

        else{
            int top1 = stk.top(); stk.pop();
            int top2 = stk.top(); stk.pop();
            if(exp[i]=='+') stk.push(top2+top1);
            if(exp[i]=='-') stk.push(top2-top1);
            if(exp[i]=='*') stk.push(top2*top1);
            if(exp[i]=='/') stk.push(top2/top1);
        }
    }

    return stk.top();
}

int evaluatePrefix(string exp){
    string postfix = Prefix2Postfix(exp);
    return evaluatePostfix(postfix);
}

int evaluateInfix(string exp){
    string postfix = Infix2Postfix(exp);
    return evaluatePostfix(postfix);
}

int main(){
    string str="(())()";
    if(isBalanced(str)) cout<<"Yes"<<endl;

    string prefix ="-a+bc";
    string infix = "a-(b+c)";
    string postfix="abc+-";

    cout<<Infix2Prefix(infix)<<endl;

    string exp = "10 8 9 + -";
    cout<<evaluatePostfix(exp)<<endl;

    return 0;
}
