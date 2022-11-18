SRCS = main.cpp coord-conv.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

CXX ?= c++
CPPFLAGS ?= -I./include
CXXFLAGS ?= -g -std=c++11
LDFLAGS ?= -g

DESTDIR ?= /usr/local
DESTDIR_BIN ?= $(DESTDIR)/bin

TARGET = lv95-converter

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CXX) $(LDFLAGS) -o $(TARGET) $(OBJS)

main.o : src/main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c src/main.cpp

coord-conv.o : src/coord-conv.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c src/coord-conv.cpp


.PHONY : clean distclean install uninstall

clean : 
	rm $(OBJS)

distclean : 
	rm $(TARGET)

install : $(TARGET)
	@install -d $(DESTDIR_BIN)
	@install $(TARGET) $(DESTDIR_BIN)
	@echo "$(TARGET) was installed to $(DESTDIR)"

uninstall :
	@if [ -f $(DESTDIR_BIN)/$(TARGET) ]; then rm $(DESTDIR_BIN)/$(TARGET); else echo "ERROR: $(TARGET) not installed at location: \"$(DESTDIR_BIN)\" --> please uninstall manually"; fi
