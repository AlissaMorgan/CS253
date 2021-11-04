# This is a Makefile.  Its purpose is to create the program “small”.
#
# The rules, below, indicate what depends on what, and how to build
# things when they get out-of-date.  It is VERY important to know that
# what looks like eight leading spaces is really a leading tab
# character.  Leading spaces won’t work--it MUST be a tab character.
#
# For the following questions, do the command if there is one,
# and then answer the question.  If you need another line for you
# answer, continue it on the next line, indented.
#
# As an example, I’ve already answered (1), which has nothing to do
# with anything else in this lab.
#
# Question 1 is worth 0.09 points; questions 2–14 are worth 0.07
# points each.
#
#  1) Command:  date +%A
#     Question: Describe the output of that command.
#     Answer:   It’s today’s day of the week.
#
#  2) Command:  make
#     Question: Describe what happens.  Don’t just write the commands;
#     		describe what each command does.
#     Answer:   Determines which files need to be recompiled based on the dependencies in the #		Makefile and if any file is out of date then recompiles the needed files. 
# 
#  3) Command:  ./small
#     Question: What is the output?  Reproduce the output exactly.
#     Answer:   Runs the program small, which executes main.o and foo.o
#
#  4) Command:  make
#     Question: Why did nothing much happen?
#     Answer:   No file has been modified since we last compiled. 
#
#  5) Command:  rm small; make
#     Question: What got remade, and why?
#     Answer:   main.o and foo.o were remade because small depends on them. Since main.o and #		foo.o were remade, small also was remade.  
#
#  6) Command:  rm foo.o; make 
#     Question: What got remade, and why?
#     Answer:   foo.c was remade because foo.o depends on foo.c. This means that foo.o was modified, #		so small was also remade. 
#
#  7) Command:  make clean 
#     Question: What did that do?
#     Answer:   removed small and any .o file (main.o and foo.o)
#
#  8) Command:  make 
#     Question: What got remade, and why?
#     Answer:   main.o and foo.o were remade in order to remake small because small, main.o, and #		foo.o didn't exist. 
#
#  9) Question: Why does main.o depend on foo.h?
#		I know that it’s because the Makefile says so.
#		Why was that dependency put into the Makefile?
#     Answer:   main.o needs to know where to find the functions used in main.cc, which can be found #		in foo.h
#
# 10) Command:  Create a new function bar() in bar.cc & bar.h,
# 		similar to foo.cc.  Change main.cc to call the new
# 		bar() function, make sure to #include the proper .h
# 		files everywhere, and type “make”.  Don’t alter Makefile.
#     Question: Why did it fail?
#     Answer:   When trying to recompile main.cc, there is no executable for bar.cc because the make #		file never told the computer to make a bar.o, so main.o can't compile. This creates #		an error because bar() can't be found. 
#
# 11) Command:  Fix the Makefile; verify with “make” until it compiles.
#     Question: Describe your changes.  Don’t just show the changed
#     		lines--describe the purpose of each change.
#     Answer:   To make the executable bar.o, I made bar.o dependent on bar.cc and bar.h and compile #		based on bar.cc. To tell main.o that bar() is in bar.cc, I made main.o dependent #		upon bar.h. To connect all executables, I made small dependent upon main.o, foo.o, #		and bar.o. 
#
# 12) Command:  Uncomment the CXXFLAGS= line, and type “make”.
#     Question: Why didn't anything happen?
#     Answer:   no files were modified so nothing was recompiled. 
#
# 13) Command:  Force a rebuild with: make clean; make 
#     Question: What’s new about the commands executed?
#     Answer:   The *.cc and *.o files are compiled with c++17 and differing flags now. 
#
# 14) Command: 	make clean; ls -l clean
#     Question: The target is “clean”, but no file “clean” got created.
#     		Why not?
#     Answer:   make clean removes the small file and all .o files, not create a file called clean. 
#
# For extra fame & glory (but no extra points):
#
# 15) Command:  Consult the make manual at
# 		https://www.gnu.org/software/make/manual/make.html
#		and improve this Makefile by using $@ in the rule
#		that creates “small” itself.

# The CXX variable contains the name of the C++ compiler.  You can’t
# have plus signs in a Make variable, so X is a rotated plus sign.
CXX=g++

CXXFLAGS=-std=c++17 -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -Wctor-dtor-privacy -Wold-style-cast -D_GLIBCXX_DEBUG -fno-diagnostics-show-option

small: main.o foo.o bar.o
	$(CXX) $(CXXFLAGS) main.o foo.o bar.o -o small

main.o: main.cc foo.h bar.h
	$(CXX) $(CXXFLAGS) -c main.cc

foo.o: foo.cc foo.h
	$(CXX) $(CXXFLAGS) -c foo.cc

bar.o: bar.cc bar.h
	$(CXX) $(CXXFLAGS) -c bar.cc

clean:
	-rm -f small *.o
