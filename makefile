target: lex.yy.o	y.tab.o
	gcc y.tab.c lex.yy.c -ll -ly -o mycompiler
		

y.tab.c y.tab.h: test.y 
	yacc -d test.y

lex.yy.o: lex.yy.c y.tab.h
	gcc -c lex.yy.c

y.tab.o: y.tab.c
	cc -c y.tab.c

lex.yy.c: test.l
	lex test.l


clean:
	rm -f .o lex.yy.c y.tab.
