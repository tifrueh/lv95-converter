lv95-to-wgs84 : main.o coord-conv.o
	g++ -o lv95-to-wgs84 main.o coord-conv.o

main.o : main.cpp headers/coord-conv.h
	g++ -c main.cpp

coord-conv.o : coord-conv.cpp headers/coord-conv.h
	g++ -c coord-conv.cpp
	

clean : 
	rm main.o coord-conv.o
