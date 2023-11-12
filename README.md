# OOP
Overview
This program categorizes students into 'good' and 'bad' categories based on their scores. It offers different strategies for sorting and provides performance metrics for each operation.

Compiling

g++ -std=c++17 -o v1.0 v1.0.cpp side_functions.cpp

Running the Program

After successful compilation, run the program with:

./v1.0


Usage

Upon running, the program will prompt you for inputs:

Container Type: Choose the type of container to use for storing students.

Enter 'l' for std::list.

Enter 'v' for std::vector.

Strategy: Choose the sorting strategy.

Enter '1' for Strategy 1 (basic sorting without optimizations).

Enter '2' for Strategy 2 (optimizes memory by modifying the original container).

Enter '3' for Strategy 3 (optimized for std::vector using efficient sorting algorithms).

The program will then process the student data from the specified file and output the time taken for each phase (reading data, sorting, writing data) and the total processing time.

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
Read time: 0.00219637 seconds.
Sort time: 0.000954803 seconds.
Write time: 0.00115382 seconds.
Total processing time: 0.004305 seconds.
-----------------------------------------
File: students_10000.csv
Read time: 0.0179392 seconds.
Sort time: 0.0113228 seconds.
Write time: 0.00832428 seconds.
Total processing time: 0.0375862 seconds.
-----------------------------------------
File: students_100000.csv
Read time: 0.168481 seconds.
Sort time: 0.155091 seconds.
Write time: 0.0856886 seconds.
Total processing time: 0.409261 seconds.
-----------------------------------------
File: students_1000000.csv
Read time: 1.67114 seconds.
Sort time: 2.0001 seconds.
Write time: 0.931938 seconds.
Total processing time: 4.60318 seconds.

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
Read time: 0.00221898 seconds.
Sort time: 0.000453276 seconds.
Write time: 0.00140396 seconds.
Total processing time: 0.00407622 seconds.
-----------------------------------------
File: students_10000.csv
Read time: 0.017829 seconds.
Sort time: 0.0053875 seconds.
Write time: 0.0110899 seconds.
Total processing time: 0.0343064 seconds.
-----------------------------------------
File: students_100000.csv
Read time: 0.17879 seconds.
Sort time: 0.0733479 seconds.
Write time: 0.110435 seconds.
Total processing time: 0.362573 seconds.
-----------------------------------------
File: students_1000000.csv
Read time: 1.84095 seconds.
Sort time: 1.03266 seconds.
Write time: 1.30679 seconds.
Total processing time: 4.18039 seconds.
