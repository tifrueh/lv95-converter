SHELL = /bin/sh

CXX ?= g++

override CPPFLAGS += -I./include
override CXXFLAGS += -g -std=c++17 -Wall
override LDFLAGS += -g -lncurses

LOCAL_BIN = lv95-converter
LOCAL_BIN_PATH = $(BUILDDIR)/$(LOCAL_BIN)

PREFIX ?= /usr/local
BINDIR = $(PREFIX)/bin

DEST_BINDIR = $(DESTDIR)$(BINDIR)
DEST_BIN_PATH = $(DEST_BINDIR)/$(LOCAL_BIN)

SRCDIR ?= ./src
BUILDDIR ?= ./build

MAKE_OBJ = $(CXX) $(CPPFLAGS) $(CXXFLAGS) -c
MAKE_LINK = $(CXX) $(LDFLAGS) -o $(LOCAL_BIN_PATH)

SRCS = $(SRCDIR)/main.cpp \
	   $(SRCDIR)/coord-conv.cpp

OBJS = $(subst $(SRCDIR),$(BUILDDIR),$(subst .cpp,.o,$(SRCS)))


all : $(LOCAL_BIN_PATH)

$(LOCAL_BIN_PATH) : $(OBJS)
	$(MAKE_LINK) $(OBJS)

$(BUILDDIR)/%.o : $(SRCDIR)/%.cpp
	$(MAKE_OBJ) $(SRCDIR)/$*.cpp -o $@


.PHONY : clean distclean install uninstall

clean : 
	-rm $(OBJS)

distclean : 
	-rm $(OBJS)
	-rm $(LOCAL_BIN_PATH)

install : all
	@mkdir -p $(DEST_BINDIR)
	@cp $(LOCAL_BIN_PATH) $(DEST_BINDIR)
	@echo "$(LOCAL_BIN) was installed to $(DEST_BINDIR)"

uninstall :
	@if [ -f $(DEST_BIN_PATH) ]; then rm $(DEST_BIN_PATH) && echo "$(DEST_BIN_PATH) was deleted"; else echo "ERROR: $(LOCAL_BIN) not installed at location: \"$(DEST_BIN_PATH)\" --> please uninstall manually"; fi
