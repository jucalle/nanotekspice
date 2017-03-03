//
// not_link.cpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:45:17 2017 Callewaert
// Last update Fri Mar  3 12:59:25 2017 Callewaert
//

#include "not_link.hpp"

not_link::not_link()
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


std::vector<onePinComp*>	not_link::getPin() const
{
  return (this->links);
}

void				not_link::add_link(onePinComp *new_link)
{
  this->links.push_back(new_link);
}
