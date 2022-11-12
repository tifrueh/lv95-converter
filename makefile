SRCS = main.cpp coord-conv.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

CXX ?= c++
CPPFLAGS ?= -I./include
CXXFLAGS ?= -g -std=c++11
LDFLAGS ?= -g

INSTALLDIR ?= /usr/local/bin

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
	@cp $(TARGET) $(INSTALLDIR)

uninstall :
	@if [ -f $(INSTALLDIR)/$(TARGET) ]; then rm $(INSTALLDIR)/$(TARGET); else echo "ERROR: $(TARGET) not installed at location: \"$(INSTALLDIR)\" --> please uninstall manually"; fi
