//
// nand_link.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:42:16 2017 Callewaert
// Last update Fri Mar  3 12:49:05 2017 Callewaert
//

#ifndef NAND_LINK_HPP_
# define NAND_LINK_HPP_

# include "cpp_nanotekspice_parser.hpp"
# include "OnePinComp.hpp"
# include "ILink.hpp"

class				nand_link : public ILink
{
private:
  std::vector<onePinComp*>	links;
public:
  nand_link();
  virtual			~nand_link();
  nts::Tristate			nand_op(nts::Tristate, nts::Tristate);
  virtual std::vector<onePinComp*> getPin() const;
  virtual void			add_link(onePinComp*);

};

#endif // NAND_LINK_HPP_
