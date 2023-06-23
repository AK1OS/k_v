cc=g++
OBJ=test
all:
	$(cc) -c ./*.cpp
	$(cc) -o $(OBJ) ./*.o -I /usr/lib/x86_64-linux-gnu/libreadline.so -lreadline -ltermcap -g

clean:
	rm -rf *.o test

