//
// lexer.hpp for  in /home/julien/rendu/tek2/CPP/cpp_nanotekspice
//
// Made by Callewaert
// Login   <callew_j@epitech.net>
//
// Started on  Wed Feb  8 16:08:30 2017 Callewaert
// Last update Tue Feb 14 11:12:38 2017 Pereira Ugo
//

#ifndef LEXER_HPP_
# define LEXER_HPP_

# include <string>
# include <vector>
# include "cpp_nanotekspice_parser.hpp"

# define ERR_FILE_EXIST "File doesn't exist."
# define ERR_FILE_EXT "Wrong file extension."

# define M_FALSE "false"
# define M_TRUE "true"
# define M_INPUT "input"
# define M_CLOCK "clock"
# define M_OUTPUT "output"
# define M_CHIPSET ".chipsets:"
# define M_LINK ".links:"

namespace lex
{
  enum chipset_type
    {
      FALSE,
      TRUE,
      INPUT,
      CLOCK,
      OUTPUT,
      CHIPSET_SEC,
      LINK_SEC,
      CHIPSET,
      LINK,
      ERROR
    };
  typedef struct		s_lexer
  {
    std::string			lexeme;
    nts::ASTNodeType		type;
    chipset_type		c_type;
  }				t_lexer;

  class lexer
  {
  private:
    std::vector<t_lexer>	token;
    std::vector<std::string>	chipset_list;
    int				chipset_link;

  public:
    lexer() : chipset_link(0){};
    ~lexer(){};
    void			setlexer(char const *);
    bool			set_line_data(lex::t_lexer&, std::string);
    void			set_end_link();
    std::vector<t_lexer>	getToken() const;
    void			setChipsetList();
    bool			chipset_is_known(std::string);
    void			link(lex::t_lexer& lexer, std::string line_file, std::vector<lex::t_lexer> &token);
    lex::chipset_type		get_c_type(std::string lexeme, std::vector<lex::t_lexer> &token);
  };
};

bool				fill_false_func(lex::t_lexer& lexer, std::string line_file);
bool				fill_true_func(lex::t_lexer& lexer, std::string line_file);
bool				fill_input_func(lex::t_lexer& lexer, std::string line_file);
bool				fill_clock_func(lex::t_lexer& lexer, std::string line_file);
bool				fill_output_func(lex::t_lexer& lexer, std::string line_file);
bool				fill_link_func(lex::t_lexer& lexer, std::string line_file);
bool				fill_chipset_sec_func(lex::t_lexer& lexer, std::string line_file);
bool				only_space_tab(std::string line_file);
bool				verif_link_end(lex::t_lexer& lexer, std::vector<lex::t_lexer> &token);

#endif // LEXER_HPP_
