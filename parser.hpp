//
// parser.hpp for nano in /home/pereir_u/TEK2/cpp_nanotekspice
//
// Made by Pereira Ugo
// Login   <ugo.pereira@epitech.eu>
//
// Started on  Sat Feb 11 15:40:54 2017 Pereira Ugo
// Last update Tue Feb 28 14:03:24 2017 Callewaert
//

#ifndef PARSER_HPP_
# define PARSER_HPP_

# include "lexer.hpp"

namespace pars
{
  class Parser : public nts::IParser
  {
  public:
    nts::s_ast_node            *createChipset();
    nts::s_ast_node            *createLinkSection();
    std::vector<struct nts::s_ast_node*>            *createChipsetComponent();
    std::vector<struct nts::s_ast_node*>            *createEndLine();
    std::vector<struct nts::s_ast_node*>            *createLinkComponent(auto);
    std::vector<struct nts::s_ast_node*>            *createLink();
    std::vector<struct nts::s_ast_node*>            *createSection();
    virtual void feed(std::string const& input);
    virtual void parseTree(nts::t_ast_node& root);
    virtual nts::t_ast_node *createTree();

    virtual ~Parser(){};
    Parser(lex::lexer  &lexer);

  private:
    lex::lexer			lexer;
    std::vector<lex::t_lexer>	token;
  };
}

#endif /* !PARSER_HPP_ */
