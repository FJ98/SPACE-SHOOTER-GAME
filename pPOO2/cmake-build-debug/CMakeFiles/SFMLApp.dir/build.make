# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\felix\Galaga\pPOO2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\felix\Galaga\pPOO2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SFMLApp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SFMLApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SFMLApp.dir/flags.make

CMakeFiles/SFMLApp.dir/main.cpp.obj: CMakeFiles/SFMLApp.dir/flags.make
CMakeFiles/SFMLApp.dir/main.cpp.obj: CMakeFiles/SFMLApp.dir/includes_CXX.rsp
CMakeFiles/SFMLApp.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\felix\Galaga\pPOO2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SFMLApp.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SFMLApp.dir\main.cpp.obj -c C:\Users\felix\Galaga\pPOO2\main.cpp

CMakeFiles/SFMLApp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFMLApp.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\felix\Galaga\pPOO2\main.cpp > CMakeFiles\SFMLApp.dir\main.cpp.i

CMakeFiles/SFMLApp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFMLApp.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\felix\Galaga\pPOO2\main.cpp -o CMakeFiles\SFMLApp.dir\main.cpp.s

# Object files for target SFMLApp
SFMLApp_OBJECTS = \
"CMakeFiles/SFMLApp.dir/main.cpp.obj"

# External object files for target SFMLApp
SFMLApp_EXTERNAL_OBJECTS =

SFMLApp.exe: CMakeFiles/SFMLApp.dir/main.cpp.obj
SFMLApp.exe: CMakeFiles/SFMLApp.dir/build.make
SFMLApp.exe: C:/SFML-2.5.1/lib/libsfml-graphics-d.a
SFMLApp.exe: C:/SFML-2.5.1/lib/libsfml-window-d.a
SFMLApp.exe: C:/SFML-2.5.1/lib/libsfml-system-d.a
SFMLApp.exe: CMakeFiles/SFMLApp.dir/linklibs.rsp
SFMLApp.exe: CMakeFiles/SFMLApp.dir/objects1.rsp
SFMLApp.exe: CMakeFiles/SFMLApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\felix\Galaga\pPOO2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SFMLApp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SFMLApp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SFMLApp.dir/build: SFMLApp.exe

.PHONY : CMakeFiles/SFMLApp.dir/build

CMakeFiles/SFMLApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SFMLApp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SFMLApp.dir/clean

CMakeFiles/SFMLApp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\felix\Galaga\pPOO2 C:\Users\felix\Galaga\pPOO2 C:\Users\felix\Galaga\pPOO2\cmake-build-debug C:\Users\felix\Galaga\pPOO2\cmake-build-debug C:\Users\felix\Galaga\pPOO2\cmake-build-debug\CMakeFiles\SFMLApp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SFMLApp.dir/depend

