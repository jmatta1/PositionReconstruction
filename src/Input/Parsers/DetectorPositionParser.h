#ifndef POSITIONRECONSTRUCTION_SRC_INPUT_PARSERS_DETECTORPOSITIONPARSER_H
#define POSITIONRECONSTRUCTION_SRC_INPUT_PARSERS_DETECTORPOSITIONPARSER_H

// includes for C system headers
// includes for C++ system headers
// includes from other libraries
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_object.hpp>
#include <boost/phoenix/bind/bind_member_function.hpp>
// includes from ORCHIDReader
#include"Input/Data/DetectorPositionData.h"
#include"UtilityParsers.h"

namespace Input
{

namespace Parsers
{

template <typename Iterator>
struct DetectorPositionParser : qi::grammar<Iterator>
{
public:
    DetectorPositionParser(Data::DetectorPositionData* cd) : DetectorPositionParser::base_type(startRule), ptr(cd)
    {
        using qi::skip;
        using qi::eoi;
        using qi::blank;
        using qi::lexeme;
        using qi::fail;
        using qi::on_error;
        using qi::int_;
        using qi::float_;
        using Utility::eol_;
        namespace phoenix = boost::phoenix;
        
        // define the start rule which holds the whole monstrosity and set the rule to skip blanks
        // if we skipped spaces we could not parse newlines as separators
        startRule = skip(blank) [fileRule];
        fileRule  = (
                       *eol_
                       > lineRule
                       > *(+eol_ >> lineRule)
                       > *eol_
                       > eoi
                       );
        lineRule = (int_   [phoenix::bind(&Data::DetectorPositionData::addDetectorNumber, ptr, qi::_1)] > lexeme[','] >
                    int_   [phoenix::bind(&Data::DetectorPositionData::addRunNumber,      ptr, qi::_1)] > lexeme[','] >
                    float_ [phoenix::bind(&Data::DetectorPositionData::addXPosition,      ptr, qi::_1)] > lexeme[','] >
                    float_ [phoenix::bind(&Data::DetectorPositionData::addYPosition,      ptr, qi::_1)] > lexeme[','] >
                    float_ [phoenix::bind(&Data::DetectorPositionData::addZPosition,      ptr, qi::_1)]);
        on_error<fail>(startRule,
                    std::cout << phoenix::val("Error! Expecting ")
                              << qi::_4                             // what failed?
                              << phoenix::val(" here: \n\"")
                              << phoenix::construct<std::string>(qi::_3, qi::_2) // iterators to error-pos, end
                              << phoenix::val("\"")
                              << std::endl);
    }

private:
    //base rules for the file
    qi::rule<Iterator>                  startRule;
    qi::rule<Iterator, qi::blank_type > fileRule;
    qi::rule<Iterator, qi::blank_type > lineRule;
    
    
    // hold the pointer that we are going to bind to
    Data::DetectorPositionData* ptr;
    
};

}
}

#endif //POSITIONRECONSTRUCTION_SRC_INPUT_PARSERS_DETECTORPOSITIONPARSER_H
