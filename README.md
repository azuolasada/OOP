# OOP
v1.0

This is a simple program to manage student data, calculate their final scores, and sort them into categories.


What It Does


Reads student data from files.
Calculates scores for students.
Sorts students based on scores.
Writes sorted data to new files.


How to Use


Compile all the .cpp files in the project.
Run the compiled program.
Follow the on-screen instructions.


Files in the Project


v0.3.cpp: The main program.

side_functions.cpp: Contains side functions used in the main program.

Time averages (vector):
Strategy 1:

-----------------------------------------
File: students_1000.csv
Read time: 0.00228861 seconds.
Sort time: 0.000944754 seconds.
Write time: 0.00123954 seconds.
Total processing time: 0.0044729 seconds.
-----------------------------------------
File: students_10000.csv
Read time: 0.0211663 seconds.
Sort time: 0.0112507 seconds.
Write time: 0.00950556 seconds.
Total processing time: 0.0419226 seconds.
-----------------------------------------
File: students_100000.csv
Read time: 0.188785 seconds.
Sort time: 0.149576 seconds.
Write time: 0.0920896 seconds.
Total processing time: 0.430451 seconds.
-----------------------------------------
File: students_1000000.csv
Read time: 1.92084 seconds.
Sort time: 1.98602 seconds.
Write time: 0.970726 seconds.
Total processing time: 4.87758 seconds.

Strategy 2:
-----------------------------------------
File: students_1000.csv
Read time: 0.00237341 seconds.
Sort time: 0.000935052 seconds.
Write time: 0.0304455 seconds.
Total processing time: 0.033754 seconds.
-----------------------------------------
File: students_10000.csv
Read time: 0.026772 seconds.
Sort time: 0.011238 seconds.
Write time: 3.09683 seconds.
Total processing time: 3.13484 seconds.
-----------------------------------------
File: students_100000.csv
Read time: 0.183112 seconds.
Sort time: 0.150305 seconds.
Write time: 301.963 seconds.
Total processing time: 302.296 seconds.

NaN

Strategy 3:
-----------------------------------------
File: students_1000.csv
Read time: 0.00211033 seconds.
Sort time: 0.00108361 seconds.
Write time: 0.0013028 seconds.
Total processing time: 0.00449674 seconds.
-----------------------------------------
File: students_10000.csv
Read time: 0.0179079 seconds.
Sort time: 0.0133886 seconds.
Write time: 0.0108015 seconds.
Total processing time: 0.042098 seconds.
-----------------------------------------
File: students_100000.csv
Read time: 0.168995 seconds.
Sort time: 0.183667 seconds.
Write time: 0.10335 seconds.
Total processing time: 0.456012 seconds.
-----------------------------------------
File: students_1000000.csv
Read time: 1.69891 seconds.
Sort time: 2.39712 seconds.
Write time: 1.12614 seconds.
Total processing time: 5.22217 seconds.

Time averages(list):
Strategy 1:
-----------------------------------------
File: students_1000.csv
Read time: 0.00220979 seconds.
Sort time: 0.000459017 seconds.
Write time: 0.00128124 seconds.
Total processing time: 0.00395005 seconds.
-----------------------------------------
File: students_10000.csv
Read time: 0.0187449 seconds.
Sort time: 0.00556794 seconds.
Write time: 0.00828573 seconds.
Total processing time: 0.0325985 seconds.
-----------------------------------------
File: students_100000.csv
Read time: 0.184278 seconds.
Sort time: 0.0649531 seconds.
Write time: 0.0854591 seconds.
Total processing time: 0.33469 seconds.
-----------------------------------------
File: students_1000000.csv
Read time: 1.92206 seconds.
Sort time: 1.08167 seconds.
Write time: 1.03058 seconds.
Total processing time: 4.03431 seconds.

Strategy 2:
-----------------------------------------
File: students_1000.csv
Read time: 0.00223679 seconds.
Sort time: 0.00046602 seconds.
Write time: 0.00100012 seconds.
Total processing time: 0.00370292 seconds.
-----------------------------------------
File: students_10000.csv
Read time: 0.0184731 seconds.
Sort time: 0.00560782 seconds.
Write time: 0.00692744 seconds.
Total processing time: 0.0310083 seconds.
-----------------------------------------
File: students_100000.csv
Read time: 0.180833 seconds.
Sort time: 0.0658852 seconds.
Write time: 0.071678 seconds.
Total processing time: 0.318396 seconds.
-----------------------------------------
File: students_1000000.csv
Read time: 1.87972 seconds.
Sort time: 1.21176 seconds.
Write time: 0.933052 seconds.
Total processing time: 4.02453 seconds.

Strategy 3:
-----------------------------------------
File: students_1000.csv
Read time: 0.0021549 seconds.
Sort time: 0.000458654 seconds.
Write time: 0.00153691 seconds.
Total processing time: 0.00415047 seconds.
-----------------------------------------
File: students_10000.csv
Read time: 0.0182307 seconds.
Sort time: 0.00548761 seconds.
Write time: 0.0121416 seconds.
Total processing time: 0.03586 seconds.
-----------------------------------------
File: students_100000.csv
Read time: 0.180252 seconds.
Sort time: 0.068724 seconds.
Write time: 0.157162 seconds.
Total processing time: 0.406138 seconds.
-----------------------------------------
File: students_1000000.csv
Read time: 1.80134 seconds.
Sort time: 1.11793 seconds.
Write time: 1.75462 seconds.
Total processing time: 4.6739 seconds.
