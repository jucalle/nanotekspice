//
// xor_link.cpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:38:31 2017 Callewaert
// Last update Fri Mar  3 12:57:25 2017 Callewaert
//

#include "xor_link.hpp"

xor_link::xor_link()
{
}

xor_link::~xor_link()
{
}

nts::Tristate	xor_link::xor_op(nts::Tristate a, nts::Tristate b)
{
  bool		tmp1;
  bool		tmp2;
  nts::Tristate	result;

  if (a != nts::Tristate::UNDEFINED && b != nts::Tristate::UNDEFINED)
    {
      tmp1 = static_cast<bool>(a);
      tmp2 = static_cast<bool>(b);
      result = static_cast<nts::Tristate>(tmp1 ^ tmp2);
      return (result);
    }
  return (nts::Tristate::UNDEFINED);
}

std::vector<onePinComp*>	xor_link::getPin() const
{
  return (this->links);
}

void				xor_link::add_link(onePinComp *new_link)
{
  this->links.push_back(new_link);
}
