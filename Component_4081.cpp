//
// Component_4081.cpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Thu Mar  2 14:26:32 2017 Callewaert
// Last update Fri Mar  3 09:51:59 2017 Callewaert
//

#include "and_link.hpp"
#include "OnePinComp.hpp"
#include "Component_4081.hpp"

Component_4081::Component_4081(std::string const& name)
  : name(name)
{
  this->links = {
    std::make_pair(3, new and_link()),
    std::make_pair(6, new and_link()),
    std::make_pair(10, new and_link()),
    std::make_pair(11, new and_link())
  };
  this->type = lex::CHIPSET;
}

Component_4081::~Component_4081()
{
}

nts::Tristate		Component_4081::Compute(size_t pin_num_this)
{
  lex::chipset_type	getType;

  if (this->connexion.find(pin_num_this) != this->connexion.end())
    {
      getType = this->connexion[pin_num_this]->getType();
      // A Faire pour tous les autres types de chipset, (pointeur sur fonction ?)
      // On retournerai le getState() de leur output
      if (getType == lex::INPUT
	  || getType == lex::OUTPUT
	  || getType == lex::CLOCK
	  || getType == lex::TRUE
	  || getType == lex::FALSE)
	{
	  onePinComp *opc = dynamic_cast<onePinComp*>(this->connexion[pin_num_this]);
	  return (opc->getState());
	}
    }
  return (nts::Tristate::UNDEFINED);
}

void			Component_4081::SetLink(size_t pin_num_this,
						nts::IComponent &component,
						size_t pin_num_target)
{
  if (this->connexion.find(pin_num_this) != this->connexion.end())
    {
      this->connexion[pin_num_this] = &component;
      if (component.getType() == lex::CHIPSET
	  && component.getConnexion().find(pin_num_target) != component.getConnexion().end())
	component.getConnexion()[pin_num_target] = this;
    }
}

void		Component_4081::Dump(void) const
{
}

lex::chipset_type	Component_4081::getType() const
{
  return (this->type);
}

std::map<size_t, nts::IComponent*>	Component_4081::getConnexion() const
{
  return (this->connexion);
}
