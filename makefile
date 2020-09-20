.PHONY: distclean play

CC=gcc
CFLAGS=-W -Wall
EXEC=battleGame
EXECDIR=/cmd
OBJ=random.o print.o fill.o init.o game.o battleGame.o
OBJDIR=./obj
SRC=./src
RM=rm -f
all: $(EXEC)
 
$(EXEC): $(OBJ)
	cd $(OBJDIR) ; gcc $(OBJ) -o ../cmd/battleGame

random.o: 
	$(CC) $(CFLAGS) $(SRC)/random/random.c -c -o $(OBJDIR)/random.o

print.o:
	$(CC) $(CFLAGS) $(SRC)/utils/print.c -c -o $(OBJDIR)/print.o

fill.o:
	$(CC) $(CFLAGS) $(SRC)/utils/fill.c -c -o $(OBJDIR)/fill.o

init.o: 
	$(CC) $(CFLAGS) $(SRC)/init/init.c -c -o $(OBJDIR)/init.o

game.o:
	$(CC) $(CFLAGS) $(SRC)/game/game.c -c -o $(OBJDIR)/game.o

$(EXEC).o:
	$(CC) $(CFLAGS) $(SRC)/main/$(EXEC).c -c -o $(OBJDIR)/$(EXEC).o

distclean:
	cd $(OBJDIR); $(RM) *.o; cd ..$(EXECDIR); $(RM) $(EXEC)

play:
	./cmd/battleGame