all: server client

IDIR =../include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj

LIBS= -static -lcryptopp

_DEPS = studentscode.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJSERV = studentscode.o server.o 
OBJSERV = $(patsubst %,$(ODIR)/%,$(_OBJSERV))

_OBJCLI = studentscode.o client.o 
OBJCLI = $(patsubst %,$(ODIR)/%,$(_OBJCLI))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

server: $(OBJSERV)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

client: $(OBJCLI)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~