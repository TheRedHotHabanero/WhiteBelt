class SortedStrings
{
  private:
    vector<string> data;
  public:
    void AddString(const std::string& s)
    { data.push_back(s); }
  std::vector<std::string> GetSortedStrings()
  {
    std::sort(begin(data), end(data));
    return data;
  }
};