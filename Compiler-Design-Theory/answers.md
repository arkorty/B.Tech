Q1: PCCST601 0000182: Explain the different phases of compilation with a suitable example?
A1: The compilation process is a sequence of phases that transform a high-level source code into low-level machine code. Each phase takes the output of the previous phase as input. The main phases are:
    1.  **Lexical Analysis:** The source code is scanned to break it into a series of tokens. For example, `position = initial + rate * 60` is broken into tokens: `position` (identifier), `=` (operator), `initial` (identifier), `+` (operator), `rate` (identifier), `*` (operator), `60` (number).
    2.  **Syntax Analysis (Parsing):** The tokens are arranged into a hierarchical structure called a parse tree (or syntax tree) that represents the grammatical structure of the source code.
    3.  **Semantic Analysis:** The parse tree is checked for semantic consistency with the language rules. This includes type checking and ensuring variables are declared before use. For the example, it would check if `initial` and `rate` are declared numeric types and convert the integer `60` to a floating-point number if `rate` is a float.
    4.  **Intermediate Code Generation:** An intermediate representation of the source code is generated. A common form is three-address code. The example expression would be converted to:
        ```
        t1 = int_to_float(60)
        t2 = id3 * t1
        t3 = id2 + t2
        id1 = t3
        ```
    5.  **Code Optimization:** The intermediate code is improved to make it run faster and take up less space. For example, the multiplication by a constant could be replaced by a series of shifts and adds.
    6.  **Code Generation:** The final phase generates the target machine code or assembly code from the optimized intermediate code. This involves register allocation and instruction selection.
    **Symbol Table Management:** This runs concurrently with all phases, storing information about identifiers (variables, functions, etc.) like their type and scope.

Q2: PCCST601 0000183: Explain how the following expression is translated via different phases of compilation using a suitable diagram: position = initial + rate * 60
A2: The translation of `position = initial + rate * 60` through the phases of compilation is as follows:
    1.  **Lexical Analyzer:** Breaks the expression into a stream of tokens: `<id, 'position'>` `<=>` `<id, 'initial'>` `<+>` `<id, 'rate'>` `<*>` `<number, 60>`.
    2.  **Syntax Analyzer:** Creates a parse tree from the tokens, following the rules of grammar to establish operator precedence (multiplication before addition).
        ```
              =
             / \
        position  +
                 / \
            initial   *
                     / \
                    rate 60
        ```
    3.  **Semantic Analyzer:** Checks the types of the identifiers from the symbol table. It coerces the integer `60` into a floating-point number if `rate` or `initial` are floats. The output is an annotated syntax tree.
    4.  **Intermediate Code Generator:** Generates three-address code:
        ```
        t1 = 60
        t2 = rate * t1
        t3 = initial + t2
        position = t3
        ```
    5.  **Code Optimizer:** If `rate` was a constant, constant folding could be applied. Here, no major optimization is obvious.
    6.  **Code Generator:** Generates target assembly code, for example:
        ```assembly
        LDF R2, rate
        MULF R2, R2, #60.0
        LDF R1, initial
        ADDF R1, R1, R2
        STF position, R1
        ```

Q3: PCCST601 0000184: Write short note on any three of the following: i. Three-address code ii. Syntax tree iii. Symbol table iv. Lexical analysis v. Back end compilation
A3:
    **i. Three-Address Code:** This is a type of intermediate code representation used by compilers where each instruction has at most three operands. A typical instruction is of the form `result = arg1 op arg2`. This format is useful because it breaks down complex expressions into a sequence of simple, manageable instructions, making it easier to perform optimizations and translate into machine code.
    **ii. Syntax Tree:** An Abstract Syntax Tree (AST) is a tree representation of the syntactic structure of source code. Each node denotes a construct, with the tree's structure following the grammar of the language. It is "abstract" because it omits details like parentheses and other syntactic sugar. The AST is created by the parser and is a primary data structure for all subsequent compiler phases.
    **iii. Symbol Table:** A symbol table is a data structure used by a compiler to store information about all identifiers in a program (e.g., variables, functions). The information includes the identifier's name, type, scope, and memory location. It is essential for semantic analysis (e.g., type checking) and code generation.

Q4: PCCST601 0000185: What do you mean by Symbol Table? Explain the different operations/methods that can be performed on a Symbol Table? What are the different ways to implement Symbol Table? Explain each category in detail.
A4: A **Symbol Table** is a crucial data structure used by a compiler to keep track of identifiers and their attributes (like type, scope, memory location).
    **Operations on a Symbol Table:**
    1.  **Insert/Enter:** Adds a new identifier to the table when a new variable or function is declared.
    2.  **Lookup/Find:** Searches for an identifier to retrieve its attributes, which is essential for checking declarations and types.
    3.  **Set Attribute:** Modifies the attributes of an existing identifier.
    4.  **Delete/Remove:** Removes an identifier from the table, for instance, when its scope ends.
    **Implementation of Symbol Tables:**
    1.  **Linear List:** A simple list or array. Insertion is fast (O(1)), but lookup is slow (O(n)).
    2.  **Hash Table:** The most common and efficient method. It uses a hash function to map an identifier to an index, providing fast average-case time for insertion and lookup (O(1)). Collisions are handled using techniques like chaining.
    3.  **Binary Search Tree (BST):** Keeps identifiers sorted, which can be useful. Lookup and insertion times are O(log n) on average for a balanced tree.
    4.  **Scope-based Symbol Tables:** For block-structured languages, a stack of hash tables is often used. A new table is pushed for a new scope and popped when the scope is exited, naturally handling variable visibility.

Q5: PCCST601 0000186: What do you mean by ambiguity of a grammar? Explain with a suitable example? Consider the following grammar, show that the string 'aa+a' can be generated by this grammar? Construct the parse tree? S -> S + S | S S * | a
A5: A grammar is **ambiguous** if it can produce more than one parse tree for a single string. This means the string's syntactic structure is not uniquely defined.
    
