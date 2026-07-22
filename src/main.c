#include <stdio.h>
#include "compiler.h"
#include "vm.h"

int main() {
    const char *pascal_program = 
        "program MathTest;\n"
        "var x, y, result : integer;\n"
        "begin\n"
        "  x := 15;\n"
        "  y := 5;\n"
        "  result := x * 2 + y - 3;\n"
        "end.";

    printf("Compiling Pascal Program...\n");
    compile(pascal_program);
    printf("Compilation successful. Generated %d instructions.\n", code_idx);

    printf("\nRunning Virtual Machine...\n");
    run_vm();

    printf("\nVM Execution Finished. Final State:\n");
    for (int i = 0; i < sym_count; i++) {
        printf("%s = %d\n", sym_table[i], vm_vars[i]);
    }

    return 0;
}
