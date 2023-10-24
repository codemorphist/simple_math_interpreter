#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool is_number(std::string v) {
  if(v != "+" and v != "-" and v != "*" and v != "/" and v != "_")
    return 1;
  else
   return 0;
}

float calc(float a, float b, char op) {
  switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default: return 0;
  }
}

float last_res;
float eval_rpb(std::string expr) {
  std::vector<float> stack(0); 
  
  std::istringstream e(expr);

  std::string v;
  while(std::getline(e, v, ' ')) {
    if (is_number(v)) stack.push_back(std::stof(v));
    else {
      if (v == "_") {
        stack.push_back(last_res);
        continue;
      } 

      int l = stack.size();
      float b = stack[l-2];
      float a = stack.back();
      stack.pop_back();

      stack[l-2] = calc(a, b, v[0]);

      std::cout << "\033[1;34m[STEP]:\033[0m\t" << 
        a << " " << v << " " << b << " = " << stack[l-2] << std::endl;
    }
  }

  last_res = stack[0];
  return stack[0];
}

int main() {
  std::string expr;

  
  do {
    std::cout << "\033[1;35m>> \033[0m";
    std::getline(std::cin, expr);

    if (expr == "exit") break;

    std::cout << "\n\033[1;33m.......R.......P.......N.......\033[0m\n";
    float res = eval_rpb(expr);
    std::cout << "\n\033[1;32m[RESULT]:\033[0m " << res; 
    std::cout << "\n\033[1;33m...............................\033[0m\n\n";
  } while(expr != "exit");

  return 0;
}
