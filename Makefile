#
# BASIC MAKEFILE FOR PUTTING IN PLACE A PROJECT IN C++
#

CC := g++
SRCDIR := Source/src
BUILDDIR := Temp
TARGET := Game/Asteroides

SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%, $(BUILDDIR)/%, $(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wextra -Wall -std=c++11
LIB := -lsfml-graphics -lsfml-window -lsfml-system
INC := -I Source/include

$(TARGET): $(OBJECTS)
	@echo "Linking (Park)"
	@echo " $(CC) $^ -o $(TARGET) $(LIB)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "Cleaning"
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)

.PHONY: clean
