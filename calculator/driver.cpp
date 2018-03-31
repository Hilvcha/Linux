#include "driver.h"
int Driver::no_of_errors;

std::istream *Driver::input;

void Driver::skip() {         //丢弃字符直到换下一个句
	Driver::no_of_errors++;

	while (*Driver::input) {
		char ch;
		Driver::input->get(ch);

		switch (ch) {
			case '\n':
			case ';':
				return;
		}
	}
}