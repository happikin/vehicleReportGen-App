# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/happikin/dev/projects/majorproject/ex2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/happikin/dev/projects/majorproject/ex2/build

# Include any dependencies generated for this target.
include CMakeFiles/SuspensionHealthpub.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SuspensionHealthpub.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SuspensionHealthpub.dir/flags.make

opendds_generated/StatusC.h: /opt/OpenDDS/share/ace/bin/tao_idl
opendds_generated/StatusC.h: /opt/OpenDDS/share/ace/bin/ace_gperf
opendds_generated/StatusC.h: ../Status.idl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/happikin/dev/projects/majorproject/ex2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating opendds_generated/StatusC.h, opendds_generated/StatusC.inl, opendds_generated/StatusS.h, opendds_generated/StatusC.cpp"
	/usr/bin/cmake -E env DDS_ROOT=/opt/OpenDDS/share/dds TAO_ROOT=/opt/OpenDDS/include LD_LIBRARY_PATH=/opt/OpenDDS/lib /opt/OpenDDS/share/ace/bin/tao_idl -g /opt/OpenDDS/share/ace/bin/ace_gperf -Sp -Sd -Sg -Wb,pre_include=ace/pre.h -Wb,post_include=ace/post.h --idl-version 4 -as --unknown-annotations ignore -I/opt/OpenDDS/include -I/home/happikin/dev/projects/majorproject/ex2 -I/opt/OpenDDS/share/dds -I/home/happikin/dev/projects/majorproject/ex2 -SS -Yp,/usr/bin/c++ -Sa -St -D__ACE_INLINE__ -o /home/happikin/dev/projects/majorproject/ex2/build/opendds_generated /home/happikin/dev/projects/majorproject/ex2/Status.idl

opendds_generated/StatusC.inl: opendds_generated/StatusC.h
	@$(CMAKE_COMMAND) -E touch_nocreate opendds_generated/StatusC.inl

opendds_generated/StatusS.h: opendds_generated/StatusC.h
	@$(CMAKE_COMMAND) -E touch_nocreate opendds_generated/StatusS.h

opendds_generated/StatusC.cpp: opendds_generated/StatusC.h
	@$(CMAKE_COMMAND) -E touch_nocreate opendds_generated/StatusC.cpp

opendds_generated/StatusTypeSupportC.h: /opt/OpenDDS/share/ace/bin/tao_idl
opendds_generated/StatusTypeSupportC.h: /opt/OpenDDS/share/ace/bin/ace_gperf
opendds_generated/StatusTypeSupportC.h: opendds_generated/StatusTypeSupport.idl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/happikin/dev/projects/majorproject/ex2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating opendds_generated/StatusTypeSupportC.h, opendds_generated/StatusTypeSupportC.inl, opendds_generated/StatusTypeSupportS.h, opendds_generated/StatusTypeSupportC.cpp"
	/usr/bin/cmake -E env DDS_ROOT=/opt/OpenDDS/share/dds TAO_ROOT=/opt/OpenDDS/include LD_LIBRARY_PATH=/opt/OpenDDS/lib /opt/OpenDDS/share/ace/bin/tao_idl -g /opt/OpenDDS/share/ace/bin/ace_gperf -Sp -Sd -Sg -Wb,pre_include=ace/pre.h -Wb,post_include=ace/post.h --idl-version 4 -as --unknown-annotations ignore -I/opt/OpenDDS/include -I/home/happikin/dev/projects/majorproject/ex2 -I/opt/OpenDDS/share/dds -I/home/happikin/dev/projects/majorproject/ex2 -SS -Yp,/usr/bin/c++ -Sa -St -D__ACE_INLINE__ -o /home/happikin/dev/projects/majorproject/ex2/build/opendds_generated /home/happikin/dev/projects/majorproject/ex2/build/opendds_generated/StatusTypeSupport.idl

opendds_generated/StatusTypeSupportC.inl: opendds_generated/StatusTypeSupportC.h
	@$(CMAKE_COMMAND) -E touch_nocreate opendds_generated/StatusTypeSupportC.inl

opendds_generated/StatusTypeSupportS.h: opendds_generated/StatusTypeSupportC.h
	@$(CMAKE_COMMAND) -E touch_nocreate opendds_generated/StatusTypeSupportS.h

opendds_generated/StatusTypeSupportC.cpp: opendds_generated/StatusTypeSupportC.h
	@$(CMAKE_COMMAND) -E touch_nocreate opendds_generated/StatusTypeSupportC.cpp

opendds_generated/StatusTypeSupportImpl.h: /opt/OpenDDS/bin/opendds_idl
opendds_generated/StatusTypeSupportImpl.h: /opt/OpenDDS/share/dds/dds/idl/IDLTemplate.txt
opendds_generated/StatusTypeSupportImpl.h: ../Status.idl
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/happikin/dev/projects/majorproject/ex2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating opendds_generated/StatusTypeSupportImpl.h, opendds_generated/StatusTypeSupportImpl.cpp, opendds_generated/StatusTypeSupport.idl"
	/usr/bin/cmake -E env DDS_ROOT=/opt/OpenDDS/share/dds TAO_ROOT=/opt/OpenDDS/include LD_LIBRARY_PATH=/opt/OpenDDS/lib /opt/OpenDDS/bin/opendds_idl -I/home/happikin/dev/projects/majorproject/ex2 --default-nested -Yp,/usr/bin/c++ -Sa -St -D__ACE_INLINE__ /home/happikin/dev/projects/majorproject/ex2/Status.idl -o /home/happikin/dev/projects/majorproject/ex2/build/opendds_generated

opendds_generated/StatusTypeSupportImpl.cpp: opendds_generated/StatusTypeSupportImpl.h
	@$(CMAKE_COMMAND) -E touch_nocreate opendds_generated/StatusTypeSupportImpl.cpp

