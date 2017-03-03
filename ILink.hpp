//
// ILink.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Mar  1 17:06:39 2017 Callewaert
// Last update Wed Mar  1 18:14:35 2017 Callewaert
//

#ifndef ILINK_HPP_
# define ILINK_HPP_

# include "cpp_nanotekspice_parser.hpp"

class			ILink
{
public:
  ILink(){};
  virtual onePinComp	*getPin(size_t) const = 0;
  virtual		~ILink(){};
};

#endif // ILINK_HPP_
