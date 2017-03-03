//
// OnePinComp.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 16:26:38 2017 Callewaert
// Last update Fri Mar  3 09:06:00 2017 Callewaert
//

#ifndef ONEPINCOMP_HPP_
# define ONEPINCOMP_HPP_

# include "lexer.hpp"
# include "IComponent.hpp"
# include "cpp_nanotekspice_parser.hpp"

class					onePinComp : public nts::IComponent
{
private:
  std::string				name;
  nts::Tristate				state;
  lex::chipset_type			type;
  size_t				pin;
public:
  onePinComp(std::string const& name,
	     nts::Tristate const& state,
	     lex::chipset_type const& type,
	     size_t const& pin);
  virtual				~onePinComp();
  virtual nts::Tristate			Compute(size_t pin_num_this);
  virtual void				SetLink(size_t pin_num_this,
						nts::IComponent &component,
						size_t pin_num_target);
  virtual void				Dump(void) const;
  std::string				getName() const;
  nts::Tristate				getState() const;
  virtual lex::chipset_type		getType() const;
  size_t				getPin() const;
  void					setState(nts::Tristate const& new_state);
};

#endif // ONEPINCOMP_HPP_
