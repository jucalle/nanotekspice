//
// nor_link.cpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:41:48 2017 Callewaert
// Last update Fri Mar  3 12:55:03 2017 Callewaert
//

#include "nor_link.hpp"

nor_link::nor_link()
{
}

nor_link::~nor_link()
{
}

nts::Tristate	nor_link::nor_op(nts::Tristate a, nts::Tristate b)
{
  bool          tmp1;
  bool          tmp2;
  nts::Tristate result;

  if (a != nts::Tristate::UNDEFINED && b != nts::Tristate::UNDEFINED)
    {
      tmp1 = static_cast<bool>(a);
      tmp2 = static_cast<bool>(b);
      result = static_cast<nts::Tristate>(!(tmp1 || tmp2));
      return (result);
    }
  return (nts::Tristate::UNDEFINED);
}

std::vector<onePinComp*>	nor_link::getPin() const
{
  return (this->links);
}

void				nor_link::add_link(onePinComp *new_link)
{
  this->links.push_back(new_link);
}
