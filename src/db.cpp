bool checkIfUserExists(std::string userName)
{
  std::string query = "select count(*) from USERS where NAME = \'"
                    + userName + "\';"
  return DB::run_sql<int>(query) > 0;
}

bool autheticate()
{
  std::string userName = UI::readUserInput();
  return checkIfUserExists(userName);
}

bool isValidName( std::string const& text )
{
  const static std::regex NAME{"\\w+"};
  std::smatch match;
  return std::regex_match(text, match, NAME);
}

// NOT RECOMMENDED!
bool checkIfUserExists(std::string userName)
{
  if (!isValidName(userName)) SIGNAL();

  std::string query = "select count(*) from USERS where NAME = \'"
                    + userName + "\';"
  return DB::run_sql<int>(query) > 0;
}

bool autheticate()
{
  std::string userName = UI::readUserInput();
  if (!isValidName(userName)) SIGNAL();

  return checkIfUserExists(userName);
}
