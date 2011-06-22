#include <iostream>
#include <stdlib.h>
#include <vector>

namespace simple_calculator {
  // types of tokens
  enum TokenType {
    SC_NUMBER,
    SC_PLUS,
    SC_MINUS,
    SC_TIMES,
    SC_DIVIDE,
    SC_NEW_LINE
  };

  /* TOKEN CLASS */
  class Token {
  public:
    int type;
    double value;
    
    Token(void);
    Token(TokenType token_type);
    Token(TokenType token_type, char str_value[]);
  };
  
  Token::Token(void) {};

  Token::Token(TokenType token_type) {
    type = token_type;
  };

  Token::Token(TokenType token_type, char str_value[]){
    type = token_type;
    value = atof(str_value);
  };

  /* CALC QUEUE CLASS */
  class Queue: public std::vector<Token> {
  public:
    double total;
    Queue append(Token token);
    double calculate(void);
  };
  
  Queue Queue::append(Token token) {
    push_back(token);
    return *this;
  };
  
  double Queue::calculate(void) {
    // initial conditions for total
    int i = 0;
    Token token = at(i);
    if( token.type == SC_NUMBER ){
      total = token.value;
      i++;
    } else {
      total = 0;
    }
    
    for(i; i < size(); i++){
      Token token = at(i);
      Token next_token = at(i+1);
      
      switch( token.type ){
        case SC_PLUS:
          total += next_token.value;
          i++;
          break;
        case SC_MINUS:
          total -= next_token.value;
          i++;
          break;
        case SC_TIMES:
          total *= next_token.value;
          i++;
          break;
        case SC_DIVIDE: 
          total /= next_token.value;
          i++;
          break;
        default:
          std::cout << "unexpected output of type=";
          std::cout << token.type;
          std::cout << " and value=";
          std::cout << token.value;
          break;
      }
    };
    clear();
    return total;
  };
};

/* Tests to see that the library works! 
  using namespace simple_calculator;

  int main(void) {
    Token token;
    Queue token_queue;
    token = Token (SC_NUMBER, "3.14");
    token_queue.append(token);
    token = Token (SC_TIMES);
    token_queue.append(token);
    token = Token(SC_NUMBER, "2");
    token_queue.append(token);
    token = Token (SC_TIMES);
    token_queue.append(token);
    token = Token(SC_NUMBER, "17");
    token_queue.append(token);
    std::cout << "Total of 3.14 * 2 * 17 is ";
    std::cout << token_queue.calculate();
    std::cout << "\n";
  }
*/

