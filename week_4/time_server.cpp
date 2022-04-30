#include <exception>
#include <iostream>
#include <string>

using std::string;
using std::runtime_error;
using std::system_error;
using std::error_code;
using std::cout;
using std::endl;
using std::exception;

string AskTimeServer()
{
  throw system_error(error_code());
  return "01:01:01";
}

class TimeServer
{
  private:
    string last_fetched_time = "00:00:00";
  public:
    string GetCurrentTime()
    {
      string curr_time;
      try
      { curr_time = AskTimeServer(); }
      catch (system_error &syserr)
      { return last_fetched_time; }

      last_fetched_time = curr_time;
      return curr_time;
    }
};

int main()
{
  TimeServer ts;
  try
  { cout << ts.GetCurrentTime() << endl; }
  catch (exception &e)
  { cout << "Exception got: " << e.what() << endl; }
  return 0;
}