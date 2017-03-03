//
// nand_link.cpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:43:14 2017 Callewaert
// Last update Fri Mar  3 12:51:38 2017 Callewaert
//

#include "nand_link.hpp"

nand_link::nand_link()
{
}

nand_link::~nand_link()
{
}

nts::Tristate	nand_link::nand_op(nts::Tristate a, nts::Tristate b)
{
  bool          tmp1;
  bool          tmp2;
  nts::Tristate result;

  if (a != nts::Tristate::UNDEFINED && b != nts::Tristate::UNDEFINED)
    {
      tmp1 = static_cast<bool>(a);
      tmp2 = static_cast<bool>(b);
      result = static_cast<nts::Tristate>(!(tmp1 && tmp2));
      return (result);
    }
  return (nts::Tristate::UNDEFINED);
}

std::vector<onePinComp*>	nand_link::getPin() const
{
  return (this->links);
}

void				nand_link::add_link(onePinComp *new_link)
{
  this->links.push_back(new_link);
}
