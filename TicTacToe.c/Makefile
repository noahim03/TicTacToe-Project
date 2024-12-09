
tic_tac_toe.out: board.o game.o input_val.o main.o move.o player.o read_any_length.o win.o
	gcc -Wall -Werror -g -o tic_tac_toe.out board.o game.o input_val.o main.o move.o player.o read_any_length.o win.o

board.o: board.c move.h board.h
	gcc -Wall -Werror -g -c board.c

game.o: game.c game.h board.h player.h move.h
	gcc -Wall -Werror -g -c game.c

input_val.o: input_val.c input_val.h
	gcc -Wall -Werror -g -c input_val.c

main.o: main.c game.h board.h player.h move.h
	gcc -Wall -Werror -g -c main.c

move.o: move.c move.h board.h
	gcc -Wall -Werror -g -c move.c

player.o: player.c player.h move.h board.h game.h input_val.h read_any_length.h
	gcc -Wall -Werror -g -c player.c

read_any_length.o: read_any_length.c read_any_length.h	
	gcc -Wall -Werror -g -c read_any_length.c

win.o: win.c win.h board.h	
	gcc -Wall -Werror -g -c win.c

clean:
	rm -f *.o *.out
