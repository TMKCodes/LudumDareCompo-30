# project name (generate executable with this name)
TARGET		= ConnectingNokia

CC		= g++
CFLAGS  	= -std=c++11 -g -Wall -I. -fpermissive

LINKER  	= g++ -o
LFLAGS		= -Wall -I. -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

# change these to set the proper directories where each files should be
SRCDIR		= src
OBJDIR		= obj
BINDIR		= bin

SOURCES		:= $(wildcard $(SRCDIR)/*.cpp)
INCLUDES	:= $(wildcard $(SRCDIR)/*.hpp)
OBJECTS		:= $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm		= rm -f


$(BINDIR)/$(TARGET): $(OBJECTS)
	$(LINKER) $@ $(LFLAGS) $(OBJECTS)

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONEY: clean
clean:
	$(rm) $(OBJECTS)

.PHONEY: remove
remove: clean
	$(rm) $(BINDIR)/$(TARGET)

