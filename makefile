S=task1
P=task2

all: $(S)

$(S): $(S).c
	gcc -static $(S).c -o $(S)
	
$(P): $(P).c
	gcc -static $(P).c -o $(P)
	
clean:
	rm $(S)
	rm $(P)
	
pull:
	git pull
	clear
	clear
	make $(S)
	make $(P)
	
run 1: $(S)
	./$(S)
	


