# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mirmik/project/servoce

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mirmik/project/servoce

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
	/usr/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test

.PHONY : test/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mirmik/project/servoce/CMakeFiles /home/mirmik/project/servoce/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/mirmik/project/servoce/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named servoce

# Build rule for target.
servoce: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 servoce
.PHONY : servoce

# fast build rule for target.
servoce/fast:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/build
.PHONY : servoce/fast

#=============================================================================
# Target rules for targets named servoce_test

# Build rule for target.
servoce_test: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 servoce_test
.PHONY : servoce_test

# fast build rule for target.
servoce_test/fast:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/build
.PHONY : servoce_test/fast

src/b64.o: src/b64.cpp.o

.PHONY : src/b64.o

# target to build an object file
src/b64.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/b64.cpp.o
.PHONY : src/b64.cpp.o

src/b64.i: src/b64.cpp.i

.PHONY : src/b64.i

# target to preprocess a source file
src/b64.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/b64.cpp.i
.PHONY : src/b64.cpp.i

src/b64.s: src/b64.cpp.s

.PHONY : src/b64.s

# target to generate assembly for a file
src/b64.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/b64.cpp.s
.PHONY : src/b64.cpp.s

src/boolops.o: src/boolops.cpp.o

.PHONY : src/boolops.o

# target to build an object file
src/boolops.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/boolops.cpp.o
.PHONY : src/boolops.cpp.o

src/boolops.i: src/boolops.cpp.i

.PHONY : src/boolops.i

# target to preprocess a source file
src/boolops.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/boolops.cpp.i
.PHONY : src/boolops.cpp.i

src/boolops.s: src/boolops.cpp.s

.PHONY : src/boolops.s

# target to generate assembly for a file
src/boolops.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/boolops.cpp.s
.PHONY : src/boolops.cpp.s

src/camera.o: src/camera.cpp.o

.PHONY : src/camera.o

# target to build an object file
src/camera.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/camera.cpp.o
.PHONY : src/camera.cpp.o

src/camera.i: src/camera.cpp.i

.PHONY : src/camera.i

# target to preprocess a source file
src/camera.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/camera.cpp.i
.PHONY : src/camera.cpp.i

src/camera.s: src/camera.cpp.s

.PHONY : src/camera.s

# target to generate assembly for a file
src/camera.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/camera.cpp.s
.PHONY : src/camera.cpp.s

src/convert.o: src/convert.cpp.o

.PHONY : src/convert.o

# target to build an object file
src/convert.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/convert.cpp.o
.PHONY : src/convert.cpp.o

src/convert.i: src/convert.cpp.i

.PHONY : src/convert.i

# target to preprocess a source file
src/convert.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/convert.cpp.i
.PHONY : src/convert.cpp.i

src/convert.s: src/convert.cpp.s

.PHONY : src/convert.s

# target to generate assembly for a file
src/convert.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/convert.cpp.s
.PHONY : src/convert.cpp.s

src/curve2.o: src/curve2.cpp.o

.PHONY : src/curve2.o

# target to build an object file
src/curve2.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/curve2.cpp.o
.PHONY : src/curve2.cpp.o

src/curve2.i: src/curve2.cpp.i

.PHONY : src/curve2.i

# target to preprocess a source file
src/curve2.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/curve2.cpp.i
.PHONY : src/curve2.cpp.i

src/curve2.s: src/curve2.cpp.s

.PHONY : src/curve2.s

# target to generate assembly for a file
src/curve2.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/curve2.cpp.s
.PHONY : src/curve2.cpp.s

src/curve3.o: src/curve3.cpp.o

.PHONY : src/curve3.o

# target to build an object file
src/curve3.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/curve3.cpp.o
.PHONY : src/curve3.cpp.o

src/curve3.i: src/curve3.cpp.i

.PHONY : src/curve3.i

# target to preprocess a source file
src/curve3.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/curve3.cpp.i
.PHONY : src/curve3.cpp.i

