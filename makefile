IDIR = inc
CC = gcc
INCFLAGS = -I$(IDIR)

ODIR = obj
SDIR = src

_DEPS = shift_rows_layer.h sub_bytes_layer.h mix_columns_layer.h add_round_key_layer.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = shift_rows_layer.o sub_bytes_layer.o mix_columns_layer.o add_round_key_layer.o AES.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


aes-main : $(OBJ)
	$(CC) -o $@ $^ $(INCFLAGS)

$(OBJ) : $(ODIR)/%.o : $(SDIR)/%.c
	$(CC) -c -o $@ $< $(INCFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
