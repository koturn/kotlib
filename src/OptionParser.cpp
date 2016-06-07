/*!
 * @file OptionParser.cpp
 * @brief Simple option parser
 * @author koturn
 */
#include "../include/kotlib/OptionParser.h"

#ifdef KOTLIB_OPTION_PARSER_ENABLE_SINGLE_HEADER
#  define KOTLIB_OPTION_PARSER_INLINE inline
#else
#  define KOTLIB_OPTION_PARSER_INLINE
#endif


namespace kot
{
/*!
 * @brief Constructor: Create option parser
 *
 * @param [in] progname  Program name (such as 'argv[0]')
 */
KOTLIB_OPTION_PARSER_INLINE
OptionParser::OptionParser(const std::string& progname) :
  noShortNameCnt(0),
  progname(progname),
  description(),
  optionString(),
  optionSets(),
  arguments(),
  longOptionMap(),
  shortOptionMap(),
  ss()
{}


/*!
 * @brief  Copy constructor: Copy OptionParser instance
 *
 * @param [in] that  Original option parser instance
 */
KOTLIB_OPTION_PARSER_INLINE
OptionParser::OptionParser(
    const OptionParser& that) :
  noShortNameCnt(that.noShortNameCnt),
  progname(that.progname),
  description(that.description),
  optionString(that.optionString),
  optionSets(that.optionSets),
  arguments(that.arguments),
  longOptionMap(that.longOptionMap),
  shortOptionMap(that.shortOptionMap),
  ss()
{}


/*!
 * @brief Set description of your program
 *
 * Specified description is shown by OptionParser::showUsage()
 *
 * @param [in] description  Description of your program
 */
KOTLIB_OPTION_PARSER_INLINE void
OptionParser::setDescription(const std::string& description)
{
  this->description = description;
}


/*!
 * @brief Set one option
 *
 * @param [in] longOptName   Long option name such as "apple", "banana" or "cake"
 * @param [in] shortOptName  Short option name such as 'a', 'b' or 'c'
 * @param [in] optAttr       Option attributes (NO_ARGUMENT, REQUIRED_ARGUMENT)
 * @param [in] defaultValue  Default value for this option
 * @param [in] help          Description of this option
 * @param [in] metavar       Name of meta variable for this option
 */
KOTLIB_OPTION_PARSER_INLINE void
OptionParser::setOption(
    const std::string& longOptName,
    int shortOptName,
    OptionType optAttr,
    const std::string& defaultValue,
    const std::string& help,
    const std::string& metavar)
{
  std::string defaultValue_ = (optAttr == NO_ARGUMENT && defaultValue.empty()) ? "0" : defaultValue;
  if (longOptName.empty()) {
    optionSets.push_back(OptionSet("", shortOptName, optAttr, help, metavar));
  } else {
    optionSets.push_back(OptionSet(longOptName, shortOptName, optAttr, help, metavar));
    longOptionMap[longOptName] = defaultValue_;
  }
  shortOptionMap[shortOptName] = defaultValue_;

  optionString += static_cast<char>(shortOptName);
  if (optAttr == REQUIRED_ARGUMENT || optAttr == OPTIONAL_ARGUMENT) {
    optionString += ":";
  }
}


KOTLIB_OPTION_PARSER_INLINE void
OptionParser::setOption(
    const std::string& longOptName,
    int shortOptName,
    OptionType optAttr,
    const char* defaultValue,
    const std::string& help,
    const std::string& metavar)
{
  setOption(longOptName, shortOptName, optAttr, std::string(defaultValue), help, metavar);
}


/*!
 * @brief Set one option
 *
 * @param [in] longOptName   Long option name such as "apple", "banana" or "cake"
 * @param [in] optAttr       Option attributes (NO_ARGUMENT, REQUIRED_ARGUMENT)
 * @param [in] defaultValue  Default value for this option
 * @param [in] help          Description of this option
 * @param [in] metavar       Name of meta variable for this option
 */
KOTLIB_OPTION_PARSER_INLINE void
OptionParser::setOption(
    const std::string& longOptName,
    OptionType optAttr,
    const std::string& defaultValue,
    const std::string& help,
    const std::string& metavar)
{
  setOption(longOptName, ++noShortNameCnt, optAttr, defaultValue, help, metavar);
}


KOTLIB_OPTION_PARSER_INLINE void
OptionParser::setOption(
    const std::string& longOptName,
    OptionType optAttr,
    const char* defaultValue,
    const std::string& help,
    const std::string& metavar)
{
  setOption(longOptName, ++noShortNameCnt, optAttr, std::string(defaultValue), help, metavar);
}


/*!
 * @brief Set one option
 *
 * @param [in] shortOptName  Short option name such as 'a', 'b' or 'c'
 * @param [in] optAttr       Option attributes (NO_ARGUMENT, REQUIRED_ARGUMENT)
 * @param [in] defaultValue  Default value for this option
 * @param [in] help          Description of this option
 * @param [in] metavar       Name of meta variable for this option
 */
KOTLIB_OPTION_PARSER_INLINE void
OptionParser::setOption(
    int shortOptName,
    OptionType optAttr,
    const std::string& defaultValue,
    const std::string& help,
    const std::string& metavar)
{
  setOption("", shortOptName, optAttr, defaultValue, help, metavar);
}


KOTLIB_OPTION_PARSER_INLINE void
OptionParser::setOption(
    int shortOptName,
    OptionType optAttr,
    const char* defaultValue,
    const std::string& help,
    const std::string& metavar)
{
  setOption("", shortOptName, optAttr, std::string(defaultValue), help, metavar);
}


/*!
 * @brief Parse specified command line arguments
 *
 * @param [in] argc               A number of command-line arguments
 * @param [in] argv               Command line arguments
 * @param [in] nRequiredArgument  Number of required argument
 */
KOTLIB_OPTION_PARSER_INLINE void
OptionParser::parse(
    int argc,
    char *const * argv,
    int nRequiredArgument)
{
  if (argv == NULL) {
    throw std::invalid_argument("Second argument of OptionParser::parse() must not be NULL pointer");
  }

  std::vector<char*> argVector;
  argVector.reserve(argc);
  for (int i = 0; i < argc; i++) {
    argVector.push_back(argv[i]);
  }

  std::vector<option> optionVector;
  optionVector.reserve(optionSets.size() + 1);
  for (std::vector<OptionSet>::const_iterator itr = optionSets.begin(); itr != optionSets.end(); ++itr) {
    option opt = {itr->longOptName.c_str(), itr->optAttr, NULL, itr->shortOptName};
    optionVector.push_back(opt);
  }
  option sentinelOption = {NULL, 0, NULL, 0};
  optionVector.push_back(sentinelOption);

  // int prevOpterr = opterr;
  // opterr = 0;
  int ret, optidx;
  while ((ret = getopt_long(argc, &argVector[0], optionString.c_str(), &optionVector[0], &optidx)) != -1) {
    for (std::vector<OptionSet>::const_iterator itr = optionSets.begin(); itr != optionSets.end(); ++itr) {
      if (itr->shortOptName == ret) {
        switch (itr->optAttr) {
          case REQUIRED_ARGUMENT:
            longOptionMap[itr->longOptName] = optarg;
            shortOptionMap[ret] = optarg;
            break;
          case NO_ARGUMENT:
            longOptionMap[itr->longOptName] = "1";
            shortOptionMap[ret] = "1";
            break;
          case OPTIONAL_ARGUMENT:
            if (optarg == NULL) {
              longOptionMap[itr->longOptName] = "1";
              shortOptionMap[ret] = "1";
            } else {
              longOptionMap[itr->longOptName] = optarg;
              shortOptionMap[ret] = optarg;
            }
            break;
        }
      } else if (ret == '?') {
        throw std::runtime_error("Invalid option");
      }
    }
  }
  // opterr = prevOpterr;

  if (nRequiredArgument > 0 && optind > argc - nRequiredArgument) {
    ss.str("");
    ss.clear(std::stringstream::goodbit);
    ss << "Please specify " << nRequiredArgument << " argument";
    if (nRequiredArgument > 1) {
      ss << "s";
    }
    throw std::runtime_error(ss.str());
  }
  for (int i = optind; i < argc; i++) {
    std::copy(argVector.begin() + i, argVector.end(), std::back_inserter(arguments));
  }
}


/*!
 * @brief Check whether option parser can recognize specified option or not
 * @param [in] key  Long option name
 * @return True then option parser can recognize specified option
 */
KOTLIB_OPTION_PARSER_INLINE bool
OptionParser::has(
    const std::string& key) const
{
  return longOptionMap.find(key) != longOptionMap.end();
}


/*!
 * @brief Check whether option parser can recognize specified option or not
 * @param [in] key  Short option name
 * @return True then option parser can recognize specified option
 */
KOTLIB_OPTION_PARSER_INLINE bool
OptionParser::has(
    int key) const
{
  return shortOptionMap.find(key) != shortOptionMap.end();
}


/*!
 * @brief Get option value
 *
 * @param [in] key  Long option name
 *
 * @return Option value (as std::string)
 */
KOTLIB_OPTION_PARSER_INLINE std::string
OptionParser::get(
    const std::string& key) const
{
  return longOptionMap.at(key);
}


/*!
 * @brief Get option value
 *
 * @param [in] key  Short option name
 * @return Option value (as std::string)
 */
KOTLIB_OPTION_PARSER_INLINE std::string
OptionParser::get(
    int key) const
{
  return shortOptionMap.at(key);
}


/*!
 * @brief Get remaining arguments
 *
 * @return String vector of remaining arguments
 */
KOTLIB_OPTION_PARSER_INLINE std::vector<std::string>
OptionParser::getArguments(void) const
{
  return arguments;
}


/*!
 * @brief Show usage of your program
 *
 * @param [in] os  Output stream
 */
KOTLIB_OPTION_PARSER_INLINE void
OptionParser::showUsage(
    std::ostream& os) const
{
  if (!description.empty()) {
    os << description << "\n";
  }
  os << "[Usage]\n"
     << "  " << progname << " [Options ...] [Arguments ...]\n\n"
     << "[Option]\n";
  for (std::vector<OptionSet>::const_iterator itr = optionSets.begin(); itr != optionSets.end(); ++itr) {
    os << "  ";
    if (itr->longOptName.empty()) {
      os << "-" << static_cast<char>(itr->shortOptName);
      if (itr->optAttr == REQUIRED_ARGUMENT) {
        os << " " << itr->metavar;
      }
    } else if (itr->shortOptName < 30) {
      os << "--" << itr->longOptName;
      if (itr->optAttr == REQUIRED_ARGUMENT) {
        os << "=" << itr->metavar;
      }
    } else {
      os << "-" << static_cast<char>(itr->shortOptName);
      if (itr->optAttr == REQUIRED_ARGUMENT) {
        os << " " << itr->metavar;
      }
      os << ", --" << itr->longOptName;
      if (itr->optAttr == REQUIRED_ARGUMENT) {
        os << "=" << itr->metavar;
      }
    }
    os << "\n";
    if (!itr->help.empty()) {
      os << "    " << itr->help << "\n";
    }
  }
  os << std::endl;
}


/*!
 * @brief Access option value
 *
 * You can get/set option value
 *
 * @param [in] longOptName   Long option name such as "apple", "banana" or "cake"
 *
 * @return Option value as std::string
 */
KOTLIB_OPTION_PARSER_INLINE std::string&
OptionParser::operator[](
    const std::string& longOptName)
{
  return longOptionMap.at(longOptName);
}


/*!
 * @brief Access option value
 *
 * You can get/set option value as following code
 *
 * @code
 * OptionParser op(argc, argv);
 * op.setOption("apple", 'a', OptionParser::NO_ARGUMENT, "", "Specify apple");
 * op.parse();
 * std::cout << op["apple"] << std::endl;
 * std::cout << op['a'] << std::endl;
 * op["apple"] = "foo";
 * std::cout << op["apple"] << std::endl;
 * std::cout << op['a'] << std::endl;
 * @endcode
 *
 * @param [in] shortOptName  Short option name such as 'a', 'b' or 'c'
 *
 * @return Option value as std::string
 */
KOTLIB_OPTION_PARSER_INLINE std::string&
OptionParser::operator[](
    char shortOptName)
{
  return shortOptionMap.at(shortOptName);
}


/*!
 * @brief Assignment operator for OptionParser
 *
 * Allocate memory and 'argv' of 'that' is copied to there
 *
 * @param [in] that  Original OptionParser instance
 *
 * @return Copied option parser instance
 */
KOTLIB_OPTION_PARSER_INLINE OptionParser&
OptionParser::operator=(
    const OptionParser& that)
{
  noShortNameCnt = that.noShortNameCnt;
  progname = that.progname;
  description = that.description;
  optionString = that.optionString;
  optionSets = that.optionSets;
  arguments = that.arguments;
  longOptionMap = that.longOptionMap;
  shortOptionMap = that.shortOptionMap;
  return *this;
}


}  // namespace kot


#undef KOTLIB_OPTION_PARSER_INLINE
