CC := gcc

football.exe: football__main.c football.h
	# fill in commands here
	$(CC) -o football.exe football__main.c football.h

temperature.exe: temperature_main.c report.h
	# fill in commands here
	$(CC) -o temperature.exe temperature_main.c temperature.h
clean:
	rm -f football.exe temperature.exe
