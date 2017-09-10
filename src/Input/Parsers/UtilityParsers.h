#ifndef POSITIONDECOMPOSER_SRC_INPUTLIB_UTILITYPARSERS_H
#define POSITIONDECOMPOSER_SRC_INPUTLIB_UTILITYPARSERS_H

// includes for C system headers
// includes for C++ system headers
// includes from other libraries
#include <boost/spirit/include/qi.hpp>
// includes from ORCHIDReader

namespace Utility
{

//symbol table for reading in boolean values
struct BoolSymbols_ : boost::spirit::qi::symbols<char, bool>
{
    BoolSymbols_(){
        this->add("True" , true )
                 ("true" , true )
                 ("T"    , true )
                 ("t"    , true )
                 ("False", false)
                 ("false", false)
                 ("F"    , false)
                 ("f"    , false);
     }
};

static const BoolSymbols_ boolSymbols_;

// define my 'line enders' here, use auto cause it is going to return a strange templated type
// this version is for use within blocks, it allows key value pairs to be separated with
// commas, newlines, or comments followed by newlines
static const auto separator = boost::spirit::qi::copy(',' | +(boost::spirit::qi::eol | ('#' >> *(boost::spirit::qi::char_ - boost::spirit::qi::eol) >> boost::spirit::qi::eol)));
	//allows trailing comments newlines comment lines in any order and quantity
// this line ender version is a more strict newline in that it requires a newline character
static const auto eol_ = boost::spirit::qi::copy( +(('#' >> *(boost::spirit::qi::char_ - boost::spirit::qi::eol) >> boost::spirit::qi::eol) | boost::spirit::qi::eol));

//grammar for parsing and returning quoted strings
template <typename Iterator>
struct QuotedString : public boost::spirit::qi::grammar<Iterator, std::string()>
{
    QuotedString() : QuotedString::base_type(quotedStringRule)
    {
        quotedStringRule = '"' > +~boost::spirit::qi::char_("\"\n") > '"';
    }
private:
    boost::spirit::qi::rule<Iterator, std::string()> quotedStringRule;
};

//grammar for parsing and returning normal strings
template <typename Iterator>
struct String_ : public boost::spirit::qi::grammar<Iterator, std::string()>
{
    String_() : String_::base_type(stringRule)
    {
        stringRule = +(~boost::spirit::qi::char_("\"\n\r "));
    }
private:
    boost::spirit::qi::rule<Iterator, std::string()> stringRule;
};

//grammar for parsing strings that contain spaces and go up to the end of the line
template <typename Iterator>
struct StrWithSpaces : public boost::spirit::qi::grammar<Iterator, std::string()>
{
    StrWithSpaces() : StrWithSpaces::base_type(stringRule)
    {
        stringRule = +(~boost::spirit::qi::char_("\n\r"));
    }
private:
    boost::spirit::qi::rule<Iterator, std::string()> stringRule;
};

//grammar for handling strings that represent IP addresses
template <typename Iterator>
struct IPAddressString : public boost::spirit::qi::grammar<Iterator, std::string()>
{
    IPAddressString() : IPAddressString::base_type(addrRule)
    {
        addrRule = +boost::spirit::qi::char_("0123456789.");
    }
private:
    boost::spirit::qi::rule<Iterator, std::string()> addrRule;
};

}

#endif  // POSITIONDECOMPOSER_SRC_INPUTLIB_UTILITYPARSERS_H
