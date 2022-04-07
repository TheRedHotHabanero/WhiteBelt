#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::vector;
using std::string;

int main()
{
  int Q;
  std::cin >> Q;
  int month = 0;

  vector<int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  vector<string> tasks;
  //std::cout << tasks.size() << " старый" << std::endl;
  tasks.resize(31);
  //tasks = {"0"};

  vector<int> num_tasks;
  num_tasks.resize(31);
  //num_tasks = {0};

  for (int i = 0; i < Q; ++i)
  {
    string command;
    std::cin >> command;
    int date = 1;
    string task;
    if (command == "ADD")
    {
      std::cin >> date >> task;
    }
    else if (command == "DUMP")
    {
      std::cin >> date;
    }

    if (command == "ADD")
    {
      tasks[date - 1] += task;
      tasks[date - 1] += " ";
      num_tasks[date - 1] += 1;
    }
    else if (command == "DUMP")
    {
      std::cout << num_tasks[date - 1] << " ";
      std::cout << tasks[date - 1] << std::endl;
    }
    else if(command == "NEXT")
    {
      month += 1;
      if (month > 11)
      {month -= 12; }
      //if (month - 1 < 0)
      //{month = 11; } ?????????????????///

      int current = days_in_month[month];
      int previous = days_in_month[month - 1];

      if (previous <= current)
      {
        tasks.resize(current);
        num_tasks.resize(current);
        // лишние дни по идее заполнились нулями
      }
      else //т.е в новом месяце меньше дней
      {
        int razn = previous - current;
        vector<string> saving_tasks(razn);
        saving_tasks = {""};
        vector<int> saving_num_tasks(razn);
        saving_num_tasks = {0};

        for (int j = 0; j < razn; ++j)
        {
          saving_tasks.push_back(tasks[previous - j - 1]);
          saving_num_tasks.push_back(num_tasks[previous - j - 1]);
          // сюда возможно предстоит добавить пробел:
        }
        /*for (int j = 0; j < razn; ++j)
        {
          tasks.pop_back();
          num_tasks.pop_back();
        }
        */
        //std::cout << tasks.size() << " старый" << std::endl;
        tasks.resize(current);
        //std::cout << tasks.size() << " новый" << std::endl;
        num_tasks.resize(current);

        for (int j = 0; j < razn; ++j)
        {
          tasks[tasks.size() - 1] += saving_tasks[j];
          num_tasks[num_tasks.size() - 1] += saving_num_tasks[j];
        }
      }
    }
  }
  return 0;
}