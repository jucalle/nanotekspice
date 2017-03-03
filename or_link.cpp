//
// or_link.cpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:36:45 2017 Callewaert
// Last update Thu Mar  2 13:14:38 2017 Callewaert
//

#include "or_link.hpp"

or_link::or_link(onePinComp *one, onePinComp *two)
  : one(one), two(two)
{
}

or_link::~or_link()
{
}

nts::Tristate	or_link::or_op(nts::Tristate a, nts::Tristate b)
{
  bool          tmp1;
  bool          tmp2;
  nts::Tristate result;

  if (a != nts::Tristate::UNDEFINED && b != nts::Tristate::UNDEFINED)
    {
      tmp1 = static_cast<bool>(a);
      tmp2 = static_cast<bool>(b);
      result = static_cast<nts::Tristate>(tmp1 || tmp2);
      return (result);
    }
  return (nts::Tristate::UNDEFINED);
}

onePinComp	*or_link::getPin(size_t pin) const
{
  if (pin == this->one->getPin())
    return (this->one);
  else if (pin == this->two->getPin())
    return (this->two);
  return (NULL);
}
