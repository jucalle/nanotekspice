//
// nand_link.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:42:16 2017 Callewaert
// Last update Wed Mar  1 17:50:54 2017 Callewaert
//

#ifndef NAND_LINK_HPP_
# define NAND_LINK_HPP_

# include "cpp_nanotekspice_parser.hpp"
# include "OnePinComp.hpp"
# include "ILink.hpp"

class			nand_link : public ILink
{
private:
  onePinComp		*one;
  onePinComp		*two;
public:
  nand_link(onePinComp *one, onePinComp *two);
  virtual ~nand_link();
  nts::Tristate		nand_op(nts::Tristate, nts::Tristate);
  virtual onePinComp	*getPin(size_t) const;
};

#endif // NAND_LINK_HPP_
