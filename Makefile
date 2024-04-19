# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dnvic/Desktop/cppstuff/dsfinal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dnvic/Desktop/cppstuff/dsfinal

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/usr/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dnvic/Desktop/cppstuff/dsfinal/CMakeFiles /home/dnvic/Desktop/cppstuff/dsfinal//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/dnvic/Desktop/cppstuff/dsfinal/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Assignment

# Build rule for target.
Assignment: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Assignment
.PHONY : Assignment

# fast build rule for target.
Assignment/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Assignment.dir/build.make CMakeFiles/Assignment.dir/build
.PHONY : Assignment/fast

Airport.o: Airport.cpp.o
.PHONY : Airport.o

# target to build an object file
Airport.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Assignment.dir/build.make CMakeFiles/Assignment.dir/Airport.cpp.o
.PHONY : Airport.cpp.o

Airport.i: Airport.cpp.i
.PHONY : Airport.i

# target to preprocess a source file
Airport.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Assignment.dir/build.make CMakeFiles/Assignment.dir/Airport.cpp.i
.PHONY : Airport.cpp.i

Airport.s: Airport.cpp.s
.PHONY : Airport.s

# target to generate assembly for a file
Airport.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Assignment.dir/build.make CMakeFiles/Assignment.dir/Airport.cpp.s
.PHONY : Airport.cpp.s

AirportGraph.o: AirportGraph.cpp.o
.PHONY : AirportGraph.o

# target to build an object file
AirportGraph.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Assignment.dir/build.make CMakeFiles/Assignment.dir/AirportGraph.cpp.o
.PHONY : AirportGraph.cpp.o

AirportGraph.i: AirportGraph.cpp.i
.PHONY : AirportGraph.i

# target to preprocess a source file
AirportGraph.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Assignment.dir/build.make CMakeFiles/Assignment.dir/AirportGraph.cpp.i
.PHONY : AirportGraph.cpp.i

AirportGraph.s: AirportGraph.cpp.s
.PHONY : AirportGraph.s

# target to generate assembly for a file
AirportGraph.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Assignment.dir/build.make CMakeFiles/Assignment.dir/AirportGraph.cpp.s
.PHONY : AirportGraph.cpp.s

MST.o: MST.cpp.o
.PHONY : MST.o

# target to build an object file
MST.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Assignment.dir/build.make CMakeFiles/Assignment.dir/MST.cpp.o
.PHONY : MST.cpp.o

MST.i: MST.cpp.i
.PHONY : MST.i

# target to preprocess a source file
MST.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Assignment.dir/build.make CMakeFiles/Assignment.dir/MST.cpp.i
.PHONY : MST.cpp.i

MST.s: MST.cpp.s
.PHONY : MST.s

# target to generate assembly for a file
MST.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Assignment.dir/build.make CMakeFiles/Assignment.dir/MST.cpp.s
.PHONY : MST.cpp.s

MinHeap.o: MinHeap.cpp.o
.PHONY : MinHeap.o

# target to build an object file
MinHeap.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Assignment.dir/build.make CMakeFiles/Assignment.dir/MinHeap.cpp.o
.PHONY : MinHeap.cpp.o

MinHeap.i: MinHeap.cpp.i
.PHONY : MinHeap.i

# target to preprocess a source file
MinHeap.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Assignment.dir/build.make CMakeFiles/Assignment.dir/MinHeap.cpp.i
.PHONY : MinHeap.cpp.i

MinHeap.s: MinHeap.cpp.s
.PHONY : MinHeap.s

# target to generate assembly for a file
MinHeap.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Assignment.dir/build.make CMakeFiles/Assignment.dir/MinHeap.cpp.s
.PHONY : MinHeap.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Assignment.dir/build.make CMakeFiles/Assignment.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Assignment.dir/build.make CMakeFiles/Assignment.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Assignment.dir/build.make CMakeFiles/Assignment.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Assignment"
	@echo "... Airport.o"
	@echo "... Airport.i"
	@echo "... Airport.s"
	@echo "... AirportGraph.o"
	@echo "... AirportGraph.i"
	@echo "... AirportGraph.s"
	@echo "... MST.o"
	@echo "... MST.i"
	@echo "... MST.s"
	@echo "... MinHeap.o"
	@echo "... MinHeap.i"
	@echo "... MinHeap.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
