CC = gcc
AR = ar -rcs
FLAGS = -Wall -g
OBJECTS_MAIN = main.o
OBJECT_MY_FUNCS = MyFuncs.o

all: stringProg funcs funcd

funcs: libclassmyFunc.a

funcd: libclassmyFunc.so

libclassmyFunc.a:$(OBJECT_MY_FUNCS)
		$(AR) libclassmyFunc.a $(OBJECT_MY_FUNCS)

libclassmyFunc.so:$(OBJECT_MY_FUNCS)
		$(CC) -shared -o libclassmyFunc.so $(OBJECT_MY_FUNCS)

stringProg:$(OBJECTS_MAIN) libclassmyFunc.a
		$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN) libclassmyFunc.a

main.o: main.c MyFuncs.h
		$(CC) $(FLAGS) -c main.c

MyFuncs.o: MyFuncs.c MyFuncs.h
		$(CC) $(FLAGS) -c MyFuncs.c

.PHONY: clean all

Clean:
		rm -f *.o *.a *.so *.txt stringProg funcs funcd