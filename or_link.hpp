//
// or_link.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:35:50 2017 Callewaert
// Last update Fri Mar  3 12:54:11 2017 Callewaert
//

#ifndef OR_LINK_HPP_
# define OR_LINK_HPP_

# include "cpp_nanotekspice_parser.hpp"
# include "OnePinComp.hpp"
# include "ILink.hpp"

class				or_link : public ILink
{
private:
  std::vector<onePinComp*>	links;
public:
  or_link();
  virtual			~or_link();
  nts::Tristate			or_op(nts::Tristate, nts::Tristate);
  virtual std::vector<onePinComp*> getPin() const;
  virtual void			add_link(onePinComp*);
};

#endif // OR_LINK_HPP_
