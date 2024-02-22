CC = gcc
CFLAGS =
SRC = main.c update_board.c count_cell_neighbors.c initialize_board.c print_board.c
OBJ = $(SRC:.c=.o)
ASM = $(OBJ:.o=.s)
EXE = game.exe

all: $(EXE)

ncurses: $(SRC)
	$(CC) $(SRC) -lncurses -Wno-deprecated-declarations
	@echo "Start program with ./a.exe"

$(EXE): $(OBJ)
	@echo "Compiling program..."
	$(CC) -o $(CFLAGS) $(EXE) $(OBJ)

main.o: main.c
	@echo "Compiling main..."
	$(CC) $(CFLAGS) -c main.c

count_cell_neighbors.o: count_cell_neighbors.c
	@echo "Compiling count_cell_neighbors..."
	$(CC) $(CFLAGS) -c count_cell_neighbors.c

update_board.o: update_board.c
	@echo "Compiling update_board..."
	$(CC) $(CFLAGS) -c update_board.c

initialize_board.o: initialize_board.c
	@echo "Compiling initialize_board..."
	$(CC) $(CFLAGS) -c initialize_board.c

print_board.o: print_board.c
	@echo "Compiling print_board..."
	$(CC) $(CFLAGS) -c print_board.c

asm: $(ASM)

$(ASM): $(SRC)
	@echo "Compiling all files to assembler..."
	$(CC) $(CFLAGS) -S $< -o $@

clean:
	@echo "Removing everything but the source files..."
	del $(OBJ) game.exe $(ASM) a.exe