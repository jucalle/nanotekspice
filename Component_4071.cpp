//
// Component_4071.cpp for  in /home/julien/rendu/tek2/CPP/nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Fri Mar  3 14:31:44 2017 Callewaert
// Last update Fri Mar  3 14:52:48 2017 Callewaert
//

#include "OnePinComp.hpp"
#include "Component_4071.hpp"

Component_4071::Component_4071(std::string const& name)
  : name(name)
{
  this->links = {
    std::make_pair(3, new or_link()),
    std::make_pair(4, new or_link()),
    std::make_pair(10, new or_link()),
    std::make_pair(11, new or_link())
  };
  this->type = lex::CHIPSET;
}

Component_4071::~Component_4071()
{
}

nts::Tristate		Component_4071::Compute(size_t pin_num_this)
{
  lex::chipset_type	getType;

  if (this->connexion.find(pin_num_this) != this->connexion.end())
    {
      getType = this->connexion[pin_num_this]->getType();
      if (getType == lex::INPUT
	  || getType == lex::OUTPUT
	  || getType == lex::CLOCK
	  || getType == lex::TRUE
	  || getType == lex::FALSE)
	{
	  onePinComp *opc = dynamic_cast<onePinComp*>(this->connexion[pin_num_this]);
	  return (opc->getState());
	}
      else if (getType == lex::CHIPSET
	       && this->links.find(pin_num_this) != this->links.end())
	{
	  std::vector<onePinComp*> opc = this->links[pin_num_this]->getPin();
	  or_link *tmp = dynamic_cast<or_link*>(this->links[pin_num_this]);
	  return (tmp->or_op(opc[1]->getState(), opc[2]->getState()));
	}
    }
  return (nts::Tristate::UNDEFINED);
}

void			Component_4071::SetLink(size_t pin_num_this,
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

void		Component_4071::Dump(void) const
{
}

lex::chipset_type	Component_4071::getType() const
{
  return (this->type);
}

std::map<size_t, nts::IComponent*>	Component_4071::getConnexion() const
{
  return (this->connexion);
}
