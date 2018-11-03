# Brainf*ck interpreter

This is a Brainf*ck interpreter written in C++. It's fairly simple. It uses a memory bank of 30,000
chars, a code pointer, a memory pointer. It also uses two stacks to keep track of state. The first stack
is the call stack. Whenever the interpreter encounters a '[' character, it pushes the current
position on the call stack, and when the corresponding loop close ']' character is encountered, it either
loops back to the top element on the stack, or pops it and continues. The second stack, execution stack,
is just a boolean stack that determines whether the current code char could be executed.