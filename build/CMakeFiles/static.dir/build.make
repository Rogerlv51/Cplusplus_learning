# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = D:\CMake\bin\cmake.exe

# The command to remove a file.
RM = D:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Roger\Desktop\CodeSpace\C++ learning\vscode_c++"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Roger\Desktop\CodeSpace\C++ learning\vscode_c++\build"

# Include any dependencies generated for this target.
include CMakeFiles/static.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/static.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/static.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/static.dir/flags.make

CMakeFiles/static.dir/aboutStatic.obj: CMakeFiles/static.dir/flags.make
CMakeFiles/static.dir/aboutStatic.obj: C:/Users/Roger/Desktop/CodeSpace/C++\ learning/vscode_c++/aboutStatic.cpp
CMakeFiles/static.dir/aboutStatic.obj: CMakeFiles/static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Roger\Desktop\CodeSpace\C++ learning\vscode_c++\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/static.dir/aboutStatic.obj"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/static.dir/aboutStatic.obj -MF CMakeFiles\static.dir\aboutStatic.obj.d -o CMakeFiles\static.dir\aboutStatic.obj -c "C:\Users\Roger\Desktop\CodeSpace\C++ learning\vscode_c++\aboutStatic.cpp"

CMakeFiles/static.dir/aboutStatic.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/static.dir/aboutStatic.i"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Roger\Desktop\CodeSpace\C++ learning\vscode_c++\aboutStatic.cpp" > CMakeFiles\static.dir\aboutStatic.i

CMakeFiles/static.dir/aboutStatic.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/static.dir/aboutStatic.s"
	D:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Roger\Desktop\CodeSpace\C++ learning\vscode_c++\aboutStatic.cpp" -o CMakeFiles\static.dir\aboutStatic.s

# Object files for target static
static_OBJECTS = \
"CMakeFiles/static.dir/aboutStatic.obj"

# External object files for target static
static_EXTERNAL_OBJECTS =

static.exe: CMakeFiles/static.dir/aboutStatic.obj
static.exe: CMakeFiles/static.dir/build.make
static.exe: CMakeFiles/static.dir/linklibs.rsp
static.exe: CMakeFiles/static.dir/objects1.rsp
static.exe: CMakeFiles/static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Roger\Desktop\CodeSpace\C++ learning\vscode_c++\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable static.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\static.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/static.dir/build: static.exe
.PHONY : CMakeFiles/static.dir/build

CMakeFiles/static.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\static.dir\cmake_clean.cmake
.PHONY : CMakeFiles/static.dir/clean

CMakeFiles/static.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Roger\Desktop\CodeSpace\C++ learning\vscode_c++" "C:\Users\Roger\Desktop\CodeSpace\C++ learning\vscode_c++" "C:\Users\Roger\Desktop\CodeSpace\C++ learning\vscode_c++\build" "C:\Users\Roger\Desktop\CodeSpace\C++ learning\vscode_c++\build" "C:\Users\Roger\Desktop\CodeSpace\C++ learning\vscode_c++\build\CMakeFiles\static.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/static.dir/depend

