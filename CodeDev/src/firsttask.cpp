#include "firsttask.h"
#include <iostream>
#include <utility>
namespace task{
AbstractTask::AbstractTask(const int& num, std::string  nam)
    : m_id(num)
    , m_name(std::move(nam))
{
}

void AbstractTask::actionTask()
{
  std::cout<<m_name<<std::endl;
}
}