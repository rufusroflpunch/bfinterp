#include <iostream>
#include <stack>
#include <array>
#include <string>

using namespace std;

int main() {
  string src = R"(++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.)";
  array<unsigned char, 30000> mem;
  mem.fill(0);
  auto mp = mem.begin(); // Memory pointer
  auto cp = src.cbegin(); // Code pointer
  auto eof = src.cend(); // End of code pointer
  stack<decltype(cp)> call_stack; // Stack to keep track of loops
  stack<bool> exec_stack; // Stack to track whether to execute the current code char

  exec_stack.push(true);

  while (cp != eof) {
    auto c = *cp;
    switch(c) {
      case '>': if (exec_stack.top()) mp++; break;
      case '<': if (exec_stack.top()) mp--; break;
      case '+': if (exec_stack.top()) (*mp)++; break;
      case '-': if (exec_stack.top()) (*mp)--; break;
      case '.': if (exec_stack.top()) cout << (*mp); break;
      case ',': if (exec_stack.top()) cin >> (*mp); break;
      case '[':
        if (!exec_stack.top()) break;
        call_stack.push(cp);
        if (*mp) exec_stack.push(true);
        else exec_stack.push(false);
        break;
      case ']':
        if (*mp) {
          cp = call_stack.top();
          break;
        }
        exec_stack.pop();
        call_stack.pop();
        break;
    }
    cp++;
  }
}