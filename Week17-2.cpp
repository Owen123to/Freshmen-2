class Set
{
  public:
  Set()
  {
    count =0;
  }
   ~Set()
  {
    for(int i = 0;i<count;i++)
    element[i] = 0;
    count = 0;
  }
  Set(const Set &win)
  {
    this->count = win.count;
    for(int i =0;i<count;i++)
      this->element[i] = win.element[i];
  }
  int add(const int d)
  {
      int i;
      for(i = 0;i<count;i++)
        if(element[i] == d)
          return 0;
      element[count++] = d;
      return 1;
  }
  int add(const Set &set)
  {
     int tmp = 0;
      for (int i = 0; i < set.count; i++)
            tmp = tmp + add(set.element[i]);
        return tmp;
  }
  	void display()
    {
      int j;
      for(j = 0;j < count;j ++)
        std::cout<<element[j]<<" ";
    }
  private:
  	int element[100];
  	int count=0;
};
