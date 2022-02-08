#include "bnflite.h"
#include "lexems.cpp"
#include "parsing_tree.hpp"
#include <iostream>
#include <memory>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <stack>

std::shared_ptr<Node> current_root;


#include <exception>
#include <stdexcept>
#include <sstream>
using namespace std;

//Custom exception class
class ParserException: public runtime_error {
public:

  ParserException(int status, char *tail)
    : runtime_error( "Parsing error" )
    {}

  virtual const char* what() const throw()
  {
    cnvt.str( "" );

    cnvt << runtime_error::what() << ": " << "status message: " << getStatus()
         << ", failed at" << tail;

    return cnvt.str().c_str();
  }

  int getStatus() const
    { return status; }

  char* getTail() const
    { return tail; }


private:
    int status;
    char* tail;
    static ostringstream cnvt;
};


//opStack = operator stack
std::stack<char> opStack;

std::stack<std::shared_ptr<Node> > printStack;
static bool printFilter(const char* lexem, size_t len)
{
     std::set<std::string> set;
     std::string buffer = "";

     for(int i=1; i< len-1; i++) {
         //switch to next element
        if (lexem[i] == ',' ) {
             set.insert(buffer);
             buffer.clear();
         }

        //code specifically for subsets
        else if (lexem[i] == '{') {
            //read the opening bracket
            buffer=buffer+lexem[i];
            //read everything else
            do {
                i++;
                buffer = buffer+lexem[i];
            } while(lexem[i] != '}');
        }
        //else just continue reading the buffer
        else {
            buffer = buffer+lexem[i];
        }

    }
    //to insert the element before "}"
    set.insert(buffer);
    buffer.clear();
    //add a node in the stack with value = set
    printStack.push(std::make_shared<Node>(set));
	return true;
}

static bool opFilter(const char* lexem, size_t len)
{
   // std::cout << "Shinra tensei! " << lexem[0] << std::endl;
    opStack.push(lexem[0]);
    return true;
}

static bool openFilter(const char* lexem, size_t len)
{
    opStack.push('(');
    // std::cout << "Shinra tensei! " << lexem[0] << std::endl;
    return true;
}

void newnode() {
        char operand = opStack.top();
          std::shared_ptr<Node> node;
            if (operand == '*') {
            node = std::make_shared<Intersect_node>();
            }
            else if (operand == '/') {
                node = std::make_shared<Diff_node>();
            }
            else if (operand == '+') {
                node = std::make_shared<Union_node>(); 
            } 
            opStack.pop();

        node->set_left_child(printStack.top());
        printStack.pop();
        node->set_right_child(printStack.top());
        printStack.pop();
        printStack.push(node);

    }
static bool closeFilter(const char* lexem, size_t len)
{
   // std::cout << "Closing the deal! Currently:" << opStack.top();
    while(opStack.top() != '(') {
        newnode();
}
//get rid of the open bracket
opStack.pop();
return true;
}

void test(std::string input) {
    //Variable to hold the place where we stopped parsing
    const char* tail = 0;
    terminal_expr = terminal_expr;
    bnf::Rule root = sentence;


//Calc result;
int test = Analyze(root, input.c_str(), &tail);

    if (test > 0) {
        std::cout << "Lexems gathered, parenthesis are in correct order" << //Cfg.size()  << 
        std::endl;
        //join the rest of nodes
        while (!opStack.empty()) newnode();
        current_root = printStack.top();
        std::set<std::string> set = current_root->evaluate(); 
        std::cout << "set: {";
        for (auto str:set) std::cout << "," << str; 
        std::cout << "}" << std::endl;
    }
    else
        std::cout << "Parsing errors detected, status = " << std::hex << test << std::endl
         << "stopped at: " << tail << std::endl;
}
        
void init() {
parse_set = "{" + Iterate(0,element + Iterate(0,"," + element)) + "}";
expr = terminal_expr + *expr_next;
terminal_expr =  opening + expr  + ending | parse_set + printFilter  | name + printFilter | func_call + printFilter;
expr_next = operation + opFilter + expr;

}

int main() {
init();
std::string input = "A = {a} + {d} + {a,c} * ({a,c,{}} * {c,d,a}) + ({a,c} + {a,c} * {a,d}) + {a,b,{c,d},c,d} + (({a,d} * {a,b,c}) + {a,cd,{}})"; //правильный ответ: 
//remove spaces from the input
input.erase(remove(input.begin(), input.end(), ' '), input.end());
test(input);
}

