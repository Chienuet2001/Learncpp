all: clean compile run

compile:
	g++ main.cpp -o output.exe

run: compile
	./output.exe

clean:
	del output.exe

.PHONY: all compile run clean
	