//
// Parser.cpp for nano in /home/pereir_u/TEK2/cpp_nanotekspice
//
// Made by Pereira Ugo
// Login   <ugo.pereira@epitech.eu>
//
// Started on  Sat Feb 11 15:56:37 2017 Pereira Ugo
// Last update Wed Mar  1 16:01:03 2017 Callewaert
//

#include <iostream>
#include <map>
#include <string>
#include "parser.hpp"

std::vector<struct nts::s_ast_node*>		*pars::Parser::createEndLine()
{
  std::vector<struct nts::s_ast_node*>	*child = new std::vector<struct nts::s_ast_node*>;
  nts::t_ast_node *tmp = new nts::t_ast_node(NULL);

  tmp->lexeme = "";
  tmp->type = nts::ASTNodeType::NEWLINE;
  tmp->value = "";
  child->push_back(tmp);
  return (child);
}

std::vector<struct nts::s_ast_node*>            *pars::Parser::createChipsetComponent()
{
  std::vector<struct nts::s_ast_node*>		*child = new std::vector<struct nts::s_ast_node*>;
  std::map<lex::chipset_type, std::string>	chip_type;

  chip_type.insert(std::make_pair(lex::FALSE, std::string("false")));
  chip_type.insert(std::make_pair(lex::TRUE, std::string("true")));
  chip_type.insert(std::make_pair(lex::INPUT, std::string("input")));
  chip_type.insert(std::make_pair(lex::CLOCK, std::string("clock")));
  chip_type.insert(std::make_pair(lex::OUTPUT, std::string("output")));
  for (auto it = this->token.begin(); it != token.end() && it->c_type != lex::LINK_SEC; ++it)
    {
      if (it->c_type != lex::CHIPSET_SEC)
	{
	  nts::t_ast_node *tmp = new nts::t_ast_node(this->createEndLine());
	  tmp->lexeme = it->lexeme;
	  tmp->type = it->type;
	  tmp->value = chip_type[it->c_type];
	  child->push_back(tmp);
	}
    }
  return (child);
}

nts::s_ast_node            *pars::Parser::createChipset()
{
  nts::t_ast_node *tmp = new nts::t_ast_node(this->createChipsetComponent());

  for (auto it = this->token.begin(); it != this->token.end(); ++it)
    {
      if (it->c_type == lex::CHIPSET_SEC)
	{
	  tmp->lexeme = it->lexeme;
	  tmp->type = it->type;
	  tmp->value = "";
	}
    }
  return (tmp);
}

std::vector<struct nts::s_ast_node*>            *pars::Parser::createLinkComponent(auto it)
{
  nts::t_ast_node *tmp_link1 = new nts::t_ast_node(this->createEndLine());
  nts::t_ast_node *tmp_link2 = new nts::t_ast_node(this->createEndLine());
  std::vector<struct nts::s_ast_node*>	*child = new std::vector<struct nts::s_ast_node*>;

  ++it;
  tmp_link1->lexeme = it->lexeme;
  tmp_link1->type = it->type;
  tmp_link1->value = "";
  ++it;
  tmp_link2->lexeme = it->lexeme;
  tmp_link2->type = it->type;
  tmp_link2->value = "";
  child->push_back(tmp_link1);
  child->push_back(tmp_link2);
  return (child);
}

std::vector<struct nts::s_ast_node*>            *pars::Parser::createLink()
{
  std::vector<struct nts::s_ast_node*>	*child = new std::vector<struct nts::s_ast_node*>;

  for (auto it = this->token.begin(); it != this->token.end(); ++it)
    {
      if (it->type == nts::ASTNodeType::LINK)
	{
	  nts::t_ast_node *tmp = new nts::t_ast_node(this->createLinkComponent(it));
	  tmp->lexeme = it->lexeme;
	  tmp->type = it->type;
	  tmp->value = "";
	  child->push_back(tmp);
	}
      else if (it->type == nts::ASTNodeType::LINK_END)
	{
	  nts::t_ast_node *tmp = new nts::t_ast_node(this->createLinkComponent(it));
	  tmp->lexeme = it->lexeme;
	  tmp->type = it->type;
	  tmp->value = "";
	  child->push_back(tmp);
	}
    }
  return (child);
}

nts::s_ast_node            *pars::Parser::createLinkSection()
{
  nts::t_ast_node *tmp = new nts::t_ast_node(this->createLink());

  for (auto it = this->token.begin(); it != this->token.end(); ++it)
    {
      if (it->c_type == lex::LINK_SEC)
	{
	  tmp->lexeme = it->lexeme;
	  tmp->type = it->type;
	  tmp->value = "";
	}
    }
  return (tmp);
}

std::vector<struct nts::s_ast_node*>            *pars::Parser::createSection()
{
  std::vector<struct nts::s_ast_node*>	*child = new std::vector<struct nts::s_ast_node*>;

  child->push_back(this->createChipset());
  child->push_back(this->createLinkSection());
  return (child);
}

pars::Parser::Parser(lex::lexer  &lexer)
  : lexer(lexer), token(lexer.getToken())
{
}

void		pars::Parser::feed(std::string const& input)
{
  (void)input;
}

void		pars::Parser::parseTree(nts::t_ast_node& root)
{
  std::vector<nts::s_ast_node*> tmp_ptr = *root.children;

  for (auto it = tmp_ptr.begin(); it != tmp_ptr.end(); ++it)
    {
      auto tmp = *it;
      if (tmp->type != nts::ASTNodeType::NEWLINE)
	{
	  std::cout << "lexeme = " << tmp->lexeme << std::endl;
	  std::cout << "type = " << static_cast<int>(tmp->type) << std::endl;
	  std::cout << "value = " << tmp->value << std::endl;
	  std::cout << std::endl;
	  this->parseTree(*tmp);
	}
    }
}



nts::t_ast_node	*pars::Parser::createTree()
{
  nts::t_ast_node *tree = new nts::t_ast_node(this->createSection());

  tree->lexeme = "";
  tree->type = nts::ASTNodeType::DEFAULT;
  tree->value = "";
  return (tree);
}
