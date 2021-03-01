class Logger {
  private:
    Logger();
    Logger(const Logger& log) = delete; // non construction-copyable
    Logger& operator = (const Logger& log) = delete; // non copyable
    queue<Message> q; // Queue which multiple threads might add/remove from
    mutex m; // Mutex to protect this queue

  //Lazy initialization
  //C++11: For the singleton pattern, double-checked locking is not needed. 
  //If control enters the declaration concurrently while the variable is being initialized, the concurrent execution shall wait for completion of the initialization.
  public:
    static Logger* getInstance();
   void AddToQueue(Message msg);
    void RemoveFromQueue();
};

Logger* Logger::getInstance()
{
    static Logger instance;
    return &instance;
}

void Logger::AddToQueue(Message msg)
{
    std::lock_guard<std::mutex> guard(m); // Lock will be held from here to end of function
    std::ostringstream ss;
    ss << std::this_thread::get_id();
    msg.setName(ss.str());
    q.push(msg);
}
 
void Logger::RemoveFromQueue()
{
    Message msg;
    {
      std::lock_guard<std::mutex> guard(m); // Lock held from here to end of scope
      while (!q.empty())
      {
          msg = q.front();
          cout<<msg.getName()<<": "<<msg.getMessage()<<endl;
          q.pop();
      }
    }
}
