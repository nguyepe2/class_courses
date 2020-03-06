CC = g++
exe_file = pokemon
$(exe_file): pokemondriver.o location.o event.o pokemon.o psychic.o rock.o flying.o pokestop.o cave.o
	$(CC) pokemondriver.o location.o event.o pokemon.o psychic.o rock.o flying.o pokestop.o cave.o -o $(exe_file)
debug: pokemondriver.o locationD.o event.o pokemon.o psychic.o rock.o flying.o pokestop.o cave.o
	$(CC) pokemondriver.o location.o event.o pokemon.o psychic.o rock.o flying.o pokestop.o cave.o -o $(exe_file)
mains.o: pokemondriver.cpp
	$(CC) -c pokemondriver.cpp
locationD.o: location.cpp
	$(CC) -c  location.cpp -D DEBUG
location.o: location.cpp
	$(CC) -c location.cpp
event.o: event.cpp
	$(CC) -c event.cpp
pokemon.o: pokemon.cpp
	$(CC) -c pokemon.cpp
psychic.o: psychic.cpp
	$(CC) -c psychic.cpp
rock.o: rock.cpp
	$(CC) -c rock.cpp
flying.o: flying.cpp
	$(CC) -c flying.cpp
pokestop.o: pokestop.cpp
	$(CC) -c pokestop.cpp
cave.o: cave.cpp
	$(CC) -c cave.cpp
clean:
	rm -f *.out *.o $(exe_file)

