S=lab3

all: $(S)

$(S): $(S).c
	gcc -static $(S).c -o $(S)
	
clean:
	rm $(S)
	
pull:
	git pull
	clear
	clear
	make $(S)
	
run: $(S)
	./$(S)
