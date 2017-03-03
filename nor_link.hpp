//
// nor_link.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:40:44 2017 Callewaert
// Last update Fri Mar  3 12:54:11 2017 Callewaert
//

#ifndef NOR_LINK_HPP_
# define NOR_LINK_HPP_

# include "cpp_nanotekspice_parser.hpp"
# include "OnePinComp.hpp"
# include "ILink.hpp"

class				nor_link : public ILink
{
private:
  std::vector<onePinComp*>	links;
public:
  nor_link();
  virtual			~nor_link();
  nts::Tristate			nor_op(nts::Tristate, nts::Tristate);
  virtual std::vector<onePinComp*> getPin() const;
  virtual void			add_link(onePinComp*);
};

#endif // NOR_LINK_HPP_
