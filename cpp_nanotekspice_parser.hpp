//
// cpp_nanotekspice_parser.hpp for nano in /home/pereir_u/Documents/kickage
//
// Made by Pereira Ugo
// Login   <ugo.pereira@epitech.eu>
//
// Started on  Tue Feb  7 10:29:30 2017 Pereira Ugo
// Last update Mon Feb 13 17:11:59 2017 Pereira Ugo
//

#ifndef CPP_NANOTEKSPICE_PARSER_HPP
# define CPP_NANOTEKSPICE_PARSER_HPP

# include <string>
# include <vector>

 namespace nts
{

  enum class ASTNodeType : int
  {
    DEFAULT = -1,
      NEWLINE = 0,
      SECTION,
      COMPONENT,
      LINK,
      LINK_END,
      STRING
      };

  typedef struct s_ast_node
  {
    s_ast_node(std::vector<struct s_ast_node*> *children)
      : children(children) { }
    std::string    lexeme;
    ASTNodeType    type;
    std::string    value;
    std::vector<struct s_ast_node*> *children;
  } t_ast_node;

  class IParser
  {
  public:
    virtual void feed(std::string const& input) = 0;
    virtual void parseTree(t_ast_node& root) = 0;
    virtual t_ast_node *createTree() = 0;
    virtual ~IParser(){};
  };
}

#endif //CPP_NANOTEKSPICE_PARSER_HPP
