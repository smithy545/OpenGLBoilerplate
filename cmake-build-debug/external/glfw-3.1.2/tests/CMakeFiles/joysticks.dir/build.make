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
include external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\depend.make

# Include the progress variables for this target.
include external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\progress.make

# Include the compile flags for this target's objects.
include external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\flags.make

external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\joysticks.c.obj: external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\flags.make
external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\joysticks.c.obj: ..\external\glfw-3.1.2\tests\joysticks.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Philip\CLionProjects\worker\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glfw-3.1.2/tests/CMakeFiles/joysticks.dir/joysticks.c.obj"
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug\external\glfw-3.1.2\tests
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\joysticks.dir\joysticks.c.obj /FdCMakeFiles\joysticks.dir\ /FS -c C:\Users\Philip\CLionProjects\worker\external\glfw-3.1.2\tests\joysticks.c
<<
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug

external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\joysticks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/joysticks.dir/joysticks.c.i"
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug\external\glfw-3.1.2\tests
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe > CMakeFiles\joysticks.dir\joysticks.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Philip\CLionProjects\worker\external\glfw-3.1.2\tests\joysticks.c
<<
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug

external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\joysticks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/joysticks.dir/joysticks.c.s"
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug\external\glfw-3.1.2\tests
	C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\joysticks.dir\joysticks.c.s /c C:\Users\Philip\CLionProjects\worker\external\glfw-3.1.2\tests\joysticks.c
<<
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug

# Object files for target joysticks
joysticks_OBJECTS = \
"CMakeFiles\joysticks.dir\joysticks.c.obj"

# External object files for target joysticks
joysticks_EXTERNAL_OBJECTS =

external\glfw-3.1.2\tests\joysticks.exe: external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\joysticks.c.obj
external\glfw-3.1.2\tests\joysticks.exe: external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\build.make
external\glfw-3.1.2\tests\joysticks.exe: external\glfw-3.1.2\src\glfw3.lib
external\glfw-3.1.2\tests\joysticks.exe: external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Philip\CLionProjects\worker\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable joysticks.exe"
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug\external\glfw-3.1.2\tests
	D:\Apps\JetBrains\apps\CLion\ch-0\193.6015.37\bin\cmake\win\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\joysticks.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~2\2017\COMMUN~1\VC\Tools\MSVC\1416~1.270\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\joysticks.dir\objects1.rsp @<<
 /out:joysticks.exe /implib:joysticks.lib /pdb:C:\Users\Philip\CLionProjects\worker\cmake-build-debug\external\glfw-3.1.2\tests\joysticks.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console /ENTRY:mainCRTStartup ..\src\glfw3.lib opengl32.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug

# Rule to build all files generated by this target.
external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\build: external\glfw-3.1.2\tests\joysticks.exe

.PHONY : external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\build

external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\clean:
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug\external\glfw-3.1.2\tests
	$(CMAKE_COMMAND) -P CMakeFiles\joysticks.dir\cmake_clean.cmake
	cd C:\Users\Philip\CLionProjects\worker\cmake-build-debug
.PHONY : external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\clean

external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Philip\CLionProjects\worker C:\Users\Philip\CLionProjects\worker\external\glfw-3.1.2\tests C:\Users\Philip\CLionProjects\worker\cmake-build-debug C:\Users\Philip\CLionProjects\worker\cmake-build-debug\external\glfw-3.1.2\tests C:\Users\Philip\CLionProjects\worker\cmake-build-debug\external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : external\glfw-3.1.2\tests\CMakeFiles\joysticks.dir\depend
