# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Apps\JetBrains\apps\CLion\ch-0\193.6015.37\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\Apps\JetBrains\apps\CLion\ch-0\193.6015.37\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Philip\CLionProjects\worker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Philip\CLionProjects\worker\cmake-build-debug

# Include any dependencies generated for this target.
include external\CMakeFiles\GLEW_1130.dir\depend.make

# Include the progress variables for this target.
include external\CMakeFiles\GLEW_1130.dir\progress.make

# Include the compile flags for this target's objects.
include external\CMakeFiles\GLEW_1130.dir\flags.make

external\CMakeFiles\GLEW_1130.dir\glew-1.13.0\src\glew.c.obj: external\CMakeFiles\GLEW_1130.dir\flags.make
external\CMakeFiles\GLEW_1130.dir\glew-1.13.0\src\glew.c.obj: ..\external\glew-1.13.0\src\glew.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Philip\CLionProjects\worker\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/CMakeFiles/GLEW_1130.dir/glew-1.13.0/src/glew.c.obj"
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug\external
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\GLEW_1130.dir\glew-1.13.0\src\glew.c.obj /FdCMakeFiles\GLEW_1130.dir\GLEW_1130.pdb /FS -c C:\Users\Philip\CLionProjects\worker\external\glew-1.13.0\src\glew.c
<<
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug

external\CMakeFiles\GLEW_1130.dir\glew-1.13.0\src\glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GLEW_1130.dir/glew-1.13.0/src/glew.c.i"
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug\external
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\GLEW_1130.dir\glew-1.13.0\src\glew.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Philip\CLionProjects\worker\external\glew-1.13.0\src\glew.c
<<
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug

external\CMakeFiles\GLEW_1130.dir\glew-1.13.0\src\glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GLEW_1130.dir/glew-1.13.0/src/glew.c.s"
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug\external
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\GLEW_1130.dir\glew-1.13.0\src\glew.c.s /c C:\Users\Philip\CLionProjects\worker\external\glew-1.13.0\src\glew.c
<<
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug

# Object files for target GLEW_1130
GLEW_1130_OBJECTS = \
"CMakeFiles\GLEW_1130.dir\glew-1.13.0\src\glew.c.obj"

# External object files for target GLEW_1130
GLEW_1130_EXTERNAL_OBJECTS =

external\GLEW_1130.lib: external\CMakeFiles\GLEW_1130.dir\glew-1.13.0\src\glew.c.obj
external\GLEW_1130.lib: external\CMakeFiles\GLEW_1130.dir\build.make
external\GLEW_1130.lib: external\CMakeFiles\GLEW_1130.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Philip\CLionProjects\worker\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library GLEW_1130.lib"
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug\external
	$(CMAKE_COMMAND) -P CMakeFiles\GLEW_1130.dir\cmake_clean_target.cmake
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug\external
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /lib /nologo /machine:X86 /out:GLEW_1130.lib @CMakeFiles\GLEW_1130.dir\objects1.rsp 
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug

# Rule to build all files generated by this target.
external\CMakeFiles\GLEW_1130.dir\build: external\GLEW_1130.lib

.PHONY : external\CMakeFiles\GLEW_1130.dir\build

external\CMakeFiles\GLEW_1130.dir\clean:
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug\external
	$(CMAKE_COMMAND) -P CMakeFiles\GLEW_1130.dir\cmake_clean.cmake
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug
.PHONY : external\CMakeFiles\GLEW_1130.dir\clean

external\CMakeFiles\GLEW_1130.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Philip\CLionProjects\worker C:\Users\Philip\CLionProjects\worker\external C:\Users\Philip\CLionProjects\worker\cmake-build-debug C:\Users\Philip\CLionProjects\worker\cmake-build-debug\external C:\Users\Philip\CLionProjects\worker\cmake-build-debug\external\CMakeFiles\GLEW_1130.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : external\CMakeFiles\GLEW_1130.dir\depend
