# To Do

1. ~~Break up source file into multiple source files~~
2. ~~Input file <name>.pas~~
3. Add options - can also be achieved by having 3 different main programs
    1. pascal file.pas              ; compile and run
    2. pascal file.pas -o file.svm  ; compile and save to stack VM          pc
    3. pascal -b file.svm           ; load and run VM file                  svm
    * do this later
    
4. Expand on syntax until Google AI gives up



# From Gemini

* Add Control Flow structural support like IF/THEN loops
* Incorporate Write / WriteLn IO procedures
* ~~Implement an abstract syntax tree (AST) for cleaner optimization~~
* Create a bytecode output module to save compiled binaries directly to a file
* Add Dead Code Elimination (e.g., removing variables that are assigned but never used)
* ~~Implement an AST Printer to output a visual tree structure text representation~~
* Incorporate relational conditional tokens like >, <, and =
* Introduce jump offsets to support IF-THEN branch structures
