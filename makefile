S=task1
P=task2
Q=task3

all: $(S) $(P) $(Q)

$(S): $(S).c
	gcc -static $(S).c -o $(S)
	
$(P): $(P).c
	gcc -static $(P).c -o $(P)

$(Q): $(Q).c
	gcc -static $(Q).c -o $(Q)
	
clean:
	rm $(S)
	rm $(P)
	rm $(Q)
	
pull:
	git pull
	clear
	clear
	make $(S)
	make $(P)
	make $(Q)
	
run 1: $(S)
	./$(S)
	