opendds_generated/StatusTypeSupport.idl: opendds_generated/StatusTypeSupportImpl.h
	@$(CMAKE_COMMAND) -E touch_nocreate opendds_generated/StatusTypeSupport.idl

CMakeFiles/SuspensionHealthpub.dir/src/SuspensionHealthpub.cpp.o: CMakeFiles/SuspensionHealthpub.dir/flags.make
CMakeFiles/SuspensionHealthpub.dir/src/SuspensionHealthpub.cpp.o: ../src/SuspensionHealthpub.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/happikin/dev/projects/majorproject/ex2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SuspensionHealthpub.dir/src/SuspensionHealthpub.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SuspensionHealthpub.dir/src/SuspensionHealthpub.cpp.o -c /home/happikin/dev/projects/majorproject/ex2/src/SuspensionHealthpub.cpp

CMakeFiles/SuspensionHealthpub.dir/src/SuspensionHealthpub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SuspensionHealthpub.dir/src/SuspensionHealthpub.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/happikin/dev/projects/majorproject/ex2/src/SuspensionHealthpub.cpp > CMakeFiles/SuspensionHealthpub.dir/src/SuspensionHealthpub.cpp.i

CMakeFiles/SuspensionHealthpub.dir/src/SuspensionHealthpub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SuspensionHealthpub.dir/src/SuspensionHealthpub.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/happikin/dev/projects/majorproject/ex2/src/SuspensionHealthpub.cpp -o CMakeFiles/SuspensionHealthpub.dir/src/SuspensionHealthpub.cpp.s

# Object files for target SuspensionHealthpub
SuspensionHealthpub_OBJECTS = \
"CMakeFiles/SuspensionHealthpub.dir/src/SuspensionHealthpub.cpp.o"

# External object files for target SuspensionHealthpub
SuspensionHealthpub_EXTERNAL_OBJECTS =

SuspensionHealthpub: CMakeFiles/SuspensionHealthpub.dir/src/SuspensionHealthpub.cpp.o
SuspensionHealthpub: CMakeFiles/SuspensionHealthpub.dir/build.make
SuspensionHealthpub: /opt/OpenDDS/lib/libOpenDDS_InfoRepoDiscovery.so.3.20.0
SuspensionHealthpub: /opt/OpenDDS/lib/libOpenDDS_Tcp.so.3.20.0
SuspensionHealthpub: /opt/OpenDDS/lib/libOpenDDS_Rtps_Udp.so.3.20.0
SuspensionHealthpub: libStatus_idl.a
SuspensionHealthpub: /opt/OpenDDS/lib/libOpenDDS_Rtps.so.3.20.0
SuspensionHealthpub: /opt/OpenDDS/lib/libOpenDDS_Dcps.so.3.20.0
SuspensionHealthpub: /opt/OpenDDS/lib/libTAO_PortableServer.so.2.2a_p23
SuspensionHealthpub: /opt/OpenDDS/lib/libTAO_BiDirGIOP.so.2.2a_p23
SuspensionHealthpub: /opt/OpenDDS/lib/libTAO_PI.so.2.2a_p23
SuspensionHealthpub: /opt/OpenDDS/lib/libTAO_CodecFactory.so.2.2a_p23
SuspensionHealthpub: /opt/OpenDDS/lib/libTAO_AnyTypeCode.so.2.2a_p23
SuspensionHealthpub: /opt/OpenDDS/lib/libTAO.so.2.2a_p23
SuspensionHealthpub: /opt/OpenDDS/lib/libACE.so.6.2a_p23
SuspensionHealthpub: CMakeFiles/SuspensionHealthpub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/happikin/dev/projects/majorproject/ex2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable SuspensionHealthpub"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SuspensionHealthpub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SuspensionHealthpub.dir/build: SuspensionHealthpub

.PHONY : CMakeFiles/SuspensionHealthpub.dir/build

CMakeFiles/SuspensionHealthpub.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SuspensionHealthpub.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SuspensionHealthpub.dir/clean

CMakeFiles/SuspensionHealthpub.dir/depend: opendds_generated/StatusC.h
CMakeFiles/SuspensionHealthpub.dir/depend: opendds_generated/StatusC.inl
CMakeFiles/SuspensionHealthpub.dir/depend: opendds_generated/StatusS.h
CMakeFiles/SuspensionHealthpub.dir/depend: opendds_generated/StatusC.cpp
CMakeFiles/SuspensionHealthpub.dir/depend: opendds_generated/StatusTypeSupportC.h
CMakeFiles/SuspensionHealthpub.dir/depend: opendds_generated/StatusTypeSupportC.inl
CMakeFiles/SuspensionHealthpub.dir/depend: opendds_generated/StatusTypeSupportS.h
CMakeFiles/SuspensionHealthpub.dir/depend: opendds_generated/StatusTypeSupportC.cpp
CMakeFiles/SuspensionHealthpub.dir/depend: opendds_generated/StatusTypeSupportImpl.h
CMakeFiles/SuspensionHealthpub.dir/depend: opendds_generated/StatusTypeSupportImpl.cpp
CMakeFiles/SuspensionHealthpub.dir/depend: opendds_generated/StatusTypeSupport.idl
	cd /home/happikin/dev/projects/majorproject/ex2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/happikin/dev/projects/majorproject/ex2 /home/happikin/dev/projects/majorproject/ex2 /home/happikin/dev/projects/majorproject/ex2/build /home/happikin/dev/projects/majorproject/ex2/build /home/happikin/dev/projects/majorproject/ex2/build/CMakeFiles/SuspensionHealthpub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SuspensionHealthpub.dir/depend

