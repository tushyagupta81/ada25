CC=g++

compile: socket/*.cpp
	$(CC) -o socket/main.o $^

run:
	socket/main.o &
	gui/.venv/bin/python gui/main.py

all: compile run

clean:
	rm socket/main.o
