//
// and_link.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:16:07 2017 Callewaert
// Last update Fri Mar  3 12:49:06 2017 Callewaert
//

#ifndef AND_LINK_HPP_
# define AND_LINK_HPP_

# include "cpp_nanotekspice_parser.hpp"
# include "OnePinComp.hpp"
# include "ILink.hpp"

class				and_link : public ILink
{
private:
  std::vector<onePinComp*>	links;
public:
  and_link();
  virtual			~and_link();
  nts::Tristate			and_op(nts::Tristate, nts::Tristate);
  virtual std::vector<onePinComp*> getPin() const;
  virtual void			add_link(onePinComp*);
};

#endif // AND_LINK_HPP_
