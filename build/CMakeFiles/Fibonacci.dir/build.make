# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\cmake-3.19.8-win64-x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\cmake-3.19.8-win64-x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\CollegeC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\CollegeC\build

# Include any dependencies generated for this target.
include CMakeFiles/Fibonacci.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Fibonacci.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Fibonacci.dir/flags.make

CMakeFiles/Fibonacci.dir/Fibonacci.c.obj: CMakeFiles/Fibonacci.dir/flags.make
CMakeFiles/Fibonacci.dir/Fibonacci.c.obj: ../Fibonacci.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\CollegeC\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Fibonacci.dir/Fibonacci.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Fibonacci.dir\Fibonacci.c.obj -c D:\CollegeC\Fibonacci.c

CMakeFiles/Fibonacci.dir/Fibonacci.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Fibonacci.dir/Fibonacci.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\CollegeC\Fibonacci.c > CMakeFiles\Fibonacci.dir\Fibonacci.c.i

CMakeFiles/Fibonacci.dir/Fibonacci.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Fibonacci.dir/Fibonacci.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\X8EAA8~1.EXE $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\CollegeC\Fibonacci.c -o CMakeFiles\Fibonacci.dir\Fibonacci.c.s

# Object files for target Fibonacci
Fibonacci_OBJECTS = \
"CMakeFiles/Fibonacci.dir/Fibonacci.c.obj"

# External object files for target Fibonacci
Fibonacci_EXTERNAL_OBJECTS =

Fibonacci.exe: CMakeFiles/Fibonacci.dir/Fibonacci.c.obj
Fibonacci.exe: CMakeFiles/Fibonacci.dir/build.make
Fibonacci.exe: CMakeFiles/Fibonacci.dir/linklibs.rsp
Fibonacci.exe: CMakeFiles/Fibonacci.dir/objects1.rsp
Fibonacci.exe: CMakeFiles/Fibonacci.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\CollegeC\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Fibonacci.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Fibonacci.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Fibonacci.dir/build: Fibonacci.exe

.PHONY : CMakeFiles/Fibonacci.dir/build

CMakeFiles/Fibonacci.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Fibonacci.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Fibonacci.dir/clean

CMakeFiles/Fibonacci.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\CollegeC D:\CollegeC D:\CollegeC\build D:\CollegeC\build D:\CollegeC\build\CMakeFiles\Fibonacci.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Fibonacci.dir/depend
