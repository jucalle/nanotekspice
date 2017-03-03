//
// lexer_error.cpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Fri Feb 10 17:44:54 2017 Callewaert
// Last update Fri Feb 10 17:46:08 2017 Callewaert
//

#include <sstream>
#include <vector>
#include "lexer.hpp"

bool			only_space_tab(std::string line_file)
{
  for (auto it = line_file.begin(); it != line_file.end(); ++it)
    {
      if (std::isalpha(*it))
	return (false);
    }
  return (true);
}

bool				verif_link_end(lex::t_lexer& lexer, std::vector<lex::t_lexer> &token)
{
  std::stringstream		tmp(lexer.lexeme.c_str());
  std::string			save1;
  std::string			save2;

  tmp >> save1;
  tmp >> save2;
  for (auto i = token.begin(); i != token.end(); ++i)
    {
      if (save1.substr(0, save1.find(':')) == i->lexeme && i->c_type == lex::OUTPUT)
	return (true);
      if (save2.substr(0, save2.find(':')) == i->lexeme && i->c_type == lex::OUTPUT)
	return (true);
    }
  return (false);
}
