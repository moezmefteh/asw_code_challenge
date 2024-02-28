CC = gcc

.PHONY: all clean

all:

	$(CC) main.c i2c.c lis3mdl_driver.c -o main.exe

clean:
	$(RM) -r $(OBJ_DIR) $(BIN_DIR)
