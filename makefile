programa: bin/programa
test: bin/programa_test

test: bin/programa_test




build/programa_test.o: test/test.c build
	gcc -I thirdparty -I src -c test/test.c -o build/programa_test.o
build/main.o: src/main.c build
	gcc  -Wall -Werror -c src/main.c -o build/main.o
build/board.o: src/board.c build
	gcc -Wall -Werror -c src/board.c -o build/board.o
build/board_print.o: src/board_print.c
	gcc  -Wall -Werror -c src/board_print.c -o build/board_print.o
bin/programa: build/main.o build/board.o build/board_print.o bin
	gcc -Wall -Werror build/main.o build/board.o build/board_print.o -lm -o bin/programa
	
bin/programa_test: build/programa_test.o build/board.o build/board_print.o bin
	gcc -Wall -Werror build/programa_test.o build/board.o build/board_print.o -lm -o bin/programa_test


.PHONY : clean runprog

runprog:
	g++ build/main.o build/board.o build/board_print.o
	./*.out

bin:
	mkdir bin

build:
	mkdir build

clean:
	rm -rf build
	rm -rf bin