src/curve3.s: src/curve3.cpp.s

.PHONY : src/curve3.s

# target to generate assembly for a file
src/curve3.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/curve3.cpp.s
.PHONY : src/curve3.cpp.s

src/face.o: src/face.cpp.o

.PHONY : src/face.o

# target to build an object file
src/face.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/face.cpp.o
.PHONY : src/face.cpp.o

src/face.i: src/face.cpp.i

.PHONY : src/face.i

# target to preprocess a source file
src/face.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/face.cpp.i
.PHONY : src/face.cpp.i

src/face.s: src/face.cpp.s

.PHONY : src/face.s

# target to generate assembly for a file
src/face.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/face.cpp.s
.PHONY : src/face.cpp.s

src/geombase.o: src/geombase.cpp.o

.PHONY : src/geombase.o

# target to build an object file
src/geombase.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/geombase.cpp.o
.PHONY : src/geombase.cpp.o

src/geombase.i: src/geombase.cpp.i

.PHONY : src/geombase.i

# target to preprocess a source file
src/geombase.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/geombase.cpp.i
.PHONY : src/geombase.cpp.i

src/geombase.s: src/geombase.cpp.s

.PHONY : src/geombase.s

# target to generate assembly for a file
src/geombase.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/geombase.cpp.s
.PHONY : src/geombase.cpp.s

src/interactive_object.o: src/interactive_object.cpp.o

.PHONY : src/interactive_object.o

# target to build an object file
src/interactive_object.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/interactive_object.cpp.o
.PHONY : src/interactive_object.cpp.o

src/interactive_object.i: src/interactive_object.cpp.i

.PHONY : src/interactive_object.i

# target to preprocess a source file
src/interactive_object.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/interactive_object.cpp.i
.PHONY : src/interactive_object.cpp.i

src/interactive_object.s: src/interactive_object.cpp.s

.PHONY : src/interactive_object.s

# target to generate assembly for a file
src/interactive_object.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/interactive_object.cpp.s
.PHONY : src/interactive_object.cpp.s

src/opencascade_types.o: src/opencascade_types.cpp.o

.PHONY : src/opencascade_types.o

# target to build an object file
src/opencascade_types.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/opencascade_types.cpp.o
.PHONY : src/opencascade_types.cpp.o

src/opencascade_types.i: src/opencascade_types.cpp.i

.PHONY : src/opencascade_types.i

# target to preprocess a source file
src/opencascade_types.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/opencascade_types.cpp.i
.PHONY : src/opencascade_types.cpp.i

src/opencascade_types.s: src/opencascade_types.cpp.s

.PHONY : src/opencascade_types.s

# target to generate assembly for a file
src/opencascade_types.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/opencascade_types.cpp.s
.PHONY : src/opencascade_types.cpp.s

src/prs3d.o: src/prs3d.cpp.o

.PHONY : src/prs3d.o

# target to build an object file
src/prs3d.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/prs3d.cpp.o
.PHONY : src/prs3d.cpp.o

src/prs3d.i: src/prs3d.cpp.i

.PHONY : src/prs3d.i

# target to preprocess a source file
src/prs3d.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/prs3d.cpp.i
.PHONY : src/prs3d.cpp.i

src/prs3d.s: src/prs3d.cpp.s

.PHONY : src/prs3d.s

# target to generate assembly for a file
src/prs3d.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/prs3d.cpp.s
.PHONY : src/prs3d.cpp.s

src/scene.o: src/scene.cpp.o

.PHONY : src/scene.o

# target to build an object file
src/scene.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/scene.cpp.o
.PHONY : src/scene.cpp.o

src/scene.i: src/scene.cpp.i

.PHONY : src/scene.i

# target to preprocess a source file
src/scene.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/scene.cpp.i
.PHONY : src/scene.cpp.i

src/scene.s: src/scene.cpp.s

.PHONY : src/scene.s

