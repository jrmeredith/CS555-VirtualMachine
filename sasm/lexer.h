#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>
using namespace std;

typedef uint8_t byte;
typedef vector<string> strings;

enum State : byte {
	START,
	READCHAR,
	READBLOCK,
	SKIP,
	DUMP,
	COMMENT,
	END
};

class Lexer {
private:
	bool my_isSpace(char c);
	bool isSpecial(char c);
	bool isGroup(char c);
	char end_char, beg_char;

public:
	strings lex(string s);
};

#endif // !LEXER_H