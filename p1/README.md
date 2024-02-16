# Geographic Information System (GIS)
[![Points badge](../../blob/badges/.github/badges/points.svg)](../../actions)

## Project Outcomes:
Develop a C++ program that uses:
- Multi-dimensional arrays
- Arrays of complex objects
- Multiple user-defined classes
- Make rules for compiling and testing code

## Preparatory Readings:
- ZyBook chapters 1-7: C++ basics/review
- ZyBook chapter 9: Modular design and `make`

## Background Information:
### Project overview:
Geographic Information Systems (GIS) are a useful application of technology to the field of Geography.
GIS tools are used in systems such as GCCS, often used by the military for mission planning and high-level navigation.
They are also used by municipalities for managing resources such as monitoring watersheds for testing purposes.
County tax assessors likewise use such tools for assessing taxes on property owners.

All of these applications involve efficient and accurate querying of points (for example a mouse click) to determine whether a query is inside a particular polygon.
The purpose of such queries is often to report _which_ polygon contains the query point.
For this project, we'll only slightly worry about the efficiency of such a search.

Checking whether a point is inside a polygon depends on how the polygon is stored.
For this project, we'll work with convex polygons only, this enables us to simplify the inclusion check a bit.
In our case, polygons will be stored as a list of **Point**s given in clockwise order.
Thus, checking if a point is inside a polygon involves checking whether the point lies to the right of the directed line from **p<sub>i</sub>** to **p<sub>i+1</sub>** for all **i** vertices.
Sometimes, the "right" of the directed line is _above_ the line and other times, it is _below_.
Determining which is the appropriate check is difficult if comparing `x` and `y` values with the line equation.

There is a better way, math to the rescue!
Determining which side of a directed line from `a` to `b` a **Point** `p` lies on can be found by calculating the [determinant](https://en.wikipedia.org/wiki/Determinant) of the following matrix:
<code><pre>| 1    a<sub>x</sub>    a<sub>y</sub> |
| 1    b<sub>x</sub>    b<sub>y</sub> |
| 1    p<sub>x</sub>    p<sub>y</sub> |
</pre></code>

### Project Requirements:
Your application must function as described below:
1. Your program shall adhere to the [test](test/) suites distributed with this repository.
This means that all tests must pass in their current configuration.
1. Since one goal of this project is to learn how to build and run complex projects, no out-of-the-box Makefile is given.
	1. You must edit the [Makefile](Makefile) given to properly compile and run your code.
	1. The following rules must be created and should run the appropriate test suite file from the [test](test/) directory:
		- `test-1-point`
		- `test-2-polygon`
		- `test-3-matrix`
		- `test-4-polygon-advanced`
		- `test-5-gis`
1. Additionally, you must create a user-facing application that allows a user to specify an input file which conforms to the [Sample data](#sample-polygonal-data) format given below.
	- This application must be compiled by running `make main` and shall create an executable file called main.
	- Data will be given as alternating `x` and `y` values.
	- Each line of the input file will contain a single polygon.
	- All coordinate values are integer values.
	- The sample data below is a 2x2 square with the bottom left vertex at (0,0) and a rectangle that is two units high and six units wide with a bottom left vertex at (0,2).
	- Not all inputs will be axis-aligned rectangles, they are just good exemplars due to their simplicity.
1. The program must then allow queries to be submitted in the form of **x** and **y** coordinates and should report the _title_ of the polygon which contains the query point.
	- The user should be prompted for the x coordinate, then prompted for the y coordinate as seen in [Sample run of application](#sample-run-of-application) below.

#### Sample polygonal data
This sample data is found in [simple-polygons.txt](simple-polygons.txt).
A more complicated input file is in [polygons.txt](polygons.txt), for when you are ready to test your program against something more complicated.
```
squareParcel 0 0 0 2 2 2 2 0
wideRectangleParcel 0 2 0 4 6 4 6 2
```

#### Sample run of application
```
Please enter the file with the polygon data: bad-file-name.zz
Invalid file name!
Please enter the file with the polygon data: simple-polygons.txt

Coordinates of query point (non-integer quits)
	x: 1
	y: 1
Query point is inside: squareParcel

Coordinates of query point (non-integer quits)
	x: 3
	y: 3
Query point is inside: wideRectangleParcel

Coordinates of query point (non-integer quits)
	x: 7
	y: 7
Query point is inside: Query point not present in any known parcel

Coordinates of query point (non-integer quits)
	x: quit

Have a great day!
```

### Implementation Notes:
1. Create a project that is object oriented, therefore there should be several classes.
1. The input file will match the exact format given above.

[![Link to "Getting Started" video](https://res.cloudinary.com/dm3fdmzec/image/upload/v1611877323/Project_1_-_GIS_-_YouTube__vdwnfg.png)](https://youtu.be/ulJn2jPDN6M)

### Submission Requirements:
1. All code must be added and committed to your local git repository.
2. All code must be pushed to the GitHub repository created when you "accepted" the assignment.
	1. After pushing, with `git push origin main`, visit the web URL of your repository to verify that your code is there.
	If you don't see the code there, then we can't see it either.
3. Your code must compile and run. The auto-grading tests will indicate your score for your submission.
	1. The auto-grading build should begin automatically when you push your code to GitHub.
	2. If your program will not compile, the graders will not be responsible for trying to test it.
	3. You should get an email regarding the status of your build, if it does not pass, keep trying.

## Important Notes:
- Projects will be graded on whether they correctly solve the problem, and whether they adhere to good programming practices.
- Projects must be received by the time specified on the due date. Projects received after that time will get a grade of zero.
- Please review the academic honesty policy.
	- Note that viewing another student's solution, whether in whole or in part, is considered academic dishonesty.
	- Also note that submitting code obtained through the Internet or other sources, whether in whole or in part, is considered academic dishonesty.
	- All programs submitted will be reviewed for evidence of academic dishonesty, and all violations will be handled accordingly.

## Grading
- View on GitHub:
	1. On your GitHub repo page, Click the :arrow_forward: **Actions** tab to see your graded results.
	1. If it isn't a green check mark (:heavy_check_mark:) then at least part of the testing failed.
	1. Click the commit message for the failing version then click "Autograding" on the left side of the page.
	1. Follow the :x: path and expand things to see what errors exist.
	1. At the bottom of the _education/autograding_ section, you can view the score for the auto-grading portion of the rubric.
		It will look something like ***40/90***.
