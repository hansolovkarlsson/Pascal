# To Do

1. ~~Break up source file into multiple source files~~

2. ~~Input file <name>.pas~~

3. Expand on syntax until Google AI gives up

4. ~~Add options - can also be achieved by having 3 different main programs~~
    pascal -c <file.pas> <file.bin>
    pascal -r <file.bin>
    



# From Gemini

https://share.google/aimode/4AP5PmheFvhgb7HAg

* Add Control Flow structural support like IF/THEN loops
* Incorporate Write / WriteLn IO procedures
* ~~Implement an abstract syntax tree (AST) for cleaner optimization~~
* ~~Create a bytecode output module to save compiled binaries directly to a file~~
* Add Dead Code Elimination (e.g., removing variables that are assigned but never used)
* ~~Implement an AST Printer to output a visual tree structure text representation~~
* Incorporate relational conditional tokens like >, <, and =
* Introduce jump offsets to support IF-THEN branch structures
* Implement a Bytecode Disassembler to print instructions inside binary objects
* ~~Add Global Type Check Validation for handling different variable categories~~
* Implicit Type Coercion (e.g., handling mixed conversions if you want to add a real/float data type)
* Type checking for control-flow expressions (e.g., ensuring that the condition inside an IF statement evaluates to a boolean) [5, 6, 7, 8] 
* Add type checking to control-flow expressions (e.g., ensuring an IF test condition evaluates to a strict boolean)
* Implement boolean-specific operators like AND, OR, or NOT structures
* Show you how to implement IF-THEN control flow structures
* Add relational boolean comparison operators like =, <, or >
