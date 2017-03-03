//
// nor_link.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:40:44 2017 Callewaert
// Last update Wed Mar  1 17:51:34 2017 Callewaert
//

#ifndef NOR_LINK_HPP_
# define NOR_LINK_HPP_

# include "cpp_nanotekspice_parser.hpp"
# include "OnePinComp.hpp"
# include "ILink.hpp"

class			nor_link : public ILink
{
private:
  onePinComp		*one;
  onePinComp		*two;
public:
  nor_link(onePinComp *one, onePinComp *two);
  virtual ~nor_link();
  nts::Tristate		nor_op(nts::Tristate, nts::Tristate);
  virtual onePinComp	*getPin(size_t) const;
};

#endif // NOR_LINK_HPP_
