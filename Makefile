# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O2 -Wall -Wextra -Werror -pedantic-errors -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g 
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS = test_nodeset test_dijkstra test_graph_nofile test_graph_small test_graph_file test_general_dijkstra main

all: $(PROGS)

test_og: test_dijkstra test_graph_nofile test_graph_small test_nodeset
	./test_dijkstra
	./test_graph_nofile
	./test_graph_small
	./test_nodeset

test_all: test_nodeset test_dijkstra test_graph_nofile test_graph_small test_graph_file test_general_dijkstra
	./test_nodeset
	./test_dijkstra
	./test_graph_nofile
	./test_graph_small
	./test_graph_file
	./test_general_dijkstra

test_main: main
	./main

# Targets rely on implicit rules for compiling and linking
test_nodeset: test_nodeset.o NodeSet.o Node.o Edge.o 
test_dijkstra: test_dijkstra.o NodeSet.o Node.o Edge.o dijkstra.o 
test_graph_nofile: test_graph_nofile.o Graph.o Edge.o Node.o
test_graph_small: test_graph_small.o Graph.o Edge.o Node.o
test_graph_file: test_graph_file.o Graph.o Edge.o Node.o
test_general_dijkstra: test_general_dijkstra.o NodeSet.o Node.o Edge.o dijkstra.o 
main: main.o Node.o Graph.o dijkstra.o Edge.o NodeSet.o

 
# Phony targets
.PHONY: all test clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d

# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
	