CXX=g++
# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#  -Werror=* turns those warnings into errors.
#     This makes it harder to ignore warnings that are likely to be failures on a basic Linux machine
CXXFLAGS = -g -std=c++11 -Wall -Werror=return-type  -Werror=uninitialized


all: test-1-point test-2-polygon test-3-matrix3d test-4-polygon-advanced test-5-gis

test-1-point: test/catch/catch.o test/test-1-point.cpp point.o
	$(CXX) $(CXXFLAGS) $^ -o test/test-1-point
	test/test-1-point --success

test-2-polygon: test/catch/catch.o test/test-2-polygon.cpp polygon.o point.o matrix3d.o
	$(CXX) $(CXXFLAGS) $^ -o test/test-2-polygon
	test/test-2-polygon --success

test-3-matrix3d: test/catch/catch.o test/test-3-matrix3d.cpp polygon.o point.o matrix3d.o
	$(CXX) $(CXXFLAGS) $^ -o test/test-3-matrix3d
	test/test-3-matrix3d --success

test-4-polygon-advanced: test/catch/catch.o test/test-4-polygon-advanced.cpp point.o polygon.o matrix3d.o
	$(CXX) $(CXXFLAGS) $^ -o test/test-4-polygon-advanced
	test/test-4-polygon-advanced --success

test-5-gis: test/catch/catch.o test/test-5-gis.cpp point.o polygon.o matrix3d.o gis.o
	$(CXX) $(CXXFLAGS) $^ -o test/test-5-gis
	test/test-5-gis --success

main: main.cpp point.o polygon.o matrix3d.o gis.o
	$(CXX) $(CXXFLAGS) $^ -o main

# SHOULDN'T NEED TO CHANGE THE CLEAN RULE, BUT FEEL FREE IF IT HELPS
clean:
	rm -rf *.dSYM test/*.dSYM
	$(RM) *.o *.gc* main test/*.o test/catch/catch.o test/test-1-point test/test-2-polygon test/test-3-matrix3d test/test-4-polygon-advanced test/test-5-gis

# DO NOT CHANGE THESE RULES, OR YOU WILL LOSE CREDIT
# You can run them using (e.g.) `make simple-main` to test your final main application
simple-main: main
	echo -e "bad-file-name.zz\nsimple-polygons.txt\n1\n1\n3\n3\n7\n7\nq\n" | ./main

complex-main: main
	echo -e "polygons.txt\n2\n14\n0\n2\n2\n8\n5\n9\n5\n5\n5\n0\n7\n4\nq\n" | ./main

