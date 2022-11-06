lv95-converter : main.o coord-conv.o
	c++ -o lv95-converter main.o coord-conv.o

main.o : src/main.cpp headers/coord-conv.h
	c++ -c src/main.cpp

coord-conv.o : src/coord-conv.cpp headers/coord-conv.h
	c++ -c src/coord-conv.cpp
	

clean : 
	rm main.o coord-conv.o
