/*!
 * @file OptionParser.h
 * @brief Simple option parser
 * @author koturn
 */
#ifndef KOTLIB_OPTION_PARSER_H
#define KOTLIB_OPTION_PARSER_H

#include <getopt.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#if __cplusplus >= 201103L
#  include <unordered_map>
#else
#  include <map>
#endif


namespace kot
{

/*!
 * @brief Simple option parser
 *
 * Sample code
 *
 * @code
 * #include <cstdlib>
 * #include <iostream>
 * #include <stdexcept>
 * #include <vector>
 * #include "OptionParser.h"
 *
 * int
 * main(int argc, char *const argv[])
 * {
 *   OptionParser op(argv[0]);
 *   op.setOption("apple", 'a', OptionParser::NO_ARGUMENT, false, "Specify apple");
 *   op.setOption("banana", 'b', OptionParser::REQUIRED_ARGUMENT, std::string(""), "Specify banana", "BANANA_NUMBER");
 *   op.setOption("cake", 'c', OptionParser::REQUIRED_ARGUMENT, 0, "Specify cake");
 *   op.setOption("help", 'h', OptionParser::NO_ARGUMENT, "", "Show help and exit this program");
 *   op.setOption('x', OptionParser::NO_ARGUMENT, "0", "No long option sample");
 *   op.setOption("long-x", OptionParser::NO_ARGUMENT, "0", "no short option sample");
 *   try {
 *     op.parse(argc, argv, 1);
 *     if (op.get<bool>("apple")) std::cout << "  -a, --apple\n";
 *     if (op.get("banana") != "") std::cout << "  -b, --banana=" << op.get("banana") << "\n";
 *     if (op.get<int>("cake") != 0) std::cout << "  -c, --cake=" << op.get<int>("cake") << "\n";
 *     if (op.get<bool>('x')) std::cout << "  -x\n";
 *     if (op.get<bool>("long-x")) std::cout << "  --long-x\n";
 *   } catch (const std::exception& e) {
 *     std::cerr << e.what() << std::endl;
 *     return EXIT_FAILURE;
 *   }
 *
 *   std::cout << "[Specified options]\n";
 *   if (op.get<bool>("help")) {
 *     op.showUsage();
 *     return EXIT_SUCCESS;
 *   }
 *
 *   std::cout << "[Remaining arguments]\n";
 *   std::vector<std::string> v = op.getArguments();
 *   for (std::vector<std::string>::const_iterator itr = v.begin(); itr != v.end(); ++itr) {
 *     std::cout << *itr << "\n";
 *   }
 *   std::cout << std::flush;
 *
 *   return EXIT_SUCCESS;
 * }
 * @endcode
 */
class OptionParser
{
public:
  /*!
   * @brief Enumeration of option types
   *
   * NO_ARGUMENT: The option takes no argument
   * REQUIRED_ARGUMENT: The option takes one argument
   * OPTIONAL_ARGUMENT: The option takes no or one argument
   */
  enum OptionType {
    NO_ARGUMENT = no_argument,
    REQUIRED_ARGUMENT = required_argument,
    OPTIONAL_ARGUMENT = optional_argument
  };
private:
  /*!
   * @brief Set of option attributes
   */
  struct OptionSet {
    std::string longOptName;
    int shortOptName;
    OptionType optAttr;
    std::string help;
    std::string metavar;
    OptionSet(
        const std::string& longOptName,
        int shortOptName,
        OptionType optAttr,
        const std::string& help,
        const std::string& metavar) :
      longOptName(longOptName),
      shortOptName(shortOptName),
      optAttr(optAttr),
      help(help),
      metavar(metavar)
    {}
  };
  int noShortNameCnt;
  std::string progname;
  std::string description;
  std::string optionString;
  std::vector<OptionSet> optionSets;
  std::vector<std::string> arguments;
#if __cplusplus >= 201103L
  std::unordered_map<std::string, std::string> longOptionMap;
  std::unordered_map<int, std::string> shortOptionMap;
#else
  std::map<std::string, std::string> longOptionMap;
  std::map<int, std::string> shortOptionMap;
#endif
  mutable std::stringstream ss;
public:
  OptionParser(const std::string& progname="[This program]");
  OptionParser(const OptionParser& that);

  void setDescription(
      const std::string& description);

  void setOption(
      const std::string& longOptName,
      int shortOptName,
      OptionType optAttr,
      const std::string& defaultValue="",
      const std::string& help="",
      const std::string& metavar="ARG");

  void setOption(
      const std::string& longOptName,
      int shortOptName,
      OptionType optAttr,
      const char* defaultValue,
      const std::string& help="",
      const std::string& metavar="ARG");

  template<typename ValType>
  void setOption(
      const std::string& longOptName,
      int shortOptName,
      OptionType optAttr,
      const ValType& defaultValue,
      const std::string& help="",
      const std::string& metavar="ARG");


  void setOption(
      const std::string& longOptName,
      OptionType optAttr,
      const std::string& defaultValue="",
      const std::string& help="",
      const std::string& metavar="ARG");

