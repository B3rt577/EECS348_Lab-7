CC := gcc

football.exe: football_main.c football.c
	# fill in commands here
	$(CC) football_main.c -c
	$(CC) football.c -c
	$(CC) football_main.o football.o -o football.exe
	
temperature.exe: temperature_main.c temperature.c
	# fill in commands here
	$(CC) temperature_main.c -c
	$(CC) temperature.c -c
	$(CC) temperature_main.o temperature.o -o temperature.exe
clean:
	rm -f football.exe temperature.exe