# target to generate assembly for a file
src/scene.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/scene.cpp.s
.PHONY : src/scene.cpp.s

src/shape_view.o: src/shape_view.cpp.o

.PHONY : src/shape_view.o

# target to build an object file
src/shape_view.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/shape_view.cpp.o
.PHONY : src/shape_view.cpp.o

src/shape_view.i: src/shape_view.cpp.i

.PHONY : src/shape_view.i

# target to preprocess a source file
src/shape_view.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/shape_view.cpp.i
.PHONY : src/shape_view.cpp.i

src/shape_view.s: src/shape_view.cpp.s

.PHONY : src/shape_view.s

# target to generate assembly for a file
src/shape_view.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/shape_view.cpp.s
.PHONY : src/shape_view.cpp.s

src/solid.o: src/solid.cpp.o

.PHONY : src/solid.o

# target to build an object file
src/solid.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/solid.cpp.o
.PHONY : src/solid.cpp.o

src/solid.i: src/solid.cpp.i

.PHONY : src/solid.i

# target to preprocess a source file
src/solid.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/solid.cpp.i
.PHONY : src/solid.cpp.i

src/solid.s: src/solid.cpp.s

.PHONY : src/solid.s

# target to generate assembly for a file
src/solid.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/solid.cpp.s
.PHONY : src/solid.cpp.s

src/surface.o: src/surface.cpp.o

.PHONY : src/surface.o

# target to build an object file
src/surface.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/surface.cpp.o
.PHONY : src/surface.cpp.o

src/surface.i: src/surface.cpp.i

.PHONY : src/surface.i

# target to preprocess a source file
src/surface.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/surface.cpp.i
.PHONY : src/surface.cpp.i

src/surface.s: src/surface.cpp.s

.PHONY : src/surface.s

# target to generate assembly for a file
src/surface.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/surface.cpp.s
.PHONY : src/surface.cpp.s

src/topo.o: src/topo.cpp.o

.PHONY : src/topo.o

# target to build an object file
src/topo.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/topo.cpp.o
.PHONY : src/topo.cpp.o

src/topo.i: src/topo.cpp.i

.PHONY : src/topo.i

# target to preprocess a source file
src/topo.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/topo.cpp.i
.PHONY : src/topo.cpp.i

src/topo.s: src/topo.cpp.s

.PHONY : src/topo.s

# target to generate assembly for a file
src/topo.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/topo.cpp.s
.PHONY : src/topo.cpp.s

src/trans.o: src/trans.cpp.o

.PHONY : src/trans.o

# target to build an object file
src/trans.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/trans.cpp.o
.PHONY : src/trans.cpp.o

src/trans.i: src/trans.cpp.i

.PHONY : src/trans.i

# target to preprocess a source file
src/trans.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/trans.cpp.i
.PHONY : src/trans.cpp.i

src/trans.s: src/trans.cpp.s

.PHONY : src/trans.s

# target to generate assembly for a file
src/trans.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/trans.cpp.s
.PHONY : src/trans.cpp.s

src/view.o: src/view.cpp.o

.PHONY : src/view.o

# target to build an object file
src/view.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/view.cpp.o
.PHONY : src/view.cpp.o

src/view.i: src/view.cpp.i

.PHONY : src/view.i

# target to preprocess a source file
src/view.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/view.cpp.i
.PHONY : src/view.cpp.i

src/view.s: src/view.cpp.s

.PHONY : src/view.s

# target to generate assembly for a file
src/view.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/view.cpp.s
.PHONY : src/view.cpp.s

src/viewer.o: src/viewer.cpp.o

.PHONY : src/viewer.o

# target to build an object file
src/viewer.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/viewer.cpp.o
.PHONY : src/viewer.cpp.o

src/viewer.i: src/viewer.cpp.i

.PHONY : src/viewer.i

# target to preprocess a source file
src/viewer.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/viewer.cpp.i
.PHONY : src/viewer.cpp.i

src/viewer.s: src/viewer.cpp.s

