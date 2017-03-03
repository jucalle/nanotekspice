//
// or_link.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:35:50 2017 Callewaert
// Last update Wed Mar  1 17:51:21 2017 Callewaert
//

#ifndef OR_LINK_HPP_
# define OR_LINK_HPP_

# include "cpp_nanotekspice_parser.hpp"
# include "OnePinComp.hpp"
# include "ILink.hpp"

class			or_link : public ILink
{
private:
  onePinComp		*one;
  onePinComp		*two;
public:
  or_link(onePinComp *one, onePinComp *two);
  virtual ~or_link();
  nts::Tristate		or_op(nts::Tristate, nts::Tristate);
  virtual onePinComp	*getPin(size_t) const;
};

#endif // OR_LINK_HPP_
