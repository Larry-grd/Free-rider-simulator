FLAGS = -pedantic-errors -std=c++11

print_menu.o: print_menu.cpp print_menu.h
	g++ $(FLAGS) -c $<

print_start_menu.o: print_start_menu.cpp print_start_menu.h
	g++ $(FLAGS) -c $<

game_initialise.o: game_initialise.cpp game_initialise.h player.h
	g++ $(FLAGS) -c $<

save.o: save.cpp save.h player.h
	g++ $(FLAGS) -c $<
	
random_task.o: random_task.cpp random_task.h player.h
	g++ $(FLAGS) -c $<

freerider_simulator.o: freerider_simulator.cpp print_menu.h print_start_menu.h save.h player.h game_initialise.h random_task.h
	g++ $(FLAGS) -c $<
	
freerider_simulator: freerider_simulator.o save.o game_initialise.o print_start_menu.o print_menu.o random_task.o
	g++ $(FLAGS) $^ -o $@

clean:
	rm freerider_simulator *.o

tar:
	tar -czvf freerider_simulator.tgz *.cpp *.h

.PHONY: clean tar
