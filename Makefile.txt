CC = gcc
CFLAGS = -g -Wall --std=c99
OBJECTS = main.o my_string.o generic_vector.o avl_tree.o
TESTOBJECTS = unit_test.o test_def.o

string_driver: $(OBJECTS)
        $(CC) $(CFLAGS) -o string_driver $(OBJECTS)
main.o: main.c
        $(CC) $(CFLAGS) -c main.c -o main.o
my_string.o: my_string.c my_string.h
        $(CC) $(CFLAGS) -c my_string.c -o my_string.o
generic_vector.o: generic.h generic_vector.c generic_vector.h
        $(CC) $(CFLAGS) -c generic_vector.c -o generic_vector.o
avl_tree.o: avl_tree.c avl_tree.h
        $(CC) $(CFLAGS) -c avl_tree.c -o avl_tree.o

unit_test: my_string.o $(TESTOBJECTS)
        $(CC) $(CFLAGS) -o unit_test my_string.o $(TESTOBJECTS)
test_def.o: test_def.c unit_test.h
        $(CC) $(CFLAGS) -c test_def.c -o test_def.o
unit_test.o: unit_test.c
        $(CC) $(CFLAGS) -c unit_test.c -o unit_test.o


clean:
        rm string_driver $(OBJECTS)
clean_test:
        rm unit_test $(TESTOBJECTS)
