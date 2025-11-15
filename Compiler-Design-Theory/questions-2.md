### 📜 List of 10-Mark Questions (Set 2)

* **PCCST601 0000205:** Construct the predictive parsing table to check if the grammar is LL(1) or not.
    (Grammar: E $\to$ TE', E' $\to$ +TE' | $\epsilon$, T $\to$ FT', T' $\to$ *FT' | $\epsilon$, F $\to$ (E) | id)
    * **CO/BL:** CO5|BL3.0

* **PCCST601 0000206:** Construct the predictive parsing table to check if the grammar is LL(1) or not.
    (Grammar: S $\to$ iCtS | iCtSeS | a, C $\to$ b)
    * **CO/BL:** CO5|BL3.0

* **PCCST601 0000207:** Consider the following grammar and complete the closure sets in the following SLR automaton.
    (Grammar: E' $\to$ E, E $\to$ E + T | T, T $\to$ T * F | F, F $\to$ (E) | id)
    * **CO/BL:** CO5|BL3.0

* **PCCST601 0000208:** Consider the following LR(0) automaton and parse the following string: **id \* id + id**. Show Stack, grammar symbols corresponding to the states, input and action entries.
    * **CO/BL:** CO5|BL3.0

* **PCCST601 0000209:** Parse the following string ' **(id) \* id**' by shift-reduce parsing method indicating the input string, stack entry and action taken at each step. Use the following grammar and SLR parsing table:
    (Grammar: E $\to$ E + T | T, T $\to$ T * F | F, F $\to$ (E) | id)
    * **CO/BL:** CO5|BL3.0

* **PCCST601 0000210:** Remove the left recursion from the following grammar. Construct the predictive parsing table of the grammar obtained after removing the left recursion. Is the grammar LL(1)? justify
    (Grammar: A$\to$Ac | Aad |bd |$\epsilon$)
    * **CO/BL:** CO5|BL3.0

* **PCCST601 0000211:** Consider the following itemsset and Find out the itemssets obtained from the following GOTO functions:
    I = { E' $\to$ .E, E $\to$ .E + T | .T, T $\to$ .T * F | .F, F $\to$ .(E) | .id }
    GOTO(I, E), GOTO(I, T), GOTO(I, id), GOTO(I, ( )
    * **CO/BL:** CO5|BL3.0

* **PCCST601 0000212:** Consider the following augmented grammar and SLR automaton. Construct the SLR parsing table.
    (Grammar: E' $\to$ E, E $\to$ E + T | T, T $\to$ T * F | F, F $\to$ (E) | id)
    * **CO/BL:** CO6|BL4.0

* **PCCST601 0000213:** Find the FIRST & FOLLOW the following grammar:
    A $\to$ Ab | aC
    B $\to$ BaBb | BA
    C $\to$ bC | BA
    * **CO/BL:** CO6|BL4.0

* **PCCST601 0000214:** Find the FIRST & FOLLOW the following grammar:
    A $\to$ Ba | Baa
    B $\to$ Abb
    * **CO/BL:** CO6|BL4.0

* **PCCST601 0000215:** Find the FIRST & FOLLOW the following grammar:
    S $\to$ Aa | Bb
    A $\to$ Aa | Abc | c | Sb
    B $\to$ bb
    * **CO/BL:** CO5|BL5.0

* **PCCST601 0000216:** Find the FIRST & FOLLOW the following grammar:
    S $\to$ AA | 0
    A $\to$ SS | 1
    * **CO/BL:** CO5|BL5.0

* **PCCST601 0000217:** Find the FIRST & FOLLOW the following grammar:
    S $\to$ Abc
    A $\to$ Aa | Ad | b
    B $\to$ Bd | e
    C $\to$ Cc | g
    * **CO/BL:** CO6|BL5.0

* **PCCST601 0000218:** Find the FIRST & FOLLOW the following grammar:
    A $\to$ c | s&s | i<i | i4A
    S $\to$ Sa | aSSb | $\epsilon$
    * **CO/BL:** CO2|BL2.0

* **PCCST601 0000219:** Convert the following regular expression to a DFA:
    x(yxx | y + x)\*
    * **CO/BL:** CO2|BL2.0

* **PCCST601 0000220:** Construct the LALR(1) parsing table from the following CLR parsing table. Justify the reason behind merging every pair of states.
    * **CO/BL:** CO2|BL5.0

* **PCCST601 0000221:** Convert the following NFA to an equivalent DFA: (NFA transition table is provided)
    * **CO/BL:** CO2|BL6.0

* **PCCST601 0000222:** What is the drawback of CLR parsing? How do we overcome it in LALR parsing? Write down the steps to convert a CLR parsing table to LALR parsing table.
    * **CO/BL:** CO2|BL6.0