  void setOption(
      const std::string& longOptName,
      OptionType optAttr,
      const char* defaultValue,
      const std::string& help="",
      const std::string& metavar="ARG");

  template<typename ValType>
  void setOption(
      const std::string& longOptName,
      OptionType optAttr,
      const ValType& defaultValue,
      const std::string& help="",
      const std::string& metavar="ARG");

  void setOption(
      int shortOptName,
      OptionType optAttr,
      const std::string& defaultValue="",
      const std::string& help="",
      const std::string& metavar="ARG");

  void setOption(
      int shortOptName,
      OptionType optAttr,
      const char* defaultValue,
      const std::string& help="",
      const std::string& metavar="ARG");

  template<typename ValType>
  void setOption(
      int shortOptName,
      OptionType optAttr,
      const ValType& defaultValue,
      const std::string& help="",
      const std::string& metavar="ARG");

  void parse(
      int argc,
      char *const * argv,
      int nRequiredArgument=-1);
  bool has(
      const std::string& key) const;
  bool has(
      int key) const;

  template<typename ValType> ValType get(
      const std::string& key) const;
  std::string get(
      const std::string& key) const;

  template<typename ValType> ValType get(
      int key) const;
  std::string get(
      int key) const;

  std::vector<std::string> getArguments(void) const;
  void showUsage(std::ostream& os=std::cout) const;

  std::string& operator[](const std::string& longOptName);
  std::string& operator[](char shortOptName);
  OptionParser& operator=(const OptionParser& that);

  template<typename CharT, typename Traits>
    friend std::basic_ostream<CharT, Traits>&
    operator<<(std::basic_ostream<CharT, Traits>& os, const OptionParser& this_);
};  // class OptionParser


template<typename ValType>
void
OptionParser::setOption(
    const std::string& longOptName,
    int shortOptName,
    OptionType optAttr,
    const ValType& defaultValue,
    const std::string& help,
    const std::string& metavar)
{
  ss.str("0");
  ss.clear(std::stringstream::goodbit);
  ss << defaultValue;
  setOption(longOptName, shortOptName, optAttr, ss.str(), help, metavar);
}


template<typename ValType>
void
OptionParser::setOption(
    const std::string& longOptName,
    OptionType optAttr,
    const ValType& defaultValue,
    const std::string& help,
    const std::string& metavar)
{
  ss.str("0");
  ss.clear(std::stringstream::goodbit);
  ss << defaultValue;
  setOption(longOptName, ++noShortNameCnt, optAttr, ss.str(), help, metavar);
}


template<typename ValType>
void
OptionParser::setOption(
    int shortOptName,
    OptionType optAttr,
    const ValType& defaultValue,
    const std::string& help,
    const std::string& metavar)
{
  ss.str("0");
  ss.clear(std::stringstream::goodbit);
  ss << defaultValue;
  setOption("", shortOptName, optAttr, ss.str(), help, metavar);
}


/*!
 * @brief Get option value
 *
 * @tparam ValType  Value type
 * @param [in] key  Long option name
 *
 * @return Option value (Its type is converted to the specified template argument type)
 */
template<typename ValType>
ValType
OptionParser::get(
    const std::string& key) const
{
  ValType val;
  ss.str("");
  ss.clear(std::stringstream::goodbit);
  ss << longOptionMap.at(key);
  ss >> val;
  if (ss.fail()) {
    ss.str("");
    ss.clear(std::stringstream::goodbit);
    ss << "Cannot convert value: \""
       << longOptionMap.at(key)
       << "\" (key="
       << key
       << ") to desired type";
    throw std::runtime_error(ss.str());
  }
  return val;
}


/*!
 * @brief Get option value
 *
 * @tparam ValType  Value type
 * @param [in] key  Short option name
 *
 * @return Option value (Its type is converted to the specified template argument type)
 */
template<typename ValType>
ValType
OptionParser::get(
    int key) const
{
  ValType val;
  ss.str("");
  ss.clear(std::stringstream::goodbit);
  ss << shortOptionMap.at(key);
  ss >> val;
  if (ss.fail()) {
    ss.str("");
    ss.clear(std::stringstream::goodbit);
    ss << "Cannot convert value: \""
       << shortOptionMap.at(key)
       << "\" (key="
       << static_cast<char>(key)
       << ") to desired type";
    throw std::runtime_error(ss.str());
  }
  return val;
}


/*!
 * @brief Operator overload for 'std::ostream' (such as 'std::cout')
 *
 * @tparam CharT   Character type
 * @tparam Traits  Traits type
 * @param [in,out]  os     Output stream
 * @param [in]      this_  Option parser instance
 *
 * @return Output stream
 */
template<typename CharT, typename Traits>
std::basic_ostream<CharT, Traits>&
operator<<(
    std::basic_ostream<CharT, Traits>& os,
    const OptionParser& this_)
{
  this_.showUsage(os);
  return os;
}


}  // namespace kot


#endif  // KOTLIB_OPTION_PARSER_H
