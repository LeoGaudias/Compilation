prefixe=compilateur

all: $(prefixe).y $(prefixe).l
	yacc -d -v $(prefixe).y
	flex $(prefixe).l
	#gcc y.tab.c lex.yy.c -ly -lfl
  #gcc y.tab.c lex.yy.c Lib/symbol.c Lib/quad.c Lib/quad_list.c -ly -lfl -std=gnu99
  gcc y.tab.c lex.yy.c Lib/symbol.c Lib/quad.c -ly -lfl -std=gnu99


clean:
	rm *.o y.tab.c lex.yy.c y.tab.h a.out