The production `S S *` in the question appears to be a typo, likely for `S * S`. Assuming this correction, the string 'a+a*a' can be generated.
    **Leftmost Derivation (assuming S -> S * S):**
    `S -> S + S`
    `-> a + S`
    `-> a + S * S`
    `-> a + a * S`
    `-> a + a * a`
    **Parse Tree:** This derivation corresponds to a tree where `+` is the root, and `*` is its right child, correctly giving multiplication higher precedence.
    ```
          +
         / \
        S   *
        |  / \
        a S   S
          |   |
          a   a
    ```

Q6: PCCST601 0000187: What do you mean by ambiguity of a grammar? Explain with a suitable example? Consider the following grammar, show that the string '() ()' can be generated by this grammar? Construct the parse tree? S -> ( S ) | S S | a
A6: A grammar is **ambiguous** if a string can have more than one parse tree, meaning its structure is not uniquely defined.
    The grammar `S -> ( S ) | S S | a` cannot generate the string `'() ()'` because it has no rule to produce an empty string (`ε`) inside the parentheses. If we assume the rule `S -> a` was intended to be `S -> ε` (a common pattern for base cases), then a derivation is possible.
    **Derivation for '() ()' (assuming S -> ε):**
    1. `S -> S S`
    2. `-> ( S ) S`
    3. `-> ( ε ) S` which is `()S`
    4. `-> () ( S )`
    5. `-> () ( ε )` which is `()()`
    **Parse Tree (assuming S -> ε):**
    ```
          S
         / \
        S   S
       /|\ /|\
      ( S ) ( S )
        |     |
        ε     ε
    ```
    *(Note: The question is ill-formed. The provided grammar generates strings like `(a)(a)` but not `()()`. The answer assumes a corrected grammar `S -> (S) | SS | ε`.)*

Q7: PCCST601 0000188: Consider the following grammar and draw the LR(0) automaton: S -> L = R | L, L -> *R | id, R -> L
A7: The LR(0) automaton is a set of states (item sets) connected by GOTO transitions. The augmented grammar is `S' -> S`.
    - **I0:** `CLOSURE({S' -> .S})` = `{ S' -> .S, S -> .L=R, S -> .L, L -> .*R, L -> .id, R -> .L }`
    - **I1:** `GOTO(I0, S)` = `{ S' -> S. }` (Accept)
    - **I2:** `GOTO(I0, L)` = `CLOSURE({S -> L.=R, S -> L., R -> L.})` = `{ S -> L.=R, S -> L., R -> L. }`
    - **I3:** `GOTO(I0, *)` = `CLOSURE({L -> *.R})` = `{ L -> *.R, R -> .L, L -> .*R, L -> .id }`
    - **I4:** `GOTO(I0, id)` = `{ L -> id. }`
    - **I5:** `GOTO(I2, =)` = `CLOSURE({S -> L=.R})` = `{ S -> L=.R, R -> .L, L -> .*R, L -> .id }`
    - **I6:** `GOTO(I3, R)` = `{ L -> *R. }`
    - **I7:** `GOTO(I3, L)` = `{ R -> L. }`
    - **I8:** `GOTO(I5, R)` = `{ S -> L=R. }`
    - **I9:** `GOTO(I5, L)` = `{ R -> L. }` (Same as I7)

Q8: PCCST601 0000189: Show that SLR parser can not be constructed for the following grammar. Consider the following LR(0) automaton for constructing the SLR parsing table. S -> L = R | L, L -> *R | id, R -> L
A8: An SLR parser cannot be constructed if there is a shift-reduce or reduce-reduce conflict in any state of the LR(0) automaton.
    First, we determine the necessary `FOLLOW` sets.
    `FOLLOW(S) = { $ }`
    `FOLLOW(R) = FOLLOW(S) U FOLLOW(L) = { $ } U FOLLOW(L)`
    `FOLLOW(L) = { = } U FOLLOW(R)`
    Solving these, we find `FOLLOW(L) = FOLLOW(R) = { =, $ }`.

    Now, consider state **I2** from the LR(0) automaton:
    `I2 = { S -> L.=R, S -> L., R -> L. }`

    This state has a **shift-reduce conflict** on the lookahead symbol `= `:
    1.  **Shift Action:** The item `S -> L.=R` indicates that on input `=`, the parser should shift the token and transition to another state.
    2.  **Reduce Action:** The item `R -> L.` is a reduce item. The parser should reduce by this rule if the lookahead is in `FOLLOW(R)`. Since `FOLLOW(R)` contains `=`, the parser is instructed to reduce by `R -> L` on input `= `.

    Because the parser has conflicting actions (shift and reduce) in the same state (`I2`) on the same lookahead (`=`), the grammar is not SLR(1).

Q9: PCCST601 0000190: Construct the LR(1) automaton for the following grammar: S' -> S, S -> CC, C -> cC | d
A9: The LR(1) automaton consists of LR(1) items `[production, lookahead]`.
    - **I0:** `CLOSURE({[S' -> .S, $]})` = `{ [S' -> .S, $], [S -> .CC, $], [C -> .cC, c/d], [C -> .d, c/d] }`
    - **I1:** `GOTO(I0, S)` = `{ [S' -> S., $] }` (Accept)
    - **I2:** `GOTO(I0, C)` = `CLOSURE({[S -> C.C, $]})` = `{ [S -> C.C, $], [C -> .cC, $], [C -> .d, $] }`
    - **I3:** `GOTO(I0, c)` = `CLOSURE({[C -> c.C, c/d]})` = `{ [C -> c.C, c/d], [C -> .cC, c/d], [C -> .d, c/d] }`
    - **I4:** `GOTO(I0, d)` = `{ [C -> d., c/d] }`
    - **I5:** `GOTO(I2, C)` = `{ [S -> CC., $] }`
    - **I6:** `GOTO(I2, c)` = `CLOSURE({[C -> c.C, $]})` = `{ [C -> c.C, $], [C -> .cC, $], [C -> .d, $] }`
    - **I7:** `GOTO(I2, d)` = `{ [C -> d., $] }`
    - **I8:** `GOTO(I3, C)` = `{ [C -> cC., c/d] }`
    - `GOTO(I3, c)` is `I3` itself.
    - `GOTO(I3, d)` is `I4`.
    - **I9:** `GOTO(I6, C)` = `{ [C -> cC., $] }`
    - `GOTO(I6, c)` is `I6` itself.
    - `GOTO(I6, d)` is `I7`.

