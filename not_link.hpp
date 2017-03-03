//
// not_link.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:43:59 2017 Callewaert
// Last update Wed Mar  1 18:09:09 2017 Callewaert
//

#ifndef NOT_LINK_HPP_
# define NOT_LINK_HPP_

# include "cpp_nanotekspice_parser.hpp"
# include "OnePinComp.hpp"
# include "ILink.hpp"

class			not_link : public ILink
{
private:
  onePinComp		*one;
public:
  not_link(onePinComp *one);
  virtual ~not_link();
  nts::Tristate		not_op(nts::Tristate);
  virtual onePinComp	*getPin(size_t) const;
};

#endif // NOT_LINK_HPP_
