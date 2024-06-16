CXX = g++
CXXFLAGS = -Wall -std=c++11

# Directories
INCDIR = include
SRCDIR = src
OBJDIR = obj
BINDIR = bin
DOCDIR = docs

# Files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
EXECUTABLE = $(BINDIR)/main

# Targets
all: $(EXECUTABLE) docs

$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(OBJECTS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

docs:
	doxygen $(DOCDIR)/Doxyfile

clean:
	rm -rf $(OBJDIR)/*.o $(EXECUTABLE) $(DOCDIR)/html

.PHONY: all clean docs