Q10: PCCST601 0000192: Show that the string 'id + id * id' has two distinct leftmost derivation for the following grammar. Draw both parse trees by showing the construction at every step of the derivation. E -> E + E | E * E | ( E ) | id
A10: The grammar is ambiguous because a string can have more than one leftmost derivation, leading to different parse trees.
    **Leftmost Derivation 1 (corresponds to `id + (id * id)`):**
    1. `E -> E + E`
    2. `-> id + E`
    3. `-> id + E * E`
    4. `-> id + id * E`
    5. `-> id + id * id`
    **Parse Tree 1:**
    ```
        +
       / \
      E   E
      |  / \
     id E   E
        |   |
       id  id
    ```
    **Leftmost Derivation 2 (corresponds to `(id + id) * id`):**
    1. `E -> E * E`
    2. `-> E + E * E`
    3. `-> id + E * E`
    4. `-> id + id * E`
    5. `-> id + id * id`
    **Parse Tree 2:**
    ```
          *
         / \
        E   E
       / \  |
      E + E id
      |   |
     id  id
    ```
    Since two different leftmost derivations (and two different parse trees) exist for the same string, the grammar is ambiguous.

Q11: PCCST601 0000193: Consider the following grammar, S -> S + S | S * S | a. Show the leftmost derivation of string 'a+a*a'? Show the rightmost derivation of string 'a+a*a'? Draw the parse tree? Is the grammar ambiguous or unambiguous?
A11:
    **a) Leftmost Derivation:**
    `S -> S + S`
    `-> a + S`
    `-> a + S * S`
    `-> a + a * S`
    `-> a + a * a`
    **b) Rightmost Derivation:**
    `S -> S * S`
    `-> S * a`
    `-> S + S * a`
    `-> S + a * a`
    `-> a + a * a`
    **c) Parse Trees:** The two derivations correspond to two different parse trees.
    **Tree 1 (from LMD):** `+` is the root.
    **Tree 2 (from RMD):** `*` is the root.
    **d) Ambiguity:** The grammar is **ambiguous** because the string `a+a*a` has two different parse trees, as shown by the different leftmost and rightmost derivations.

Q12: PCCST601 0000194: Write down the regular expression for the following language: Set of all strings whose lengths are divisible by 3, over $\Sigma$={a,b}. Set of all strings that begin with 'ab' over $\Sigma$={a,b}. Set of all strings that ends with 'ab' over $\Sigma$={a,b}.
A12:
    *   **Set of all strings whose lengths are divisible by 3:** `((a|b)(a|b)(a|b))*`
    *   **Set of all strings that begin with 'ab':** `ab(a|b)*`
    *   **Set of all strings that ends with 'ab':** `(a|b)*ab`

