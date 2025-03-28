CC := gcc

# Target for football.exe
football.exe: football_main.o football.o
	$(CC) football_main.o football.o -o football.exe

# Compile football_main.c and football.c into object files
football_main.o: football_main.c
	$(CC) football_main.c -c -o football_main.o

football.o: football.c
	$(CC) football.c -c -o football.o

# Target for temperature.exe
temperature.exe: temperature_main.o temperature.o
	$(CC) temperature_main.o temperature.o -o temperature.exe

# Compile temperature_main.c and temperature.c into object files
temperature_main.o: temperature_main.c
	$(CC) temperature_main.c -c -o temperature_main.o

temperature.o: temperature.c
	$(CC) temperature.c -c -o temperature.o

# Clean up generated files
clean:
	rm -f *.exe *.o
