# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/starsdemo/myWebServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/starsdemo/myWebServer/build

# Include any dependencies generated for this target.
include CMakeFiles/muduo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/muduo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/muduo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/muduo.dir/flags.make

CMakeFiles/muduo.dir/main.cpp.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/main.cpp.o: ../main.cpp
CMakeFiles/muduo.dir/main.cpp.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/starsdemo/myWebServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/muduo.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/main.cpp.o -MF CMakeFiles/muduo.dir/main.cpp.o.d -o CMakeFiles/muduo.dir/main.cpp.o -c /root/starsdemo/myWebServer/main.cpp

CMakeFiles/muduo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/starsdemo/myWebServer/main.cpp > CMakeFiles/muduo.dir/main.cpp.i

CMakeFiles/muduo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/starsdemo/myWebServer/main.cpp -o CMakeFiles/muduo.dir/main.cpp.s

CMakeFiles/muduo.dir/src/Inetaddress.cpp.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/Inetaddress.cpp.o: ../src/Inetaddress.cpp
CMakeFiles/muduo.dir/src/Inetaddress.cpp.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/starsdemo/myWebServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/muduo.dir/src/Inetaddress.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/Inetaddress.cpp.o -MF CMakeFiles/muduo.dir/src/Inetaddress.cpp.o.d -o CMakeFiles/muduo.dir/src/Inetaddress.cpp.o -c /root/starsdemo/myWebServer/src/Inetaddress.cpp

CMakeFiles/muduo.dir/src/Inetaddress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/Inetaddress.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/starsdemo/myWebServer/src/Inetaddress.cpp > CMakeFiles/muduo.dir/src/Inetaddress.cpp.i

CMakeFiles/muduo.dir/src/Inetaddress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/Inetaddress.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/starsdemo/myWebServer/src/Inetaddress.cpp -o CMakeFiles/muduo.dir/src/Inetaddress.cpp.s

CMakeFiles/muduo.dir/src/Logger.cpp.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/Logger.cpp.o: ../src/Logger.cpp
CMakeFiles/muduo.dir/src/Logger.cpp.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/starsdemo/myWebServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/muduo.dir/src/Logger.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/Logger.cpp.o -MF CMakeFiles/muduo.dir/src/Logger.cpp.o.d -o CMakeFiles/muduo.dir/src/Logger.cpp.o -c /root/starsdemo/myWebServer/src/Logger.cpp

CMakeFiles/muduo.dir/src/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/Logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/starsdemo/myWebServer/src/Logger.cpp > CMakeFiles/muduo.dir/src/Logger.cpp.i

CMakeFiles/muduo.dir/src/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/Logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/starsdemo/myWebServer/src/Logger.cpp -o CMakeFiles/muduo.dir/src/Logger.cpp.s

CMakeFiles/muduo.dir/src/Socket.cpp.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/Socket.cpp.o: ../src/Socket.cpp
CMakeFiles/muduo.dir/src/Socket.cpp.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/starsdemo/myWebServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/muduo.dir/src/Socket.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/Socket.cpp.o -MF CMakeFiles/muduo.dir/src/Socket.cpp.o.d -o CMakeFiles/muduo.dir/src/Socket.cpp.o -c /root/starsdemo/myWebServer/src/Socket.cpp

CMakeFiles/muduo.dir/src/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/Socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/starsdemo/myWebServer/src/Socket.cpp > CMakeFiles/muduo.dir/src/Socket.cpp.i

CMakeFiles/muduo.dir/src/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/Socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/starsdemo/myWebServer/src/Socket.cpp -o CMakeFiles/muduo.dir/src/Socket.cpp.s

CMakeFiles/muduo.dir/src/TimeStamp.cpp.o: CMakeFiles/muduo.dir/flags.make
CMakeFiles/muduo.dir/src/TimeStamp.cpp.o: ../src/TimeStamp.cpp
CMakeFiles/muduo.dir/src/TimeStamp.cpp.o: CMakeFiles/muduo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/starsdemo/myWebServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/muduo.dir/src/TimeStamp.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/muduo.dir/src/TimeStamp.cpp.o -MF CMakeFiles/muduo.dir/src/TimeStamp.cpp.o.d -o CMakeFiles/muduo.dir/src/TimeStamp.cpp.o -c /root/starsdemo/myWebServer/src/TimeStamp.cpp

CMakeFiles/muduo.dir/src/TimeStamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/muduo.dir/src/TimeStamp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/starsdemo/myWebServer/src/TimeStamp.cpp > CMakeFiles/muduo.dir/src/TimeStamp.cpp.i

CMakeFiles/muduo.dir/src/TimeStamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/muduo.dir/src/TimeStamp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/starsdemo/myWebServer/src/TimeStamp.cpp -o CMakeFiles/muduo.dir/src/TimeStamp.cpp.s

# Object files for target muduo
muduo_OBJECTS = \
"CMakeFiles/muduo.dir/main.cpp.o" \
"CMakeFiles/muduo.dir/src/Inetaddress.cpp.o" \
"CMakeFiles/muduo.dir/src/Logger.cpp.o" \
"CMakeFiles/muduo.dir/src/Socket.cpp.o" \
"CMakeFiles/muduo.dir/src/TimeStamp.cpp.o"

# External object files for target muduo
muduo_EXTERNAL_OBJECTS =

muduo: CMakeFiles/muduo.dir/main.cpp.o
muduo: CMakeFiles/muduo.dir/src/Inetaddress.cpp.o
muduo: CMakeFiles/muduo.dir/src/Logger.cpp.o
muduo: CMakeFiles/muduo.dir/src/Socket.cpp.o
muduo: CMakeFiles/muduo.dir/src/TimeStamp.cpp.o
muduo: CMakeFiles/muduo.dir/build.make
muduo: CMakeFiles/muduo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/starsdemo/myWebServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable muduo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/muduo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/muduo.dir/build: muduo
.PHONY : CMakeFiles/muduo.dir/build

CMakeFiles/muduo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/muduo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/muduo.dir/clean

CMakeFiles/muduo.dir/depend:
	cd /root/starsdemo/myWebServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/starsdemo/myWebServer /root/starsdemo/myWebServer /root/starsdemo/myWebServer/build /root/starsdemo/myWebServer/build /root/starsdemo/myWebServer/build/CMakeFiles/muduo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/muduo.dir/depend

