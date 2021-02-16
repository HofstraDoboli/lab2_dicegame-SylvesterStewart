all: random input dice
# compile generate_random.cpp
random: generate_random.cpp 
	g++ -o random generate_random.cpp
# compile input.cpp
input: input.cpp
	g++ -o input input.cpp
# compile lab1_2
dice: play_dice.cpp
	g++ -o dice play_dice.cpp
# delete executable files
clean: 
	$(RM) random
	$(RM) input
	$(RM) dice
