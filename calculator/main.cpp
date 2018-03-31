#include "error.h"
#include "lexer.h"
#include "parser.h"
#include "table.h"
#include "driver.h"
#include <sstream>
#include <iostream>
#include <cctype>

using namespace std;
using namespace Driver;
using namespace Lexer;


int main(int argc, char*argv[]){
	switch (argc) {
		case 1:			 // 无传入参数
			input = &cin;
			break;
		case 2:			 // 读取cmd传入的表达式
			input = new istringstream(argv[1], strlen(argv[1]));
			break;
		default:
			cerr << "只能解决一个表达式！！！\n";
			return 1;
	}

	// insert pre-defined names:
	Symbol_table::table["pi"] = 3.1415926535897932385;
	Symbol_table::table["e"] = 2.7182818284590452354;

	while (*input) {
		cout << "请输入表达式:\n";
		try {
			Lexer::get_token();
			if (Lexer::curr_tok == Lexer::END) break;
			if (Lexer::curr_tok == Lexer::PRINT) continue;
			cout << Parser::expr(false) << '\n';
		}
		catch (Error::Zero_divide) {
			cerr << "attempt to divide by zero\n";
			skip();
		}
		catch (Error::Syntax_error e) {
			cerr << "syntax error:" << e.p << "\n";
			skip();
		}
	}

	if (input != &std::cin) delete input;
	return no_of_errors;
}