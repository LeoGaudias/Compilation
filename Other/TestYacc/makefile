prefixe=test

all: $(prefixe).y $(prefixe).l
	yacc -d $(prefixe).y
	flex $(prefixe).l
	gcc y.tab.c lex.yy.c matrix.c -ly -lfl
	# gcc y.tab.c lex.yy.c symbol.c quad.c -ly -lfl

clean:
	rm *.o y.tab.c lex.yy.c y.tab.h a.out
