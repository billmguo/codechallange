#include <iostream>
#include <stack>
using namespace std;

int evaluate(const string& f, int &x, int &y, int &z) {
    int cur_sum_y = 0;
    int cur_sum_x = 0;
	int cur_sum_num = 0;
    int last_op = 1, bracket_op = 1;
    stack<int> brackets;
    for(int i = 0; i <= f.size(); ++i) {
        char c = f[i];
        if(isdigit(f[i])) {
            int over = i + 1;
            while( over< f.size() && isdigit(over)) 
                ++over;
            int number = stoi(f.substr(i,over-i)) * last_op * bracket_op;
            if(f[over] == 'x') {
                cur_sum_x += number;
                cout<<number<<endl;
                i = over;
            } else if(f[over] == 'y') {
                cur_sum_y += number;
               /* cout<<last_op<<endl;
                cout<<bracket_op<<endl;
                cout<<cur_sum_y<<endl;*/
                i = over;
            } else {
                cur_sum_num += number;
                i = over - 1;
            }
        }else if( c == 'x' ) {
            cur_sum_x += last_op * bracket_op;
        } else if( c == 'y' ){
            cur_sum_y += last_op * bracket_op;
        } else if( c == '(' ) {
        	brackets.push(last_op);
            bracket_op *= last_op;
          	last_op = 1;
        } else if( c == ')' ) {
            bracket_op *= brackets.top();
            brackets.pop();
        } else if( c == '+' || c =='-') {
            last_op = (c == '+')?1:-1;
        } else if (c == '=') {
        	bracket_op = -1 ;
        	last_op = 1;
       	} 	
    }
}

int main() {
	// your code goes here
	string s{"5 + 2x - ( 3y + 2x - ( 7 - 2x ) - 9 ) = 2y + 1"};
	evaluate(s);
	return 0;
}
