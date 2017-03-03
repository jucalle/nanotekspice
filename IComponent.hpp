//
// IComponent.hpp for nano in /home/pereir_u/Documents/kickage
//
// Made by Pereira Ugo
// Login   <ugo.pereira@epitech.eu>
//
// Started on  Tue Feb  7 10:29:03 2017 Pereira Ugo
// Last update Fri Mar  3 09:29:11 2017 Callewaert
//

#ifndef __ICOMPONENT_HPP__
# define __ICOMPONENT_HPP__

# include <map>
# include <cstdio>
# include "lexer.hpp"

namespace nts
{
  enum Tristate
    {
      UNDEFINED = (-true),
      TRUE = true,
      FALSE = false
    };
  class IComponent
  {
  public:
    virtual nts::Tristate Compute(size_t pin_num_this) = 0;
    virtual void SetLink(size_t pin_num_this,
			 nts::IComponent &component,
			 size_t pin_num_target) = 0;
    virtual void Dump(void) const = 0;
    virtual lex::chipset_type	getType() const = 0;
    virtual std::map<size_t, IComponent*> getConnexion() const = 0;
    virtual ~IComponent(void) { }
  };
}

#endif // __ICOMPONENT_HPP__
