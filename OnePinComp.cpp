//
// OnePinComp.cpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 16:17:30 2017 Callewaert
// Last update Wed Mar  1 16:48:17 2017 Callewaert
//

#include <iostream>
#include "OnePinComp.hpp"

onePinComp::onePinComp(std::string const& name,
		       nts::Tristate const& state,
		       lex::chipset_type const& type,
		       size_t const& pin)
  : name(name), state(state), type(type), pin(pin)
{
}

onePinComp::~onePinComp()
{
}

std::string		onePinComp::getName() const
{
  return (this->name);
}

nts::Tristate		onePinComp::getState() const
{
  return (this->state);
}

lex::chipset_type	onePinComp::getType() const
{
  return (this->type);
}

size_t			onePinComp::getPin() const
{
  return (this->pin);
}

void			onePinComp::setState(nts::Tristate const& new_state)
{
  if (this->type != lex::TRUE
      && this->type != lex::FALSE
      && this->type != lex::CLOCK)
    this->state = new_state;
  else if (this->type == lex::CLOCK && this->state == nts::TRUE)
    this->state = nts::FALSE;
  else if (this->type == lex::CLOCK && this->state == nts::FALSE)
    this->state = nts::TRUE;
}

nts::Tristate		onePinComp::Compute(size_t pin_num_this = 1)
{
  (void)pin_num_this;
  return (this->getState());
}
void			onePinComp::SetLink(size_t pin_num_this,
					    nts::IComponent &component,
					    size_t pin_num_target)
{
  (void)pin_num_this;
  (void)component;
  (void)pin_num_target;
}

void			onePinComp::Dump(void) const
{
  std::cout << "Component " << this->name << " of type " << this->type << std::endl;
  std::cout << "State : " << this->state << std::endl;
}
