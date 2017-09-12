#ifndef POSITIONRECONSTRUCTION_SRC_INPUT_PARSERS_CONFIGPARSER_H
#define POSITIONRECONSTRUCTION_SRC_INPUT_PARSERS_CONFIGPARSER_H

// includes for C system headers
// includes for C++ system headers
#include<iostream>
// includes from other libraries
#include<boost/spirit/include/qi.hpp>
#include<boost/spirit/include/phoenix_operator.hpp>
#include<boost/spirit/include/phoenix_object.hpp>
#include<boost/phoenix/bind/bind_member_function.hpp>
// includes from this code
#include"Input/Data/ConfigData.h"
#include"UtilityParsers.h"

namespace Input
{
namespace Parsers
{

namespace qi = boost::spirit::qi;

// the main gammar
template <typename Iterator>
struct ConfigParser : qi::grammar<Iterator>
{
public:
    ConfigParser(Data::ConfigData* cd) : ConfigParser::base_type(startRule), ptr(cd)
    {
        namespace phoenix = boost::phoenix;
        using qi::skip;
        using qi::blank;
        using qi::lexeme;
        using qi::int_;
        using qi::float_;
        using qi::fail;
        using qi::on_error;
        using Utility::eol_;
        using Utility::separator;
        //define the rules to parse the parameters
        detSif = (lexeme["DetSpecInputFile"]    >> '=' > quotedString [phoenix::bind(&Data::ConfigData::setDetSpecInputFile,    ptr, qi::_1)] > separator);
        detPif = (lexeme["DetPosInputFile"]     >> '=' > quotedString [phoenix::bind(&Data::ConfigData::setDetPosInputFile,     ptr, qi::_1)] > separator);
        panPif = (lexeme["PanelPosInputFile"]   >> '=' > quotedString [phoenix::bind(&Data::ConfigData::setPanelPosInputFile,   ptr, qi::_1)] > separator);
        panSof = (lexeme["PanelSpecOutputFile"] >> '=' > quotedString [phoenix::bind(&Data::ConfigData::setPanelSpecOutputFile, ptr, qi::_1)] > separator);
        srcDof = (lexeme["SrcDataOutputFile"]   >> '=' > quotedString [phoenix::bind(&Data::ConfigData::setSrcDataOutputFile,   ptr, qi::_1)] > separator);
        numCor = (lexeme["NumCores"]            >> '=' > int_         [phoenix::bind(&Data::ConfigData::setSetNumCores,         ptr, qi::_1)] > separator);
        minEn  = (lexeme["MinimumEnergy"]       >> '=' > float_       [phoenix::bind(&Data::ConfigData::setMinEnergy,           ptr, qi::_1)] > separator);
        maxEn  = (lexeme["MaximumEnergy"]       >> '=' > float_       [phoenix::bind(&Data::ConfigData::setMaxEnergy,           ptr, qi::_1)] > separator);
        // define the start rule which holds the whole monstrosity and set the rule to skip blanks
        // if we skipped spaces we could not parse newlines as separators
        startRule = skip(blank) [configDataRule];
        configDataRule = *eol_ > lexeme["[StartConfig]"] > *eol_
            > (
                detSif ^ detPif ^ panPif ^ panSof ^
                srcDof ^ numCor ^ minEn ^ maxEn
            ) > lexeme["[EndConfig]"];
        
        on_error<fail>(startRule,
                       std::cout << phoenix::val("Error! Expecting ")
                       << qi::_4                             // what failed?
                       << phoenix::val(" here: \n")
                       << phoenix::construct<std::string>(qi::_3, qi::_2) // iterators to error-pos, end
                       << std::endl);
    }
private:
    //base rules for the file
    qi::rule<Iterator>                 startRule;
    qi::rule<Iterator, qi::blank_type> configDataRule;
    
    // special sub grammars
    Utility::QuotedString<Iterator> quotedString;
    
    // parameters
    qi::rule<Iterator, qi::blank_type> detSif, detPif, panPif;
    qi::rule<Iterator, qi::blank_type> panSof, srcDof, numCor;
    qi::rule<Iterator, qi::blank_type> minEn, maxEn;
    
    // hold the pointer that we are going to bind to
    Data::ConfigData* ptr;
};

}
}
#endif //POSITIONRECONSTRUCTION_SRC_INPUT_PARSERS_CONFIGPARSER_H
