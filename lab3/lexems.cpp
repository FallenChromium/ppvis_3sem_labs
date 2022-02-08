#import "./bnflite.h"
#import "parsing_tree.hpp"
//From the task
// <предложение> ::= [ <присвоение> ] <выражение>
// <присвоение> ::= <имя_переменной> ‘=’
// <выражение> ::= <терм_выражение> [ <операция> <выражение> ]
// <терм_выражение> ::= <множество>
// | <имя_переменной>
// | <вызов_функции>
// | ‘(’ <выражение> ‘)’
// <множество> ::= ‘{’ [ <элемент> [ ‘,’ <элемент> ] ] ‘}’
// <элемент> ::= <имя> | <множество>
// <имя_переменной> ::= <имя>
// <вызов_функции> ::= <имя> ‘(’ [ <выражение> [ ‘,’ <выражение> ] ] ‘)’
// <операция> ::= ‘+’ | ‘*’ | ‘-’
// <имя> ::= <цифра> | <буква> [ <буква> | ‘_’ | <цифра> ]
// <цифра> ::= ‘0’ | ... | ‘9’
// <буква> ::= ‘A’ | ... | ‘z’

//elementaries - DIGIT




bnf::Token digit("0123456789");
bnf::Token letter('A', 'z');
bnf::Token separator('_');
bnf::Token set_symm_difference('-');
bnf::Token set_intersection('*');
bnf::Token set_union("+");
bnf::Token opening("(");
bnf::Token ending(")");
bnf::Lexem name_extension = letter | separator | digit;
bnf::Lexem name = digit | letter + Iterate(0, name_extension, 1);
bnf::Rule operation = (set_symm_difference  | set_intersection  | set_union) ;
bnf::Lexem parse_set;
bnf::Lexem element = name | parse_set;
bnf::Rule expr;
bnf::Rule expr_next = operation + expr;
bnf::Lexem func_args = expr + Iterate(0,"," + expr);
bnf::Lexem func_call = name + "(" + Iterate(0,func_args,1) + ending; 
bnf::Rule terminal_expr =  (opening  + expr  + ending  | parse_set   | name  | func_call );
bnf::Lexem assignment = name + "=";
bnf::Rule sentence = Iterate(0, assignment) + expr;





