//
// not_link.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:43:59 2017 Callewaert
// Last update Fri Mar  3 13:00:09 2017 Callewaert
//

#ifndef NOT_LINK_HPP_
# define NOT_LINK_HPP_

# include "cpp_nanotekspice_parser.hpp"
# include "OnePinComp.hpp"
# include "ILink.hpp"

class				not_link : public ILink
{
private:
  std::vector<onePinComp*>	links;
public:
  not_link();
  virtual			~not_link();
  nts::Tristate			not_op(nts::Tristate);
  virtual std::vector<onePinComp*> getPin() const;
  virtual void			add_link(onePinComp*);
};

#endif // NOT_LINK_HPP_
