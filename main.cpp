//
// main.cpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Feb  8 15:25:54 2017 Callewaert
// Last update Thu Mar  2 15:09:20 2017 Callewaert
//

#include <iostream>
#include <vector>
#include <sstream>
#include "cpp_nanotekspice_parser.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "IComponent.hpp"
#include "Circuit.hpp"

int				main(int ac, char **av)
{
  lex::lexer			l;
  std::vector<lex::t_lexer>	token;

  if (ac != 1)
    l.setlexer(av[1]);
  token = l.getToken();
  for (auto i = token.begin(); i != token.end(); ++i)
    {
      std::cout << "lexeme = " << i->lexeme << std::endl;
      std::cout << "type = " << static_cast<int>(i->type) << std::endl;
      std::cout << "chipset_type = " << static_cast<int>(i->c_type) << std::endl;
      std::cout << "**************************" << std::endl << std::endl;
    }
  pars::Parser			p(l);
  nts::t_ast_node		*it = p.createTree();
  Circuit			c(it);
  (void)c;
  return (0);
}
