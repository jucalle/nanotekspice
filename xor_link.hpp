//
// xor_link.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:37:47 2017 Callewaert
// Last update Wed Mar  1 17:51:59 2017 Callewaert
//

#ifndef XOR_LINK_HPP_
# define XOR_LINK_HPP_

# include "cpp_nanotekspice_parser.hpp"
# include "OnePinComp.hpp"
# include "ILink.hpp"

class			xor_link : public ILink
{
private:
  onePinComp		*one;
  onePinComp		*two;
public:
  xor_link(onePinComp *one, onePinComp *two);
  virtual ~xor_link();
  nts::Tristate		xor_op(nts::Tristate, nts::Tristate);
  virtual onePinComp	*getPin(size_t) const;
};

#endif // XOR_LINK_HPP_