Q13: PCCST601 0000195: Consider the following grammar, S -> (S | S [S] | a. Show the leftmost derivation of string (a [a] a )?. Show the rightmost derivation of string ( a [a] a )?. Draw the parse tree?
A13: *(Note: The question is ill-formed due to likely typos in both the grammar and the target string. The answer assumes the grammar was intended to be `S -> (S) | S[S] | a` and the target string was `(a[a])`.)*
    Assuming the corrected grammar `S -> (S) | S[S] | a` and string `(a[a])`:
    **Leftmost Derivation for `(a[a])`:**
    `S -> (S)`
    `-> (S [S])`
    `-> (a [S])`
    `-> (a [a])`
    **Rightmost Derivation for `(a[a])`:**
    `S -> (S)`
    `-> (S [S])`
    `-> (S [a])`
    `-> (a [a])`
    **Parse Tree for `(a[a])`:**
    ```
          S
          |
         (S)
          |
        S [S]
        |  |
        a  a
    ```

Q14: PCCST601 0000196: Find the regular expressions of the following languages; Set of all strings over $\Sigma$ = {a, b} such that all the strings begin and end with different symbols. Set of all strings over $\Sigma$ = {a, b} such that all the strings begin and end with same symbol.
A14:
    *   **Begin and end with different symbols:** `a(a|b)*b | b(a|b)*a`
    *   **Begin and end with same symbol:** `a | b | a(a|b)*a | b(a|b)*b`

Q15: PCCST601 0000197: Remove the left recursion from the following grammar S -> S + S | S&S | !S | (S) | i&i | i<i | i4A, S -> Sa | aSSb | $\epsilon$
A15: This question lists two separate grammars.
    **Grammar 1:** `S -> S + S | S&S | !S | (S) | i&i | i<i | i4A`
    This has direct left recursion. Assuming `i4A` is a terminal-like token.
    `S -> S(+S | &S) | !S | (S) | i&i | i<i | i4A`
    The equivalent non-left-recursive grammar is:
    `S -> (!S | (S) | i&i | i<i | i4A) S'`
    `S' -> (+S | &S) S' | ε`
    **Grammar 2:** `S -> Sa | aSSb | ε`
    This has direct left recursion.
    `S -> S(a) | aSSb | ε`
    The equivalent non-left-recursive grammar is:
    `S -> (aSSb | ε) S'`
    `S' -> a S' | ε`

Q16: PCCST601 0000198: Remove the left recursion from the following grammar A -> Ab | aC, B -> BaBB | BA, C -> bC | BA
A16:
    **For production A:** `A -> Ab | aC` becomes:
    `A -> aC A'`
    `A' -> b A' | ε`
    **For production B:** `B -> BaBB | BA` becomes:
    `B -> BA B'`
    `B' -> aBB B' | ε`
    **For production C:** `C -> bC | BA` is not left recursive.
    The final grammar is:
    `A -> aC A'`, `A' -> b A' | ε`
    `B -> BA B'`, `B' -> aBB B' | ε`
    `C -> bC | BA`

Q17: PCCST601 0000199: Remove the left recursion from the following grammar S -> Aa | Bb, A -> Aa | Abc | c | Sb, B -> bb
A17: The grammar has indirect left recursion (`S -> Aa -> Sba...`).
    1.  Substitute `S` into `A`:
        `A -> Aa | Abc | c | (Aa | Bb)b`
        `A -> Aa | Abc | c | Aab | Bbb`
    2.  Group `A`'s left-recursive productions:
        `A -> A(a | bc | ab) | (c | Bbb)`
    3.  Eliminate direct left recursion for `A`:
        `A -> (c | Bbb) A'`
        `A' -> (a | bc | ab) A' | ε`
    The full, non-left-recursive grammar is:
    `S -> Aa | Bb`
    `B -> bb`
    `A -> c A' | Bbb A'`
    `A' -> a A' | bc A' | ab A' | ε`

Q18: PCCST601 0000200: Remove the left recursion from the following grammar S -> A a | b, A -> S S | 1
A18: This grammar has indirect left recursion: `S -> Aa -> SSa`.
    1.  Substitute `A` into `S`:
        `S -> (SS | 1)a | b`
        `S -> SSa | a | b`
    2.  Now `S` has direct left recursion. Eliminate it:
        `S -> (a | b) S'`
        `S' -> Sa S' | ε`
    The resulting grammar is:
    `S -> a S' | b S'`
    `S' -> Sa S' | ε`
    `A -> S S | 1`

Q19: PCCST601 0000201: Remove the left recursion from the following grammar S -> Abc, A -> Aa | Ad | b, B -> Bd | e, C -> Cc | g
A19:
    - **For A:** `A -> A(a | d) | b` becomes `A -> b A'`, `A' -> a A' | d A' | ε`
    - **For B:** `B -> B(d) | e` becomes `B -> e B'`, `B' -> d B' | ε`
    - **For C:** `C -> C(c) | g` becomes `C -> g C'`, `C' -> c C' | ε`
    The production `S -> Abc` is not left recursive. The final grammar is a combination of these new productions.

Q20: PCCST601 0000202: Construct the predictive parsing table to check if the grammar is LL(1) or not? S -> aABb, A -> c | $\epsilon$, B -> d | $\epsilon$
A20: To construct the table, we need FIRST and FOLLOW sets.
    **FIRST sets:** `FIRST(A) = {c, ε}`, `FIRST(B) = {d, ε}`, `FIRST(S) = {a}`
    **FOLLOW sets:**
    `FOLLOW(S) = { $ }`
    `FOLLOW(A) = FIRST(Bb)`. `FIRST(B)={d,ε}`, so `d` is in `FOLLOW(A)`. Since `B` can be `ε`, `FOLLOW(A)` also gets `FIRST(b)={b}`. So, `FOLLOW(A) = {d, b}`.
    `FOLLOW(B) = FIRST(b) = {b}`.
    **Predictive Parsing Table:**
    | Non-terminal | a | b | c | d | $ |
    | :--- | :--- | :--- | :--- | :--- | :--- |
    | **S** | S -> aABb | | | | |
    | **A** | | A -> ε | A -> c | A -> ε | |
    | **B** | | B -> ε | | B -> d | |
    **Is the grammar LL(1)?** Yes. There are no cells in the parsing table with multiple entries, so the grammar is LL(1).

Q21: PCCST601 0000203: Construct the predictive parsing table and parse the string "ab" by using the parsing table. S -> AaAb | BbBa, A -> $\epsilon$, B -> $\epsilon$
A21: The grammar as written is ambiguous and not LL(1). `S` can derive `ab` via `S -> AaAb -> a(ε)Ab -> aAb -> a(ε)b -> ab`. It can derive `ba` via `S -> BbBa`. 
    An LL(1) parser cannot be constructed. For example, `FIRST(AaAb) = {a}` and `FIRST(BbBa) = {b}`. This seems fine. But `A -> ε` and `B -> ε`.
    `FOLLOW(A) = FIRST(Ab) = {a}`. Also `S -> AaAb`, so `FOLLOW(A)` gets `FIRST(b)={b}`. `FOLLOW(A) = {a,b}`.
    `FOLLOW(B) = FIRST(bBa) = {b}`. Also `S -> BbBa`, so `FOLLOW(B)` gets `FIRST(a)={a}`. `FOLLOW(B) = {a,b}`.
    The table would have entries for `A -> ε` under both `a` and `b`, and for `B -> ε` under both `a` and `b`.
    The question is flawed as the grammar is not LL(1). A predictive parser cannot be deterministically constructed.

Q22: PCCST601 0000204: Prove that the following grammar is LL(1). Parse the string 'aa$' by using the parsing table. S -> SA | A, A -> a
A22: The premise of the question is false. The grammar `S -> SA | A` is **left-recursive**. A grammar that has left recursion **cannot** be LL(1). A predictive parser requires a non-left-recursive grammar.
    Even after eliminating left recursion (`S -> A S'`, `S' -> A S' | ε`), the resulting grammar (`S -> aS'`, `S' -> aS' | ε`) is still not LL(1) because of a FIRST/FOLLOW conflict in the `S'` production.

Q23: PCCST601 0000205: Construct the predictive parsing table to check if the grammar is LL(1) or not. (Grammar: E $\to$ TE', E' $\to$ +TE' | $\epsilon$, T $\to$ FT', T' $\to$ *FT' | $\epsilon$, F $\to$ (E) | id)
A23: This is the classic expression grammar, designed to be LL(1).
    **FIRST sets:** `FIRST(F) = {(, id}`, `FIRST(T') = {*, ε}`, `FIRST(T) = {(, id}`, `FIRST(E') = {+, ε}`, `FIRST(E) = {(, id}`.
    **FOLLOW sets:** `FOLLOW(E) = {$, )}`, `FOLLOW(E') = {$, )}`, `FOLLOW(T) = {+, $, )}`, `FOLLOW(T') = {+, $, )}`, `FOLLOW(F) = {* , +, $, )}`.
    **Predictive Parsing Table:**
    | Non-terminal | id | + | * | ( | ) | $ |
    | :--- | :--- | :--- | :--- | :--- | :--- | :--- |
    | **E** | E -> TE' | | | E -> TE' | | |
    | **E'** | | E' -> +TE' | | | E' -> ε | E' -> ε |
    | **T** | T -> FT' | | | T -> FT' | | |
    | **T'** | | T' -> ε | T' -> *FT' | | T' -> ε | T' -> ε |
    | **F** | F -> id | | | F -> (E) | | |
    **Is the grammar LL(1)?** Yes. No cell in the table contains more than one production, so the grammar is LL(1).

Q24: PCCST601 0000206: Construct the predictive parsing table to check if the grammar is LL(1) or not. (Grammar: S $\to$ iCtS | iCtSeS | a, C $\to$ b)
A24: The grammar has a common prefix `iCtS`. We must left-factor it:
    `S -> iCtS S' | a`
    `S' -> eS | ε`
    `C -> b`
    Now, we check if this factored grammar is LL(1).
    `FIRST(S') = {e, ε}`.
    `FOLLOW(S) = {$, e}` (The `e` comes from the original grammar's structure, creating the "dangling else" problem).
    `FOLLOW(S') = FOLLOW(S) = {$, e}`.
    There is a **FIRST/FOLLOW conflict** for the production `S' `.
    - `FIRST(eS) = {e}`. This tells us to apply `S' -> eS` on lookahead `e`.
    - `S' -> ε` is an epsilon production, so we must apply it on any lookahead in `FOLLOW(S')`. Since `e` is in `FOLLOW(S')`, this tells us to apply `S' -> ε` on lookahead `e`.
    Because we have two choices (`S' -> eS` and `S' -> ε`) on the same lookahead (`e`), the grammar is **not LL(1)**.

Q25: PCCST601 0000209: Parse the following string ' (id) * id' by shift-reduce parsing method indicating the input string, stack entry and action taken at each step. Use the following grammar and SLR parsing table: (Grammar: E $\to$ E + T | T, T $\to$ T * F | F, F $\to$ (E) | id)
A25: The parse requires an SLR parsing table, which is assumed. The steps are:
    | Stack | Input | Action |
    | :--- | :--- | :--- |
    | $ | `(id) * id$` | Shift |
    | $( | `id) * id$` | Shift |
    | $(id | `) * id$` | Reduce: F -> id |
    | $(F | `) * id$` | Reduce: T -> F |
    | $(T | `) * id$` | Reduce: E -> T |
    | $(E | `) * id$` | Shift |
    | $(E) | `* id$` | Reduce: F -> (E) |
    | $F | `* id$` | Reduce: T -> F |
    | $T | `* id$` | Shift |
    | $T* | `id$` | Shift |
    | $T*id | `$` | Reduce: F -> id |
    | $T*F | `$` | Reduce: T -> T * F |
    | $T | `$` | Reduce: E -> T |
    | $E | `$` | Accept |

Q26: PCCST601 0000210: Remove the left recursion from the following grammar. Construct the predictive parsing table of the grammar obtained after removing the left recursion. Is the grammar LL(1)? justify (Grammar: A$\to$Ac | Aad |bd |$\epsilon$)
A26:
    **1. Remove Left Recursion:**
    The grammar `A -> Ac | Aad | bd | ε` is left-recursive.
    Factored form: `A -> A(c | ad) | (bd | ε)`.
    Eliminating left recursion gives:
    `A -> (bd | ε) A'` which is `A -> bd A' | A'`
    `A' -> (c | ad) A' | ε` which is `A' -> c A' | ad A' | ε`
    **2. LL(1) Check:**
    A grammar is not LL(1) if for any production `X -> α | β`, `FIRST(α)` and `FIRST(β)` are not disjoint, or if `X -> ε`, `FIRST(X)` and `FOLLOW(X)` are not disjoint.
    Let's find the necessary sets for the transformed grammar. From the original grammar, `A` can be followed by `c` or `d`. Assuming `A` is the start symbol, `$ ` is also in its follow set. 
    `FOLLOW(A) = {c, d, $}`.
    `FOLLOW(A') = FOLLOW(A) = {c, d, $}`.
    Now consider the production `A' -> c A' | ad A' | ε`.
    `FIRST(c A') = {c}`.
    `FIRST(ad A') = {a}`.
    `FIRST(ε) = {ε}`.
    Since `A'` has an epsilon production, we must check `FIRST(A') ∩ FOLLOW(A')`.
    `FIRST(A') = {c, a, ε}`.
    `FOLLOW(A') = {c, d, $}`.
    The intersection is `{c}`, which is non-empty.
    **Justification:** The grammar is **not LL(1)**. The intersection of `FIRST(A')` and `FOLLOW(A')` is not disjoint. On lookahead `c`, the parser cannot decide whether to apply the production `A' -> c A'` (based on the FIRST set) or `A' -> ε` (based on the FOLLOW set).

Q27: PCCST601 0000211: Consider the following itemsset and Find out the itemssets obtained from the following GOTO functions: I = { E' $\to$ .E, E $\to$ .E + T | .T, T $\to$ .T * F | .F, F $\to$ .(E) | .id }, GOTO(I, E), GOTO(I, T), GOTO(I, id), GOTO(I, ( )
A27: The initial set `I` is the state `I0` of the canonical LR(0) collection.
    `I0 = { E' -> .E, E -> .E+T, E -> .T, T -> .T*F, T -> .F, F -> .(E), F -> .id }`
    - **GOTO(I0, E):** `CLOSURE({ E' -> E., E -> E.+T })` = `{ E' -> E., E -> E.+T }`
    - **GOTO(I0, T):** `CLOSURE({ E -> T., T -> T.*F })` = `{ E -> T., T -> T.*F }`
    - **GOTO(I0, id):** `CLOSURE({ F -> id. })` = `{ F -> id. }`
    - **GOTO(I0, ():** `CLOSURE({ F -> (.E) })` = `{ F -> (.E), E -> .E+T, E -> .T, T -> .T*F, T -> .F, F -> .(E), F -> .id }` which is a new state containing the initial set of items, but within the context of parentheses.

Q28: PCCST601 0000213: Find the FIRST & FOLLOW the following grammar: A $\to$ Ab | aC, B $\to$ BaBb | BA, C $\to$ bC | BA
A28: The grammar as written has non-terminating productions. `B`'s productions all start with `B`, meaning any derivation from `B` will loop infinitely without producing terminals. The language generated by `B` is empty.
    Assuming this is intentional (a trick question) or a typo:
    `FIRST(B) = {}` (empty set)
    `FIRST(C) = {b}` (since `FIRST(B)` is empty)
    `FIRST(A) = {a}` (from `A -> aC`)
    `FOLLOW(A)`: Assuming `A` is start, `$` is in `FOLLOW(A)`. `A` is followed by `A` in `B->BA`, and by `b` in `A->Ab`. This is complex due to recursion. Given the flawed nature, a definitive FOLLOW set is problematic.

Q29: PCCST601 0000214: Find the FIRST & FOLLOW the following grammar: A $\to$ Ba | Baa, B $\to$ Abb
A29: This grammar has mutual recursion (`A` depends on `B` and `B` depends on `A`) with no terminal-only exit rule. No terminal string can ever be generated. The language is empty.
    `FIRST(A) = FIRST(B)`
    `FIRST(B) = FIRST(A)`
    Therefore, `FIRST(A) = {}` and `FIRST(B) = {}`.
    `FOLLOW(A) = { $ }` (if start symbol).
    `FOLLOW(B) = {a}`.

Q30: PCCST601 0000215: Find the FIRST & FOLLOW the following grammar: S $\to$ Aa | Bb, A $\to$ Aa | Abc | c | Sb, B $\to$ bb
A30:
    **FIRST sets:**
    `FIRST(B) = {b}`
    `FIRST(A)` gets `c`. It also gets `FIRST(S)`.
    `FIRST(S)` gets `FIRST(A)` and `FIRST(B)`.
    `FIRST(S) = FIRST(A) U {b}`.
    `FIRST(A) = {c} U FIRST(S) = {c} U FIRST(A) U {b}`. So, `FIRST(A) = {c, b}`.
    `FIRST(S) = {c, b}`.
    **FOLLOW sets:**
    `FOLLOW(S) = { $, b }` (`b` from `A -> Sb`)
    `FOLLOW(B) = {b}` (from `S -> Bb`)
    `FOLLOW(A) = {a, b}` (`a` from `S->Aa`, `b` from `A->Abc`).

Q31: PCCST601 0000216: Find the FIRST & FOLLOW the following grammar: S $\to$ AA | 0, A $\to$ SS | 1
A31:
    **FIRST sets:**
    `FIRST(S) = FIRST(A) U {0}`
    `FIRST(A) = FIRST(S) U {1}`
    By substitution: `FIRST(S) = (FIRST(S) U {1}) U {0}`. So, `FIRST(S) = {0, 1}`.
    Similarly, `FIRST(A) = {0, 1}`.
    **FOLLOW sets:**
    `FOLLOW(S) = { $ } U FOLLOW(A)` (from `A -> SS`, S is followed by S, so `FOLLOW(S)` gets `FOLLOW(A)`)
    `FOLLOW(A) = FIRST(A) U FOLLOW(S)` (from `S -> AA`)
    `FOLLOW(A) = {0, 1} U FOLLOW(S)`.
    `FOLLOW(S) = { $ } U ({0, 1} U FOLLOW(S))`. So, `FOLLOW(S) = {$, 0, 1}`.
    `FOLLOW(A) = {0, 1} U {$, 0, 1} = {$, 0, 1}`.

Q32: PCCST601 0000217: Find the FIRST & FOLLOW the following grammar: S $\to$ Abc, A $\to$ Aa | Ad | b, B $\to$ Bd | e, C $\to$ Cc | g
A32:
    **FIRST sets:**
    `FIRST(A) = {b}` (after accounting for left recursion)
    `FIRST(B) = {e}`
    `FIRST(C) = {g}`
    `FIRST(S) = FIRST(A) = {b}`
    **FOLLOW sets:**
    `FOLLOW(S) = { $ }`
    `FOLLOW(A) = {b}` (from `S -> Abc`)
    `FOLLOW(B) = { $ }` (B is not reachable from S, so FOLLOW is based on it being a start symbol)
    `FOLLOW(C) = { $ }` (C is not reachable from S)

Q33: PCCST601 0000218: Find the FIRST & FOLLOW the following grammar: A $\to$ c | s&s | i<i | i4A, S $\to$ Sa | aSSb | $\epsilon$
A33: These are two separate grammars.
    **Grammar 1:** `A -> c | s&s | i<i | i4A` (Assuming `i4A` is a typo for `iA`)
    `FIRST(A) = {c, s, i}`
    `FOLLOW(A) = { $ }` (Assuming A is the start symbol)
    **Grammar 2:** `S -> Sa | aSSb | ε`
    `FIRST(S) = {a, ε}`
    `FOLLOW(S) = { $, a, b }` (`a` from `S->Sa`, `b` from `S->aSSb`)

Q34: PCCST601 0000219: Convert the following regular expression to a DFA: x(yxx | y + x)*
A34: Assuming `+` means union (`|`), the expression is `x(yxx | y | x)*`. The conversion is a standard two-step process:
    1.  **NFA Construction (Thompson's Algorithm):** An NFA is built by combining smaller NFAs for `x`, `y`, `yxx` using concatenation, union (`|`), and Kleene star (`*`) operations.
    2.  **NFA to DFA Conversion (Subset Construction):** A DFA is constructed where each DFA state corresponds to a set of NFA states. The process starts with the ε-closure of the NFA's start state and systematically computes transitions for each input symbol (`x`, `y`) to new sets of NFA states, until no new DFA states are generated. The resulting DFA would be complex to draw in text but the process is algorithmic.

Q35: PCCST601 0000222: What is the drawback of CLR parsing? How do we overcome it in LALR parsing? Write down the steps to convert a CLR parsing table to LALR parsing table.
A35:
    **Drawback of CLR Parsing:** The main drawback of Canonical LR (CLR) parsing is the large number of states it generates. This is because CLR states distinguish between items not only by their core production but also by their lookahead terminal. This leads to very large parsing tables, which can be impractical.
    **How LALR Overcomes It:** Look-Ahead LR (LALR) parsing reduces the table size by merging CLR states that have the same set of core items (i.e., the same productions and dot positions), ignoring the lookaheads. The lookaheads of the merged state become the union of the original lookaheads.
    **Steps to Convert CLR to LALR:**
    1.  Construct the complete set of CLR(1) items (the automaton).
    2.  Find all sets of items (states) that have the same core. For example, `{[C -> .cC, c/d]}` and `{[C -> .cC, $]}` have the same core `C -> .cC`.
    3.  Merge these sets into a single new state. The new state has the common core and the union of the lookaheads. In the example, the merged state would be `{[C -> .cC, c/d/$]}`.
    4.  Reconstruct the GOTO graph and the parsing table using the new, smaller set of LALR states.

Q36: PCCST601 0000223: Construct an equivalent NFA of the following regular expression: $(0+1)\(00+11)0\*(1)\*$. Convert that NFA to its equivalent DFA?
A36: The process involves two main stages:
    **1. Regular Expression to NFA (Thompson's Construction):**
    - Build NFAs for the basic components (`0`, `1`).
    - Use the union operation for `(0+1)` and `(00+11)`.
    - Use concatenation for the parts of the expression.
    - Use the Kleene star operation for `(0+1)*`, `0*`, and `1*`.
    - The final NFA will have several states and ε-transitions.
    **2. NFA to DFA (Subset Construction):**
    - The start state of the DFA is the ε-closure of the NFA's start state.
    - From each DFA state, compute the transitions for inputs `0` and `1`. The destination is the ε-closure of the set of NFA states reached.
    - Repeat this process for all new DFA states until no new states are created.
    - Mark any DFA state that contains an accepting state of the NFA as an accepting state. This process is algorithmic but too lengthy to draw out fully in text.

Q37: PCCST601 0000257: a) Optimize the following C code: count=0; while(count++ < 20) { increment= 2*count; result = increment; }. b) Explain about: Dead code elimination.
A37:
    **a) Code Optimization:**
    Original code:
    ```c
    count=0;
    while(count++ < 20) {
        increment = 2 * count;
        result = increment;
    }
    ```
    The loop runs 20 times. Inside the loop, `count` takes values from 1 to 20. The variable `result` is overwritten in each iteration. Only the value from the final iteration is visible after the loop.
    - **Dead Store Elimination:** The assignments to `result` in the first 19 iterations are "dead" and can be removed.
    - **Constant Folding:** The final value of `result` can be determined at compile time. In the last iteration, `count` is 20, so `result` becomes `2 * 20 = 40`. The loop itself can be removed.
    **Optimized Code:**
    ```c
    count = 21; // Final value after the loop
    result = 40;
    ```
    **b) Dead Code Elimination:** This is an optimization that removes code that does not affect the program's output. This includes unreachable code (e.g., code in an `if (false)` block) and dead stores, where a variable is assigned a value that is never subsequently used.

Q38: PCCST601 0000258: a) What is the purpose of code optimization? Explain in detail about Peephole Optimization with examples. b) Define: Loop optimization.
A38:
    **a) Purpose of Code Optimization and Peephole Optimization:**
    The **purpose of code optimization** is to transform code to improve its performance (making it run faster) and/or reduce its resource consumption (like memory or disk space). 
    **Peephole Optimization** is a local optimization technique that examines a small, sliding window of instructions (the "peephole") and replaces them with a shorter or faster sequence.
    **Examples:**
    - **Strength Reduction:** Replacing `x = x * 2` with `x = x << 1` (a cheaper bit-shift).
    - **Redundant Load/Store Elimination:** Removing `MOV R0, x` followed by `MOV x, R0` if `x` hasn't changed.
    **b) Loop Optimization:** A class of optimization techniques focused on making loops more efficient, since programs spend most of their time in loops. Key techniques include moving loop-invariant code out of the loop, eliminating redundant induction variables, and loop unrolling to reduce overhead.

Q39: PCCST601 0000259: Explain the machine-dependent and independent techniques.
A39: Code optimization techniques are classified into two types:
    **1. Machine-Independent Optimization:** This phase improves the intermediate code without knowledge of the target machine's architecture. It focuses on logical improvements to the program.
    **Examples:** Common Subexpression Elimination, Constant Folding, Dead Code Elimination, Loop-invariant Code Motion.
    **2. Machine-Dependent Optimization:** This phase uses specific features of the target machine's instruction set and architecture to improve the generated code.
    **Examples:** Register Allocation (using CPU registers efficiently), Instruction Scheduling (reordering instructions to avoid CPU pipeline stalls), and using specific machine idioms or addressing modes.

Q40: PCCST601 0000260: a) What is an activation record? Explain how it is related with run time storage organization. b) Give the applications of DAG.
A40:
    **a) Activation Record and Runtime Storage:**
    An **activation record** (or stack frame) is a block of memory on the runtime stack that stores information for a single function call. It is the core of runtime storage organization for procedural languages. When a function is called, a new record is pushed onto the stack; when it returns, the record is popped.
    It typically contains: the return value, parameters, pointers to the caller's context (control link), and storage for local variables.
    **b) Applications of DAG:**
    A Directed Acyclic Graph (DAG) is used in compilers for optimization, primarily within basic blocks.
    1.  **Identifying Common Subexpressions:** A DAG naturally represents shared computations. If a subexpression appears multiple times, it becomes a single node with multiple parents, making it easy to compute once and reuse.
    2.  **Optimizing Basic Blocks:** It helps generate efficient three-address code by reordering instructions and eliminating redundant steps.

