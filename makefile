prefixe=compilateur

all: $(prefixe).y $(prefixe).l
	yacc -d -v $(prefixe).y
	flex $(prefixe).l
	gcc y.tab.c lex.yy.c Lib/symbol.c Lib/quad.c Lib/mips.c -ly -lfl -std=gnu99 -g


clean:
	rm *.o y.tab.c lex.yy.c y.tab.h a.out