.PHONY : src/viewer.s

# target to generate assembly for a file
src/viewer.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/viewer.cpp.s
.PHONY : src/viewer.cpp.s

src/wire.o: src/wire.cpp.o

.PHONY : src/wire.o

# target to build an object file
src/wire.cpp.o:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/wire.cpp.o
.PHONY : src/wire.cpp.o

src/wire.i: src/wire.cpp.i

.PHONY : src/wire.i

# target to preprocess a source file
src/wire.cpp.i:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/wire.cpp.i
.PHONY : src/wire.cpp.i

src/wire.s: src/wire.cpp.s

.PHONY : src/wire.s

# target to generate assembly for a file
src/wire.cpp.s:
	$(MAKE) -f CMakeFiles/servoce.dir/build.make CMakeFiles/servoce.dir/src/wire.cpp.s
.PHONY : src/wire.cpp.s

utests/curve3.o: utests/curve3.cpp.o

.PHONY : utests/curve3.o

# target to build an object file
utests/curve3.cpp.o:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/curve3.cpp.o
.PHONY : utests/curve3.cpp.o

utests/curve3.i: utests/curve3.cpp.i

.PHONY : utests/curve3.i

# target to preprocess a source file
utests/curve3.cpp.i:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/curve3.cpp.i
.PHONY : utests/curve3.cpp.i

utests/curve3.s: utests/curve3.cpp.s

.PHONY : utests/curve3.s

# target to generate assembly for a file
utests/curve3.cpp.s:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/curve3.cpp.s
.PHONY : utests/curve3.cpp.s

utests/face.o: utests/face.cpp.o

.PHONY : utests/face.o

# target to build an object file
utests/face.cpp.o:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/face.cpp.o
.PHONY : utests/face.cpp.o

utests/face.i: utests/face.cpp.i

.PHONY : utests/face.i

# target to preprocess a source file
utests/face.cpp.i:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/face.cpp.i
.PHONY : utests/face.cpp.i

utests/face.s: utests/face.cpp.s

.PHONY : utests/face.s

# target to generate assembly for a file
utests/face.cpp.s:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/face.cpp.s
.PHONY : utests/face.cpp.s

utests/main.o: utests/main.cpp.o

.PHONY : utests/main.o

# target to build an object file
utests/main.cpp.o:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/main.cpp.o
.PHONY : utests/main.cpp.o

utests/main.i: utests/main.cpp.i

.PHONY : utests/main.i

# target to preprocess a source file
utests/main.cpp.i:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/main.cpp.i
.PHONY : utests/main.cpp.i

utests/main.s: utests/main.cpp.s

.PHONY : utests/main.s

# target to generate assembly for a file
utests/main.cpp.s:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/main.cpp.s
.PHONY : utests/main.cpp.s

utests/solid.o: utests/solid.cpp.o

.PHONY : utests/solid.o

# target to build an object file
utests/solid.cpp.o:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/solid.cpp.o
.PHONY : utests/solid.cpp.o

utests/solid.i: utests/solid.cpp.i

.PHONY : utests/solid.i

# target to preprocess a source file
utests/solid.cpp.i:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/solid.cpp.i
.PHONY : utests/solid.cpp.i

utests/solid.s: utests/solid.cpp.s

.PHONY : utests/solid.s

# target to generate assembly for a file
utests/solid.cpp.s:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/solid.cpp.s
.PHONY : utests/solid.cpp.s

utests/trans.o: utests/trans.cpp.o

.PHONY : utests/trans.o

# target to build an object file
utests/trans.cpp.o:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/trans.cpp.o
.PHONY : utests/trans.cpp.o

utests/trans.i: utests/trans.cpp.i

.PHONY : utests/trans.i

# target to preprocess a source file
utests/trans.cpp.i:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/trans.cpp.i
.PHONY : utests/trans.cpp.i

utests/trans.s: utests/trans.cpp.s

.PHONY : utests/trans.s

