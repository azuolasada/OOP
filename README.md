Overview
This program sorts student data based on their final scores and categorizes them into different performance groups.

Features
Processes data using Student class.
Supports both std::list and std::vector.
Offers multiple strategies for data processing.
Reads and writes student data to/from files.




Usage
Run the program.
Choose container type ('l' for list, 'v' for vector).
Select processing strategy (1, 2, or 3).
Choose input method('m' for manual, 'f' for file).
Choose output method('s' for screen, 'f' for file).
Select sort criterion (name,surname or finalScore).



Compile with:
g++ -O3 -std=c++17 -o v1.5 v1,5.cpp side_functions.cpp student.cpp



Run with:
Copy code
./v1.5



Notes
Input files should be in CSV format.
Outputs are categorized into 'good' and 'bad' based on student scores.