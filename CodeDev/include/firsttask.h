#ifndef BASICPROJECT_C_FIRSTTASK_H
#define BASICPROJECT_C_FIRSTTASK_H

#include <string>
namespace task{
    class AbstractTask{
    public:
        explicit AbstractTask(const int& num, std::string  nam);

        void actionTask();

    protected:
        virtual void createTask()=0;

    protected:
        int m_id{};
        std::string m_name{};
    };
}
#endif //BASICPROJECT_C_FIRSTTASK_H
