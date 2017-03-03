//
// and_link.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:16:07 2017 Callewaert
// Last update Thu Mar  2 14:06:51 2017 Callewaert
//

#ifndef AND_LINK_HPP_
# define AND_LINK_HPP_

# include "cpp_nanotekspice_parser.hpp"
# include "OnePinComp.hpp"
# include "ILink.hpp"

class			and_link : public ILink
{
private:
  onePinComp		*one;
  onePinComp		*two;
public:
  and_link();
  and_link(onePinComp *one, onePinComp *two);
  virtual		~and_link();
  nts::Tristate		and_op(nts::Tristate, nts::Tristate);
  virtual onePinComp	*getPin(size_t) const;
  void			setOne(onePinComp&);
  void			setTwo(onePinComp&);
};

#endif // AND_LINK_HPP_
