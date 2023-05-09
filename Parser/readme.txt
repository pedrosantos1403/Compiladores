-> Retirando prefixo comum

if-stmt' -> if condition then stmt-list if-stmt
if-stmt -> end | else stmt-list end

expression' -> simple-expression expression
expression -> relop simple-expr | lambda

-> Retirando recurssão à esquerda

simple-expr -> term simple-expr'
simple-expr' -> addop term simple-expr' | lambda

term -> factor-a term'
term' -> mulop factor-a term' | lambda