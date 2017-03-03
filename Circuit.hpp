//
// Circuit.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Thu Mar  2 14:18:05 2017 Callewaert
// Last update Thu Mar  2 14:26:14 2017 Callewaert
//

#ifndef CIRCUIT_HPP_
# define CIRCUIT_HPP_

# include <vector>
# include "IComponent.hpp"
# include "cpp_nanotekspice_parser.hpp"

class				Circuit
{
private:
  nts::t_ast_node		*Tree;
  std::vector<nts::IComponent*>	components;
public:
  Circuit(nts::t_ast_node *Tree);
  virtual			~Circuit();
  void				parseTree();
};

#endif // CIRCUIT_HPP_