Q41: PCCST601 0000261: a. Discuss the various issues in code generation with examples. b. Write short notes on basic blocks and flow graphs.
A41:
    **a) Issues in Code Generation:**
    1.  **Instruction Selection:** Choosing the best machine instructions to implement intermediate code. For `a = a + 1`, a generic `ADD` or a more efficient `INC` instruction might be available.
    2.  **Register Allocation:** Deciding which variables to keep in the limited number of fast CPU registers to minimize slow memory access.
    3.  **Evaluation Order:** The order of computation can affect efficiency and the number of registers required.
    **b) Basic Blocks and Flow Graphs:**
    - **Basic Block:** A sequence of consecutive instructions where control flow enters at the beginning and leaves at the end without branching, except possibly at the end.
    - **Flow Graph:** A directed graph where nodes are basic blocks and edges represent the flow of control between them. Flow graphs are essential for performing global optimizations and data-flow analysis.

Q42: PCCST601 0000262: a) Define triples, indirect triples and quadruples. b) Write three codes for $x=f(a[i, z])$ with detail explanation.
A42:
    **a) Triples, Indirect Triples, and Quadruples:**
    These are three-address intermediate representations.
    1.  **Quadruples:** Have four fields: `(op, arg1, arg2, result)`. Example: `(+, y, z, t1)`. They are easy to optimize but can be verbose.
    2.  **Triples:** Have three fields: `(op, arg1, arg2)`. Results are referred to by their position. Example: `(0): (+, y, z)`. `(1): (-, x, (0))`. Moving code is difficult as it requires updating all references.
    3.  **Indirect Triples:** A list of pointers to triples. Code motion is achieved by reordering the pointers, not the triples themselves, solving the issue with standard triples.
    **b) Three-Address Code for `x = f(a[i, z])`:**
    Assuming `a` is a 2D array where each element has size `w` and each row has `num_cols` columns.
    ```
    t1 = i * num_cols     // Calculate row offset
    t2 = t1 + z           // Add column offset
    t3 = t2 * w           // Calculate byte offset from base address
    t4 = a_base + t3      // Get the final address of a[i, z]
    t5 = *t4              // Get the value at that address (load from memory)
    param t5              // Pass the value as a parameter to function f
    t6 = call f, 1        // Call function f with 1 parameter
    x = t6                // Assign return value to x
    ```

