lv95-to-wgs84 : main.o coord-conv.o
	g++ -o lv95-to-wgs84 main.o coord-conv.o

main.o : src/main.cpp headers/coord-conv.h
	g++ -c src/main.cpp

coord-conv.o : src/coord-conv.cpp headers/coord-conv.h
	g++ -c src/coord-conv.cpp
	

clean : 
	rm main.o coord-conv.o
