//
// lexer_func_ptr.cpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Fri Feb 10 17:27:50 2017 Callewaert
// Last update Fri Feb 10 17:31:57 2017 Callewaert
//

#include <sstream>
#include "cpp_nanotekspice_parser.hpp"
#include "lexer.hpp"

bool			fill_false_func(lex::t_lexer& lexer, std::string line_file)
{
  std::stringstream	tmp(line_file.c_str());
  std::string		cut;

  if (line_file.find(M_FALSE) != std::string::npos)
    {
      tmp >> cut;
      tmp >> cut;
      lexer.lexeme = cut;
      lexer.type = nts::ASTNodeType::COMPONENT;
      lexer.c_type = lex::FALSE;
      return (true);
    }
  return (false);
}

bool			fill_true_func(lex::t_lexer& lexer, std::string line_file)
{
  std::stringstream	tmp(line_file.c_str());
  std::string		cut;

  if (line_file.find(M_TRUE) != std::string::npos)
  {
    tmp >> cut;
    tmp >> cut;
    lexer.lexeme = cut;
    lexer.type = nts::ASTNodeType::COMPONENT;
    lexer.c_type = lex::TRUE;
    return (true);
  }
  return (false);
}

bool			fill_input_func(lex::t_lexer& lexer, std::string line_file)
{
  std::stringstream	tmp(line_file.c_str());
  std::string		cut;

  if (line_file.find(M_INPUT) != std::string::npos)
    {
      tmp >> cut;
      tmp >> cut;
      lexer.lexeme = cut;
      lexer.type = nts::ASTNodeType::COMPONENT;
      lexer.c_type = lex::INPUT;
      return (true);
    }
  return (false);
}

bool			fill_clock_func(lex::t_lexer& lexer, std::string line_file)
{
  std::stringstream	tmp(line_file.c_str());
  std::string		cut;

  if (line_file.find(M_CLOCK) != std::string::npos)
    {
      tmp >> cut;
      tmp >> cut;
      lexer.lexeme = cut;
      lexer.type = nts::ASTNodeType::COMPONENT;
      lexer.c_type = lex::CLOCK;
      return (true);
    }
  return (false);
}

bool			fill_output_func(lex::t_lexer& lexer, std::string line_file)
{
  std::stringstream	tmp(line_file.c_str());
  std::string		cut;

  if (line_file.find(M_OUTPUT) != std::string::npos)
    {
      tmp >> cut;
      tmp >> cut;
      lexer.lexeme = cut;
      lexer.type = nts::ASTNodeType::COMPONENT;
      lexer.c_type = lex::OUTPUT;
      return (true);
    }
  return (false);
}

bool	fill_link_func(lex::t_lexer& lexer, std::string line_file)
{
  if (line_file.find(M_LINK) != std::string::npos)
    {
      lexer.lexeme = line_file;
      lexer.type = nts::ASTNodeType::SECTION;
      lexer.c_type = lex::LINK_SEC;
      return (true);
    }
  return (false);
}

bool	fill_chipset_sec_func(lex::t_lexer& lexer, std::string line_file)
{
  if (line_file.find(M_CHIPSET) != std::string::npos)
    {
      lexer.lexeme = line_file;
      lexer.type = nts::ASTNodeType::SECTION;
      lexer.c_type = lex::CHIPSET_SEC;
      return (true);
    }
  return (false);
}
