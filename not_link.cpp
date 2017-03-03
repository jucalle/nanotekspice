//
// not_link.cpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:45:17 2017 Callewaert
// Last update Wed Mar  1 18:08:04 2017 Callewaert
//

#include "not_link.hpp"

not_link::not_link(onePinComp *one)
  : one(one)
{
}

not_link::~not_link()
{
}

nts::Tristate	not_link::not_op(nts::Tristate a)
{
  if (a == nts::TRUE)
    return (nts::FALSE);
  else if (a == nts::FALSE)
    return (nts::TRUE);
  return (nts::UNDEFINED);
}

onePinComp	*not_link::getPin(size_t pin) const
{
  if (pin == this->one->getPin())
    return (this->one);
  return (NULL);
}
