#ifndef AST_H
#define AST_H

#include "base.h"
#include "parser.h"
#include "symbol_table.h"

struct AstNode {
    char *name;
    int kind;
    Type type;
    Value value;
    Symbol *symbol;
    int linenum;
    struct AstNode* children;
    struct AstNode* sibling;
};

struct AstNode *ast_node_new(const char* name, int kind, int type,
                             int linenum, Symbol *symbol);
void ast_node_destroy(struct AstNode *node);
void ast_node_add_child(struct AstNode *node, struct AstNode *child);
void ast_node_add_sibling(struct AstNode *node, struct AstNode *sibling);
void ast_node_print(struct AstNode *node);
void ast_node_print_graph(struct AstNode *node);

#endif // AST_H