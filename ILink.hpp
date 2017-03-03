//
// ILink.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:06:39 2017 Callewaert
// Last update Fri Mar  3 13:37:22 2017 Callewaert
//

#ifndef ILINK_HPP_
# define ILINK_HPP_

# include <vector>
# include "OnePinComp.hpp"
# include "cpp_nanotekspice_parser.hpp"

class			ILink
{
public:
  ILink(){};
  virtual void		add_link(onePinComp*) = 0;
  virtual std::vector<onePinComp*> getPin() const = 0;
  virtual		~ILink(){};
};

#endif // ILINK_HPP_
