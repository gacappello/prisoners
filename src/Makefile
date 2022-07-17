CC=gcc
CFLAGS=-Wall -pedantic -g

ODIR=obj
IDIR=../includes

_DEPS=game.h logic.h box.h prisoner.h
_OBJ=main.o box.o prisoner.o logic.o
 
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))
DEPS=$(patsubst %,$(IDIR)/%,$(_DEPS))

$(ODIR)/%.o: %.c $(IDIR)/$(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: prisoners

.PHONY: clean debug prisoners

prisoners: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ 