# target to generate assembly for a file
utests/trans.cpp.s:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/trans.cpp.s
.PHONY : utests/trans.cpp.s

utests/wire.o: utests/wire.cpp.o

.PHONY : utests/wire.o

# target to build an object file
utests/wire.cpp.o:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/wire.cpp.o
.PHONY : utests/wire.cpp.o

utests/wire.i: utests/wire.cpp.i

.PHONY : utests/wire.i

# target to preprocess a source file
utests/wire.cpp.i:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/wire.cpp.i
.PHONY : utests/wire.cpp.i

utests/wire.s: utests/wire.cpp.s

.PHONY : utests/wire.s

# target to generate assembly for a file
utests/wire.cpp.s:
	$(MAKE) -f CMakeFiles/servoce_test.dir/build.make CMakeFiles/servoce_test.dir/utests/wire.cpp.s
.PHONY : utests/wire.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... install"
	@echo "... servoce"
	@echo "... install/local"
	@echo "... test"
	@echo "... list_install_components"
	@echo "... servoce_test"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... src/b64.o"
	@echo "... src/b64.i"
	@echo "... src/b64.s"
	@echo "... src/boolops.o"
	@echo "... src/boolops.i"
	@echo "... src/boolops.s"
	@echo "... src/camera.o"
	@echo "... src/camera.i"
	@echo "... src/camera.s"
	@echo "... src/convert.o"
	@echo "... src/convert.i"
	@echo "... src/convert.s"
	@echo "... src/curve2.o"
	@echo "... src/curve2.i"
	@echo "... src/curve2.s"
	@echo "... src/curve3.o"
	@echo "... src/curve3.i"
	@echo "... src/curve3.s"
	@echo "... src/face.o"
	@echo "... src/face.i"
	@echo "... src/face.s"
	@echo "... src/geombase.o"
	@echo "... src/geombase.i"
	@echo "... src/geombase.s"
	@echo "... src/interactive_object.o"
	@echo "... src/interactive_object.i"
	@echo "... src/interactive_object.s"
	@echo "... src/opencascade_types.o"
	@echo "... src/opencascade_types.i"
	@echo "... src/opencascade_types.s"
	@echo "... src/prs3d.o"
	@echo "... src/prs3d.i"
	@echo "... src/prs3d.s"
	@echo "... src/scene.o"
	@echo "... src/scene.i"
	@echo "... src/scene.s"
	@echo "... src/shape_view.o"
	@echo "... src/shape_view.i"
	@echo "... src/shape_view.s"
	@echo "... src/solid.o"
	@echo "... src/solid.i"
	@echo "... src/solid.s"
	@echo "... src/surface.o"
	@echo "... src/surface.i"
	@echo "... src/surface.s"
	@echo "... src/topo.o"
	@echo "... src/topo.i"
	@echo "... src/topo.s"
	@echo "... src/trans.o"
	@echo "... src/trans.i"
	@echo "... src/trans.s"
	@echo "... src/view.o"
	@echo "... src/view.i"
	@echo "... src/view.s"
	@echo "... src/viewer.o"
	@echo "... src/viewer.i"
	@echo "... src/viewer.s"
	@echo "... src/wire.o"
	@echo "... src/wire.i"
	@echo "... src/wire.s"
	@echo "... utests/curve3.o"
	@echo "... utests/curve3.i"
	@echo "... utests/curve3.s"
	@echo "... utests/face.o"
	@echo "... utests/face.i"
	@echo "... utests/face.s"
	@echo "... utests/main.o"
	@echo "... utests/main.i"
	@echo "... utests/main.s"
	@echo "... utests/solid.o"
	@echo "... utests/solid.i"
	@echo "... utests/solid.s"
	@echo "... utests/trans.o"
	@echo "... utests/trans.i"
	@echo "... utests/trans.s"
	@echo "... utests/wire.o"
	@echo "... utests/wire.i"
	@echo "... utests/wire.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

