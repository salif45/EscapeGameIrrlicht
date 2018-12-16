CPPFLAGS = -I/usr/include/irrlicht
CXXFLAGS = -Wall -Wextra -O2 -g -std=c++11 -Wno-unused-parameter

irrlicht-projet: main.o events.o create_window.o characater_objects.o interaction_with_object.o #Dico_Enigmes.o
	g++ $^ -o $@ -lIrrlicht

main.o events.o create_window.o characater_objects.o interaction_with_object.o : events.h create_window.h characater_objects.h interaction_with_object.h gui_ids.h
clean:
	@rm -f irrlicht-projet *.o
