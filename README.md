# SudokuF - A Sudoku Solver

## Introduction

It's a sudoku solver based on python(openpyxl) and c++. You can give it an xlsx table and tell it where the question sheet is by editing $\text{config.py}$.After finishing running, there is an output file named $\text{solution.csv}$. You can view the answer in it.

It's for Windows, but you can use it on Linux or Darwin with some simple changes. Just compile the cpp file again and edit the last line of $\text{main.py}$.

## Installtion

1. Download the source code (git or zip).

2. Run `pip install openpyxl` or `pip3 install openpyxl`.

3. Make sure the cpp file is okey to compile or the exe can run on your computer.

4. Make sure the folder is not read-only.

## Run

1. Prepare an xlsx file with a suduku question(A1:I9)

2. Tell the solver where the file is and which sheet it is in by editing $\text{config.py}$.

3. Click main.py or run `python main.py` or `python3 main.py`.

4. Then you can find the solution in $\text{solution.csv}$.








