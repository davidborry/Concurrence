#=======================================================================
# MAKEFILE FOR THE CONCURRENCE PROJECT 16 : GILLOT Thomas & BORRY David
#-----------------------------------------------------------------------
# Author : Thomas GILLOT --- No Copyright 2016
#=======================================================================


# Compiler
COMPILER = g++

# All the different directory used
SRC_DIR = source
HEAD_DIR = include
BIN_DIR = bin
OBJECTS_DIR = obj

# Compilation options
OPTIONS = -I$(HEAD_DIR) -g -Wall -std=c++11 -ansi


# Executable name
EXE = projet1-16.exe


# We declare where are the sources files and where the objects files will are

SOURCES = $(wildcard $(SRC_DIR)/*.cpp) main.cpp
OBJECTS= $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJECTS_DIR)/%.o)

all: $(EXE)

# We create the executable
projet1-16.exe : $(OBJECTS)
	$(COMPILER) -o $(BIN_DIR)/$@ $^ $(OPTIONS)

$(OBJECTS_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEAD_DIR)/%.h
	$(COMPILER) -o $@ -c $< $(OPTIONS)

# Clean all the .o and executable
clean:
	rm -f $(OBJECTS_DIR)/*.o

clean_all: clean
	rm $(BINDIR)/*




