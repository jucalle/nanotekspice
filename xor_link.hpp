//
// xor_link.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:37:47 2017 Callewaert
// Last update Fri Mar  3 12:56:09 2017 Callewaert
//

#ifndef XOR_LINK_HPP_
# define XOR_LINK_HPP_

# include "cpp_nanotekspice_parser.hpp"
# include "OnePinComp.hpp"
# include "ILink.hpp"

class				xor_link : public ILink
{
private:
  std::vector<onePinComp*>	links;
public:
  xor_link();
  virtual			~xor_link();
  nts::Tristate			xor_op(nts::Tristate, nts::Tristate);
  virtual std::vector<onePinComp*> getPin() const;
  virtual void			add_link(onePinComp*);
};

#endif // XOR_LINK_HPP_
