//
// lexer.cpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Fri Feb 10 17:22:23 2017 Callewaert
// Last update Tue Feb 14 11:12:23 2017 Pereira Ugo
//

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <functional>
#include "cpp_nanotekspice_parser.hpp"
#include "lexer.hpp"

std::vector<lex::t_lexer> lex::lexer::getToken() const
{
  return (this->token);
}


bool	lex::lexer::set_line_data(lex::t_lexer& line_data, std::string line_file)
{
  std::vector<std::function<bool(lex::t_lexer&, std::string)>>	fill_struct
    {
      &fill_false_func,
	&fill_true_func,
	&fill_input_func,
	&fill_clock_func,
	&fill_output_func,
	&fill_link_func,
	&fill_chipset_sec_func
	};

  if (line_file.empty() || only_space_tab(line_file))
    return (false);
  if (this->chipset_link == 1)
    return (true);
  for (auto i = fill_struct.begin(); i != fill_struct.end() && this->chipset_link == 0; ++i)
    {
      auto tmp = *i;
      if (tmp(line_data, line_file))
	{
	  if (line_data.c_type == LINK_SEC)
	    this->chipset_link = 1;
	  return (true);
	}
    }
  return (false);
}

lex::chipset_type	lex::lexer::get_c_type(std::string lexeme, std::vector<lex::t_lexer> &token)
{
  std::string		save;

  for (auto i = token.begin(); i != token.end(); ++i)
    {
      if (i->c_type != lex::CHIPSET)
	{
	  if (lexeme.substr(0, lexeme.find(':')) == i->lexeme)
	    return (i->c_type);
	}
      else if (i->c_type == lex::CHIPSET)
	{
	  std::stringstream	tmp(i->lexeme.c_str());
	  tmp >> save;
	  tmp >> save;
	  if (lexeme.substr(0, lexeme.find(':')) == save)
	    return (i->c_type);
	}
    }
  return (lex::ERROR);
}

void				lex::lexer::link(lex::t_lexer& lexer, std::string line_file, std::vector<lex::t_lexer> &token)
{
  std::stringstream		tmp(line_file.c_str());
  lex::t_lexer			link1;
  lex::t_lexer			link2;

  lexer.lexeme = line_file;
  if(verif_link_end(lexer, token) == true)
    lexer.type = nts::ASTNodeType::LINK_END;
  else
    lexer.type = nts::ASTNodeType::LINK;
  lexer.c_type = lex::LINK;
  token.push_back(lexer);
  link1.type = nts::ASTNodeType::COMPONENT;
  tmp >> link1.lexeme;
  link1.c_type = this->get_c_type(link1.lexeme, token);
  link2.type = nts::ASTNodeType::COMPONENT;
  tmp >> link2.lexeme;
  link2.c_type = this->get_c_type(link2.lexeme, token);
  token.push_back(link1);
  token.push_back(link2);
}

void				lex::lexer::setChipsetList()
{
  this->chipset_list.push_back("2716");
  this->chipset_list.push_back("4001");
  this->chipset_list.push_back("4008");
  this->chipset_list.push_back("4011");
  this->chipset_list.push_back("4013");
  this->chipset_list.push_back("4017");
  this->chipset_list.push_back("4030");
  this->chipset_list.push_back("4040");
  this->chipset_list.push_back("4069");
  this->chipset_list.push_back("4071");
  this->chipset_list.push_back("4081");
  this->chipset_list.push_back("4094");
  this->chipset_list.push_back("4503");
  this->chipset_list.push_back("4512");
  this->chipset_list.push_back("4514");
  this->chipset_list.push_back("i4004");
  this->chipset_list.push_back("mk4801");
}

bool				lex::lexer::chipset_is_known(std::string line_file)
{
  std::stringstream		tmp(line_file.c_str());
  std::string			get_first_w;

  tmp >> get_first_w;
  for (auto i = this->chipset_list.begin(); i != this->chipset_list.end(); ++i)
    {
      if (get_first_w == *i)
	return (true);
    }
  return (false);
}

void				lex::lexer::setlexer(char const *file_name)
{
  std::string			convert_file_name(file_name);
  std::string			line_file;
  std::ifstream			file;
  lex::t_lexer			line_data;

  file.open(file_name);
  if (!file.is_open())
    std::cerr << ERR_FILE_EXIST << std::endl;
  else
    {
      this->setChipsetList();
      if (convert_file_name.substr(convert_file_name.find_last_of(".") + 1) != "nts")
	{
	  std::cerr << ERR_FILE_EXT << std::endl;
	  return ;
	}
      while (!file.eof())
	{
	  getline(file, line_file);
	  if (this->chipset_is_known(line_file))
	    {
	      line_data.lexeme = line_file;
	      line_data.type = nts::ASTNodeType::COMPONENT;
	      line_data.c_type = lex::CHIPSET;
	      this->token.push_back(line_data);
	    }
	  else if (this->set_line_data(line_data, line_file))
	    {
	      if (this->chipset_link == 1 && line_file != std::string(M_LINK))
		this->link(line_data, line_file, this->token);
	      else
		this->token.push_back(line_data);
	    }
	}
      file.close();
    }
}
