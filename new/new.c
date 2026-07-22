int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <source_file.pas>\n", argv);
        return 1;
    }

    char *pascal_program = read_file(argv);
    if (!pascal_program) return 1;

    printf("--- Phase 1: Parsing AST ---\n");
    ASTNode *ast = parse_ast(pascal_program);
    
    printf("\n--- Visual AST Representation (Unoptimized) ---\n");
    print_ast(ast, 0);

    printf("\n--- Phase 2: Optimizing AST ---\n");
    ast = optimize_ast(ast);

    printf("\n--- Visual AST Representation (Optimized) ---\n");
    print_ast(ast, 0);

    printf("\n--- Phase 3: Emitting VM Bytecode ---\n");
    generate_code(ast);
    code[code_idx++] = (Instruction){OP_HALT, 0};
    printf("Compilation completed. Total Instructions: %d\n", code_idx);

    printf("\n--- Phase 4: Virtual Machine execution ---\n");
    run_vm();

    printf("\n--- Execution Output Results ---\n");
    for (int i = 0; i < sym_count; i++) {
        printf("%s = %d\n", sym_table[i], vm_vars[i]);
    }

    free_ast(ast);
    free(pascal_program);
    return 0;
}
