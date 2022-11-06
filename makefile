lv95-converter : main.o coord-conv.o
	c++ -o lv95-converter main.o coord-conv.o

main.o : src/main.cpp headers/coord-conv.h
	c++ -c src/main.cpp

coord-conv.o : src/coord-conv.cpp headers/coord-conv.h
	c++ -c src/coord-conv.cpp
	

clean : 
	rm main.o coord-conv.o

install : lv95-converter
	sudo mv lv95-converter /usr/local/bin

install-local : lv95-converter
	@mkdir -p $(HOME)/.local/bin
	mv lv95-converter $(HOME)/.local/bin

uninstall:
	@if [ -f /usr/local/bin/lv95-converter ]; then sudo rm /usr/local/bin/lv95-converter; elif [ -f $(HOME)/.local/bin/lv95-converter ]; then rm $(HOME)/.local/bin/lv95-converter; else echo "ERROR: lv95-converter is not installed ..."; fi
