stringMe: mallickMohammadAdibA2.o mallickMohammadAdibA2Main.o
	gcc -Wall -std=c99 mallickMohammadAdibA2.o mallickMohammadAdibA2Main.o -o bin/stringMe

mallickMohammadAdibA2.o: src/mallickMohammadAdibA2.c include/mallickMohammadAdibA2.h
	gcc -Wall -std=c99 -c src/mallickMohammadAdibA2.c include/mallickMohammadAdibA2.h

mallickMohammadAdibA2Main.o: src/mallickMohammadAdibA2Main.c include/mallickMohammadAdibA2.h
	gcc -Wall -std=c99 -c src/mallickMohammadAdibA2Main.c

clean:
	rm *.o bin/stringMe 