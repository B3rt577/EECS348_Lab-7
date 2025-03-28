CC := gcc

football.exe: football.c
	# fill in commands here
	$(CC) -o football.exe football.c

temperature.exe: main.c report.c
	# fill in commands here
	$(CC) -o temperature.exe temperature_main.c temperature.c
clean:
	rm -f football.exe temperature.exe
