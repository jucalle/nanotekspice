//
// Component_4001.hpp for  in /home/julien/rendu/tek2/CPP/nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Fri Mar  3 13:21:29 2017 Callewaert
// Last update Fri Mar  3 13:22:27 2017 Callewaert
//

#ifndef COMPONENT_4001_HPP_
# define COMPONENT_4001_HPP_

# include <vector>
# include <map>
# include <string>
# include "IComponent.hpp"
# include "ILink.hpp"
# include "nor_link.hpp"

class				Component_4001 : public nts::IComponent
{
private:
  lex::chipset_type		type;
  std::string			name;
  std::map<size_t, ILink*>	links;
  std::map<size_t, IComponent*>	connexion;
public:
  Component_4001(std::string const& name);
  virtual			~Component_4001();
  virtual nts::Tristate		Compute(size_t pin_num_this);
  virtual void			SetLink(size_t pin_num_this,
					nts::IComponent &component,
					size_t pin_num_target);
  virtual void			Dump(void) const;
  virtual lex::chipset_type	getType() const;
  virtual std::map<size_t, IComponent*> getConnexion() const;
};

#endif // COMPONENT_4001_HPP_