Q43: PCCST601 0000263: a) Write a note on the specification of a simple type checker. b) List the various ways of calling the procedures. Explain in detail.
A43:
    **a) Specification of a Simple Type Checker:**
    A type checker verifies that the types in a program are used according to the language's rules. It works by assigning a type expression to each component of the program. It uses rules to synthesize types (e.g., `int + int = int`) and check for consistency (e.g., in `if (E) S`, `E` must be boolean). If a rule is violated, a type error is reported.
    **b) Ways of Calling Procedures (Parameter Passing):**
    1.  **Call by Value:** A copy of the argument's value is passed to the function. Changes inside the function do not affect the original argument.
    2.  **Call by Reference:** The address of the argument is passed. The function can modify the original argument through this address.
    3.  **Call by Value-Result:** The argument's value is copied in at the start, and its final value is copied back out when the function returns.
    4.  **Call by Name:** The argument expression is textually substituted for the parameter and re-evaluated every time it is used inside the function.

Q44: PCCST601 0000264: a) How would you convert the following into intermediate code. (i) Assignments statements. (ii) Array elements. b) Describe the method of generating syntax directed definition for control Statements.
A44:
    **a) Conversion to Intermediate Code:**
    **(i) Assignments statements:** A statement like `x = y + z * 60;` is broken into a sequence of three-address instructions: `t1 = 60; t2 = z * t1; t3 = y + t2; x = t3;`.
    **(ii) Array elements:** Accessing `y = a[i]` requires calculating the memory address: `t1 = i * element_width; t2 = base_address(a) + t1; y = *t2;`.
    **b) Syntax Directed Definition for Control Statements:**
    An SDD associates semantic rules with grammar productions to generate intermediate code, often managing labels for jumps.
    **Example for `while (E) S1`:**
    The grammar is `Stmt -> while ( Expr ) Stmt1`. The SDD generates code in the pattern: `begin_label: code for Expr, if_false goto after_label, code for Stmt1, goto begin_label, after_label: `.
    The rules would be:
    `Stmt.begin = newlabel()`
    `Stmt.after = newlabel()`
    `Stmt.code = label(Stmt.begin) || E.code || if_false(E.addr, Stmt.after) || S1.code || goto(Stmt.begin) || label(Stmt.after)`